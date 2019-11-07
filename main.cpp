#include <stdio.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <thread>
#include <mutex>

//Car Structure
class Car {
    private:
        int _id;
        std::string _direction;
    
    public: 
        Car(int, std::string);
        ~Car();
        void print();
};

// Member Functions
Car::Car(int id, std::string direction) {
    this->_id = id;
    this->_direction = direction;
}

void Car::print() {
    printf("ID: %i\n", this->_id);
    printf("Direction: %s\n", this->_direction.c_str());
}

int main() {
    std::ifstream file("inputs/simple.txt");
    std::string line;
    std::vector<Car*> cars;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            int decimal = 1;

            int id = 0;
            std::string direction = "";
            for (int i = line.size() - 1; i >= 0; --i) {
                if (isdigit(line[i])) {
                    id += (line[i] - '0') * decimal;
                    decimal *= 10;
                }
                else if (isalpha(line[i])) {
                    direction.push_back(line[i]);
                }
            }
            cars.push_back(new Car(id, direction));
        }
    }

    for (int i = 0; i < cars.size(); ++i) {
        cars[i]->print();
    }

    return 0;
}

