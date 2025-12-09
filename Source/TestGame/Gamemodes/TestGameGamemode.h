
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestGameGamemode.generated.h"

UCLASS()
class TESTGAME_API ATestGameGamemode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATestGameGamemode();

	UFUNCTION(BlueprintCallable)
	int32 GetMaxAIAmount();

	UFUNCTION(BlueprintCallable)
	bool CanSpawnAI();
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI Count", meta=(AllowPrivateAccess="true"))
	int32 MaxAIAmount;
};
