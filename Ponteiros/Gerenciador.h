#pragma once
#ifndef INCLUDED_GERENCIADOR_H
#define INCLUDED_GERENCIADOR_H
#include <crtdbg.h>

class MyList;
class UI;
class elemento;

class Gerenciador
{

private:
   UI * userInterface; 

   MyList * MyList1;
   MyList * MyList2;
   MyList * atual;

   _CrtMemState s1;


public:
   ~Gerenciador(){}
   Gerenciador();

   void criaListas(char c);
  
   void executarComando(char c);
   void executarComandoMenuPrincipal(char c);
   void execucaoSistema();

   void deleteAplicacao();

   void verificaMemoria();
   
};

#endif //INCLUDED_GERENCIADOR_H