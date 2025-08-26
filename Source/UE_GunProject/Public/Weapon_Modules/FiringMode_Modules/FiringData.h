#pragma once

#include "CoreMinimal.h"
#include "WeaponFiringType.h"
#include "FiringData.generated.h"

USTRUCT()
struct FFiringData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Delay after this shot(in seconds)")
	float DelayAfterFire = 0.5f;
};

UCLASS(BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class UFiringDataObject : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Firing Mode Type")
	EWeaponFiringType FiringTypeForModule = EWeaponFiringType::CONTINUOUS;
	
	UPROPERTY(EditAnywhere)
	TArray<FFiringData> FiringDataArray;
};
