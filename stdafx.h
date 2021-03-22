#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <psapi.h>
#include <intrin.h>

#include <string>
#include <vector>

#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_internal.h>

#include <MinHook.h>
#pragma comment(lib, "minhook.lib")

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

#include "xorstr.h"

#include "structs.h"
#include "offsets.h"
#include "util.h"
#include "settings.h"
#include "hooks.h"
#include "renderer.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <map>