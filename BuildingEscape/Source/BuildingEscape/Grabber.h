// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"
#include "Grabber.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	

private:

	//How far ahead the player can reach in cm
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	//Ray-cast and grab what's in reach
	void Grab();

	//Called when grab is released
	void Release();

	//Find attached Physics
	void FindPhysicsHandleComponent();

	//Set-up attached input component
	void SetupInputComponent();

	//Returns hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	//Returns the start of the reach line
	const FVector GetReachLineStart();

	//Returns the end of the reach line
	const FVector GetReachLineEnd();
};
