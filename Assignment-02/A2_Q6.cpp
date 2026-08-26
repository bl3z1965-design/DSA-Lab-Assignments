#include <iostream>
using namespace std;

#define MAX 100

class SparseMatrix {
public:
    int data[MAX][3];
    int terms;

    SparseMatrix() {
        terms = 0;
        data[0][0] = data[0][1] = data[0][2] = 0;
    }

    void readMatrix(int rows, int cols) {
        int mat[20][20];
        cout << "Enter elements row-wise (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> mat[i][j];

        terms = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] != 0) {
                    terms++;
                    data[terms][0] = i;
                    data[terms][1] = j;
                    data[terms][2] = mat[i][j];
                }
            }
        }
        data[0][0] = rows;
        data[0][1] = cols;
        data[0][2] = terms;
    }

    void display() {
        if (terms == 0) {
            cout << "(Matrix has no non-zero terms)\n";
            return;
        }
        cout << "Row\tCol\tValue\n";
        for (int i = 1; i <= terms; i++)
            cout << data[i][0] << "\t" << data[i][1] << "\t" << data[i][2] << "\n";
    }

    void displayAsGrid() {
        int rows = data[0][0], cols = data[0][1];
        int k = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (k <= terms && data[k][0] == i && data[k][1] == j) {
                    cout << data[k][2] << "\t";
                    k++;
                } else {
                    cout << "0\t";
                }
            }
            cout << "\n";
        }
    }
};

void transpose(SparseMatrix &a, SparseMatrix &result) {
    int rows = a.data[0][0];
    int cols = a.data[0][1];
    int t = a.data[0][2];

    result.terms = 0;

    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= t; i++) {
            if (a.data[i][1] == c) {
                result.terms++;
                result.data[result.terms][0] = a.data[i][1];
                result.data[result.terms][1] = a.data[i][0];
                result.data[result.terms][2] = a.data[i][2];
            }
        }
    }

    result.data[0][0] = cols;
    result.data[0][1] = rows;
    result.data[0][2] = result.terms;
}

bool add(SparseMatrix &a, SparseMatrix &b, SparseMatrix &result) {
    if (a.data[0][0] != b.data[0][0] || a.data[0][1] != b.data[0][1]) {
        cout << "Error: Matrix dimensions do not match for addition.\n";
        return false;
    }

    int pA = 1, pB = 1;
    result.terms = 0;

    while (pA <= a.terms && pB <= b.terms) {
        int rA = a.data[pA][0], cA = a.data[pA][1];
        int rB = b.data[pB][0], cB = b.data[pB][1];

        if (rA < rB || (rA == rB && cA < cB)) {
            result.terms++;
            result.data[result.terms][0] = rA;
            result.data[result.terms][1] = cA;
            result.data[result.terms][2] = a.data[pA][2];
            pA++;
        } else if (rB < rA || (rA == rB && cB < cA)) {
            result.terms++;
            result.data[result.terms][0] = rB;
            result.data[result.terms][1] = cB;
            result.data[result.terms][2] = b.data[pB][2];
            pB++;
        } else {
            int sum = a.data[pA][2] + b.data[pB][2];
            if (sum != 0) {
                result.terms++;
                result.data[result.terms][0] = rA;
                result.data[result.terms][1] = cA;
                result.data[result.terms][2] = sum;
            }
            pA++;
            pB++;
        }
    }

    while (pA <= a.terms) {
        result.terms++;
        result.data[result.terms][0] = a.data[pA][0];
        result.data[result.terms][1] = a.data[pA][1];
        result.data[result.terms][2] = a.data[pA][2];
        pA++;
    }

    while (pB <= b.terms) {
        result.terms++;
        result.data[result.terms][0] = b.data[pB][0];
        result.data[result.terms][1] = b.data[pB][1];
        result.data[result.terms][2] = b.data[pB][2];
        pB++;
    }

    result.data[0][0] = a.data[0][0];
    result.data[0][1] = a.data[0][1];
    result.data[0][2] = result.terms;
    return true;
}

bool multiply(SparseMatrix &a, SparseMatrix &b, SparseMatrix &result) {
    int aRows = a.data[0][0], aCols = a.data[0][1];
    int bRows = b.data[0][0], bCols = b.data[0][1];

    if (aCols != bRows) {
        cout << "Error: Incompatible dimensions for multiplication.\n";
        return false;
    }

    SparseMatrix bT;
    transpose(b, bT);

    result.terms = 0;
    int aRowStart = 1;

    for (int i = 0; i < aRows; i++) {
        while (aRowStart <= a.terms && a.data[aRowStart][0] < i) {
            aRowStart++;
        }

        int bRowStart = 1;
        for (int j = 0; j < bCols; j++) {
            while (bRowStart <= bT.terms && bT.data[bRowStart][0] < j) {
                bRowStart++;
            }

            int pA = aRowStart;
            int pB = bRowStart;
            int sum = 0;

            while (pA <= a.terms && a.data[pA][0] == i &&
                   pB <= bT.terms && bT.data[pB][0] == j) {

                int colA = a.data[pA][1];
                int colB = bT.data[pB][1];

                if (colA == colB) {
                    sum += a.data[pA][2] * bT.data[pB][2];
                    pA++;
                    pB++;
                } else if (colA < colB) {
                    pA++;
                } else {
                    pB++;
                }
            }

            if (sum != 0) {
                result.terms++;
                result.data[result.terms][0] = i;
                result.data[result.terms][1] = j;
                result.data[result.terms][2] = sum;
            }
        }
    }

    result.data[0][0] = aRows;
    result.data[0][1] = bCols;
    result.data[0][2] = result.terms;
    return true;
}

int main() {
    int choice;
    SparseMatrix a, b, result;
    int r1, c1, r2, c2;

    do {
        cout << "\n----- Sparse Matrix Operations -----\n";
        cout << "1. Transpose\n";
        cout << "2. Addition\n";
        cout << "3. Multiplication\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter rows and cols of matrix: ";
                cin >> r1 >> c1;
                a.readMatrix(r1, c1);
                cout << "\nOriginal matrix (triplet form):\n";
                a.display();

                transpose(a, result);
                cout << "\nTransposed matrix (triplet form):\n";
                result.display();
                cout << "\nTransposed matrix (grid form):\n";
                result.displayAsGrid();
                break;

            case 2:
                cout << "Enter rows and cols of Matrix A: ";
                cin >> r1 >> c1;
                a.readMatrix(r1, c1);

                cout << "Enter rows and cols of Matrix B: ";
                cin >> r2 >> c2;
                b.readMatrix(r2, c2);

                if (add(a, b, result)) {
                    cout << "\nSum matrix (triplet form):\n";
                    result.display();
                    cout << "\nSum matrix (grid form):\n";
                    result.displayAsGrid();
                }
                break;

            case 3:
                cout << "Enter rows and cols of Matrix A: ";
                cin >> r1 >> c1;
                a.readMatrix(r1, c1);

                cout << "Enter rows and cols of Matrix B: ";
                cin >> r2 >> c2;
                b.readMatrix(r2, c2);

                if (multiply(a, b, result)) {
                    cout << "\nProduct matrix (triplet form):\n";
                    result.display();
                    cout << "\nProduct matrix (grid form):\n";
                    result.displayAsGrid();
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}