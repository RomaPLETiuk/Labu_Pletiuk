/******************************************************************************

                             23.09.22

*******************************************************************************/

#include <conio.h>
#include <iostream>
#include <conio.h>
#include <cmath>
 
using namespace std;
 
class Kvadrat
{
private:
    double side;
    double area;
    
public:
 
    Kvadrat()
    {
        this->side = 0.0;
        this->area = side*side;
    }
 
    Kvadrat(double side)
    {
       this->side = side;
       this->area = pow(side,2);
    }
    
    double getSide() {
            return side; 
        }
    double getArea() {
            return area; 
        }
     
 
    void setSide(double side){
            this->side=side;
        }
        
        
   Kvadrat operator +(Kvadrat z) {
       
       double S = this->area+z.area;
       
       double side = sqrt(S);
       Kvadrat newKvadrat(side);
       return newKvadrat;
   }    
        
        
    
   Kvadrat operator ++()// префіксна форма інкременту 
   {

    side++; 
    return *this;
    }
 
   Kvadrat operator ++(int notused) // постфіксна форма інкременту
	{
		Kvadrat temp = *this;
	    side++;
		return temp;
	}
	
    friend ostream& operator <<(ostream& t, Kvadrat a);
    
};  


    ostream& operator <<(ostream& t, Kvadrat a)
	{
		t << "side =" << a.side << ", area =" << a.area << endl;
		return t;
	}


 
int main()
{
    setlocale(LC_ALL, "Ru");
 
   Kvadrat a(5), b(4), c;
   // a = ++b;
   ++b;
   cout<<b;
   c=a+b;
   cout <<c;
    return 0;
}
