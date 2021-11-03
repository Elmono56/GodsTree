#include "headers/json.hpp"
#include "fstream"
#include "iostream"
#include "headers/dioses.h"
#include <vector>

using json = nlohmann::json;

using namespace std;

std::vector<Dios> vectorDioses;

int main(){

    fstream archivo("diosesJson.json");

    json infoDioses;

    archivo>>infoDioses;

    for (int i = 0; i < 20; i++)
    {

        vectorDioses.push_back(Dios(infoDioses["Dioses"][i],infoDioses["Fieles"][i]));

        
    }

    while(!vectorDioses.empty()){
        cout << vectorDioses.back().getFieles() << endl;
        vectorDioses.pop_back();
    }

    archivo.close();

    return 0;

}
 