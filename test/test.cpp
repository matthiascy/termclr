#include <iostream>
#include <cstdlib>
#include "../termclr.hpp"


int main(int argc, char **argv)
{
  using namespace termclr;
  std::cout << black      << "black   text 30" << reset << std::endl;
  std::cout << red        << "red     text 31" << reset << std::endl;
  std::cout << green      << "green   text 32" << reset << std::endl;
  std::cout << yellow     << "yellow  text 33" << reset << std::endl;
  std::cout << blue       << "blue    text 34" << reset << std::endl;
  std::cout << magenta    << "magenta text 35" << reset << std::endl;
  std::cout << cyan       << "cyan    text 36" << reset << std::endl;
  std::cout << white      << "white   text 37" << reset << std::endl;
  std::cout << std::endl;
  std::cout << grey          << "grey          text 90" << reset << std::endl;
  std::cout << light_red     << "light red     text 91" << reset << std::endl;
  std::cout << light_green   << "light green   text 92" << reset << std::endl;
  std::cout << light_yellow  << "light yellow  text 93" << reset << std::endl;
  std::cout << light_blue    << "light blue    text 94" << reset << std::endl;
  std::cout << light_magenta << "light magenta text 95" << reset << std::endl;
  std::cout << light_cyan    << "light cyan    text 96" << reset << std::endl;
  std::cout << bright_white  << "bright white  text 97" << reset << std::endl;
  std::cout << std::endl;
  std::cout << on_black   << "on black   text 40" << reset << std::endl;
  std::cout << on_red     << "on red     text 41" << reset << std::endl;
  std::cout << on_green   << "on green   text 42" << reset << std::endl;
  std::cout << on_yellow  << "on yellow  text 43" << reset << std::endl;
  std::cout << on_blue    << "on blue    text 44" << reset << std::endl;
  std::cout << on_magenta << "on magenta text 45" << reset << std::endl;
  std::cout << on_cyan    << "on cyan    text 46" << reset << std::endl;
  std::cout << on_white   << "on white   text 47" << reset << std::endl;
  std::cout << on_grey          << "on grey          text 100" << reset << std::endl;
  std::cout << on_light_red     << "on light red     text 101" << reset << std::endl;
  std::cout << on_light_green   << "on light green   text 102" << reset << std::endl;
  std::cout << on_light_yellow  << "on light yellow  text 103" << reset << std::endl;
  std::cout << on_light_blue    << "on light blue    text 104" << reset << std::endl;
  std::cout << on_light_magenta << "on light magenta text 105" << reset << std::endl;
  std::cout << on_light_cyan    << "on light cyan    text 106" << reset << std::endl;
  std::cout << on_bright_white  << "on bright white  text 107" << reset << std::endl;
  std::cout << std::endl;
  std::cout << bold       << "bold       text 1" << reset << std::endl;
  std::cout << dim        << "dim        text 2" << reset << std::endl;
  std::cout << italic     << "italic     text 3" << reset << std::endl;
  std::cout << underline  << "underline  text 4" << reset << std::endl;
  std::cout << blink      << "blink      text 5" << reset << std::endl;
  std::cout << inverse    << "inverse    text 7" << reset << std::endl;
  std::cout << conceal    << "conceal    text 8" << reset << std::endl;
  std::cout << crossedout << "crossedout text 9" << reset << std::endl;

  /*
  char* term = getenv("TERM");
  char* colr =getenv("COLORTERM");
  if (term != nullptr)
    std::cout << term << std::endl;

  if (colr != nullptr)
    std::cout << colr << std::endl;
  */

  return 0;
}
