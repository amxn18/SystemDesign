#include<bits/stdc++.h>
using namespace std;

class Singelton{
    private:
    // A Variable to hold Singleton class Instance And will make sure that only one instance of the class is created.
    static Singelton* instance; 
    Singelton(){
        cout << "Constructor called!" << endl;
    }
    public:
    // As object is not created we need to create a static method to access the instance
    // As Static  Methds belong to the class rather than an instance, we can use it to access the single instance of the class.
    static Singelton* getInstance(){
        if(instance == nullptr){  // Check if instance is null Or not created yet
            // If instance is null, create a new instance of Singelton class
            instance = new Singelton();
        }
        return instance;
    }
};
Singelton* Singelton::instance = nullptr; // Initialize the static instance variable to null

int main(){
    Singelton* s1 = Singelton::getInstance(); // Get the single instance of Singelton class
    Singelton* s2 = Singelton::getInstance(); // Get the same instance again

    if(s1 == s2){
        cout << "Both instances are the same!" << endl; // This will print as both s1 and s2 point to the same instance Means no new instance is created
    } else {
        cout << "Instances are different!" << endl; // This will not happen
    }
    
    return 0;
}