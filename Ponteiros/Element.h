#pragma once
#ifndef INCLUDED_ELEMENT_H
#define INCLUDED_ELEMENT_H

class Element
{
private: 
   int value;
   Element* next;
   Element* previous;
   
public:
   ~Element() {}
   Element(int _value= 0) {
      value= _value;
      next= nullptr;
      previous= nullptr;
   }

   void setValue(int v) { value= v; }
   void setNext(Element* e) { next= e; }
   void setPrevious(Element* e) { previous= e; }

   int getValue() { return value; }

   Element* getNext() { return next; }
   Element* getPrevious() { return previous; }  
};

#endif //INCLUDED_ELEMENT_H