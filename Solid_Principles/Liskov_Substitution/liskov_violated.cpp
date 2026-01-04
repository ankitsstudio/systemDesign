#include <iostream>
#include <vector>

using namespace std;

class Account {
    public:
        virtual bool withdraw(double amount) = 0;
};

class SavingAccount : public Account{
    private: 
        double balance;

    public: 
        SavingAccount(double balance){
            this->balance = balance;
        }  

        bool withdraw(double amount) override {
            if(balance-amount >= 0){
                balance -= amount;
                cout<<"Successfully withdrawn "<<amount<<"rs from your saving account"<<endl;
                cout<<"remaining balance is "<< balance <<endl;
                return true;
            }
            else{
                cout<<"You do not have sufficient balance in your saving account";
                return false;
            }
        }
};

class CurrentAccount : public Account{
    private: 
        double balance;

    public: 
        CurrentAccount(double balance){
            this->balance = balance;
        } 

        bool withdraw(double amount) override {
            if(balance-amount >= 0){
                balance -= amount;
                cout<<"Successfully withdrawn "<<amount<<"rs from your current account"<<endl;
                cout<<"remaining balance is "<< balance <<endl;
                return true;
            }
            else{
                cout<<"You do not have sufficient balance in your current account";
                return false;
            }
        }
};

class FixedDepositeAccount : public Account{
    private: 
        double balance;

    public:
        FixedDepositeAccount(double balance){
            this->balance = balance;
        } 

        bool withdraw(double amount) override {
            cout << "[FD] FIXED DEPOSIT CANNOT BE WITHDRAWN BEFORE MATURITY!" <<endl;
            return false;  // Always fails - VIOLATES base contract!
        }
};

class BankClient {
    private: 
        vector<Account*> accounts;
    
    public:
        BankClient(vector<Account*> accounts){
            this->accounts = accounts;
        }
        void processTransaction(){
            for(auto account: accounts){
                try{
                    account->withdraw(1000);
                }
                catch(const exception& e){
                    cout <<"Exception: "<< e.what() << '\n';
                }
            }
        }
};

int main() {
    vector<Account* > accounts;

    accounts.push_back(new SavingAccount(1200));
    accounts.push_back(new CurrentAccount(1300));
    accounts.push_back(new FixedDepositeAccount(3000));

    BankClient* bank = new BankClient(accounts);
    bank->processTransaction();
}