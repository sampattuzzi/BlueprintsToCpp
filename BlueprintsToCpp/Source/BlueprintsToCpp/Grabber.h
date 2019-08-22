// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class BLUEPRINTSTOCPP_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	UFUNCTION(BlueprintCallable)
	void Grab();
	
	UFUNCTION(BlueprintCallable)
	void Release();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool TraceForPhysicsBodies(class AActor*& HitActor, class UPrimitiveComponent*& HitComponent);

	UFUNCTION(BlueprintImplementableEvent)
	void NotifyQuestActor(class AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetMaxGrabLocation() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetHoldLocation() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UPhysicsHandleComponent* GetPhysicsComponent() const;

	UPROPERTY(EditAnywhere, BlueprintReadonly)
	float MaxGrabDistance = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HoldDistance = 100;
};
