#include "matrix.h"
#include <iostream>

using namespace std;

int main() {
    try {
        int n;
        cout << "Enter what the 'n' is in your n x n matrices (for the txt files I have it's 6): ";
        cin >> n;
        vector<vector<int>> D0 = readMatrix("D_0.txt", n);
        vector<vector<int>> D1 = readMatrix("D_1.txt", n);
        vector<vector<int>> D_minus_1 = readMatrix("D_minus_1.txt", n);

        cout << "D0 Matrix:" << endl;
        for (const auto &row : D0) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        cout << "D1 Matrix:" << endl;
        for (const auto &row : D1) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        cout << "D(-1) Matrix:" << endl;
        for (const auto &row : D_minus_1) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        auto C = combinedMatrix(D0, D1, D_minus_1);

        cout << "Combined Matrix C:" << endl;
        for (const auto &row : C) {
            for (double val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        auto result = multiplyMatrix(C, C);

        cout << "Matrix after multiplication:" << endl;
        for (const auto &row : result) {
            for (double val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

        normalizeMatrix(result, n);

        
        cout << "Normalized matrix:" << endl;
        for (const auto &row : result) {
            for (double val : row) {
                cout << val << " ";
            }
            cout << endl;
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
