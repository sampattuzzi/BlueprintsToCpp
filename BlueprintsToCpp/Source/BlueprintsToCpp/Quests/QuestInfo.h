// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct BLUEPRINTSTOCPP_API FQuestInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest Info")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Info")
	FName QuestId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Info")
	int32 Progress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Info")
	int32 ProgressTotal;
};
