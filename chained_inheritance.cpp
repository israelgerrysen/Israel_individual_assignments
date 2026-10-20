#include <iostream>
#include<string>
using namespace std;
//base class
class GeometricObject{
    protected:
    string color;
    bool isFilled;

    public:
    GeometricObject(string c="white",bool filled=false)
    :color(c), isFilled(filled){}
    void displayGeometricObject()const{
        cout<<"Color: "<<color<<",Filled: "<<(isFilled? "Yes":"No")<<endl;
    }
};
//derived class 1
class Shape2D:public GeometricObject{
    protected:
    double xCoordinate;
    double yCoordinate;

    public:
    Shape2D(string c, bool filled, double x, double y)
    :GeometricObject(c,filled),xCoordinate(x),yCoordinate(y){}
    void displayPosition() const{
        cout<<"Position: ("<<xCoordinate<<","<<yCoordinate<<")"<<endl;
    }
};
//derived class 2
class rectangle: public Shape2D{
    protected:
    double length;
    double width;

    public:
    rectangle(string c, bool filled, double x, double y, double l, double w)
    :Shape2D(c, filled, x, y), length(l), width(w){}
    double calculateArea()const{
        return length*width;
    }
    void displayRectangle()const{
        cout<<"Rectangle Dimensions -Length: "<<length<<", Width: "<<width<<endl;
        cout<<"Area: "<<calculateArea()<<endl;
    }
};
//derived class 3
class square: public rectangle{
    public:
    square(string c, bool filled, double x, double y, double side)
    :rectangle(c, filled, x, y, side, side){}
    void displaySquare()const{
        cout<<"--Square Object (Cahined Inheritence Demonstration)--"<<endl;
        displayGeometricObject();
        displayPosition();
        cout<<"Square side: "<<length<<endl;
        cout<<"Area: "<<calculateArea()<<endl;
    }
};
int main(){
    square mySquare("Blue", true, 2.5, 4.0, 6.0);
    mySquare.displaySquare();
    return 0;
}
