#include "Weapon_Modules/Weapon_Module_Base.h"

#include "Kismet/KismetSystemLibrary.h"

void UWeapon_Module_Base::IntegrateWithAttack_Implementation()
{

}

void UWeapon_Module_Base::AttachModule_Implementation(AActor* Actor)
{
	if (Execute_ParentIsValid(this))
		ParentActor = GetOwner();
	else
		UKismetSystemLibrary::QuitGame(GetWorld(),
			nullptr, EQuitPreference::Quit, false);
}

inline bool UWeapon_Module_Base::ParentIsValid_Implementation()
{
	return GetOwner()->Implements<UFireable>();
}