// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMarker.h"

// Sets default values
AQuestMarker::AQuestMarker()
{
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	SetRootComponent(ParticleSystem);
}

// Called when the game starts or when spawned
void AQuestMarker::BeginPlay()
{
	Super::BeginPlay();
	GetManager()->OnCompletedQuest.AddDynamic(this, &AQuestMarker::OnQuestCompleted);
	RefreshVisibility();
}

void AQuestMarker::OnQuestCompleted(int32 Index)
{
	RefreshVisibility();
}

void AQuestMarker::RefreshVisibility_Implementation()
{
	AQuestManager* Manager = GetManager();
	FQuestInfo Quest = Manager->GetQuest(QuestName);
	bool Visibility = Manager->IsActiveQuest(Quest.QuestId) && Quest.Progress == ShowAtProgress;
	ParticleSystem->SetVisibility(Visibility);
}

