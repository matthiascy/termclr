#include <iostream>
#include <cstdlib>
#include "../termclr.hpp"


int main(int argc, char **argv)
{
  using namespace termclr;
  std::cout << black      << "black text 30"   << reset_all << std::endl;
  std::cout << red        << "red text 31"     << reset_all << std::endl;
  std::cout << green      << "green text 32"   << reset_all << std::endl;
  std::cout << yellow     << "yellow text 33"  << reset_all << std::endl;
  std::cout << blue       << "blue text 34"    << reset_all << std::endl;
  std::cout << magenta    << "magenta text 35" << reset_all << std::endl;
  std::cout << cyan       << "cyan text 36"    << reset_all << std::endl;
  std::cout << silver      << "silver text 37"   << reset_all << std::endl;
  std::cout << std::endl;
  std::cout << grey          << "grey text 90"          << reset_all << std::endl;
  std::cout << light_red     << "light red text 91"     << reset_all << std::endl;
  std::cout << light_green   << "light green text 92"   << reset_all << std::endl;
  std::cout << light_yellow  << "light yellow text 93"  << reset_all << std::endl;
  std::cout << light_blue    << "light blue text 94"    << reset_all << std::endl;
  std::cout << light_magenta << "light magenta text 95" << reset_all << std::endl;
  std::cout << turquoise     << "turquoise text 96"     << reset_all << std::endl;
  std::cout << white        << "white text 97"        << reset_all << std::endl;
  std::cout << std::endl;
  std::cout << on_black   << "on black 40"   << reset_all << std::endl;
  std::cout << on_red     << "on red 41"     << reset_all << std::endl;
  std::cout << on_green   << "on green 42"   << reset_all << std::endl;
  std::cout << on_yellow  << "on yellow 43"  << reset_all << std::endl;
  std::cout << on_blue    << "on blue 44"    << reset_all << std::endl;
  std::cout << on_magenta << "on magenta 45" << reset_all << std::endl;
  std::cout << on_cyan    << "on cyan 46"    << reset_all << std::endl;
  std::cout << on_silver  << "on silver 47"   << reset_all << std::endl;
  std::cout << on_grey    << "on grey 100"   << reset_all << std::endl;
  std::cout << on_light_red     << "on light red 101"     << reset_all << std::endl;
  std::cout << on_light_green   << "on light green 102"   << reset_all << std::endl;
  std::cout << on_light_yellow  << "on light yellow 103"  << reset_all << std::endl;
  std::cout << on_light_blue    << "on light blue 104"    << reset_all << std::endl;
  std::cout << on_light_magenta << "on light magenta 105" << reset_all << std::endl;
  std::cout << on_light_cyan    << "on light cyan 106"    << reset_all << std::endl;
  std::cout << on_white        << "on white 107"        << reset_all << std::endl;

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
