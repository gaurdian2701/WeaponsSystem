#pragma once

#include "CoreMinimal.h"
#include "FiringData.generated.h"

USTRUCT()
struct FFiringData
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly, Category = "Delay after this shot(in seconds)")
	float DelayAfterFire = 0.5f;

	//Other data to be included later such as recoil power, how it affects recoil recovery and so on
};
