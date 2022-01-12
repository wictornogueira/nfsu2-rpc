#pragma once

#include <fstream>
#include <locale>
#include <string>
#include <Windows.h>

#include "json.hpp"

#include "config.h"
#include "gamestuff.h"

using namespace std;
using json = nlohmann::json;

enum class GameState {
  Loading,
  InMenu,
  Racing,
  Tuning,
  Exploring
};

enum class GameMode {
  URL,
  Drag,
  Drift,
  Sprint,
  Circuit,
  Unknown,
  StreetX,
  Explorer
};

struct CarInfo {
  const char* name;
  const char* brand;
};

void initConsole();
void makeCall(int at, void* to);
wstring getModulePath(HMODULE hModule);
json buildLangJsonObj(HMODULE hModule, LPWSTR lpName);
string replaceAll(const string& str, const string& searchValue, const string& newValue);
string capitalizeString(const string& str);
string getGameString(const string& str);
GameState getGameState();
GameMode guessGameMode(int trackId = (*C_TRACK_PTR));
CarInfo getCarInfo(int carId = (*C_CAR_PTR));
string getTrack();
string getProfileName();
string getLobbyName();
string getBalance();
