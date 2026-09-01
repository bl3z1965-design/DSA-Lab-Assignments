// 4) String Related Programs 
// (a) Write a program to concatenate one string to another string. 
// (b) Write a program to reverse a string. 
// (c) Write a program to delete all the vowels from the string. 
// (d) Write a program to sort the strings in alphabetical order. 
// (e) Write a program to convert a character from uppercase to lowercase.

#include <iostream>
// #include <string>
using namespace std;

void concatenate(char str1[], int maximum, char str2[]) {

    int i = 0;
    while(str1[i] != '\0') {
        i++;
    }

    int j = 0;
    while(str2[j] != 0 && i < maximum -1) {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str2[j] = '\0';
}

void reverse(char str[]){

    int size = 0;
    while(str[size] != '\0') {
        size++;
    }

    int temp, end = size - 1;

    for(int i = 0; i < size/2; i++){
        temp = str[i];
        str[i] = str[end];
        str[end] = temp;
        end--;
    }

}

bool isVowel(char ch){

    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');

}

void removeVowels(char str[]){

    int rid = 0, wid = 0;

    while(str[rid] != '\0'){
        if(!isVowel(str[rid])){
            str[wid] = str[rid];
            wid++;
        }
        rid++;
    }
    str[wid] = '\0';

}

void sortString(char str[]){

    int size = 0;
    while(str[size] != '\0'){
        size++;
    }    

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(str[j] > str[j + 1]){
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

char toLowerCase(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return ch + ('a' - 'A');
    }
    return ch;
}


void stringToLowerCase(char str[]){
    int size = 0;
    while(str[size] != '\0'){
        str[size] = toLowerCase(str[size]);
        size++;
    }
}

int main() {
    char str1[100], str2[50];
    
    cout << "Enter the first string: ";
    cin.getline(str1, 100);

    cout << "Enter the second string: ";
    cin.getline(str2, 50);

    concatenate(str1, 100, str2);
    cout << "Concatenated: " << str1 << endl;
    
    cout << "Enter a string to reverse: ";
    cin.getline(str1, 100);

    reverse(str1);
    cout << "Reversed: " << str1 << endl;

    cout << "Enter a string to remove vowels: ";
    cin.getline(str1, 100);

    removeVowels(str1);
    cout << "String without vowels: " << str1 << endl;

    cout << "Enter a string to arrange in alphabetical order (either lower or UPPER): ";
    cin.getline(str1, 100);

    sortString(str1);
    cout << "String in alphabetical order: " << str1 << endl;
    
    cout << "Enter a string to convert it to lowercase: ";
    cin.getline(str1, 100);

    stringToLowerCase(str1);
    cout << "String in lowercase: " << str1 << endl;

    return 0;
}