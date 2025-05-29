#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <assert.h>

#define GREEN  "\033[32m"
#define RED    "\033[31m"
#define RESET  "\033[0m"
#define BLUE   "\033[34m"
#define YELLOW "\033[33m" 
#define LENGTH 60

static bool testing_status = false;
static int tests_ran = 0;
static int tests_passed = 0;

namespace tester {
enum State {
    PASSED = 1,
    FAILED = 0
};

void output_result(State state,const std::string&msg){
    std::ostringstream msgstream;
    std::string color = (state == tester::PASSED) ? GREEN : RED;
    std::string code = (state == tester::PASSED) ? "PASSED" : "FAILED";
    msgstream << "- [TESTING]: ";
    if(msg.length() < LENGTH){
        msgstream << msg;
    }else{
        msgstream << msg.substr(0,LENGTH-15) << "...";
    }
    std::cout << std::left << std::setw(LENGTH) << msgstream.str() << 
              color << "[" << code << "]" << RESET;
    std::cout << ( (state == tester::PASSED) ? '\n' : ' ' );
}
template <typename T> void output_failed(T exprf,const std::string&msg){
    tester::output_result(State::FAILED,msg);
    std::cout << std::right << YELLOW << " * [GOTTEN]: " << exprf << RESET <<std::endl;
}
void output_passed(const std::string&msg){
    tests_passed++;
    output_result(State::PASSED,msg);
}
};

#define ASSERRT_EQ(expr1,expr2,msg) assert(testing_status);\
                                    tests_ran++;\
                                    if((expr1) != (expr2)) tester::output_failed((expr2),(msg));\
                                    else tester::output_passed((msg));\

void InitTesta(void){
    std::cout << "TESTA RUNNING ...\n";
    tests_ran = 0;
    tests_passed = 0;
    testing_status = true;
}
void EndTesta(void){
    std::cout << "TESTA COMPLETED ...\n";
    testing_status = false;
    std::cout << "Tests ran : "  <<  tests_ran << '\n';
    std::cout << GREEN << "Passed : "  <<  tests_passed << RESET << '\n';
    std::cout << RED << "Failed : "  <<  tests_ran-tests_passed << RESET << '\n';
}
