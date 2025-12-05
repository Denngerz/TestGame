
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestGame/Interaction/InteractionInterface.h"
#include "WeaponBase.generated.h"

class USphereComponent;

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Unarmed        UMETA(DisplayName = "Unarmed"),
	Rifle		   UMETA(DisplayName = "Rifle")
};

UENUM(BlueprintType)
enum class EWeaponName : uint8
{
	Unarmed          UMETA(DisplayName = "Unarmed"),
	AutomaticRifle   UMETA(DisplayName = "AutomaticRifle"),
	EnergyRifle      UMETA(DisplayName = "EnergyRifle"),
};

UENUM(BlueprintType)
enum class EWeaponFireMode : uint8
{
	Single        UMETA(DisplayName = "Single"),
	Burst		  UMETA(DisplayName = "Burst"),
	Automatic     UMETA(DisplayName = "Automatic"),
};

UCLASS()
class TESTGAME_API AWeaponBase : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

public:
	AWeaponBase();

	virtual void Interact_Implementation(AActor* Interactor) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	EWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	EWeaponName WeaponName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	EWeaponFireMode FireMode;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USphereComponent> InteractionCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USceneComponent> LeftHandIK;
};
