
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponsHolder.generated.h"

class AWeaponBase;

USTRUCT(Blueprintable)
struct FStorageWeapon : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AWeaponBase> Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsEmpty = true;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTGAME_API UWeaponsHolder : public UActorComponent
{
	GENERATED_BODY()

public:
	UWeaponsHolder();

	UFUNCTION(BlueprintCallable)
	int32 TryAddWeapon(AWeaponBase* NewWeapon);

	UFUNCTION(BlueprintCallable)
	FStorageWeapon GetWeaponAtIndex(int32 Index);

	UFUNCTION(BlueprintCallable)
	bool SetWeaponAtIndex(AWeaponBase* NewWeapon, int32 Index);

	UFUNCTION(BlueprintCallable)
	bool EmptySlotsLeft();

	UFUNCTION(BlueprintCallable)
	bool DropWeaponAtIndex(int32 Index);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	TArray<FStorageWeapon> StoredWeapons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Weapon", meta=(AllowPrivateAccess="true"))
	int32 StorageAmount;
};
