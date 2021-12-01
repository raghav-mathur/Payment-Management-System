
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <ctime>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

// Account Login
int valid_username(char username[17]);
int existing_username(char username[17]);
int existing_username_create(char username[17]);

class paymentSystem
{
public:
    // Dashboard
    int check_amount(float);
    void buy_tickets();
    void pay_bills();
    void deposit();
    void check_balance();

    // Account Management
    void create_account();
    void delete_account();
    void change_password();

    // Password: pass123
    void account_list();
    void sort_accounts();
};
// Account Class

class account
{
private:
    // Account Login
    char account_username[17];
    int account_password;
    // Owner Details
    char f_name[20];
    char l_name[20];
    // Balance
    float balance;

public:
    account();
    char* return_username();
    float return_balance();
    int check_password(int);
    void in();
    void out();
    void deposit(float amount);
    void withdraw(float amount);
    int sufficient_balance(float amount);
    void change_password(int new_password);
};
// Constructor
account::account()
{
    strcpy(account_username,"000000000000");
    account_password = 0;
    strcpy(f_name, "NULL");
    strcpy(l_name, "NULL");
    balance = 0;
}

// Returns username
char* account::return_username()
{
    return account_username;
}

// Returns Account Balance
float account::return_balance()
{
    return balance;
}

// Authorizes Account
int account::check_password(int password)
{
    if (account_password == password)
    {
        cout << "\nAuthorized!\n \n";
        return 1;
    }
    else
    {
        cout << "\nIncorrect password. Please try again\n";
        return 0;
    }
}

// Create New Account
void account::in()
{
    cout << "Enter your first name: ";
    cin >> f_name;
    cout << "Enter your last name: ";
    cin >> l_name;

    cout << "\nEnter a username (12 characters): ";
    cin >> account_username;

    // username Validity Check
    if (!valid_username(account_username))
    {
        exit(0);
    }

    if (existing_username_create(account_username))
    {
        exit(0);
    }

    cout << "\nEnter your 4 digit account password: ";
    cin >> account_password;
}

// Output Account Details
void account::out()
{
    cout << account_username << endl;
    cout << "First name: " << f_name << endl;
    cout << "Last name: " << l_name << endl;
    cout << "password: " << account_password << endl;
    cout << "Balance: " << balance << endl << endl;
}

void account::deposit(float amount)
{
    balance += amount;
}

void account::withdraw(float amount)
{
    balance -= amount;
}

// Checks if Withdrawal is allowed
int account::sufficient_balance(float amount)
{
    if (balance >= amount)
    {
        return 1;
    }
    cout << "\nERROR: Insufficient Funds\n";
    return 0;
}

void account::change_password(int new_password)
{
    account_password = new_password;
}

