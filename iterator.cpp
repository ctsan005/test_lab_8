#include "iterator.h"
#include <iostream>

void PreorderIterator::first() {
    // Empty the stack (just in case we had something leftover from another run)
    // Create an iterator for the Base* that we built the iterator for
    // Initialize that iterator and push it onto the stack
    while(!iterators.empty()){
        iterators.pop();
    }
    iterators.push(self_ptr->create_iterator());
    // std::cout << iterators.size() << endl;
}

void PreorderIterator::next() {
    // Create an iterator for the item on the top of the stack
    // Initialize the iterator and push it onto the stack
    // As long as the top iterator on the stack is_done(), pop it off the stack and then advance whatever iterator is now on top of the stack
    // std::cout << "test\n";
    
    iterators.top()->next();
    while(!is_done() && iterators.top()->is_done()){
        iterators.pop();
        if(!is_done()){
            iterators.top()->next();
        }
    }
    if(!is_done()){
        // if(!iterators.top()->is_done()){
            // std::cout << "\n";
            // iterators.top()->next();
        current_ptr = iterators.top()->current();
        // std::cout << iterators.size() <<  " before" <<endl;
        iterators.push(current_ptr->create_iterator());
        if(iterators.top()->is_done()){
            iterators.pop();
        }
            // std::cout << iterators.size() << " after" << endl;
            

        // }
        // else{
        //     iterators.pop();
        // }
    }
    
    
}

bool PreorderIterator::is_done() {
    // Return true if there are no more elements on the stack to iterate
    // std::cout << "Is it empty?" << endl;
    // std::cout << iterators.size() << endl;
    if(iterators.empty()){
        return true;
    }
    return false;
}

Base* PreorderIterator::current() {
    // Return the current for the top iterator in the stack
    return iterators.top()->current();
    // return current_ptr;
}
