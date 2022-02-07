/**
 * @file main.cpp
 * @author Jugal Shah (shahjugalr@gmail.com)
 * @brief 
 * @version 0.1
 * @date 07/02/2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <array>
#include <iostream>
#include <list>

enum class Fluid{
    RED = 1,
    GREEN =  2,
    BLUE = 3
};

void Pour(std::list<Fluid>* from, std::list<Fluid>* to);

int main(){
    
    std::list<Fluid> bottle1 = {Fluid::BLUE, Fluid::BLUE, Fluid::BLUE, Fluid::RED};
    std::list<Fluid> bottle2 = {Fluid::BLUE, Fluid::BLUE, Fluid::BLUE, Fluid::GREEN};
    std::list<Fluid> bottle3 = {};
    std::list<Fluid> bottle4 = {};

    std::cout << "Bottle 1" << std::endl;

    for (auto &&i : bottle1)
    {
        std::cout << (int)i << std::endl;
    }

    std::cout << "Bottle 2" << std::endl;

    for (auto &&i : bottle2)
    {
        std::cout << (int)i << std::endl;
    }

    std::cout << "Bottle 3" << std::endl;

    for (auto &&i : bottle3)
    {
        std::cout << (int)i << std::endl;
    }

    std::cout << "Pouring from bottle 1 and 2 to 3" << std::endl;
        
    Pour(&bottle1, &bottle3);
    Pour(&bottle2, &bottle3);

    std::cout << "Bottle 1" << std::endl;

    for (auto &&i : bottle1)
    {
        std::cout << (int)i << std::endl;
    }

    std::cout << "Bottle 2" << std::endl;

    for (auto &&i : bottle2)
    {
        std::cout << (int)i << std::endl;
    }

    std::cout << "Bottle 3" << std::endl;

    for (auto &&i : bottle3)
    {
        std::cout << (int)i << std::endl;
    }

    std::cout << "Pouring from bottle 3 to 4" << std::endl;

    Pour(&bottle3, &bottle4);

    std::cout << "Bottle 3" << std::endl;

    for (auto &&i : bottle3)
    {
        std::cout << (int)i << std::endl;
    }

    std::cout << "Bottle 4" << std::endl;

    for (auto &&i : bottle4)
    {
        std::cout << (int)i << std::endl;
    }

    return 0;
}

void Pour(std::list<Fluid>* from, std::list<Fluid>* to){

    if((int)(to->size()) == 5){
        std::cout << "Can't Pour Destination's capacity is reached!" << "\n";
        return;
    }

    if (to->front() == from->front() || (int)to->front() == 0){
        Fluid t_fluid = from->front();
        from->pop_front();
        to->push_front(t_fluid);
        if(from->front() == t_fluid && (int)(to->size()) < 5)
            Pour(from, to);
    }

    else{
        std::cout << "Can't Pour Destination's top fluid is " << (int)to->front() << " And you are trying to pour" << (int)from->front() << "\n";
    }

}