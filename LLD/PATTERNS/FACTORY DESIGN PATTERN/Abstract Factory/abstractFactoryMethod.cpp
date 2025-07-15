#include<bits/stdc++.h>
using namespace std;

// Abstract Factory Method provides an interface for creating families of related or dependent objects without specifying their concrete classes.   
class Burger {
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

class WheatCheeseBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Wheat Cheese Burger" << endl;
    }
};

class WheatVeggieBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Wheat Veggie Burger" << endl;
    }
};

class WheatChickenBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Wheat Chicken Burger" << endl;
    }
};

class GarlicBread {
public:
    virtual void prepare() = 0;  // Make it public
    virtual ~GarlicBread() {}
};

class BasicGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Basic Garlic Bread" << endl;
    }
};

class wheatGarlicBread : public GarlicBread {
public:
    void prepare() override {
        cout << "Preparing Wheat Garlic Bread" << endl;
    }
};

class MealFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
    virtual GarlicBread* createGarlicBread(string& type1) = 0;
    virtual ~MealFactory() {}
};

class ABCMealFactory : public MealFactory {
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

    GarlicBread* createGarlicBread(string& type1) override {
        if (type1 == "Basic") {
            return new BasicGarlicBread();
        } else {
            return nullptr;
        }
    }
};

class XYZMealFactory : public MealFactory {
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

    GarlicBread* createGarlicBread(string& type1) override {
        if (type1 == "Wheat") {
            return new wheatGarlicBread();
        } else {
            return nullptr;
        }
    }
};

int main() {
    string burgerType, garlicBreadType;
    cout << "Enter Burger Type (Cheese/Veggie/Chicken/WheatCheese/WheatVeggie/WheatChicken): ";
    cin >> burgerType;
    cout << "Enter Garlic Bread Type (Basic/Wheat): ";
    cin >> garlicBreadType;

    MealFactory* abcfactory = new ABCMealFactory();
    MealFactory* xyzfactory = new XYZMealFactory();

    Burger* burger = abcfactory->createBurger(burgerType);
    GarlicBread* garlicBread = abcfactory->createGarlicBread(garlicBreadType);
    Burger* wheatBurger = xyzfactory->createBurger(burgerType);
    GarlicBread* wheatGarlicBread = xyzfactory->createGarlicBread(garlicBreadType);

    burger->prepare();
    garlicBread->prepare();

    return 0;
}
