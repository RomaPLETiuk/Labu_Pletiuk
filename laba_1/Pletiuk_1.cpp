

/******************************************************************************

 P!QP2P>Q P8QP8 P:P;P0Q B+P:P>P<P?P;P5P:QP=P5 QP8QP;P>B;, QP0P:P8P9, Q	P>:
a) P9P>P3P> P5P:P7P5P<P?P;QQ  P<QQQP8QQ P4QP9QP=Q Q QQP2P=Q QP0QQP8P=Q - P7P<QP=P=Q P7 P?P;P0P2P0QQP>Q
QP>QP:P>Q.
b) P9P>P3P> P:P>P=QQQ QP:QP>Q  P1P5P7 P?P0Q P0P<P5QQ P0 QQP2P>Q QQ P5P:P7P5P<P?P;QQ  P7Q P7P=P0QP5P=P=QP< 0.0
+ 0.0i, P0 P:P>P=QQQ QP:QP>Q  P7 P?P0Q P0P<P5QQ P0P<P8 QQP2P>Q QQ P5P:P7P5P<P?P;QQ  P7
P2QP4P?P>P2QP4P=P>Q P4QP9QP=P>Q QP0 QQP2P=P>Q QP0QQP8P=P>Q.
c) P9P>P3P> P<P5QP>P4P8 P4P>P7P2P>P;QQQQ P>QQ P8P<QP2P0QP8 Q P?Q P8QP2P>QP2P0QP8 P7P=P0QP5P=P=Q P4QP9QP=P>Q
QP0 QQP2P=P>Q QP0QQP8P=P8.
d) QQP=P:QQQ print () P2P8P2P>P4P8QQ P=P0 P5P:Q P0P= P7P=P0QP5P=P=Q P5P:P7P5P<P?P;QQ P0 Q P2P8P3P;QP4Q
(0.00 B1 0.00i).

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


int
main ()
{

  Complex complex;

  complex.getComplex ();
  complex.showComplex ();

  return 0;
}
