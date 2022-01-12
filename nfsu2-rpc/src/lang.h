#pragma once

#include <string>
#include "json.hpp"
#include "utils.h"

using namespace std;
using json = nlohmann::json;

/*
  This class is responsible for handling string fallback and all that fun stuff
*/

class LangManager {
  private:
    json langJson;
  public:
    LangManager();
    LangManager(json &lJson);
    void setJson(json &lJson);

    string getString(const string& str);

    string getCarName(CarInfo carInfo = getCarInfo());
    string getTrackName(const string& strTrackId = getTrack());
    string getGameModeName(GameMode gameMode = guessGameMode());

    string getDetailsTemplate(GameState gameState = getGameState());
    string getStateTemplate(GameState gameState = getGameState());

    string getStateString();
    string getDetailsString();


    string replaceAllPlaceHolders(const string& str);
};

