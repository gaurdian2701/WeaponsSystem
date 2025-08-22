#pragma once

#include "CoreMinimal.h"
#include "Fireable.h"
#include "GameFramework/Actor.h"
#include "Weapon_Modules/FiringMode_Modules/UFiringMode_WeaponModule.h"
#include "Weapon_Modules/Shot_Modules/Shot_WeaponModule.h"
#include "Weapon.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UE_GUNPROJECT_API AWeapon : public AActor, public IFireable
{
	GENERATED_BODY()

public:
	virtual FVector GetFiringStartPosition_Implementation() override;
	virtual void Fire_Implementation() override;
	inline TObjectPtr<AActor> GetWeaponOwner();

protected:
	virtual void BeginPlay() override;
	void AttachModules();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void InitWeapon(AActor* Parent);

protected:
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<AActor> WeaponOwner = nullptr;
	UPROPERTY()
	TObjectPtr<UFiringMode_WeaponModule> FiringModule = nullptr;
	UPROPERTY()
	TArray<UActorComponent*> WeaponModules;
};
