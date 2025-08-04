#pragma once

#include "CoreMinimal.h"
#include "WeaponFiringType.h"
#include "FiringData.generated.h"

USTRUCT()
struct FFiringData
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, Category = "Delay after this shot(in seconds)")
	float DelayAfterFire = 0.5f;
};

UCLASS(BlueprintType, Blueprintable)
class UFiringDataObject : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Firing Mode Type")
	EWeaponFiringType FiringTypeForModule = EWeaponFiringType::CONTINUOUS;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<FFiringData> FiringDataArray;
};
