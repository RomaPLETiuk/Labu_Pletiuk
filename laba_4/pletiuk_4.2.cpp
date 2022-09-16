#include <iostream>
#include <cstdlib>
using namespace std;
int i;
class Array {
int *m;
int n;
public:
    Array(int k) {
    cout << "Constructor with parametr" << endl;
    n=k;
    m=new int[n];
    setData();
    }
~Array() {
    delete m;
    cout << "\nDestructor." << endl;
}
void setData() {
for(i=0;i<n;i++) {
    if(i%2==0) {
        m[i]=i+3;
    }
    else {
        m[i]=i-7;
    }
}
output();
}
void output() {
    cout << "Kilkist elementiv: " << endl;
    for(i=0;i<n;i++){
    cout << m[i] << " ";
}}
 
friend void sumOnlyThirdEl(Array obj);
};
void sumOnlyThirdEl(Array obj) {
    int sum=0;
cout << "\nKojen tretiy element: "<<obj.m<<"\n";
for(i=0;i<obj.n;i++) {
    if((i+1)%3==0) {
        cout << obj.m[i] << " ";
        sum=sum+obj.m[i];
    }
} cout << endl;
cout << "Summa tretiyh elementiv: " << sum;
}
int main(){
Array arr(11);
sumOnlyThirdEl(arr);

return 0;
}