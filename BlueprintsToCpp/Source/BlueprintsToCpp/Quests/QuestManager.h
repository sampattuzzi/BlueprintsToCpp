// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCompletedQuestSignature, int, QuestIndex);

UCLASS(Blueprintable)
class BLUEPRINTSTOCPP_API AQuestManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FCompletedQuestSignature OnCompletedQuest;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
