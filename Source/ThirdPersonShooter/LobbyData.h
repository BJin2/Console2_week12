// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LobbyData.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API ALobbyData : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALobbyData();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "Lobby")
		TArray<FName> teamANames;
	UPROPERTY(BlueprintReadOnly, Replicated, Category = "Lobby")
		TArray<FName> teamBNames;
};
