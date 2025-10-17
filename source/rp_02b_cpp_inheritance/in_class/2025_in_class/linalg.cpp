#include "linalg.h"
#include <iostream>
int main(){

    Rotation2f rot;
    std::cout<<rot; // prints Hello World
    Rotation2f rot2(3.14);
        std::cout << "rotation empty constructor should be identity:"<<rot2<<std::endl; // prints Hello World



return 0;
}