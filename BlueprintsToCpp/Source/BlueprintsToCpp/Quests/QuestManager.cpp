// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"

// Sets default values
AQuestManager::AQuestManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AQuestManager::CompleteQuest(const FName& Name, bool CompleteWholeQuest)
{
	int32 QuestIndex = GetQuestIndex(Name);
	FQuestInfo Quest = QuestList[QuestIndex];
	if (CompleteWholeQuest)
	{
		Quest.Progress = Quest.ProgressTotal;
	}
	else
	{
		Quest.Progress = FMath::Min(Quest.Progress + 1, Quest.ProgressTotal);
	}
	QuestList[QuestIndex] = Quest;
}

// Called when the game starts or when spawned
void AQuestManager::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AQuestManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

