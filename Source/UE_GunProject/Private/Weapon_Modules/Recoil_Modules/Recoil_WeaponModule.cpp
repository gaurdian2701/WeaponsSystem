#include "Weapon_Modules/Recoil_Modules/Recoil_WeaponModule.h"

#include "Recoilable.h"
#include "Kismet/KismetSystemLibrary.h"


URecoil_WeaponModule::URecoil_WeaponModule()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void URecoil_WeaponModule::AttachModule_Implementation(AActor* Actor)
{
	if (Execute_ParentIsValid(this))
		ParentActor = Actor;
	else
		UKismetSystemLibrary::QuitGame(GetWorld(),
	nullptr, EQuitPreference::Quit, false);
}

void URecoil_WeaponModule::IntegrateWithAttack_Implementation()
{
	CalculateRecoilAngle();
	CalculateRecoilLength();
	IRecoilable::Execute_DoRecoil(ParentActor, RecoilAngle, RecoilLength * M_TO_CM);
}

bool URecoil_WeaponModule::ParentIsValid_Implementation()
{
	return Super::ParentIsValid_Implementation() && GetOwner()->Implements<URecoilable>();
}


void URecoil_WeaponModule::BeginPlay()
{
	Super::BeginPlay();
}

void URecoil_WeaponModule::CalculateRecoilAngle()
{
	RecoilAngle =  (2 * BulletMass) / WeaponMass * RECOIL_MULTIPLIER;
}

void URecoil_WeaponModule::CalculateRecoilLength()
{
	RecoilLength = (pow(BulletMass, 2) * pow(BulletVelocity, 2))/(2 * WeaponMass * ResistanceConstant);
}

