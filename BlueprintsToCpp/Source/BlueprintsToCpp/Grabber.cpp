// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // Can only unset if blueprint isn't ticking.
}

void UGrabber::Grab2()
{
	
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UGrabber::TraceForPhysicsBodies2_Implementation(AActor*& HitActor, UPrimitiveComponent*& HitComponent)
{
	return false;	
}

FVector UGrabber::GetMaxGrabLocation() const
{
	const FVector Forward = UKismetMathLibrary::GetForwardVector(GetComponentRotation());
	return GetComponentLocation() + Forward * MaxGrabDistance;
}

FVector UGrabber::GetHoldLocation() const
{
	const FVector Forward = UKismetMathLibrary::GetForwardVector(GetComponentRotation());
	return GetComponentLocation() + Forward * HoldDistance;
}

UPhysicsHandleComponent* UGrabber::GetPhysicsComponent() const
{
	return GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
}


