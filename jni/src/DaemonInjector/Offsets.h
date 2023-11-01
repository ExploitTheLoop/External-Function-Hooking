   //THIS SOURCE SHARE BY @ETEONPUBG TELEGRAM CHENNAL
//

namespace Offsets {
    uintptr_t Aimbot[2] = {};
    uintptr_t BlackBody;
    uintptr_t BlackSky;
	uintptr_t NightMode;
    uintptr_t Bypass;
    uintptr_t Fog;
    uintptr_t CharacterView;

    uintptr_t GNames;
    uintptr_t GWorld;
    uintptr_t ViewWorld;
    //功能
    uintptr_t bIsWeaponFiring = 0xe98;
    uintptr_t ShootWeaponEntity = 0xb40; //not sure
    uintptr_t ShootInterval = 0x3e8;
    uintptr_t BulletFireSpeed = 0x3C4;
    uintptr_t AccessoriesVRecoilFactor = 0x814;
    uintptr_t AccessoriesHRecoilFactor = 0x818;
    uintptr_t AccessoriesRecoveryFactor = 0x81c;
    uintptr_t ParachuteComponent = 0xe88;
    uintptr_t CurrentFallSpeed = 0x290;
    //绘制
    uintptr_t PersistentLevel = 0x20;
    uintptr_t ULevelToAActors = 0x70;
    uintptr_t ULevelToAActorsCount = 0x74;
    uintptr_t RootComponent = 0x144;
    uintptr_t Position = 0x150;
    uintptr_t SkeletalMeshComponent = 0x318;
    uintptr_t BoneArray = 0x5E4;
    uintptr_t Health = 0x93C;
    uintptr_t HealthMax = 0x940;
    uintptr_t PlayerDeath = 0x1024;
    uintptr_t PlayerName = 0x648;
    uintptr_t TeamID = 0x670;
    uintptr_t IsBot = 0x6E8;
    uintptr_t WeaponEntityComp = 0x4f4;
    uintptr_t WeaponId = 0xcc;
    uintptr_t CurBulletNumInClip = 0x90c;

    void globalOffsets(){
        Aimbot[0] = 0x263E530;
        Aimbot[1] = 0x3740D98;
        BlackBody = 0x2E4C108;
        BlackSky = 0x3B32A60;
        Bypass = 0x1394c;
        NightMode = 0x2F685EC;
        Fog = 0x2DC1028;
        CharacterView = 0x38802B0;

        GNames = 0x6EADCE0;
        GWorld = 0x785EDFC;
        ViewWorld = 0x77E5710;
    }
    void vietnamOffsets(){
        Aimbot[0] = 0x2C73654;
        Aimbot[1] = 0x263E4D0;
        BlackBody = 0x2E4C0A8;
        BlackSky = 0x3B32A3C;
        Bypass = 0x1394c;
        NightMode = 0x2F6858C;
        Fog = 0x2DC0FC8;
        CharacterView = 0x3880250;

        GNames = 0x6EADC60;
        GWorld = 0x6CB087C;
        ViewWorld = 0x7111E80;
    }
    void koreaOffsets(){
        Aimbot[0] = 0x2C73654;
        Aimbot[1] = 0x263E4D0;
        BlackBody = 0x2E4C0A8;
        BlackSky = 0x3B32A3C;
        Bypass = 0x1394c;
        NightMode = 0x2F6858C;
        Fog = 0x2DC0FC8;
        CharacterView = 0x3880250;

        GNames = 0x6EADC60;
        GWorld = 0x6CB087C;
        ViewWorld = 0x7111E80;
    }
    void taiwanOffsets(){
        Aimbot[0] = 0x2C73654;
        Aimbot[1] = 0x263E4D0;
        BlackBody = 0x2E4C0A8;
        BlackSky = 0x3B32A3C;
        Bypass = 0x1394c;
        NightMode = 0x2F6858C;
        Fog = 0x2DC0FC8;
        CharacterView = 0x3880250;

        GNames = 0x6EADC60;
        GWorld = 0x6CB087C;
        ViewWorld = 0x7111E80;
    }
	void india(){
        Aimbot[0] = 0x2C73654;
        Aimbot[1] = 0x263E4D0;
        BlackBody = 0x2E4C0A8;
        BlackSky = 0x3B32A3C;
        Bypass = 0x1394c;
        NightMode = 0x2F6858C;
        Fog = 0x2DC0FC8;
        CharacterView = 0x3880250;

        GNames = 0x6EADC60;
        GWorld = 0x6CB087C;
        ViewWorld = 0x7111E80;
    }
}

