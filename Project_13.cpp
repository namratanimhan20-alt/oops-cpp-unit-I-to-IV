//Real-Time Application 13: Secure Banking Transaction Module 
//Problem Scenario : A banking service must reject negative deposits, invalid withdrawals, and withdrawal requests exceeding the available balance. 
//Custom exceptions allow callers to distinguish between failure types. 

#include <exception>
// <exception>:
// Header file that provides the standard exception class.
//
// The exception class is used as a base class
// for creating and handling exceptions.

#include <iostream>
// <iostream>:
// Header file used for input and output.
//
// It provides cout and endl.

#include <stdexcept>
// <stdexcept>:
// Header file that provides standard exception classes.
//
// It provides invalid_argument, which is used
// when a function receives an invalid argument.

#include <string>
// <string>:
// Header file used for the string data type.

using namespace std;
// Allows us to use standard names such as
// cout, string, exception, and invalid_argument
// without writing std:: before them.


// Custom exception class
class InsufficientFundsException : public exception
{
    /*
        class:
        Keyword used to create a class.

        InsufficientFundsException:
        Name of the custom exception class.

        : public exception:
        Means InsufficientFundsException publicly inherits
        from the standard exception class.

        exception:
        Standard C++ base class used for exceptions.

        public inheritance:
        Public members of the base class remain public
        in the derived class.

        This custom class represents the situation
        where a person tries to withdraw more money
        than the available balance.
    */


private:
    // private:
    // Members under private can only be accessed
    // directly inside this class.

    double balance;
    // Stores the account balance available
    // at the time of the exception.

    double requestedAmount;
    // Stores the amount the user tried to withdraw.


public:
    // public:
    // Members under public can be accessed
    // from outside the class.


    // Constructor of the custom exception
    InsufficientFundsException(
        double currentBalance,
        double requested
    )
        : balance(currentBalance),
          requestedAmount(requested)
    {
    }

    /*
        InsufficientFundsException:
        Constructor name.
        It is the same as the class name.

        double currentBalance:
        Parameter that receives the current account balance.

        double requested:
        Parameter that receives the amount requested
        for withdrawal.

        : balance(currentBalance),
          requestedAmount(requested):

        This is a member initializer list.

        balance(currentBalance):
        Initializes balance using currentBalance.

        requestedAmount(requested):
        Initializes requestedAmount using requested.

        The constructor stores the details needed
        to explain the insufficient-funds error.
    */


    // Override the what() function
    const char* what() const noexcept override
    {
        /*
            const char*:
            Return type of the function.

            char:
            Character data type.

            const char*:
            Pointer to constant characters.
            It returns a text message.

            what():
            Function provided by the standard exception class.
            It returns a description of the exception.

            const:
            This function does not modify the exception object.

            noexcept:
            Specifies that this function will not throw
            another exception.

            override:
            Indicates that this function overrides
            a virtual function from the base class exception.
        */

        return "Insufficient balance for withdrawal.";

        /*
            return:
            Sends a value back to the calling statement.

            The returned text explains the reason
            for the exception.
        */
    }


    // Getter function for the balance
    double getBalance() const
    {
        /*
            double:
            Return type.
            The function returns a decimal number.

            getBalance:
            Function name.

            const:
            This function does not modify the exception object.
        */

        return balance;
        // Returns the balance stored in the exception object.
    }


    // Getter function for the requested amount
    double getRequestedAmount() const
    {
        /*
            double:
            Return type.

            getRequestedAmount:
            Function name.

            const:
            This function does not modify the exception object.
        */

        return requestedAmount;
        // Returns the amount that was requested for withdrawal.
    }
};



// BankAccount class
class BankAccount
{
private:
    // private:
    // Data members can only be accessed directly
    // inside the BankAccount class.

    int accountNumber;
    // Stores the bank account number.

    string holderName;
    // Stores the account holder's name.

    double balance;
    // Stores the current account balance.


public:
    // public:
    // Public members can be accessed from outside the class.


