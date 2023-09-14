# T05
## Contents

5. [MODULES](#modules) \
 5.1.  [search](#search) \
 5.2.  [test](#test)


# MODULES

## search

> ***search.h | search.c***

> int input(int *a, int *n);
> <br/> void output(int *a, int n);
> <br/> int max(int *a, int n);
> <br/> int min(int *a, int n);
> <br/> double mean(int *a, int n);
> <br/> double variance(int *a, int n);
> <br/> void squaring(int *asqr, int *a, int n);
> <br/> void search(int *a, int n, double mean_v, double variance_v);
> <br/> int even(int x);
> <br/> int sigma_rule(int x, double mean_v, double variance_v);

***Программа принимает через stdin массив целых чисел и находит в нем первое вхождение числа, удовлетворяющего следующим требованиям: 
<br/> -- четное,
<br/> -- больше или равно математическому ожиданию, 
<br/> -- подчиняется правилу трех сигм,
<br/> -- не равняется 0. 
<br/>В результате выполнения программы выводится:
<br/> -- экстремумы (max и min), 
<br/> -- математическое ожидание и дисперсию,
<br/> -- найденное число, если такого числа нет, то выводится 0. 
<br/>Максимальное количество введенных чисел равно 30. 
<br/>В случае некорректного ввода выводится n/a.***

| Входные данные | Выходные данные |
| ------ | ------ |
| 4<br/>1 2 3 4 | 4 1 2.500000 1.250000 4 |

