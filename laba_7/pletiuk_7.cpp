
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

class Shape {
private:
    string name;

public:
    Shape()
    {
        this->name = " ";

    }

    Shape(string name)
    {
        this->name = name;

    }

    string GetName()
    {
        return name;
    }

    void SetName(string name)
    {
        this->name = name;
    }

    virtual double getArea() = 0;
};


class Trapeze : public Shape {
public:

    int a;
    int b;
    int h;

    Trapeze(int a, int b, int h)
        : Shape("Трапеція")
    {
        this->a = a;
        this->b = b;
        this->h = h;
    }

    Trapeze()
        : Shape("Трапеція")
    {
        this->a = 1;
        this->b = 1;
        this->h = 1;
    }
    double getArea() override {
        return (h * (a + b) / 2.0);
    }
};

class Triangle : public Shape {
public:
    int a;
    int b;
    int c;

    Triangle()
    {
        this->a = 1;
        this->b = 1;
        this->c = 1;
    }

    Triangle(int a, int b, int c)
        : Shape("Трикутник")
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double getArea() override {
        float s = (float)(a + b + c) / 2;
        return (sqrt(s * (s - a) * (s - b) * (s - c)));
    }
};

class Equtriangle : public Shape {
public:
    int a;
    Equtriangle()

    {
        this->a = 1;
    }


    Equtriangle(int a)
        : Shape("Рівносторонній_трикутник")
    {
        this->a = a;
    }

    double getArea() override {

        return (a * a) * 0.433;
    }
};


int main(void) {

    Shape* A[4];
    Trapeze trap(5, 7, 4);
    Triangle  trian(5, 7, 4);
    Equtriangle etrian(4);

    A[0] = &trap;
    A[1] = &trian;
    A[2] = &etrian;

    for (int i = 0; i < 3; i++)
       cout << A[i]->getArea()<<"\n";


    //cout << "Total Trapeze area: " << trap.getArea() << endl;

    //cout << "Total Triangle area: " << trian.getArea() << endl;

    //cout << "Total equilateral triangle area: " << etrian.getArea() << endl;
    

    return 0;
}

