#include "Weapon_Modules/Emitter_Modules/Emitter_WeaponModule.h"

void UEmitter_WeaponModule::AttachModule_Implementation(AActor* Actor)
{
	Super::AttachModule_Implementation(Actor);
}

void UEmitter_WeaponModule::IntegrateWithAttack_Implementation()
{
}

bool UEmitter_WeaponModule::ParentIsValid_Implementation()
{
	return Super::ParentIsValid_Implementation();
}