int main()
{
    //remove("accounts.dat");
    fflush(stdin);
    int choice;
    paymentSystem q;
    while (1)
    {
        cout<<"Welcome to Qpay payment solutions!"<<endl;
        // Menu
        cout << "\n\t1. Buy tickets"
             << "\n\t2. Deposit Money"
             << "\n\t3. Check Balance"
             << "\n\t4. Pay Bills"
             << "\n\t5. Create New Account"
             << "\n\t6. Delete Existing Account"
             << "\n\t7. Change Account Password"
             << "\n\t8. List all Accounts"
             << "\n\t9. Sort all Accounts"
             << "\n\t10. Exit";

        cout << "\n\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            system("CLS");
            cout<<"BUYING TICKETS"<<endl<<endl;
            q.buy_tickets();
            cout<<endl<<"Tickets have ben purchased. \n Thank you for buying tickets!"<<endl;
            cout<<"Press \"R\" to return."<<endl;
            char p;
            cin>>p;
            if(p=='R'||p=='r')
                system("CLS");
        }
        else if (choice == 2) {
            system("CLS");
            cout<<"DEPOSITING MONEY"<<endl<<endl;
            q.deposit();
            cout<<endl<<"Money has been deposited!"<<endl;
            cout<<"Press \"R\" to return."<<endl;
            char p;
            cin>>p;
            if(p=='R'||p=='r')
                system("CLS");
        }
        else if (choice == 3){
            system("CLS");
            cout<<"CHECKING BALANCE"<<endl<<endl;
            q.check_balance();
            cout<<"Press \"R\" to return."<<endl;
            char p;
            cin>>p;
            if(p=='R'||p=='r')
                system("CLS");
        }
        else if (choice == 4){
            system("CLS");
            cout<<"PAYING BILLS"<<endl<<endl;
            q.pay_bills();
            cout<<"Press \"R\" to return."<<endl;
            char p;
            cin>>p;
            if(p=='R'||p=='r')
                system("CLS");
        }
        else if (choice == 5){
            system("CLS");
            cout<<"CREATING NEW ACCOUNT"<<endl<<endl;
            q.create_account();
            cout<<"Your accounts has been created. \n Thank you for creating an account!"<<endl;
            cout<<"Press \"R\" to return."<<endl;
            char p;
            cin>>p;
            if(p=='R'||p=='r')
                system("CLS");
        }
        else if (choice == 6){
            system("CLS");
            cout<<"DELETING ACCOUNT"<<endl<<endl;
            q.delete_account();
            cout<<"We're sad to see you go. Hope you return soon!"<<endl;
            cout<<"Press \"R\" to return."<<endl;
            char p;
            cin>>p;
            if(p=='R'||p=='r')
                system("CLS");
        }
        else if (choice == 7){
            system("CLS");
            cout<<"CHANGING ACCOUNT PASSWORD"<<endl<<endl;
            q.change_password();
            cout<<"Your password has been changed!"<<endl;
            cout<<"Press \"R\" to return."<<endl;
            char p;
            cin>>p;
            if(p=='R'||p=='r')
                system("CLS");
        }
        else if (choice == 8){
            system("CLS");
            cout<<"LISTING ALL ACCOUNTS (ADMIN ONLY)"<<endl<<endl;
            q.account_list();
            cout<<"Press \"R\" to return."<<endl;
            char p;
            cin>>p;
            if(p=='R'||p=='r')
                system("CLS");
        }
        else if (choice == 9) {
            system("CLS");
            cout<<"SORTING ALL ACCOUNTS (ADMIN ONLY)"<<endl<<endl;
            q.sort_accounts();
            cout<<"\n Accounts have been sorted. Please enter Admin password again to display all accounts"<<endl;
            q.account_list();
            cout<<"Press \"R\" to return."<<endl;
            char p;
            cin>>p;
            if(p=='R'||p=='r')
                system("CLS");
        }
        // Exits Menu
        else if (choice == 10)
        {
            cout << "\nProgram successfully terminated\n";
            break;
        }
        else
            cout << "\nInvalid Choice\n";
    }

    return 0;
}

// Valid username Check
int valid_username(char username[17])
{
    if (strlen(username)!=12)
    {
        cout << "\nERROR: Only 12 Digits allowed\n";
        return 0;
    }

    return 1;
}

// Existing username Check (During Account Authorization)
int existing_username(char username[17])
{
    ifstream f("accounts.dat", ios::binary);
    account a;

    while (f.read((char*)(&a),sizeof(account)))
    {
        if (!strcmp(a.return_username(),username))
        {
            f.close();
            return 1;
        }
    }

    cout << "\nERROR: Account Doesn't Exist.\n";
    f.close();
    return 0;
}

// Existing username Check (During Account Creation)
int existing_username_create(char username[17])
{
    ifstream f("accounts.dat", ios::binary);
    account a;

    while (f.read((char*)(&a),sizeof(account)))
    {
        if (strcmp(a.return_username(),username)==0)
        {
            cout << "\nERROR: username Taken.\n";
            f.close();
            return 1;
        }
    }

    f.close();
    return 0;
}

// Valid Withdrawal Amount (Not Negative, Not Zero)
int paymentSystem::check_amount(float amount)
{
    if (amount > 0)
    {
        return 1;
    }
    if (amount == 0)
    {
        cout << "\nERROR: Amount Cannot Be Zero\n";
        return 0;
    }

    cout << "\nERROR: Amount Cannot Be Negative\n";
    return 0;
}

