#include <iostream>
using namespace std;

void merge(int array[], int left, int mid, int right){

    int leftArray = mid - left + 1;
    int rightArray = right - mid;

    int lArray[leftArray];
    int rArray[rightArray];
    for(int i = 0; i < leftArray; i++){
        lArray[i] = array[left + i];
    } 
    for(int j = 0; j < rightArray; j++){
        rArray[j] = array[mid + 1 + j];
    }

    int leftIndex = 0, rightIndex = 0, mergeIndex = left;

    while (leftIndex < leftArray && rightIndex < rightArray){
        if(lArray[leftIndex] <= rArray[rightIndex]){
            array[mergeIndex] = lArray[leftIndex];
            leftIndex++;
        } else {
            array[mergeIndex] = rArray[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }
    while(leftIndex < leftArray){
        array[mergeIndex] = lArray[leftIndex];
        leftIndex++;
        mergeIndex++;

    }

   while(rightIndex < rightArray){
        array[mergeIndex] = rArray[rightIndex];
        rightIndex++;
        mergeIndex++;

    }  

}
void mergeSort(int array[], int begin, int end){
    if (begin < end){
        int mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    } else{
        return;
     }
    
}
int main(){
    int size, k;
    cin >> size;
    int array[size];
    for(int i = 0; i < size; i++){
        cin >> k;
        array[i] = k;
    }
    mergeSort(array, 0, size-1);
    for(int i = 0; i < size; i++){
        cout << array[i] << ";";
    }
    
} 




