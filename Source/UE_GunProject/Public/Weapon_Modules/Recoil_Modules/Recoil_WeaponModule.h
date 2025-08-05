// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RecoilData.h"
#include "Weapon_Modules/Weapon_Module_Base.h"
#include "Weapon_Modules/FiringMode_Modules/UFiringMode_WeaponModule.h"
#include "Recoil_WeaponModule.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UE_GUNPROJECT_API URecoil_WeaponModule : public UWeapon_Module_Base
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Recoil Data")
	TSubclassOf<URecoilData> RecoilDataClass;
	UPROPERTY()
	TObjectPtr<URecoilData> RecoilDataObject = nullptr;
	UPROPERTY()
	TObjectPtr<UFiringMode_WeaponModule> FiringModule = nullptr;

private:
	FTimerHandle RecoilTimerHandle = FTimerHandle();
	float RecoilAngle = 0.0f;
	float CurrentRecoilAngle = 0.0f;
	float KickbackStrength = 0.0f;
	float CurrentKickbackStrength = 0.0f;
	bool CanRecoil = false;
	bool KickbackEnded = false;
	const int M_TO_CM = 100;

	void DoRecoilForCurrentShot(float DeltaTime);
	inline void AfterRecoil();
	inline void ShowRecoilVisual();

public:
	URecoil_WeaponModule();
	virtual void AttachModule_Implementation(AActor* Actor) override;
	virtual void IntegrateWithAttack_Implementation() override;
	virtual bool ParentIsValid_Implementation() override;

protected:
	virtual void TickComponent(float DeltaTime,
		enum ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;
	virtual void CalculateRecoilAngle();
	virtual void CalculateKickbackStrength();
};


