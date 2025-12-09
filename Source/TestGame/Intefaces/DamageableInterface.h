
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageableInterface.generated.h"

UINTERFACE(BlueprintType)
class UDamageableInterface : public UInterface
{
	GENERATED_BODY()
};

class TESTGAME_API IDamageableInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Damagable")
	void TakeDamage(float Damage, AActor* Caller);
};
