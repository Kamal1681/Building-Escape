// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "Grabber.h"

#define OUT


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
		
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get player viewpoint this tick

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);


	//log out to test

	//UE_LOG(LogTemp, Log, TEXT("Location: %s, Rotation: %s"), 
		//*PlayerViewPointLocation.ToString(), *PlayerViewPointRotation.ToString());

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	DrawDebugLine(
		GetWorld(), PlayerViewPointLocation, LineTraceEnd, FColor(255, 0, 0), false, 0.f, 0.f, 5.f
	);


	//Line trace (Ray cast) out to reach distance

	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit, PlayerViewPointLocation, LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	//see what we hit

	AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line Trace Hit: %s"), *(ActorHit->GetName()));
	}
	

}

