#include <iostream> 
#include <string>
using namespace std;

#ifdef _WIN32
#define CLEAR_SCREEN  "cls" //for Window
#else
#define CLEAR_SCREEN "clear" // for Linux & Mac
#endif

class Bank{
    private:
        int Account_ID, Password;
        string Firstname, Lastname;
        double Balance;
        
    public:
    void ClearScreen(){
        system(CLEAR_SCREEN);
    }
    void OpenAccount(){
        ClearScreen();
        cout << "------ Welcome to BTI Bank --------\n";
        cout << "Enter Account ID       : ";
        cin >> Account_ID;
        cout << "Enter Firstname        : ";
        cin >> Firstname;
        cout << "Enter Lastname         : ";
        cin >> Lastname;
        cout << "Enter Password         : ";
        cin >> Password;
        cout << "Enter Initial Balance  : $ ";
        cin >> Balance;
        cout << "\nYour bank account has successfully created!";
    }

    void ShowAccount(){
        ClearScreen();
        cout << "---- Your Personal Bank Account ----\n";
        cout << "Account ID         : " << Account_ID << endl;
        cout << "Firstname          : " << Firstname << endl;
        cout << "Lastname           : " << Lastname << endl;
        cout << "Password           : " << Password << endl;
        cout << "Balance            : $ " << Balance << endl;
    }

    void Deposit(){
        ClearScreen();
        double amount;
        cout << "--------------- Deposit system ---------------\n";
        cout << "Enter amount you want to deposit : $ ";
        cin >> amount;
        Balance = Balance + amount;
        cout << "\n\nAmount deposited successfully!\n";
        cout << "You Have Deposited To Balance : $ " << amount << endl;
        cout << "To Account : " << Firstname << " " + Lastname << endl;
    }

    void Withdraw(){
        ClearScreen();
        double amount;
        cout << "--------------- Withdraw system ---------------\n";
        cout << "Enter amount to withdraw : $ ";
        cin >> amount;
        if (amount <= Balance) {
            Balance -= amount;
            cout << "\n\nAmount withdrawn successfully!" << endl;
            cout << "You Have Withdrawn From Balance : - $ " << amount << endl;
            cout << "From Account : " << Firstname << " " + Lastname << endl;
        } 
        else {
            cout << "\n\nInsufficient balance!" << endl;
        }
    }
    void Update(){
        ClearScreen();
        string NewFirstname, NewLastname;
        int NewPassword;
        system("clear");
        cout << "--------- Update system -----------\n";
        cout << "Enter New Firstname      : ";
        cin >> NewFirstname;
        cout << "Enter New Lastname       : ";
        cin >> NewLastname;
        cout << "Enter New PassWord       : ";
        cin >> NewPassword;
        cout << "\nYour bank account has successfully updated!";
        Firstname = NewFirstname;
        Lastname = NewLastname;
        Password = NewPassword;
    }
    bool Search(int Acc){
        if(Acc == Account_ID){
            return true;
        } else {
            return false;
        }
    }
    bool Search_Password(int PassW){
        if(PassW == Password){
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    Bank Account[10];
    int Choice, AccountCount = 0; 
    
    do{
        // Bank Manu
        cout << endl;
        cout << "|----------------------------------|\n";
        cout << "|             BTI Bank             |\n";
        cout << "|----------------------------------|\n";
        cout << "|  1. Open Account                 |\n";
        cout << "|  2. Show Account                 |\n";
        cout << "|  3. Deposit                      |\n";
        cout << "|  4. Withdraw                     |\n";
        cout << "|  5. Update                       |\n";
        cout << "|  6. Exit                         |\n";
        cout << "|----------------------------------|\n";
        cout << "Choice: "; cin >> Choice;
        
        switch (Choice){
                case 1:{
                if(AccountCount < 10){
                    Account[AccountCount].OpenAccount();
                    AccountCount++;
                }
                else{
                    system("clear");
                    cout << "\n\nMaximum account limit reached!..\n";
                }
            
                break;
            }
            case 2: {
                int Acc, PassW;
                cout << "Enter Account Number  : ";
                cin >> Acc;
                cout << "Enter Password        : ";
                cin >> PassW;
                bool found = false;
                for (int i = 0; i < AccountCount; i++){
                    if (Account[i].Search(Acc) && Account[i].Search_Password(PassW)){
                        Account[i].ShowAccount();
                        found = true;
                        break;
                    } else {
                        system("clear");
                        cout << "\n\nAccount not found!..\n";
                    }
                }
                break;
            }
            case 3:{
                int Acc, PassW;
                cout << "Enter Account Number  : ";
                cin >> Acc;
                cout << "Enter Password        : ";
                cin >> PassW;
                bool found = false;
                for (int i = 0; i < AccountCount; i++){
                    if (Account[i].Search(Acc) && Account[i].Search_Password(PassW)){
                        Account[i].Deposit();
                        found = true;
                        break;
                    } else {
                        system("clear");
                        cout << "\n\nAccount not found!..\n";
                    }
                }
               break;
            }
            case 4: {
                int Acc, PassW;
                cout << "Enter Account Number  : ";
                cin >> Acc;
                cout << "Enter Password        : ";
                cin >> PassW;
                bool found = false;
                for (int i = 0; i < AccountCount; i++ ){
                    if(Account[i].Search(Acc) && Account[i].Search_Password(PassW)){
                        Account[i].Withdraw();
                        found = true;
                        break;
                    } else {
                        system("clear");
                        cout << "\n\nAccount not found!..\n";
                    }
                }
                break;
            }
            case 5:{
                int Acc, PassW;
                cout << "Enter Account Number  : ";
                cin >> Acc;
                cout << "Enter Password        : ";
                cin >> PassW;
                bool found = false;
                for (int i = 0; i < AccountCount; i++ ){
                    if(Account[i].Search(Acc) && Account[i].Search_Password(PassW)){
                        Account[i].Update();
                        found = true;
                    } else {
                        system("clear");
                        cout << "\n\nAccount not found!..\n";
                    }
                }
                break;
            }
            case 6: {
                cout << "\n\n\nExiting the system.\n\n";
                cout << "Thank you for using our Bank system. \nHave a nice day!\n";
                break;
            default:
                system("clear");
                cout << endl;
                cout << "\n\nOops!! Invalid choice! Please try again.\n\n";
            }
        }
    } while (Choice != 6);

    return 0;
}