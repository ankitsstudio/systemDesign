#include <iostream>
#include <vector>

using namespace std;

class Shape {
    public: 
        // Fat Interfaces forces empty implementations
        // 3D shapes do not need area method
        virtual double areaCalculate() = 0; // calculate area for the 2D shapes like rectangle, square, circle...
        // 2D shapes do not need this volume calculator method
        virtual double volumeCalculate() = 0; // calculate volume for 3D shapes like Cube..
};

class Circle : public Shape {
    private: 
        double radius;
        const double PI = 3.14159;
        
    public:
        Circle(double radius){
            this->radius = radius;
        } 

        double areaCalculate() override {
            double area = PI*radius*radius;
            cout<<"Area of the circle with radius "<<radius<<" is : "<<area<<endl;
            return area;
        }

        // ❌ EMPTY STUB! Circle has NO volume!
        double volumeCalculate() override {
            cout << "[Circle] volume() NOT APPLICABLE - ISP VIOLATION!" << endl;
            return 0.0;
        }
};

class Rectangle: public Shape {
    private: 
        double width;
        double length;
        
    public: 
        Rectangle(double width, double length){
            this->length = length;
            this->width = width;
        }

        double areaCalculate() override {
            double area =  width*length;
            cout<<"Area of the rectangle with width: "<<width<<", and length: "<<length<<" is: "<<area<<endl;
            return area;
        }

        // ❌ EMPTY STUB! Rectangle has NO volume!
        double volumeCalculate() override {
            cout << "[Rectangle] volume() NOT APPLICABLE - ISP VIOLATION!" << endl;
            return 0.0;
        }
};

class Cube: public Shape {
    private: 
        double side;
        
    public: 
        Cube(double side){
            this->side = side;
        }

        // 3D shapes have surface area, but clients expect 2D area!
        double areaCalculate() override {
            cout << "[Cube] Surface area used as 2D area? CONFUSING!" << endl;
            return 6 * side * side;  // Surface area, not 2D area!
        }

        double volumeCalculate() override {
            double volume = side*side*side;
            cout<<"The volume of the shape Cube with side given "<<side<<" is: "<<volume<<endl;
            return volume;
        }
};

class GraphicsRenderer {
    private: 
        vector<Shape*> shapes;

    public:
        GraphicsRenderer(vector<Shape*> shapes){
            this->shapes = shapes;
        }
        void renderShapes(){
            for(auto shape: shapes){
                shape->areaCalculate();
                shape->volumeCalculate();
            }
        }
};

int main() {
    vector<Shape* > shapes;
    shapes.push_back(new Rectangle(4.8, 3));
    shapes.push_back(new Circle(4));
    shapes.push_back(new Cube(5));

    GraphicsRenderer* graphicsRenderer = new GraphicsRenderer(shapes);
    graphicsRenderer->renderShapes();
}