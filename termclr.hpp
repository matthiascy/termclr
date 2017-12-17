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
#  inlcude <windows.h>
#endif

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>


namespace termclr {

  namespace detail {
    const char* reset      = "\u001b[0m";
    const char* bold       = "\u001b[1m";
    const char* dim        = "\u001b[2m";
    const char* italic     = "\u001b[3m";
    const char* underline  = "\u001b[4m";
    const char* blink      = "\u001b[5m";
    const char* inverse    = "\u001b[7m";
    const char* conceal    = "\u001b[8m";
    const char* crossedout = "\u001b[9m";

    const char* black   = "\u001b[30m";
    const char* red     = "\u001b[31m";
    const char* green   = "\u001b[32m";
    const char* yellow  = "\u001b[33m";
    const char* blue    = "\u001b[34m";
    const char* magenta = "\u001b[35m";
    const char* cyan    = "\u001b[36m";
    const char* white   = "\u001b[37m";

    const char* grey          = "\u001b[90m";
    const char* light_red     = "\u001b[91m";
    const char* light_green   = "\u001b[92m";
    const char* light_yellow  = "\u001b[93m";
    const char* light_blue    = "\u001b[94m";
    const char* light_magenta = "\u001b[95m";
    const char* light_cyan    = "\u001b[96m";
    const char* bright_white  = "\u001b[97m";

    const char* on_black   = "\u001b[40m";
    const char* on_red     = "\u001b[41m";
    const char* on_green   = "\u001b[42m";
    const char* on_yellow  = "\u001b[43m";
    const char* on_blue    = "\u001b[44m";
    const char* on_magenta = "\u001b[45m";
    const char* on_cyan    = "\u001b[46m";
    const char* on_white   = "\u001b[47m";

    const char* on_grey          = "\u001b[100m";
    const char* on_light_red     = "\u001b[101m";
    const char* on_light_green   = "\u001b[102m";
    const char* on_light_yellow  = "\u001b[103m";
    const char* on_light_blue    = "\u001b[104m";
    const char* on_light_magenta = "\u001b[105m";
    const char* on_light_cyan    = "\u001b[106m";
    const char* on_bright_white  = "\u001b[107m";

    inline bool is_atty(const std::ostream& stream)
    {
      if (typeid(stream) == typeid(std::fstream) ||
          typeid(stream) == typeid(std::stringstream) ||
          typeid(stream) == typeid(std::streambuf)) {

        return false;

      } else {
        #if defined(TERM_MAC) || defined(TERM_NIX)
          return isatty(STDOUT_FILENO);
        #elif defined(TERM_WIN)
          return _isatty(STDOUT_FILENO);
        #endif
      }
    }
  }

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


  /**
   * Colors
   */
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

}

#undef TERM_WIN
#undef TERM_NIX
#undef TERM_MAC

#endif  // !TERMCLR_HPP
