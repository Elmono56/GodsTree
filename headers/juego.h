
#ifndef _JUEGO_
#define _JUEGO_ 0

#include "cartas.h"
#include "dioses.h"
#include "pila.h"
#include "cola.h"

#include <windows.h>
#include <time.h>
#include <iostream>


void ejecutar(Pila pMazoCartas, Cola pColaDioses){ //priority_queue<Dios, vector<Dios>, CompareAge> *pMazoDioses){

    
    while(pColaDioses.getPQSize()!=0){

        Carta pSiguiente = pMazoCartas.getCarta(); 
        
        if(pSiguiente.getTipo() == "Milagro"){

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;

            salvar.realizaraccion(&diosA,&diosB);

            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;
            cout << "----------------------------" << endl;

        }
        else if (pSiguiente.getTipo()=="Traicion"){

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;
            salvar.realizaraccion(&diosA,&diosB);
            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;
            cout << "----------------------------" << endl;
        }

        else if (pSiguiente.getTipo()=="Anarquia"){

        }

        else if (pSiguiente.getTipo()=="Union"){

        }

        else if (pSiguiente.getTipo()=="NuevoDios"){

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            salvar.realizaraccion(&diosA,&diosB);
            cout << "----------------------------" << endl;

        }

        else if (pSiguiente.getTipo()=="Retorno"){
            
            cout << "----------------------------" << endl;
            salvar.realizaraccion(&pMazoCartas);
            cout << "----------------------------" << endl;

        }

        else if (pSiguiente.getTipo()=="Muerte"){

            Dios diosA = pColaDioses.getDios();

            cout << "----------------------------" << endl;
            cout << diosA.getFieles() << " / " << diosA.getName() << endl;
            salvar.realizaraccion(&diosA);
            cout << diosA.getFieles() << " / " << diosA.getName() << endl;
            cout << "----------------------------" << endl;

        }
        else{

        }

        Sleep(3000);    
    }

};


#endif