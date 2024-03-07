#include "NumberList.h"
#include <algorithm>
using namespace std;

void NumberList::Init() {  // count will be 0
    this->count = 0;
    for (int i = 0; i < 10; i++) {
        this->numbers[i] = 0;
    }
}
bool NumberList::Add(int x) {  // adds X to the numbers list and increase the data member count.
    
    if (count <= 9) {
        numbers[count] = x;
        count++;
        return true;
    }
    else
    {
        return false;
    }
    
    
}
// if count is bigger or equal to 10, the function will return false
void NumberList::Sort() {   // will sort the numbers vector

    int ultim = count;
    int temp = 0;
    int penultim = ultim - 1;
    for (int i = 0; i < ultim; i++) {
        for (int j = 0; j < penultim; j++) {
            if (numbers[j] > numbers[j+1]) {
                temp = numbers[j+1];
                numbers[j+1] = numbers[j];
                numbers[j] = temp;
            }
        }
        penultim--;
        
    }

}
void NumberList::Print() { // will print the current vector
    for (int i = 0; i < count; i++) {

        cout << numbers[i] << " ";
    }
}
