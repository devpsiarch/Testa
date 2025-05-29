#include "testa.h"

int main(void){
    // int passed, failed;
    // this is a hallucination of the API 
    // assert_eq(func(...),expected); info should be ([TESTING]: (class) -> (STATUS):(expected))
    // assert_eq(func(...),expected);
    // assert_eq(func(...),expected); 
    // assert_ne(func(...),expected); 
    // assert_true(func(...),expected); 
    // assess_results(); <-- passed and failed and time
    InitTesta();
        ASSERRT_EQ(19,18,"rome is cool , but not this cool");
        ASSERRT_EQ(std::string("plaza"),std::string("plaza"),"remember how to make stuff");
        ASSERRT_EQ(std::string("change"),std::string("never"),"this too shall pass");
    EndTesta();
    return 0;
}
