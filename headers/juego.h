
#ifndef _JUEGO_
#define _JUEGO_ 0

#include "cartas.h"
#include "dioses.h"
#include "pila.h"
#include "cola.h"
#include "avl.h"

#include <windows.h>
#include <time.h>
#include <iostream>
#include<conio.h>

#define KEY_X 120

bool juego = true;

void ejecutar(Pila<Carta> pMazoCartas, Cola pColaDioses,avl *bosque[]){ //priority_queue<Dios, vector<Dios>, CompareAge> *pMazoDioses){ / vector<avl*> arboles

    
    while(juego & pColaDioses.getPQSize()!=0){

        Carta pSiguiente = pMazoCartas.getCarta(); 
        
        if(pSiguiente.getTipo() == "Milagro"){

            CartaMilagro jugada = CartaMilagro();

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
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

            cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" << endl;
            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;
            jugada.realizaraccion(&diosA,&diosB);
            cout << diosA.getFieles() << " / " << diosA.getName() << "---------" << diosB.getFieles() << " / " << diosB.getName() << endl;
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
            pColaDioses.pushDios(&diosB);
        }

        else if (pSiguiente.getTipo()=="Anarquia"){

            CartaAnarquia jugada = CartaAnarquia();

            Dios diosA = pColaDioses.getDios();

            cout << "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC" << endl;

            jugada.realizaraccion(&diosA,bosque);
            
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);

        }

        else if (pSiguiente.getTipo()=="Union"){

            CartaUnion jugada = CartaUnion();

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDd" << endl;
            
            jugada.realizaraccion(&diosA, &diosB, bosque);

            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
            pColaDioses.pushDios(&diosB);

        }

        else if (pSiguiente.getTipo()=="NuevoDios"){

            CartaNuevoDios jugada = CartaNuevoDios();

            Dios diosA = pColaDioses.getDios();
            Dios diosB = pColaDioses.getDios();

            cout << "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << endl;
            jugada.realizaraccion(&diosA,&diosB,&pColaDioses);
            cout << "----------------------------" << endl;

            pColaDioses.pushDios(&diosA);
            pColaDioses.pushDios(&diosB);

        }

        else if (pSiguiente.getTipo()=="Retorno"){

            CartaRetorno jugada = CartaRetorno();
            
            cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFf" << endl;
            cout << "             RETORNO        " << endl;
            jugada.realizaraccion(&pMazoCartas);
            cout << "----------------------------" << endl;

        }

        else if (pSiguiente.getTipo()=="Muerte"){

            CartaMuerte jugada = CartaMuerte();

            Dios diosA = pColaDioses.getDios();

            cout << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG" << endl;
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
}

void finalizar(){
    
    char key = getch();
    int value = key;

    if(value == KEY_X){

        juego = false;

        cout << "Juego finalizado" << endl;
        
    }
};

#endif