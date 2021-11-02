#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "dioses.h"
#include "cola.h"

using namespace std;

class avl{
   private:
      Dios value;
      avl* leftSon;
      avl* rightSon;

   public:
      alv(){
         leftSon=nullptr;
         rightSon=nullptr;
      }

      void setValue(Dios pValue){
         value = pValue;
      }

      void setLS(avl* pLeftSon){
         leftSon = pLeftSon;
      }

      void setRS(avl* pRightSon){
         rightSon = pRightSon;
      }

      Dios getValue(){
         return value;
      }

      avl* getLS(){
         return leftSon;
      }

      avl* getRS(){
         return rightSon;
      }
};
/*
struct avl {

   Dios value;
   struct avl *leftSon = nullptr;
   struct avl *rightSon = nullptr;

}*root;
*/

class avl_tree {
   public:
      avl* root;

      int height(avl *Nodo) {
         int h = 0;
         if (Nodo != NULL) {

            avl* leftSon = Nodo->getLS();
            int l_height = height(leftSon);

            avl* rightSon = Nodo->getRS();
            int r_height = height(rightSon);

            int max_height = max(l_height, r_height);
            h = max_height + 1;
         }
         return h;
      }

      int difference(avl *Nodo) {

         avl* leftSon = Nodo->getLS();
         int l_height = height(leftSon);

         avl* rightSon = Nodo->getRS();
         int r_height = height(rightSon);

         int b_factor = l_height - r_height;
         return b_factor;
      }

      avl* rr_rotat(avl *parent) {
         avl *Nodo = parent->getRS();

         parent->setRS(Nodo->getLS());

         Nodo->setLS(parent);

         return Nodo;
      }

      avl* ll_rotat(avl *parent) {
         avl *Nodo = parent->getLS();

         parent->setLS(Nodo->getRS());
         
         Nodo->setRS(parent);
         
         return Nodo;
      }

      avl* lr_rotat(avl *parent) {
         avl *Nodo = parent->getLS();

         parent->setLS(rr_rotat(Nodo));

         return ll_rotat(parent);
      }

      avl* rl_rotat(avl *parent) {
         avl *Nodo = parent->getRS();
         
         parent->setRS(ll_rotat(Nodo));

         return rr_rotat(parent);
      }

      avl* balance(avl *Nodo) {
         int bal_factor = difference(Nodo);
         if (bal_factor > 1) {
            if (difference(Nodo->getLS()) > 0)
               Nodo = ll_rotat(Nodo);
            else
               Nodo = lr_rotat(Nodo);
         } else if (bal_factor < -1) {
            if (difference(Nodo->getRS()) > 0)
               Nodo = rl_rotat(Nodo);
            else
               Nodo = rr_rotat(Nodo);
         }
         return Nodo;
      }

      avl* insert(avl *pRoot, Dios pDeus) {
         if ( pRoot== NULL) {
            pRoot = (avl*)calloc(1, sizeof(avl));
            pRoot->setValue(pDeus);
            pRoot->setLS(NULL);
            pRoot->setRS(NULL);
            return pRoot;
         } else if (pDeus.getFieles() < pRoot->getValue().getFieles()) {
            pRoot->setLS(insert(pRoot->getLS(), pDeus));
            pRoot = balance(pRoot);

         } else if (pDeus.getFieles() >= pRoot->getValue().getFieles()) {
            pRoot->setRS(insert(pRoot->getRS(), pDeus));
            pRoot = balance(pRoot);
         } return pRoot;
      }

      avl* deleteNode(avl* pFather, avl* pRoot, Dios pDeus){

         if(pRoot == nullptr){
            return pRoot;
         }

         int fieles = pDeus.getFieles();

         if (fieles < pRoot->getValue().getFieles()){ //fieles menor al busacado (va hacia la derecha)
            //cout<<"RIGTH SON"<<endl;
            //cout<<fieles<<" "<<pRoot->value.getFieles()<<endl;
            return deleteNode(pRoot, pRoot->getLS(), pDeus);


         }

         else if (fieles > pRoot->getValue().getFieles()){//fieles menor al busacado (va hacia la izquierda)
            //cout<<"LEFT SON"<<endl;
            //cout<<fieles<<" "<<pRoot->value.getFieles()<<endl;
            return deleteNode(pRoot, pRoot->getRS(), pDeus);
            
         }

         else{ //fieles igual a la cantidad buscada
         //cout<<"IGUALES"<<endl;
         //cout<<fieles<<" "<<pRoot->value.getFieles()<<endl;
            if (pRoot->getRS()==nullptr){ //no hay nada al lado derecho
               //cout<<"NADA DERECHO"<<endl;

               pFather->setLS(nullptr);

               return pRoot;
            }
            else{ //hay algo mayor que este
               //cout<<"HAY ALGO AL LADO DERECHO"<<endl;

               pFather->setLS(pRoot->getRS());

               return pRoot;
               
            }

         }

      }

      void show(avl *Nodo, int pHeightTree) {
         int contador;
         if (Nodo != NULL) {
            show(Nodo->getRS(), pHeightTree+ 1);
            cout<<" ";
            if (Nodo == root)
               cout << "Root -> ";
            for (contador = 0; contador < pHeightTree&& Nodo != root; contador++)
               cout << " ";
               cout << Nodo->getValue().getFieles();
               show(Nodo->getLS(), pHeightTree + 1);
         }
      }

      void postorder(avl *Nodo) {
         if (Nodo == NULL)
               return;
               postorder(Nodo ->getLS());
               postorder(Nodo ->getRS());
               cout << Nodo->getValue().getFieles() << " ";
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

   avl* root = nullptr;

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
   cout<<endl;
   cout<<hola->getValue().getFieles()<<endl;
   cout<<hola->getLS()->getValue().getFieles()<<endl;


   arbolAVL.balance(root);
   arbolAVL.postorder(root);
   //arbolAVL.postorder();

   return 0;
}