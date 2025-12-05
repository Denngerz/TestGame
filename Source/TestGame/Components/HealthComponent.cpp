
#include "HealthComponent.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "TestGame/AbilitySystem/Attributes/HealthSet.h"

UHealthComponent::UHealthComponent()
	: AbilitySystemComponent (nullptr)
	, HealthSet (nullptr)
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UHealthComponent::GetHealth() const
{
	return HealthSet ? HealthSet->GetHealthPoints() : 0.f;
}

float UHealthComponent::GetMaxHealth() const
{
	return HealthSet ? HealthSet->GetMaxHealthPoints() : 0.f;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	InitASCHealth();
}

void UHealthComponent::OnNewHealth(const FOnAttributeChangeData& Data) const
{
	OnCurrentHealthChanged.Broadcast(Data.NewValue);

	if (Data.NewValue <= 0.f)
	{
		OnOutOfHealth.Broadcast();
	}
}

void UHealthComponent::OnNewMaxHealth(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UHealthComponent::InitASCHealth()
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(GetOwner()))
	{
		AbilitySystemComponent = ASCInterface->GetAbilitySystemComponent();
	}
	
	if (!ensureMsgf(AbilitySystemComponent, TEXT("HealthComponent [%s]: AbilitySystemComponent is null!"), *GetNameSafe(this)))
	{
		return;
	}

	HealthSet = AbilitySystemComponent->GetSet<UHealthSet>();
	if (!ensureMsgf(HealthSet, TEXT("HealthComponent [%s]: Failed to retrieve HealthSet!"), *GetNameSafe(this)))
	{
		return;
	}

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HealthSet->GetHealthPointsAttribute()).AddUObject(this, &ThisClass::OnNewHealth);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(HealthSet->GetMaxHealthPointsAttribute()).AddUObject(this, &ThisClass::OnNewMaxHealth);

	OnCurrentHealthChanged.Broadcast(GetHealth());
	OnMaxHealthChanged.Broadcast(GetMaxHealth());
}