// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class HOMEWORK2_API AWeapon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* Mesh;
	UPROPERTY(EditAnywhere)
		FName Muzzle_Socket;

	UFUNCTION(BlueprintCallable)
		void Start_fire();
	UFUNCTION(BlueprintCallable)
		void Stop_fire();
	UFUNCTION(BlueprintCallable)
		void Start_grenade();
	UFUNCTION(BlueprintImplementableEvent)
		void Spawn_grenade();
	UFUNCTION(BlueprintImplementableEvent)
		void Spawn_Projectile();
	UFUNCTION(BlueprintCallable)
		bool Calc_Fire_Info(FVector& location, FVector& Dir);
	UFUNCTION(BlueprintCallable)
		void Change_spot();
	UFUNCTION(BlueprintImplementableEvent)
		void change_spots();
};
