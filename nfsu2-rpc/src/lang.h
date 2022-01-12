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

    string getString(string &str);
    string getString(const string& str);

    string getCarName(int carId);
    string getTrackName(int trackId);
    string getGameModeName(GameMode);

    string getStateString(GameState state, int carId);
    string getDetailsString(GameState state, int trackId);
};

