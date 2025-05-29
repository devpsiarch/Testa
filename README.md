# Testa
This is a small code for my own personal use , one header file to include and use any where i want.
# How to use
Copy and past the the header file ```testa.h``` into your repo dir and create a test file then compile and run it.
```C++ 
#include "testa.h"

int main(void){
    InitTesta();
        ASSERRT_EQ(19,18,"rome is cool , but not this cool");
        ASSERRT_EQ(std::string("plaza"),std::string("plaza"),"remember how to make stuff");
        ASSERRT_EQ(std::string("change"),std::string("never"),"this too shall pass");
    EndTesta();
    return 0;
}
```
# Future of this ?
I'd really what to make this better and compatible with many languages, for now it does what i want it to do.
