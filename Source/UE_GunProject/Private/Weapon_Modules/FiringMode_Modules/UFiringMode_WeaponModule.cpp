#include "Weapon_Modules/FiringMode_Modules/UFiringMode_WeaponModule.h"


void UFiringMode_WeaponModule::BeginPlay()
{
	Super::BeginPlay();

	checkf(FiringDataObject != nullptr, TEXT("Firing Data Object is null"));

	if (FiringDataObject->FiringDataArray.Num() < 1)
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

	switch (FiringDataObject->FiringTypeForModule)
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
	                                       FiringDataObject->FiringDataArray[0].DelayAfterFire, false, -1);
}

void UFiringMode_WeaponModule::FireBurstRound()
{
	GetWorld()->GetTimerManager().SetTimer(FiringTimerHandle, this, &UFiringMode_WeaponModule::OnFireEnded,
	                                       FiringDataObject->FiringDataArray[CurrentFireDataIndex++].DelayAfterFire,
	                                       false, -1);

	if (CurrentFireDataIndex == FiringDataObject->FiringDataArray.Num())
		CurrentFireDataIndex = 0;
}

void UFiringMode_WeaponModule::ToggleCanFire(bool Toggle)
{
	CanFire = Toggle;
}

inline void UFiringMode_WeaponModule::OnFireEnded()
{
	ToggleCanFire(true);
}

bool UFiringMode_WeaponModule::CanModuleFire() const
{
	return CanFire;
}

bool UFiringMode_WeaponModule::IsCurrentlyFiring() const
{
	return FiringTimerHandle.IsValid();
}

float UFiringMode_WeaponModule::GetDelayUntilNextRoundFired() const
{
	switch (FiringDataObject->FiringTypeForModule)
	{
	default:
	case EWeaponFiringType::CONTINUOUS:
		return FiringDataObject->FiringDataArray[0].DelayAfterFire;
	case EWeaponFiringType::BURST:
		return FiringDataObject->FiringDataArray[CurrentFireDataIndex].DelayAfterFire;
	}
}
