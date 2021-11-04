#ifndef _GETJSON_
#define _GETJSON_ 0

#include "json.hpp"
#include "fstream"
#include "iostream"
#include "dioses.h"
#include <vector>

using json = nlohmann::json;

using namespace std;

vector<Dios> getFromJSON(){

    std::vector<Dios> vectorDioses;

    fstream archivo("diosesJson.json");

    json infoDioses;

    archivo>>infoDioses;

    for (int i = 0; i < 20; i++){
        
        vectorDioses.push_back(Dios(infoDioses["Dioses"][i],infoDioses["Fieles"][i]));
    }
    return vectorDioses;
}

#endif 