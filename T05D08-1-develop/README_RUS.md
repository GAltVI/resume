# T05D08

![day5_door](misc/rus/images/day5_door.png)


## Contents

1. [MODULES](#modules) \
 3.1.  [Quest 1. Arguments and pointers.](#quest-1-arguments-and-pointers) \
 3.2.  [Quest 2. Data I/O.](#quest-2-data-io) \
 3.3.  [Quest 3. Data metrics.](#quest-3-data-metrics) \
 3.4.  [Quest 4. Search.](#quest-4-search) 
4. [Chapter IV](#chapter-iv)


# MODULES

## Search.
> int input(int *a, int *n);
> <br/>void output(int *a, int n);
> <br/>int max(int *a, int n);
> <br/>int min(int *a, int n);
> <br/>double mean(int *a, int n);
> <br/>double variance(int *a, int n);
><br/> void squaring(int *asqr, int *a, int n);
> <br/>void search(int *a, int n, double mean_v, double variance_v);
> <br/>int even(int x);
><br/> int sigma_rule(int x, double mean_v, double variance_v);

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

