// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetGroup.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTUI_API UWidgetGroup : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UWidgetGroup(const FObjectInitializer &ObjectInitializer);

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	UUserWidget* IntroWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	UUserWidget* InterActionWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	UUserWidget* NPCTextWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	UUserWidget* ItemWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TArray<UUserWidget*> WIdgetGroup;

};
