#include <iostream>

bool check_pin (int input, int pin);
void print_menu ();
void balance_check (int balance);

int main ()
{
    int pin = 4311;
    bool is_correct = false;
    int input = 0;
    int option = 0;
    int balance = 10000;

    do
    {
        is_correct = check_pin(input, pin);
        
    } while (!is_correct);

    print_menu();
    std::cin >> option;

    switch (option)
    {
    case 1:
        balance_check(balance);
        break;    
    default:
        break;
    }
}

bool check_pin (int input, int pin)
{
    std::cout << "Enter your pin: ";
    std::cin >> input;

    if (input == pin)
    {
        std::cout << "***** Login successful. *****" << std::endl;
        std::cout << std::endl;
        std::cout << "***** Welcome to Bank of America. *****" << std::endl;
        std::cout << std::endl;

        return true;
    }
    else 
    {
        std::cout << "Pin is incorrect." << std::endl;
        return false;
    }
}

void print_menu ()
{
    std::cout << "***** Menu *****" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Check balance" << std::endl;
    std::cout << std::endl;
    std::cout << "2. Deposite money" << std::endl;
    std::cout << std::endl;
    std::cout << "3. Withdrawal money" << std::endl;
    std::cout << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << std::endl;
}

void balance_check (int balance)
{
    std::cout << "Your current balance is: " << balance << std::endl;
}