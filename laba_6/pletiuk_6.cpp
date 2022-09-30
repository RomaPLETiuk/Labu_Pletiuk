/******************************************************************************
журнал, книга, друковане видання, підручник;

      30.09.2022 
                     by Roman Pletiuk

*******************************************************************************/
#include <iostream>
#include <locale.h>

using namespace std;

class PrintEdition
{
protected:
  int year;  
  string name; 
public:

   void setYear(int year) { 
       this->year = year; 
       
   }
   
   int getYear() {
       return year;
       }
       
   void setName(string text) { name = text; }
   
   string getName() { 
       return name; 
       
   }
};

class Book : public PrintEdition
{
  
  string autor; 
  
public:
  Book(){}
  ~Book(){}
  void setAutor(string text) { autor = text; }
  string getAutor() { return autor; }
void show ();
};

class Journal : public PrintEdition
{
protected:
   int day;
   int moth;
public:
   Journal(){}
   ~Journal(){}

   void setDay(int day) { 
       this->day = day; 
       
   }
   int getDay() { return day; }
   
   void setMoth (int moth) { 
       this->moth = moth; 
       
   }
   int getMoth() { return moth; }
void show ();
};


class Edubook : public Book
{
    
    string subject;
    int klas;
 public:   
   Edubook(){
       
   }
   
   ~Edubook(){
       
   }
   
  
   void setKlas (int klas) { 
       this->klas = klas; 
       
   }
   int getKlas() { return klas; }
   
   void setSubject(string text) { subject = text; }
   string getSubject() { return subject; }
   void show (); 
    
    
};


void Book::show()
{
cout<<"Книга: "<<" "<<getName()<<endl;
cout<<"Рік виходу: "<<getYear()<<"р. \n";
cout<<"Автор: "<<autor<<endl<<endl;
}

void Journal::show()
{
cout<<"Журнал: "<<getName()<<endl;
cout<<"Дата виходу: "<<getYear() <<"р., "<<moth<<" місяця, "<<day<<" дня."<<endl<<endl;
}


void Edubook::show(){
    
cout<<"Підручник: "<<getName()<<endl;
cout<<"Року виходу "<<getYear() <<"р. "<<endl;
cout<<"З предмету: "<<subject<<endl;
cout<<"Для учнів "<<klas<<" класу"<<endl<<endl;
    
}

int main()
{
  setlocale(0, "Ukr")  
Book b;
Journal j;
Edubook e;
b.setName("Капітан на острові");
b.setYear(2002);
b.setAutor("Тарас Шевченко");

j.setMoth (12);
j.setName("Шишкін лес");
j.setYear(2021);
j.setDay(28);

e.setName("Історія");
e.setYear(1995);
e.setSubject("Історія України");
e.setKlas (5);

b.show();
j.show();
e.show();
}
