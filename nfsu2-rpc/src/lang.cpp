#include "lang.h"

LangManager::LangManager() {}

LangManager& LangManager::getInstance() {
  static LangManager instance;
  return instance;
}

string LangManager::getString(const string &str) {
  return m_jsonObj.value(json::json_pointer(str), "");
}

/*
  1. Checks JSON
  2. Checks game language
  3. Uses name and brand extracted from carTypeInfo
*/

string LangManager::getCarName(CarInfo carInfo) {
  if (!carInfo.name) {
    return "";
  }

  string carTypeName = string(carInfo.name);
  string carFullName = getString("/cars/" + carTypeName);

  if (!carFullName.length()) {
    string carName = getGameString("CAR_NAME_" + carTypeName);
    string carBrand = string(carInfo.brand);

    carFullName = carName.length() ? capitalizeString(carBrand) + " " + carName : carBrand + " " + carTypeName;
  }

  return carFullName;
}

/*
  Did not have to be here, but I wanted to group all getWhateverName

  1. Checks game language
  2. Uses trackId
*/

string LangManager::getTrackName(const string &strTrackId) {
  string trackName = getGameString("TRACK_NAME_" + strTrackId);
  return trackName.length() ? trackName : strTrackId;
}

/*
  1. Checks JSON
*/

string LangManager::getGameModeName(GameMode gameMode) {
  static const char* gameModeKeys[] = { "url", "drag", "drift", "sprint", "circuit", "unknown", "streetx", "explorer" };
  return getString(string("/gamemodes/") + gameModeKeys[(int)gameMode]);
}

/*
  1. Checks JSON
*/

string LangManager::getDetailsTemplate(GameState gameState) {
  static const char* gameStateKeys[] = { "loading", "inmenu", "racing", "tuning", "exploring" };
  return getString(string("/activity/details/") + gameStateKeys[(int)gameState]);
}

/*
  1. Checks JSON
*/

string LangManager::getStateTemplate(GameState gameState) {
  static const char* gameStateKeys[] = { "loading", "inmenu", "racing", "tuning", "exploring" };
  return getString(string("/activity/state/") + gameStateKeys[(int)gameState]);
}

/*
  TODO: Optimize
*/

/*
  This is kinda ridiculous
*/

string LangManager::replaceAllPlaceHolders(const string &str) {
    return replaceAll(
      replaceAll(
        replaceAll(
          replaceAll(
            replaceAll(
              replaceAll(
                str,
                "$lobby$", getLobbyName()),
              "$profile$", getProfileName()),
            "$balance$", getBalance()),
          "$gamemode$", getGameModeName()),
        "$track$", getTrackName()),
      "$car$", getCarName());
}

string LangManager::getStateString() {
  return replaceAllPlaceHolders(getStateTemplate());
}

string LangManager::getDetailsString() {
  return replaceAllPlaceHolders(getDetailsTemplate());
}

void LangManager::update(json j) {
  m_jsonObj.merge_patch(j);
}
