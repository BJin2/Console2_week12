// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyData.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ALobbyData::ALobbyData()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void ALobbyData::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALobbyData::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyData, teamANames);
	DOREPLIFETIME(ALobbyData, teamBNames);
}

// Called every frame
void ALobbyData::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

