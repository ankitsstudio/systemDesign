#include <iostream>
#include <vector>
#include "./NotificationService.cpp"
#include "./Observers/Logger.cpp"
#include "./Observers/NotificationEngine.cpp"
#include "./Observers/NotificationObservable.cpp"
#include "./Strategies/EmailStrategy.cpp"
#include "./Strategies/SMSStrategy.cpp"
#include "./Strategies/PopUpStrategy.cpp"
#include "./Decorators/SimpleNotification.cpp"
#include "./Decorators/TimestampDecorator.cpp"
#include "./Decorators/SignatureDecorator.cpp"
#include "./Decorators/INotificationDecorator.cpp"


using namespace std;

int main(){
    NotificationService* notificationService = NotificationService::getInstance();
    NotificationObservable* notificationObservable = notificationService->getObservable();

    Logger* logger = new Logger(notificationObservable);
    NotificationEngine* notificationEngine = new NotificationEngine(notificationObservable);

    notificationEngine->addNotificationStrategy(new EmailStrategy("random123@gmail.com"));
    notificationEngine->addNotificationStrategy(new SMSStrategy("9023456712"));
    notificationEngine->addNotificationStrategy(new PopUpStrategy());

    notificationObservable->addObserver(logger);
    notificationObservable->addObserver(notificationEngine);

    INotification* notification = new SimpleNotification("your order has been shiped!");
    notification = new TimestampDecorator(notification);
    notification = new SignatureDecorator(notification, "Customer Care");

    notificationService->sendNotification(notification);

    delete logger;
    delete notificationEngine;
    return 0;


}
