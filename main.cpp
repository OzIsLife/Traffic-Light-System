//
//  main.cpp
//  Traffic Light System
//
//  Created by Khai on 11/8/19.
//  Copyright © 2019 Khai. All rights reserved.
//
#include <thread>
#include <mutex>
#include <fstream>
#include <iostream>
#include <queue>
#include <ctype.h>
#include <string>

// Car Objects
class Car {
    public:
        Car(int, std::string);
        ~Car();
        void print();
    
    private:
        int _id;
        std::string _direction;
};

Car::Car(int id, std::string direction) {
    this->_id = id;
    this->_direction = direction;
}

void Car::print() {
    std::cout << "ID: " << this->_id << std::endl;
    std::cout << "Direction: " << this->_direction << std::endl;
}


// Road Objects
class Road {
    public:
        Road();
        void push(Car*);
        void pop();
        
    private:
        std::queue<Car*> _road;
};

Road::Road() {
    
}

void Road::push(Car* newCar) {
    this->_road.push(newCar);
}

void Road::pop() {
    
}

Road* north = new Road();

int main() {
    std::ifstream file("inputs/simple.txt");
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            int decimal = 1;

            int arrive = 0;
            std::string direction = "";
            for (int i = (int)line.size() - 1; i >= 0; --i) {
                if (isdigit(line[i])) {
                    arrive += (line[i] - '0') * decimal;
                    decimal *= 10;
                }
                else if (isalpha(line[i])) {
                    direction = (std::string() + line[i]) + direction;
                }
            }
            
            switch (line[0]) {
                case 'N': //Going through North
                    //south->push();
                    break;
                
                case 'S':
                    //north->push();
                    break;
                    
                case 'W':
                    //east->push();
                    break;
                    
                case 'E':
                    //west->push();
                    break;
            }
        }
    }
    
   
    std::thread threadOne(&Road::pop, north);
    threadOne.join();
    

    return 0;
}

