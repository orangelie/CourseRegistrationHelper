#pragma once

#if defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

#define Clicked(key) (GetAsyncKeyState(key) & 0x8000)

constexpr static const int gMaxKeyInput = 9;
constexpr static const int gMaxClassInput = 6;
constexpr static const char gSpaceZero[] = "                                                                                       ";