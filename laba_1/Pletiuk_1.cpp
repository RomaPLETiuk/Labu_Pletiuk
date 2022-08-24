

/******************************************************************************

 Створити клас «комплексне число», такий, що:
a) його екземпляр містить дійсну і уявну частину - змінні з плаваючою
точкою.
b) його конструктор без параметра створює екземпляр зі значенням 0.0
+ i0.0, а конструктор з параметрами створює екземпляр з
відповідною дійсною та уявною частиною.
c) його методи дозволяють отримувати і присвоювати значення дійсної
та уявної частини.
d) функція print () виводить на екран значення екземпляра у вигляді
(0.00 ± i0.00).

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
    Complex ()
  {
    this->real = 0.0;
    this->imagine = 0.0;

  }
  Complex (double real, double imagine)
  {
    this->real = real;
    this->imagine = imagine;

  }
  void showComplex ()
  {
    if (imagine >= 0)
      cout << real << "+" << imagine << "i" << endl;
    else
      cout << real << imagine << "i" << endl;
  }
  void getComplex ()
  {

    cout << "Enter real and imagine part of complex number" << endl;
    cin >> real >> imagine;

  }

};


int main ()
{

  Complex complex;

  complex.getComplex ();
  complex.showComplex ();

  return 0;
}
