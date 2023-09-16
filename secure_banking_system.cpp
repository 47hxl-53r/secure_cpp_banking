// BASIC SECURE BANKING SYSTEM PROGRAM IN C++
// DEVELOPER : <47HXL/>
// DATE : 16/11/2023
// TELEGRAM : @ieatkidsforlunch


#include <iostream>
#include <limits>
using namespace std;



// FUNCTION FOR DEPOSITING AMOUNT
int deposit(int totalBalance){
    int depositAmount;
    cout<<"Enter the amount to deposit : ";
    cin>>depositAmount;

    if (depositAmount <= 0){  // CHECKING IF THE AMOUNT IS 0 OR A NEGATIVE NUMBER
        cout<<"\n\nInvalid amount, Operation cancelled.";
        return -1;

    }else{
        totalBalance+=depositAmount;
        cout<<"\n\n$"<<depositAmount<<" deposited to your account successfully. Your updated balance is "<<totalBalance;
        return totalBalance; // RETURNING THE UPDATED BALANCE
    }
}


// FUNCTION FOR WITHDRAWING AMOUNT
int withdraw(int totalBalance){
    int withdrawAmount;
    cout<<"Enter the amount to withdraw : ";
    cin>>withdrawAmount;

    if (withdrawAmount <= 0){  // CHECKING IF THE AMOUNT IS 0 OR A NEGATIVE NUMBER
        cout<<"\n\nInvalid amount, Operation cancelled.";
        return -1;

    }else{
        if (withdrawAmount<=totalBalance){ // CHECKING IF THE ACCOUNT HAS SUFFICENT AMOUNT TO WITHDRAW
            // ON SUCCESS
            totalBalance-=withdrawAmount;
            cout<<"\n\n$"<<withdrawAmount<<" has been withdrawed from your account successfully. Your updated balance is "<<totalBalance;
            return totalBalance; // RETURNING THE UPDATED BALANCE

        }else {
            // ON FAILURE
            cout<<"\n\nInsufficent balance left on your account.";
            return -1;
        }
    }
}



// FUNCTION TO DISPLAY ACCOUNT BALANCE
int showBalance(int balance){
    cout<<"\n\nYour balance is $"<<balance<<".";
    return 0;
}


// MAIN FUNCTION
int main(){
    double balance = 2000.0; // POCKET MONEY XD ( DEFAULT BANK BALANCE )

    string menu_text = "\nS3CUR3 Bank\n"
                        "1. Check balance\n"
                        "2. Deposit\n"
                        "3. Withdraw\n"
                        "4. Quit\n\n"
                        "Select an option : ";

    

    while (true){    
        int choice;
        cout<<menu_text;
        cin>>choice;
        


        if (cin.fail() || choice < 1 || choice > 4 ||  choice != static_cast<int>(choice)) {  // VALIDATE USER INPUT: CHECK FOR INPUT FAILURE, OUT-OF-RANGE VALUES, AND NON-WHOLE NUMBERS
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer after input validation
                cout << "\n\nInvalid input. Please enter a valid choice (1-4).\n";
        }



        switch (choice) // EVALUATING CHOICE BASED ON USER INPUT
        {
        case 1: // SHOW BALANCE
            showBalance(balance);
            break;
        
        case 2: // DEPOSIT
            int deposit_status_or_updated_balance;
            deposit_status_or_updated_balance = deposit(balance); // THE DEPOSIT MIGHT FAIL RESULTING IN THE RETURN VALUE AS -1, WE CAN'T SET IT AS UPDATED BALANCE, SO WE EVALUATE IT BEFORE SETTING AS NEW BALANCE :)
            if(deposit_status_or_updated_balance != -1){
                balance = deposit_status_or_updated_balance;
            }
            break;
        
        case 3: // WITHDRAW
            int withdraw_status_or_updated_balance; // THE WITHDRAW MIGHT FAIL RESULTING IN THE RETURN VALUE AS -1, WE CAN'T SET IT AS UPDATED BALANCE, SO WE EVALUATE IT BEFORE SETTING AS NEW BALANCE :)
            withdraw_status_or_updated_balance = withdraw(balance);
            if(withdraw_status_or_updated_balance != -1){
                balance = withdraw_status_or_updated_balance;
            }
            break;
        
        case 4: // QUIT
            cout<<"Bye...";
            return 0;

        }
    }
    return 0;
}

// THE END