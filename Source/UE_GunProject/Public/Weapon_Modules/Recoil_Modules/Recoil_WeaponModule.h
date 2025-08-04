// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon_Modules/Weapon_Module_Base.h"
#include "Weapon_Modules/FiringMode_Modules/UFiringMode_WeaponModule.h"
#include "Recoil_WeaponModule.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UE_GUNPROJECT_API URecoil_WeaponModule : public UWeapon_Module_Base
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bullet Mass(Increases Recoil)")
	float BulletMass = 0.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bullet Velocity(Increases Recoil)")
	float BulletVelocity = 0.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon Mass(Decreases Recoil)")
	float WeaponMass = 0.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Resistance Constant")
	float ResistanceConstant = 0.0f;
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
	const int RECOIL_MULTIPLIER = 1000;
	const int M_TO_CM = 100;

	void DoRecoilForCurrentShot(float DeltaTime);
	inline void AfterRecoil();

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


