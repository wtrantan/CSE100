#include <iostream> 
#include <utility>
using namespace std;

void maxHeapify(int A[], int i, int n){
   int l = 2 * i + 1;//we look at the left child of the root
   int r = 2 * i + 2;// right child of the root
   int largest = i; // we state the largest as the root
   if(l < n && A[l] > A[largest]){
    largest = l; // if left child is larger than root, we make left child largest   

   }

   if(r< n && A[r] > A[largest]) {
    largest = r;// if right child is larger than root, we make right child largest
}
if (largest != i){ // if the largest is not equal to the root
    swap(A[i], A[largest]);// swap a[i] with largest
    maxHeapify(A, largest, n);// we recursively heapify the affected sub-tree
}

}
void buildMaxHeap(int A[], int n){
    for(int i = n/2-1; i >= 0; i--){
        maxHeapify(A, i, n); // rearrage array / roots and childs
    }


}

void heapSort(int A[], int n){
    buildMaxHeap(A, n);
    for(int i = n -1;i >= 0;i--){// after we rearrage array from biggest to smallest
        swap(A[0], A[i]); // we swap root to the end
        n = n-1; 
        maxHeapify(A, 0, i);// we then find the next biggest
    }

}

int main(){
    int size;
    int input;
    cin >> size;
    int A[size];

    
    for(int i = 0; i < size; i++){
    cin >> A[i];
    }
    heapSort(A, size);
    for(int j = 0; j < size; j++){
        cout << A[j] << ";" ;
    }
}