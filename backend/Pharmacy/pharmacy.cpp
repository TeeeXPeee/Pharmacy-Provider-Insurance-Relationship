#include <iostream>

void printMenu()
{
    std::cout << R"( 
    Triage : Take in new incoming prescriptions
    Patient : Look up and access pre-existing patients
)" << std::endl;
}

int main(int argc, char *argv[])
{
std::string userInput;
while(true)
{
    printMenu();
    std::cin >> userInput;

    std::cout << 'cls\n' << userInput;

}


};