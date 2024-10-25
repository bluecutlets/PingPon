// Fill out your copyright notice in the Description page of Project Settings.


#include "PingPongPaddle.h"

// Sets default values
APingPongPaddle::APingPongPaddle()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APingPongPaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APingPongPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APingPongPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

