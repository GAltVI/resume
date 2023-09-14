#ifndef H_SEARCH
#define H_SEARCH

#define NMAX 30
#define INTMAX 2147483647

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
void squaring(int *asqr, int *a, int n);
void search(int *a, int n, double mean_v, double variance_v);
int even(int x);
int sigma_rule(int x, double mean_v, double variance_v);

#endif
