
#include "TestGameGameState.h"
#include "TestGame/Gamemodes/TestGameGamemode.h"

ATestGameGameState::ATestGameGameState()
	:CurrentAICount(0)
{
}

int32 ATestGameGameState::GetCurrentAICount()
{
	return CurrentAICount;
}

bool ATestGameGameState::IncreaseAICount()
{
	ATestGameGamemode* GameMode = Cast<ATestGameGamemode>(GetWorld()->GetAuthGameMode());
	
	if (!GameMode)
	{
		return false;
	}
	
	if (CurrentAICount < GameMode->GetMaxAIAmount())
	{
		CurrentAICount++;
		return true;
	}

	return false;
}

bool ATestGameGameState::DecreaseAICount()
{
	if (CurrentAICount > 0)
	{
		CurrentAICount--;
		return true;
	}
	
	return false;
}
