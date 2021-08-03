// Bank Management System Code (in C++)

// Header Files
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

class Bank
{
private:
    string username, password;
    string username1, password1;
    int total;

    // Stores the basic data of the user
    struct person
    {
        string name, email, ID;
        float cash;
        long long int contact;
    } person[100];

public:
    // Constructor
    Bank()
    {
        total = 0;
    }

    void choice();
    void start();
    void signUp();
    void login();
    void Data();
    void show();
    void update();
    void search();
    void transactions();
    void del();
};

// MAIN
int main()
{
    Bank b;

    b.start();
    b.signUp();
    b.login();
}

// Function to input choice of the user
void Bank ::choice()
{
    char ch;

    // to run the code infinite times till the user press exit
    while (true)
    {
        cout << "\n\nPRESS..!!" << endl;
        cout << "1. Create new account" << endl;
        cout << "2. View customers list" << endl;
        cout << "3. Update information of existing account" << endl;
        cout << "4. Check the details of an existing account" << endl;
        cout << "5. For transactions" << endl;
        cout << "6. Remove existing account" << endl;
        cout << "7. Exit" << endl;

        // to take a character from the user
        ch = getch();

        // Clear screen command to clear screen after each menu iteration
        system("ClS");

        // Switch Menu
        switch (ch)
        {
        case '1':
            Bank ::Data();
            break;

        case '2':
            if (total == 0)
                cout << "No data is entered !!" << endl;
            else
                Bank ::show();
            break;

        case '3':
            if (total == 0)
                cout << "No data is entered !!" << endl;
            else
                Bank ::update();
            break;

        case '4':
            if (total == 0)
                cout << "No data is entered !!" << endl;
            else
                Bank ::search();
            break;

        case '5':
            if (total == 0)
                cout << "No data is entered !!" << endl;
            else
                Bank ::transactions();
            break;

        case '6':
            if (total == 0)
                cout << "No data is entered !!" << endl;
            else
                Bank ::del();
            break;

        case '7':
            exit(0);
            break;

        default:
            cout << "\aInvalid input" << endl;
            break;
        }
    }
}

// to display the heading of the project
void Bank ::start()
{
    char arr[] = {'B', 'A', 'N', 'K', ' ', 'M', 'A', 'N', 'A', 'G', 'E', 'M', 'E', 'N', 'T', ' ', 'S', 'Y', 'S', 'T', 'E', 'M'};
    cout << "\n\n\n\n\n\t\t\t";

    for (int i = 0; i < 24; i++)
    {
        cout << arr[i];

        // time in milliseconds
        Sleep(50);
    }

    // time in milliseconds
    Sleep(2000);

    // to clear screen
    system("CLS");
}

// Function used for signing up a user
void Bank ::signUp()
{
    cout << "\n\n\t\tBANK MANAGEMENT SYSTEM\n"
         << endl;
    cout << "\n\t\t  SIGN UP\n"
         << endl;

    cout << "\t\tEnter Username: ";
    cin >> username;

    cout << "\t\tEnter Password: ";
    cin >> password;

    cout << "\t\tYour new id is creating please wait";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";

        // time in milliseconds
        Sleep(1000);
    }
}

// Function used to login a user
void Bank ::login()
{
    system("CLS");
    cout << "\n\n\t\t LOGIN\n"
         << endl;

    cout << "\t\tEnter Username: ";
    cin >> username1;

    cout << "\t\tEnter Password: ";
    cin >> password1;

    if (username == username1 && password == password1)
    {
        // to clear screen
        system("CLS");

        Bank::choice();
    }

    else if (username != username1 && password == password1)
    {
        cout << "\t\t\aInvalid username please try again";

        // time in milliseconds
        Sleep(3000);

        Bank::login();
    }

    else if (username == username1 && password != password1)
    {
        cout << "\t\t\aInvalid password please try again";

        // time in milliseconds
        Sleep(3000);

        Bank::login();
    }

    else
    {
        cout << "\t\t\aInvalid username and password please try again";

        // time in milliseconds
        Sleep(3000);

        Bank::login();
    }
}

// Function to enter the data of the user
void Bank ::Data()
{
    cout << "\nEnter data of person" << endl
         << endl;
    cout << "Enter Name: ";
    cin >> person[total].name;
    cout << "Enter ID: ";
    cin >> person[total].ID;
    cout << "Enter Contact: ";
    cin >> person[total].contact;
    cout << "Enter Email: ";
    cin >> person[total].email;
    cout << "Enter Cash: ";
    cin >> person[total].cash;
    total++;
}

