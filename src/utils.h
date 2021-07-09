#include <unordered_map>

namespace utils {
  const char* const PRF_NAME_PTR  = (char*) 0x0083A9E0; // 15 byte-long
  const char* const LBBY_NAME_PTR = (char*) 0x0086A3D8; // 12 byte-long
  const int*  const BAL_PTR       = (int*)  0x00861E74;
  const int*  const C_CAR_PTR     = (int*)  0x008021B0;
  const int*  const C_TRACK_PTR   = (int*)  0x0089E7A0;
  const int*  const CARS_ADDR_PTR = (int*)  0x008A1CCC;

  std::unordered_map<std::string, const char*> CAR_TABLE = {
    // Vanilla

    {"PEUGOT", "Peugeot 206 GTi"},
    {"FOCUS", "Ford Focus ZX3"},
    {"COROLLA", "Toyota Corolla GTS"},
    {"240SX", "Nissan 240SX"},
    {"MIATA", "Mazda Miata"},
    {"CIVIC", "Honda Civic Coupe Si"},
    {"PEUGOT106", "Peugeot 106"},
    {"CORSA", "Vauxhall Corsa"},
    {"HUMMER", "Hummer H2"},
    {"NAVIGATOR", "Lincoln Navigator"},
    {"ESCALADE", "Cadillac Escalade"},
    {"TIBURON", "Hyundai Tiburon GT"},
    {"SENTRA", "Nissan Sentra SE-R Spec V"},
    {"CELICA", "Toyota Celica GT-S"},
    {"IS300", "Lexus iS300"},
    {"SUPRA", "Toyota Supra"},
    {"GOLF", "Volkswagen Golf GTI"},
    {"A3", "Audi A3"},
    {"RSX", "Acura RSX Type S"},
    {"ECLIPSE", "Mitsubishi Eclipse GSX"},
    {"TT", "Audi TT"},
    {"RX8", "Mazda RX-8"},
    {"350Z", "Nissan 350Z"},
    {"G35", "Infiniti G35"},
    {"3000GT", "Mitsubishi 3000 GT"},
    {"GTO", "Pontiac GTO"},
    {"MUSTANGGT", "Ford Mustang GT"},
    {"SKYLINE", "Nissan Skyline R34 GT-R"},
    {"LANCEREVO8", "Mitsubishi Lancer EVO VIII"},
    {"RX7", "Mazda RX-7"},
    {"IMPREZAWRX", "Subaru WRX STI"},

    // Olympic Imports

    {"IMPREZA", "Subaru Impreza RS"},
    {"INTEGRA", "Acura Integra Type R"},
    {"LANCER", "Mitsubishi Lancer ES"},
    {"NEONC", "Dodge Neon"},
    {"NSX", "Acura NSX"},
    {"S2000", "Honda S2000"},
    {"LOCK", "Lock"},                  // why? ;-;
    {"CHARGER", "Dodge Charger R/T"},
  };

  std::unordered_map<short, const char*> TRACK_TABLE = {
    // Circuit

    {4001, "Outer Ring"},
    {4002, "Freeway West"},
    {4003, "Freeway East"},
    {4004, "Jackpot"},
    {4005, "Garibaldi Run"},
    {4006, "Broad Street"},

    {4011, "Freemont"},
    {4012, "Providencia"},
    {4013, "Scenic Ride"},
    {4014, "Resort Loop"},
    {4015, "Lower Eastside"},

    {4021, "City Hall"},
    {4022, "Switchback"},
    {4023, "Shoreside"},
    {4024, "Park Drive"},

    {4041, "Dockside"},
    {4042, "Boxcar"},
    {4043, "Smokestack"},
    {4044, "Bayview Concrete"},
    {4045, "Phoenix Steel"},

    {4062, "Bellavista"},
    {4063, "Bayview Summit"},
    {4061, "Observatory"},
    
    {4081, "Palm Highway"},
    {4082, "Ambassador Ridge"},
    {4083, "University Hill"},
    {4084, "Marine & 25th"},
    {4085, "Grandview Station"},
    {4086, "Woodbine Park"},
    {4087, "12th & Arbutus"},
    {4088, "Bayview International"},

    // Sprint

    {4101, "Bayview Plaza"},
    {4102, "Palomino & 16th"},
    {4103, "South Junction"},
    {4104, "Upper Deck"},
    {4105, "Blackcomb Way"},
    {4106, "Cypress Bowl"},
    {4107, "Marathon"},

    {4121, "Rockridge Cross"},
    {4122, "Palm Hill"},
    {4123, "Wall Center"},
    {4124, "Tailgate"},
    {4125, "Sentinel Hill"},
    {4126, "Black Tusk"},
    {4127, "2nd & Bellevue"},
    
    {4141, "Terminal & 2nd"},
    {4142, "Port Authority"},
    {4143, "Waste Management"},
    {4144, "Domestic Arrivals"},
    {4145, "Broadway & Grandville"},

    {4161, "Rollercoaster"},
    {4162, "Eagleridge Estates"},
    {4163, "The Chief"},
    {4164, "Grouse Grind"},

    // Drag

    {4201, "Bayview Bridge"},

    {4211, "Central Station"},
    {4212, "Coastal Express"},
    {4213, "Switching Yard"},

    {4221, "South Runway"},
    {4222, "Runway 15"},
    {4223, "Runway 9"},

    {4401, "Tunnel Construction"},
    {4402, "North Freeway"},
    {4404, "Airport Freeway"},

    // Drift

    {4301, "Parkade Drift 1"},
    {4302, "Parkade Drift 2"},
    {4303, "Parkade Drift 3"},
    {4304, "Parkade Drift 4"},
    {4305, "Parkade Drift 5"},
    {4306, "Parkade Drift 6"},

    {4311, "Stadium Drift 1"},
    {4312, "Stadium Drift 2"},
    {4313, "Stadium Drift 3"},
    {4314, "Stadium Drift 4"},
    {4315, "Stadium Drift 5"},

    {4174, "Capilano Heights"},
    {4175, "Hillside Manor"},
    {4176, "Powerline"},
    {4177, "Hollyburn Ridge"},
    {4178, "Lighthouse"},
    {4179, "City Lights"},

    // Street X

    {4601, "Industrial Park Track 1"},
    {4602, "Industrial Park Track 2"},
    {4603, "Industrial Park Track 3"},
    {4604, "Industrial Park Track 4"},
    {4605, "Parkade Track 1"},
    {4606, "Parkade Track 3"},
    {4607, "Parkade Track 3"},
    {4608, "Parkade Track 4"},

    // URL

    {4701, "Bayview Speedway Track 1"},
    {4702, "Bayview Speedway Track 2"},
    {4703, "Bayview Speedway Track 3"},
    {4704, "Bayview Speedway Track 4"},
    {4705, "Bayview Speedway Track 5"},

    {4711, "Airport Circuit Track 1"},
    {4712, "Airport Circuit Track 2"},
    {4713, "Airport Circuit Track 3"},
    {4714, "Airport Circuit Track 4"},
    {4715, "Airport Circuit Track 5"},
    {4716, "Airport Circuit Track 6"},
  };
}
