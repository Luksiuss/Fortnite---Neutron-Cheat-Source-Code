#include "stdafx.h"

SETTINGS Settings = { 0 };

namespace SettingsHelper 
{
	VOID SaveConfig()
	{
		CHAR path[0xFF];
		GetTempPathA(sizeof(path) / sizeof(path[0]), path);
		strcat(path, xorstr("neutron.cfg"));

		auto file = fopen(path, xorstr("wb"));
		if (file) {
			fwrite(&Settings, sizeof(Settings), 1, file);
			fclose(file);
		}
	}
	VOID LoadDefaultConfig()
	{
		Settings.Aimbot = false;
		Settings.AutoAimbot = false;
		Settings.SilentAimbot = false;
		Settings.AimbotFOV = 1337.f;
		Settings.InstantReload = false;
		Settings.FOV = 80.f;
		Settings.AimbotSlow = 8.0f;
		Settings.WaterMark = false;
		Settings.CrosshairThickness = 2.0;
		Settings.CrosshairScale = 8.0;
		Settings.ESP.Containers = false;
		Settings.ESP.Weapons = false;
		Settings.ESP.AimbotFOV = false;
		Settings.ESP.PlayerNames = false;
		Settings.ESP.Vehicles = false;
		Settings.ESP.SupplyDrops = false;
		Settings.FPS = true;
		Settings.SpinSpeed = 11.25f;

		Settings.ESP.PlayerWeapons = false;
		Settings.ESP.Ammo = false;
		Settings.ESP.Skeletons = false;
		Settings.MemesTest = false;
		Settings.ESP.Memes = false;
		Settings.ColorAdjuster = false;
		Settings.CustomSpeedValue = 2;
		Settings.ESP.PlayerLines = false;
		Settings.ESP.Boxes = false;
		Settings.FovChanger = false;
		Settings.FovValue = 80;
		Settings.TargetLine = false;
		Settings.ESP.PlayerAmmo = false;
		Settings.ESP.LLamas = false;
		Settings.Crosshair = true;
		Settings.Test = false;
		Settings.HitBoxPos = 0;
		Settings.Rainbow = false;

		Settings.Spinbot = false;
		Settings.BigPlayers = false;

		Settings.SniperAimbotSlow = 30.f;
		Settings.ESP.PlayerNameColor[0] = 210;
		Settings.ESP.PlayerNameColor[1] = 210;
		Settings.ESP.PlayerNameColor[2] = 210;
		Settings.ESP.PlayerNameColor[3] = 255;

		Settings.ESP.FovColor[0] = 255;
		Settings.ESP.FovColor[1] = 255;
		Settings.ESP.FovColor[2] = 255;
		Settings.ESP.FovColor[3] = 255;

		Settings.ESP.PlayerNameVisibleColor[0] = 210;
		Settings.ESP.PlayerNameVisibleColor[1] = 210;
		Settings.ESP.PlayerNameVisibleColor[2] = 210;
		Settings.ESP.PlayerNameVisibleColor[3] = 255;

		Settings.ESP.PlayerNameNotVisibleColor[0] = 210;
		Settings.ESP.PlayerNameNotVisibleColor[1] = 0;
		Settings.ESP.PlayerNameNotVisibleColor[2] = 0;
		Settings.ESP.PlayerNameNotVisibleColor[3] = 255;

		Settings.ESP.BoxVisibleColor[0] = 210;
		Settings.ESP.BoxVisibleColor[1] = 210;
		Settings.ESP.BoxVisibleColor[2] = 210;
		Settings.ESP.BoxVisibleColor[3] = 255;

		Settings.ESP.BoxNotVisibleColor[0] = 210;
		Settings.ESP.BoxNotVisibleColor[1] = 0;
		Settings.ESP.BoxNotVisibleColor[2] = 0;
		Settings.ESP.BoxNotVisibleColor[3] = 255;

		Settings.ESP.SnaplineVisibleColor[0] = 210;
		Settings.ESP.SnaplineVisibleColor[1] = 210;
		Settings.ESP.SnaplineVisibleColor[2] = 210;
		Settings.ESP.SnaplineVisibleColor[3] = 255;


		Settings.ESP.SnaplineNotVisibleColor[0] = 210;
		Settings.ESP.SnaplineNotVisibleColor[1] = 0;
		Settings.ESP.SnaplineNotVisibleColor[2] = 0;
		Settings.ESP.SnaplineNotVisibleColor[3] = 255;

		Settings.ESP.SkeletonVisibleColor[0] = 210;
		Settings.ESP.SkeletonVisibleColor[1] = 210;
		Settings.ESP.SkeletonVisibleColor[2] = 210;
		Settings.ESP.SkeletonVisibleColor[3] = 255;

		Settings.ESP.SkeletonNotVisibleColor[0] = 210;
		Settings.ESP.SkeletonNotVisibleColor[1] = 0;
		Settings.ESP.SkeletonNotVisibleColor[2] = 0;
		Settings.ESP.SkeletonNotVisibleColor[3] = 255;

		Settings.ESP.TargetLineColor[0] = 255;
		Settings.ESP.TargetLineColor[1] = 0;
		Settings.ESP.TargetLineColor[2] = 0;
		Settings.ESP.TargetLineColor[3] = 255;

		SaveConfig();
	}
	VOID LoadSavedConfig()
	{
		CHAR path[0xFF] = { 0 };
		GetTempPathA(sizeof(path) / sizeof(path[0]), path);
		strcat(path, xorstr("neutron.cfg"));

		auto file = fopen(path, xorstr("rb"));
		if (file) {
			fseek(file, 0, SEEK_END);
			auto size = ftell(file);

			if (size == sizeof(Settings)) {
				fseek(file, 0, SEEK_SET);
				fread(&Settings, sizeof(Settings), 1, file);
				fclose(file);
			}
			else {
				fclose(file);
				LoadDefaultConfig();
			}
		}
		else {
			LoadDefaultConfig();
		}
	}
	VOID LoadTheme()
	{
		auto& style = ImGui::GetStyle();
		style.WindowPadding = { 10.f, 10.f };
		style.PopupRounding = 0.f;
		style.FramePadding = { 8.f, 4.f };
		style.ItemSpacing = { 10.f, 8.f };
		style.ItemInnerSpacing = { 6.f, 6.f };
		style.TouchExtraPadding = { 0.f, 0.f };
		style.IndentSpacing = 21.f;
		style.ScrollbarSize = 15.f;
		style.GrabMinSize = 8.f;
		style.WindowBorderSize = 1.5f;
		style.ChildBorderSize = 1.5f;
		style.PopupBorderSize = 1.5f;
		style.FrameBorderSize = 0.f;
		style.WindowRounding = 3.f;
		style.ChildRounding = 3.f;
		style.FrameRounding = 1.0f;
		style.ScrollbarRounding = 1.f;
		style.GrabRounding = 1.f;
		style.ButtonTextAlign = { 0.5f, 0.5f };
		style.DisplaySafeAreaPadding = { 3.f, 3.f };

		ImGuiIO& io = ImGui::GetIO(); (void)io;

		ImVec4* colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.f);
		colors[ImGuiCol_TextDisabled] = ImVec4(1.00f, 0.90f, 0.19f, 1.f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		colors[ImGuiCol_Border] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
		colors[ImGuiCol_BorderShadow] = ImVec4(1.f, 1.f, 1.f, 1.f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.21f, 0.21f, 0.21f, 0.78f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.28f, 0.27f, 0.27f, 1.f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.15f, 0.15f, 0.15f, 0.8f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.25f, 0.25f, 0.25f, 1.f);
		colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.30f, 0.30f, 0.30f, 1.f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.34f, 0.34f, 0.34f, 1.f);
		colors[ImGuiCol_Button] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.25f, 0.25f, 0.25f, 1.f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.30f, 0.30f, 0.30f, 1.f);
		colors[ImGuiCol_Header] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.19f, 0.19f, 0.19f, 1.f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.25f, 0.25f, 0.25f, 1.f);
		colors[ImGuiCol_Separator] = ImVec4(0.38f, 0.38f, 0.38f, 0.5f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.46f, 0.46f, 0.46f, 0.5f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.46f, 0.46f, 0.46f, 0.64f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.26f, 0.26f, 1.f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.31f, 0.31f, 0.31f, 1.f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.35f, 0.35f, 0.35f, 1.f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.9f);
	}
}