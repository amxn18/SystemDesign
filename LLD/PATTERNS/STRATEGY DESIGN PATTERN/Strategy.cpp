#include<bits/stdc++.h>
using namespace std;

// Strategy Interface For Walk
class WalkAbleRobot {
    public:
    virtual void walk() = 0; // Pure virtual function
    virtual ~WalkAbleRobot() {}; // Virtual destructor
};

// Concrete Strategy for Walking
class NormalWalk : public WalkAbleRobot {
    public:
    void walk() override {
        cout << "Walking normally." << endl;
    }
};

class NoWalk : public WalkAbleRobot {
    public:
    void walk() override {
        cout << "Cannot walk." << endl;
    }
};


class FlyableRobot {
    public:
    virtual void fly() = 0; // Pure virtual function
    virtual ~FlyableRobot() {}; // Virtual destructor
};

// Concrete Strategy for Flying
class NormalFly : public FlyableRobot {
    public:
    void fly() override {
        cout << "Flying normally." << endl;
    }
};
class NoFly : public FlyableRobot {
    public:
    void fly() override {
        cout << "Cannot fly." << endl;
    }
};

class TalkableRobot {
    public:
    virtual void talk() = 0; // Pure virtual function
    virtual ~TalkableRobot() {}; // Virtual destructor
};

// Concrete Strategy for Talking
class NormalTalk : public TalkableRobot {
    public:
    void talk() override {
        cout << "Talking normally." << endl;
    }
};

class NoTalk : public TalkableRobot {
    public:
    void talk() override {
        cout << "Cannot talk." << endl;
    }
};

class Projectable {
    public:
    virtual void projection() = 0; // Pure virtual function
    virtual ~Projectable() {}; // Virtual destructor
};

// Concrete Strategy for Projection
class NormalProjection : public Projectable {
    public:
    void projection() override {
        cout << "Normal projection available." << endl;
    }
};
class NoProjection : public Projectable {
    public:
    void projection() override {
        cout << "No projection available." << endl;
    }
};

// Client Class
class Robot {
    // Reference to strategy interfaces
    private:
    WalkAbleRobot* walkStrategy;
    FlyableRobot* flyStrategy;
    TalkableRobot* talkStrategy;
    Projectable* projectionStrategy;


    public:
    // Constructor to initialize strategies
      Robot(WalkAbleRobot* w, FlyableRobot* f, TalkableRobot* t, Projectable* p)
        : walkStrategy(w), flyStrategy(f), talkStrategy(t), projectionStrategy(p) {} 

    void performWalk() {
        walkStrategy->walk();
    }

    void performFly() {
        flyStrategy->fly();
    }

    void performTalk() {
        talkStrategy->talk();
    }

    void projection() {
        projectionStrategy->projection();
    }
};

// Concrete Robot Class
class CompanionRobot : public Robot {
    public:
    CompanionRobot(WalkAbleRobot* w, FlyableRobot* f, TalkableRobot* t, Projectable* p) 
        : Robot(w, f, t, p) {}

};

class CleanerRobot : public Robot {
    public:
    CleanerRobot(WalkAbleRobot* w, FlyableRobot* f, TalkableRobot* t, Projectable* p) 
        : Robot(w, f, t, p) {}
};


int main(){
    // Create strategies
    WalkAbleRobot* normalWalk = new NormalWalk();
    FlyableRobot* normalFly = new NoFly();
    TalkableRobot* normalTalk = new NormalTalk();
    Projectable* normalProjection = new NormalProjection();

    WalkAbleRobot* noWalk = new NoWalk();
    FlyableRobot* noFly = new NoFly();
    TalkableRobot* noTalk = new NoTalk();
    Projectable* noProjection = new NoProjection();

    // Create robots with different strategies
    Robot* companion = new CompanionRobot(normalWalk, normalFly, normalTalk, normalProjection);
    Robot* cleaner = new CleanerRobot(normalWalk, noFly, noTalk, normalProjection);

    // Perform actions
    companion->performWalk();
    companion->performFly();
    companion->performTalk();
    companion->projection();

    cleaner->performWalk();
    cleaner->performFly();
    cleaner->performTalk();
    cleaner->projection();

    return 0;
}