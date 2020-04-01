// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSProjectileWeapon.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "TPSProjectile.h"
#include "TPSCharacter.h"

void ATPSProjectileWeapon::Fire()
{
	ATPSCharacter* MyOwner = Cast<ATPSCharacter>(GetOwner());

	if (MyOwner)
	{
		FVector EyeLoc;
		FRotator EyeRot;
		MyOwner->GetActorEyesViewPoint(EyeLoc, EyeRot);

		FVector traceEnd = EyeLoc + 10000 * EyeRot.Vector();
		FHitResult HitResult;
		if (GetWorld()->LineTraceSingleByChannel(HitResult, EyeLoc, traceEnd, ECC_Visibility))
		{
			//DO damage stuff
			AActor* HitActor = HitResult.GetActor();
			//UGameplayStatics::ApplyPointDamage(HitActor, 20.0f, EyeRot.Vector(), HitResult, MyOwner->GetInstigatorController(), this, damageType);
		}

		PlayMuzzleEffect();
		SpawnProjectile(EyeRot);
		
		//DrawDebugLine(GetWorld(), EyeLoc, traceEnd, FColor::Red, false, 1.0f, 0, 1.0f);

		// Camera shake
		APlayerController* PlayerController = Cast<APlayerController>(MyOwner->GetController());
		if (PlayerController)
		{
			PlayerController->ClientPlayCameraShake(FireCameraShake);
		}

		ammoCount--;
		MyOwner->TriggerOnWeaponAmmoChange(weaponIcon, ammoCount, magazineSize);
		if (ammoCount == 0 && totalNumberOfBullets > 0)
		{
			MyOwner->PlayReloadAnim();
		}
	}
}

void ATPSProjectileWeapon::SpawnProjectile(FRotator EyeRot)
{
	if (ProjectileObject)
	{
		FVector socketLoc;
		FRotator socketRot;
		MeshComp->GetSocketWorldLocationAndRotation(MuzzleSocketName, socketLoc, socketRot);
		GetWorld()->SpawnActor<ATPSProjectile>(ProjectileObject, socketLoc, EyeRot);
	}
}
