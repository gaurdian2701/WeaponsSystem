#include "Weapon_Modules/FiringMode_Modules/UFiringMode_WeaponModule.h"


void UFiringMode_WeaponModule::BeginPlay()
{
	Super::BeginPlay();
	
	if (FiringData.Num() < 1)
		ToggleCanFire(false);
}

void UFiringMode_WeaponModule::AttachModule_Implementation(AActor* Actor)
{
	Super::AttachModule_Implementation(Actor);
}

bool UFiringMode_WeaponModule::ParentIsValid_Implementation()
{
	return Super::ParentIsValid_Implementation();
}

void UFiringMode_WeaponModule::IntegrateWithAttack_Implementation()
{
	if (CanFire)
		ToggleCanFire(false);

	switch (FiringTypeForModule)
	{
	default:
	case EWeaponFiringType::CONTINUOUS:
		FireContinuousRound();
		break;
	case EWeaponFiringType::BURST:
		FireBurstRound();
		break;
	}
}

void UFiringMode_WeaponModule::FireContinuousRound()
{
	GetWorld()->GetTimerManager().SetTimer(FiringTimerHandle, this, &UFiringMode_WeaponModule::OnFireEnded,
		FiringData[0].DelayAfterFire, false, -1);
}

void UFiringMode_WeaponModule::FireBurstRound()
{
	if (CurrentFireDataIndex == FiringData.Num())
		CurrentFireDataIndex = 0;
	
	GetWorld()->GetTimerManager().SetTimer(FiringTimerHandle, this, &UFiringMode_WeaponModule::OnFireEnded,
	FiringData[CurrentFireDataIndex++].DelayAfterFire, false, -1);
}

void UFiringMode_WeaponModule::ToggleCanFire(bool Toggle)
{
	CanFire = Toggle;
}

void UFiringMode_WeaponModule::OnFireEnded()
{
	ToggleCanFire(true);
}

bool UFiringMode_WeaponModule::CanModuleFire() const
{
	return CanFire;
}
