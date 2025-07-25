# `Printf` function

Welcome to our custom printf function project.
This is our first group project at Holberton school

## 🔖 Table of contents

<details>
  <summary>
    CLICK TO ENLARGE 😇
  </summary>
  📄 <a href="#description">Description</a>
  <br>
  🎓 <a href="#objectives">Objectives</a>
  <br>
  📋 <a href="#flowchart">Flow Chart</a>
  <br>
  📥 <a href="#installation"> Installation </a>
  <br>
  🏗️ <a href="#compilation"> Compilation </a>
  <br>
  📄 <a href="#restrictions"> Restrictions </a>
  <br>
  ⚒️ <a href="#feature"> Feature </a>
  <br>
  🔨 <a href="#tech-stack">Tech stack</a>
  <br>
  📂 <a href="#files-description">Files description</a>
  <br>
  👷🏼‍♂️👷🏼‍♂️ <a href="#authors">Authors</a>
  </details>

## 📄 <span id="description">Description</span>

_printf is a function trying to mimic the behavior of standard `printf` in C.
<br>The principal usecase of `_printf` is to print a string.

## 🎓 <span id="objectives">Objectives</span>

- This `_printf` function allow to print formatted data to the standard output.
- In mandatory task :
   - Basic conversion specifiers such as %c, %s, %i and %d
- In Advanced task :
   - %b, %o, %x, %p, and others.

## 📋 <span id="flowchart">Flow chart</span>

```mermaid
---
config:
  layout: dagre
---
flowchart TD
    A["Start"] --> B("_printf call")
    B --> D{"Is string null"}
    D -- no --> E{"Did we cross the null terminator"}
    E -- no --> F{"Did we cross a %"}
    F -- no --> G["Write the character"]
    D -- yes --> H["Return error"]
    E -- yes --> I["Return success"]
    F -- yes --> J{"Did we find a specifier"}
    J -- yes --> K["Print result"]
    G -- looping --> E
    O["Skip next character"] -- looping --> E
    J -- no --> P["Print the specifier"]
    P --> O
    K --> O
    style A fill:#FFD600,stroke:#FFD600,color:#000000
    style D fill:#FFCDD2,stroke:#FFCDD2,color:#000000
    style E fill:#FFCDD2,stroke:#FFCDD2,color:#000000
    style F fill:#FFCDD2,stroke:#FFCDD2,color:#000000
    style G fill:#BBDEFB,stroke:#BBDEFB,color:#000000
    style H fill:#D50000,stroke:#D50000,color:#000000
    style I fill:#D50000,stroke:#D50000,color:#000000
    style J fill:#FFCDD2,stroke:#FFCDD2,color:#000000
    style K fill:#BBDEFB,stroke:#BBDEFB,color:#000000
    style O fill:#BBDEFB,stroke:#BBDEFB,color:#000000
    style P fill:#BBDEFB,stroke:#BBDEFB,color:#000000

```
##  🏗️ <span id="instalation">Instalation</span>
To install, you need to clone the directory as follows:
```
git clone https://github.com/JeremyLrs/holbertonschool-printf.git
cd holbertonschool-printf
```

To use a manual :

```
sudo apt install groff /* To install Groff */
groff -Tascii -man man_3_printf /* To use manual with groff */

```

## ⚙️ <span id="compilation">Compilation</span>
The code should be compiled like this:

1. Use `make` cmd in terminal for compilate the file in .o and executable file.
   - This will generate all the executable named `.o` .
2. Use `make clean` cmd in terminal for clean all the executable file.

## 📄 <span id="restrictions">Restrictions</span>

The restrictions are as follows:

- `No more than 5 functions per file`

- `No use a global variables`

Authorized functions and macros:

- `write`
- `malloc`
- `free`
- `va_start`
- `va_end`
- `va_copy`
- `va_arg`



## ⚒️ <span id="feature">Feature</span>
### Typical usecase :

Use `_printf()` in your C programs as a direct substitute for the standard `printf` function.

``` c
#include "main.h"

int main(void)
{
  _printf ("%c\n", 'A'); /* To print a char */
  _printf ("%s\n", "My name is toto"); /* To print a string */
  _printf ("%d\n", 12345); /* To print an integer */
  _printf ("%i\n", -1); /* To print an Integer*/
  return (0);
}
```

### _printf with argument :
In `_printf` it's possible to give an infinit number of argument to the function.
To do so `_printf` is variadic function.

#### Prototype :
```c
int _printf(const char *format, ...);
```
#### Specifier :
With `_printf` it's possible to print diferent types using specifier
In order to acces a specifier it's typical to use `"%"` follow the specifier.
##### Specifier usecase with number :
``` c
#include "main.h"

int main(void)
{
  int age = 18;
  _printf("Toto age is %d years old \n", age);
  return (0);
}
```
Expected output :
`$: Toto age is 18 years old`


## 🔨 <span id="tech-stack">Tech stack</span>

<p align="left">
<img src="https://img.shields.io/badge/C-blue?logo=c&logoColor=white&style=for-the-badge" alt="C badge">
<img src="https://img.shields.io/badge/GITHUB-000000?logo=github&logoColor=white&style=for-the-badge" alt="GITHUB badge">
<img src="https://img.shields.io/badge/GIT-red?logo=git&logoColor=white&style=for-the-badge" alt="GIT badge">
<img src="https://img.shields.io/badge/GCC-yellow?logo=gcc&logoColor=white&style=for-the-badge" alt="GCC badge">
<img src="https://img.shields.io/badge/LINUX-000000?logo=linux&logoColor=white&style=for-the-badge" alt="LINUX badge">
</p>

## 📂 <span id="files-description">File description</span>

| **FILE**            | **DESCRIPTION**                                  |
| -----------------: | ------------------------------------------------- |
| `main.h`()| The header file contain all the prototypes functions.      |
| `_putchar.c`()| The file contain the function `_putchar` to display a character.|
| `printf.c`()| The file contain our `printf` function.|
| `get_print_function.c`()| Function to get the right function according to a given character.|
| `string_handler.c`()| Function to `print` any given string.|
| `int_handler.c`()| Function to `print` any given character.|
| `unsigned_int_handler.c`()| Function to `print` any given unsigned integer.|
| `binary_handler.c`()| Function to `print` any given integer in binary.|
| `octal_handler.c`()| Function to `print` any given integer in octal.|
| `hexa_handler.c`()| Function to `print` any given integer in lowercase and uppercase hexadecimal.|
| `README.md`()| The `README.md` file.|
| `man_3_printf`()| Manual page of our function `printf`.| 

## 👷🏼‍♂️👷🏼‍♂️ <span id="authors">Authors</span>

**👷🏼‍♂️ Adel MEJRISSI**
- GitHub: [@AdelMej](https://github.com/AdelMej)
- LinkedIn: [@adel-mejrissi](https://www.linkedin.com/in/adel-mejrissi-709374172/)

**👷🏼‍♂️ Jérémy LAURENS**
- GitHub: [@JeremyLrs](https://github.com/JeremyLrs)
- LinkedIn: [@jeremylrs](www.linkedin.com/in/jeremylrs)
