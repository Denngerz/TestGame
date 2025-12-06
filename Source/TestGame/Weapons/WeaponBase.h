
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

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Weapon")
	void Shoot();

	UFUNCTION(BlueprintCallable, Category="Weapon")
	void Reload();

	UFUNCTION(BlueprintCallable)
	int32 GetCurrentBulletsAmount();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	float Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	float CurrentBulletsAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	float MaxAmmoCapacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USphereComponent> InteractionCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USceneComponent> LeftHandIK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USceneComponent> ShootPoint;
};
