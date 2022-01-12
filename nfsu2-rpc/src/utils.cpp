#include "utils.h"

// Misc

void initConsole() {
  AllocConsole();

  FILE* fDummy;
  freopen_s(&fDummy, "CONIN$", "r", stdin);
  freopen_s(&fDummy, "CONOUT$", "w", stderr);
  freopen_s(&fDummy, "CONOUT$", "w", stdout);
}

void makeCall(int at, void* to) {
  DWORD oldvp;
  VirtualProtect((LPVOID)at, 5, PAGE_EXECUTE_READWRITE, &oldvp);

  *((unsigned char*)at) = 0xE8;
  *((int*)++at) = (int)to - (at + 4);

  VirtualProtect((LPVOID)at, 5, oldvp, &oldvp);
}

wstring getModulePath(HMODULE hModule) {
  WCHAR path[MAX_PATH] = {0};
  GetModuleFileName(hModule, path, MAX_PATH);
  wstring pathString = wstring(path);
  return pathString.substr(0, pathString.find_last_of(L"\\/"));
}

json buildLangJsonObj(HMODULE hModule, LPWSTR lpName) {
  json langJson;

  HRSRC hResInfo;
  HGLOBAL hRes;
  LPVOID memRes;

  if (
    (hResInfo = FindResource(hModule, lpName, L"Text")) == 0 ||
    (hRes = LoadResource(hModule, hResInfo)) == 0 ||
    (memRes = LockResource(hRes)) == 0
    ) {
    throw runtime_error("Could not load internal lang file\n");
  }

  langJson = json::parse((char*)memRes);

  wstring langPackPath = getModulePath(hModule) + LANG_PACK_FILENAME;
  ifstream langPackFile(langPackPath);

  if (langPackFile) {
    json langPackJson;
    langPackFile >> langPackJson;
    langJson.merge_patch(langPackJson);
  }

  return langJson;
}

// String utils

string replaceAll(const string& str, const string& searchValue, const string& newValue) {
  if (searchValue.compare(newValue)) {
    string copy = str;
    size_t cPos = 0;

    while ((cPos = copy.find(searchValue, cPos)) != string::npos) {
      copy.replace(cPos, searchValue.length(), newValue);
    }

    return copy;
  }

  return str;
}

string capitalizeString(const string& str) {
  string copy = str;
  copy[0] = (char)toupper(copy[0]);
  for (size_t i = 1; i < copy.length(); i++) {
    copy[i] = (char)tolower(copy[i]);
  }
  return copy;
}

// Game utils

string getGameString(const string &str) {
  unsigned int hash = csHash((char*)str.c_str());
  char* langString = getLangString(hash);
  return strncmp(langString, "FENG:", 5) ? langString : "";
}

GameState getGameState() {
  switch (*SOME_STATE) {
  case 3:
    return GameState::InMenu;
  case 6:
    return (*IS_TUNING) ?
              GameState::Tuning :
              (*C_TRACK_PTR) == 4000 ?
                GameState::Exploring :
                GameState::Racing;
  default:
    return GameState::Loading;
  }
}

GameMode guessGameMode(int trackId) {
  switch (trackId / 100) {
  case 40:
    return GameMode::Circuit;
  case 41:
    return (trackId >= 4174) ? GameMode::Drift : GameMode::Sprint;
  case 43:
    return GameMode::Drift;
  case 42:
  case 44:
    return GameMode::Drag;
  case 46:
    return GameMode::StreetX;
  case 47:
    return GameMode::URL;
  default:
    return GameMode::Unknown;
  }
}

CarInfo getCarInfo(int carId) {
  if (carId < 0) {
    return {};
  }

  char* carData = getCarData(carId);
  return { carData, carData + 0xC0 };
}

string getTrack() {
  return to_string(*C_TRACK_PTR);
}

string getProfileName() {
  return PRF_NAME_PTR;
}

string getLobbyName() {
  return LBBY_NAME_PTR;
}

string getBalance() {
  return to_string(*BAL_PTR);
}
