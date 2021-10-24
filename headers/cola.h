#ifndef _COLA_
#define _COLA_ 0

#include <functional>
#include <queue>
#include <vector>
#include "dioses.h"

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
        Dios Thor = Dios("Thor",100);
        Dios Loki = Dios("Loki",500);
        Dios Hela = Dios("Hela", 150);
        Dios Zeus = Dios("Zeus",400);
        Dios Jesus = Dios("Jesus",50);

        Dios Ares = Dios("Ares",175);
        Dios Apolo = Dios("Apolo",620);
        Dios Asclepio = Dios("Asclepio", 120);
        Dios Baco = Dios("Baco",420);
        Dios Cupido = Dios("Cupido",510);

        Dios Dionisio = Dios("Dionisio",160);
        Dios Eros = Dios("Eros",340);
        Dios Febo = Dios("Febo", 550);
        Dios Forcis = Dios("Forcis",700);
        Dios Hades = Dios("Hades",905);

        Dios Hefesto = Dios("Hefesto",170);
        Dios Hercules = Dios("Hercules",500);
        Dios Hermes = Dios("Hermes", 130);
        Dios Helios = Dios("Helios",565);
        Dios Marte = Dios("Marte",50);

        colaPrioridadDioses.push(Thor);
        colaPrioridadDioses.push(Loki);
        colaPrioridadDioses.push(Hela);
        colaPrioridadDioses.push(Zeus);
        colaPrioridadDioses.push(Jesus);

        colaPrioridadDioses.push(Ares);
        colaPrioridadDioses.push(Apolo);
        colaPrioridadDioses.push(Asclepio);
        colaPrioridadDioses.push(Baco);
        colaPrioridadDioses.push(Cupido);

        colaPrioridadDioses.push(Dionisio);
        colaPrioridadDioses.push(Eros);
        colaPrioridadDioses.push(Febo);
        colaPrioridadDioses.push(Forcis);
        colaPrioridadDioses.push(Hades);

        colaPrioridadDioses.push(Hefesto);
        colaPrioridadDioses.push(Hercules);
        colaPrioridadDioses.push(Hermes);
        colaPrioridadDioses.push(Helios);
        colaPrioridadDioses.push(Marte);
    }

    priority_queue<Dios, vector<Dios>, CompareAge> getColaDioses(){
        return colaPrioridadDioses;
    }

    void imprimirCola(priority_queue<Dios, vector<Dios>, CompareAge> pColaPrueba)
    {
        while (!pColaPrueba.empty())
        {
            cout << pColaPrueba.top().getName() << " / " << pColaPrueba.top().getFieles() << endl; //está dando errores
            pColaPrueba.pop();
        }
    }

    //Dios getTwoDioses(){
        //debe devolver dos dioses
    //}

    //Dios getOneDios(){
        //debe retornar un dios
    //}



};


#endif