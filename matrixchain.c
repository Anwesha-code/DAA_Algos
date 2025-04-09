#include <stdio.h>
#include <limits.h>

int MatrixChainMulti(int n, int p[]) {
    int m[n][n];
    int s[n][n];
    int i, j, k, d, q;

    for (i = 1; i < n; i++) {               // Initialize main diagonal to 0
        m[i][i] = 0;
    }

    for (d = 1; d < n - 1; d++) {                 // chain length  (diagonal which is currently being filled ) (m, s matrices are to be filled diagonally)
        for (i = 1; i < n - d; i++) {
            j = i + d;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int p[] = {5, 4, 6, 2, 7};
    int n = sizeof(p) / sizeof(p[0]);  // number of matrices is n-1

    /*int A1 = {{3, 5, 7, 3}, {4, 5, 2, 8}, {9, 5, 3, 7}, {3, 6, 8, 9}, {9, 0, 3, 1}};
    int A2 = {{4,6,3,7,1,0}, {9,5,2,4,1,0}, {2,7,4,0,3,6}, {1,2,3,4,5,6}};
    int A3 = {{2,3}, {3,4}, {3,7}, {8,5}, {3,0}, {5,7}};
    int A4 = {{3,5,7,1,3,2,9}, {7,5,3,0,9,3,1}};*/

    int cost = MatrixChainMulti(n, p);
    printf("Minimum cost = %d\n", cost);

    return 0;
}