// Function to display the details of a user
void Bank ::show()
{
    for (int i = 0; i < total; i++)
    {
        cout << "\nData of person " << i + 1 << endl;
        cout << "Name: " << person[i].name << endl;
        cout << "ID: " << person[i].ID << endl;
        cout << "Contact: " << person[i].contact << endl;
        cout << "Email: " << person[i].email << endl;
        cout << "Cash: " << person[i].cash << endl;
    }
}

// Function to update the details of a user
void Bank ::update()
{
    string id;

    cout << "Enter ID of person for update" << endl;
    cin >> id;

    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            // Previous data
            cout << "\nPrevious data of person " << i + 1 << endl;
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Email: " << person[i].email << endl;
            cout << "Cash: " << person[i].cash << endl;

            // New data
            cout << "\nEnter new data" << endl
                 << endl;
            cout << "Enter Name: ";
            cin >> person[i].name;
            cout << "Enter ID: ";
            cin >> person[i].ID;
            cout << "Enter Contact: ";
            cin >> person[i].contact;
            cout << "Enter Email: ";
            cin >> person[i].email;
            cout << "Enter Cash: ";
            cin >> person[i].cash;
            cout << "Your required data is updated" << endl;
            break;
        }

        // if any invalid input is given
        if (i == total - 1)
        {
            cout << "No such record found" << endl;
        }
    }
}

// Function to search the details of a user
void Bank ::search()
{
    string id;

    cout << "Enter ID of person for check" << endl;
    cin >> id;

    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            cout << "\nData of person " << i + 1 << endl;
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Email: " << person[i].email << endl;
            cout << "Cash: " << person[i].cash << endl;
            break;
        }

        // if any invalid input is given
        if (i == total - 1)
        {
            cout << "No such record found" << endl;
        }
    }
}

// Function used for transactions of the user
void Bank ::transactions()
{
    string id;
    char ch;
    int cash;

    cout << "Enter id of person which you want to transaction" << endl;
    cin >> id;

    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Email: " << person[i].email << endl;
            cout << "\nExisting Cash " << person[i].cash << endl;
            cout << "\nPress 1 to deposit cash" << endl;
            cout << "Press 2 to withdraw cash" << endl;
            cout << endl;

            // to take a character from the user
            ch = getch();

            // Switch Menu
            switch (ch)
            {
            case '1':
                cout << "Enter cash which you want to deposit: " << endl;
                cin >> cash;

                person[i].cash += cash;
                cout << "New amount is " << person[i].cash << endl;
                break;

            case '2':
            back:
                cout << "Enter cash which you want to withdraw: " << endl;
                cin >> cash;

                if (cash > person[i].cash)
                {
                    cout << "Your existing cash is just Rupees " << person[i].cash << endl;

                    // time in milliseconds
                    Sleep(3000);

                    // Used for unconditional jump
                    goto back;
                }

                person[i].cash -= cash;
                cout << "New amount is " << person[i].cash << endl;
                break;

            default:
                cout << "\aInvalid Input" << endl;
                break;
            }

            break;
        }

        // if any invalid input is given
        if (i == total - 1)
        {
            cout << "No such record found" << endl;
        }
    }
}

// Function to delete the data of a user
void Bank ::del()
{
    if (total != 0)
    {
        char ch;

        cout << "Press 1 to remove a specific record" << endl;
        cout << "Press 2 to remove full record" << endl;

        // to take a character from the user
        ch = getch();

        // to remove a specific record
        if (ch == '1')
        {
            string id;

            cout << "Enter id of person which you want to remove " << endl;
            cin >> id;

            for (int i = 0; i < total; i++)
            {
                if (id == person[i].ID)
                {
                    // it will override the current data with the data of the next user
                    for (int j = i; j < total; j++)
                    {
                        person[j].name = person[j + 1].name;
                        person[j].ID = person[j + 1].ID;
                        person[j].email = person[j + 1].email;
                        person[j].contact = person[j + 1].contact;
                        person[j].cash = person[j + 1].cash;
                        total--;
                        cout << "Your required record is deleted !!" << endl;
                        break;
                    }
                }

                // if any invalid input is given
                if (i == total - 1)
                {
                    cout << "No such record found !!" << endl;
                }
            }
        }

        // to remove full record
        else if (ch == '2')
        {
            total = 0;
            cout << "All record is deleted" << endl;
        }

        // if any invalid input is given
        else
        {
            cout << "\aInvalid Input" << endl;
        }
    }

    else
    {
        cout << "No data is entered" << endl;
    }
}
