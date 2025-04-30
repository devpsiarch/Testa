#include <iostream>
#include <string>
#include <iomanip>

#define GREEN  "\033[32m"
#define RED    "\033[31m"
#define RESET  "\033[0m"
#define BLUE   "\033[34m"
#define YELLOW "\033[33m" 
#define LENGTH 60

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
    output_result(State::PASSED,msg);
}
};

#define ASSERRT_EQ(expr1,expr2,msg) if((expr1) != (expr2)) tester::output_failed((expr2),(msg));\
                                    else tester::output_passed((msg));\

// experimental ideas
struct Resume {};
template <typename T> class test {
private:
    // cross language ???
    std::string reason;
    std::string info_about_error;
    T expected, found;
    Resume states_about_test_run;
    // ptr to a bunch of tester functions ?
public:
    // some printers and checkers 
    void test_all();
    void get_resume_all();
};

int main(void){
    // int passed, failed;
    // assert_eq(func(...),expected); info should be ([TESTING]: (class) -> (STATUS):(expected))
    // assert_eq(func(...),expected);
    // assert_eq(func(...),expected); 
    // assert_ne(func(...),expected); 
    // assert_true(func(...),expected); 
    // assess_results(); <-- passed and failed and time
    ASSERRT_EQ(19,18,"rome is cool , but not this cool");
    ASSERRT_EQ(std::string("plaza"),std::string("plaza"),"remember how to make stuff");
    ASSERRT_EQ(std::string("change"),std::string("never"),"this too shall pass");
    return 0;
}
