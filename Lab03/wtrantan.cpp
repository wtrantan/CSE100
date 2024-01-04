#include <iostream>
#include <limits.h>
using namespace std;

int maxCross(int a[], int low, int mid, int high){
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft;
    int maxRight;
    for(int i = mid; i >= low; i--){
        sum = sum + a[i];
        if(sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    int rightSum = INT_MIN;
    sum = 0;
    for(int j = mid + 1; j <= high; j++){
        sum = sum + a[j];
        if(sum > rightSum){
            rightSum = sum;
            maxRight = j;
        }
    }
    return (maxLeft, maxRight, leftSum + rightSum);
}
int findMaxSubarray(int a[], int low, int high) {
    int leftLow, rightLow, leftHigh, rightHigh, leftSum, rightSum, crossLow, crossHigh, crossSum;
    if(high == low) {
       return (low, high, a[low]);
    } else{
        int mid = (low + high)/2;
        (leftLow, leftHigh, leftSum) = findMaxSubarray(a, low, mid);
        (rightLow, rightHigh, rightSum) = findMaxSubarray(a, mid + 1, high);
        (crossLow, crossHigh, crossSum) = maxCross(a, low, mid, high); 
        if(leftSum >= rightSum && leftSum >= crossSum){
            return (leftLow,leftHigh, leftSum); 
        } else if(rightSum >= leftSum && rightSum >= crossSum){
            return (rightLow, rightHigh, rightSum);
        } else{
            return (crossLow, crossHigh, crossSum);
        }
    }
    return 0;
}

int main(){
     int size;
    cin >> size;
    int a[size];
    for(int i = 0; i < size; i++){
        cin >> a[i];
    }
    int maxSum = findMaxSubarray(a, 0, size-1);
    cout<< maxSum; 
    return maxSum; 
}