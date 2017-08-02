#include "StdAfx.h"
#include "UI.h"
#include "myList.h"


using namespace std;

void UI::welcome()
{
   cout << "------------------- BEM-VINDO -------------------" << endl;
   cout << "Deseja gerar as MyLists? [s/n]" << endl;
   cout<<endl;
  

}

void UI::print(MyList * l1, MyList * l2)
{  
   cout<<"Primeira MyList: ";
   l1->printForward();
   cout<<"-----------------"<<endl;
   cout<<"Segunda MyList: ";
   l2->printForward();
  
}

void UI::mainMenu()
{
   cout << "--------------- MENU PRINCIPAL ---------------"<<endl;
   cout << "|                                            |"<<endl;
   cout << "| 1- Configurar Primeira Lista               |"<<endl;
   cout << "| 2- Configurar Segunda Lista                |"<<endl;
   cout << "| X- Fechar aplicacao                        |"<< endl;
   cout << "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |"<<endl;
   
}

void UI::optionMenu()
{
   cout << "------------------- Opcoes de manipulacao -------------------" <<endl;
   cout << "0- Adicionar na posicao" <<endl;
   cout << "1- Adicionar no fim"<<endl;
   cout << "-----------------" <<endl;
   cout << "2- Deletar posicao" <<endl; 
   cout << "3- Deletar inicio da MyList"<<endl;
   cout << "4- Deletar fim da MyList"<<endl;
   cout << "-----------------" <<endl;
   cout << "5- Imprimir sentido inicio-fim"<<endl;
   cout << "6- Imprimir sentido fim-inicio"<<endl;
   cout << "-----------------" <<endl;
   cout << "7- Esvaziar MyList" <<endl;
   cout << "8- Ordenar" <<endl;
   cout << "9- Concatenar" <<endl;
   cout << "X- Voltar para o menu principal" <<endl;
   
}


char UI::insertOption()
{
   char t;
   cout<<"Entre com a opcao desejada:  ";
   cin>>t;
   cout<<endl;
   return t;
}