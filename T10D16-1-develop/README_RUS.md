# T10

## Contents

10. [Modules](#modules) \
 10.1. [my_string](#my_string) \
 10.2. [text_processor](#text_processor) 


# Modules

## my_string
>**my_string.h | my_string.c || my_string_test.c**

int my_strlen(char *str);
int my_strcmp(char *str1, char *str2);
int my_strcpy(char *str1, char *str2);
char *my_strcat(char *str1, char *str2);
int my_strchr(char *str1, char symb);
const char *my_strstr(char *str1, char *str2);
char *my_strtok(char *str1, char *str2);

***Объявление и определение функций в файлах src/my_string.h и src/my_string.c. <br/>Тесты для проверки функций в файле src/string_test. Проверка функций производится на наборе тестовых данных: нормальные значения, ненормальные значения, краевые значения и т.д. По каждому тесту в stdout выводится вход, выход и результат теста (SUCCESS/FAIL).***

*Сборка программы осуществляется при помощи Makefile. Имена стадий сборки и исполняемых файлов (хранятся в папке build) в соответсвии с тестируемыми функциями:* 
| Функция | Стадия сборки в Makefile | Имя исполняемого файла |
|------|-----|-----|
| my_strlen | strlen_tests | Quest_1 |
| my_strcmp | strcmp_tests | Quest_2 |
| my_strcpy | strcpy_tests | Quest_3 |
| my_strcat | strcat_tests | Quest_4 |
| my_strchr | strchr_tests | Quest_5 |
| my_strstr | strstr_tests | Quest_6 |
| my_strtok | strtok_tests | Quest_7 |

>*Используемые стандартные библиотеки: stdlib.h, stdio.h*



## ~~text_processor~~

~~***src/text_processor.c~~
~~При запуске с ключом командной строки -w принимает на вход в stdin число (ширину строки) и текст до 100 символов, оканчивающийся символом переноса строки. При любых других ключах программа выводит "n/a". ~~
~~При запуске с ключом -w, программа форматирует входной текст по ширине и выводит в stdout, имитируя поведение текстового процессора. Текст разбит на несколько строк, каждая из которых состоит из указанного количества символов. Строки не могут начинаться с пробела и не могут заканчиваться пробелом, последняя строка не должна оканчиваться знаком переноса строки. Слово может быть разбито для перехода на новую строку через символ '-' только, если целиком не помещается на одной строке. Во всех других случаях оно должно оставаться целым. Слова в строке размещать равномерно, заполняя пространство между ними пробелами. ~~
~~Имя стадии сборки - text_processor. Исполняемый файл хранится в корне в папке build с именем Quest_8.~~

~~| Параметры командной строки | Входные данные | Выходные данные |~~
~~| ------ | ------ | ------ |~~
~~| -w | 10<br/>hello how are you | hello how<br/>are you |~~
~~| -w | 5<br/>ab abcd ab abcd ab abcdefgh | ab<br/>abcd<br/>ab<br/>abcd<br/>ab a-<br/>bcde-<br/>fgh |~~


