#include "Tank.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"



ATank::ATank()
{ 	
	PrimaryActorTick.bCanEverTick = true;

	this->BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Box collider"));
	this->BoxCollider->SetupAttachment(RootComponent);
	this->SetRootComponent(BoxCollider);

	BoxCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	//BoxCollider->SetSimulatePhysics(true);
	
	this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	this->StaticMesh->SetupAttachment(RootComponent);
	
	this->CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	this->CameraBoom->TargetArmLength = 400.0f;
	this->CameraBoom->bUsePawnControlRotation = true;
	this->CameraBoom->SetupAttachment(RootComponent);
	
	this->MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	this->MainCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	this->MainCamera->bUsePawnControlRotation = false;

}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Forward", this, &ATank::MoveForward);
	PlayerInputComponent->BindAxis("Right", this, &ATank::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ATank::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &ATank::LookRight);
	

}

void ATank::MoveForward(float MoveRate) {
	if(Controller && MoveRate) {
		AddActorLocalOffset(FVector(MoveRate * MovementSpeed, 0, 0));
	}
}

void ATank::MoveRight(float MoveRate) {
	if(Controller && MoveRate)
	{
		AddActorLocalRotation(FRotator(0, MoveRate * RotationSpeed, 0));
	}
}

void ATank::LookUp(float Rate) {
	AddControllerPitchInput(GetWorld()->GetDeltaSeconds() * Rate * this->lookUpRate);
}

void ATank::LookRight(float Rate) {
	AddControllerYawInput(GetWorld()->GetDeltaSeconds() * Rate * this->lookRightRate);
}
