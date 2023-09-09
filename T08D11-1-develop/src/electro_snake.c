#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 10
#define NA "n/a"

/*
    1 6 7
    2 5 8
    3 4 9
*/
/*
    1 2 3
    6 5 4
    7 8 9
*/

int input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);

void quick_sort(int *l, int *r);
void swap(int *a, int *b);

int main() { return 0; }

int input(int **matrix, int n, int m) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (scanf("%d", &matrix[i][j]) != 1) result = 1;
    }
    return result;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (; j < m - 1; j++) printf("%d ", matrix[i][j]);
        printf("%d", matrix[i][j]);

        if (i != m - 1) printf("\n");
    }
}

void quick_sort(int *l, int *r) {
    if (r - l <= 1) return;
    int m = *(l + (r - l) / 2);
    int *ll = l;
    int *rr = r - 1;
    while (ll <= rr) {
        while (*ll < m) ll++;
        while (*rr > m) rr--;
        if (ll <= rr) {
            swap(ll, rr);
            ll++;
            rr--;
        }
    }
    if (l < rr) quick_sort(l, rr + 1);
    if (ll < r) quick_sort(ll, r);
}

void swap(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}
