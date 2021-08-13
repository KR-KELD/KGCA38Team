// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStaticLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"

bool UMyStaticLibrary::bShowInventory = false;

FString UMyStaticLibrary::GetNPC_Name(int32 index)
{
	FString Text = "";
	
	if (index == 0) Text = "Mike";
	if (index == 1) Text = "Jora";
	if (index == 2) Text = "Joy";
	if (index == 3) Text = "Master";
	if (index == 4) Text = "Colin";
	if (index == 5) Text = "Selly";
	if (index == 6) Text = "Mina";
	if (index == 7) Text = "Jack";
	if (index == 8) Text = "Lick";
	return Text;
}

FString UMyStaticLibrary::GetNPC_Text(int32 index)
{
	FString Text = "";

	if (index == 0) Text = "I'm sad..";
	if (index == 1) Text = "You came to rescue me?";
	if (index == 2) Text = "They say there's a hidden room in this maze";
	if (index == 3) Text = "Bring me canned food and I'll give you something important";
	if (index == 4) Text = "I was a Special Forces member before I came here.";
	if (index == 5) Text = "what's for lunch today?";
	if (index == 6) Text = "It'll be canned food again.";
	if (index == 7) Text = "Why are you looking at me?";
	if (index == 8) Text = "H..Help Me..";
	return Text;
}

void UMyStaticLibrary::ShowWidget(UUserWidget* widget)
{
	if (widget)
	{
		widget->SetVisibility(ESlateVisibility::Visible);
	}
}

void UMyStaticLibrary::HideWidget(UUserWidget* widget)
{
	if (widget)
	{
		widget->SetVisibility(ESlateVisibility::Hidden);
	}
}

float UMyStaticLibrary::CallCharacterCurrentHealth(float curHealth)
{
	return curHealth;
}

float UMyStaticLibrary::CallCharacterMaxHealth(float maxHealth)
{
	return maxHealth;
}

void UMyStaticLibrary::SetShowInventory(bool bInventory)
{
	bShowInventory = bInventory;
}

bool UMyStaticLibrary::GetShowInventory()
{
	return bShowInventory;
}