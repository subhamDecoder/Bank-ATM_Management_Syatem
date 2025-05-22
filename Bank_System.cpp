#include <algorithm> // For functions like sort, transform
#include <cctype>    // For character functions like isdigit, isalpha
#include <vector>    // For using vector container (not used yet, maybe future use)
#include <iostream>  // For input/output streams
#include <windows.h> // For Windows-specific functions (like system calls)
#include <fstream>   // For file handling (ifstream, ofstream, fstream)
#include <iomanip>   // For formatted output (like setw, setprecision)
#include <sstream>   // For string stream manipulations
#include <string>    // For using the string class
#include <ctime>     // For time-related functions (e.g., time stamps)
#include <conio.h>   // For getch() - reading characters without Enter
#include <cstdlib>   // For exit() function
using namespace std;

class bank
{
private:
    int pin;               // User PIN (possibly used in future)
    float balance;         // Balance of a user
    string id, pass, name; // ID, password, and name of user
    string address, phone; // Address and phone number of user

public:
    // Member function declarations
    void menu();            // Main menu
    void bank_management(); // Admin-side menu
    void atm_management();  // ATM-side menu

    // Bank management options
    void new_user();    // Add new user
    void old_user();    // Access old user info
    void deposite();    // Deposit funds
    void withdraw();    // Withdraw funds
    void transfer();    // Transfer money to another account
    void payment();     // Make payment to a user
    void search_user(); // Search user by ID
    void edit_user();   // Edit user details
    void delete_user(); // Delete a user account
    void show_all();    // Display all user accounts
    void payment_all(); // Send payment to all users

    // ATM options
    void user_balance(); // Check balance via ATM
    void atm_withdraw(); // Withdraw via ATM
};

void bank::menu()
{
    const string correct_email = "desubham55@gmail.com"; // Hardcoded admin email
    const string correct_pin = "200208";                 // Hardcoded admin PIN
    const string correct_pass = "subham";                // Hardcoded admin password

    while (true) // Infinite loop for menu
    {
        system("cls"); // Clear the screen (Windows only)
        int choice;
        string pin, pass, email;

        // Display options
        cout << "\n\n\t\t\tControl Panel" << endl;
        cout << "\n 1. Bank Management" << endl;
        cout << "\n 2. ATM Management" << endl;
        cout << "\n 3. Exit" << endl;
        cout << "\n\n Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls"); // Clear screen for login
            cout << "\n\n\t\t\tLogin Account" << endl;
            cout << "\n E-mail: ";
            cin >> email;
            cout << "\n Pin Code (6 digits): ";
            cin >> pin;
            cout << "\n Password (6 characters): ";
            cin >> pass;

            // Check login credentials
            if (email == correct_email && pin == correct_pin && pass == correct_pass)
            {
                cout << "\n\n Login Successful!\n";
                bank_management(); // Enter bank management system
            }
            else
            {
                cout << "\n\n Login Failed... Please Try Again.\n";
            }
            break;
        }

        case 2:
            system("cls");
            atm_management(); // Enter ATM management system
            break;

        case 3:
            exit(0); // Exit program

        default:
            cout << "\n\n Invalid Value... Please Try Again.\n";
        }

        system("pause"); // Pause before showing menu again
    }
}

void bank::bank_management()
{
    while (true) // Infinite loop for menu
    {
        system("cls");
        int choice;
        cout << "\n\n\t\t\t Bank Management System";
        cout << "\n 1. New User";        // Create new user
        cout << "\n 2. Old User";        // Access old user account
        cout << "\n 3. Deposite Option"; // Deposit money
        cout << "\n 4. Withdraw Option"; // Withdraw money
        cout << "\n 5. Transfer Money";  // Transfer money
        cout << "\n 6. Make Payment";    // Make a payment
        cout << "\n 7. Search User";     // Search for a user
        cout << "\n 8. Edit User";       // Edit user info
        cout << "\n 9. Delete User";     // Delete user account
        cout << "\n 10. Show All Users"; // Display all users
        cout << "\n 11. Payment to All"; // Send payment to all users
        cout << "\n 12. Go Back";        // Return to main menu
        cout << "\n\n Enter Your Choice: ";
        cin >> choice;

        // Handle user choice
        switch (choice)
        {
        case 1:
            new_user();
            break;
        case 2:
            old_user();
            break;
        case 3:
            deposite();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transfer();
            break;
        case 6:
            payment();
            break;
        case 7:
            search_user();
            break;
        case 8:
            edit_user();
            break;
        case 9:
            delete_user();
            break;
        case 10:
            show_all();
            break;
        case 11:
            payment_all();
            break;
        case 12:
            return; // Go back to previous menu
        default:
            cout << "\n\n Invalid Value... Please Try Again.\n";
        }

        system("pause"); // Pause before redisplaying the menu
    }
}

