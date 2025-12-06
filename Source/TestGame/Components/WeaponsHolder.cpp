
#include "WeaponsHolder.h"

#include "TestGame/Weapons/WeaponBase.h"

UWeaponsHolder::UWeaponsHolder()
	:StorageAmount(2)
{
	StoredWeapons.SetNum(StorageAmount);
}

int32 UWeaponsHolder::TryAddWeapon(AWeaponBase* NewWeapon)
{
	if (!NewWeapon)
	{
		return -1;
	}
	
	for (int32 i = 0; i < StoredWeapons.Num(); i++)
	{
		if (StoredWeapons[i].Weapon == nullptr)
		{
			StoredWeapons[i].Weapon = NewWeapon->GetClass();
			StoredWeapons[i].CurrentAmmo = NewWeapon->GetCurrentBulletsAmount();
			StoredWeapons[i].Index = i;
			return i;
		}
	}
	
	return -1;
}

FStorageWeapon UWeaponsHolder::GetWeaponAtIndex(int32 Index)
{
	if (StoredWeapons.IsValidIndex(Index))
	{
		return StoredWeapons[Index];
	}

	return FStorageWeapon();
}

bool UWeaponsHolder::SetWeaponAtIndex(AWeaponBase* NewWeapon, int32 Index)
{
	if (NewWeapon && StoredWeapons.IsValidIndex(Index))
	{
		StoredWeapons[Index].Weapon = NewWeapon->GetClass();
		StoredWeapons[Index].CurrentAmmo = NewWeapon->GetCurrentBulletsAmount();
		return true;
	}

	return false;
}

bool UWeaponsHolder::EmptySlotsLeft()
{
	for (const FStorageWeapon& Slot : StoredWeapons)
	{
		if (Slot.Weapon == nullptr)
		{
			return true;
		}
	}

	return false;
}

bool UWeaponsHolder::DropWeaponAtIndex(int32 Index)
{
	if (StoredWeapons.IsValidIndex(Index))
	{
		StoredWeapons[Index].Weapon = nullptr;
		StoredWeapons[Index].CurrentAmmo = 0;
		return true;
	}

	return false;
}
