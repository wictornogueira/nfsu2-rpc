#pragma once

const char* const PRF_NAME_PTR  = (char*) 0x0083A9E0;
const char* const LBBY_NAME_PTR = (char*) 0x0086A3D8;
const bool* const IS_TUNING     = (bool*) 0x0089E7E6;
const int*  const BAL_PTR       = (int*)  0x00861E74;
const int*  const C_CAR_PTR     = (int*)  0x008021B0;
const int*  const C_TRACK_PTR   = (int*)  0x0089E7A0;
const int*  const CARS_ADDR_PTR = (int*)  0x008A1CCC;
const int*  const SOME_STATE    = (int*)  0x008654A4;

char*        (*const getCarData)    (int carId)         = (char* (*)(int))          0x00610110;
char*        (*const getLangString) (unsigned int hash) = (char* (*)(unsigned int)) 0x004FFA80; // 4FF9D0
unsigned int (*const ciHash)        (char* str)         = (unsigned int (*)(char*)) 0x00505450;
unsigned int (*const csHash)        (char* str)         = (unsigned int (*)(char*)) 0x0043DB50;
