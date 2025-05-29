#include "testa.h"

int main(void){
    InitTesta();
        ASSERRT_EQ(19,18,"rome is cool , but not this cool");
        ASSERRT_EQ(std::string("plaza"),std::string("plaza"),"remember how to make stuff");
        ASSERRT_EQ(std::string("change"),std::string("never"),"this too shall pass");
    EndTesta();
    return 0;
}
