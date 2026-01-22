#include <iostream>
#include <string>
using namespace std;

class BankAccount {

    private:
        string ownerName;
        int accountNumber;
        double balance;

    public:
        static int initialAccountNumber; // belongs to the class it self
        static int users; // belongs to the class it self

        //Constructor
        BankAccount(string name, double amount) {
            ownerName = name;
            accountNumber = initialAccountNumber + users;
            initalSetup(amount);
            users += 1;
        };

        //Called when user is setting up his account
        void initalSetup(double amount) {
            balance = amount;
            cout << "-------- Initial Setup ----------" << endl;
            cout << "Current Balance: $" << balance << "\n" << endl;
        }

        // For depositing money
        void deposit(double amount) {
            if(amount <=  0) {
                cout << "-------- Failed Deposit ----------" << endl;
                cout << "Invalid amount!" << "\n" << endl;
                return;
            };
                 balance += amount;
                 cout << "-------- Successful Deposit ----------" << endl;
                 cout<< "DEPOSIT of $"<< amount  << "\nDeposit Successful.\nNew balance: $" << balance << "\n" <<endl;
        };

        //For withdrawal
        void withdraw(double amount) {
          if (amount >= balance) {
                 cout << "-------- Failed Withdrawal ----------" << endl;
                 cout<<"Insufficient funds!" << "\nAvailable balance: $" << balance << "\n" << endl;
                 return;
            } else if(amount <= 0) {
                cout << "-------- Failed Withdrawal ----------" << endl;
                cout << "Invalid Amount!"<< "\nAvailable balance: $" << balance  << "\n" << endl;
                return;
            };

                balance -= amount;
                cout << "-------- Successful Withdrawal ----------" << endl;
                cout<< "WITHDRAWAL of $"<< amount << "\nWithdrawal Successful.\nNew balance: $" << balance << "\n" <<endl;
        };

        //Displays the Current available amount money  in user account
        void displayBalance() {
            cout << "-------- Final Balance ----------" << endl;
            cout << "Current Balance: $" << balance << "\n" << endl;

        };

        //Displays the user all info (name, account number, balance)
        void displayUserInfo() {
            cout << "-------- User Info ----------" << endl;
            cout << "Name: " << ownerName << "\nAccount Number: " << accountNumber << "\nBalance: $" << balance << "\n" << endl;
        };


};

//Initializing  the static datatypes
int BankAccount::initialAccountNumber = 10001;
int BankAccount::users = 0;

int main() {
  cout << "Test 1" << endl;
  BankAccount user1("Gebrezgabher Belay", 1000);

  cout << "Test 2" << endl;
  user1.withdraw(200);

  cout << "Test 3" << endl;
  user1.withdraw(2200);

  cout << "Test 4" << endl;
  user1.deposit(500);

  cout << "Test 5" << endl;
  user1.withdraw(300);

  cout << "Test 6" << endl;
  user1.displayBalance();

  cout << "Test 7" << endl;
  user1.displayUserInfo();


 return 0;
}



