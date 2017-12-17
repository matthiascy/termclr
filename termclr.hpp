/**
 * termclr.hpp
 *
 * Termclr is for coloring the text printed on terminal.
 *
 * Copyright (c) 2017 by CHEN Yang
 *
 * License: BSD
 */

#ifndef TERMCLR_HPP
#define TERMCLR_HPP

#if defined(_WIN32) || defined(_WIN64)
#  define TERM_WIN
#elif defined(__APPLE__)
#  define TERM_MAC
#elif defined(__unix__) || defined(__unix) || defined(__linux__)
#  define TERM_NIX
#else
#  error unknown platform
#endif


#if defined(TERM_MAC) || defined(TERM_NIX)
#  include <unistd.h>
#elif defined(TERM_WIN)
#  include <io.h>
#  include <windows.h>
#endif

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

namespace termclr {

  namespace detail {
    const char* _reset      = "\u001b[0m";
    const char* _bold       = "\u001b[1m";
    const char* _dim        = "\u001b[2m";
    const char* _italic     = "\u001b[3m";
    const char* _underline  = "\u001b[4m";
    const char* _blink      = "\u001b[5m";
    const char* _inverse    = "\u001b[7m";
    const char* _conceal    = "\u001b[8m";
    const char* _crossedout = "\u001b[9m";

    const char* _black   = "\u001b[30m";
    const char* _red     = "\u001b[31m";
    const char* _green   = "\u001b[32m";
    const char* _yellow  = "\u001b[33m";
    const char* _blue    = "\u001b[34m";
    const char* _magenta = "\u001b[35m";
    const char* _cyan    = "\u001b[36m";
    const char* _white   = "\u001b[37m";

    const char* _grey          = "\u001b[90m";
    const char* _light_red     = "\u001b[91m";
    const char* _light_green   = "\u001b[92m";
    const char* _light_yellow  = "\u001b[93m";
    const char* _light_blue    = "\u001b[94m";
    const char* _light_magenta = "\u001b[95m";
    const char* _light_cyan    = "\u001b[96m";
    const char* _bright_white  = "\u001b[97m";

    const char* _on_black   = "\u001b[40m";
    const char* _on_red     = "\u001b[41m";
    const char* _on_green   = "\u001b[42m";
    const char* _on_yellow  = "\u001b[43m";
    const char* _on_blue    = "\u001b[44m";
    const char* _on_magenta = "\u001b[45m";
    const char* _on_cyan    = "\u001b[46m";
    const char* _on_white   = "\u001b[47m";

    const char* _on_grey          = "\u001b[100m";
    const char* _on_light_red     = "\u001b[101m";
    const char* _on_light_green   = "\u001b[102m";
    const char* _on_light_yellow  = "\u001b[103m";
    const char* _on_light_blue    = "\u001b[104m";
    const char* _on_light_magenta = "\u001b[105m";
    const char* _on_light_cyan    = "\u001b[106m";
    const char* _on_bright_white  = "\u001b[107m";

    inline bool is_atty(const std::ostream& stream)
    {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        if (&stream == &std::cout)
          return static_cast<bool>(isatty(fileno(isatty(stdout))));
        else if ((&stream == &std::cerr) || (&stream == &std::clog))
          return static_cast<bool>(isatty(fileno(isatty(stderr))));
      #elif defined(TERM_WIN)
        if (&stream == &std::cout)
          return static_cast<bool>(_isatty(_fileno(stdout)));
        else if ((&stream == &std::cerr) || (&stream == &std::clog))
          return static_cast<bool>(_isatty(_fileno(stderr)));
      #endif
    }

