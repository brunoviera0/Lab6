#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "matrix.h"

using namespace doctest;
using namespace std;

TEST_CASE("Multiply Matrices") {
    vector<vector<double>> A = {{1, 2}, {3, 4}};
    vector<vector<double>> B = {{2, 0}, {1, 2}};
    auto result = multiplyMatrix(A, B);

    CHECK(result[0][0] == Approx(4.0));
    CHECK(result[0][1] == Approx(4.0));
    CHECK(result[1][0] == Approx(10.0));
    CHECK(result[1][1] == Approx(8.0));
}
TEST_CASE("Combining Matrices") {
    int n = 2;
    vector<vector<int>> D0 = {{0, 2}, {2, 0}};
    vector<vector<int>> D1 = {{0, 1}, {1, 0}};
    vector<vector<int>> D_minus_1 = {{0, 0}, {0, 0}};

    auto C = combinedMatrix(D0, D1, D_minus_1);

    CHECK(C[0][0] == Approx(1.0));
    CHECK(C[0][1] == Approx(3 * (n + 1)));  
    CHECK(C[1][0] == Approx(3 * (n + 1)));
    CHECK(C[1][1] == Approx(1.0));
}


TEST_CASE("Detect Negative One Edge") {
    int n = 2;
    double base = 3 * (n + 1);
    CHECK(detectNegativeOneEdge(1.0 / base, n) == true); 
}

TEST_CASE("Detect Positive One Edge") {
    int n = 2;
    double base = 3 * (n + 1);
    CHECK(detectPositiveOneEdge(base, n) == true);
}

TEST_CASE("Normalize Matrix") {
    int n = 2;
    double base = 3 * (n + 1);
    vector<vector<double>> A = {{1.0, base}, {0.0, 1.0 / base}};
    normalizeMatrix(A, n);

    CHECK(A[0][0] == Approx(0.0));
    CHECK(A[0][1] == Approx(1.0));
    CHECK(A[1][0] == Approx(0.0));
    CHECK(A[1][1] == Approx(-1.0));
}
