
#include "TestGameCharacter.h"

#include "AbilitySystemComponent.h"
#include "TestGame/Components/HealthComponent.h"
#include "TestGame/Components/WeaponsHolder.h"

ATestGameCharacter::ATestGameCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

void ATestGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	HealthComponent->InitASCHealth(AbilitySystemComponent);
}
