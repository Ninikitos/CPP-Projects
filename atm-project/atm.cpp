#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void check_pin(int input, int pin);
void print_menu();
void balance_check(float balance);
float deposite(float balance);
float withdrawal(float balance);
void insufficient_funds(float balance, float amount);

int main ()
{
    bool done = false;
    int pin = 4311;
    int input = 0;
    unsigned option = 0;
    float balance = 10000;

    while (input != pin)
    {
        cout << "Enter your pin: " << endl;
        cin >> input;
        check_pin(input, pin);
        if (cin.fail())
        {
            cout << "|--------------------------|" << endl;
            cout << "| Pin must be only digits. |" << endl;
            cout << "|--------------------------|" << endl;
            cin.clear();
            cin.ignore(10, '\n');
        }
    }
    
    while(!done)
    {
        print_menu();
        cin >> option;
        cout << endl;

        switch (option)
        {
        case 1:
            balance_check(balance);
            break; 
        case 2:
            balance = deposite(balance);
            break;
        case 3:
            balance = withdrawal(balance);
            break;
        case 0:
            done = true;
        }
    }
}

void check_pin(int input, int pin)
{
    if (input == pin)
    {
        cout << "***** Login successful. *****" << endl;
        cout << endl;
        cout << "***** Welcome to Bank of America. *****" << endl;
        cout << endl;
        return;
    }

    int counter = 0;
    do
    {
        input = input / 10;
        counter++;
    } while (input >= 10);

    if (isdigit(input) == 0 && input != 0)
    {
        if (counter < 3)
        {
            cout << "|------------------|" << endl;
            cout << "| Pin is too short.|" << endl;
            cout << "|------------------|" << endl;
            cout << endl;
        }
        else if (counter >= 4)
        {
            cout << "|-----------------|" << endl;
            cout << "| Pin is too long.|" << endl;
            cout << "|-----------------|" << endl;
            cout << endl;
        }
        else if (counter == 3 && input != pin)
        {
            cout << "|------------------|" << endl;
            cout << "| Pin is incorrect.|" << endl;
            cout << "|------------------|" << endl;
            cout << endl;
            return;
        } 
    }

    if (input != pin && isdigit(input) != 0)
    {   
        cout << "|------------------|" << endl;
        cout << "| Pin is incorrect.|" << endl;
        cout << "|------------------|" << endl;
        cout << endl;
        return;
    }
}

void print_menu()
{
    cout << "***** Menu *****" << endl;
    cout << endl;
    cout << "1. Check balance" << endl;
    cout << endl;
    cout << "2. Deposite money" << endl;
    cout << endl;
    cout << "3. Withdrawal money" << endl;
    cout << endl;
    cout << "0. Exit" << endl;
    cout << endl;
}

void balance_check(float balance)
{   cout << "--------------------------------" << endl;
    cout << "Your current balance is: " << balance << "$" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
}

float deposite(float balance)
{
    cout << "Enter amount to deposite: ";
    float amount = 0;
    cin >> amount;
    balance += amount;
    cout << endl;

    cout << "-------------------------------" << endl;
    cout << "Your new balance is: " << balance << "$" << endl;
    cout << "-------------------------------" << endl;

    return balance;
}

float withdrawal(float balance)
{
    int temp_balance = balance;
    cout << "Enter amount to withdrawal: ";
    float amount = 0;
    cin >> amount;
    balance -= amount;

    if (balance > 0)
    {
        cout << endl;

        cout << "--------------------------------" << endl;
        cout << "Your new balance is: " << balance << "$" << endl;
        cout << "--------------------------------" << endl;

        return balance;
    }
    else 
    {
        insufficient_funds(balance, amount);
        return temp_balance;
    }
}

void insufficient_funds(float balance, float amount)
{
    float possible_amount = (balance * -1) + 1;
    cout << endl;
    cout << "If you will do this transaction." << endl;
    cout << "Your funds drop to " << balance << "$." << endl;
    cout << endl;
    cout << "Considering withdrawing on " << possible_amount << "$ less" << endl;
    cout << endl;
}