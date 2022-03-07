#include "../resource.h"
#include "config.h"
#include "utils.h"
#include "lang.h"

#include <discord/discord.h>
#include <json.hpp>

#include <ctime>
#include <string>
#include <windows.h>

namespace {
  discord::Core* core{};
  discord::Activity activity{};
}

void mainLoopHook() {
#if FRAME_SKIP > 0
  static size_t skippedFrames = 0;

  if (skippedFrames != FRAME_SKIP) {
    skippedFrames++;
    goto runCallBacks;
  }

  skippedFrames = 0;
#endif

  activity.SetState(LangManager::getInstance().getStateString().c_str());
  activity.SetDetails(LangManager::getInstance().getDetailsString().c_str());

  core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});

  runCallBacks:
  core->RunCallbacks();
}

void init(HMODULE hModule) {
  discord::Result result = discord::Core::Create(APP_ID, DiscordCreateFlags_Default, &core);

  if (result != discord::Result::Ok) {
    return;
  }

  try {
    LangManager::getInstance().update(buildLangJsonObj(hModule, MAKEINTRESOURCE(IDR_LANGF)));

    activity.GetAssets().SetLargeImage(IMG_KEY);
    activity.GetAssets().SetLargeText(IMG_TXT);
    activity.GetTimestamps().SetStart(time(0));

    makeCall(0x005814DB, &mainLoopHook);
  } catch (...) {}
}

// Prevents game from going brrr
DWORD WINAPI threadInit(LPVOID lpParam) {
  init((HMODULE)lpParam);
  return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
  if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
    DisableThreadLibraryCalls(hModule);
    CreateThread(0, 0, threadInit, hModule, 0, 0);
  }

  return 1;
}
