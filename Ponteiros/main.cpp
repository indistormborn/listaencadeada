//main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Gerenciador.h"
#include <stdlib.h> 
#include <crtdbg.h>

_CrtMemState s1;

int main(int argc, _TCHAR* argv[])
{  
   _CrtMemCheckpoint( &s1 );
   _CrtMemDumpStatistics( &s1 ); 
   
   Gerenciador *gerente= new Gerenciador();
   gerente->execucaoSistema();
   
   _CrtMemCheckpoint( &s1 );
   _CrtMemDumpStatistics( &s1 );
   
   gerente->deleteAplicacao();
   
   _CrtMemCheckpoint( &s1 );
   _CrtMemDumpStatistics( &s1 );
     
   
	return 0;
}

