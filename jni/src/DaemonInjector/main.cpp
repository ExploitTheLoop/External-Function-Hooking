#include<iostream>
#include<string.h>
#include <vector>
#include <string>
#include <filesystem>
#include <unistd.h>
#include "main.h"
#include "Memory.h"
#include "inject.h"

const char key[20]="@benkkstudio";
bool shouldAutoLaunch = true;


int Verify(){
    if (getPid(OBFUSCATE("com.plexus.lieshooter")) != 0 && getPid(OBFUSCATE("com.plexus.lieshooter")) > 0){
        return 1;
    }
    return 0;
}

void launchApp(char *appLaunchActivity) {
    //Test on termux:
    //am start packagename/launchActivity
    char start_cmd[1024] = "am start ";

    strcat(start_cmd, appLaunchActivity);
    LOGI("%s", start_cmd);

    system(start_cmd);
}

bool Inputpassword(){
    bool isResult =false;
    char name[30];
    std::cout<<"Enter key\n";
    std::cin >> name;
    std::cout << "You entered: " << name << std::endl;
    if(strcmp(name, key) == 0){
        isResult = true;
    } else{
        isResult = false;
    }
    return isResult;
}

int InputGameno(){
    int gamenumber;
    std::cout<<"Choose your game\n";
    std::cout<<"Global : 1 Korea: 2 Vng: 3 Taiwan: 4 Bgmi : 5 \n";
    std::cin >> gamenumber;
    std::cout << "You entered: " << gamenumber << std::endl;
    return gamenumber;
}

int isinlobby(){
    int islobby;
    std::cout<<"Are you in lobby now ?\n";
    std::cout<<"Yes : 1 No : 2\n";
    std::cin >> islobby;
    std::cout << "You entered: " << islobby << std::endl;
    return islobby;
}


int hsub_abc(){
    printf("Injector based hooking..");
}




void bypass(int status){
    if (initMemory()){

        std::cout << "Game found\n";

        switch (status) {

            case 1:

                //hooking func example
               // hook_lib_no_backup("com.pubg.imobile" , "libanogs.so" , "0xabc", (void *) hsub_abc);

                SetLib(tersafe);
                std::cout << "please wait changing memory\n";

                if (isApkRunning("com.tencent.ig") == 1){



                    //   Write(getRealOffset(0x5A78B8), OBFUSCATE("0"), TYPE_FLOAT);
                  //  BYTE frAQBc[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
                  //  WriteByte(getRealOffset(0x5A78B8), frAQBc, sizeof(frAQBc));




                    sleep(2);
                    SetLib(UE4);



                    sleep(2);
                    SetLib(master);


                    std::cout << "PUBGM Global version is being bypassed\n";

                } else if (isApkRunning("com.pubg.imobile") == 1){

                  //  BYTE frAQBc[] = { 0x00, 0x01 };
                  //  BYTE frAQBck[] = { 0x88, 0x01 };
                  //  BYTE frAQBcj[] = { 0x00, 0x20, 0x70, 0x47 };
                  //  WriteByte(getRealOffset(0x342FA), frAQBc, sizeof(frAQBc));
                  //  WriteByte(getRealOffset(0x3432A), frAQBck, sizeof(frAQBck));
                  //  WriteByte(getRealOffset(0x35192), frAQBck, sizeof(frAQBck));
                  //  WriteByte(getRealOffset(0x35554), frAQBcj, sizeof(frAQBcj));
                  //  WriteByte(getRealOffset(0x6E832), frAQBcj, sizeof(frAQBcj));


                    sleep(2);
                    SetLib(UE4);


                    sleep(2);
                    SetLib(master);


                    std::cout << "PUBGM india version is being bypassed\n";

                } else if (isApkRunning("com.vng.pubgmobile") == 1){



                    sleep(2);
                    SetLib(UE4);


                    sleep(2);
                    SetLib(master);


                    std::cout << "VNG version is being bypassed\n";

                } else if (isApkRunning("com.rekoo.pubgm") == 1){



                    sleep(2);
                    SetLib(UE4);


                    sleep(2);
                    SetLib(master);


                    std::cout << "Taiwan version is being bypassed\n";

                } else {



                    sleep(2);
                    SetLib(UE4);


                    sleep(2);
                    SetLib(master);


                    std::cout << "Non-Global version is being bypassed\n";

                }

                std::cout << "Process completed\n";

                break;
            case 2:

                SetLib(tersafe);
               // SetSearchRange(C_ALLOC);
              //  MemorySearch(pkg,OBFUSCATE("134,914"),&countt, DWORD);
                //   MemoryOffset(pkg,OBFUSCATE("1.953.067.887"), 4, &count,DWORD);
                //   MemoryOffset(pkg,OBFUSCATE("1.634.692.166"), 28, &count,DWORD);
                //   MemoryOffset(pkg,OBFUSCATE("1.920.287.604"), 4, &count,DWORD);
             //   MemoryWrite(pkg,OBFUSCATE("84,149,249"), 0, DWORD);
           //     ClearResults();

                std::cout << "Lobby bypass activated\n";

                break;
        }
        if (handle != 0)
            close(handle);
    }else{
        std::cout << "Game not found\n";
    }
}


int main(int argc, char** argv){


    if( Inputpassword() ) {

        std::cout << " verified \n\n";

        int gameno = InputGameno();

        if (gameno == 1){
            launchApp((char *) "com.tencent.ig/com.epicgames.ue4.SplashActivity");
            std::cout << " Starting Global \n\n";
        }else if (gameno == 2){
            launchApp((char *) "com.pubg.krmobile/com.epicgames.ue4.SplashActivity");
            std::cout << " Starting korea \n\n";
        } else if (gameno == 3){
            launchApp((char *) "com.vng.pubgmobile/com.epicgames.ue4.SplashActivity");
            std::cout << " Starting vng \n\n";
        } else if (gameno == 4){
            launchApp((char *) "com.rekoo.pubgm/com.epicgames.ue4.SplashActivity");
            std::cout << " Starting Taiwan \n\n";
        } else if (gameno == 5){
            launchApp((char *) "com.pubg.imobile/com.epicgames.ue4.SplashActivity");
            std::cout << " Starting Bgmi \n\n";
        }else {

            std::cout << "Game number " << gameno << std::endl;
            std::cout << " Either Game not installed or you may have not put the right input \n\n";
            exit(1);

        }

        sleep(5);

        int status = 1;
        bypass(status);

        int inlobby;

        do{
            inlobby = isinlobby();
            if(inlobby == 1){
                bypass(2);
            }else{
                continue;
            }

        } while (inlobby!=1);




    }else{

        std::cout << " not verified \n";
        exit(1);
    }

    return 0;
}
