#include<bits/stdc++.h>
using namespace std;

class Car {
    // Properties/ Characteristics of the Car
    protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

    public:
    // Constructor to initialize the Car
    Car(string b, string m){ 
        this->brand = b; 
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    // Behaviors/ Methods of the Car
    void startEngine() {
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    }
    void stopEngine() {
        isEngineOn = false;
        cout << "Engine stopped for " << brand << " " << model << endl;
    }

    virtual void acclerate() = 0;  // Abstract method for dynamic polymorphism
    virtual void applyBrakes() = 0;   // Abstract method for dynamic polymorphism
    virtual ~Car() {}  // Virtual destructor
};

// Public inheritance from Car

class ManualCar : public Car {
    private:
    int currentGear;  // Specific property for ManualCar
    public:
    // Constructor to initialize the ManualCar
    ManualCar(string b, string m) : Car(b, m), currentGear(0) {}
    
    // Behaviors/ Methods specific to ManualCar
    void shiftGear(int gear) {
        if(isEngineOn) {
            currentGear = gear;
            cout << "Shifted to gear " << currentGear << " in " << brand << " " << model << endl;
        } else {
            cout << "Cannot shift gears. Engine is off." << endl;
        }
    }

    // Overriding the abstract methods
    void acclerate() override {
        if(isEngineOn) {
            currentSpeed += 10;  // Example speed increment
            cout << "Accelerated to " << currentSpeed << " km/h in " << brand << " " << model << endl;
        } else {
            cout << "Cannot accelerate. Engine is off." << endl;
        }
    }
    void applyBrakes() override {
        if(currentSpeed > 0) {
            currentSpeed = 0;
            cout << "Brakes applied. Current speed is now " << currentSpeed << " km/h in " << brand << " " << model << endl;
        } else {
            cout << "Already at a stop." << endl;
        }
    }
};

class ElectricCar : public Car {
    private:
    int batteryLevel;  // Specific property for ElectricCar
    public:
    // Constructor to initialize the ElectricCar
    ElectricCar(string b, string m) : Car(b, m), batteryLevel(10) {}
    
    // Behaviors/ Methods specific to ElectricCar
    void chargeBattery(int amount) {
        batteryLevel += amount;
        cout << "Battery charged to " << batteryLevel << "% in " << brand << " " << model << endl;
    }
    
    void displayBatteryLevel() {
        cout << "Current battery level: " << batteryLevel << "% in " << brand << " " << model << endl;
    }

    // Overriding the abstract methods
    void acclerate() override {
        if(isEngineOn) {
            currentSpeed += 15;  // Example speed increment
            cout << "Accelerated to " << currentSpeed << " km/h in " << brand << " " << model << endl;
        } else {
            cout << "Cannot accelerate. Engine is off." << endl;
        }
    }
    void applyBrakes() override {
        if(currentSpeed > 0) {
            currentSpeed = 0;
            cout << "Brakes applied. Current speed is now " << currentSpeed << " km/h in " << brand << " " << model << endl;
        } else {
            cout << "Already at a stop." << endl;
        }
    }
};

int main() {
    // Creating objects of ManualCar and ElectricCar
    ManualCar myManualCar("Toyota", "Corolla");
    ElectricCar myElectricCar("Tesla", "Model S");

    // Using the ManualCar object
    myManualCar.startEngine();
    myManualCar.shiftGear(2);
    myManualCar.acclerate();
    myManualCar.applyBrakes();
    myManualCar.stopEngine();

    // Using the ElectricCar object
    myElectricCar.startEngine();
    myElectricCar.chargeBattery(20);
    myElectricCar.displayBatteryLevel();
    myElectricCar.acclerate();
    myElectricCar.applyBrakes();
    myElectricCar.stopEngine();

    return 0;
}