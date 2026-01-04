#include <iostream>
#include <vector>

using namespace std;

class Shape2D {
    public:
        // 3D shapes do not need area method
        virtual double areaCalculate() = 0; // calculate area for the 2D shapes like rectangle, square, circle...
};

class Shape3D {
    public:
        // 2D shapes do not need volume method
        virtual double volumeCalculate() = 0; // calculate volume for the 3D shapes like cube..
};

class Circle : public Shape2D {
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
};

class Rectangle: public Shape2D {
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
};

class Cube: public Shape3D {
    private: 
        double side;
        
    public: 
        Cube(double side){
            this->side = side;
        }

        double volumeCalculate() override {
            double volume = side*side*side;
            cout<<"The volume of the shape Cube with side given "<<side<<" is: "<<volume<<endl;
            return volume;
        }
};

class GraphicsRenderer {
    private: 
        vector<Shape2D*> shapes2D;
        vector<Shape3D*> shapes3D;

    public:
        GraphicsRenderer(vector<Shape2D*> shapes2D, vector<Shape3D*> shapes3D){
            this->shapes2D = shapes2D;
            this->shapes3D = shapes3D;
        }
        void renderShapes(){
            for(auto shape: shapes2D){
                shape->areaCalculate();
            }
            for(auto shape: shapes3D){
                shape->volumeCalculate();
            }
        }
};

int main() {
    vector<Shape2D* > shapes2D;
    shapes2D.push_back(new Rectangle(4.8, 3));
    shapes2D.push_back(new Circle(4));
        
    vector<Shape3D* > shapes3D;
    shapes3D.push_back(new Cube(5));

    GraphicsRenderer* graphicsRenderer = new GraphicsRenderer(shapes2D, shapes3D);
    graphicsRenderer->renderShapes();
}