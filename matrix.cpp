#include "matrix.h"
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;
vector<vector<int>> readMatrix(const string& filename, int n) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Cannot open file " + filename);
    }

    vector<vector<int>> matrix;
    int num;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            if (!(file >> num)) {
                throw runtime_error("Not enough numbers");
            }
            row.push_back(num);
        }
        matrix.push_back(row);
    }

    return matrix;
}

vector<vector<double>> combinedMatrix(const vector<vector<int>>& D0, 
                                      const vector<vector<int>>& D1, 
                                      const vector<vector<int>>& D_minus_1) {
    int n = D0.size();
    vector<vector<double>> C(n, vector<double>(n, 0.0));
    double base = 3 * (n + 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (D0[i][j] == 0) C[i][j] = pow(base, 0);  //0 edge, which is 1
            if (D1[i][j] == 1) C[i][j] = pow(base, 1);  //+1 edge
            if (D_minus_1[i][j] == -1) C[i][j] = pow(base, -1);  //-1 edge
        }
    }
    return C;
}


vector<vector<double>> multiplyMatrix(const vector<vector<double>>& A, 
                                                  const vector<vector<double>>& B) {
    int n = A.size();
    vector<vector<double>> result(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) { //iterate through rows and columns and mutiply
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}
bool detectNegativeOneEdge(double edge_cost, int n) {
    double fractional_part = edge_cost - std::trunc(edge_cost);
    double check = 3 * (n + 1) * fractional_part;
    return check >= 1 && check <= 2 * n;
}

bool detectPositiveOneEdge(double edge_cost, int n) {
    double check = std::trunc(edge_cost / (3 * (n + 1)));
    return check >= 1 && check <= 2 * n;
}

bool detectZeroEdge(double edge_cost, int n) {
    double check = std::fmod(std::trunc(edge_cost), 3 * (n + 1));
    return check > 0 && check <= 3 * n;
}

void normalizeMatrix(vector<vector<double>>& A, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double edge_cost = A[i][j];
            
            if (detectZeroEdge(edge_cost, n))
                A[i][j] = 0; //0 edge
            else if (detectPositiveOneEdge(edge_cost, n))
                A[i][j] = 1; //+1 edge
            else if (detectNegativeOneEdge(edge_cost, n))
                A[i][j] = -1; //-1 edge
            else
                A[i][j] = 0; //other values no edge or infinity
        }
    }
}
