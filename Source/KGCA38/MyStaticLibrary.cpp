// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStaticLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"

FString UMyStaticLibrary::GetNPC_Name(int32 index)
{
	FString Text = "";
	
	if (index == 0) return Text = "Sara";
	if (index == 1) return Text = "Jain";
	if (index == 2) return Text = "Joy";
	if (index == 3) return Text = "Cindy";
	if (index == 4) return Text = "Colin";
	if (index == 5) return Text = "Mark";
	if (index == 6) return Text = "James";

	return Text;
}

FString UMyStaticLibrary::GetNPC_Text(int32 index)
{
	FString Text = "";

	if (index == 0) return Text = "Hi";
	if (index == 1) return Text = "Hi. Guy!";
	if (index == 2) return Text = "Hello";
	if (index == 3) return Text = "Hi There";
	if (index == 4) return Text = "What up?";
	if (index == 5) return Text = "Good Day";
	if (index == 6) return Text = "How r u";

	return Text;
}

void UMyStaticLibrary::ShowWidget(UUserWidget* widget)
{
	widget->SetVisibility(ESlateVisibility::Visible);
}

void UMyStaticLibrary::HideWidget(UUserWidget* widget)
{
	widget->SetVisibility(ESlateVisibility::Hidden);
}

float UMyStaticLibrary::CallCharacterCurrentHealth(float curHealth)
{
	return curHealth;
}

float UMyStaticLibrary::CallCharacterMaxHealth(float maxHealth)
{
	return maxHealth;
}