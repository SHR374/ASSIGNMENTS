#include <iostream>
using namespace std;

const int MAX = 100;

struct Triplet {
    int row, col, val;
};

void readMatrix(Triplet mat[], int &terms) {
    cout << "Enter number of non-zero elements: ";
    cin >> terms;
    cout << "Enter row, column, value for each non-zero element:\n";
    for (int i = 0; i < terms; ++i)
        cin >> mat[i].row >> mat[i].col >> mat[i].val;
}

void displayMatrix(Triplet mat[], int terms) {
    cout << "Row\tCol\tVal\n";
    for (int i = 0; i < terms; ++i)
        cout << mat[i].row << "\t" << mat[i].col << "\t" << mat[i].val << "\n";
}

void transpose(Triplet mat[], Triplet result[], int terms) {
    for (int i = 0; i < terms; ++i) {
        result[i].row = mat[i].col;
        result[i].col = mat[i].row;
        result[i].val = mat[i].val;
    }
}

void add(Triplet A[], int termsA, Triplet B[], int termsB, Triplet result[], int &termsR) {
    int i = 0, j = 0;
    termsR = 0;
    while (i < termsA && j < termsB) {
        if (A[i].row == B[j].row && A[i].col == B[j].col) {
            result[termsR] = {A[i].row, A[i].col, A[i].val + B[j].val};
            ++i; ++j;
        } else if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result[termsR] = A[i++];
        } else {
            result[termsR] = B[j++];
        }
        ++termsR;
    }
    while (i < termsA) result[termsR++] = A[i++];
    while (j < termsB) result[termsR++] = B[j++];
}

void multiply(Triplet A[], int termsA, Triplet B[], int termsB, Triplet result[], int &termsR) {
    termsR = 0;
    for (int i = 0; i < termsA; ++i) {
        for (int j = 0; j < termsB; ++j) {
            if (A[i].col == B[j].row) {
                int r = A[i].row;
                int c = B[j].col;
                int v = A[i].val * B[j].val;

                // Check if result already has this position
                bool found = false;
                for (int k = 0; k < termsR; ++k) {
                    if (result[k].row == r && result[k].col == c) {
                        result[k].val += v;
                        found = true;
                        break;
                    }
                }
                if (!found) result[termsR++] = {r, c, v};
            }
        }
    }
}

int main() {
    Triplet A[MAX], B[MAX], T[MAX], Sum[MAX], Prod[MAX];
    int termsA, termsB, termsT, termsSum, termsProd;

    cout << "\nEnter first sparse matrix:\n";
    readMatrix(A, termsA);

    cout << "\nEnter second sparse matrix:\n";
    readMatrix(B, termsB);

    cout << "\nTranspose of first matrix:\n";
    transpose(A, T, termsA);
    displayMatrix(T, termsA);

    cout << "\nAddition of matrices:\n";
    add(A, termsA, B, termsB, Sum, termsSum);
    displayMatrix(Sum, termsSum);

    cout << "\nMultiplication of matrices:\n";
    multiply(A, termsA, B, termsB, Prod, termsProd);
    displayMatrix(Prod, termsProd);

    return 0;
}
