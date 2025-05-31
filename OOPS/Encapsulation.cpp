#include<bits/stdc++.h>
using namespace std;

// Properties and Behaviours of SUV is encapsulated in the class SUV
class SUV{ 
    // Properties/ Characteristics of the SUV
    private:
    string brand;
    string model;
    bool isEngineOn;
    int  currentSpeed;
    int currentGear;
    string type; 

    public:
    // Constructor to initialize the SUV
    SUV(string b, string m){
        this-> brand = b;
        this-> model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        type = "All-Terrain"; 
    }

    // Getters for the properties
    string getBrand() const {
        return brand;
    }
    string getModel() const {
        return model;
    }
    bool getIsEngineOn() const {
        return isEngineOn;
    }
    int getCurrentSpeed() const {
        return currentSpeed;
    }
    int getCurrentGear() const {
        return currentGear;
    }
    string getTyres() const {
        return type;
    }

    // Setters for the properties
    void setTyres(const string& type) {
        this->type = type;
    }

    // Methods/ Behaviors of the SUV
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
    SUV* mySUV = new SUV("Toyota", "Fortuner");
    mySUV->startEngine();
    mySUV->shiftGear(1);
    mySUV->accelerate(50);
    mySUV->shiftGear(2);
    mySUV->accelerate(30);
    mySUV->applyBrakes();
    mySUV->stopEngine();

    cout<< "Brand: " << mySUV->getBrand() << endl;
    cout<< "Model: " << mySUV->getModel() << endl;
    cout<< "Is Engine On: " << (mySUV->getIsEngineOn() ? "Yes" : "No") << endl;
    cout<< "Current Speed: " << mySUV->getCurrentSpeed() << " km/h" << endl;
    cout<< "Current Gear: " << mySUV->getCurrentGear() << endl;
    cout<< "Tyres Type: " << mySUV->getTyres() << endl;
    mySUV->setTyres("Mud-Terrain");
    cout<< "Updated Tyres Type: " << mySUV->getTyres() << endl;
}
