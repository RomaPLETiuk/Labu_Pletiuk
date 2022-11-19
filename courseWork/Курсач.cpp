
/***************************************************************
Клас, що містить наступні властивості:
•	назва пункту призначення;
•	номер потягу;
•	кількість  місць;
•	кількість пасажирів, бажаючих їхати;
•	функція, яка повертає кількість вільних місць
•	функція, яка повертає кількість незадоволених пасажирів (не вистачило місця)

•	Додатковий потяг формується, якщо кількість незадоволених пасажирів перевищує 60% від кількості  місць потягу.
•	Створення динамічного масиву об'єктів «потяг», розмірність якого дорівнює кількості рядків у файлі;
•	читання з файлу in.txt даних у масив об’єктів  «потяг»;
•	вивід на дисплей і у файл  пункти призначення, куди треба подати додаткові потяги. Записи мають бути впорядковані по алфавіту.
***************************************************************
Виконав Плетюк Роман Михайлович, студент ІТ НУБІП України
***************************************************************/
#include <iostream> 
#include <vector> 
#include <fstream>
#include <locale.h>

using namespace std;

class Station {
protected:

    string destName;

public:

    Station() { //Конструктор за замовчуванням
        this->destName = "Київ";
    }

    Station(string destName) { //Конструктор c параметром
        this->destName = destName;
    }

    //Сетери
    void setDestName(string destName) {
        this->destName = destName;
    }

    //Гетери
    string getDestName() {
        return destName;
    }
};

class Passenger {

protected:

    int passAmount;

public:

    Passenger() { //Конструктор за замовчуванням
        this->passAmount = 120;
    }

    Passenger(int passAmount) { //Конструктор c параметром
        this->passAmount = passAmount;
    }

    //Сетери
    void setPassAmount(int passAmount) {
        this->passAmount = passAmount;
    }
    // Гетери
    int getPassAmount() {
        return passAmount;
    }

};

class Train : public Station, public Passenger {

    string trNumber;
    int seatAmount;

public:
    //Конструктор c параметром
    Train(string trNumber, int seatAmount)
        :Station(destName), Passenger(passAmount)
    {                                                  
        this->trNumber = trNumber;
        this->seatAmount = seatAmount;
    }
    //Конструктор за замовчуванням
    Train() {                                           
        this->trNumber = "A67";
        this->seatAmount = 120;

    }

    //Сетери  
    void setTrainNumber(string trNumber) {
        this->trNumber = trNumber;
    }

    void setSeatAmount(int seatAmount) {
        this->seatAmount = seatAmount;
    }

    //гетери
    string getTrainNumber() {
        return trNumber;
    }

    int getSeatAmount() {
        return seatAmount;
    }
    int getFreeSeatsAmount() { //Функція розрахунку кількості пустих місць
        if (seatAmount > passAmount) {
            return seatAmount - passAmount;
        }
        else {
            return 0;
        }
    }

    int getPassOverflowAmount() { //Функція розрахунку кількості недовольних пасажирів (не хватило місця)
        if (passAmount > seatAmount) {
            return passAmount - seatAmount;
        }
        else {
            return 0;
        }
    }

    bool isNewTrainNeeded() { //Функція перевірки чи потрібен додадковий потяг
        if (getPassOverflowAmount() > getSeatAmount() * 60 / 100) {
            return true;
        }
        return false;
    }

    friend ifstream& operator >>(ifstream& t, Train& s);  // читання з файлу
    friend ostream& operator <<(ostream& t, Train& s);    // вивід на екран
    friend ofstream& operator <<(ofstream& t, Train& s);  // вивід  у файл
};

ifstream& operator >>(ifstream& t, Train& s)
{
    t >> s.destName;
    t >> s.trNumber;
    t >> s.seatAmount;
    t >> s.passAmount;

    return t;
}

ostream& operator <<(ostream& t, Train& s)
{
    t << " " << s.destName << "    " << s.trNumber << "   тому що кількість пасажирів: " << s.passAmount << ", а кількість мість:" << s.seatAmount << endl;
    return t;
}
ofstream& operator <<(ofstream& t, Train& s)
{
    t << s.destName << "   " << s.trNumber << "   тому що кількість пасажирів: " << s.passAmount << ", а кількість мість:" << s.seatAmount << endl;
    return t;
}



int main() {
    setlocale(LC_ALL, "Ukr");

    int Selection;

    cout << "\tМ Е Н Ю\n  -------------------\n";
    cout << "\t1. Аналіз файлу <in.txt> \n";
    cout << "\t2. Вивід інформації в консоль\n";
    cout << "\t3. Запис в файл <out.txt>\n";
    cout << "\t4. Вихід";

    ifstream fin("in.txt");
    ofstream fout("out.txt");

    vector<Train> trains;    //динамічний масив 
    if (!fin)
    {
        cout << "Can't open file";
        return 0;
    }
    if (!fout)
    {
        cout << "Can't create file";
        return 0;
    }

 while (1){
   cout << "\n\n\tВАШ вибір: ";
   cin >> Selection;

   switch (Selection){
   case 1:

      while (!fin.eof())
      {
        fin.ignore(255, '\n');
        Train tr;
        fin >> tr;
        if (tr.isNewTrainNeeded())
            trains.push_back(tr);
      }
       for (int i = 0; i < trains.size(); i++) {                           //алгоритм сортування 
         for (int j = i + 1; j < trains.size(); j++) {
            if (trains[i].getDestName() > trains[j].getDestName()) {       //в алфавітному порядку
                swap(trains[i], trains[j]);

             }
          }
        }
    cout << "Інформацію проаналізовано виберіть наступну дію (2 або 3) ";

   break;

   case 2:
       cout << "Потрібні додаткові вагони для: " << "\n" << "  станція | номер \n" << "          | " << "потяга" << "\n";
       for (int i = 0; i < trains.size(); i++)
       {
           cout << trains[i];
       }

   break;

   case 3:
       fout << "Потрібні додаткові вагони для: " << "\n" << "   станція | номер \n" << "           | " << "потяга" << "\n";
       for (int i = 0; i < trains.size(); i++)
       {
           fout << "  " << trains[i];
       }

   cout << "Інформацію виведено у файл. Перегляньте файл out.txt ";

   break;

   case 4:
       fin.close();
       fout.close();
       exit(0);
   break;
   }
 }
}
