# T03D03

![The base operations in C such as input, output, and arithmetic.]


## Contents

1. [Chapter I](#chapter-i) \
    1.1. [Quest 1. Arithmetic test.](#quest-3-arithmetic-test)  
    1.2. [Quest 4. Who is Max.](#quest-4-who-is-max)  
    1.3. [Quest 5. Complex calculations.](#quest-5-complex-calculations)  
    1.4. [Quest 6. Be careful with the floating.](#quest-6-be-careful-with-the-floating)  
    1.5. [Quest 7. Lock picking.](#quest-7-lock-picking)
   


# Chapter I

***== Получен Quest 3. Создать программу src/arithmetic.c, которая на вход через stdin принимает два целых числа и выводит на экран через пробел последовательно их сумму, разность, произведение и частное. Необходимо предусмотреть проверку на ввод только целых чисел. Ответ не должен заканчиваться пробелом. Предусмотреть обработку деления на ноль. В случае любой ошибки вывести n/a. Пушить в git необходимо только исходные файлы с кодом и файлы с данными (при необходимости) в директорию src, ветку develop. Разрешено подключать только заголовочный файл `<stdio.h>` ==***

| Входные данные | Выходные данные |
| ------ | ------ |
| 8 2 | 10 6 16 4 |
| 1 0 | 1 1 0 n/a |
| 3 2 | 5 1 6 1 |


***== Получен Quest 4. Создать программу src/max.c, которая на вход принимает два целых числа и выводит на экран наибольшее из них. Необходимо предусмотреть проверку на ввод только чисел — в случае ошибки вывести n/a. Поиск максимума оформить в виде отдельной функции. Пушить в git необходимо только исходные файлы с кодом и файлы с данными (при необходимости) в директорию src, ветку develop, об этом в будущем больше не будет напоминаться... Подключать можно только библиотеку `<stdio.h>` ==***

| Входные данные | Выходные данные |
| ------ | ------ |
| 3 2 | 3 |
| 12.3 10 | n/a |


## Quest 5. Complex calculations.

***== Получен Quest 5. Создать программу src/important_function.c, которая на вход принимает одно число `x` с плавающей точкой и выводит на экран результат подсчета функции (округленный до одной цифры после запятой). Необходимо предусмотреть проверку на ввод только чисел. В случае ошибки вывести n/a. В этом квесте помимо `<stdio.h>` вы можете использовать библиотеку `<math.h>` ==***

| Входные данные | Выходные данные |
| ------ | ------ |
| 1 | -2070.4 |


## Quest 6. Be careful with the floating.

***== Получен Quest 6. Изменить программу src/float_compare.c так, чтобы в результате вывелось "OK!". Использовать сравнение с небольшой величиной (порядка 1E-6). Объявление переменных или констант не считается за дополнительное изменение кода. ==***


## Quest 7. Lock picking.

***== Получен Quest 7. Создать программу src/crack.c, которая на вход принимает два числа с плавающей точкой, а на выходе выдает “GOTCHA”, если координаты точки находятся внутри окружности, и “MISS” иначе. Предусмотреть ввод только чисел — в случае ошибки вывести n/a, использовать можно 
только `<stdio.h>` ==***

| Входные данные | Выходные данные |
| ------ | ------ |
| 1.5 1.5 | GOTCHA |
