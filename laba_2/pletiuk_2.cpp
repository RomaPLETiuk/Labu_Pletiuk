/******************************************************************************
 Створити клас «комплексне число», такий, що:
a) його екземпляр містить дійсну і уявну частину - змінні з плаваючою
точкою.
b) його конструктор без параметра створює екземпляр зі значенням 0.0
+ 0.0i, а конструктор з параметрами створює екземпляр з
відповідною дійсною та уявною частиною.
c) його методи дозволяють отримувати і присвоювати значення дійсної
та уявної частини.
d) функція print () виводить на екран значення екземпляра у вигляді
(0.00 ± 0.00i).
e) дружня функція frd в якості параметрів отримує екземпляри двох
«комплексних чисел», і повертає нове «комплексне число», дійсна і
уявна частини якого дорівнюють сумам дійсних і уявних частин
цих двох «комплексних чисел».
*******************************************************************************/
#include <iostream>
#include <string>
#include <list>


using namespace std;

class Complex
{
private:
    double real;
    double imagine;

public:
    
    Complex()
    {
        this->real = 0.0;
        this->imagine = 0.0;

    }
    Complex(double real, double imagine)
    {
        this->real = real;
        this->imagine = imagine;

    }

    double getReal() {
        return real;
    }
    double getImagine() {
        return imagine;
    }
    void setReal(double real) {
        this->real = real;
    }

    void setImagine(double imagine) {
        this->imagine = imagine;
    }

    void showComplex()
    {
       cout<<::noshowpos<<real;
       cout<<::showpos<<imagine<<"i";
    }
    
    friend Complex frd(Complex, Complex);
};

Complex frd(Complex c1, Complex c2){
    Complex tmp;
    tmp.real= c1.real+c2.real;
    tmp.imagine = c1.imagine+c2.imagine;
    return tmp;

}


int main()
{
    Complex c1(2.2, -1.5), c2(3.2, -3.8), c3;
    c3= frd(c1, c2);
cout<<"\n c1=";
c1.showComplex();
cout<<"\n c2=";
c2.showComplex();
cout<<"\n c3=";
c3.showComplex();
    return 0;
}