void paymentSystem::deposit()
{
    fstream f("accounts.dat", ios::binary | ios::in | ios::out | ios::ate);
    f.seekg(0);

    account a;

    char account_username[17];
    int account_password;

    cout << "\nEnter your 12 digit username: ";
    cin >> account_username;

    // username Validity Check
    if (!valid_username(account_username))
    {
        f.close();
        return;
    }

    if (!existing_username(account_username))
    {
        f.close();
        return;
    }

    cout << "\nEnter your 4 digit account password: ";
    cin >> account_password;

    while (f.read((char*)(&a),sizeof(account)))
    {
        if (!strcmp(a.return_username(), account_username))
        {
            if(!a.check_password(account_password))
            {
                f.close();
                return;
            }
            break;
        }
    }

    float amount;
    int x = -1*sizeof(account);

    cout << "\nEnter amount to deposit: ";
    cin >> amount;

    if (!check_amount(amount))
    {
        f.close();
        return;
    }

    // Make Changes to Object
    a.deposit(amount);

    a.out();

    // Make Changes to File
    f.seekp(x,ios::cur);
    f.write((char*)(&a),sizeof(account));

    f.close();
}

void paymentSystem::buy_tickets()
{
    fstream f("accounts.dat", ios::binary | ios::in | ios::out | ios::ate);
    f.seekg(0);

    account a;

    char account_username[17];
    int account_password;

    cout << "\nEnter your 12 digit username: ";
    cin >> account_username;

    // username Validity Check
    if (!valid_username(account_username))
    {
        f.close();
        return;
    }

    if (!existing_username(account_username))
    {
        f.close();
        return;
    }

    cout << "\nEnter your 4 digit account password: ";
    cin >> account_password;

    while (f.read((char*)(&a),sizeof(account)))
    {
        if (!strcmp(a.return_username(), account_username))
        {
            if(!a.check_password(account_password))
            {
                f.close();
                return;
            }
            break;
        }
    }

    float amount;
    int category,num;
    int x = -1*sizeof(account);

    cout<<"How many tickets? \n";
    cin>>num;

    cout << "\nEnter category of ticket you want to book \n 1. 250/- for front row seats \n 2. 500/- for upper row seats \n 3. 1000/- for balcony seats \n ";
    cin>>category;
    if(category==1)
        amount=250*num;
    if(category==2)
        amount=500*num;
    if(category==3)
        amount=1000*num;
    cout << endl;


    if (!a.sufficient_balance(amount))
    {
        f.close();
        return;
    }

    // Make Changes to Object
    a.withdraw(amount);

    a.out();

    // Make Changes to File
    f.seekp(x,ios::cur);
    f.write((char*)(&a),sizeof(account));

    f.close();
}

void paymentSystem::pay_bills()
{
       fstream f("accounts.dat", ios::binary | ios::in | ios::out | ios::ate);
    f.seekg(0);

    account a;

    char account_username[17];
    int account_password;

    cout << "\nEnter your 12 digit username: ";
    cin >> account_username;

    // username Validity Check
    if (!valid_username(account_username))
    {
        f.close();
        return;
    }

    if (!existing_username(account_username))
    {
        f.close();
        return;
    }

    cout << "\nEnter your 4 digit account password: ";
    cin >> account_password;

    while (f.read((char*)(&a),sizeof(account)))
    {
        if (!strcmp(a.return_username(), account_username))
        {
            if(!a.check_password(account_password))
            {
                f.close();
                return;
            }
            break;
        }
    }

    float amount;
    int category;
    int x = -1*sizeof(account);



    cout << "\nEnter category of ticket you want to book \n 1. Credit Card Bill \n 2. Electricity Bill \n 3. Water bill \n ";
    cin>>category;

    cout<<"What is the amount of the bill?"<<endl;
    cin>>amount;
    cout << endl;


    if (!a.sufficient_balance(amount))
    {
        f.close();
        return;
    }

    // Make Changes to Object
    a.withdraw(amount);

    a.out();

    // Make Changes to File
    f.seekp(x,ios::cur);
    f.write((char*)(&a),sizeof(account));

    f.close();
}


void paymentSystem::check_balance()
{
    fstream f("accounts.dat", ios::binary | ios::in);
    f.seekg(0);

    account a;

    char account_username[17];
    int account_password;

    cout << "\nEnter your 12 digit username: ";
    cin >> account_username;

    // username Validity Check
    if (!valid_username(account_username))
    {
        f.close();
        return;
    }

    if (!existing_username(account_username))
    {
        f.close();
        return;
    }

    cout << "\nEnter your 4 digit account password: ";
    cin >> account_password;

    while (f.read((char*)(&a),sizeof(account)))
    {
        if (!strcmp(a.return_username(), account_username))
        {
            if(!a.check_password(account_password))
            {
                f.close();
                return;
            }
            break;
        }
    }

    // Output Remaining Balance
    cout << "\nYour balance is " << a.return_balance() << " rupees.\n";

    f.close();
}

