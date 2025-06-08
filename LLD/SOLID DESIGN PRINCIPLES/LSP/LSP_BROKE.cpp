#include<bits/stdc++.h>
using namespace std;

// LSP Violation Example: A class that violates the Liskov Substitution Principle (LSP)

// Abstact Class for Account   
class Account {
    public:
    virtual void deposit(double amount) = 0; // Abstract method for deposit
    virtual void withdraw(double amount) = 0; // Abstract method for withdrawal
};

class SavingsAccount : public Account {
    private:
    double balance;

    public:
    // Constructor to initialize balance
    SavingsAccount() : balance(0.0) {}

    // Overriding deposit method from Account class
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " to Savings Account." << endl;
        }
    }

    // Overriding withdraw method from Account class
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << " from Savings Account." << endl;
        }
    }
    // Method to get the current balance
    double getBalance() const {
        cout << "Current Balance in Savings Account: " << balance << endl;
    }
};

class CurrentAccount : public Account {
    private:
    double balance;

    public:
    // Constructor to initialize balance
    CurrentAccount() : balance(0.0) {}

    // Overriding deposit method from Account class
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " to Current Account." << endl;
        }
    }

    // Overriding withdraw method from Account class
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << " from Current Account." << endl;
        }
    }
    
    // Method to get the current balance
    double getBalance() const {
        cout << "Current Balance in Current Account: " << balance << endl;
    }
};

class FixedDepositAccount : public Account {
    private:
    double balance;

    public:
    // Constructor to initialize balance
    FixedDepositAccount() : balance(0.0) {}

    // Overriding deposit method from Account class
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " to Fixed Deposit Account." << endl;
        }
    }

    // Overriding withdraw method from Account class

    // Violation of LSP: Fixed Deposit Account should not allow withdrawal
    // This method throws an exception to indicate that withdrawal is not allowed
    void withdraw(double amount) override {
        throw logic_error("Withdrawal not allowed from Fixed Deposit Account.");
    }
    
    // Method to get the current balance
    double getBalance() const {
        cout << "Current Balance in Fixed Deposit Account: " << balance << endl;
    }
};

class BankClient{
    private:
    vector<Account*> accounts;
    public:
    // Constructor to initialize the BankClient with a list of accounts
    BankClient(vector<Account*> accounts) {
        this->accounts = accounts;
    }

    void performTransactions() {
        for (auto& account : accounts) {
            account->deposit(1000); // Deposit 1000 to each account
            try {
                account->withdraw(500); // Withdraw 500 from each account
            } catch (const logic_error& e) {
                cout << "Error: " << e.what() << endl; // Handle withdrawal error for Fixed Deposit Account
            }
        }
    }
};

int main() {
    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedDepositAccount());

    BankClient* client = new BankClient(accounts);
    client->performTransactions();
}
