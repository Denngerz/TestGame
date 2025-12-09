
#include "TestGameGamemode.h"
#include "TestGame/GameState/TestGameGameState.h"

ATestGameGamemode::ATestGameGamemode()
	:MaxAIAmount(10)
{
}

int32 ATestGameGamemode::GetMaxAIAmount()
{
	return MaxAIAmount;
}

bool ATestGameGamemode::CanSpawnAI()
{
	ATestGameGameState* GS = GetGameState<ATestGameGameState>();
	if (GS)
	{
		return GS->GetCurrentAICount() < GetMaxAIAmount();
	}
	
	return false;
}
