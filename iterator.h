#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include "composite.h"
#include <stack>
// #include "base.h"

class Base;

class Iterator {
    protected:
        Base* self_ptr;
        Base* current_ptr;
    public:
        Iterator(Base* ptr) { this->self_ptr = ptr; current_ptr = NULL; }

        /* Sets up the iterator to start at the beginning of traversal */
        virtual void first() = 0;
        
        /* Move onto the next element */
        virtual void next() = 0;

        /* Returns if you have finished iterating through all elements */
        virtual bool is_done() = 0;

        /* Return the element the iterator is currently at */
        virtual Base* current() = 0;
};

class OperatorIterator : public Iterator {
    public:
        OperatorIterator(Base* ptr): Iterator(ptr){ 
            current_ptr = self_ptr;
        };

        void first(){
            current_ptr = self_ptr->get_left();
        }
        void next(){
            // std::cout << "here!!!!!!\n";
            // if(current_ptr == self_ptr->get_left()){
            //     current_ptr = self_ptr;
            // }
            // else if(current_ptr == self_ptr){
            //     current_ptr = current_ptr->get_right();
            // }
            // else{
            //     current_ptr = NULL;
            // }
            // return;

            if(current_ptr == self_ptr){
                // std::cout<<"equal"<<endl;
                 first();
                 
                //  std::cout << "the new ling \n";
                //  current_ptr->print();
                //  std::cout << "the end line\n";
                 
            }
            else if(current_ptr == self_ptr->get_left()){
                // std::cout<<"left"<<endl;
                 current_ptr = self_ptr->get_right();
             }
             else{

                 current_ptr = NULL;
             }
            
        }
        bool is_done(){
            if(current_ptr == NULL){
                return true;
            }
            else{
                return false;
            }
        }
        Base* current(){
            return current_ptr;
        }
};

class UnaryIterator : public Iterator {
    public:
        UnaryIterator(Base* ptr): Iterator(ptr){
            current_ptr = self_ptr;
        }

        void first(){
            current_ptr = self_ptr->get_left();
        }
        void next(){
            // std::cout << "abc\n";
            if(current_ptr == self_ptr){
                first();
            }
            else{
                current_ptr = NULL;
            }
            // current_ptr = NULL;
        }
        bool is_done(){
            if(current_ptr == NULL){
                return true;
            }
            else{
                return false;
            }
        }
        Base* current(){
            return current_ptr;
        }
};

class NullIterator : public Iterator {
    public:
        NullIterator(Base* ptr): Iterator(ptr){
            // current_ptr = self_ptr;
        }

        void first(){
            
        }
        void next(){}
        bool is_done(){
            return true;
        }
        Base* current(){
            // return current_ptr;
            return NULL;
        }
};

class PreorderIterator : public Iterator {
    protected:
        stack<Iterator*> iterators;
    public:
        PreorderIterator(Base* ptr): Iterator(ptr){}

        void first();
        void next();
        bool is_done();
        Base* current();
};

#endif //__ITERATOR_H__
