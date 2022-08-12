#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void check_pin(int input, int pin);
void print_menu();
void print_accounts(int max, int accounts[]);
int account_check(int account_number, int balance, int accounts[]);
void balance_check(int index, int accounts[]);
void deposite(float amount, int index, int accounts[]);
void withdrawal(float amount, int index, int accounts[]);
void insufficient_funds(float balance, float amount);
int open_account(int new_accounts, int accounts[]);
int close_account(int new_accounts, int accounts[]);

int main ()
{
    bool done = false;
    int pin = 4311;
    int input = 0;
    unsigned option = 0;
    float balance = 10000;

    const int MAX_ACCOUNTS = 5;
    int new_accounts = 1;
    int accounts[new_accounts];

    for (int i = 0; i < new_accounts; i++)
    {
        accounts[i] = 0;    
    }

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
            cout << "What account you want to check balance?" << endl;
            cout << "0 to go back." << endl;
            cin >> option;
            cout << endl;

            if (option == 0)
            {
                cout << "Canceling check." << endl;
                cout << endl;
            }
            else if (option >= 1 && option <= new_accounts)
            {
                int index = option - 1;
                balance_check(index, accounts);
            }
            else
            {
                cout << "Account number is invalid" << endl;
            }
            break; 
        case 2:
            cout << "What account you want to deposite?" << endl;
            cout << "0 to go back." << endl;
            cin >> option;
            cout << endl;
            if (option <= new_accounts)
            {
                if (option == 0)
                {
                    cout << "Canceling transaction." << endl;
                    cout << endl;
                }
                else if (option >= 1 && option <= new_accounts)
                {
                    cout << "Enter amount to deposite: " << endl;
                    int index = option - 1;
                    float amount;
                    cin >> amount;
                    deposite(amount, index, accounts);
                }
                else
                {
                    cout << "Account number is invalid" << endl;
                }
            }
            else
            {
                cout << "This account does not exists. Open it first." << endl;
                cout << endl;
            }
            
            break;
        case 3:
            cout << "What account you want to withdrawal from?" << endl;
            cout << "0 to go back." << endl;
            cin >> option;
            cout << endl;
            if (option <= new_accounts)
            {
                if (option == 0)
                {
                    cout << "Canceling transaction." << endl;
                    cout << endl;
                }
                else if (option >= 1 && option <= MAX_ACCOUNTS)
                {
                    cout << "Enter amount of withdrawal: " << endl;
                    int index = option - 1;
                    float amount;
                    cin >> amount;
                    withdrawal(amount, index, accounts);
                }
                else
                {
                    cout << "Account number is invalid" << endl;
                }
            }
            else
            {
                cout << "This account does not exists. Open it first." << endl;
                cout << endl;
            }
            break;
        case 4:
            print_accounts(new_accounts, accounts);
            break;
        case 5:
            if (new_accounts < MAX_ACCOUNTS)
            {
                cout << "New account opened successfully!" << endl;
                cout << endl;
                new_accounts = open_account(new_accounts, accounts);
                print_accounts(new_accounts, accounts);
            }
            else
            {
                cout << "You reached maximum accounts." << endl;
                cout << endl;
            }
            break;
        case 6:
            if (new_accounts > 1 && new_accounts <= MAX_ACCOUNTS)
            {
                cout << "Closing account #" << new_accounts << endl;

                new_accounts = close_account(new_accounts, accounts);
                print_accounts(new_accounts, accounts);
            }
            else if (new_accounts == 1)
            {
                cout << "Withdrawal money manualy." << endl;
                cout << endl;
            }
            else
            {
                cout << "Account number is invalid." << endl;
                cout << endl;
            }
            break;
        case 0:
            done = true;
            break;
        default:
            break;
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
    cout << "4. Print balance for all accounts" << endl;
    cout << endl;
    cout << "5. Open new account" << endl;
    cout << endl;
    cout << "6. Close account" << endl;
    cout << endl;
    cout << "0. Exit" << endl;
    cout << endl;
}

void print_accounts(int max, int accounts[])
{
    cout << "-----------------------------------------------------------" << endl;
    for (int i = 0; i < max; i++)
    {
        cout << "Account #" << (i + 1) << " = " << accounts[i] << "$" << fixed << setprecision(2) << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;
}

int account_check(int account_number)
{
    cout << "What account you want to check balance?" << endl;
    cout << "Enter account number: " << endl;

    int input = 0;
    cin >> input;

    if (input >= 1 && input <= 5)
    {
        return input;
    }
    else 
    {
        cout << "Account number does not exists." << endl;
        return -1;
    }
}

void balance_check(int index, int accounts[])
{   
    cout << "-----------------------------------------------------------" << endl;
    cout << "Your current balance on account #" << index + 1 << " is: " << accounts[index] << "$" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << endl;
}

void deposite(float amount, int index, int accounts[])
{
    if (amount > 0)
    {
        accounts[index] += amount;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Your new balance on account #" << index + 1 << " is: " << accounts[index] << "$" << endl;
        cout << "-----------------------------------------------------------" << endl;
    }
    else 
    {
        cout << "Invalid deposite amount." << endl;
    }
}

void withdrawal(float amount, int index, int accounts[])
{
    float temp_balance = accounts[index];
    if (amount > 0)
    {
        accounts[index] -= amount;

        if (amount > accounts[index])
        {
            insufficient_funds(accounts[index], amount);
            accounts[index] = temp_balance;
            return;
        }

        cout << "-----------------------------------------------------------" << endl;
        cout << "Your new balance on account #" << index + 1 << " is: " << accounts[index] << "$" << endl;
        cout << "-----------------------------------------------------------" << endl;
    }
    else 
    {
        cout << "Invalid withdrawal amount." << endl;
    }
}

void insufficient_funds(float balance, float amount)
{
    float possible_amount = (balance * -1) + 1;
    cout << endl;
    cout << "If you will do this transaction." << endl;
    cout << "Your funds drop to " << balance << "$." << endl;
    cout << endl;
    cout << "Considering withdrawing " << possible_amount << "$ less" << endl;
    cout << endl;
}

int open_account(int new_accounts, int accounts[])
{
    new_accounts++;
    accounts[new_accounts] = 0;
    return new_accounts;
}

int close_account(int new_accounts, int accounts[])
{
    int old_accounts_number = new_accounts - 1;
    cout << endl;
    cout << "Current balance is " << accounts[old_accounts_number] << "$ " << fixed << setprecision(2) << endl;
    cout << endl;
    cout << "What account do you want to move money to (Accounts 1 - " << old_accounts_number << ")" << endl;

    int new_account_number;
    cin >> new_account_number;//2

    int new_index = new_account_number - 1;

    cout << "Account #" << new_account_number << " balance is " << fixed << setprecision(2) << accounts[new_index] << "$" << endl;
    cout << "Adding " << fixed << setprecision(2) << accounts[old_accounts_number] << "$" << endl;
    accounts[new_index] += accounts[old_accounts_number];

    return new_account_number;
}