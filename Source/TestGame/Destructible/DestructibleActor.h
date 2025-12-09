
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestGame/Intefaces/DamageableInterface.h"
#include "DestructibleActor.generated.h"

class USphereComponent;

UCLASS()
class TESTGAME_API ADestructibleActor : public AActor, public IDamageableInterface
{
	GENERATED_BODY()
	
public:
	ADestructibleActor();
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	float Health;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess="true"))
	TObjectPtr<USphereComponent> SphereComponent;
};
