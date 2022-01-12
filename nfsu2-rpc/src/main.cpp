#include "main.h"

namespace {
  discord::Core* core{};
  discord::Activity activity{};
  LangManager langManager;
}

void mainLoopHook() {
#if FRAME_SKIP > 0

  static size_t skippedFrames = 0;

  if (skippedFrames != FRAME_SKIP) {
    skippedFrames++;
    goto runCBacks;
  }

  skippedFrames = 0;

#endif

  activity.SetState(langManager.getStateString().c_str());
  activity.SetDetails(langManager.getDetailsString().c_str());

  core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});

  runCBacks:
  core->RunCallbacks();
}

void init(HMODULE hModule) {
  discord::Result result = discord::Core::Create(APP_ID, DiscordCreateFlags_Default, &core);

  if (result != discord::Result::Ok) {
    return;
  }

  activity.GetAssets().SetLargeImage(IMG_KEY);
  activity.GetAssets().SetLargeText(IMG_TXT);
  activity.GetTimestamps().SetStart(time(0));

  try {
    json langJson = buildLangJsonObj(hModule, MAKEINTRESOURCE(IDR_TEXT1));
    langManager.setJson(langJson);

    makeCall(0x005814DB, &mainLoopHook);
  } catch (exception e) {}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
  if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
    init(hModule);
  }

  return TRUE;
}