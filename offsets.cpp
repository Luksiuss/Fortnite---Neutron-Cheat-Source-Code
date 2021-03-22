#include "stdafx.h"

/*
UWorld: 0x80A70A8
LineOfSight: 0x1E07D70
Free: 0x2AE0550
GetObjName: 0x4196C20
GObjects: 0x7FB6780
GetObjNameIndex: 0x2BE2B50

OwningGameInstance -> 0x188;
Levels -> 0x148;
LocalPlayers -> 0x38;
ControlRotation -> 0x280;
AcknowledgedPawn -> 0x298;
PlayerState -> 0x238;
RootComponent -> 0x130;
CustomTimeDilation -> 0x98;
Mesh -> 0x278;
RelativeLocation -> 0x11c;
ComponentVelocity -> 0x140;
ComponentToWorld -> 0x0;
StaticMesh -> 0x420;
CachedWorldSpaceBounds -> 0x5a0;
bIsDBNO -> 0x53a;
bIsDying -> 0x520;
CurrentWeapon -> 0x588;
PrimaryPickupItemEntry -> 0x280;
ItemDefinition -> 0x18;
DisplayName -> 0x70;
Tier -> 0x54;
TeamIndex -> 0xe60;
WeaponData -> 0x358;
AmmoCount -> 0x8dc;
WeaponStatHandle -> 0x7b8;
FireStartLoc -> 0x850;
ReloadTime -> 0xfc;
bAlreadySearched -> 0xc59;

*/

namespace addresses
{
	PVOID GetPlayerName = 0;
	PVOID SetPawnVisibility = 0;
	PVOID ClientSetRotation = 0;
	PVOID K2_TeleportTo = 0;
	PVOID ClientSetLocation = 0;
	PVOID IsInVehicle = 0;
	PVOID SetActorRelativeScale3D = 0;
	PVOID SetMouseLocation = 0;
	PVOID AddYawInput = 0;
	PVOID AddPitchInput = 0;
	PVOID GetVehicleActor = 0;
	PVOID GetVehicle = 0;
	PVOID K2_AttachToActor = 0;
	PVOID SetForcedLodModel = 0;
}

namespace offsets
{
	BOOLEAN Initialize()
	{
		uint64_t BaseAddress = (uint64_t)GetModuleHandleA(NULL);

		addresses::GetPlayerName = Util::FindObject(xorstr(L"/Script/Engine.PlayerState.GetPlayerName"));
		addresses::SetPawnVisibility = Util::FindObject(xorstr(L"/Script/FortniteGame.FortPawn.SetPawnVisibility"));
		addresses::ClientSetRotation = Util::FindObject(xorstr(L"/Script/Engine.Controller.ClientSetRotation"));
		addresses::K2_TeleportTo = Util::FindObject(xorstr(L"/Script/Engine.Actor.K2_TeleportTo"));
		addresses::ClientSetLocation = Util::FindObject(xorstr(L"/Script/Engine.Controller.ClientSetLocation"));
		addresses::SetActorRelativeScale3D = Util::FindObject(xorstr(L"/Script/Engine.Actor.SetActorRelativeScale3D"));
		addresses::IsInVehicle = Util::FindObject(xorstr(L"/Script/FortniteGame.FortPlayerPawn.IsInVehicle"));
		addresses::AddYawInput = Util::FindObject(xorstr(L"/Script/Engine.PlayerController.AddYawInput"));
		addresses::AddPitchInput = Util::FindObject(xorstr(L"/Script/Engine.PlayerController.AddPitchInput"));
		addresses::GetVehicleActor = Util::FindObject(xorstr(L"/Script/FortniteGame.FortPlayerPawn.GetVehicleActor"));
		addresses::GetVehicle = Util::FindObject(xorstr(L"/Script/FortniteGame.FortPlayerPawn.GetVehicle"));
		addresses::K2_AttachToActor = Util::FindObject(xorstr(L"/Script/Engine.Actor.K2_AttachToActor"));

		addresses::SetForcedLodModel = Util::FindObject(xorstr(L"/Script/Engine.StaticMeshComponent.SetForcedLodModel"));

		return TRUE;
	}
}