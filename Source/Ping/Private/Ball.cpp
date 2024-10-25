// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

ABall::ABall()
{
    PrimaryActorTick.bCanEverTick = true;
    bReplicates = true; 
    SetReplicateMovement(true); 

    BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
    RootComponent = BallMesh;

    BallMesh->SetSimulatePhysics(true);
    BallMesh->SetNotifyRigidBodyCollision(true);
    BallMesh->BodyInstance.SetCollisionProfileName("PhysicsActor");

    BallMesh->OnComponentHit.AddDynamic(this, &ABall::OnHit);

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->SetUpdatedComponent(BallMesh);
    ProjectileMovement->InitialSpeed = 500.f;
    ProjectileMovement->MaxSpeed = 1000.f;
    ProjectileMovement->bShouldBounce = true;
    ProjectileMovement->Bounciness = 0.6f;
    ProjectileMovement->ProjectileGravityScale = 0.f;
}

void ABall::BeginPlay()
{
    Super::BeginPlay();
}

void ABall::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABall::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // ѕри столкновении измен€ем направление движени€
    FVector ReflectedVelocity = FMath::GetReflectionVector(ProjectileMovement->Velocity, Hit.Normal);
    ProjectileMovement->Velocity = ReflectedVelocity;
}