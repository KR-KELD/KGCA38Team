#pragma once

// 아이템 타입
UENUM(BlueprintType)
enum class EItemType : uint8
{
	EIT_Weapon UMETA(DisplayName = "Weapon"),
	EIT_Food UMETA(DisplayName = "Food"),
	EIT_Object UMETA(DisplayName = "Object"),
	EIT_Medical UMETA(DisplayName = "Medical"),

	EIT_MAX UMETA(DisplayName = "DefaultMAX")
};