#include "Weapon_Modules/Weapon_Module_Base.h"

#include "Kismet/KismetSystemLibrary.h"

void UWeapon_Module_Base::IntegrateWithAttack_Implementation()
{

}

void UWeapon_Module_Base::AttachModule_Implementation(AActor* Actor)
{
	checkf(Execute_ParentIsValid(this), TEXT("Parent is not valid for weapon module!"));
	
	if (Execute_ParentIsValid(this))
		ParentActor = GetOwner();
}

inline bool UWeapon_Module_Base::ParentIsValid_Implementation()
{
	return GetOwner()->Implements<UFireable>();
}