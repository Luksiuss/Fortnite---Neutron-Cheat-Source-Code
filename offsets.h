#pragma once

namespace addresses
{
	extern PVOID GetPlayerName;
	extern PVOID SetPawnVisibility;
	extern PVOID ClientSetRotation;
	extern PVOID ClientSetLocation;
	extern PVOID IsInVehicle;
	extern PVOID SetActorRelativeScale3D;
	extern PVOID AddYawInput;
	extern PVOID AddPitchInput;
	extern PVOID GetVehicleActor;
	extern PVOID GetVehicle;
	extern PVOID SetForcedLodModel;
}



namespace offsets
{
	enum Main : uint64_t
	{
		UWorld = 0x82af928,
	};

	enum World : uint64_t
	{
		OwningGameInstance = 0x188,
		Levels = 0x148,
	};

	enum Level : uint64_t
	{
		AActors = 0x98,
	};

	enum GameInstance : uint64_t
	{
		LocalPlayers = 0x38,
	};

	enum Player : uint64_t
	{
		PlayerController = 0x30,
	};

	enum Controller : uint64_t
	{
		ControlRotation = 0x280,
	};

	enum PlayerController : uint64_t
	{
		AcknowledgedPawn = 0x298,
	};

	enum Pawn : uint64_t
	{
		PlayerState = 0x238,
	};

	enum Actor : uint64_t
	{
		RootComponent = 0x130,
		CustomTimeDilation = 0x98,
	};

	enum Character : uint64_t
	{
		Mesh = 0x278,
	};

	enum SceneComponent : uint64_t
	{
		RelativeLocation = 0x11C,
		ComponentVelocity = 0x140,
	};

	enum StaticMeshComponent : uint64_t
	{
		ComponentToWorld = 0x1C0,
		StaticMesh = 0x420,
	};

	enum SkinnedMeshComponent : uint64_t
	{
		CachedWorldSpaceBounds = 0x5a0,
	};

	enum FortPawn : uint64_t
	{
		bIsDBNO = 0x53a,
		bIsDying = 0x520,
		CurrentWeapon = 0x588,
	};

	enum FortPickup : uint64_t
	{
		PrimaryPickupItemEntry = 0x290,
	};

	enum FortItemEntry : uint64_t
	{
		ItemDefinition = 0x18,
	};

	enum FortItemDefinition : uint64_t
	{
		DisplayName = 0x70,
		Tier = 0x54,
	};

	enum FortPlayerStateAthena : uint64_t
	{
		TeamIndex = 0xE68,
	};

	enum FortWeapon : uint64_t
	{
		WeaponData = 0x358,
		AmmoCount = 0x8DC,
	};

	enum FortWeaponItemDefinition : uint64_t
	{
		WeaponStatHandle = 0x7B8,
	};

	enum FortProjectileAthena : uint64_t
	{
		FireStartLoc = 0x868,
	};

	enum FortBaseWeaponStats : uint64_t
	{
		ReloadTime = 0xFC,
	};
	enum BuildingContainer : uint64_t
	{
		bAlreadySearched = 0xc59,
	};

	BOOLEAN Initialize();
}