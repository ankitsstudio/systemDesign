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
        // define arrayList to store products
        vector<Product* > products;

    public:
        // define method to add product to the array
        void addProduct(Product* p){
            products.push_back(p);
        }

        // get products
        const vector<Product*>& getProducts() const {
            return products;
        }
        
        double calculateTotal() {
            double total = 0;
            for (auto product : products) {
                total += product->price;
            }
            return total;
        }
};

class ShoppingCartStorage {
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartStorage(ShoppingCart* cart) {
            this->cart = cart;
        }

        void saveToMongoDB() {
            cout << "Order saved successfully to Mongo Database!" << endl;
        }

        // newly added method
        // Breaking OCP by modifying existing class to add new functionality
        void saveToMySQLDB() {
            cout << "Order saved successfully to MySQL Database!" << endl;
        }

        // newly added method
        // breaking OCP by modifying existing class to add new functionality
        void saveToPostgreSQLDB() {
            cout << "Order saved successfully to PostgreSQL Database!" << endl;
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

int main() {
    // create shopping cart object
    ShoppingCart* cart = new ShoppingCart();

    // create product objects
    Product* p1 = new Product("Laptop", 1200.00);
    Product* p2 = new Product("Smartphone", 800.00);
    Product* p3 = new Product("Headphones", 150.00);

    // add products to the cart
    cart->addProduct(p1);
    cart->addProduct(p2);
    cart->addProduct(p3);

    // calculate total price
    double total = cart->calculateTotal();
    cout << "Total Price: $" << total << endl;

    // save cart to different databases
    ShoppingCartStorage* storage = new ShoppingCartStorage(cart);
    storage->saveToMongoDB();
    storage->saveToMySQLDB();        // new functionality added
    storage->saveToPostgreSQLDB();   // new functionality added

    // print invoice
    InvoicePrinter* printer = new InvoicePrinter(cart);
    printer->printInvoice();

    // free allocated memory
    delete p1;
    delete p2;
    delete p3;
    delete cart;
    delete storage;
    delete printer;

    return 0;
}