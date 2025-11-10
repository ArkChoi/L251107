// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubSystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"

AMyPlayerController::AMyPlayerController()
{
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC_Asset(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/P_38Game/Input/IMC_P38.IMC_P38'"));
	if (IMC_Asset.Succeeded())
	{
		InputMapping = IMC_Asset.Object;
	}

}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//ULocalPlayer* LocalPlayer = GetLocalPlayer();
	//UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<> //뭐 이렇게도 가능하다.. 다 못쳤다만
	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			InputSystem->AddMappingContext(InputMapping, 0);

			//if (!InputMapping.IsNull())
			//{
			//	InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), 0); //동기화 로딩 함수라고 한다. 로딩중에는 어떤 동작도 안되는 것.
			//}
		}
	}
}
