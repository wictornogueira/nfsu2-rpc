#include <thread>
#include <fstream>
#include <windows.h>
#include <discord_rpc.h>

using namespace std;

const char* CARS[] = {
  "Peugeot 206 GTI",
  "Ford Focus ZX3",
  "Toyota Corolla GTS",
  "Nissan 240SX",
  "Mazda Miata",
  "Honda Civic Coupe Si",
  "Unknown",
  "Unknown",
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

static char* PROFILE = (char * )0x0083A9E0;
static UINT32* CAR = (UINT32 *)0x008021B0;
static UINT32* MONEY = (UINT32 *)0x00861E74;

static int64_t start_time;
boolean quit_flag = false;


static void update_discord_presence () {
  char details[256];
  char profile[16];

  sprintf(details, "%s - $%d", *CAR < 0 ? "None" : *CAR > 30 ? "Unknown" : CARS[*CAR] , *MONEY);

  for (char offset = 0; offset < 16; offset++) {
    profile[offset] = *(PROFILE + offset);
  }

  DiscordRichPresence discordPresence;
  memset(&discordPresence, 0, sizeof(discordPresence));
  discordPresence.state = details;
  discordPresence.details = profile;
  discordPresence.startTimestamp = start_time;
  discordPresence.largeImageKey = "logo";
  discordPresence.largeImageText = "Need for Speed: Underground 2";
  discordPresence.instance = 0;
  Discord_UpdatePresence(&discordPresence);
}

static void handle_discord_disconnected(int errcode, const char* message) {
  quit_flag = true;
}

static void handle_discord_error(int errcode, const char* message) {
  fstream error_file;
  error_file.open("discord-error.log", fstream::out);
  error_file << message;
  error_file.close();

  quit_flag = true;
}

static void discordInit() {
  DiscordEventHandlers handlers;
  memset(&handlers, 0, sizeof(handlers));
  handlers.errored = handle_discord_disconnected;
  handlers.disconnected = handle_discord_error;
  Discord_Initialize("811339054011777065", &handlers, 1, NULL);
}

static void init () {
  start_time = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();
  discordInit();

  while(!quit_flag){
    update_discord_presence();
    Discord_RunCallbacks();
    this_thread::sleep_for(chrono::seconds(5));
  }

  Discord_Shutdown();
}

extern "C" __declspec(dllexport)
BOOL APIENTRY DllMain (HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
  switch (fdwReason) {
    case DLL_PROCESS_ATTACH: {
      thread dummy(init);
      dummy.detach();
      break;
    }
    case DLL_PROCESS_DETACH:
      quit_flag = true;
      break;
  }

  return TRUE;
}
