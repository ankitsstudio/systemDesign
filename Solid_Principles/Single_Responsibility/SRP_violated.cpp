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

        // SRP VIOLATION: Calculating total price (Business Logic)
        double calculateTotal() {
            double total = 0;
            for (auto product : products) {
                total += product->price;
            }
            return total;
        }

        // SRP VIOLATION: Applying discounts (Business Logic)
        double applyDiscount(double total, double discountPercent) {
            return total - (total * discountPercent / 100);
        }

        // SRP VIOLATION: Saving to database (Persistence Logic)
        void saveToDatabase(string orderId) {
            cout << "Saving order " << orderId << " to database..." << endl;
            cout << "Order saved successfully!" << endl;
        }

        // SRP VIOLATION: Printing receipt (Presentation Logic)
        void printReceipt() {
            cout << "\n========== RECEIPT ==========" << endl;
            cout << "Items:" << endl;
            double total = 0;
            for (auto product : products) {
                cout << "  - " << product->name << ": $" << product->price << endl;
                total += product->price;
            }
            cout << "Total: $" << total << endl;
            cout << "============================" << endl;
        }

        // SRP VIOLATION: Sending email notification (Communication Logic)
        void sendOrderConfirmation(string email) {
            cout << "Sending confirmation email to: " << email << endl;
            cout << "Email sent successfully!" << endl;
        }

        void removeProduct(int index) {
            if (index >= 0 && index < products.size()) {
                products.erase(products.begin() + index);
            }
        }

        int getProductCount() {
            return products.size();
        }
};

int main() {
    // Create products
    Product* p1 = new Product("Laptop", 999.99);
    Product* p2 = new Product("Mouse", 29.99);
    Product* p3 = new Product("Keyboard", 79.99);

    // Create shopping cart
    ShoppingCart cart;
    
    // Add products to cart
    cart.addProduct(p1);
    cart.addProduct(p2);
    cart.addProduct(p3);

    cout << "Number of products in cart: " << cart.getProductCount() << endl;

    // Calculate total
    double total = cart.calculateTotal();
    cout << "Original Total: $" << total << endl;

    // Apply discount
    double discountedTotal = cart.applyDiscount(total, 10); // 10% discount
    cout << "Total after 10% discount: $" << discountedTotal << endl;

    // Print receipt
    cart.printReceipt();

    // Save to database
    cart.saveToDatabase("ORD-001");

    // Send confirmation email
    cart.sendOrderConfirmation("customer@example.com");

    // Cleanup
    delete p1;
    delete p2;
    delete p3;

    return 0;
}