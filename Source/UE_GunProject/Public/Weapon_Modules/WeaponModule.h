
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WeaponModule.generated.h"


UINTERFACE()
class UWeaponModule : public UInterface
{
	GENERATED_BODY()
};

class IWeaponModule
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void IntegrateWithAttack();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void AttachModule(AActor* Actor);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool ParentIsValid();
};