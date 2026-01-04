#include <iostream>
#include <vector>

using namespace std;

class NonWithdrableAccount {
    public: 
        virtual void deposite(double amount) = 0;
};

class WithdrableAccount: public NonWithdrableAccount {
    public: 
        virtual bool withdraw(double amount) = 0;
};

class SavingAccount: public WithdrableAccount {
    private:
        double balance;
    
    public: 
        SavingAccount(double balance){
            this->balance = balance;
        }

        void deposite(double amount) override {
            balance += amount;
            cout<<"Your Saving Account is successfully deposited with the amount of Rs. "<<amount<<endl;
            cout<<"Current balance is: "<<balance<<endl;
        }

        bool withdraw(double amount) override {
            if(balance - amount >= 0){
                balance -= amount;
                cout<<"You successfully withdrawn amount of Rs. "<<amount<<endl;
                cout<<"Current balance for your Saving account is: "<<balance<<endl;
                return true;
            }
            else{
                cout<<"Not sufficient balance in the saving account to withdraw Rs. "<<amount<<endl;
                return false;
            }
        }
};

class CurrentAccount: public WithdrableAccount {
    private:
        double balance;
    
    public: 
        CurrentAccount(double balance){
            this->balance = balance;
        }

        void deposite(double amount) override {
            balance += amount;
            cout<<"Your Current Account is successfully deposited with the amount of Rs. "<<amount<<endl;
            cout<<"Current balance is: "<<balance<<endl;
        }

        bool withdraw(double amount) override {
            if(balance - amount >= 0){
                balance -= amount;
                cout<<"You successfully withdrawn amount of Rs. "<<amount<<endl;
                cout<<"Current balance for your Current account is: "<<balance<<endl;
                return true;
            }
            else{
                cout<<"Not sufficient balance in the current account to withdraw Rs. "<<amount<<endl;
                return false;
            }
        }
};

class FixedDepositeAccount: public NonWithdrableAccount {
    private:
        double balance;
    
    public: 
        FixedDepositeAccount(double balance){
            this->balance = balance;
        }

        void deposite(double amount) override {
            balance += amount;
            cout<<"Your Saving Account is successfully deposited with the amount of Rs. "<<amount<<endl;
            cout<<"Current balance is: "<<balance<<endl;
        }
};

class BankClient {
    private: 
        vector<NonWithdrableAccount* > depositeOnlyAccounts;
        vector<WithdrableAccount* > withdrableAccounts;

    public:
        BankClient(vector<NonWithdrableAccount* >& depositeOnlyAccounts, vector<WithdrableAccount* >& withdrableAccounts){
            this->depositeOnlyAccounts = depositeOnlyAccounts;
            this->withdrableAccounts = withdrableAccounts;
        }

        void processTransaction(){
            for(auto account: withdrableAccounts){
                account->deposite(2000);
                account->withdraw(1000);
            }
            for(auto account: depositeOnlyAccounts){
                account->deposite(500);
            }
        }
};

int main(){
    vector<NonWithdrableAccount* > depositeOnlyAccounts;
    depositeOnlyAccounts.push_back(new FixedDepositeAccount(500));

    vector<WithdrableAccount* > withdrableAccounts;
    withdrableAccounts.push_back(new SavingAccount(700));
    withdrableAccounts.push_back(new CurrentAccount(1100));


    BankClient* bank = new BankClient(depositeOnlyAccounts, withdrableAccounts);
    bank->processTransaction();
}