// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "QuestInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct BLUEPRINTSTOCPP_API FQuestInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName QuestId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Progress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ProgressTotal;
};