    // Constructor of BankAccount
    BankAccount(
        int number,
        string name,
        double openingBalance
    )
        : accountNumber(number),
          holderName(name),
          balance(openingBalance)
    {
        /*
            BankAccount:
            Constructor name.

            int number:
            Parameter for the account number.

            string name:
            Parameter for the account holder's name.

            double openingBalance:
            Parameter for the initial account balance.

            : accountNumber(number):
            Initializes accountNumber with number.

            holderName(name):
            Initializes holderName with name.

            balance(openingBalance):
            Initializes balance with openingBalance.
        */


        // Check whether the opening balance is negative
        if (openingBalance < 0.0)
        {
            /*
                if:
                Conditional statement.

                openingBalance < 0.0:
                Checks whether the opening balance
                is less than zero.

                <:
                Less-than comparison operator.
            */

            throw invalid_argument(
                "Opening balance cannot be negative."
            );

            /*
                throw:
                Used to generate or raise an exception.

                invalid_argument:
                Standard exception class used when
                an argument has an invalid value.

                Here, a negative opening balance is invalid.

                The exception is sent to the matching
                catch block in main().
            */
        }
    }


    // Function to deposit money
    void deposit(double amount)
    {
        /*
            void:
            The function does not return a value.

            deposit:
            Function name.

            double amount:
            Parameter that stores the amount to deposit.
        */


        // Check whether the deposit amount is valid
        if (amount <= 0.0)
        {
            /*
                amount <= 0.0:
                Checks whether the amount is less than
                or equal to zero.

                <=:
                Less-than-or-equal-to operator.

                A deposit must be greater than zero.
            */

            throw invalid_argument(
                "Deposit amount must be positive."
            );

            /*
                Throws an invalid_argument exception
                if the deposit amount is zero or negative.
            */
        }


        // Add the amount to the balance
        balance += amount;

        /*
            +=:
            Compound assignment operator.

            balance += amount;
            is equivalent to:

            balance = balance + amount;

            Example:
            balance = 5000
            amount  = 2000

            New balance = 7000
        */
    }


    // Function to withdraw money
    void withdraw(double amount)
    {
        /*
            void:
            The function does not return a value.

            withdraw:
            Function name.

            double amount:
            Amount the user wants to withdraw.
        */


        // Check whether the withdrawal amount is valid
        if (amount <= 0.0)
        {
            /*
                A withdrawal amount must be greater than zero.

                If amount is zero or negative,
                an invalid_argument exception is thrown.
            */

            throw invalid_argument(
                "Withdrawal amount must be positive."
            );
        }


        // Check whether sufficient balance is available
        if (amount > balance)
        {
            /*
                amount > balance:
                Checks whether the requested withdrawal
                is greater than the current balance.

                >:
                Greater-than comparison operator.

                If the requested amount is greater than
                the available balance, withdrawal is not allowed.
            */

            throw InsufficientFundsException(
                balance,
                amount
            );

            /*
                throw:
                Raises an exception.

                InsufficientFundsException:
                Creates an object of the custom exception class.

                balance:
                Sends the current balance to the exception.

                amount:
                Sends the requested withdrawal amount
                to the exception.

                Example:
                Current balance = 5500
                Requested amount = 10000

                The custom exception stores:
                balance = 5500
                requestedAmount = 10000
            */
        }


        // Deduct the amount from the balance
        balance -= amount;

        /*
            -=:
            Compound subtraction assignment operator.

            balance -= amount;
            is equivalent to:

            balance = balance - amount;

            Example:
            balance = 7000
            amount  = 1500

            New balance = 5500
        */
    }


