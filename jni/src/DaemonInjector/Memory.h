//
// Created by PCAditiaID29 on 3/10/2021.
//

#ifndef RCHEATS_V2_MEMORY_H
#define RCHEATS_V2_MEMORY_H

#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include "Process.h"
#include "MemoryTools.h"



typedef uint8_t BYTE;

enum TYPEs {
    TYPE_DWORD,
    TYPE_FLOAT
};

uintptr_t lib_base = 0;
int handlemem = 0;
int game_pid = 0;

const char tersafe[20]= "libanogs.so";
const char UE4[20]= "libUE4.so";
const char master[20]= "libTDataMaster.so";
const char igshare[20]= "libigshare.so";
const char listener[50]= "libhelpshiftlistener.so";


char pkg[100];
int countt;

bool initMemory();
pid_t getPid(const char *pkg_name);
int isApkRunning(const char *pkg_name);
uintptr_t getModuleAddress(int game_pid, const char *module_name);
void Write(uintptr_t address, const char *value, TYPE type);
void WriteDword(uintptr_t address, int value);
void WriteFloat(uintptr_t address, float value);
void WriteByte(uintptr_t address, void *buffer, size_t length);
bool SetLib(const char *module_name);
uintptr_t getRealOffset(uintptr_t address);

bool SetLib(const char *module_name){
	
	bool isResult = false;
	 if (game_pid != 0){
        LOGI("Found pid: %d", game_pid);
        lib_base = getModuleAddress(game_pid, module_name);
        if (lib_base == 0){
            isResult = false;
            std::cout << "base address is not present " << module_name << "\n";
        } else {
            std::cout << "base addr of "<<module_name <<" found \n";
            char lj[64];
            sprintf(lj, "/proc/%d/mem", game_pid);
            handlemem = open(lj, O_RDWR);
            if (handlemem != 0){
                lseek(handlemem, 0, SEEK_SET);
                isResult = true;
                std::cout << "module has been changed to "<< module_name <<"\n";
            }
        }
    }else{
         std::cout << "pid missing\n";
         isResult = false;
	 }
    return isResult;
	
	
}

uintptr_t getRealOffset(uintptr_t address)
{
    if (lib_base == 0)
		std::cout << "lib base not found \n";
        LOGE("Error: Can't get memory base address");
    return lib_base + address;
}

bool initMemory(){
    bool isResult = false;
    if (isApkRunning("com.tencent.ig") == 1){
        game_pid = getPid("com.tencent.ig");
		target_pid = getPid("com.tencent.ig");
        Offsets::globalOffsets();
        sprintf(pkg, "com.tencent.ig");
        LOGI("PUBGM Global version is runnning");
        std::cout << "PUBGM Global version is runnning\n";
        isResult = true;
    } else if (isApkRunning("com.vng.pubgmobile") == 1){
        Offsets::vietnamOffsets();
        game_pid = getPid("com.vng.pubgmobile");
		target_pid = getPid("com.vng.pubgmobile");
        sprintf(pkg, "com.vng.pubgmobile");
        LOGI("PUBGM Vietnam version is runnning");
        std::cout << "PUBGM Vietnam version is runnning\n";
        isResult = true;
    } else if (isApkRunning("com.pubg.krmobile") == 1){
        Offsets::koreaOffsets();
        game_pid = getPid("com.pubg.krmobile");
		target_pid = getPid("com.pubg.krmobile");
        sprintf(pkg, "com.pubg.krmobile");
        LOGI("PUBGM Korea version is runnning");
        std::cout << "PUBGM Korea version is runnning\n";
        isResult = true;
    } else if (isApkRunning("com.rekoo.pubgm") == 1){
        Offsets::taiwanOffsets();
        game_pid = getPid("com.rekoo.pubgm");
		target_pid = getPid("com.rekoo.pubgm");
        sprintf(pkg, "com.rekoo.pubgm");
        LOGI("PUBGM Taiwan version is runnning");
        std::cout << "PUBGM Taiwan version is runnning\n";
        isResult = true;
    } else if (isApkRunning("com.pubg.imobile") == 1){
        Offsets::india();
        game_pid = getPid("com.pubg.imobile");
		target_pid = getPid("com.pubg.imobile");
        sprintf(pkg, "com.pubg.imobile");
        LOGI("PUBGM India version is runnning");
        std::cout << "PUBGM india version is runnning\n";
        isResult = true;
    } 
	else{
        LOGE("Can't get game pid!");
        isResult = false;
    }
    return isResult;
}

