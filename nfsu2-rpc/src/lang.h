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
  public:
    static LangManager& getInstance();

  private:
    LangManager();

    string getCarName(CarInfo carInfo = getCarInfo());
    string getTrackName(const string& strTrackId = getTrack());
    string getGameModeName(GameMode gameMode = guessGameMode());
    string getDetailsTemplate(GameState gameState = getGameState());
    string getStateTemplate(GameState gameState = getGameState());
    string replaceAllPlaceHolders(const string& str);

  private:
    json m_jsonObj;

  public:
    LangManager(LangManager const&) = delete;
    void operator=(LangManager const&) = delete;

    void update(json j);
    string getString(const string& str);
    string getStateString();
    string getDetailsString();
};

