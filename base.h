#ifndef BASE_H
#define BASE_H
#include "iterator.h"
class Iterator;
class Base {
    public:
        Base(){};

        //virtual
        virtual void print() = 0;
        virtual double evaluate() = 0;
        virtual Iterator* create_iterator() = 0;
        virtual Base* get_left() = 0;
        virtual Base* get_right() = 0;
        virtual void Accept(Visitor* v) = 0;
};
#endif