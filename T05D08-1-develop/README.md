# T05
## Contents

5. [MODULES](#modules) \
 5.1.  [search](#search) \
 5.2.  [test](#test)


# MODULES

## search

>***search.h | search.c***

> int input(int *a, int *n);
> <br/> void output(int *a, int n);

Input and output an array of integers.

> <br/> int max(int *a, int n);
> <br/> int min(int *a, int n);

Finding maxima and minima an array of integers.

> <br/> double mean(int *a, int n);
> <br/> double variance(int *a, int n);
> <br/> void search(int *a, int n, double mean_v, double variance_v);

Calculates mean and variance an array of integers.
 
> <br/> void squaring(int *asqr, int *a, int n);

Squares an array of integers.

> <br/> int even(int x);

Checks even of х.

> <br/> int sigma_rule(int x, double mean_v, double variance_v);

Checks three-sigma rule.

## test

>***test.c***

> int main();

***The program receive an array of integers via stdin and find the first occurrence of number that meets the following requirements in that array: 
<br/> -- even number, 
<br/> -- equal to or above the expected value, 
<br/> -- follows the three-sigma rule, 
<br/> -- does not equal 0. 
<br/>The program outputs:
<br/> -- maxima and minima,
<br/> -- mean and variance,
<br/> -- the number it finds must be output to stdout, if such number does not exist, the program prints 0. 
<br/>The maximum number of numbers entered is 30. 
<br/>In case of incorrect input, it outputs n/a.***

| Input | Output |
| ------ | ------ |
| 4<br/>1 2 3 4 | 4 |