void paymentSystem::create_account()
{
    fstream f("accounts.dat", ios::binary | ios::app | ios::out);
    account a;

    // Input New Account Details
    cout << endl;
    a.in();

    // Appends New Account Details to File
    f.write((char*)(&a),sizeof(account));
    f.close();
}

void paymentSystem::delete_account()
{
    fstream f("accounts.dat", ios::binary | ios::in);
    f.seekg(0);

    account a;

    char account_username[17];
    int account_password;

    cout << "\nEnter your 12 digit username: ";
    cin >> account_username;

    // username Validity Check
    if (!valid_username(account_username))
    {
        f.close();
        return;
    }

    if (!existing_username(account_username))
    {
        f.close();
        return;
    }

    cout << "\nEnter your 4 digit account password: ";
    cin >> account_password;

    f.seekg(0);

    while (f.read((char*)(&a),sizeof(account)))
    {
        if (!strcmp(a.return_username(), account_username))
        {
            if(!a.check_password(account_password))
            {
                f.close();
                return;
            }
            break;
        }
    }

    char c;

    cout << "\nAre you sure you want to delete your account? all your balance will be lost.";
    cout << "\nEnter y to confirm: ";
    cin >> c;

    if (c != 'y')
    {
        f.close();
        return;
    }

    fstream g("temp.dat", ios::binary | ios::out);

    f.seekg(0);

    // Output all But Account to Delete to New File
    while (f.read((char*)(&a),sizeof(account)))
    {
        if (strcmp(a.return_username(), account_username))
        {
            g.write((char*)(&a),sizeof(account));
        }
    }

    f.close();
    g.close();

    cout << "\nAccount Deleted\n";

    remove("accounts.dat");
    rename("temp.dat","accounts.dat");
}

void paymentSystem::change_password()
{
    fstream f("accounts.dat", ios::binary | ios::in | ios::out | ios::ate);
    f.seekg(0);

    account a;

    char account_username[17];
    int account_password;

    cout << "\nEnter your 12 digit username: ";
    cin >> account_username;

    // username Validity Check
    if (!valid_username(account_username))
    {
        f.close();
        return;
    }

    if (!existing_username(account_username))
    {
        f.close();
        return;
    }

    cout << "\nEnter your (current) 4 digit account password: ";
    cin >> account_password;

    while (f.read((char*)(&a),sizeof(account)))
    {
        if (!strcmp(a.return_username(), account_username))
        {
            if(!a.check_password(account_password))
            {
                f.close();
                return;
            }
            break;
        }
    }

    int new_password;
    int x = -1*sizeof(account);

    cout << "\nEnter your new 4 digit account password: ";
    cin >> new_password;

    // Modify Object
    a.change_password(new_password);

    // Write Modified Object to File
    f.seekp(x,ios::cur);
    f.write((char*)(&a),sizeof(account));

    cout << "\npassword Successfully Changed\n";

    f.close();
}

void paymentSystem::account_list()
{
    char password[20];

    // Password: XINO
    cout << "\nEnter Administrator Password: ";
    cin >> password;

    if (strcmp(password, "pass123"))
    {
        cout << "\nERROR: Incorrect Administrator Password\n";
        return;
    }

    ifstream f("accounts.dat", ios::binary);
    account a;

    cout << endl;

    // Output
    while (f.read((char*)(&a),sizeof(account)))
    {
        a.out();
    }

    f.close();
}

void paymentSystem::sort_accounts()
{
    char password[20];

    // Password: XINO
    cout << "\nEnter Administrator Password: ";
    cin >> password;

    if (strcmp(password, "XINO"))
    {
        cout << "\nERROR: Incorrect Administrator Password\n";
        return;
    }

    ifstream f("accounts.dat", ios::binary);
    int num = 0;
    account a[100];
    account temp;

    // Take File Data in Array of Objects
    while (f.read((char*)(&a[num++]),sizeof(account)))

    // Bubble Sort Array
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (a[j].return_balance() < a[j+1].return_balance())
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    fstream g("temp.dat", ios::binary | ios::out);

    // Output Sorted Array to New File
    for (int i = 0; i < num - 1; i++)
    {
        g.write((char*)(&a[i]),sizeof(account));
    }

    f.close();
    g.close();

    remove("accounts.dat");
    rename("temp.dat","accounts.dat");
}