int isApkRunning(const char *pkg_name){
    if (getPid(pkg_name) != 0 && getPid(pkg_name) > 0){
        return 1;
    }
    return 0;
}


pid_t getPid(const char *pkg_name){
    pid_t pid = 0;
    int id;
    DIR* dir;
    FILE* fp;
    char filename[32];
    char cmdline[256];

    struct dirent* entry;
    if (pkg_name == NULL) {
        return -1;
    }
    dir = opendir("/proc");
    if (dir == NULL) {
        return -1;
    }
    while ((entry = readdir(dir)) != NULL) {
        id = atoi(entry->d_name);
        if (id != 0) {
            sprintf(filename, "/proc/%d/cmdline", id);
            fp = fopen(filename, "r");
            if (fp) {
                fgets(cmdline, sizeof(cmdline), fp);
                fclose(fp);
                if (strcmp(pkg_name, cmdline) == 0) {
                    pid = id;
                    break;
                }
            }
        }
    }
    closedir(dir);
    return pid;
}

uintptr_t getModuleAddress(int game_pid, const char *module_name){
    FILE *fp;
    unsigned int addr = 0;
    char filename[32], buffer[1024];
    snprintf(filename, sizeof(filename), "/proc/%d/maps", game_pid);
    fp = fopen(filename, "rt");
    if (fp != nullptr) {
        while (fgets(buffer, sizeof(buffer), fp)) {
            if (strstr(buffer, module_name)) {
                addr = (uintptr_t)strtoull(buffer, NULL, 16);
                break;
            }
        }
        fclose(fp);
    }
    return addr;
}

void Write(uintptr_t address, const char *value, TYPEs type){
    switch (type) {
        case TYPE_DWORD:
            WriteDword(address, atoi(value));
            break;
        case TYPE_FLOAT:
            WriteFloat(address, atof(value));
            break;
    }
}

void WriteDword(uintptr_t address, int value){
	pwrite64(handlemem, (void*)&value, sizeof(value), address);
}

void WriteFloat(uintptr_t address, float value){
	 pwrite64(handlemem, (void*)&value, sizeof(value), address);
}

void WriteByte(uintptr_t address, void *buffer, size_t length) {
    pwrite64(handlemem, (void*)buffer, length, address);
}

void WriteToVB(uintptr_t addressToWrite, char* valueToWrite, int byteNum) {
    memcpy((void*)addressToWrite, valueToWrite, byteNum);
}

template <typename T>
T Readmem(uintptr_t address) {
    T data;
    vm_readv(reinterpret_cast<void*>(address), reinterpret_cast<void*>(&data), sizeof(T));
    return data;
}

template <typename T>
void Writemem(uintptr_t address, T data) {
    vm_writev(reinterpret_cast<void*>(address), reinterpret_cast<void*>(&data), sizeof(T));
}

template <typename T>
T* ReadArr(uintptr_t address, unsigned int size) {
    T data[size];
    T* ptr = data;
    vm_readv(reinterpret_cast<void*>(address), reinterpret_cast<void*>(ptr), (sizeof(T) * size));
    return ptr;
}

std::string ReadStr(uintptr_t address, unsigned int size) {
    std::string result;
    result.resize(size);
    for (size_t i=0; i < size; i++) {
        size_t zochar = sizeof(char);
        vm_readv(reinterpret_cast<void*>(address + (zochar*i)), reinterpret_cast<void*>(&result[0]+i), zochar);
        if(result[i] == '\0'){
            break;
        }
    }
    return result;
}

uintptr_t getPtr(uintptr_t address) {
    return Readmem<uintptr_t>(address);
}


#endif //RCHEATS_V2_MEMORY_H
