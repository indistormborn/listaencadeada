#pragma once
#ifndef INCLUDED_UI_H
#define INCLUDED_UI_H
#include <iostream>

class MyList;
class Element;


class UI
{
public:
   UI(){}
   ~UI(){}

   void bemVindo();

   void printarLista(MyList * l1, MyList * l2);
  
   void menuPrincipal();
   void menuOpcoes();
  
   void limparTela() { system("cls"); }

   char inserirOpcao();
};

#endif //INCLUDED_UI_H