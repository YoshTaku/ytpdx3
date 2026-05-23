#include <kamek.hpp>

namespace Pulsar {
namespace Race {

//RACE SPECIFIC

//Fix Mushroom Glitch
kmWrite8(0x807BA077, 0x00000000);

//Impervious TC
kmWrite32(0x807AFAA8, 0x48000038);

//Rexcore Countdown (Look Behind)
kmWrite32(0x805A225C, 0x38800001);

//Extend race online
kmWrite32(0x8053F3B8,0x3C600005);
kmWrite32(0x8053F3BC,0x38837E40);
kmWrite32(0x8053F478,0x4800000C); //6 Minute DC Disables

//Anti Online Penalized by B_squo
kmWrite32(0x80549218, 0x38600000);
kmWrite32(0x8054921c, 0x4e800020);

//WW Bubble Skip [Ro]
kmWrite8(0x80609647, 0x0000003C);
kmWrite8(0x8060964F, 0x0000001E);

//Remove Chadderz Button
kmWrite16(0x8064B982, 0x00000005);
kmWrite32(0x8064BA10, 0x60000000);
kmWrite32(0x8064BA38, 0x60000000);
kmWrite32(0x8064BA50, 0x60000000);
kmWrite32(0x8064BA5C, 0x60000000);
kmWrite16(0x8064BC12, 0x00000001);
kmWrite16(0x8064BC3E, 0x00000484);
kmWrite16(0x8064BC4E, 0x000010D7);
kmWrite16(0x8064BCB6, 0x00000484);
kmWrite16(0x8064BCC2, 0x000010D7);

//Floating Flibs [Stealth Steeler]
//kmWrite32(0x808a5770, 0x00000000);
//kmWrite32(0x808a5774, 0x00000000);

//No Bullet Bill Cancel When Touching Bottom of Rainbow Road [Ro]
kmWrite32(0x8059BE30, 0x60000000);

//Skip Mode Selection Online [Ro]
kmWrite32(0x8064be64, 0x3800008F); //Regional/CTWW -> VS Race
kmWrite32(0x80609aac, 0x3800008B); //Back from Character Selection

//Fix Toad's Factory Music
kmWrite32(0x80719920, 0x48000010); //Disable Sound Trigger Reset
kmWrite16(0x80711FE8, 0x00004800); //Music starts at beginning of BRSTM
kmWrite16(0x80712024, 0x00004800);
kmWrite16(0x8071207C, 0x00004800);
kmWrite16(0x807120B8, 0x00004800);

//Fix these fuckin boxes [Unnamed]
asmFunc ItemRespawn() {
loc_0x0:
  li r12, 0x30 //30 frames
  stw r12, 184(r27)
  stw r0, 176(r27)

}
kmCall(0x80828EDC, ItemRespawn);

//Worldwide/Regional Opponent Zoom in Regional/Worldwide
kmWrite32(0x805E527C, 0x3BC00000);

//Bullet Cannon Fix
//kmWrite32(0x8057855B, 0x000000F8);

//Fix Star Off/Road Glitch after Cannon [Ro]
asmFunc StarCannonBug() {
loc_0x0:
  andi. r11, r0, 0x80
  andis. r12, r0, 0x8000
  or. r0, r11, r12
  
}  
kmCall(0x8057C3F8, StarCannonBug);

//CODES BELOW WERE TAKEN FROM INSANE KART WII!

//Event Overflow Protection [Seeky]
asmFunc EventOverflowProtection() {
  ASM(
    nofralloc;
  lbz       r12, 0x1C(r27);
  add       r12, r30, r12;
  cmpwi     r12, 0xE0;
  blt+      loc_0x18;
  li        r0, 0;
  stb       r0, 0x19(r27);

loc_0x18:
  lbz       r0, 0x19(r27);
  blr;
  )
}
kmCall(0x8065BBD4, EventOverflowProtection);

//Enhanced Pause Menu [Ro]
kmWrite32(0x8062c658, 0x38800019);
kmWrite32(0x8062c79c, 0x38800019);
kmWrite32(0x80633a98, 0x38600019);
kmWrite32(0x8062c8e0, 0x38800019);
kmWrite32(0x80633970, 0x38600019);
kmWrite32(0x8083d618, 0x60000000);

extern "C" void sInstance__8Racedata(void*);
extern "C" void sInstance__10SectionMgr(void*);
asmFunc EnhancedPauseMenu1() {
  ASM(
  lwz r3, sInstance__10SectionMgr@l (r6);
  lwz r12, sInstance__8Racedata@l (r6);
  lwz r0, 0x1760 (r12);
  cmpwi r0, 2;
  beq end;

  cmpwi r4, 0x49;
  beq decreaseRaceNum;

  cmpwi r4, 0x4A;
  bne end;

  li r4, 0x4B;

  cmpwi r0, 1;
  beq decreaseRaceNum;

  li r4, 0x4C;

  decreaseRaceNum:
  lwz r6, 0x98 (r3);
  lwz r31, 0x60 (r6);
  subi r31, r31, 1;
  stw r31, 0x60 (r6);

  li r31, 5;
  stw r31, 0x1764 (r12);

  end:
  mr r31, r5;
  blr;
  )
}
kmCall(0x806024d8, EnhancedPauseMenu1);

extern "C" void sInstance__8Racedata(void*);
asmFunc EnhancedPauseMenu2() {
  ASM(
  lis r3, sInstance__8Racedata@ha;
  lwz r3, sInstance__8Racedata@l (r3);
  lwz r4, 0x1760 (r3);
  cmpwi r4, 2;
  beq end;
  li r4, 0x1;
  stw r4, 0xD18 (r3);
  stw r4, 0xE08 (r3);
  stw r4, 0xEF8 (r3);

  end:
  li        r3, 0x6C4;
  blr;
  )
}
kmCall(0x80623df4, EnhancedPauseMenu2);

kmWrite32(0x80859068, 0x48000808);
kmWrite32(0x80858e38, 0x48000040);

//Goomba Size Memorizer [_tZ]
kmWrite32(0x80821E78, 0x38600158);
kmWrite32(0x806DC750, 0xD19D0044);
kmWrite32(0x806DC6F0, 0xD19D0044);
kmWrite32(0x806DCB30, 0xD19C0044);
kmWrite32(0x806DCAD4, 0xD19C0040);

asmFunc GoombaSizeMemorizer1() {
    ASM(
        nofralloc;
  lfs       f8, 0x3C(r29);
  lfs       f7, 0x40(r29);
  lfs       f6, 0x44(r29);
  stfs      f8, 0x14C(r29);
  stfs      f7, 0x150(r29);
  stfs      f6, 0x154(r29);
  li        r30, 0;
  blr;

    )
}
kmCall(0x806db1b4, GoombaSizeMemorizer1);

asmFunc GoombaSizeMemorizer2() {
    ASM(
        nofralloc;
  lfs       f9, 0x14C(r29);
  lfs       f10, 0x150(r29);
  lfs       f11, 0x154(r29);
  fmul      f12, f11, f1;
  fmul      f1, f9, f1;
  fmul      f0, f10, f0;
  stfs      f1, 0x3C(r29);
  blr;

    )
}
kmCall(0x806DC6E8, GoombaSizeMemorizer2);
kmCall(0x806DC748, GoombaSizeMemorizer2);

asmFunc GoombaSizeMemorizer3() {
    ASM(
        nofralloc;
  lfs       f9, 0x14C(r28);
  lfs       f10, 0x150(r28);
  lfs       f11, 0x154(r28);
  fmul      f12, f11, f1;
  fmul      f1, f9, f1;
  fmul      f0, f10, f0;
  stfs      f1, 0x3C(r28);
  blr;

    )
}
kmCall(0x806DCB28, GoombaSizeMemorizer3);

asmFunc GoombaSizeMemorizer4() {
    ASM(
        nofralloc;
  lfs       f9, 0x14C(r28);
  lfs       f10, 0x150(r28);
  lfs       f11, 0x154(r28);
  fmul      f12, f11, f0;
  fmul      f13, f9, f0;
  fmul      f0, f10, f0;
  stfs      f12, 0x3C(r28);
  blr;

    )
}
kmCall(0x806DCACC, GoombaSizeMemorizer4);

//Poocha Fix [Ro]
asmFunc PochaFix() {
    ASM(
        nofralloc;
  lbz       r31, 0x78(r3);
  cmpwi     r31, 0;
  beq-      loc_0x24;
  lbz       r31, 0xE(r3);
  addi      r31, r31, 0x1;
  cmpwi     r31, 0x3C;
  blt-      loc_0x24;
  li        r31, 0;
  stb       r31, 0x78(r3);

loc_0x24:
  stb       r31, 0xE(r3);
  mr        r31, r3;
  blr;

    )
}
kmCall(0x8069B3A8, PochaFix);
}//namespace Race
}//namespace Pulsar