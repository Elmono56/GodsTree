#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "headers/dioses.h"
#include "headers/cola.h"

using namespace std;

struct avl {

   Dios value;
   struct avl *leftSon;
   struct avl *rightSon;

}*root;

class avl_tree {
   public:
      int height(avl *);
      int difference(avl *);
      avl *rr_rotat(avl *);
      avl *ll_rotat(avl *);
      avl *lr_rotat(avl*);
      avl *rl_rotat(avl *);
      avl * balance(avl *);
      avl * insert(avl*, Dios);
      void show(avl*, int);
      void postorder(avl*);
      avl_tree() {
         root = NULL;
      }
};
int avl_tree::height(avl *Nodo) {
   int h = 0;
   if (Nodo != NULL) {
      int l_height = height(Nodo->leftSon);
      int r_height = height(Nodo->rightSon);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int avl_tree::difference(avl *Nodo) {
   int l_height = height(Nodo->leftSon);
   int r_height = height(Nodo->rightSon);
   int b_factor = l_height - r_height;
   return b_factor;
}
avl *avl_tree::rr_rotat(avl *parent) {
   avl *Nodo;
   Nodo = parent->rightSon;
   parent->rightSon = Nodo->leftSon;
   Nodo->leftSon = parent;
   return Nodo;
}
avl *avl_tree::ll_rotat(avl *parent) {
   avl *Nodo;
   Nodo = parent->leftSon;
   parent->leftSon = Nodo->rightSon;
   Nodo->rightSon = parent;
   return Nodo;
}
avl *avl_tree::lr_rotat(avl *parent) {
   avl *Nodo;
   Nodo = parent->leftSon;
   parent->leftSon = rr_rotat(Nodo);
   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent) {
   avl *Nodo;
   Nodo = parent->rightSon;
   parent->rightSon = ll_rotat(Nodo);
   return rr_rotat(parent);
}
avl *avl_tree::balance(avl *Nodo) {
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
avl *avl_tree::insert(avl *pRoot, Dios pDeus) {
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
void avl_tree::show(avl *Nodo, int pHeightTree) {
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
void avl_tree::postorder(avl *Nodo) {
   if (Nodo == NULL)
      return;
      postorder(Nodo ->leftSon);
      postorder(Nodo ->rightSon);
      cout << Nodo->value.getFieles() << " ";

}
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

   arbolAVL.postorder(root);

   return 0;
}