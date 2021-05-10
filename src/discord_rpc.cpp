#include <ctime>
#include <stdio.h>
#include <windows.h>
#include <discord_rpc.h>

#include <utils.h>

#define APP_ID "811339054011777065"
#define IMG_KEY "logo"
#define IMG_TXT "Need for Speed: Underground 2"
#define UNK_CAR "Unknown"
#define UPD_INTVL 5000

using namespace std;
using namespace utils;

static DWORD WINAPI ThreadEntry (LPVOID lpParam) {
  char state[64];
  char details[16];
  
  Discord_Initialize(APP_ID, 0, 0, 0);

  DiscordRichPresence discord_presence;
  memset(&discord_presence, 0, sizeof(discord_presence));

  discord_presence.startTimestamp = time(0);
  discord_presence.largeImageKey = IMG_KEY;
  discord_presence.largeImageText = IMG_TXT;

  discord_presence.state = state;
  discord_presence.details = details;

  while (1) {
    (*CAR < 0)  ? sprintf_s(state, 64, "$%d", *MONEY)
                : sprintf_s(state, 64, "%s - $%d", *CAR > 30 ? UNK_CAR : CAR_TABLE[*CAR] , *MONEY);

    memcpy_s(details, 16, PROFILE, 16);

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
