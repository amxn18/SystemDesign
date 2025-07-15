#include<bits/stdc++.h>
using namespace std;

// Simple Factory is a design pattern that provides a way to create objects without specifying the exact class of object that will be created. Or
// A Factory Class is that class that decides which class to instantiate based on the input provided.
// In this example, we will create a simple factory for different types of burgers.

class Burger{
    public:
    virtual void prepare() = 0; // Pure virtual function for preparing the burger
    virtual ~Burger() {}  // Virtual destructor for proper cleanup
};

class CheeseBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Cheese Burger" << endl;
    }
};

class VeggieBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Veggie Burger" << endl;
    }
};

class chickenBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Chicken Burger" << endl;
    }
};

class BurgerFactory {
    public:
    static Burger* createBurger(const string& type) {
        if (type == "cheese") {
            return new CheeseBurger();
        } else if (type == "veggie") {
            return new VeggieBurger();
        } else if (type == "chicken") {
            return new chickenBurger();
        } else {
            return nullptr; // Invalid type
        }
    }
};


int main(){
    string burgerType;
    cin>> burgerType;
    BurgerFactory* factory = new BurgerFactory();
    Burger* burger = factory->createBurger(burgerType);
    burger->prepare();
    return 0;
}