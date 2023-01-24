// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Garde.generated.h"

UCLASS()
class CASTELCOLLECT_API AGarde : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGarde();
	bool bCanSeePlayer;
	bool bPreviousCanSeePlayer;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = LookAt, meta = (AllowPrivateAccess = "true"));
	class ULookAtActorComponent* LookAtActorComponent;

	FTimerHandle ThrowTimerHandle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool CanSee(const AActor* Target);

	bool LookAtActor(AActor* Target);

	void FollowPlayer(AActor* Target);

	void Patrol();



};

/*
UCLASS()
class MYPROJECT_API AEnemy : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AEnemy();
	bool bCanSeePlayer;
	bool bPreviousCanSeePlayer;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = LookAt, meta = (AllowPrivateAccess = "true"));
	class UMockAtActorComponent* MockAtActorComponent;

	FTimerHandle ThrowTimerHandle;

	float ThrowingInterval = 2.f;
	float ThrowingDelay = 1.f;

	void ThrowPatate();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Patate)
		TSubclassOf<class APatate> PatateClass;


	//bool CanSee(const AActor* Target);

	//bool LookAtActor(AActor* Target);
};*/
