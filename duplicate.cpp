// 2) Design the logic to remove the duplicate elements from an Array and after the
// deletion the array should contain the unique elements
#include <iostream>
using namespace std;
# define MAX_SIZE 100

int main(){
    int arr[MAX_SIZE], n;
    
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements in your array:" << endl;
    for(int i = 0; i < n; i ++){
        cout << "Enter Element " << i+1 <<": ";
        cin >> arr[i];
    }
    cout << "Original Array: ";
    for(int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] == arr[i]){
                for(int k = j; k < n; k++){
                    arr[k] = arr[k+1];
                }
                n--;
                j--;
            }
        }
    }

    cout << "Unique Array: ";
    for(int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    return 0;
}