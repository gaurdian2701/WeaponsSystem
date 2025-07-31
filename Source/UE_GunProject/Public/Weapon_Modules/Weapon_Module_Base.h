#pragma once

#include "CoreMinimal.h"
#include "WeaponModule.h"
#include "Fireable.h"
#include "UObject/Object.h"
#include "Weapon_Module_Base.generated.h"

UCLASS()
class UE_GUNPROJECT_API UWeapon_Module_Base : public UActorComponent, public IWeaponModule
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AActor> ParentActor = nullptr;
	
public:
	virtual void IntegrateWithAttack_Implementation() override;
	virtual void AttachModule_Implementation(AActor* Actor) override;
	virtual bool ParentIsValid_Implementation() override;
};
