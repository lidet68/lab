/*
Project Title   : Bank Management System
*/
#include <iostream>

using namespace std;

string USERNAME="user",PASSWORD="pass",Confirm,receiver="None",account_no="1000021221",receiver_acc="None";
float amount,deposit,withdraw,transaction;
string acc_no[5]={"1000018911", "1000018912", "1000018913","1000018914","1000018915"};


void login();
void create_account();
void recent();
void system();

int main(){
    A:
        int choice;
        cout<<"\n+++++++++++++++++++++++++++"<<endl;
        cout<<"     Menu"<<endl;
        cout<<"__________________________"<<endl;
        cout<<"1. Login"<<endl;
        cout<<"2. Create an account"<<endl;
        cout<<"3. Recent activities"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"+++++++++++++++++++++++++++"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                login();
                break;
            case 2:
                create_account();
                break;
            case 3:
                recent();
                break;
            case 4:
                cout<<"GOOD BYE!"<<endl;
                exit(1);
                break;
            default:
                cout<<"Invalid choice"<<endl;
                goto A;
        }
    return 0;
}



void login(){
    string username,password;
    cout<<"\n UserName:  ";
    cin>>username;
    cout<<" Password:  ";
    cin>>password;

    if(username == USERNAME && password == PASSWORD){
        cout<<"Logged in successfully!  "<<endl;
        system();
    }
    else{
        cout<<" Access denied ";
        login();
        }
}

void create_account(){
    cout<<"\n You have to provide some information in order to create an account. "<<endl;
    cout<<"____________________________________________________________________"<<endl;
    cout<<" UserName:  ";
    cin>>USERNAME;
    M:
        cout<<" Password:  ";
        cin>>PASSWORD;
        cout<<" Confirm Password:  ";
        cin>>Confirm;
        if (PASSWORD == Confirm){
            cout<<"Your account number is "<<acc_no[0]<<endl;
            account_no = acc_no[0];

            for(int i=0;i<5;i++){
                acc_no[i] = acc_no[i+1];
            }

            cout<<"\n Your account has been created successfully  "<<endl;
            cout<<"\nEnter an amount to deposit:  ";
            cin>>deposit;
            amount = 0;
            amount += deposit;
            system();
            }
        else{
            cout<<"\n incorrect password !!"<<endl;
            cout<<" Please try again. \n"<<endl;
            goto M;
            }
}

void recent(){
    cout<<"Customer  Account No. Withdrawal  Deposit  Transaction  Receiver  Account No."<<endl;
    cout<<"--------  ----------  ----------  -------  -----------  --------  -----------"<<endl;
    cout<<USERNAME<<"\t   "<<account_no<<withdraw<<"\t     "<<deposit<<"\t    "<<transaction<<"\t    "<<receiver<<"\t  "<<receiver_acc<<endl;
    A;
}

void system(){
    abc:
        int choice;

        cout<<"\n_________________________"<<endl;
        cout<<"     system  "<<endl;
        cout<<"__________________________"<<endl;
        cout<<" 1. Check account balance"<<endl;
        cout<<" 2. Withdraw"<<endl;
        cout<<" 3. Deposit"<<endl;
        cout<<" 4. Transfer"<<endl;
        cout<<" 5. Main menu"<<endl;
        cout<<" 6. Exit"<<endl;
        cout<<"++++++++++++++++++++++++++"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Account No: "<<account_no<<endl;
                cout<<"Current Balance: $"<<amount<<endl;
                goto abc;
                break;

            case 2:
                cout<<" Enter the amount to withdraw: ";
                cin>>withdraw;
                if ((amount - withdraw) <= 0){
                    cout<<"  Your balance is insufficient  "<<endl;
                    cout<<"Current Balance: $"<<amount<<endl;
                }
                else{
                    amount -= withdraw;
                    cout<<"Current Balance: $"<<amount<<endl;
                }
                goto abc;
                break;
            case 3:
                cout<<"Enter the amount to deposit: ";
                cin>>deposit;
                amount += deposit;
                cout<<"Current Balance: $"<<amount<<endl;
                goto abc;
                break;
            case 4:
                cout<<"Enter a userName you would like to transfer: ";
                cin>>receiver;
                cout<<"Enter the receiver's account number: ";
                cin>>receiver_acc;
                cout<<"Enter the amount to transfer: ";
                cin>>transaction;
                if((amount - transaction) <= 0){
                    cout<<" Your balance is insufficient"<<endl;
                    cout<<"Current Balance: $"<<amount<<endl;
                }
                else{
                    amount -= transaction;
                    cout<<"Current Balance: $"<<amount<<endl;
                }
                goto abc;
                break;
            case 5:
                A;
                break;
            case 6:
                cout<<" GOOD BYE! "<<endl;
                exit(1);
                break;
            default:
                cout<<" Invalid choice "<<endl;
                cout<<" please try again"<<endl;
                goto abc;
        }
}
