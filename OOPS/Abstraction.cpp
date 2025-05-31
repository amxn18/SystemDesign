#include<bits/stdc++.h>
using namespace std;

class Car {
    public:
    virtual void startEngine() = 0; // Pure virtual function
    virtual void shiftGear(int gear) = 0; // Pure virtual function
    virtual void accelerate(int speed) = 0; // Pure virtual function
    virtual void applyBrakes() = 0; // Pure virtual function
    virtual void stopEngine() = 0; // Pure virtual function
    virtual ~Car() {} // Virtual destructor
};

class SUV : public Car {  // Inherits from Car
    public:
    string brand;
    string model;
    bool isEngineOn;
    int  currentSpeed;
    int currentGear;

    // Constructor to initialize the SUV
    SUV(string b, string m){
        this-> brand = b;
        this-> model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    // Implementing the pure virtual functions
    void startEngine(){
        isEngineOn = true;
        cout << "Engine started for " << brand << " " << model << endl;
    }

    void shiftGear(int gear){
        if(isEngineOn){
            currentGear = gear;
            cout << "Shifted to gear " << currentGear << " in " << brand << " " << model << endl;
        } else {
            cout << "Cannot shift gears. Engine is off." << endl;
        }
    }

    void accelerate(int speed){
        if(isEngineOn){
            currentSpeed += speed;
            cout << "Accelerated to " << currentSpeed << " km/h in " << brand << " " << model << endl;
        } else {
            cout << "Cannot accelerate. Engine is off." << endl;
        }
    }

    void applyBrakes(){
        if(currentSpeed > 0){
            currentSpeed = 0;
            cout << "Brakes applied. Current speed is now " << currentSpeed << " km/h in " << brand << " " << model << endl;
        } else {
            cout << "Already at a stop." << endl;
        }
    }

    void stopEngine(){
        if(isEngineOn){
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
            cout << "Engine stopped for " << brand << " " << model << endl;
        } else {
            cout << "Engine is already off." << endl;
        }
    }
};

int main(){
    // Object of SUV class
    Car* mySUV = new SUV("Mahindra", "XUV700");
    mySUV->startEngine();
    mySUV->shiftGear(1);
    mySUV->accelerate(50);
    mySUV->applyBrakes();
    mySUV->shiftGear(2);
    mySUV->accelerate(80);
    mySUV->applyBrakes();
    mySUV->stopEngine();
}