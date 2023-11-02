## About

- A c++ independent executable program , this helps reverse engineers to hijack any function of a program or alter memory of an address according to your will. its made for educational purposes dont' use it for illegal purposes . 


![](https://i.imgur.com/zeumkBG.gif)

## Features
- Built with C++.

## Usage
`HOOKING FUNCTION EXAMPLE`:
```
hook_lib_no_backup("com.pubg.imobile" , "libanogs.so" , "0xabc", (void *) hsub_abc);
```

`NORMAL METHODS`:

```
          Write(getRealOffset(0x5A78B8), OBFUSCATE("0"), TYPE_FLOAT); --YOU CAN CHANGE THE TYPE PARAMETER
		  
          BYTE frAQBc[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
          WriteByte(getRealOffset(0x5A78B8), frAQBc, sizeof(frAQBc));
		  
		  SetSearchRange(C_ALLOC);
          MemorySearch(pkg,OBFUSCATE("134,914"),&countt, DWORD);
          MemoryOffset(pkg,OBFUSCATE("1.953.067.887"), 4, &count,DWORD);
          MemoryOffset(pkg,OBFUSCATE("1.634.692.166"), 28, &count,DWORD);
          MemoryOffset(pkg,OBFUSCATE("1.920.287.604"), 4, &count,DWORD);
          MemoryWrite(pkg,OBFUSCATE("84,149,249"), 0, DWORD);
          ClearResults();
		  
