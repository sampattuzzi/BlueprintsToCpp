// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestMarker.h"

// Sets default values
AQuestMarker::AQuestMarker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	SetRootComponent(ParticleSystem);
}

// Called when the game starts or when spawned
void AQuestMarker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuestMarker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuestMarker::RefreshVisibility_Implementation()
{
	AQuestManager* Manager = GetManager();
	//FQuestInfo Quest = Manager->GetQuest(QuestName)
	//bool Visibility =
}

