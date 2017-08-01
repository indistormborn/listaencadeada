#pragma once
#ifndef INCLUDED_MyList_H
#define INCLUDED_MyList_H

class Element;

class MyList
{
private:
   Element* last;
   Element* first;
   
   int size;

   void addEnd(int v);
   void addBegin(int v);
public:
   ~MyList() { clear(); }
   MyList();

   
   void add(int v) { addEnd(v); }
   void add(int v, int pos);
   void del(int pos);
   void delInicio();
   void delFim();
   
   void set(int v, int pos);
   void get(int pos);

   void bubblesort();
   void clear();
   void concatenar(MyList*);

   void printForward();
   void printBackward(); 

   int getSize() { return size; }

   Element* searchForward(int pos);
   Element* searchBackward(int pos);
   Element* getPrimeiro() { return first; }
   Element* getUltimo() { return last; }
   Element* binarySearchByPos(int pos);
};

#endif //INCLUDED_MyList_H