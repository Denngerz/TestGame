
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

	WeaponType = EWeaponType::Unarmed;
	WeaponName = EWeaponName::Unarmed;
	FireMode   = EWeaponFireMode::Single;
}

void AWeaponBase::Interact_Implementation(AActor* Interactor)
{
	IInteractionInterface::Interact_Implementation(Interactor);

	UE_LOG(LogTemp, Warning, TEXT("HealthComponent [%s]: AbilitySystemComponent is null!"), *GetNameSafe(this));
}
