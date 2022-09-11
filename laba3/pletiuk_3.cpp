#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Studing
{
    string name; // ім'я
    string surname; // прізвище
    int math; // математика
    int physics; // фізика
    int informatics; // інформатика
public:

    void setInfo(string name, string surname, int math, int physics, int informatics)
    {
        this->name = name;
        this->surname = surname;
        this->math = math;
        this->physics = physics;
        this->informatics = informatics;
    }
    string getName() {
        return name;
    }
    string getSurname() {
        return surname;
    }
    int getMath() {
        return math;
    }
    int getPhysics() {
        return physics;
    }
    int getInformatics() {
        return informatics;
    }

    void print() {
        cout << name << " " << surname << ". Оцінки: математика: " << math << ", фізика: " << physics << ", інформатика: " << informatics << endl;
    }

};


using namespace std;

int main() {

    string name, surname, str;
    int math, physics, informatics, value, sum = 0, count = 0;

    fstream out_file;
    ifstream file("data.txt");

    if (file) {
        while (!file.eof()) {
            getline(file, str, '\n');
            count++;
        }

        Studing* students = new Studing[count];

        file.clear();
        file.seekg(0);

        for (int i = 0; i < count; i++) {
            file >> name;
            file >> surname;
            file >> math;
            file >> physics;
            file >> informatics;

            students[i].setInfo(name, surname, math, physics, informatics);
        }


        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (students[i].getName() > students[j].getName()) {
                    swap(students[i], students[j]);
                }
            }
        }
         /*for(int r=0;r<10;r++)
         students[r].print();*/

        cout<<"\nВведіть бал по фізиці, щоб отримати кількість студентів з заданим балом: ";
        cin>>value;

        for (int i = 0; i < count; i++) {
            if (students[i].getPhysics() == value) {
                sum++;
                students[i].print();
            }
        }
        cout<<"\nКількість студентів з заданим балом: "<< sum;

    }
    else
        cout << "File error";
    file.close();

}