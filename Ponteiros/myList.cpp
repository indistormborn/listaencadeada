#include "mylist.h"
#include "element.h"
#include <iostream>
//#include <exception>
//#include <string>

using namespace std;

MyList::MyList()
{
   first= nullptr;
   last= nullptr;
   size= 0;
}

void MyList::addEnd(int v)
{
   Element* e= new Element(v);

   if (last) {
      e->setPrevious(last);
	   last->setNext(e);
	}
   else
	   first= e;

   last= e;
   size++;
}

void MyList::addBegin(int v)
{
   Element* e= new Element(v);

   if (first) {
      e->setNext(first);
	   first->setPrevious(e);
	}
   else
	   last= e;

   first= e;
   size++;
}


void MyList::add(int v, int pos)
{
   Element *daPosicao= first;
	Element *newElement= new Element(v);
 
   if (pos > 1) {
      daPosicao= search(pos);
      if (daPosicao) {
         Element *auxPrevious= daPosicao->getPrevious();

         newElement->setPrevious(auxPrevious);
         newElement->setNext(daPosicao);

         daPosicao->setPrevious(newElement);

         if (!auxPrevious) 
            first= newElement;
         else
            auxPrevious->setNext(newElement);
   
         size++;
      }
      else
         addEnd(v);
   }
   else
      addBegin(v);
}

void MyList::del(int pos)
{
   Element *e= search(pos);

   if (e) {
      Element* next= e->getNext();
      Element* prev= e->getPrevious();
      
      if (next != nullptr)
         next->setPrevious(prev);
      else
         last= prev;    

      if(prev != nullptr)
         prev->setNext(next);
      else
         first= next;      

      size--;
      delete e;
   }
   else {
      cout <<"AVISO: impossivel deletar, posicao informada nao existe na MyList"<<endl;
      exit(0);
   }
}

void MyList::set(int v, int pos)
{
   Element *e= search(pos);
   
   if(e != nullptr)
      e->setValue(v);
   else
      cout << "Posicao a ser atualizada nao existe na MyList" << endl;
}

void MyList::get(int pos)
{
   Element *e= search(pos);
   
   if(e != nullptr)
      cout << "Valor da pos " << pos << " eh: " << e->getValue() << endl;
   else
      cout << "Posicao a ser consultada nao existe na MyList" << endl;
}

void MyList::clear()
{
   Element *aux;

   while (first) {
      aux= first->getNext();
      delete first;
      first= aux;      
   }

   size= 0;
   first= last= nullptr;
}

void MyList::printForward()
{
   Element *e= first;

   cout << "{ ";   

   if(e != nullptr) {
      for (int i= 0; i < size; i++){
         cout<< e->getValue() << ", ";
         if(e->getNext() == nullptr)
            break;  
       e= e->getNext();
      }   
   }
   
   cout << "}" << endl; 
}

void MyList::printBackward()
{
   Element *e= last;

   cout << "{ ";   
   if(e != nullptr) {
      for (int i= size; i > 0; i--){
         cout<< e->getValue() << ", ";
         if(e->getPrevious() == nullptr)
            break;  
         e= e->getPrevious();
      }   
   }
   cout << "}" << endl; 
}



void MyList::bubblesort()
{
   Element* actual;
   int countLaco1= size;

   while (countLaco1 > 0) {
      int countLaco2= countLaco1 - 1;
      actual= first;
      while (countLaco2 > 0) {
         Element* auxNext= actual->getNext();
         if (actual->getValue() > auxNext->getValue()) {
            int temp= actual->getValue();
            actual->setValue(auxNext->getValue());
            auxNext->setValue(temp);
         }
         actual= auxNext;
         countLaco2--;
      }
      countLaco1--;
   }
}

Element * MyList::searchForward(int pos)
{
   Element *e= first;

   if ((pos <= size) || (pos != 0)) {
      for (int i= 1; i < pos; i++){
         if(e->getNext() == nullptr)
            break;
         e= e->getNext();
      }
   }
   else
      e= nullptr;   
  
   return e;
}

Element * MyList::searchBackward(int pos)
{
   Element *e= last;

   if(pos <= size || pos != 0){
      for (int i= size; i > pos; i--){
         if(e->getPrevious() == nullptr)
            break;
         e= e->getPrevious();
      }   
   }else
      e= nullptr;
   
   return e;
}

Element * MyList::search(int pos)
{
   Element *e;
   int meio= size/2;

   if (pos >= meio)
      e= searchBackward(pos);
   else if (pos <= meio)
      e= searchForward(pos);
   
   cout << "The element at position " << pos << " is " << e->getValue() << endl;
   return e;
}

void MyList::concatenate(MyList* l){
  Element *e= l->getFirst();

   if( l != nullptr ){
      if( (first != nullptr) && (l->getFirst() != nullptr) ){
         last->setNext(l->getFirst());
         last= l->getLast();
         }
      l->clear();
   }   
}