void bank::atm_management()
{
    while (true)
    {
        system("cls");
        int choice;
        cout << "\n\n\t\t\t ATM Management System";
        cout << "\n 1. User Login & Check Balance"; // Option to login and see balance
        cout << "\n 2. Withdraw Amount";            // Withdraw money
        cout << "\n 3. Go Back";                    // Return to previous menu
        cout << "\n\n Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            user_balance();
            break;
        case 2:
            atm_withdraw();
            break;
        case 3:
            return; // Exit atm_management()
        default:
            cout << "\n\n Invalid Value... Please Try Again.\n";
        }

        system("pause"); // Wait for user input before re-showing menu
    }
}

void bank::new_user()
{
    system("cls");
    // Clears the screen for a clean user interface

    fstream file;
    // Declare a file stream for file operations

    cout << "\n\n\t\t\tAdd New User";
    // Display heading

    cout << "\n\n User ID: ";
    cin >> id;
    // Take input for new user's ID
    cin.ignore();
    // Clear input buffer (in case of leftover newline from cin)

    cout << "\n\n Name: ";
    getline(cin, name);
    // Read full name including spaces

    cout << "\n\n Address Pin Code: ";
    getline(cin, address);
    // Read address (can contain spaces)

    // Validate numeric 5-digit password
    do
    {
        cout << "\n\n Password (5-digit numeric): ";
        cin >> pass;
        // Prompt user for a 5-digit password

        if (pass.length() != 5 || !all_of(pass.begin(), pass.end(), ::isdigit))
        {
            cout << "\n\n\t\tInvalid! Password must be exactly 5 numeric digits.\n";
            // Check that the password is exactly 5 digits and numeric
        }
        else
            break;
        // If valid, exit loop
    } while (true);
    // Repeat until a valid password is entered

    cout << "\n\n Phone No: ";
    cin >> phone;
    // Take phone number input

    cout << "\n\n Current Balance: ";
    cin >> balance;
    // Input the initial balance

    // Check for existing ID
    file.open("bank.txt", ios::in);
    // Open bank.txt for reading to check if ID already exists

    bool exists = false;
    if (file)
    {
        string line;
        while (getline(file, line))
        {
            if (line.find(id + " ") == 0)
            {
                exists = true;
                break;
                // If line starts with entered ID, set exists = true
            }
        }
        file.close();
        // Close file after reading
    }

    if (exists)
    {
        cout << "\n\n\tUser ID Already Exists...";
        getch();
        // Wait for key press
        return;
        // Exit function without saving
    }

    // Replace spaces in name with underscores for file consistency
    for (char &ch : name)
        if (ch == ' ')
            ch = '_';

    file.open("bank.txt", ios::app);
    // Open file in append mode to add new user details
    file << id << " " << name << " " << address << " " << pass << " " << phone << " " << balance << endl;
    // Write the user's data to the file in a space-separated format
    file.close();
    // Close the file

    cout << "\n\n Add New User Successfully!";
    getch();
    // Wait for user to press a key before continuing
}

void bank::old_user()
{
    system("cls");           // Clears the console.
    fstream file;            // Create file stream for reading user data.
    string i, n, a, pas, ph; // Temporary variables for user data.
    float bal;
    bool found = false;
    cout << "Enter User ID: ";
    cin >> id;

    file.open("bank.txt", ios::in); // Open file for reading.
    if (!file)
    {
        cout << "Error opening file!";
        return;
    }

    while (file >> i >> n >> a >> pas >> ph >> bal)
    {
        if (id == i)
        {
            found = true;
            // Convert underscore to space in name and address
            replace(n.begin(), n.end(), '_', ' ');
            replace(a.begin(), a.end(), '_', ' ');
            // Display user info
            cout << "User Name: " << n << "\n";
            cout << "Address: " << a << "\n";
            cout << "Phone No: " << ph << "\n";
            cout << "Balance: " << bal << "\n";
            break;
        }
    }
    file.close();

    if (!found)
        cout << "User ID Not Found!";
    getch(); // Wait for key press
}

