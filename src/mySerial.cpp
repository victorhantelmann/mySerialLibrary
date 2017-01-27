#include <iostream>
#include <stdexcept>
#include "serial_routines.h"
#include "serial_errors.h"

int main(int argc, char **argv) {
  port p;
  std::cout << "++++++++++ NAME ++++++++++" << std::endl;
  p.setName("/dev/ttyUSB0");
  std::cout << "p.getName:         " << p.getName() << std::endl;
  std::cout << "++++++++++ BAUD ++++++++++" << std::endl;
  p.setBaud(115200);
  std::cout << "p.getBaud:         " << to_string(p.getBaud()) << std::endl;
  std::cout << "p.getStrBaud:      " << p.getBaud_Str() << std::endl;
  std::cout << "++++++++++ DATA ++++++++++" << std::endl;
  p.setDataBits(8);
  std::cout << "p.getDataBits:     " << to_string(p.getDataBits()) << std::endl;
  std::cout << "+++++++++ PARITY +++++++++" << std::endl;
  p.setParity(0);
  std::cout << "p.getParity_Str:   " << p.getParity_Str() << std::endl;
  std::cout << "p.getParity:       " << to_string(p.getParity()) << std::endl;
  std::cout << "++++++++++ STOP ++++++++++" << std::endl;
  p.setStopBits(0);
  std::cout << "p.getStopBits_Str: " << p.getStopBits_Str() << std::endl;
  std::cout << "p.getStopBits:     " << to_string(p.getStopBits()) << std::endl;

  std::cout << "+++++++++ STATUS +++++++++" << std::endl;

  std::cout << "p.getError NAME:   " << p.getError()[0].what() << std::endl;
  std::cout << "p.getError BAUD:   " << p.getError()[1].what() << std::endl;
  std::cout << "p.getError DATA:   " << p.getError()[2].what() << std::endl;
  std::cout << "p.getError PARITY: " << p.getError()[3].what() << std::endl;
  std::cout << "p.getError STOP:   " << p.getError()[4].what() << std::endl;

  std::cout << "+++++++ END STATUS +++++++" << std::endl;
  p.show_all_options();
  return 0;
}
