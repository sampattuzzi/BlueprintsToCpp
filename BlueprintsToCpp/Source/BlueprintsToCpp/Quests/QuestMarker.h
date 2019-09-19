// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestManager.h"
#include "Particles/ParticleSystemComponent.h"
#include "QuestMarker.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AQuestMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestMarker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	AQuestManager* GetManager() const;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	/*bool to make function*/void RefreshVisibility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName QuestName;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ShowAtProgress;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* ParticleSystem;

private:
	UFUNCTION()
	void OnQuestCompleted(int32 Index);
	
};
