#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

using namespace std;
bool detectZeroEdge(double edge_cost, int n);
bool detectPositiveOneEdge(double edge_cost, int n);
bool detectNegativeOneEdge(double edge_cost, int n);
vector<vector<int>> readMatrix(const string& filename, int n);
vector<vector<double>> combinedMatrix(const vector<vector<int>>& D0, 
                                                          const vector<vector<int>>& D1, 
                                                          const vector<vector<int>>& D_minus_1);
vector<vector<double>> multiplyMatrix(const vector<vector<double>>& A, 
                                                  const vector<vector<double>>& B);
void normalizeMatrix(vector<vector<double>>& A, int n);

#endif
