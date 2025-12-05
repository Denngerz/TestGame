
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

struct FOnAttributeChangeData;
class UHealthSet;
class UAbilitySystemComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOutOfHealthSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChanged, float, NewValue);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTGAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	UHealthComponent();

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnOutOfHealthSignature OnOutOfHealth;

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthChanged OnCurrentHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnMaxHealthChanged OnMaxHealthChanged;
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Health")
	float GetHealth() const;
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Health")
	float GetMaxHealth() const;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, Category="Health")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, Category="Health")
	TObjectPtr<const UHealthSet> HealthSet;
	
	void OnNewHealth(const FOnAttributeChangeData& Data) const;

	void OnNewMaxHealth(const FOnAttributeChangeData& Data) const;

	void InitASCHealth();
};
