#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Fireable.generated.h"

class AWeapon;

UINTERFACE()
class UE_GUNPROJECT_API UFireable : public UInterface
{
	GENERATED_BODY()
};

class IFireable
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FVector GetFiringStartPosition();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Fire();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void EquipWeapon(AWeapon* Weapon);
};
