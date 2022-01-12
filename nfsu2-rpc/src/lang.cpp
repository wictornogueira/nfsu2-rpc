#include "lang.h"

bool once = true;

LangManager::LangManager(json &lJson) {
  langJson = lJson;
}

LangManager::LangManager() {
}

void LangManager::setJson(json &lJson) {
  langJson = lJson;
}

string LangManager::getString(const string &str) {
  return langJson.value(json::json_pointer(str), "");
}

/*
  1. Checks JSON
  2. Checks game language
  3. Uses name and brand extracted from carTypeInfo
*/

string LangManager::getCarName(int carId) {
  if (carId < 0) {
    return "SUS";
  }

  CarInfo carInfo = getCarInfo(carId);
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

string LangManager::getTrackName(int trackId) {
  string strTrackId = to_string(trackId);
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
  TODO: Make this return something other than what car is currently being driven
*/

string LangManager::getStateString(GameState state, int carId) {
  return (int)state > 1 ?
          replaceAll(getString("/activity/state"), "$car$", getCarName(carId)) :
          "";
}

/*
  TODO: Make it more customizable
*/

string LangManager::getDetailsString(GameState state, int trackId) {
  static const char* gameStateKeys[] = { "loading", "inmenu", "racing", "tuning", "exploring" };
  string detail = getString(string("/activity/details/") + gameStateKeys[(int)state]);

  if (state == GameState::Racing) {
    detail = replaceAll(
      replaceAll(detail, "$gamemode$", getGameModeName(guessGameMode(trackId))),
      "$track$",
      getTrackName(trackId)
    );
  }

  return detail;
}
