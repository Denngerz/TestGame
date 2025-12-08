
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestGameCharacter.generated.h"

class UWeaponsHolder;
class UHealthComponent;
class UAbilitySystemComponent;

UCLASS()
class TESTGAME_API ATestGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATestGameCharacter();

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health Component", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHealthComponent> HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AbilitySystem", Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
};
