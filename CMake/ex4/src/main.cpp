#include "config.h"
#include "lib.h"
#include <iostream>

int main(){
    
    std::cout << "Hello from main!" << std::endl;
    
    lib::makeSomeSuperJob();
    
    std::cout << "Lib version:" << lib::getVersion() << std::endl;
    std::cout << "Main version: " << (PROJECT_VERSION) << std::endl;

}