#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RecoilData.generated.h"

UCLASS(BlueprintType, Blueprintable, DefaultToInstanced, EditInlineNew)
class UE_GUNPROJECT_API URecoilData : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bullet Mass(in KG - Increases Recoil)")
	float BulletMass = 0.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bullet Velocity(M/S - Increases Recoil)")
	float BulletVelocity = 0.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon Mass(in KG - Decreases Recoil)")
	float WeaponMass = 0.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Resistance Constant - Decreases Recoil")
	float ResistanceConstant = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Recoil Alpha(How strong is vertical recoil)")
	float RecoilAlpha = 1.0f;
};
