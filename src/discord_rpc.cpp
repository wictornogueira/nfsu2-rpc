#include <ctime>
#include <stdio.h>
#include <windows.h>
#include <discord_rpc.h>

#include <config.h>
#include <utils.h>

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
    (*CAR_PTR < 0)  ? sprintf_s(state, 64, "$%d", *MONEY_PTR)
                    : sprintf_s(state, 64, "%s - $%d", *CAR_PTR > 30 ? UNK_CAR : CAR_TABLE[*CAR_PTR] , *MONEY_PTR);

    memcpy_s(details, 16, PROFILE_PTR, 16);

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
