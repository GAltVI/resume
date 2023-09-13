# T04D04
The russian version of the task can be found in the repository.

## Contents

1. [MODULES](#MODULES) \
 1.1. [max_prime_divisor](#max_prime_divisor) \
 1.2. [char_decode](#char_decode) \
 1.3. [fibonacci](#fibonacci) \
 1.4. [ABH_functions](#ABH_functions) \
 1.5. [Quest 5*. Func.](#bonus-quest-5-func) 




# MODULES

## max_prime_divisor

> max_prime_divisor.h | max_prime_divisor.c

***The program finds the largest prime divisor of any entered integer `a` and prints it to the screen. Division and the operation of taking the remainder of the division are realised by subtraction. 
For errors, display "n/a".***

| Input | Output |
| ------ | ------ |
| 100 | 5 |
| -4 | 2 |

<br/>


## char_decode

> char_decode.h | char_decode.c

***The program takes operation mode (0–encoding or 1–decoding) as a command-line parameter. 
If the decoding mode is selected, the program must accept two-character strings separated by a space from stdin and output decoded characters separated by a space to stdout. Encoding involves a reverse 
operation. A line break character is a sign of the end of the input. The subtasks of encoding and decoding are organized as separate functions. 
For errors, display "n/a".***

| Terminal arguments | Input | Output |
| ------ | ------ | ------ |
| 0 | W O R L D | 57 4F 52 4C 44 |
| 0 | WORLD | n/a |
| 1 | 48 45 4C 4C 4F | H E L L O |
| 1 | 48454C4C4F | n/a |

<br/>


## fibonacci

> fibonacci.h | fibonacci.c

    46 49 42 4F 4E 41 43 43 49 32 31

***The program calculates and displays a number from the Fibonacci sequence (e.g. 21) using a recursive algorithm. The search of the specific Fibonacci number is organized as a separate function. The number is entered via the standard input stream. 
For errors, display "n/a".***

| Input | Output |
| ------ | ------ |
| 21 | 10946 |
<br/>


## ABH_functions

> ABH_functions.h | ABH_functions.c

The witch of Agnesi with diameter one: \
![The witch of Agnesi](misc/images/va.png) 

The lemniscate of Bernoulli with a unit interval in the positive half-plane: \
![The lemniscate of Bernoulli](misc/images/lb.png)

Quadratic hyperbola: \
![Quadratic hyperbola](misc/images/g.png) 

***The program calculates and displays a table with three functions: the witch of Agnesi with diameter one, the lemniscate of Bernoulli with a unit interval in the positive half-plane (Y > 0), and a quadratic hyperbola. The first column lists the values of the X-axis from minus Pi through plus Pi, there is 42 measurements at this interval; the second, third, and fourth columns describe the values ​​of the functions at a point. All values are recorded with an accuracy of 7 decimal places. Column separator: "|". 
If the function is not defined at any point, there is the "-" symbol in the table.***

Result:

-3.1415927 | 0.0919997 | - | 0.1013212<br/>
-2.9883442 | 0.1007029 | - | 0.1119796<br/>
................................................................

-1.3026116 | 0.3708103 | 0.3061966 | 0.5893457<br/>
-1.1493632 | 0.4308421 | 0.4310262 | 0.7569818


## Bonus Quest 5*. Func.

\> *Type in "Files are ready"*

Answer in the terminal: 

    Great. The door recovery algorithm can be launched. 
    However, it's possible to speed up the process by modifying your program
    and adding the printing of graphs of functions to it.
    No redundant elements, just a sequence of graphs, one by one, in the same range of definition.
    The knowledge you already have will be enough. 
    Scale on the X-axis – 42 markers; scale on the Y-axis – 21. 
    Draw using the "*" symbol. 
    Although it's not necessary – the acceleration rate will not be too high. 

***== Quest 5 received. Make the necessary additions to the src/door_functions.c program so it draws the graphs of the calculated functions in the terminal using the "\*" symbol. Scale on the X-axis – 42 markers; scale on the Y-axis – 21. The placement and rotation of the coordinate axes are not critical. Save the finished code in door_functions_print.c ==***

