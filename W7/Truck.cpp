#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Truck.h"

using namespace std;
namespace sdds {

    Truck::Truck(const char* plateNumber, int vehicleYear, double truckCapacity, const char* truckAddress)
        {
        MotorVehicle::MotorVehicle(plateNumber, vehicleYear); // Call the base class constructor
        capacity = truckCapacity;
        currentLoad = 0.0;
        moveTo(truckAddress);
    }

    bool Truck::addCargo(double cargo)
    {
        double weight = currentLoad + cargo;
        if (weight <= capacity)
        {
            currentLoad += cargo;
            return true;
        }
        return false;
    }

    bool Truck::unloadCargo()
    {
        if (currentLoad > 0) {
            currentLoad = 0.0;
            return true;
        }
        return false;
    }

    std::ostream& Truck::write(std::ostream& os)
    {
        MotorVehicle::write(os); // Call the base class write function
        os << " | " << currentLoad << "/" << capacity;
        return os;
    }

    std::istream& Truck::read(std::istream& in)
    {
        MotorVehicle::read(in); // Call the base class read function
        
        cout << "Capacity: ";
        in >> capacity;

        while (!in || capacity < 0.0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invaild input, enter another capacity: ";
            cin >> capacity;
        }

        cout << "Cargo: ";
        in >> currentLoad;
        while (!in) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invaild input, enter another cargo weight: ";
            cin >> currentLoad;
        }

        return in;

    }




}