#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Weapon_Modules/WeaponModule.h"
#include "Weapon_Modules/Weapon_Module_Base.h"
#include "Emitter_WeaponModule.generated.h"


UCLASS()
class UE_GUNPROJECT_API UEmitter_WeaponModule : public UWeapon_Module_Base
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	uint32 NumberOfEmitters;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<USceneComponent*> Emitters;
public:
	virtual void AttachModule_Implementation(AActor* Actor) override;
	virtual void IntegrateWithAttack_Implementation() override;
	virtual bool ParentIsValid_Implementation() override;
};
