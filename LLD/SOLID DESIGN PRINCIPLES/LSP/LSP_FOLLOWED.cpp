#include<bits/stdc++.h>
using namespace std;

class DepositableAccount {
    public:
    virtual void deposit(double amount) = 0; // Abstract method for deposit
};

class WithdrawableAccount : public DepositableAccount {  // DepositableAccount is a base class
    // This class is designed to be extended by accounts that support withdrawal
    public:
    virtual void withdraw(double amount) = 0; // Abstract method for withdrawal
};

class SavingAccount : public WithdrawableAccount {
    private:
    double balance;

    public:
    // Constructor to initialize balance
    SavingAccount() : balance(0.0) {}

    // Overriding deposit method from DepositableAccount class
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " to Saving Account." << endl;
        }
    }

    // Overriding withdraw method from WithdrawableAccount class
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << " from Saving Account." << endl;
        }
    }

    // Method to get the current balance
    double getBalance() const {
        cout << "Current Balance in Saving Account: " << balance << endl;
        return balance;
    }
};

class CurrentAccount : public WithdrawableAccount {
    private:
    double balance;

    public:
    // Constructor to initialize balance
    CurrentAccount() : balance(0.0) {}

    // Overriding deposit method from DepositableAccount class
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " to Current Account." << endl;
        }
    }

    // Overriding withdraw method from WithdrawableAccount class
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << " from Current Account." << endl;
        }
    }

    // Method to get the current balance
    double getBalance() const {
        cout << "Current Balance in Current Account: " << balance << endl;
        return balance;
    }
};

class FixedDepositAccount : public DepositableAccount {
    private:
    double balance;

    public:
    // Constructor to initialize balance
    FixedDepositAccount() : balance(0.0) {}

    // Overriding deposit method from DepositableAccount class
    void deposit(double amount) override {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << " to Fixed Deposit Account." << endl;
        }
    }

    // Fixed Deposit Account does not support withdrawal, so no withdraw method
    double getBalance() const {
        cout << "Current Balance in Fixed Deposit Account: " << balance << endl;
        return balance;
    }
};

class BankClient {
    private:
    vector<DepositableAccount*> depositableAccount;
    vector<WithdrawableAccount*> withdrawableAccount;
    

    public:
    // Constructor to initialize accounts
    BankClient(vector<DepositableAccount*> depositableAccount,
    vector<WithdrawableAccount*> withdrawableAccount){
        this->depositableAccount = depositableAccount;
        this->withdrawableAccount = withdrawableAccount;
    }

    void processTransactions(){
        for(WithdrawableAccount* account : withdrawableAccount) {
            account->deposit(100.0); // Deposit 100 to each withdrawable account
            account->withdraw(50.0); // Withdraw 50 from each withdrawable account
        }
        for(DepositableAccount* account : depositableAccount) {
            account->deposit(200.0); // Deposit 200 to each depositable account
        }
    }
};

int main() {
    vector<DepositableAccount*> depositableAccounts;
    vector<WithdrawableAccount*> withdrawableAccounts;

    depositableAccounts.push_back(new FixedDepositAccount());
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());
    
    BankClient bankClient(depositableAccounts, withdrawableAccounts);
    bankClient.processTransactions();

    return 0;
}