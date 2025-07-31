#include "Weapons/Weapon.h"

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	WeaponModules = GetComponentsByInterface(UWeaponModule::StaticClass());

	for (int8 i = 0; i < WeaponModules.Num(); i++)
	{
		if (Cast<UFiringMode_WeaponModule>(WeaponModules[i]))
		{
			FiringModule = Cast<UFiringMode_WeaponModule>(WeaponModules[i]);
			WeaponModules.RemoveAt(i);
			break;
		}
	}

	AttachModules();
}

void AWeapon::AttachModules()
{

	checkf(WeaponModules.Num() < 1, TEXT("No Weapon Modules attached to %s"), *GetName());

	IWeaponModule::Execute_AttachModule(FiringModule, this);
	
	for (int8 i = 0; i < WeaponModules.Num(); i++)
	{
		IWeaponModule::Execute_AttachModule(WeaponModules[i], this);
	}
}

FVector AWeapon::GetFiringStartPosition_Implementation()
{
	return IFireable::GetFiringStartPosition_Implementation();
}

void AWeapon::Fire_Implementation()
{
	checkf(FiringModule != nullptr, TEXT("Firing module for %s is null!"), *GetName());

	if (FiringModule->CanModuleFire())
	{
		IWeaponModule::Execute_IntegrateWithAttack(FiringModule);
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Firing");

		for (int8 i = 0; i < WeaponModules.Num(); i++)
			IWeaponModule::Execute_IntegrateWithAttack(WeaponModules[i]);
	}
}

