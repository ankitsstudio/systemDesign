#include <iostream>
#include <vector>

using namespace std;

class Product {
    public: 
        // define public variables
        string name;
        double price;

        // define Product class constructor
        Product(string name, double price){
            this->name = name;
            this->price = price;
        }
};

class ShoppingCart {
    private: 
        vector<Product* > products;
    
    public: 
        void addProduct(Product* product){
            products.push_back(product);
        }

        const vector<Product* >& getProducts() const{
            return products;
        }

        double calculateTotal(){
            double total = 0;
            for(auto product: products){
                total += product->price;
            }
            return total;
        }
};

class InvoicePrinter {
    private:
        ShoppingCart* cart;
    public:
        InvoicePrinter(ShoppingCart* cart) {
            this->cart = cart;
        }

        void printInvoice() {
            cout << "\n========== INVOICE ==========" << endl;
            cout << "Items:" << endl;
            double total = 0;
            for (auto product : cart->getProducts()) {
                cout << "  - " << product->name << ": $" << product->price << endl;
                total += product->price;
            }
            cout << "Total: $" << total << endl;
            cout << "============================" << endl;
        }
}; 

class Persistence {
    private: 
        ShoppingCart* cart;
    
    public: 
        virtual void save(ShoppingCart* cart) = 0;
};

class MongoDBPersistence: public Persistence {
    public:
        void save(ShoppingCart* cart) override {
            cout << "Order saved successfully to Mongo Database!" << endl;
        }
};

class MySQLDBPersistence: public Persistence {
    public:
        void save(ShoppingCart* cart) override {
            cout << "Order saved successfully to MySQL Database!" << endl;
        }
};

class PostGreSQLDBPersistence: public Persistence {
    public:
        void save(ShoppingCart* cart) override {
            cout << "Order saved successfully to PostgreSQL Database!" << endl;
        }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();

    Product* p1 = new Product("I-Phone", 1600.0);
    Product* p2 = new Product("Laptop", 3100.0);
    Product* p3 = new Product("Headphone", 400.0);

    cart->addProduct(p1);
    cart->addProduct(p2);
    cart->addProduct(p3);

    Persistence* mongo = new MongoDBPersistence();
    Persistence* mysql = new MySQLDBPersistence();
    Persistence* postgresql = new PostGreSQLDBPersistence();

    mongo->save(cart);
    mysql->save(cart);
    postgresql->save(cart);


    InvoicePrinter* printer = new InvoicePrinter(cart);
    printer->printInvoice();

}

