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
        vector<Product*> products;
    
    public:
        // define method to add product to the array
        void addProduct(Product* p) {
            products.push_back(p);
        }

        // Method to get products
        const vector<Product*>& getProducts() const {
            return products;
        }
};

class calculateTotal {
    public:
        static double computeTotal(const ShoppingCart& cart) {
            double total = 0;
            for (auto product : cart.getProducts()) {
                total += product->price;
            }
            return total;
        }
};

class DiscountApplier {
    public:
        static double applyDiscount(double total, double discountPercent) {
            return total - (total * discountPercent / 100);
        }
};

class DatabaseSaver {
    public:
        static void saveToDatabase(const string& orderId) {
            cout << "Saving order " << orderId << " to database..." << endl;
            cout << "Order saved successfully!" << endl;
        }
};

class ReceiptPrinter {
    public:
        static void printReceipt(const ShoppingCart& cart) {
            cout << "\n========== RECEIPT ==========" << endl;
            cout << "Items:" << endl;
            double total = 0;
            for (auto product : cart.getProducts()) {
                cout << "  - " << product->name << ": $" << product->price << endl;
                total += product->price;
            }
            cout << "Total: $" << total << endl;
            cout << "============================" << endl;
        }
};

int main() {
    // create shopping cart object
    ShoppingCart cart;

    // create product objects
    Product* product1 = new Product("Laptop", 69999.99);
    Product* product2 = new Product("Smartphone", 21499.99);
    Product* product3 = new Product("Headphones", 1199.99);

    // add products to the cart
    cart.addProduct(product1);
    cart.addProduct(product2);
    cart.addProduct(product3);

    // calculate total
    double total = calculateTotal::computeTotal(cart);
    cout << "Total before discount: $" << total << endl;

    // apply discount
    double discountedTotal = DiscountApplier::applyDiscount(total, 10); // 10% discount
    cout << "Total after discount: $" << discountedTotal << endl;

    // save to database
    DatabaseSaver::saveToDatabase("ORDER123");

    // print receipt
    ReceiptPrinter::printReceipt(cart);

    // clean up
    delete product1;
    delete product2;
    delete product3;

    return 0;
}