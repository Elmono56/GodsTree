
#ifndef _JUEGO_
#define _JUEGO_ 0

#include "cartas.h"
#include "dioses.h"
#include "pila.h"
#include "cola.h"

#include <windows.h>
#include <time.h>
#include <iostream>


void ejecutar(Pila<Carta> pMazoCartas, Cola pColaDioses){ //priority_queue<Dios, vector<Dios>, CompareAge> *pMazoDioses){

    
    while(pColaDioses.getPQSize()!=0){

        Carta pSiguiente = pMazoCartas.getCarta(); 
        
        if(pSiguiente.getTipo() == "Milagro"){

            CartaMilagro jugada = CartaMilagro();

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;

            jugada.realizaraccion(&diosA,&diosB);

            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
            pColaDioses.pushDios(&diosB);

        }
        else if (pSiguiente.getTipo()=="Traicion"){

            CartaTraicion jugada = CartaTraicion();

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;
            jugada.realizaraccion(&diosA,&diosB);
            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
            pColaDioses.pushDios(&diosB);
        }

        else if (pSiguiente.getTipo()=="Anarquia"){

            cout << "----------------------------" << endl;
            cout << "            ANARQUIA        " << endl;
            cout << "----------------------------" << endl;

        }

        else if (pSiguiente.getTipo()=="Union"){

            cout << "----------------------------" << endl;
            cout << "              UNION         " << endl;
            cout << "----------------------------" << endl;

        }

        else if (pSiguiente.getTipo()=="NuevoDios"){

            CartaNuevoDios jugada = CartaNuevoDios();

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            jugada.realizaraccion(&diosA,&diosB,&pColaDioses);
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
            pColaDioses.pushDios(&diosB);

        }

        else if (pSiguiente.getTipo()=="Retorno"){

            CartaRetorno jugada = CartaRetorno();
            
            cout << "----------------------------" << endl;
            cout << "             RETORNO        " << endl;
            jugada.realizaraccion(&pMazoCartas);
            cout << "----------------------------" << endl;

        }

        else if (pSiguiente.getTipo()=="Muerte"){

            CartaMuerte jugada = CartaMuerte();

            Dios diosA = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            cout << diosA.getFieles() << " / " << diosA.getName() << endl;
            jugada.realizaraccion(&diosA);
            cout << diosA.getFieles() << " / " << diosA.getName() << endl;
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);

        }
        else{

        }
        //cout<<"SIZE COLA DIOSES"<<pColaDioses.getPQSize()<<endl;
        Sleep(3000);
        
    }

};


#endif