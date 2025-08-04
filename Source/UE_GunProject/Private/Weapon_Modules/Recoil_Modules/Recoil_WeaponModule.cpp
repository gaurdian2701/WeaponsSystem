#include "Weapon_Modules/Recoil_Modules/Recoil_WeaponModule.h"
#include "Recoilable.h"
#include "Kismet/KismetSystemLibrary.h"

URecoil_WeaponModule::URecoil_WeaponModule()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void URecoil_WeaponModule::BeginPlay()
{
	Super::BeginPlay();
	FiringModule = GetOwner()->GetComponentByClass<UFiringMode_WeaponModule>();
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
	if (!CanRecoil)
		CanRecoil = true;

	GetWorld()->GetTimerManager().SetTimer(RecoilTimerHandle, this, &URecoil_WeaponModule::AfterRecoil,
		FiringModule->GetDelayUntilNextRoundFired(), false);
	
	CalculateRecoilAngle();
	CalculateKickbackStrength();
}

bool URecoil_WeaponModule::ParentIsValid_Implementation()
{
	return Super::ParentIsValid_Implementation() && GetOwner()->Implements<URecoilable>();
}

void URecoil_WeaponModule::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CanRecoil)
	{
		DoRecoilForCurrentShot(DeltaTime);
	}
}

void URecoil_WeaponModule::CalculateRecoilAngle()
{
	RecoilAngle =  (2 * BulletMass) / WeaponMass * RECOIL_MULTIPLIER;
}

void URecoil_WeaponModule::CalculateKickbackStrength()
{
	KickbackStrength = (pow(BulletMass, 2) * pow(BulletVelocity, 2))/(2 * WeaponMass * ResistanceConstant);
}

void URecoil_WeaponModule::DoRecoilForCurrentShot(float DeltaTime)
{
	if (FMath::IsNearlyEqual(CurrentKickbackStrength, KickbackStrength, 0.01f))
	{
		KickbackEnded = true;
	}

	if (KickbackEnded)
	{
		CurrentKickbackStrength = FMath::Lerp(CurrentKickbackStrength, 0,
	DeltaTime/(FiringModule->GetDelayUntilNextRoundFired()/2));
	}
	else
	{
		CurrentKickbackStrength = FMath::Lerp(CurrentKickbackStrength, KickbackStrength,
	DeltaTime/(FiringModule->GetDelayUntilNextRoundFired()/2));
	}

	CurrentRecoilAngle = FMath::Lerp(CurrentRecoilAngle, RecoilAngle, DeltaTime);
	IRecoilable::Execute_DoRecoil(ParentActor, CurrentRecoilAngle, CurrentKickbackStrength * M_TO_CM);
}

inline void URecoil_WeaponModule::AfterRecoil()
{
	CanRecoil = false;
	KickbackEnded = false;
	CurrentKickbackStrength = 0.0f;
}

