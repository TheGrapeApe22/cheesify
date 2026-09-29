## Welcome to cheesify 🧀
Would you like to make your code unmaintainable forever? Do you hate conventions with every cell in your body? Most importantly, do you love cheese? If you answered any of these questions, cheesify is undoubtedly the solution for you.

**cheesify** is a python script that rewrites your C and C++ files into an extremely visually appealing format. See as an example:

`sample_output.c`:
```c
#include <stdio.h>
#define cheese int
#define Cheese main
#define cHeese (
#define CHeese )
#define chEese {
#define ChEese for
#define cHEese i
#define CHEese =
#define cheEse 1
#define CheEse ;
#define cHeEse <=
#define CHeEse 10
#define chEEse ++)
#define ChEEse printf
#define cHEEse "%d "
#define CHEEse ,
#define cheeSe }
#define CheeSe "\n"
#define cHeeSe return
#define CHeeSe 0

cheese Cheese cHeese CHeese chEese
    // cheese
    ChEese cHeese cheese cHEese CHEese cheEse CheEse cHEese cHeEse CHeEse CheEse cHEese chEEse chEese
        ChEEse cHeese cHEEse CHEEse cHEese CHeese CheEse
    cheeSe
    ChEEse cHeese CheeSe CHeese CheEse
    cHeeSe CHeeSe CheEse
cheeSe
```
Perfectly readable syntax, in my humble opinion.

## How to use

Run cheesify.py:
```shell
python3 cheesify.py input_file
```
with the path to your C or C++ file in place of `input_file`. It will print your cheesified file to stdout, which you can pipe into any output file.

Example usage:
```shell
python3 cheesify.py not_cheesy.c > cheesy.c
```

## Why did I make such an abomination?
:)
