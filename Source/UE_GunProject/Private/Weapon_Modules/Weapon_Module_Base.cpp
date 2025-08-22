#include "Weapon_Modules/Weapon_Module_Base.h"

#include "Kismet/KismetSystemLibrary.h"

void UWeapon_Module_Base::IntegrateWithAttack_Implementation()
{

}

void UWeapon_Module_Base::AttachModule_Implementation(AActor* Actor)
{
	checkf(Execute_ParentIsValid(this), TEXT("Parent is invalid for %s"), *this->GetName());
	ParentActor = GetOwner();
}

inline bool UWeapon_Module_Base::ParentIsValid_Implementation()
{
	return GetOwner()->Implements<UFireable>();
}