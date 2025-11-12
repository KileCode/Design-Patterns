// main.cpp - Client code demonstrating Abstract Factory pattern
#include <iostream>
#include <string>
#include "VehicleFactory.h"
#include "ToyotaFactory.h"
#include "BMWFactory.h"
#include "TeslaFactory.h"
#include "Sedan.h"
#include "SUV.h"
#include "Truck.h"

using namespace std;

// Helper function - Client works with abstract interfaces
void showInventory(VehicleFactory* factory) {
    cout << "\n=== DEALERSHIP INVENTORY ===" << endl;
    
    Sedan* sedan = factory->createSedan();
    SUV* suv = factory->createSUV();
    Truck* truck = factory->createTruck();
    
    cout << "Sedan: " << sedan->getDescription() << endl;
    cout << "SUV: " << suv->getDescription() << endl;
    cout << "Truck: " << truck->getDescription() << endl;
    
    delete sedan;
    delete suv;
    delete truck;
}

// Helper function - Test drive vehicles
void testDriveVehicles(VehicleFactory* factory) {
    cout << "\n=== TEST DRIVES ===" << endl;
    
    Sedan* sedan = factory->createSedan();
    cout << "\n--- Sedan Test Drive ---" << endl;
    sedan->drive();
    delete sedan;
    
    SUV* suv = factory->createSUV();
    cout << "\n--- SUV Test Drive ---" << endl;
    suv->drive();
    delete suv;
    
    Truck* truck = factory->createTruck();
    cout << "\n--- Truck Test Drive ---" << endl;
    truck->drive();
    delete truck;
}

int main() {
    cout << "=====================================" << endl;
    cout << "  ABSTRACT FACTORY PATTERN DEMO" << endl;
    cout << "  Vehicle Manufacturing System" << endl;
    cout << "=====================================" << endl;
    
    // Decision Point 1: Choose which factory to use
    cout << "\n>>> DECISION POINT: Select manufacturer <<<" << endl;
    cout << "1. Toyota" << endl;
    cout << "2. BMW" << endl;
    cout << "3. Tesla" << endl;
    cout << "Enter choice (1-3): ";
    
    int choice;
    cin >> choice;
    
    VehicleFactory* factory = nullptr;
    
    // Client decides which concrete factory to create
    switch(choice) {
        case 1:
            factory = new ToyotaFactory();
            cout << "\n>>> YOU CHOSE: Toyota Factory <<<" << endl;
            break;
        case 2:
            factory = new BMWFactory();
            cout << "\n>>> YOU CHOSE: BMW Factory <<<" << endl;
            break;
        case 3:
            factory = new TeslaFactory();
            cout << "\n>>> YOU CHOSE: Tesla Factory <<<" << endl;
            break;
        default:
            cout << "Invalid choice. Using Toyota by default." << endl;
            factory = new ToyotaFactory();
    }
    
    // Client works with abstract factory interface
    showInventory(factory);
    testDriveVehicles(factory);
    
    // Clean up first factory
    delete factory;
    
    cout << "\n=====================================" << endl;
    cout << "  KEY BENEFITS DEMONSTRATED:" << endl;
    cout << "=====================================" << endl;
    cout << "1. Client code works with ANY factory" << endl;
    cout << "2. All products are from SAME family" << endl;
    cout << "3. Easy to add NEW families (e.g., Honda)" << endl;
    cout << "4. Product families are GUARANTEED consistent" << endl;
    cout << "=====================================" << endl;
    
    // Demonstrate switching factories at runtime
    cout << "\n\n>>> SWITCHING TO DIFFERENT MANUFACTURER <<<" << endl;
    cout << "Creating Tesla factory for comparison..." << endl;
    
    VehicleFactory* teslaFactory = new TeslaFactory();
    showInventory(teslaFactory);
    
    cout << "\nNotice: Same client code, different products!" << endl;
    cout << "This is the power of Abstract Factory!\n" << endl;
    
    // Clean up
    delete teslaFactory;
    
    return 0;
}