void bank::deposite()
{
    // Clear the screen (Windows-specific command)
    system("cls");

    // Declare file streams for reading and writing
    fstream file, temp;

    // Variables to store user record fields
    string i, n, a, pas, ph; // i = ID, n = name, a = address, pas = password, ph = phone
    float bal;               // Current balance

    // Flag to check if user is found
    bool found = false;

    // Prompt for the user ID
    cout << "Enter User ID to Deposit: ";
    cin >> id; // `id` is a class-level variable

    // Open the main file for reading and a temporary file for writing
    file.open("bank.txt", ios::in);
    temp.open("temp.txt", ios::out);

    // If either file fails to open, show error and exit
    if (!file || !temp)
    {
        cout << "File error!";
        return;
    }

    // Read data line by line from the file
    while (file >> i >> n >> a >> pas >> ph >> bal)
    {
        // Check if the current record matches the entered ID
        if (id == i)
        {
            found = true; // Set the flag that user was found

            // Ask how much the user wants to deposit
            float amt;
            cout << "Enter amount to deposit: ";
            cin >> amt;

            // Add the deposit amount to current balance
            bal += amt;

            // Confirm the deposit to user
            cout << "Deposited successfully!";
        }

        // Write updated (or original) data to the temp file
        temp << i << " " << n << " " << a << " " << pas << " " << ph << " " << bal << "\n";
    }

    // Close both files
    file.close();
    temp.close();

    // Remove the original file
    remove("bank.txt");

    // Rename the temporary file to original file name
    rename("temp.txt", "bank.txt");

    // If user was not found, notify the user
    if (!found)
        cout << "User ID not found!";

    // Pause to let user see the output
    getch();
}

void bank::withdraw()
{
    // Clear the console screen (works only on Windows)
    system("cls");

    // Declare file streams
    fstream file, temp;

    // Declare variables to store user data
    string i, n, a, pas, ph; // i = ID, n = name, a = address, pas = password, ph = phone
    float bal, withdraw_amt; // bal = balance, withdraw_amt = amount to withdraw

    // Flag to check if user was found
    bool found = false;

    // Display header for withdraw section
    cout << "\n\n\t\t\tWithdraw Section";

    // Prompt user for their ID
    cout << "\n\n Enter User ID: ";
    cin >> id; // `id` is assumed to be a class-level variable

    // Open the original bank file for reading
    file.open("bank.txt", ios::in);

    // Open a temporary file for writing updated data
    temp.open("temp.txt", ios::out);

    // Check if files failed to open
    if (!file || !temp)
    {
        cout << "\n\n File Error!"; // Error message
        getch();                    // Pause for user to read
        return;                     // Exit the function
    }

    // Read each user record from the file
    while (file >> i >> n >> a >> pas >> ph >> bal)
    {
        // If the ID matches the entered ID
        if (i == id)
        {
            found = true; // Set flag to true

            // Ask how much to withdraw
            cout << "\n Enter Withdraw Amount: ";
            cin >> withdraw_amt;

            // Check if balance is sufficient
            if (withdraw_amt > bal)
            {
                cout << "\n\n Insufficient Balance!"; // Not enough money
            }
            else
            {
                bal -= withdraw_amt;                           // Deduct amount from balance
                cout << "\n\n Amount Withdrawn Successfully!"; // Confirmation
            }
        }

        // Write either updated or original data to temp file
        temp << i << " " << n << " " << a << " " << pas << " " << ph << " " << bal << endl;
    }

    // Close both file streams
    file.close();
    temp.close();

    // Delete the original file
    remove("bank.txt");

    // Rename temp file to original file name
    rename("temp.txt", "bank.txt");

    // If no user was found with the given ID
    if (!found)
        cout << "\n\n User ID Not Found...";

    // Pause so user can read the message
    getch();
}

