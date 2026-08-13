// 3) Design the logic of a program to rotate a 1-D array by K positions.
// e.g., for A = {1,2,3,4,5} and K = 2, the left rotation is {3,4,5,1,2} and the right
// rotation is {4,5,1,2,3}
#include <iostream>
using namespace std;
#define MAX_SIZE 100

int main(){
    int arr[MAX_SIZE], n, k;
    cout << "Enter the size of array: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "Enter Element " << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "Enter how many positions you want to shift the array: ";
    cin >> k;
    k = k % n;
    cout << "Original Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < k; i++){
        int temp = arr[0];
        for(int j = 1; j < n; j++){
            arr[j - 1] = arr[j];
        }
        arr[n-1] = temp;
    }
    cout << "Rotated Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}