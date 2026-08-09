// 1) DevelopaMenudrivenprogramtodemonstrate the followingoperations ofArrays
// ——MENU——-
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.LINEAR SEARCH
// 6.EXIT
#include <iostream>
using namespace std;

#define MAX_SIZE 100

void CreateArray(int arr[], int &n){
    cout << "\nCreating Array:" << endl;
    n = 0;
    cout << "Enter the size of array: ";
    cin >> n;
    if(n <= 0 || n > MAX_SIZE){
        cout << "Size of the Array cannot be 0 or less than 0 or more than 100" << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        cout << "Enter Element " << i+1 << ": ";
        cin >> arr[i];
    }
}

void DisplayArray(int arr[], int n){
    cout << "\nDisplaying Array:" << endl;
    if(n <= 0){
        cout << "Cannot display array: Array has not been allocated" << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void InsertArray(int arr[], int &n){
    if(n <= 0){
        cout << "Cannot insert element: Array has not been allocated" << endl;
        return;
    }
    cout << "\nInstering element in Array:" << endl;
    int element, position;
    cout << "At which position do you want to insert an element 1-" << n+1 << ": ";
    cin >> position;
    if(position < 1 || position > n+1){
        cout << "Array index out of bounds" << endl;
        return;
    }
    cout << "Enter the element you want to insert: ";
    cin >> element;
    for(int i = n; i > position - 1; i--){
        arr[i] = arr[i-1];
    }
    arr[position - 1] = element;
    n++;
}

void DeleteArray(int arr[], int &n){
    if(n <= 0){
        cout << "Cannot delete element: Array has not been allocated" << endl;
        return;
    }
    cout << "\nDeleting element in Array:" << endl;
    int element, position;
    cout << "From which position do you want to delete an element 1-" << n << ": ";
    cin >> position;
    if(position < 1 || position > n){
        cout << "Array index out of bounds" << endl;
        return;
    }
    for(int i = position-1; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    n--;
}

void LinearSearch(int arr[], int n){
    if(n <= 0){
        cout << "Cannot apply linear search: Array has not been allocated" << endl;
        return;
    }
    int element;
    cout << "Which element do you want to find: ";
    cin >> element;
    for(int i = 0; i < n; i++){
        if(arr[i] == element){
            cout << "Element " << element << " found at position " << i+1 << " (index " << i <<")" << endl;
            return;
        }
    }
    cout << "Element " << element << " not found" << endl;
}
int main(){
    int arr[MAX_SIZE];
    int n = 0;
    int choice = 0;
    while(choice != 6){
        cout << "——MENU——" << endl;
        cout << "1.CREATE\t";
        cout << "2.DISPLAY\t";
        cout << "3.INSERT\t";
        cout << "4.DELETE\t";
        cout << "5.LINEAR SEARCH\t\t";
        cout << "6.EXIT\t"<< endl;
        cout << "Choose an option from th Menu (1-6): ";
        cin >> choice;
        switch(choice){
            case 1:
                CreateArray(arr, n);
                break;
            case 2:
                DisplayArray(arr, n);
                break;
            case 3:
                InsertArray(arr, n);
                break;
            case 4:
                DeleteArray(arr, n);
                break;
            case 5:
                LinearSearch(arr, n);
                break;
            case 6:
                cout << "Exiting the Menu" << endl;
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}