void bank::transfer()
{
    // Clear the console screen (Windows-specific)
    system("cls");

    // File streams for reading original data and writing updated data
    fstream file, temp;

    // Variables for user input and reading file content
    string from_id, to_id;   // Sender and receiver user IDs
    string i, n, a, pas, ph; // Variables to read from file
    float bal, amount;       // Account balance and transfer amount
    bool from_found = false; // Flag to check if sender exists
    bool to_found = false;   // Flag to check if receiver exists

    // Display transfer prompt
    cout << "\n\n\t\t\tTransfer Amount";

    // Input: Sender's ID
    cout << "\n\n From User ID: ";
    cin >> from_id;

    // Input: Receiver's ID
    cout << "\n To User ID: ";
    cin >> to_id;

    // Input: Transfer amount
    cout << "\n Amount to Transfer: ";
    cin >> amount;

    // Open the original bank file for reading and a temp file for writing
    file.open("bank.txt", ios::in);
    temp.open("temp.txt", ios::out);

    // Check if files opened successfully
    if (!file || !temp)
    {
        cout << "\n\n File Error!";
        getch(); // Pause the screen
        return;  // Exit the function
    }

    // Read each line (record) from the original file
    while (file >> i >> n >> a >> pas >> ph >> bal)
    {
        // If this record matches the sender's ID
        if (i == from_id)
        {
            from_found = true; // Mark sender found

            // Check if sender has enough balance
            if (bal >= amount)
            {
                bal -= amount; // Deduct amount from sender
            }
            else
            {
                // Insufficient funds
                cout << "\n\n Insufficient Balance in Sender's Account!";

                // Still write the record unchanged
                temp << i << " " << n << " " << a << " " << pas << " " << ph << " " << bal << endl;
                continue; // Skip to next record
            }
        }
        // If this record matches the receiver's ID
        else if (i == to_id)
        {
            to_found = true; // Mark receiver found
            bal += amount;   // Add amount to receiver
        }

        // Write the (updated or unchanged) record to temp file
        temp << i << " " << n << " " << a << " " << pas << " " << ph << " " << bal << endl;
    }

    // Close both file streams
    file.close();
    temp.close();

    // Replace original file with updated temp file
    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    // Show result of the transfer
    if (from_found && to_found)
        cout << "\n\n Transfer Successful!";
    else
        cout << "\n\n Transfer Failed: One or Both Users Not Found.";

    // Wait for user input to pause screen
    getch();
}

void bank::payment()
{
    // Clear the console screen (Windows-only command)
    system("cls");

    // Declare file streams for reading from and writing to files
    fstream file, temp;

    // Declare variables for reading account data
    string i, n, a, pas, ph, billType;
    float bal, pay;
    bool found = false; // Flag to check if user exists

    // Display payment section
    cout << "\n\n\t\t\tMake a Payment";

    // Display bill type options
    cout << "\n\n Select Payment Type:";
    cout << "\n 1. Electricity";
    cout << "\n 2. DishTV";
    cout << "\n 3. Water Bill";
    cout << "\n 4. Internet";

    // Input: user selects a bill type
    cout << "\n Enter choice (1-4): ";
    int choice;
    cin >> choice;

    // Set bill type based on user selection
    switch (choice)
    {
    case 1:
        billType = "Electricity";
        break;
    case 2:
        billType = "DishTV";
        break;
    case 3:
        billType = "Water";
        break;
    case 4:
        billType = "Internet";
        break;
    default:
        // Invalid selection
        cout << "\n Invalid choice.";
        getch(); // Pause screen
        return;  // Exit function
    }

    // Ask for user ID and payment amount
    cout << "\n Enter User ID: ";
    cin >> id;

    cout << "\n Enter Payment Amount: ";
    cin >> pay;

    // Open existing account file and temporary file
    file.open("bank.txt", ios::in);
    temp.open("temp.txt", ios::out);

    // Read all records from file one by one
    while (file >> i >> n >> a >> pas >> ph >> bal)
    {
        // If user ID matches input
        if (i == id)
        {
            found = true; // Mark as found

            // Check for sufficient balance
            if (pay <= bal)
            {
                bal -= pay; // Deduct payment from balance
                cout << "\n Payment of Rs: " << pay << " for " << billType << " successful.";
            }
            else
            {
                // Not enough balance
                cout << "\n Insufficient Balance.";
            }
        }

        // Write (updated or unchanged) data to temp file
        temp << i << " " << n << " " << a << " " << pas << " " << ph << " " << bal << endl;
    }

    // Close files
    file.close();
    temp.close();

    // Replace original file with updated data
    remove("bank.txt");
    rename("temp.txt", "bank.txt");

    // If no matching user ID was found
    if (!found)
        cout << "\n\n User ID Not Found...";

    // Pause screen
    getch();
}

