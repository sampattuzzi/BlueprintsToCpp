// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Grabber.h"
#include "FirstPersonCharacter.generated.h"

UCLASS() //Note Blueprintable is inherited
class BLUEPRINTSTOCPP_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFirstPersonCharacter();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:	
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure /*=>BlueprintCallable*/)
	UGrabber* GetGrabber() const;

private:
	void Forward(float AxisValue);
	void Grab();
	void Release();
};
