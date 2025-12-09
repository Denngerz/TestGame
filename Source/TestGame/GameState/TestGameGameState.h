
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TestGameGameState.generated.h"

UCLASS()
class TESTGAME_API ATestGameGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ATestGameGameState();

	UFUNCTION(BlueprintCallable)
	int32 GetCurrentAICount();

	UFUNCTION(BlueprintCallable)
	bool IncreaseAICount();

	UFUNCTION(BlueprintCallable)
	bool DecreaseAICount();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI Count", meta=(AllowPrivateAccess="true"))
	int32 CurrentAICount;
};
