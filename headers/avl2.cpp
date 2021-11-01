#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "dioses.h"
#include "cola.h"

using namespace std;

struct avl {

   Dios value;
   struct avl *leftSon = nullptr;
   struct avl *rightSon = nullptr;

}*root;

class avl_tree {
   public:

      int height(avl *Nodo) {
         int h = 0;
         if (Nodo != NULL) {
            int l_height = height(Nodo->leftSon);
            int r_height = height(Nodo->rightSon);
            int max_height = max(l_height, r_height);
            h = max_height + 1;
         }
         return h;
      }

      int difference(avl *Nodo) {
         int l_height = height(Nodo->leftSon);
         int r_height = height(Nodo->rightSon);
         int b_factor = l_height - r_height;
         return b_factor;
      }

      avl* rr_rotat(avl *parent) {
         avl *Nodo;
         Nodo = parent->rightSon;
         parent->rightSon = Nodo->leftSon;
         Nodo->leftSon = parent;
         return Nodo;
      }

      avl* ll_rotat(avl *parent) {
         avl *Nodo;
         Nodo = parent->leftSon;
         parent->leftSon = Nodo->rightSon;
         Nodo->rightSon = parent;
         return Nodo;
      }

      avl* lr_rotat(avl *parent) {
         avl *Nodo;
         Nodo = parent->leftSon;
         parent->leftSon = rr_rotat(Nodo);
         return ll_rotat(parent);
      }

      avl* rl_rotat(avl *parent) {
         avl *Nodo;
         Nodo = parent->rightSon;
         parent->rightSon = ll_rotat(Nodo);
         return rr_rotat(parent);
      }

      avl* balance(avl *Nodo) {
         int bal_factor = difference(Nodo);
         if (bal_factor > 1) {
            if (difference(Nodo->leftSon) > 0)
               Nodo = ll_rotat(Nodo);
            else
               Nodo = lr_rotat(Nodo);
         } else if (bal_factor < -1) {
            if (difference(Nodo->rightSon) > 0)
               Nodo = rl_rotat(Nodo);
            else
               Nodo = rr_rotat(Nodo);
         }
         return Nodo;
      }

      avl* insert(avl *pRoot, Dios pDeus) {
         if ( pRoot== NULL) {
            pRoot = (avl*)calloc(1, sizeof(avl));
            pRoot->value = pDeus;
            pRoot->leftSon = NULL;
            pRoot->rightSon = NULL;
            return pRoot;
         } else if (pDeus.getFieles() < pRoot->value.getFieles()) {
            pRoot->leftSon = insert(pRoot->leftSon, pDeus);
            pRoot = balance(pRoot);
         } else if (pDeus.getFieles() >= pRoot->value.getFieles()) {
            pRoot->rightSon = insert(pRoot->rightSon, pDeus);
            pRoot = balance(pRoot);
         } return pRoot;
      }

      avl* deleteNode(avl* pFather, avl* pRoot, Dios pDeus){

         if(pRoot == nullptr){
            return pRoot;
         }

         int fieles = pDeus.getFieles();

         if (fieles < pRoot->value.getFieles()){ //fieles menor al busacado (va hacia la derecha)
            cout<<"RIGTH SON"<<endl;
            cout<<fieles<<" "<<pRoot->value.getFieles()<<endl;
            return deleteNode(pRoot, pRoot->leftSon, pDeus);


         }

         else if (fieles > pRoot->value.getFieles()){//fieles menor al busacado (va hacia la izquierda)
            cout<<"LEFT SON"<<endl;
            cout<<fieles<<" "<<pRoot->value.getFieles()<<endl;
            return deleteNode(pRoot, pRoot->rightSon, pDeus);
            
         }

         else{ //fieles igual a la cantidad buscada
         cout<<"IGUALES"<<endl;
         cout<<fieles<<" "<<pRoot->value.getFieles()<<endl;
            if (pRoot->rightSon==nullptr){ //no hay nada al lado derecho
               cout<<"NADA DERECHO"<<endl;

               pFather->leftSon = nullptr;

               return pRoot;
            }
            else{ //hay algo mayor que este
               cout<<"HAY ALGO AL LADO DERECHO"<<endl;

               pFather->leftSon = pRoot->rightSon;

               return pRoot;
               
            }

         }

      }

      void show(avl *Nodo, int pHeightTree) {
         int contador;
         if (Nodo != NULL) {
            show(Nodo->rightSon, pHeightTree+ 1);
            cout<<" ";
            if (Nodo == root)
               cout << "Root -> ";
            for (contador = 0; contador < pHeightTree&& Nodo != root; contador++)
               cout << " ";
               cout << Nodo->value.getFieles();
               show(Nodo->leftSon, pHeightTree + 1);
         }
      }

   void postorder(avl *Nodo) {
      if (Nodo == NULL)
            return;
            postorder(Nodo ->leftSon);
            postorder(Nodo ->rightSon);
            cout << Nodo->value.getFieles() << " ";
      }

      avl_tree() {
         root = NULL;
      }
};

int main() {
   
   avl_tree arbolAVL;

   Cola colaDioses;

   priority_queue<Dios, vector<Dios>, CompareAge> colaPrioridad= colaDioses.getColaDioses();
   priority_queue<Dios, vector<Dios>, CompareAge> *ptrCola;

   ptrCola = &colaPrioridad;

   while(!ptrCola->empty()){
      root = arbolAVL.insert(root, ptrCola->top());
      ptrCola->pop();
   }
   
   //Dios Asclepio = Dios("Asclepio", 120);
   Dios Thor = Dios("Thor",100);

   arbolAVL.postorder(root);

   cout<<endl;

   avl* hola = arbolAVL.deleteNode(nullptr,root,Thor);

   arbolAVL.postorder(root);
   cout<<hola->value.getFieles()<<endl;
   cout<<hola->leftSon->value.getFieles()<<endl;

   return 0;
}