void bank::search_user()
{
    // Clear the console screen (only works on Windows)
    system("cls");

    // Declare file stream for reading data
    fstream file;

    // Variables to read each record from file
    string i, n, a, pas, ph;
    float bal;

    // Flag to check if user is found
    bool found = false;

    // Display search header
    cout << "\n\n\t\t\tSearch User";

    // Prompt user for ID to search
    cout << "\n\n Enter User ID: ";
    cin >> id; // `id` is assumed to be a class member variable

    // Open the bank data file for reading
    file.open("bank.txt", ios::in);

    // Read records one by one
    while (file >> i >> n >> a >> pas >> ph >> bal)
    {
        // If user ID matches
        if (i == id)
        {
            found = true; // Mark user as found

            // Display user details
            cout << "\nUser ID: " << i;
            cout << "\nName: " << n;
            cout << "\nAddress: " << a;
            cout << "\nPhone: " << ph;
            cout << "\nBalance: " << bal;
            break; // Exit loop since user is found
        }
    }

    // Close the file
    file.close();

    // If user ID wasn't found in the file
    if (!found)
        cout << "\n\n User ID Not Found...";

    // Pause screen
    getch();
}

void bank::edit_user() // Member function of the 'bank' class to edit user details
{
    system("cls"); // Clears the screen for a clean interface (platform-specific, works on Windows)

    fstream file, temp;      // Declare two file streams: 'file' for reading, 'temp' for writing
    string i, n, a, pas, ph; // Variables to hold user ID, name, address, password, and phone
    float bal;               // Variable to hold balance
    bool found = false;      // Flag to check if the user ID was found

    cout << "\n\n\t\t\tEdit User Record";   // Print heading
    cout << "\n\n Enter User ID to Edit: "; // Prompt for user ID
    cin >> id;                              // Input user ID to search for

    file.open("bank.txt", ios::in);  // Open the original file in input (read) mode
    temp.open("temp.txt", ios::out); // Open a temporary file in output (write) mode

    while (file >> i >> n >> a >> pas >> ph >> bal) // Read each record from file
    {
        if (i == id) // If current record matches the entered user ID
        {
            found = true; // Set flag to true

            // Display old user data
            cout << "\n\n\tOld User Account:\n";
            cout << "User ID: " << i << "\n";
            cout << "Name: " << n << "\n";
            cout << "Address: " << a << "\n";
            cout << "Password: " << pas << "\n";
            cout << "Phone: " << ph << "\n";
            cout << "Balance: " << bal << "\n";

            int choice; // Variable for user’s edit choice
            cout << "\nWhat would you like to edit?";
            cout << "\n 1. Name";
            cout << "\n 2. Address";
            cout << "\n 3. Password";
            cout << "\n 4. Phone";
            cout << "\nEnter your choice: ";
            cin >> choice; // Input user’s choice
            cin.ignore();  // Ignore leftover newline character to safely use getline()

            switch (choice) // Based on choice, update specific field
            {
            case 1:
                cout << "Enter New Name: ";
                getline(cin, n); // Input full name (can include spaces)
                break;
            case 2:
                cout << "Enter New Address: ";
                getline(cin, a); // Input full address
                break;
            case 3:
                cout << "Enter New Password: ";
                getline(cin, pas); // Input new password
                break;
            case 4:
                cout << "Enter New Phone: ";
                getline(cin, ph); // Input new phone number
                break;
            default:
                cout << "Invalid choice."; // Handle invalid input
                break;
            }

            // Show updated record for confirmation
            cout << "\n\n\tUpdated User Account:\n";
            cout << "User ID: " << i << "\n";
            cout << "Name: " << n << "\n";
            cout << "Address: " << a << "\n";
            cout << "Password: " << pas << "\n";
            cout << "Phone: " << ph << "\n";
            cout << "Balance: " << bal << "\n";
        }

        // Write the (possibly updated) record into the temp file
        temp << i << " " << n << " " << a << " " << pas << " " << ph << " " << bal << endl;
    }

    file.close(); // Close the original file
    temp.close(); // Close the temporary file

    remove("bank.txt");             // Delete the original file
    rename("temp.txt", "bank.txt"); // Rename the temp file to original file name

    if (found)
        cout << "\n\n Record Updated Successfully!"; // Success message
    else
        cout << "\n\n User ID Not Found..."; // Error message if ID wasn't found

    getch(); // Wait for user to press a key (used for pause in Windows; requires <conio.h>)
}

