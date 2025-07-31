#pragma once

#include "CoreMinimal.h"
#include "FiringData.h"
#include "WeaponFiringType.h"
#include "UObject/Object.h"
#include "Weapon_Modules/WeaponModule.h"
#include "Weapon_Modules/Weapon_Module_Base.h"
#include "UFiringMode_WeaponModule.generated.h"


UCLASS(Blueprintable, BlueprintType)
class UE_GUNPROJECT_API UFiringMode_WeaponModule : public UWeapon_Module_Base
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Firing Mode Type")
	EWeaponFiringType FiringTypeForModule = EWeaponFiringType::CONTINUOUS;
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing Data Array")
	TArray<FFiringData> FiringData;

protected:
	void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void ToggleCanFire(bool Toggle);

	UFUNCTION(BlueprintCallable)
	void FireContinuousRound();

	UFUNCTION(BlueprintCallable)
	void FireBurstRound();

	UFUNCTION()
	void OnFireEnded();
	
private:
	FTimerHandle FiringTimerHandle = FTimerHandle();
	bool CanFire = true;
	int8 CurrentFireDataIndex = 0;
	const int MaxFiringDataArrayLength = 256;

public:
	virtual void IntegrateWithAttack_Implementation() override;
	virtual void AttachModule_Implementation(AActor* Actor) override;
	virtual bool ParentIsValid_Implementation() override;
	bool CanModuleFire() const;
};
