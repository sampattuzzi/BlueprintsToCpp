// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestInfo.h"
#include "QuestManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCompletedQuestSignature, int, QuestIndex);

UCLASS(Blueprintable)
class BLUEPRINTSTOCPP_API AQuestManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestManager();

	UFUNCTION(BlueprintCallable)
		void CompleteQuest(const FName& Name, bool CompleteWholeQuest);
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
		int32 GetQuestIndex(const FName& Name) const;
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
		FQuestInfo GetQuest(const FName& Name) const;
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
		bool IsActiveQuest(const FName& QuestId) const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FCompletedQuestSignature OnCompletedQuest;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestInfo> QuestList;

};
