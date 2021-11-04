#ifndef _COLA_
#define _COLA_ 0

#include <functional>
#include <queue>
#include <vector>
#include "dioses.h"
#include "json.hpp"
#include "fstream"
#include "gfJSON.h"

using namespace std;



struct CompareAge {
    bool operator()(Dios & pDios1, Dios & pDios2) {
        return pDios1.getFieles() < pDios2.getFieles();
    }
};

class Cola{

    private:
        priority_queue<Dios, vector<Dios>, CompareAge> colaPrioridadDioses;

    public:

    Cola(){

        vector<Dios> auxiliar = getFromJSON();

         while(!auxiliar.empty()){
            colaPrioridadDioses.push(auxiliar.back());
            auxiliar.pop_back();
        }
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