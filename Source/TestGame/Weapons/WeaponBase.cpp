
#include "WeaponBase.h"
#include "Components/SphereComponent.h"

AWeaponBase::AWeaponBase()
{
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	
	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;
	
	InteractionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	InteractionCollision->SetupAttachment(RootComponent);
	
	LeftHandIK = CreateDefaultSubobject<USceneComponent>(TEXT("LeftHandIK"));
	LeftHandIK->SetupAttachment(RootComponent);

	ShootPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ShootPoint"));
	ShootPoint->SetupAttachment(RootComponent);

	WeaponType = EWeaponType::Unarmed;
	WeaponName = EWeaponName::Unarmed;
	FireMode   = EWeaponFireMode::Single;
}

int32 AWeaponBase::GetCurrentBulletsAmount()
{
	return CurrentBulletsAmount;
}

void AWeaponBase::SetCurrentBulletsAmount(int32 NewAmount)
{
	CurrentBulletsAmount = FMath::Min(NewAmount, MaxAmmoCapacity);
}

void AWeaponBase::DecreaseBulletsAmmount()
{
	if (CurrentBulletsAmount > 0)
	{
		CurrentBulletsAmount--;
	}
}

bool AWeaponBase::CanShoot()
{
	return CurrentBulletsAmount > 0;
}
