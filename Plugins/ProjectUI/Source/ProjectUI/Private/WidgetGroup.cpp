// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectUI.h"
#include "WidgetGroup.h"


UWidgetGroup::UWidgetGroup(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
	if (IntroWidget && InterActionWidget && NPCTextWidget && ItemWidget)
	{
		WIdgetGroup.Add(IntroWidget);
		WIdgetGroup.Add(InterActionWidget);
		WIdgetGroup.Add(NPCTextWidget);
		WIdgetGroup.Add(ItemWidget);
	}
}

void UWidgetGroup::NativeConstruct()
{
	Super::NativeConstruct();

	

}
