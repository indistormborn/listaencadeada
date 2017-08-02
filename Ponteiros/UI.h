#pragma once
#ifndef INCLUDED_UI_H
#define INCLUDED_UI_H
#include <iostream>

class MyList;
class Element;


class UI
{
public:
   ~UI(){}
   UI(){}

   void welcome();

   void print(MyList * l1, MyList * l2);
  
   void mainMenu();
   void optionMenu();
  
   void clearScreen() { system("cls"); }

   char insertOption();
};

#endif //INCLUDED_UI_H