#include "StdAfx.h"
#include "Gerenciador.h"
#include "element.h"
#include "MyList.h"
#include "UI.h"
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////
Gerenciador::Gerenciador()
{
   userInterface= new UI();
   MyList1= new MyList();
   MyList2= new MyList();
   atual= new MyList();
}

///////////////////////////////////////////////////////////////////////////////////

void Gerenciador::criaListas(char c)
{
   char entrada= c; 
   while(true){
      if (entrada == 's'){
         for(int i= 0; i < 10; i++){
            int x= rand() % 15;
            MyList1->add(x);
         }
         for(int i= 0; i < 10; i++){
            int x= rand() % 15;
            MyList2->add(x);
         }
         break;
      }
      else if (entrada == 'n'){
         exit(0);
      }
      else{
         cout << "Opcao inválida!  ";
         entrada= userInterface->insertOption();
      }
   }
}

///////////////////////////////////////////////////////////////////////////////////

void Gerenciador::executarComandoMenuPrincipal(char c)
{
   char entrada= c;

   while(true){
      if (entrada == '1'){
         userInterface->clearScreen();
         userInterface->optionMenu();
         this->atual= MyList1;
         break;
      }
      else if (entrada == '2'){
         userInterface->clearScreen();
         userInterface->optionMenu();
         this->atual= MyList2;
         break;
      }
      else if( (entrada == 'X') || (entrada == 'x') ){
         exit(0);
      }
      else{
         cout << "Opcao inválida!  ";
         entrada= userInterface->insertOption();
      }
   }
}

void Gerenciador::executarComando(char c){
   bool cond= true;
   char entrada= c;

   while(cond){
      int value= 0;
      int pos= 0;   

      switch(entrada){
         
         case '0':
            cout<<"Insira valor e posicao: ";
            cin>> value >> pos;
            atual->add(value,pos);
            cout<<endl;
            cout << "Valor " << value << " adicionado a posicao " << pos << "   ";
            atual->printForward();
            system("pause");
            userInterface->clearScreen();
            userInterface->optionMenu();
            entrada= userInterface->insertOption();
            break;
         
         case '1':
            cout<<"Insira valor: ";
            cin>> value;
            atual->add(value);
            cout<<endl;
            cout << "Valor " << value << " adicionado ao fim da MyList" << "   ";
            atual->printForward();
            system("pause");
            userInterface->clearScreen();
            userInterface->optionMenu();
            entrada= userInterface->insertOption();
            break;

         case '2':
            cout<<"Insira a posicao: ";
            cin>>pos;
            atual->del(pos);
            cout<<endl;
            cout << "Posicao " << pos << " removida  ";
            atual->printForward(); 
            system("pause");
            userInterface->clearScreen();
            userInterface->optionMenu();
            entrada= userInterface->insertOption();
            break;

         case '3':
            atual->del(1);
            cout<<endl;
            cout << "Inicio da MyList excluido!  ";
            atual->printForward();
            system("pause");
            userInterface->clearScreen();
            userInterface->optionMenu();
            entrada= userInterface->insertOption();

            break;

         case '4':
            atual->del(atual->getSize());
            cout<<endl;
            cout << "Fim da MyList excluido!  ";
            atual->printForward();
            system("pause");
            userInterface->clearScreen();
            userInterface->optionMenu();
            entrada= userInterface->insertOption();

            break;

         case '5':
            cout << "Sentido inicio-fim   ";
            cout<<endl;
            atual->printForward();
            system("pause");
            userInterface->clearScreen();
            userInterface->optionMenu();
            entrada= userInterface->insertOption();
            break;

         case '6':
            cout << "Sentido fim-inicio   ";
            cout<<endl;
            atual->printBackward();
            system("pause");
            userInterface->clearScreen();
            userInterface->optionMenu();
            entrada= userInterface->insertOption();
            break;

         case '7':
            atual->clear();
            cout<<endl;
            cout<< "Lista esvaziada!" <<endl;
            system("pause");
            userInterface->clearScreen();
            userInterface->optionMenu();
            entrada= userInterface->insertOption();
            break;

         case '8':
            atual->bubblesort();
            cout << "Lista ordenada!"<<endl;
            atual->printForward();
            cout<<endl;
            system("pause");
            userInterface->clearScreen();
            userInterface->optionMenu();
            entrada= userInterface->insertOption();
            break;

         case '9':
            if(atual == MyList1)
               atual->concatenate(MyList2);
            else if(atual == MyList2)
               atual->concatenate(MyList1);
            cout<<endl;
            cout<<"Lista concatenada!"<<endl; 
            system("pause");
            userInterface->clearScreen();
            userInterface->optionMenu();
            entrada= userInterface->insertOption();
            break;

         case 'X':
            userInterface->clearScreen();
            cond= false;
            break;
         
         default:
            cout<< "Opcao inválida! Insira outra: ";
            system("pause");
            userInterface->clearScreen();
            userInterface->optionMenu();
            entrada= userInterface->insertOption();
         }
   }

}

void Gerenciador::execucaoSistema(){
  
      userInterface->welcome();
      char c1= userInterface->insertOption();
      criaListas(c1);

      userInterface->clearScreen();
      userInterface->print(MyList1, MyList2);
      cout<<endl;

      bool cond= true;
      
      while(cond){
         userInterface->mainMenu();
         char option= userInterface->insertOption();
         executarComandoMenuPrincipal(option);
         option= userInterface->insertOption();
         executarComando(option);
      }
      
   
}

///////////////////////////////////////////////////////////////////////////////////
void Gerenciador::verificaMemoria(){
   _CrtMemCheckpoint( &s1 );
   _CrtMemDumpStatistics( &s1 );
}


void Gerenciador::deleteAplicacao(){
   delete userInterface;
   verificaMemoria();

   MyList1->clear();
   delete MyList1->getFirst();
   delete MyList1->getLast();
   delete MyList1;
   verificaMemoria();
   MyList2->clear();
   delete MyList2->getFirst();
   delete MyList2->getLast();
   delete MyList2;
   verificaMemoria();
   delete this;
}

