// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


//forward declaration
class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;
UCLASS()
class BOWLINGTANK_API ATank : public APawn
{
	GENERATED_BODY()
	
	void MoveForward(float MoveRate);
	void MoveRight(float MoveRate);
	void LookUp(float Rate);
	void LookRight(float Rate);

public:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditAnywhere)
	float MovementSpeed = 5.0f;
	UPROPERTY(EditAnywhere)
	float RotationSpeed = 1.0f;
	UPROPERTY(EditAnywhere)
	float lookUpRate = 45.0f;
	UPROPERTY(EditAnywhere)
	float lookRightRate = 45.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UBoxComponent* BoxCollider;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USpringArmComponent* CameraBoom;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UCameraComponent* MainCamera;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
