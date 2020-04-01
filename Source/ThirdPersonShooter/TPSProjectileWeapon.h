// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TPSWeapon.h"
#include "TPSProjectileWeapon.generated.h"

/**
 * 
 */
class ATPSProjectile;

UCLASS()
class THIRDPERSONSHOOTER_API ATPSProjectileWeapon : public ATPSWeapon
{
	GENERATED_BODY()
	
public:
	void Fire() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	TSubclassOf<ATPSProjectile> ProjectileObject;

protected:
	void SpawnProjectile(FRotator EyeRot);
};
