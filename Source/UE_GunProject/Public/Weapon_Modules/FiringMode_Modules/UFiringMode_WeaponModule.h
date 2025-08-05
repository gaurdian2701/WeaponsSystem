#pragma once

#include "CoreMinimal.h"
#include "FiringData.h"
#include "UObject/Object.h"
#include "Weapon_Modules/Weapon_Module_Base.h"
#include "UFiringMode_WeaponModule.generated.h"


UCLASS(Blueprintable, BlueprintType)
class UE_GUNPROJECT_API UFiringMode_WeaponModule : public UWeapon_Module_Base
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing Data Object")
	TSubclassOf<UFiringDataObject> FiringDataClass;

	UPROPERTY()
	TObjectPtr<UFiringDataObject> FiringDataObject = nullptr;

protected:
	void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void ToggleCanFire(bool Toggle);

	UFUNCTION(BlueprintCallable)
	void FireContinuousRound();

	UFUNCTION(BlueprintCallable)
	void FireBurstRound();
	
private:
	FTimerHandle FiringTimerHandle = FTimerHandle();
	bool CanFire = true;
	int8 CurrentFireDataIndex = 0;
	const int MaxFiringDataArrayLength = 256;

private:
	inline void OnFireEnded();

public:
	virtual void IntegrateWithAttack_Implementation() override;
	virtual void AttachModule_Implementation(AActor* Actor) override;
	virtual bool ParentIsValid_Implementation() override;
	bool CanModuleFire() const;
	bool IsCurrentlyFiring() const;
	float GetDelayUntilNextRoundFired() const;
};
