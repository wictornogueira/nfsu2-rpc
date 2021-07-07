#include <stdint.h>
#include <unordered_map>

namespace utils {
  const char*     const PRF_NAME_PTR  = (char *)    0x0083A9E0; // 15 byte-long
  const char*     const LBBY_NAME_PTR = (char *)    0x0086A3D8; // 12 byte-long
  const int32_t*  const BAL_PTR       = (int32_t *) 0x00861E74;
  const int32_t*  const C_CAR_PTR     = (int32_t *) 0x008021B0;
  const int32_t*  const C_TRACK_PTR   = (int32_t *) 0x0089E7A0;

  std::unordered_map<short, const char*> CAR_TABLE = {
    // Vanilla

    {0, "Peugeot 206 GTI"},
    {1, "Ford Focus ZX3"},
    {2, "Toyota Corolla GTS"},
    {3, "Nissan 240SX"},
    {4, "Mazda Miata"},
    {5, "Honda Civic Coupe Si"},
    {6, "Peugeot 106"},
    {7, "Vauxhall Corsa"},
    {8, "Hummer H2"},
    {9, "Lincoln Navigator"},
    {10, "Cadillac Escalade"},
    {11, "Hyundai Tiburon GT"},
    {12, "Nissan Sentra SE-R Spec V"},
    {13, "Toyota Celica GT-S"},
    {14, "Lexus iS300"},
    {15, "Toyota Supra"},
    {16, "Volkswagen Golf GTI"},
    {17, "Audi A3"},
    {18, "Acura RSX Type S"},
    {19, "Mitsubishi Eclipse GSX"},
    {20, "Audi TT"},
    {21, "Mazda RX-8"},
    {22, "Nissan 350Z"},
    {23, "Infiniti G35"},
    {24, "Mitsubishi 3000 GT"},
    {25, "Pontiac GTO"},
    {26, "Ford Mustang GT"},
    {27, "Nissan Skyline R34 GTR"},
    {28, "Mitsubishi Lancer EVO VIII"},
    {29, "Mazda RX-7"},
    {30, "Subaru WRX STI"},

    // Olympic Imports

    {46, "Subaru Impreza RS"},
    {47, "Acura Integra Type R"},
    {48, "Mitsubishi Lancer ES"},
    {49, "Dodge Neon"},
    {50, "Acura NSX"},
    {51, "Honda S2000"},
    {52, "Lock"},                  // why? ;-;
    {53, "Dodge Charger R/T"},
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
