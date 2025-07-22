# printf

Welcome in our first commun project. 

## Description de la fonction

_printf is a function trying to mimic the behavior of standard printf in C
The principal usecase of printf is to print a string.
Typical usecase : 

``` c
printf ("My name is toto");
expected output : 
$: My name is toto
```

### 

With **printf** it's possible to print diferent types using specifier 

Type : 
    - Number
    - String
    - Character
    - ....

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

## Technology used

------------

## MAN links

## Authors and thanks


