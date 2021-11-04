#ifndef _ARBOLI_
#define _ARBOLI_ 0

#include <vector>
#include "dioses.h"
#include "avl.h"
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "dioses.h"
#include "cola.h"


avl* crearArbol(){

    avl_tree arbolAVL;
    
    Cola colaDioses;
    
    priority_queue<Dios, vector<Dios>, CompareAge> colaPrioridad= colaDioses.getColaDioses();
    
    priority_queue<Dios, vector<Dios>, CompareAge> *ptrCola;
    ptrCola = &colaPrioridad;
    
    avl* root = nullptr;
    
    while(!ptrCola->empty())
    {
       root = arbolAVL.insert(root, ptrCola->top());
       ptrCola->pop();
    }
   return root;
}

#endif