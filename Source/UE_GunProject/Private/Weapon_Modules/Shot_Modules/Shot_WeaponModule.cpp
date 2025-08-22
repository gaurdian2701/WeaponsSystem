#include "Weapon_Modules/Shot_Modules/Shot_WeaponModule.h"

#include "Weapons/Weapon.h"

UShot_WeaponModule::UShot_WeaponModule()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UShot_WeaponModule::BeginPlay()
{
	Super::BeginPlay();
}

void UShot_WeaponModule::AttachModule_Implementation(AActor* Actor)
{
	Super::AttachModule_Implementation(Actor);
}

void UShot_WeaponModule::IntegrateWithAttack_Implementation()
{
	DoTrace();
}

bool UShot_WeaponModule::ParentIsValid_Implementation()
{
	return Super::ParentIsValid_Implementation();
}

