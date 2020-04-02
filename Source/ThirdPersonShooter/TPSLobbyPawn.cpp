// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSLobbyPawn.h"

// Sets default values
ATPSLobbyPawn::ATPSLobbyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ATPSLobbyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATPSLobbyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATPSLobbyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

