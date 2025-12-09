
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestGame/Intefaces/InteractionInterface.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	EWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	EWeaponName WeaponName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
	EWeaponFireMode FireMode;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Weapon")
	void Shoot();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Weapon")
	void Reload();

	UFUNCTION(BlueprintCallable)
	int32 GetCurrentBulletsAmount();

	UFUNCTION(BlueprintCallable)
	void SetCurrentBulletsAmount(int32 NewAmount);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	float Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	int32 CurrentBulletsAmount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	int32 MaxAmmoCapacity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USphereComponent> InteractionCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USceneComponent> LeftHandIK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USceneComponent> ShootPoint;

	UFUNCTION(BlueprintCallable)
	void DecreaseBulletsAmmount();

	UFUNCTION(BlueprintCallable)
	bool CanShoot();
};
