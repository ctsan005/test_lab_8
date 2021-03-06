#ifndef __COMPOSITE_CLASS__
#define __COMPOSITE_CLASS__

#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include "visitor.h"




using namespace std;

class Iterator;
class NullIterator;
class UnaryIterator;
class PreorderIterator;
class Visitor;
class PrintVisitor;
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

#include "iterator.h"


//Leaf Class
class Op: public Base {
    private:
        double value;

    public:
        Op();
        Op(double val);

        Base* get_left();
        Base* get_right();
        double evaluate(); 
        void print();
        Iterator* create_iterator();
        void Accept(Visitor* v);
};

//Composite Base Classes
class Operator: public Base {
    protected:
        Base* left, *right;
    public:
        Operator();
        Operator(Base* l, Base* r);

        Base* get_left();
        Base* get_right();
        virtual double evaluate() = 0;	//Note: this is implicit in the inheritance, but can also be made explicit
        Iterator* create_iterator();
        // void Accept(Visitor* v);
};

class UnaryOperator: public Base {
    protected:
        Base* child;
    public:
        UnaryOperator();
        UnaryOperator(Base* c);

        Base* get_left();
        Base* get_right();
        virtual double evaluate() = 0;	//Note: this is implicit in the inheritance, but can also be made explicit
        Iterator* create_iterator();
        // void Accept(Visitor* v);
};

//Composite Classes
class Add: public Operator {
    public:
        Add();
        Add(Base* left, Base* right);

        void print();
        double evaluate();
        void Accept(Visitor* v);
        
};

class Sub: public Operator {
    public:
        Sub();
        Sub(Base* left, Base* right);

        void print();
        double evaluate();
        void Accept(Visitor* v);
};

class Mult: public Operator {
    public:
        Mult();
        Mult(Base* left, Base* right);

        void print();
        double evaluate();
        void Accept(Visitor* v);
};

class Sqr: public UnaryOperator {
    public:
        Sqr();
        Sqr(Base* child);

        void print();
        double evaluate();
        void Accept(Visitor* v);
};

class Root: public UnaryOperator {
    public:
        Root();
        Root(Base* root);

        void print();
        double evaluate();
        void Accept(Visitor* v);
};

#endif //__COMPOSITE_CLASS__
