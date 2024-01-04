#include <iostream>

using namespace std;

int partition (int A[], int p, int r){
    int x = A[r]; //pivot the end index
    int i = p - 1; //index of the smaller element 
    for(int j = p; j <= r-1; j++){
        if(A[j] <= x){ //if current element is smaller than pivot
            i = i +1; //increment index of smaller element
            swap(A[i], A[j]); //we swap smaller with current index
        }
    }
    swap(A[i+1], A[r]);  //swap right of smaller index and the end of the index
    return i + 1; //returns the value to a new pivot that splits in half the array
}

void quickSort(int A[], int p, int r){
    if(p<r){  //continues the partition until p is no longer p < r
        int q = partition(A, p, r); //q is the partition index
        quickSort(A, p, q-1);  // separately sort elements of lower half
        quickSort(A, q+1,r); // separately sort elements of upper half
    }
}

int main(){
    int size, in;
    cin >> size;
    int array[size];
    
    for(int i = 0; i < size; i++){
        cin >> array[i];
    }

    quickSort(array, 0, size-1);
    for(int i = 0; i < size; i++){
        cout << array[i] <<";";
    }
}