void bank::delete_user() // Member function of 'bank' class to delete a user
{
    system("cls"); // Clear the console screen for better user experience

    fstream file, temp;      // Declare file stream objects: 'file' for reading, 'temp' for writing
    string i, n, a, pas, ph; // Variables to store data read from file
    float bal;               // To hold balance
    bool found = false;      // Flag to track if user was found
    string entered_pass;     // To store password input from user for confirmation

    cout << "\n\n\t\t\tDelete User Record";   // Display heading
    cout << "\n\n Enter User ID to Delete: "; // Prompt for ID
    cin >> id;                                // Get ID from user

    file.open("bank.txt", ios::in);  // Open original data file in read mode
    temp.open("temp.txt", ios::out); // Open a temp file to store updated data

    while (file >> i >> n >> a >> pas >> ph >> bal) // Read each user record
    {
        if (i == id) // If the current record matches the entered ID
        {
            found = true; // Mark that user was found

            cout << " Enter Password to Confirm Deletion: "; // Ask for confirmation password
            cin >> entered_pass;                             // Take password input

            if (entered_pass == pas) // If password matches
            {
                cout << "\n\n Record Deleted Successfully!"; // Show success
                continue;                                    // Skip writing this user to temp file (i.e., delete it)
            }
            else
            {
                // If password is incorrect, keep the record unchanged
                cout << "\nIncorrect Password. Deletion Aborted.";
                temp << i << " " << n << " " << a << " " << pas << " " << ph << " " << bal << endl;
            }
        }
        else
        {
            // If the record doesn't match the entered ID, copy it to temp file
            temp << i << " " << n << " " << a << " " << pas << " " << ph << " " << bal << endl;
        }
    }

    file.close(); // Close the original file
    temp.close(); // Close the temp file

    remove("bank.txt");             // Delete original file
    rename("temp.txt", "bank.txt"); // Rename temp file to original filename

    if (!found) // If no match was found in the loop
        cout << "\n\n User ID Not Found or Deletion Aborted...";

    getch(); // Pause for user to read output (requires <conio.h>)
}

void bank::show_all() // Member function of the 'bank' class to display all user records
{
    system("cls"); // Clear the console screen for better readability

    fstream file;            // Declare a file stream object for file operations
    string i, n, a, pas, ph; // Strings to hold user data: ID, Name, Address, Password, and Phone
    float bal;               // Float variable to store the account balance
    bool found = false;      // Flag to check whether any records were found or not

    cout << "\n\n\t\t\tAll User Records" << endl; // Print title

    file.open("bank.txt", ios::in); // Open the data file in input (read) mode

    // Loop through each line of the file and read user data
    while (file >> i >> n >> a >> pas >> ph >> bal)
    {
        found = true; // If at least one record is read, set found to true

        // Print the details of the current user (excluding password for privacy)
        cout << "\nUser ID: " << i
             << "\nName: " << n
             << "\nAddress: " << a
             << "\nPhone: " << ph
             << "\nBalance: " << bal << endl;
    }

    file.close(); // Close the file after reading all records

    // If no records were found in the file
    if (!found)
        cout << "\n\n No Record Found...";

    getch(); // Pause the screen until a key is pressed (requires <conio.h>)
}

