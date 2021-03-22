#pragma once

#define BONE_HEAD_ID (66)

namespace hooks {
	extern bool NoSpread;
	extern bool IsLocalPlayerInVehicle;
	extern PVOID LocalPlayerPawn;
	extern PVOID LocalPlayerCurrentWeapon;
	extern PVOID LocalPlayerController;
	extern PVOID LocalRootComp;
	extern PVOID PlayerCameraManager;
	extern FVector LocalplayerPosition;
	extern FVector ClosestTargetCoord;
	extern float Distance;
	extern bool IsSniper;
	extern PVOID TargetPawn;
	extern PVOID VehicleTargetPawn;
	extern PVOID ClosestVehicle;

	extern PVOID(*ProcessEvent)(PVOID, PVOID, PVOID, PVOID);
	BOOLEAN Initialize();
	void SetPlayerVisibility(int VisibilityValue);
	void WriteAngles(float TargetX, float TargetY);
	void Teleport(PVOID Pawn, FVector Coords);
	void Teleport2(FVector Coords);
}