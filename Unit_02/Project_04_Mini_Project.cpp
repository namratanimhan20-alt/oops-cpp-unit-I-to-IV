//Mini-Project Problem Statement :
//Banking System with Account Hierarchy : Create a base Account class and derived classes SavingsAccount, CurrentAccount, and FixedDepositAccount. 
//Include account number, holder name, balance, deposit, withdrawal, and interest-calculation features. Use virtual functions for account-specific behavior. 

#include <iostream> // Provides input and output operations using cin and cout.
#include <iomanip> // Provides formatting functions such as fixed and setprecision.
#include <string> // Provides the string data type.

using namespace std; // Allows standard library names to be used without std::.


// Abstract base class representing a general bank account.
class Account
{
protected:
    string accountNumber; // Stores the unique account number.
    string holderName; // Stores the name of the account holder.
    double balance; // Stores the current account balance.

public:

    // Constructor initializes the common account details.
    Account(string accNo, string name, double initialBalance)
    {
        accountNumber = accNo; // Assigns the account number.
        holderName = name; // Assigns the account holder name.
        balance = initialBalance; // Assigns the initial balance.
    }

    // Virtual destructor is used for proper destruction of derived objects.
    virtual ~Account()
    {
        cout << "Account object destroyed." << endl;
    }

    // Function to deposit money into the account.
    void deposit(double amount)
    {
        if (amount > 0) // Checks whether the deposit amount is valid.
        {
            balance += amount; // Adds the amount to the current balance.
            cout << "Deposit of Rs. " << amount << " successful." << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Virtual function to withdraw money from the account.
    virtual void withdraw(double amount)
    {
        if (amount <= 0) // Checks whether the withdrawal amount is valid.
        {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > balance) // Checks whether sufficient balance is available.
        {
            cout << "Insufficient balance." << endl;
        }
        else
        {
            balance -= amount; // Deducts the withdrawal amount.
            cout << "Withdrawal of Rs. " << amount << " successful." << endl;
        }
    }

    // Pure virtual function for account-specific interest calculation.
    virtual double calculateInterest() const = 0;

    // Pure virtual function to display the account type.
    virtual void displayAccountType() const = 0;

    // Function to display common account details.
    void displayBasicInfo() const
    {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Holder Name    : " << holderName << endl;
        cout << "Balance        : Rs. " << fixed << setprecision(2) << balance << endl;
    }
};


// Derived class representing a Savings Account.
class SavingsAccount : public Account
{
private:
    double interestRate; // Stores the interest rate for the savings account.

public:

    // Constructor initializes the Savings Account.
    SavingsAccount(string accNo, string name, double initialBalance)
        : Account(accNo, name, initialBalance)
    {
        interestRate = 4.0; // Sets the savings account interest rate.
    }

    // Destructor of the Savings Account.
    ~SavingsAccount()
    {
        cout << "Savings Account destroyed." << endl;
    }

    // Overrides the interest calculation for a Savings Account.
    double calculateInterest() const override
    {
        return balance * interestRate / 100; // Calculates savings interest.
    }

    // Overrides the account type display function.
    void displayAccountType() const override
    {
        cout << "Account Type   : Savings Account" << endl;
    }
};


// Derived class representing a Current Account.
class CurrentAccount : public Account
{
private:
    double interestRate; // Stores the interest rate for the current account.

public:

    // Constructor initializes the Current Account.
    CurrentAccount(string accNo, string name, double initialBalance)
        : Account(accNo, name, initialBalance)
    {
        interestRate = 0.0; // Sets the current account interest rate.
    }

    // Destructor of the Current Account.
    ~CurrentAccount()
    {
        cout << "Current Account destroyed." << endl;
    }

    // Overrides the withdrawal function for Current Account.
    void withdraw(double amount) override
    {
        double minimumBalance = 1000.0; // Defines the minimum balance requirement.

        if (amount <= 0) // Checks whether the withdrawal amount is valid.
        {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (balance - amount < minimumBalance) // Checks the minimum balance condition.
        {
            cout << "Withdrawal denied. Minimum balance of Rs. "
                 << minimumBalance << " must be maintained." << endl;
        }
        else
        {
            balance -= amount; // Deducts the withdrawal amount.
            cout << "Withdrawal of Rs. " << amount << " successful." << endl;
        }
    }

    // Overrides the interest calculation for a Current Account.
    double calculateInterest() const override
    {
        return balance * interestRate / 100; // Calculates current account interest.
    }

    // Overrides the account type display function.
    void displayAccountType() const override
    {
        cout << "Account Type   : Current Account" << endl;
    }
};


// Derived class representing a Fixed Deposit Account.
class FixedDepositAccount : public Account
{
private:
    double interestRate; // Stores the interest rate for the fixed deposit account.

public:

    // Constructor initializes the Fixed Deposit Account.
    FixedDepositAccount(string accNo, string name, double initialBalance)
        : Account(accNo, name, initialBalance)
    {
        interestRate = 7.0; // Sets the fixed deposit interest rate.
    }

    // Destructor of the Fixed Deposit Account.
    ~FixedDepositAccount()
    {
        cout << "Fixed Deposit Account destroyed." << endl;
    }

    // Overrides the withdrawal function for Fixed Deposit Account.
    void withdraw(double amount) override
    {
        cout << "Withdrawal is not allowed from the Fixed Deposit Account." << endl;
    }

    // Overrides the interest calculation for a Fixed Deposit Account.
    double calculateInterest() const override
    {
        return balance * interestRate / 100; // Calculates fixed deposit interest.
    }

    // Overrides the account type display function.
    void displayAccountType() const override
    {
        cout << "Account Type   : Fixed Deposit Account" << endl;
    }
};


// Utility function to display complete account information.
void displayAccount(const Account& account)
{
    cout << "---------------------------------------------" << endl;
    account.displayAccountType(); // Calls the appropriate derived class function.
    account.displayBasicInfo(); // Displays common account information.
    cout << "Interest       : Rs. " << fixed << setprecision(2)
         << account.calculateInterest() << endl;
    cout << "---------------------------------------------" << endl;
}


// Main function where program execution begins.
int main()
{
    cout << "=============================================" << endl;
    cout << "          BANKING SYSTEM" << endl;
    cout << "=============================================" << endl;


    // Creates a Savings Account object.
    SavingsAccount savings("SA1001", "Amit", 50000);

    // Creates a Current Account object.
    CurrentAccount current("CA2001", "Sneha", 75000);

    // Creates a Fixed Deposit Account object.
    FixedDepositAccount fixedDeposit("FD3001", "Rohan", 100000);


    // Performs transactions on the Savings Account.
    cout << "\nSAVINGS ACCOUNT TRANSACTION" << endl;
    savings.deposit(5000); // Deposits money into the savings account.
    savings.withdraw(2000); // Withdraws money from the savings account.
    displayAccount(savings); // Displays updated savings account details.


    // Performs transactions on the Current Account.
    cout << "\nCURRENT ACCOUNT TRANSACTION" << endl;
    current.deposit(10000); // Deposits money into the current account.
    current.withdraw(5000); // Withdraws money from the current account.
    displayAccount(current); // Displays updated current account details.


    // Performs transactions on the Fixed Deposit Account.
    cout << "\nFIXED DEPOSIT ACCOUNT TRANSACTION" << endl;
    fixedDeposit.deposit(20000); // Deposits money into the fixed deposit account.
    fixedDeposit.withdraw(10000); // Demonstrates account-specific withdrawal behavior.
    displayAccount(fixedDeposit); // Displays updated fixed deposit account details.


    // Creates base class pointers for runtime polymorphism.
    Account* accounts[3];

    accounts[0] = &savings; // Stores the address of the Savings Account object.
    accounts[1] = &current; // Stores the address of the Current Account object.
    accounts[2] = &fixedDeposit; // Stores the address of the Fixed Deposit object.


    // Demonstrates runtime polymorphism.
    cout << "\nPOLYMORPHISM DEMONSTRATION" << endl;
    cout << "=============================================" << endl;

    for (int i = 0; i < 3; i++)
    {
        displayAccount(*accounts[i]); // Calls overridden functions using the base class pointer.
    }


    // Displays the completion message.
    cout << "\nBanking System executed successfully." << endl;

    return 0; // Returns 0 to indicate successful program execution.
}