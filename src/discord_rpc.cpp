#include <ctime>
#include <stdio.h>
#include <windows.h>
#include <discord_rpc.h>

#include <config.h>
#include <utils.h>

using namespace std;
using namespace utils;

static void format_state (char* state, char length) {
  if (*C_CAR_PTR < 0) {
    state[0] = 0;
    return;
  }

  const int car_addr = (*CARS_ADDR_PTR + (*C_CAR_PTR * 0x890));
  const char* const car_name = (char*)(car_addr + 0x20);
  
  const auto car_itr = CAR_TABLE.find(car_name);
  if (car_itr != CAR_TABLE.end()) {
    sprintf_s(state, length, "%s", car_itr->second);
  } else {
    const char* const car_brand = (char*)(car_addr + 0xC0);
    sprintf_s(state, length, "%s %s", car_brand, car_name);
  }
}

static void format_details (char* details, char length) {
  switch (*C_TRACK_PTR) {
    case 0:
    case 2000:
      sprintf_s(details, length, (*LBBY_NAME_PTR == 0) ? IN_MENU : IN_LOBBY);
      break;
    case 4000:
      sprintf_s(details, length, GM_EXPLORER);
      break;
    default: {
      const char* mode;

      switch (*C_TRACK_PTR / 100) {
        case 40:
          mode = GM_CIRCUIT;
          break;
        case 41:
          mode = (*C_TRACK_PTR >= 4174) ? GM_DRIFT : GM_SPRINT;
          break;
        case 43:
          mode = GM_DRIFT;
          break;
        case 42:
        case 44:
          mode = GM_DRAG;
          break;
        case 46:
          mode = GM_STREET_X;
          break;
        case 47:
          mode = GM_URL;
          break;
        default:
          mode = GM_UNKNOWN;
      }

      const auto track_itr = TRACK_TABLE.find(*C_TRACK_PTR);
      const char* const track_name = track_itr != TRACK_TABLE.end() ? track_itr->second : UNK_TRACK;

      sprintf_s(details, length, (*LBBY_NAME_PTR == 0) ? "%s - %s" : "%s - %s (LAN)", mode, track_name);
    }
  }
}

static DWORD WINAPI ThreadEntry (LPVOID lpParam) {
  char state[64];
  char details[64];
  
  Discord_Initialize(APP_ID, 0, 0, 0);

  DiscordRichPresence discord_presence;
  memset(&discord_presence, 0, sizeof(discord_presence));

  discord_presence.startTimestamp = time(0);
  discord_presence.largeImageKey = IMG_KEY;
  discord_presence.largeImageText = IMG_TXT;

  discord_presence.state = state;
  discord_presence.details = details;

  while (1) {
    format_details(details, sizeof(details));
    format_state(state, sizeof(state));

    Discord_UpdatePresence(&discord_presence);
    Discord_RunCallbacks();
    Sleep(UPD_INTVL);
  }
}

extern "C" __declspec(dllexport)
BOOL APIENTRY DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
  switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
      DisableThreadLibraryCalls(hinstDLL);
      CreateThread(0, 0, ThreadEntry, 0, 0, 0);
      break;
    case DLL_PROCESS_DETACH:
      Discord_Shutdown();
      break;
  }

  return 1;
}
