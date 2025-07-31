#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Recoilable.generated.h"

UINTERFACE()
class URecoilable : public UInterface
{
	GENERATED_BODY()
};

class IRecoilable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DoRecoil(float RecoilAngle, float RecoilLength);
};
