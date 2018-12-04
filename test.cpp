#include "composite.h"
#include "iterator.h"
#include "gtest/gtest.h"


TEST(basicTest, test1) {
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);
    Base* num8 = new Op(8);
    Base* num9 = new Op(9);
    
    Add* add = new Add(num9,num8);
    Sub* sub = new Sub(add, num1);
    Mult* mult = new Mult(sub, num2);
    Sqr* sqr = new Sqr(mult);
    

    
    
    


    
    Iterator* t = new PreorderIterator(sqr);

    
    Visitor* curr = new PrintVisitor();

    for(t->first(); !t->is_done(); t->next()){
        
        t->current()->Accept(curr);
    }
    testing::internal::CaptureStdout();
    curr->execute();
    std::string output = testing::internal::GetCapturedStdout();
    
    
    
    EXPECT_EQ(" ^2  *  -  +  9   8   1   2  \n", output );
    
}

TEST(basicTest, test2) {
    Base* num1 = new Op(1);
    Base* num2 = new Op(2);

    Base* num8 = new Op(8);
    Base* num9 = new Op(9);
    
    Add* add = new Add(num9,num8);
    Mult* mult = new Mult(add, num2);
    Sub* sub = new Sub(mult, num1);
    


    
    Iterator* t = new PreorderIterator(sub);

    


    Visitor* curr = new PrintVisitor();
            
    for(t->first(); !t->is_done(); t->next()){

        
        t->current()->Accept(curr);
    }

    testing::internal::CaptureStdout();
    curr->execute();
    std::string output = testing::internal::GetCapturedStdout();
    
    
    
    EXPECT_EQ(" -  *  +  9   8   2   1  \n", output );
    
}


int main(int argc, char **argv) {
	  ::testing::InitGoogleTest(&argc, argv);
	    return RUN_ALL_TESTS();
}
