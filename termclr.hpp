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
#elif defined(__unix__) || defined(__unix)
#  define TERM_NIX
#else
#  error platform unkown
#endif


#if defined(TERM_MAC) || defined(TERM_NIX)
#  include <unistd.h>
#elif defined(TERM_WIN)
#  include <io.h>
#  inlcude <windows.h>
#endif

#include <iostream>
#include <cstdio>


namespace termclr {

  namespace detail {
  }

  inline std::ostream& reset(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[0m";
    #elif defined(TERM_WIN)
    // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& bold(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[1m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& dim(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[2m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& italic(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[3m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& underline(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[4m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& blink(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[5m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& inverse(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[7m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& conceal(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[8m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& crossedout(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[9m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }


  /**
   * Colors
   */

  inline std::ostream& black(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[30m";
    #elif defined(TERM_WIN)
    // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& red(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[31m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& green(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[32m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& yellow(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[33m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& blue(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[34m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& magenta(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[35m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& cyan(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[36m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& white(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[37m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& grey(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[90m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& light_red(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[91m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& light_green(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[92m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& light_yellow(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[93m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& light_blue(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[94m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& light_magenta(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[95m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& light_cyan(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[96m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& bright_white(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[97m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_black(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[40m";
    #elif defined(TERM_WIN)
    // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_red(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[41m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_green(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[42m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_yellow(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[43m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_blue(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[44m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_magenta(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[45m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_cyan(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[46m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_white(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[47m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_grey(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[100m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_light_red(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[101m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_light_green(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[102m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_light_yellow(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[103m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_light_blue(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[104m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_light_magenta(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[105m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_light_cyan(std::ostream& stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[106m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

  inline std::ostream& on_bright_white(std::ostream &stream)
  {
    #if defined(TERM_MAC) || defined(TERM_NIX)
      stream << "\u001b[107m";
    #elif defined(TERM_WIN)
      // TODO: windows
    #endif

    return stream;
  }

}

#undef TERM_WIN
#undef TERM_NIX
#undef TERM_MAC

#endif  // !TERMCLR_HPP
