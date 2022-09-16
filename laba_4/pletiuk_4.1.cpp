/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <list>
#include <iostream>

using namespace std;


class Array {
private:
    list<int> nums;
public:
    Array(int n) {
        srand(time(0));
        for (int i = 0; i < n; i++) {
            int val = rand() % 10;
            
            if (val % 2 == 0) {
                nums.push_front(val + 3);
            } else {
                nums.push_front(val - 7);
            }
        }
    }

    ~Array() {
        nums.clear();
        nums.empty();
    }

    list<int> getNums() {
        return nums;
    }

    void printElements() {
        for (int n: nums) {
            cout << n << " ";
        }
        cout<<endl;
    }
};



int sumOfOddElements(Array a) {
    int sum = 0;
    list<int> nums = a.getNums();
    for (int n: nums) {
        
     /* if(n == 0 && n > 11){
            sum += n;
        }  */
          if ((n + 1) % 3 == 0) {
              sum = sum + n;
          }

    }
    return sum;
}



int main() {
    Array array(11);
    array.printElements();
    int res = sumOfOddElements(array);
    cout << res;

}
