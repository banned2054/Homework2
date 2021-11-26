// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class HOMEWORK2_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	UPROPERTY(BlueprintReadWrite)
		float move_forward_value;
	UPROPERTY(BlueprintReadWrite)
		float move_right_value;
	UPROPERTY(BlueprintReadWrite)
		float turn_value;
	UPROPERTY(BlueprintReadWrite)
		float look_value;
	UPROPERTY(BlueprintReadWrite)
		bool is_fire;
	UPROPERTY(BlueprintReadWrite)
		bool is_stay;
	UPROPERTY(BlueprintReadWrite)
		bool is_jump;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//������ұ���������ĵ��ɱ����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmComp;

	//��Ҹ��������
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UCameraComponent* CameraComp;

	//Ϊ��ǰ/������������
	void MoveForward(float InputAxis);

	//Ϊ��/�Ҳ����������
	void MoveRight(float InputAxis);

	void Turn(float InputAxis);

	void Look_up(float InputAxis);

	void Start_jump();

	void Stop_jump();

	void Change_stay();

	UFUNCTION(BlueprintImplementableEvent)
		void Start_fire();

	UFUNCTION(BlueprintImplementableEvent)
		void Stop_fire();

	UFUNCTION(BlueprintImplementableEvent)
		void Change_spot();
	UFUNCTION(BlueprintImplementableEvent)
		void Start_grenade();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
