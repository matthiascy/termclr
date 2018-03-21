# Termclr

`Termclr` is a header-only C++ library which provides a set of C++ stream manipulators to print colored text to terminal.

Thanks to [ANSI escape code](https://en.wikipedia.org/wiki/ANSI_escape_code#Colors), terminals can display colors and formatted texts, there is a detailed explanation [here](https://misc.flogisoft.com/bash/tip_colors_and_formatting). For Unix-like systems, escape codes are naturally supported in terminals, but for Windows, it works only when [virtual terminal processing](https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences#Text_Formatting) is enabled(only supported by Windows 10). Depends on different type of terminals, some formatting codes may not work, see [terminals compatibility](https://misc.flogisoft.com/bash/tip_colors_and_formatting#Terminals-compatibility) for more infomation. On Windows, the only two supported formatting codes are `underline` and `inverse`(swaps foreground and background colors).

## How to use ?

Basically, put the color/format manipulators before the text you want to color.

```c++
#include <iostream>
#include "termclr.hpp"

int main(int argc, char** argv)
{
    std::cout << termclr::light_cyan << "Dyed in bright cyan."
              << termclr::reset << std::endl;

    std::cout << termclr::light_magenta("Dyed in light_magenta.")
              << std::endl;

    std::cout << termclr::light_red << termclr::on_grey << "Bright red text on grey."
              << std::endl;

    return 0;
}
```

Termclr provides a manipulator and a function to color the text.

```c++
std::cout << termclr::blue("Hues of blue include indigo and ultramarine.");
```

or

```c++
std::cout << termclr::blue << "Hues of blue include indigo and ultramarine." << termclr::reset;
```

Noticed that, the function version will automatically add a `reset` manipulator at the end of the string but the manipulator itself doesn't, so you need to add `termclr::reset` manually to avoid that color will affect the following texts.

When `cout` or `cerr` is redirected to a file or a buffer, or output stream is a file or a string, if manipulators are used(not include function version of colors), escape codes will be ignored automatically.

```c++
std::stringstream str_stream;
str_stream << termclr::light_green << "un grand arbre vert" << termclr::reset;
std::cout << str_stream.str();
```
will print "un grand arbre vert" but not a blue string. Actually, the function version of colors only create a string with head be the desired color codes and tail be the reset codes.

```c++
std::stringstream str_stream;
str_stream << termclr::light_red("Pay attention please!");
std::cout << str_stream.str();
```
*will print "Pay attention please!" in bright red*.

## Available manipulators

+ [Formatting](#formatting)
+ [Foreground Color](#foreground-color)
+ [Background Color](#background-color)

### Formatting

- `termclr::reset`
- `termclr::bold`
- `termclr::dim`
- `termclr::italic`
- `termclr::underline`
- `termclr::blink`
- `termclr::inverse`
- `termclr::conceal`
- `termclr::crossedout`

### Foreground color

- `termclr::black`
- `termclr::red`
- `termclr::green`
- `termclr::yellow`
- `termclr::blue`
- `termclr::magenta`
- `termclr::cyan`
- `termclr::white`
- `termclr::grey`
- `termclr::light_red`
- `termclr::light_green`
- `termclr::light_yellow`
- `termclr::light_blue`
- `termclr::light_magenta`
- `termclr::light_cyan`
- `termclr::bright_white`

### Background color

- `termclr::on_black`
- `termclr::on_red`
- `termclr::on_green`
- `termclr::on_yellow`
- `termclr::on_blue`
- `termclr::on_magenta`
- `termclr::on_cyan`
- `termclr::on_white`
- `termclr::on_grey`
- `termclr::on_light_red`
- `termclr::on_light_green`
- `termclr::on_light_yellow`
- `termclr::on_light_blue`
- `termclr::on_light_magenta`
- `termclr::on_light_cyan`
- `termclr::on_bright_white`
