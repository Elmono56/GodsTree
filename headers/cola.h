#ifndef _COLA_
#define _COLA_ 0

#include <functional>
#include <queue>
#include <vector>
#include "dioses.h"
#include "json.hpp"
#include "fstream"


using json = nlohmann::json;
using namespace std;



struct CompareAge {
    bool operator()(Dios & p1, Dios & p2) {
        return p1.getFieles() < p2.getFieles();
    }
};

class Cola{

    private:
        priority_queue<Dios, vector<Dios>, CompareAge> colaPrioridadDioses;

    public:

    Cola(){

        fstream archivo("diosesJson.json");

        json infoDioses;

        archivo>>infoDioses;

        for (int i = 0; i < 20; i++)
        {

            colaPrioridadDioses.push(Dios(infoDioses["Dioses"][i],infoDioses["Fieles"][i]));
            
        }
        archivo.close();
    }


    priority_queue<Dios, vector<Dios>, CompareAge> getColaDioses(){
        return colaPrioridadDioses;
    }

    void imprimirCola(priority_queue<Dios, vector<Dios>, CompareAge> pColaPrueba)
    {
        while (!pColaPrueba.empty())
        {
            cout << pColaPrueba.top().getName() << " / " << pColaPrueba.top().getFieles() << endl;
            pColaPrueba.pop();
        }
    }

    int getPQSize(){
        return colaPrioridadDioses.size();
    }

    Dios getDios(){
        Dios deus = colaPrioridadDioses.top();
        colaPrioridadDioses.pop();
        return deus;
    }

    void pushDios(Dios* pDiosA){

        colaPrioridadDioses.push(*pDiosA);

    }

};


#endif