    // Function to display account details
    void display() const
    {
        /*
            void:
            The function does not return a value.

            display:
            Function name.

            const:
            The function does not modify the account object.
        */

        cout << "Account: " << accountNumber
             << " | Holder: " << holderName
             << " | Balance: Rs. " << balance
             << endl;

        /*
            cout:
            Displays output on the screen.

            "Account: ":
            Displays the account label.

            accountNumber:
            Displays the account number.

            " | Holder: ":
            Displays a separator and holder label.

            holderName:
            Displays the account holder's name.

            " | Balance: Rs. ":
            Displays the balance label.

            balance:
            Displays the current balance.

            endl:
            Moves the cursor to the next line.
        */
    }
};



// Main function
int main()
{
    /*
        int:
        Return type of the main function.

        main():
        Program execution starts here.
    */


    // Start a try block
    try
    {
        /*
            try:
            Contains code that may produce an exception.

            If an exception occurs inside this block,
            control immediately moves to a matching catch block.
        */


        // Create a bank account
        BankAccount account(1001, "Rahul", 5000.0);

        /*
            BankAccount:
            Class name.

            account:
            Object name.

            1001:
            Account number.

            "Rahul":
            Account holder's name.

            5000.0:
            Opening balance.

            The constructor initializes:

            accountNumber = 1001
            holderName    = "Rahul"
            balance       = 5000.0
        */


        // Deposit money into the account
        account.deposit(2000.0);

        /*
            Calls the deposit() function.

            Old balance = 5000.0
            Deposit     = 2000.0

            New balance = 7000.0
        */


        // Withdraw money from the account
        account.withdraw(1500.0);

        /*
            Calls the withdraw() function.

            Requested amount = 1500.0
            Available balance = 7000.0

            Since 1500.0 is less than 7000.0,
            the withdrawal is successful.

            New balance = 7000.0 - 1500.0
                        = 5500.0
        */


        // Try to withdraw more money than the balance
        account.withdraw(10000.0);

        /*
            Requested amount = 10000.0
            Available balance = 5500.0

            Since:

            10000.0 > 5500.0

            the condition inside withdraw() becomes true.

            InsufficientFundsException is thrown.

            The remaining statements in the try block
            are skipped, and control moves to the
            matching catch block.
        */
    }


    // Catch the custom insufficient-funds exception
    catch (const InsufficientFundsException& error)
    {
        /*
            catch:
            Handles an exception thrown from the try block.

            const InsufficientFundsException& error:

            InsufficientFundsException:
            Type of exception being caught.

            const:
            The exception object will not be modified.

            &:
            Reference to the original exception object.
            It avoids making a copy.

            error:
            Name used to access the caught exception.

            This catch block is specifically designed
            to handle insufficient-funds errors.
        */


        cout << "Transaction failed: "
             << error.what()
             << endl;

        /*
            error.what():
            Calls the what() function of the custom exception.

            It returns:
            "Insufficient balance for withdrawal."

            The message is displayed on the screen.
        */


        cout << "Available balance: Rs. "
             << error.getBalance()
             << endl;

        /*
            error.getBalance():
            Calls the getter function that returns
            the balance stored in the exception.

            It displays:
            Available balance: Rs. 5500
        */


        cout << "Requested amount: Rs. "
             << error.getRequestedAmount()
             << endl;

        /*
            error.getRequestedAmount():
            Returns the amount that was requested.

            It displays:
            Requested amount: Rs. 10000
        */
    }


    // Catch other standard exceptions
    catch (const exception& error)
    {
        /*
            This catch block handles other exceptions
            derived from the standard exception class.

            const exception& error:
            Catches the exception by constant reference.

            This can handle exceptions such as:
            invalid_argument
            runtime_error
            and other standard exception types.

            Important:
            The custom InsufficientFundsException catch block
            is placed before this general exception catch block.

            This is because InsufficientFundsException is
            derived from exception.
        */


        cout << "System error: "
             << error.what()
             << endl;

        /*
            error.what():
            Returns the description of the standard exception.

            For example, if a negative deposit were attempted,
            the message could be:

            System error: Deposit amount must be positive.
        */
    }


    return 0;
    /*
        return 0:
        Indicates that the program executed successfully.
    */
}