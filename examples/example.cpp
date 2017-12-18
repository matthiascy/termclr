#include <iostream>
#include <cstdlib>
#include "../termclr.hpp"

int main(int argc, char **argv)
{
  std::cout << "Bonjour, welcome to termclr testing field." << std::endl;

  std::cout << termclr::black         << "black   text 30" << termclr::reset << std::endl;
  std::cout << termclr::red           << "red     text 31" << termclr::reset << std::endl;
  std::cout << termclr::green         << "green   text 32" << termclr::reset << std::endl;
  std::cout << termclr::yellow        << "yellow  text 33" << termclr::reset << std::endl;
  std::cout << termclr::blue          << "blue    text 34" << termclr::reset << std::endl;
  std::cout << termclr::magenta       << "magenta text 35" << termclr::reset << std::endl;
  std::cout << termclr::cyan          << "cyan    text 36" << termclr::reset << std::endl;
  std::cout << termclr::white         << "white   text 37" << termclr::reset << std::endl;
  std::cout << std::endl;
  std::cout << termclr::grey          << "grey          text 90" << termclr::reset << std::endl;
  std::cout << termclr::light_red     << "light red     text 91" << termclr::reset << std::endl;
  std::cout << termclr::light_green   << "light green   text 92" << termclr::reset << std::endl;
  std::cout << termclr::light_yellow  << "light yellow  text 93" << termclr::reset << std::endl;
  std::cout << termclr::light_blue    << "light blue    text 94" << termclr::reset << std::endl;
  std::cout << termclr::light_magenta << "light magenta text 95" << termclr::reset << std::endl;
  std::cout << termclr::light_cyan    << "light cyan    text 96" << termclr::reset << std::endl;
  std::cout << termclr::bright_white  << "bright white  text 97" << termclr::reset << std::endl;
  std::cout << std::endl;
  std::cout << termclr::on_black         << "on black   text 40" << termclr::reset << std::endl;
  std::cout << termclr::on_red           << "on red     text 41" << termclr::reset << std::endl;
  std::cout << termclr::on_green         << "on green   text 42" << termclr::reset << std::endl;
  std::cout << termclr::on_yellow        << "on yellow  text 43" << termclr::reset << std::endl;
  std::cout << termclr::on_blue          << "on blue    text 44" << termclr::reset << std::endl;
  std::cout << termclr::on_magenta       << "on magenta text 45" << termclr::reset << std::endl;
  std::cout << termclr::on_cyan          << "on cyan    text 46" << termclr::reset << std::endl;
  std::cout << termclr::on_white         << "on white   text 47" << termclr::reset << std::endl;
  std::cout << termclr::on_grey          << "on grey          text 100" << termclr::reset << std::endl;
  std::cout << termclr::on_light_red     << "on light red     text 101" << termclr::reset << std::endl;
  std::cout << termclr::on_light_green   << "on light green   text 102" << termclr::reset << std::endl;
  std::cout << termclr::on_light_yellow  << "on light yellow  text 103" << termclr::reset << std::endl;
  std::cout << termclr::on_light_blue    << "on light blue    text 104" << termclr::reset << std::endl;
  std::cout << termclr::on_light_magenta << "on light magenta text 105" << termclr::reset << std::endl;
  std::cout << termclr::on_light_cyan    << "on light cyan    text 106" << termclr::reset << std::endl;
  std::cout << termclr::on_bright_white  << "on bright white  text 107" << termclr::reset << std::endl;
  std::cout << std::endl;
  std::cout << termclr::bold       << "bold       text 1" << termclr::reset << std::endl;
  std::cout << termclr::dim        << "dim        text 2" << termclr::reset << std::endl;
  std::cout << termclr::italic     << "italic     text 3" << termclr::reset << std::endl;
  std::cout << termclr::underline  << "underline  text 4" << termclr::reset << std::endl;
  std::cout << termclr::blink      << "blink      text 5" << termclr::reset << std::endl;
  std::cout << termclr::inverse    << "inverse    text 7" << termclr::reset << std::endl;
  std::cout << termclr::conceal    << "conceal    text 8" << termclr::reset << std::endl;
  std::cout << termclr::crossedout << "crossedout text 9" << termclr::reset << std::endl;

  std::stringstream str;
  str << termclr::italic << termclr::on_cyan << "italic text on cyan from stringstream" << termclr::reset << std::endl;
  std::cout << str.str() << std::endl;
  std::ofstream out_file("out.txt", std::ios::app);
  out_file << str.str();
  out_file.close();

  return 0;
}
