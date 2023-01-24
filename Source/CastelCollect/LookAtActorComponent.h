// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "LookAtActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CASTELCOLLECT_API ULookAtActorComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULookAtActorComponent();

private:
	bool bCanSeeActor = false;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	AActor* TargetActor;
	//bool bCanSeeActor = false;
	bool LookAtActor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FORCEINLINE void SetTarget(AActor* NewTarget) { TargetActor = NewTarget; }
	FORCEINLINE void SetCanSeeActor(bool v) { bCanSeeActor = v; }
	FORCEINLINE bool GetCanSeeActor() { return bCanSeeActor; }
};
