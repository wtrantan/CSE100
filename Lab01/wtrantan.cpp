
#include <iostream>
using namespace std;
int main(){
    int size = 0;
    int i, key, j;
    int arr = 0;
    cin >> size;
    int array[size];

    //array input
    for(int k = 0; k < size; k++){
        cin >> arr;
        array[k] = arr;
    }

//Insertion Sort (Used textbook page 18 for help)
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;

        for (int x = 0; x < i+1; x++)
        cout << array[x] << ";";
     cout << endl;
    }
     
   
}



