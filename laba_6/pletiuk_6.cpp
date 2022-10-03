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
    PrintEdition()
    {
        this->name = " ";
        this->year = 1986;

    }

    PrintEdition(int year, string name) {
        this->name = name;
        this->year = year;
        
    }

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
    Book(int year, string name, string autor)
        :PrintEdition(year,  name)
    {
        
        this->autor = autor;
    
    }
    
    Book() {
        this->autor = "Чарльз";
    }
    ~Book() {}
    void setAutor(string text) { autor = text; }
    string getAutor() { return autor; }
    void show();
};

class Journal : public PrintEdition
{
protected:
    int day;
    int moth;
public:

    
    Journal(string name, int year, int day,  int moth)
        :PrintEdition(year,  name)
    {
        this->day = day;
        this->moth = moth;
    
    }
    Journal() {
        this->day = 1;
        this->moth = 1;
    
    
    }
    ~Journal() {}

    void setDay(int day) {
        this->day = day;

    }
    int getDay() { return day; }

    void setMoth(int moth) {
        this->moth = moth;

    }
    int getMoth() { return moth; }
    void show();
};


class Edubook : public Book
{

    string subject;
    int klas;
public:
    Edubook(string subject, int klas, int year, string name, string autor) 
        :Book(year, name, autor)
    {
        this->klas = klas;
        this->subject = subject;
    }

    Edubook() {
        this->klas = 11;
        this->subject = " м";

    }

    ~Edubook() {

    }


    void setKlas(int klas) {
        this->klas = klas;

    }
    int getKlas() { return klas; }

    void setSubject(string text) { subject = text; }
    string getSubject() { return subject; }
    void show();


};


void Book::show()
{
    cout << "Книга: " << " " << getName() << endl;
    cout << "Рік виходу: " << getYear() << "р. \n";
    cout << "Автор: " << autor << endl << endl;
}

void Journal::show()
{
    cout << "Журнал: " << getName() << endl;
    cout << "Дата виходу: " << getYear() << "р., " << moth << " місяця, " << day << " дня." << endl << endl;
}


void Edubook::show() {

    cout << "Підручник: " << getName() << endl;
    cout << "Року виходу " << getYear() << "р. " << endl;
    cout << "З предмету: " << subject << endl;
    cout << "Для учнів " << klas << " класу" << endl << endl;

}

int main()
{
    setlocale(0, "Ukr");
    Book b(1895, " Капітан нa острові", "Тарас шевченко");
    Journal j("Сад і город", 1999, 5, 12);
    Edubook e("УКрМова", 5, 1895, " Українська мова", "Пилипенко");



   /* b.setName("Капітан на острові");
    b.setYear(2002);
    b.setAutor("Тарас Шевченко");

    j.setMoth(12);
    j.setName("Шишкін лес");
    j.setYear(2021);
    j.setDay(28);

    e.setName("Історія");
    e.setYear(1995);
    e.setSubject("Історія України");
    e.setKlas(5);
    */
    b.show();
    j.show();
    e.show();
}