void bank::payment_all()
{
    system("cls");                        // Clears the screen
    fstream file, log;                    // File streams for user data and logging
    vector<vector<string>> updated_users; // To temporarily store updated user data
    string i, n, a, pas, ph;              // Variables to store individual fields from file
    float bal;                            // Variable to store user balance
    float fixed_payment;                  // Payment amount to credit to all accounts

    cout << "\n\n\t\t\tCredit Payment to All Accounts";
    cout << "\n\n Enter Payment Amount to Add: ";
    cin >> fixed_payment; // Take input for payment amount

    file.open("bank.txt", ios::in);            // Open bank.txt to read existing data
    log.open("payment_history.txt", ios::app); // Open payment_history.txt in append mode

    if (!file || !log) // Check for file errors
    {
        cout << "\n\nError opening file(s).";
        getch(); // Pause execution
        return;
    }

    // Print header for payment summary
    cout << "\n\n\t\tPayment Summary:\n";
    cout << "-------------------------------------------------------------\n";
    cout << left << setw(15) << "Account ID"
         << setw(15) << "Name"
         << setw(12) << "Credited"
         << setw(12) << "New Balance" << endl;
    cout << "-------------------------------------------------------------\n";

    // Read data from file and apply payment
    while (file >> i >> n >> a >> pas >> ph >> bal)
    {
        bal += fixed_payment; // Add payment to balance

        // Get current time for log
        time_t now = time(0);
        char *dt = ctime(&now);
        dt[strlen(dt) - 1] = '\0'; // Remove newline from timestamp

        // Log the payment
        log << "User ID: " << i
            << ", Name: " << n
            << ", Type: Bulk Credit"
            << ", Amount: Rs " << fixed_payment
            << ", New Balance: Rs " << bal
            << ", Time: " << dt << endl;

        // Store updated data in vector
        updated_users.push_back({i, n, a, pas, ph, to_string(bal)});

        // Show this user's payment summary
        cout << left << setw(15) << i
             << setw(15) << n
             << setw(12) << fixed_payment
             << setw(12) << bal << endl;
    }

    file.close(); // Close input file
    log.close();  // Close log file

    // Write updated data back to file
    ofstream out("bank.txt", ios::out);
    for (auto &user : updated_users)
    {
        for (auto &field : user)
            out << field << " ";
        out << endl;
    }
    out.close();

    cout << "\n\n Payment Applied and User Balances Updated.";
    getch(); // Pause execution
}

void bank::user_balance() // Member function of the 'bank' class to allow a user to login and view their balance
{
    system("cls"); // Clears the console screen (Windows-specific)

    fstream file;                          // File stream to read from the bank record file
    string t_id, ch_pass = "";             // t_id stores entered user ID; ch_pass will store masked password input
    string id, name, address, pass, phone; // Variables to store user details read from the file
    double balance;                        // To store the user's balance
    int found = 0;                         // Flag to track if a matching record is found
    char ch;                               // To capture each keypress during password entry

    cout << "\n\n\t\t\tUser Login & Check Balance"; // Display title

    file.open("bank.txt", ios::in); // Open the bank file in read mode
    if (!file)                      // Check if file failed to open
    {
        cout << "\n\nFile Opening Error..."; // Error message if file can't be opened
        return;                              // Exit the function
    }

    cout << "\n\nUser ID: "; // Ask for user ID
    cin >> t_id;             // Take user ID input

    cout << "\n\nPassword (5 digits): "; // Prompt user for password
    while (true)                         // Infinite loop for secure password entry
    {
        ch = getch(); // Get one character input without displaying it

        if (ch == 13) // If Enter key is pressed
        {
            if (ch_pass.length() == 5) // Check if 5 digits have been entered
                break;                 // Exit the loop
            else
                continue; // Otherwise, keep asking until length is 5
        }
        else if (ch == 8) // If Backspace key is pressed
        {
            if (!ch_pass.empty()) // Make sure there's something to delete
            {
                ch_pass.pop_back(); // Remove last character from password string
                cout << "\b \b";    // Move cursor back, print space to erase, move back again
            }
        }
        else if (isdigit(ch) && ch_pass.length() < 5) // Allow only digits and limit to 5
        {
            ch_pass += ch; // Append character to password
            cout << "*";   // Print * instead of actual digit for masking
        }
    }

    // Begin reading each user record from file to validate login
    while (file >> id >> name >> address >> pass >> phone >> balance)
    {
        if (t_id == id && ch_pass == pass) // If both ID and password match
        {
            found = 1; // Set flag to indicate successful login

            cout << "\n\nLogin Successful!"; // Confirmation message

            // Show user account details
            cout << "\n\n\t\t\tUser Account Details";
            cout << "\n\nUser ID   : " << id;
            cout << "\nName      : " << name;
            cout << "\nAddress   : " << address;
            cout << "\nPhone     : " << phone;
            cout << "\nBalance   : " << balance << " INR";
            break; // Stop loop since user has been found
        }
    }

    file.close(); // Close the file

    if (!found) // If no matching record was found
    {
        cout << "\n\n\t\tInvalid User ID or Password."; // Error message
    }

    getch(); // Wait for a key press before exiting (pauses screen)
}

