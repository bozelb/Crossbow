// FPS_Crossbow


#include "Weapons/WeaponBase.h"
#include "Crossbow/Crossbow.h"

AWeaponBase::AWeaponBase()
{

}

void AWeaponBase::Fire()
{
	WRITE_MESSAGE_TO_SCREEN("Weapon Fired");
}

void AWeaponBase::ReloadWeapon()
{
	WRITE_MESSAGE_TO_SCREEN("Reloaded Weapon");
}
