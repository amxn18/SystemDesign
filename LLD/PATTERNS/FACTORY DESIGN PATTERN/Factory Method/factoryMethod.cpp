#include<bits/stdc++.h>
using namespace std;

// Factory Method defines an interface for creating objects but allows subclasses to decide which class to instantiate.

class Burger{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
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

class WheatCheeseBurger : public Burger{
public:
    void prepare() override {
        cout << "Preparing Wheat Cheese Burger" << endl;
    }
};

class WheatVeggieBurger : public Burger{
public:
    void prepare() override {
        cout << "Preparing Wheat Veggie Burger" << endl;
    }
};

class WheatChickenBurger : public Burger{
public: 
    void prepare() override {
        cout << "Preparing Wheat Chicken Burger" << endl;
    }
};      


class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
};

class ABCBurgerFactory : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "Cheese") {
            return new CheeseBurger();
        } else if (type == "Veggie") {
            return new VeggieBurger();
        } else if (type == "Chicken") {
            return new chickenBurger();
        } else {
            return nullptr;
        }
    }
};

class XYZBurgerFactory : public BurgerFactory {
public: 
    Burger* createBurger(string& type) override {
        if (type == "WheatCheese") {
            return new WheatCheeseBurger();
        } else if (type == "WheatVeggie") {
            return new WheatVeggieBurger();
        } else if (type == "WheatChicken") {
            return new WheatChickenBurger();
        } else {
            return nullptr;
        }
    }
};  

int main(){
    string type;
    cout << "Enter the type of burger you want (Cheese, Veggie, Chicken, WheatCheese, WheatVeggie, WheatChicken): ";
    cin >> type;

    BurgerFactory* factory = new ABCBurgerFactory();
    BurgerFactory* wheatFactory = new XYZBurgerFactory();

    Burger* burger = factory->createBurger(type);
    if (burger) {
        burger->prepare();
    } else {
        burger = wheatFactory->createBurger(type);
        if (burger) {
            burger->prepare();
        } else {
            cout << "Invalid burger type!" << endl;
        }
    }
}