    #define COLOR_FUNCTION(COLOR, SIZE)                   \
    inline std::ostream& (COLOR)(std::ostream& stream) {  \
      if (detail::is_atty(stream)) {                      \
        detail::enable_seq_char(stream);                  \
        stream << detail::_##COLOR;                       \
      }
      return stream;                                      \
    }                                                     \
                                                          \
    template <typename T>                                 \
    inline std::string (COLOR)(const T str) {             \
      std::string out(detail::_##COLOR);                  \
      return out.append(str).append(detail::_reset)       \
    }

    #if defined(TERM_WIN)
    inline void enable_seq_char(std::ostream& stream)
    {
      HANDLE handle = INVALID_HANDLE_VALUE;
      if (&stream == &std::cout)
        handle = GetStdHandle(STD_OUTPUT_HANDLE);
      else if (&stream == &std::cerr || &stream == &std::clog)
        handle = GetStdHandle(STD_ERROR_HANDLE);
      else
        return;

      DWORD dw_mode = 0;
      if (!GetConsoleMode(handle, &dw_mode))
        return;

      dw_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
      if (!SetConsoleMode(handle, dw_mode))
        return;
    }
    #endif
  }

  COLOR_FUNCTION(reset)
  COLOR_FUNCTION(bold)
  COLOR_FUNCTION(dim)
  COLOR_FUNCTION(italic)
  COLOR_FUNCTION(underline)
  COLOR_FUNCTION(blink)
  COLOR_FUNCTION(inverse)
  COLOR_FUNCTION(conceal)
  COLOR_FUNCTION(crossedout)

  COLOR_FUNCTION(black)
  COLOR_FUNCTION(red)
  COLOR_FUNCTION(green)
  COLOR_FUNCTION(yellow)
  COLOR_FUNCTION(blue)
  COLOR_FUNCTION(magenta)
  COLOR_FUNCTION(cyan)
  COLOR_FUNCTION(white)

  COLOR_FUNCTION(grey)
  COLOR_FUNCTION(light_red)
  COLOR_FUNCTION(light_green)
  COLOR_FUNCTION(light_yellow)
  COLOR_FUNCTION(light_blue)
  COLOR_FUNCTION(light_magenta)
  COLOR_FUNCTION(light_cyan)
  COLOR_FUNCTION(bright_white)

  COLOR_FUNCTION(on_black)
  COLOR_FUNCTION(on_red)
  COLOR_FUNCTION(on_green)
  COLOR_FUNCTION(on_yellow)
  COLOR_FUNCTION(on_blue)
  COLOR_FUNCTION(on_magenta)
  COLOR_FUNCTION(on_cyan)
  COLOR_FUNCTION(on_white)

  COLOR_FUNCTION(on_grey)
  COLOR_FUNCTION(on_light_red)
  COLOR_FUNCTION(on_light_green)
  COLOR_FUNCTION(on_light_yellow)
  COLOR_FUNCTION(on_light_blue)
  COLOR_FUNCTION(on_light_magenta)
  COLOR_FUNCTION(on_light_cyan)
  COLOR_FUNCTION(on_bright_white)

  /*
  inline std::ostream& reset(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[0m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& bold(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[1m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& dim(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[2m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& italic(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[3m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& underline(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[4m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& blink(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[5m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& inverse(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[7m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& conceal(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[8m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& crossedout(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[9m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& black(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[30m";
      #elif defined(TERM_WIN)
      // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& red(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[31m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& green(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[32m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& yellow(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[33m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& blue(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[34m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& magenta(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[35m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& cyan(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[36m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& white(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[37m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& grey(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[90m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& light_red(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[91m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& light_green(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[92m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& light_yellow(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[93m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& light_blue(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[94m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& light_magenta(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[95m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& light_cyan(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[96m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& bright_white(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[97m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_black(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[40m";
      #elif defined(TERM_WIN)
      // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_red(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[41m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_green(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[42m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_yellow(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[43m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_blue(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[44m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_magenta(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[45m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_cyan(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[46m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_white(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[47m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_grey(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[100m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_light_red(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[101m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_light_green(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[102m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_light_yellow(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[103m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_light_blue(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[104m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_light_magenta(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[105m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_light_cyan(std::ostream& stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[106m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }

  inline std::ostream& on_bright_white(std::ostream &stream)
  {
    if (detail::is_atty(stream)) {
      #if defined(TERM_MAC) || defined(TERM_NIX)
        stream << "\u001b[107m";
      #elif defined(TERM_WIN)
        // TODO: windows
      #endif
    }

    return stream;
  }
  */

}

#undef TERM_WIN
#undef TERM_NIX
#undef TERM_MAC

#endif  // !TERMCLR_HPP
