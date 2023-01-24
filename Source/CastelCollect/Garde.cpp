// Fill out your copyright notice in the Description page of Project Settings.


#include "Garde.h"
//#include "EscapeFunctionLibrary.h"
#include "LookAtActorComponent.h"

#include "TimerManager.h"
#include <DrawDebugHelpers.h>
#include <Kismet/KismetMathLibrary.h> 
#include <Kismet/Gameplaystatics.h> 
#include "Engine/World.h"
#include <GameFramework/ProjectileMovementComponent.h>

// Sets default values
AGarde::AGarde()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LookAtActorComponent = CreateAbstractDefaultSubobject<ULookAtActorComponent>(TEXT("Sight Source"));
	LookAtActorComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AGarde::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGarde::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bCanSeePlayer = LookAtActorComponent->GetCanSeeActor();
	//LookAtActor();

	if (bCanSeePlayer != bPreviousCanSeePlayer) {

		if (bCanSeePlayer) {
			//start timer
			//GetWorldTimerManager().SetTimer(ThrowTimerHandle, this, &AEnemy::ThrowPatate, ThrowingInterval, true, ThrowingDelay);
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::White, TEXT("bite"));

		}
		else {
			//stop timer		
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::White, TEXT("Patate"));
			GetWorldTimerManager().ClearTimer(ThrowTimerHandle);
		}
	}
	bPreviousCanSeePlayer = bCanSeePlayer;

}

// Called to bind functionality to input
void AGarde::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AGarde::LookAtActor(AActor* Target) {
	const TArray<const AActor*> IgnoreActors = { this, Target };
	//if (UEscapeFunctionLibrary::CanSeeActor(GetWorld(), SightSource->GetComponentLocation(), Target, IgnoreActors)) {
		FVector Start = GetActorLocation();
		FVector End = Target->GetActorLocation();
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);
		LookAtRotation.Pitch = 0;
		LookAtRotation.Roll = 0;
		SetActorRotation(LookAtRotation);
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::White, TEXT("Patate"));
		return true;
	//}
	return false;
}

bool AGarde::CanSee(const AActor* Target)
{
	if (Target == nullptr) return false;
	FHitResult Hit;

	FVector Start = GetActorLocation()//SightSource->GetComponentLocation();
	FVector End = Target->GetActorLocation();

	FCollisionQueryParams QueryParam;
	QueryParam.AddIgnoredActor(this);
	QueryParam.AddIgnoredActor(Target);

	ECollisionChannel Channel = ECollisionChannel::ECC_Visibility;
	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel);

	if (!Hit.bBlockingHit) DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}

/*
// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bCanSeePlayer = MockAtActorComponent->CanSeeActor();

	if (bCanSeePlayer != bPreviousCanSeePlayer) {

		if (bCanSeePlayer) {
			//start timer
			GetWorldTimerManager().SetTimer(ThrowTimerHandle, this, &AEnemy::ThrowPatate, ThrowingInterval, true, ThrowingDelay);

		}
		else {
			//stop timer		
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::White, TEXT("Patate"));
			GetWorldTimerManager().ClearTimer(ThrowTimerHandle);
		}
	}
	bPreviousCanSeePlayer = bCanSeePlayer;


}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


bool AEnemy::LookAtActor(AActor* Target) {
	const TArray<const AActor*> IgnoreActors = { this, Target };
	if (UEscapeFunctionLibrary::CanSeeActor(GetWorld(), SightSource->GetComponentLocation(), Target, IgnoreActors)) {
		FVector Start = GetActorLocation();
		FVector End = Target->GetActorLocation();
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);
		LookAtRotation.Pitch = 0;
		LookAtRotation.Roll = 0;
		SetActorRotation(LookAtRotation);
		return true;
	}
	return false;
}

bool AEnemy::CanSee(const AActor* Target)
{
	if (Target == nullptr) return false;
	FHitResult Hit;

	FVector Start = SightSource->GetComponentLocation();
	FVector End = Target->GetActorLocation();

	FCollisionQueryParams QueryParam;
	QueryParam.AddIgnoredActor(this);
	QueryParam.AddIgnoredActor(Target);

	ECollisionChannel Channel = ECollisionChannel::ECC_Visibility;
	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel);

	if (!Hit.bBlockingHit) DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}

*/