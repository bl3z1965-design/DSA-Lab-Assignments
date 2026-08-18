#include <iostream>
using namespace std;

int main(){
    int arr[4][6] = {
        {0, 0, 0, 0, 5, 0},
        {9, 0, 3, 0, 0, 0},
        {0, 0, 0, 8, 7, 0},
        {0, 13, 0, 0, 0, 0}
    };
    int k = 1;
    int sparse[100][3];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 6; j++){
            if(arr[i][j] != 0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = arr[i][j];
                k++;
            }
        }
    }
    sparse[0][0] = 4;
    sparse[0][1] = 6;
    sparse[0][2] = k-1;
    cout << "Row\t" << "Column\t" << "Value" << endl;
    for(int i = 0; i <= sparse[0][2]; i++){
        cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << endl;
    }

    int transpose[100][3];
    k = 1;
    for(int i = 0; i < sparse[0][1]; i++){
        for(int j = 1; j <= sparse[0][2]; j++){
            if(sparse[j][1]==i){
                transpose[k][0] = sparse[j][1];
                transpose[k][1] = sparse[j][0];
                transpose[k][2] = sparse[j][2];
                k++;
            }
        }
    }
    transpose[0][0] = sparse[0][1];
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];

    cout << "Row\t" << "Column\t" << "Value" << endl;
    for(int i = 0; i <= transpose[0][2]; i++){
        cout << transpose[i][0] << "\t" << transpose[i][1] << "\t" << transpose[i][2] << endl;
    }
    
    return 0;
}