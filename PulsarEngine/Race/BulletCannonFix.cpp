#include <MarioKartWii/Item/ItemManager.hpp>
#include <MarioKartWii/Item/Obj/Kumo.hpp>
#include <MarioKartWii/Kart/KartMovement.hpp>
#include <Info.hpp>


namespace yoshpackDX {
namespace Race {
	//Code is interpreted from the implementation found in Formula Kart Wii.

//# Check if it's the first call before the race
kmCallDefAsm(0x8057855C) {
loc_0x0:	
lwz r12, 0x28(r12)
cmpwi cr7, r12, 0
bnelr+ cr7

//# If so execute original instruction
stfs f0, 0x2C(r30)
blr
}

}//namespace Race
}//namespace Pulsar