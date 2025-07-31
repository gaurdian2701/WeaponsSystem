#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Weapon_Modules/WeaponModule.h"
#include "Weapon_Modules/Weapon_Module_Base.h"
#include "Shot_WeaponModule.generated.h"


UCLASS(BlueprintType, Blueprintable)
class UE_GUNPROJECT_API UShot_WeaponModule : public UWeapon_Module_Base
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	FVector ShotStartLocation = FVector::ZeroVector;
	UPROPERTY(BlueprintReadOnly)
	FVector ShotEndLocation = FVector::ZeroVector;
	
public:
	UShot_WeaponModule();

protected:
	virtual void BeginPlay() override;
	virtual void AttachModule_Implementation(AActor* Actor) override;
	virtual void IntegrateWithAttack_Implementation() override;
	virtual bool ParentIsValid_Implementation() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void DoTrace();
};
