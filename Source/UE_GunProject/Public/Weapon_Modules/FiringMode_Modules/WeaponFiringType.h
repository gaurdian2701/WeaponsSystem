#pragma once

#include "CoreMinimal.h"
#include "WeaponFiringType.generated.h"

UENUM()
enum class EWeaponFiringType : uint8
{
	CONTINUOUS,
	BURST
};

