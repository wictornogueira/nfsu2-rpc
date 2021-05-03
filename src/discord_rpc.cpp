#include <ctime>
#include <fstream>
#include <windows.h>
#include <discord_rpc.h>

#define APP_ID "811339054011777065"
#define UPD_INTVL 5000

using namespace std;

static const char* CAR_TABLE [] = {
  "Peugeot 206 GTI",
  "Ford Focus ZX3",
  "Toyota Corolla GTS",
  "Nissan 240SX",
  "Mazda Miata",
  "Honda Civic Coupe Si",
  "Peugeot 106",
  "Vauxhall Corsa",
  "Hummer H2",
  "Lincoln Navigator",
  "Cadillac Escalade",
  "Hyundai Tiburon GT",
  "Nissan Sentra SE-R Spec V",
  "Toyota Celica GT-S",
  "Lexus iS300",
  "Toyota Supra",
  "Volkswagen Golf GTI",
  "Audi A3",
  "Acura RSX Type S",
  "Mitsubishi Eclipse GSX",
  "Audi TT",
  "Mazda RX-8",
  "Nissan 350Z",
  "Infiniti G35",
  "Mitsubishi 3000 GT",
  "Pontiac GTO",
  "Ford Mustang GT",
  "Nissan Skyline R34 GTR",
  "Mitsubishi Lancer EVO VIII",
  "Mazda RX-7",
  "Subaru WRX STI"
};

static const char* PROFILE = (char *)0x0083A9E0;
static const int32_t* CAR = (int32_t *)0x008021B0;
static const int32_t* MONEY = (int32_t *)0x00861E74;

static const int64_t START_TIME = time(0);

static void update_discord_presence () {
  char details[256];
  char profile[16];

  sprintf_s(details, 256, "%s - $%d", *CAR < 0 ? "None" : *CAR > 30 ? "Unknown" : CAR_TABLE[*CAR] , *MONEY);
  memcpy_s(profile, 16, PROFILE, 16);

  DiscordRichPresence discordPresence;
  memset(&discordPresence, 0, sizeof(discordPresence));

  discordPresence.state = details;
  discordPresence.details = profile;
  discordPresence.startTimestamp = START_TIME;
  discordPresence.largeImageKey = "logo";
  discordPresence.largeImageText = "Need for Speed: Underground 2";

  Discord_UpdatePresence(&discordPresence);
}

static void handle_discord_error (int errcode, const char* message) {
  fstream error_file;
  error_file.open("discord-error.log", fstream::out);
  error_file << message;
  error_file.close();
}

static void init_discord () {
  DiscordEventHandlers handlers;
  memset(&handlers, 0, sizeof(handlers));
  handlers.errored = handle_discord_error;

  Discord_Initialize(APP_ID, &handlers, 0, 0);
}

static DWORD WINAPI ThreadEntry (LPVOID lpParam) {
  init_discord();

  while (1) {
    update_discord_presence();
    Discord_RunCallbacks();
    Sleep(UPD_INTVL);
  }
}

extern "C" __declspec(dllexport)
BOOL APIENTRY DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
  switch (fdwReason) {
    case DLL_PROCESS_ATTACH: {
      DisableThreadLibraryCalls(hinstDLL);
      CreateThread(0, 0, ThreadEntry, 0, 0, 0);
      break;
    }
    case DLL_PROCESS_DETACH:
      Discord_Shutdown();
      break;
  }

  return 1;
}