void bank::atm_withdraw() // Member function of 'bank' class for ATM-style withdrawal
{
    system("cls"); // Clear the console screen (Windows only)

    fstream file, temp;                           // File streams: one to read existing data, one to write updated data
    string t_id, ch_pass = "", confirm_pass = ""; // Variables for entered ID, password, and password confirmation
    string id, name, address, pass, phone;        // Variables for each user's data from the file
    double balance, amount;                       // Variables to store current balance and withdrawal amount
    int found = 0;                                // Flag to check if the user exists and withdrawal was successful
    char ch;                                      // Character used for password masking (getch)

    cout << "\n\n\t\t\tATM Withdrawal"; // Display title

    cout << "\n\nUser ID: "; // Prompt for user ID
    cin >> t_id;             // Input user ID

    cout << "\n\nPassword (5 digits): "; // Prompt for password
    while (true)                         // Loop for secure password input
    {
        ch = getch(); // Get character input without showing it

        if (ch == 13 && ch_pass.length() == 5) // Enter key pressed and 5 digits entered
            break;
        else if (ch == 8 && !ch_pass.empty()) // Handle Backspace key
        {
            ch_pass.pop_back(); // Remove last character
            cout << "\b \b";    // Erase character on screen
        }
        else if (isdigit(ch) && ch_pass.length() < 5) // Allow only digit input, max 5 digits
        {
            ch_pass += ch; // Append digit to password string
            cout << "*";   // Show * for each digit entered
        }
    }

    file.open("bank.txt", ios::in);  // Open bank file to read existing records
    temp.open("temp.txt", ios::out); // Open temp file to write updated records

    if (!file || !temp) // Check if file opening failed
    {
        cout << "\n\nFile error..."; // Show error message
        return;                      // Exit the function
    }

    // Loop to read all user records from bank.txt
    while (file >> id >> name >> address >> pass >> phone >> balance)
    {
        if (t_id == id && ch_pass == pass) // If entered ID and password match
        {
            cout << "\n\nCurrent Balance: " << balance << " INR"; // Show balance
            cout << "\nEnter Amount to Withdraw: ";               // Prompt for amount
            cin >> amount;                                        // Input amount

            if (amount <= 0 || amount > balance) // Check for invalid or insufficient funds
            {
                cout << "\n\nInvalid amount or insufficient funds!"; // Show error
                // Write back original data unchanged
                temp << id << " " << name << " " << address << " " << pass << " " << phone << " " << balance << endl;
            }
            else // Valid withdrawal
            {
                cout << "\n\nConfirm Password to Proceed: "; // Ask for password again
                while (true)
                {
                    ch = getch();                               // Get input
                    if (ch == 13 && confirm_pass.length() == 5) // Enter key and 5 digits
                        break;
                    else if (ch == 8 && !confirm_pass.empty()) // Backspace
                    {
                        confirm_pass.pop_back();
                        cout << "\b \b";
                    }
                    else if (isdigit(ch) && confirm_pass.length() < 5) // Digit entry
                    {
                        confirm_pass += ch;
                        cout << "*";
                    }
                }

                if (confirm_pass == ch_pass) // If confirmation password matches
                {
                    balance -= amount;                                  // Deduct amount from balance
                    cout << "\n\nWithdrawal Successful!";               // Success message
                    cout << "\nUpdated Balance: " << balance << " INR"; // Show updated balance
                    found = 1;                                          // Mark success
                }
                else // Password mismatch
                {
                    cout << "\n\nPassword mismatch! Transaction cancelled."; // Error
                }

                // Save updated record (balance may or may not be changed)
                temp << id << " " << name << " " << address << " " << pass << " " << phone << " " << balance << endl;
            }
        }
        else // For other users, just copy the data to temp as-is
        {
            temp << id << " " << name << " " << address << " " << pass << " " << phone << " " << balance << endl;
        }
    }

    file.close(); // Close input file
    temp.close(); // Close temp file

    remove("bank.txt");             // Delete old file
    rename("temp.txt", "bank.txt"); // Rename temp to original file name

    if (!found) // If user not found or transaction failed
    {
        cout << "\n\n\t\tInvalid User ID or Password."; // Show error
    }

    getch(); // Wait for a key press before continuing (pause screen)
}

// Main function - program entry point
int main()
{
    bank obj;   // Step 1: Create an object 'obj' of class 'bank'
    obj.menu(); // Step 2: Call the 'menu' function using the 'obj' object
    return 0;   // Step 3: Return 0 to signal successful execution
}