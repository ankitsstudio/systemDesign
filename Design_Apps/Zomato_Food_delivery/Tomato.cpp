#include <vector>
#include <string>
#include "Models/User.cpp"
#include "Models/Restaurent.cpp"
#include "Models/Cart.cpp"
#include "Managers/OrderManager.cpp"
#include "Managers/RestaurentManager.cpp"
#include "Strategies/PaymentStrategy.cpp"
#include "Strategies/UpiPaymentStrategy.cpp"
#include "factories/NowOrder.cpp"
#include "Factories/ScheduleOrder.cpp"
#include "services/NotificationService.cpp"
#include "utils/TimeUtils.cpp"
using namespace std;

class TomatoApp {
public:
    TomatoApp() {
        initializeRestaurants();
    }

    void initializeRestaurants() {
        Restaurent* restaurant1 = new Restaurent("Bikaner", "Delhi");
        restaurant1->addMenuItem(MenuItem("P1", "Chole Bhature", 120));
        restaurant1->addMenuItem(MenuItem("P2", "Samosa", 15));
        restaurant1->addMenuItem(MenuItem("P3", "Tawa Roti", 10));
        restaurant1->addMenuItem(MenuItem("P4", "Paneer Butter Masala", 120));


        Restaurent* restaurant2 = new Restaurent("Haldiram", "Kolkata");
        restaurant2->addMenuItem(MenuItem("P1", "Raj Kachori", 80));
        restaurant2->addMenuItem(MenuItem("P2", "Pav Bhaji", 100));
        restaurant2->addMenuItem(MenuItem("P3", "Dhokla", 50));

        Restaurent* restaurant3 = new Restaurent("Saravana Bhavan", "Chennai");
        restaurant3->addMenuItem(MenuItem("P1", "Masala Dosa", 90));
        restaurant3->addMenuItem(MenuItem("P2", "Idli Vada", 60));
        restaurant3->addMenuItem(MenuItem("P3", "Filter Coffee", 30));

        RestaurentManager* restaurantManager = RestaurentManager::getInstance();
        restaurantManager->addRestaurent(restaurant1);
        restaurantManager->addRestaurent(restaurant2);
        restaurantManager->addRestaurent(restaurant3);

        // Add other sample restaurants...
    }

    vector<Restaurent*> searchRestaurants(const string& location) {
        return RestaurentManager::getInstance()->searchByLocation(location);
    }

    void selectRestaurant(User* user, Restaurent* restaurant) {
        Cart* cart = user->getCart();
        cart->setRestaurent(restaurant);
    }

    void addToCart(User* user, const string& itemCode) {
        Restaurent* restaurent = user->getCart()->getRestaurent();
        if (!restaurent) {
            cout << "Please select a restaurant first." << endl;
            return;
        }
        for (const auto& item: restaurent->getMenu()) {
            if (item.getItemCode() == itemCode) {
                user->getCart()->addItem(item);
                break;
            }
        }
    }

    Order* checkoutNow(User* user, const string& orderType, PaymentStrategy* paymentStrategy) {
        return checkout(user, orderType, paymentStrategy, new NowOrder());
    }

    Order* checkoutScheduled(User* user, const string& orderType, PaymentStrategy* paymentStrategy, const string& scheduleTime) {
        return checkout(user, orderType, paymentStrategy, new ScheduleOrder(scheduleTime));
    }

    Order* checkout(User* user, const string& orderType, 
        PaymentStrategy* paymentStrategy, OrderFactory* orderFactory) {
        if (user->getCart()->isEmpty())
        return nullptr;

        Cart* userCart = user->getCart();
        Restaurent* orderedRestaurent = userCart->getRestaurent();
        vector<MenuItem> itemsOrdered = userCart->getItems();
        double totalCost = userCart->getTotalCost();

        Order* order = orderFactory->createOrder(user, userCart, orderedRestaurent, itemsOrdered, paymentStrategy, totalCost, orderType);
        OrderManager::getInstance()->addOrder(order);
        return order;
    }

    void payForOrder(User* user, Order* order) {
        bool isPaymentSuccess = order->processPayment();

        // clear user cart if payment is successful.
        if(isPaymentSuccess) {
            NotificationService* notification = new NotificationService();
            notification->notify(order);
            user->getCart()->clear();
        }  
    }

    void printUserCart(User* user) {
        cout << "Items in cart:" << endl;
        cout << "------------------------------------" << endl;
        for (const auto& item : user->getCart()->getItems()) {
            cout << item.getItemCode() << " : " << item.getItemName() << " : ₹" << item.getPrice() << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Grand total : ₹" << user->getCart()->getTotalCost() << endl;
    }
};