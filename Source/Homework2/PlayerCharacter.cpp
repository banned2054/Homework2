// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    //ʵ������������

    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));

    //���ý�ɫ������任��λ�ú���ת
    GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -90.0f), FQuat(FRotator(0.0f, -90.0f, 0.0f)));

    //�������������ӵ�Ĭ�Ͻ�ɫ�Ĺ��������������
    SpringArmComp->SetupAttachment(GetMesh());
    CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);

    //���õ��ɱ۵������
    SpringArmComp->bUsePawnControlRotation = true;

    //���ý�ɫ��������������
    GetCharacterMovement()->bOrientRotationToMovement = true;

    move_forward_value = 0.0f;
    move_right_value = 0.0f;
    look_value = 0.0f;
    turn_value = 0.0f;
    is_jump = false;
    is_fire = false;
    is_stay = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();

}


// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::Look_up);

    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Start_jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::Stop_jump);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::Start_fire);
    PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerCharacter::Stop_fire);
    PlayerInputComponent->BindAction("Grenade", IE_Pressed, this, &APlayerCharacter::Start_grenade);
    PlayerInputComponent->BindAction("Stay", IE_Pressed, this, &APlayerCharacter::Change_stay);
    PlayerInputComponent->BindAction("Spot", IE_Pressed, this, &APlayerCharacter::Change_spot);
}

void APlayerCharacter::MoveForward(float AxisValue)
{
    if (Controller != nullptr)
    {
        move_forward_value = AxisValue;
        if (AxisValue != 0.0f)
        {
            // �ҳ���ǰ����
            const FRotator Rotation = Controller->GetControlRotation();
            const FRotator YawRotation(0, Rotation.Yaw, 0);

            // ��ȡ��ǰʸ��
            const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
            AddMovementInput(Direction, AxisValue);
        }
    }

}

void APlayerCharacter::MoveRight(float AxisValue)
{
    if (Controller != nullptr)
    {
        move_right_value = AxisValue;
        if (AxisValue != 0.0f)
        {
            // �ҳ����ҷ���
            const FRotator Rotation = Controller->GetControlRotation();
            const FRotator YawRotation(0, Rotation.Yaw, 0);

            // ��ȡ����ʸ�� 
            const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

            // ��Ӹ÷�����
            AddMovementInput(Direction, AxisValue);
        }
    }
}
void APlayerCharacter::Turn(float InputAxis)
{
    if (Controller != nullptr)
    {
        turn_value = InputAxis;
        AddControllerYawInput(InputAxis);
    }
}

void APlayerCharacter::Look_up(float InputAxis)
{
    if (Controller != nullptr)
    {
        look_value = InputAxis;
        APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0);
        FRotator cam_dir = CameraManager->GetCameraRotation();
    	AddControllerPitchInput(InputAxis);
        if (cam_dir.Pitch < -53) cam_dir.Pitch = -52;
    }
}

void APlayerCharacter::Start_jump()
{
    bPressedJump = true;
    is_jump = true;
}

void APlayerCharacter::Stop_jump()
{
    bPressedJump = false;
    is_jump = false;
}

void APlayerCharacter::Change_stay()
{
    is_stay = !is_stay;
}
