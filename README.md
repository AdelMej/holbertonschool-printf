# printf

Welcome in our first commun project. 

## Description de la fonction

_printf is a function trying to mimic the behavior of standard printf in C
The principal usecase of printf is to print a string.

## Flow chart

flowchart TD
    A[Start] --> B(string)
    B --> C{printing character}
    C --> D{is it null}
    D --> |no| E{did we cross the null terminator}
    E --> |no| F{did we cross a %}
    F --> |no| G[write the character]
    D --> |yes| H[return error]
    E --> |yes| I[return success]
    F --> |yes| J{what's the next character}
    J --> |c| K[write character in argument]
    J --> |s| L[write string in argument]
    J --> |%| M[write %]
    G --> |looping|E
    K --> O[skip next character]
    L --> O
    M --> O
    O --> |looping|E
## Feature
### Typical usecase : 

``` c
printf ("My name is toto");
expected output : 
$: My name is toto
```

### printf with argument :
In printf it's possible to give an infinit number of argument to the function 

to do so printf is variadic function.

#### Prototype :
```c
int _printf(const char *format, ...);
```
### Specifier :
With **printf** it's possible to print diferent types using specifier 
In order to acces a scpecifier it's typical to use **"%"** follow the specifier.
#### Specifier usecase with number :
``` c
int age = 18;
printf("Toto age is %d years old \n", age);
expected output :
$: Toto age is 18 years old
```

#### Curent handle type : 

**Number - String - Character**

## 

## Technology used
![Static Badge](https://img.shields.io/badge/-C-blue?style=plastic&logo=C&logoColor=white&logoSize=big)
![Static Badge](https://img.shields.io/badge/-Vim-green?style=plastic&logo=VIM&logoColor=white&logoSize=big)
![Static Badge](https://img.shields.io/badge/-Github-black?style=plastic&logo=GITHUB&logoColor=white&logoSize=big)
![Static Badge](https://img.shields.io/badge/-Git-red?style=plastic&logo=GIT&logoColor=white&logoSize=big)
![Static Badge](https://img.shields.io/badge/-gcc-yellow?style=plastic&logo=gcc&logoColor=white&logoSize=big)
![Static Badge](https://img.shields.io/badge/-Linux-white?style=plastic&logo=LINUX&logoColor=white&logoSize=big)
![Static Badge](https://img.shields.io/badge/-Makefile-violet?style=plastic&logo=MAKEFILE&logoColor=white&logoSize=big)


------------

## MAN links

## Authors and thanks
Adel Mejrissi

Jeremy Laurens



