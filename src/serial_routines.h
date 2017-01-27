/*
 * serial_routines.h
 *
 *  Created on: Jan 27, 2017
 *      Author: victorhantelmann
 */

#ifndef SERIAL_ROUTINES_H_
#define SERIAL_ROUTINES_H_

#include <string>
#include <algorithm>
#include <iostream>

#include <cstdio>
#include <string>
#include <cassert>

#include <termios.h>

#include "serial_errors.h"

std::string to_string(unsigned int x) {
  int length = snprintf (NULL, 0, "%d", x);
  assert (length >= 0);
  char* buf = new char[length + 1];
  snprintf (buf, length + 1, "%d", x);
  std::string str (buf);
  delete[] buf;
  return str;
}

std::string to_string(int x) {
  int length = snprintf (NULL, 0, "%d", x);
  assert (length >= 0);
  char* buf = new char[length + 1];
  snprintf (buf, length + 1, "%d", x);
  std::string str (buf);
  delete[] buf;
  return str;
}

std::string to_string(unsigned short x) {
  int length = snprintf (NULL, 0, "%d", x);
  assert (length >= 0);
  char* buf = new char[length + 1];
  snprintf (buf, length + 1, "%d", x);
  std::string str (buf);
  delete[] buf;
  return str;
}

std::string to_string(short x) {
  int length = snprintf (NULL, 0, "%d", x);
  assert (length >= 0);
  char* buf = new char[length + 1];
  snprintf (buf, length + 1, "%d", x);
  std::string str (buf);
  delete[] buf;
  return str;
}

std::string to_string(unsigned char x) {
  int length = snprintf (NULL, 0, "%d", x);
  assert (length >= 0);
  char* buf = new char[length + 1];
  snprintf (buf, length + 1, "%d", x);
  std::string str (buf);
  delete[] buf;
  return str;
}

std::string to_string(char x) {
  int length = snprintf (NULL, 0, "%d", x);
  assert (length >= 0);
  char* buf = new char[length + 1];
  snprintf (buf, length + 1, "%d", x);
  std::string str (buf);
  delete[] buf;
  return str;
}

class port {
  public:
    port ();
    port (std::string iName, unsigned int iBaud);
    port (std::string iName, unsigned int iBaud, unsigned char iDataBits, unsigned char iParity, unsigned char iStopBits);
    port (std::string iName, unsigned int iBaud, unsigned char iDataBits,   std::string iParity,   std::string iStopBits);
    ~port ();

    void show_all_options ();

    void setConfig (struct termios attr);
    struct termios getConfig ();
    int getFileStream ();

    void setName (std::string iName);
    std::string getName ();

    void setBaud (unsigned int iBaud);
    unsigned int getBaud ();
    std::string getBaud_Str ();

    void setDataBits(unsigned char iDataBits);
    unsigned char getDataBits ();

    void setParity(unsigned char iParity);
    void setParity(std::string iParity);
    unsigned char getParity();
    std::string getParity_Str();

    void setStopBits(unsigned char iStopBits);
    void setStopBits(std::string iStopBits);
    unsigned char getStopBits();
    std::string getStopBits_Str();

    serial_error* getError ();

  private:
    struct termios orig_attr;
    struct termios new_attr;

    int fstream;
    bool is_open;

    std::string name;
    unsigned int baud;
    std::string str_baud;
    unsigned char data_bits;
    std::string parity_str;
    unsigned char parity;
    std::string stop_bits_str;
    unsigned char stop_bits;

    serial_error error[8];
};
port::port() {
  /** @NAME                     *//** @BAUD                             */
  port::error[0] = err_empty_name; port::error[1] = err_baud_rate_not_set;
  /** @DATA                            *//** @PARITY                        */
  port::error[2] = err_data_bits_not_set; port::error[3] = err_parity_not_set;
  /** @STOP                            *//**                */
  port::error[4] = err_stop_bits_not_set; port::error[5] = ok;
  /**               *//**                */
  port::error[6] = ok; port::error[7] = ok;
  port::name = "";
  port::baud          =   0; port::str_baud  = "B0";
  port::data_bits     = 255;
  port::parity_str    =  ""; port::parity    = 255;
  port::stop_bits_str =  ""; port::stop_bits = 255;
  port::is_open = false;     port::fstream = -1;
}
port::port(std::string iName, unsigned iBaud) {
  /** @NAME                     *//** @BAUD                             */
  port::error[0] = err_empty_name; port::error[1] = err_baud_rate_not_set;
  /** @DATA                            *//** @PARITY                        */
  port::error[2] = err_data_bits_not_set; port::error[3] = err_parity_not_set;
  /** @STOP                            *//**                */
  port::error[4] = err_stop_bits_not_set; port::error[5] = ok;
  /**               *//**                */
  port::error[6] = ok; port::error[7] = ok;
  port::setName(iName);      port::setBaud(iBaud);
  port::data_bits     = 255;
  port::parity_str    =  ""; port::parity    = 255;
  port::stop_bits_str =  ""; port::stop_bits = 255;
  port::is_open = false;     port::fstream = -1;
}
port::port (std::string iName, unsigned int iBaud, unsigned char iDataBits, unsigned char iParity, unsigned char iStopBits) {
  /** @NAME                     *//** @BAUD                             */
  port::error[0] = err_empty_name; port::error[1] = err_baud_rate_not_set;
  /** @DATA                            *//** @PARITY                        */
  port::error[2] = err_data_bits_not_set; port::error[3] = err_parity_not_set;
  /** @STOP                            *//**                */
  port::error[4] = err_stop_bits_not_set; port::error[5] = ok;
  /**               *//**                */
  port::error[6] = ok; port::error[7] = ok;
  port::setName(iName);    port::setBaud(iBaud);
  port::setDataBits(iDataBits);
  port::setParity(iParity);
  port::setStopBits(iStopBits);
  port::is_open = false;   port::fstream = -1;
}
port::port (std::string iName, unsigned int iBaud, unsigned char iDataBits, std::string iParity, std::string iStopBits) {
  /** @NAME                     *//** @BAUD                             */
  port::error[0] = err_empty_name; port::error[1] = err_baud_rate_not_set;
  /** @DATA                            *//** @PARITY                        */
  port::error[2] = err_data_bits_not_set; port::error[3] = err_parity_not_set;
  /** @STOP                            *//**                */
  port::error[4] = err_stop_bits_not_set; port::error[5] = ok;
  /**               *//**                */
  port::error[6] = ok;     port::error[7] = ok;
  port::setName(iName);    port::setBaud(iBaud);
  port::setDataBits(iDataBits);
  port::setParity(iParity);
  port::setStopBits(iStopBits);
  port::is_open = false;   port::fstream = -1;
}
port::~port () {}

void port::show_all_options () {
	std::cout << "*** BAUD OPTIONS ***" << std::endl;
	for (unsigned int i = 0; i < baud_vector.size(); i++) {
		std::cout << to_string(baud_vector.at(i)) << " | ";
	}
	std::cout << std::endl << "*** DATA OPTIONS ***" << std::endl;
	for (unsigned int i = 0; i < data_bits_vector.size(); i++) {
		std::cout << to_string(data_bits_vector.at(i)) << " | ";
	}
	std::cout << std::endl << "*** PARITY OPTIONS ***" << std::endl;
	for (unsigned int i = 0; i < parity_str_vector.size(); i++) {
		std::cout << parity_str_vector.at(i) << " | ";
	}
	std::cout << std::endl << "*** STOP OPTIONS ***" << std::endl;
	for (unsigned int i = 0; i < stop_bits_str_vector.size(); i++) {
		std::cout << stop_bits_str_vector.at(i) << " | ";
	}
	std::cout << std::endl << "*** END *** OPTIONS ***" <<  std::endl;
}

void port::setName (std::string iName) {
    iName.erase(std::remove_if(iName.begin(), iName.end(), ::isspace), iName.end());
    std::string origName = iName;
    transform(iName.begin(), iName.end(), iName.begin(), ::toupper);
    if (iName.compare("") == 0) {
        port::error[0] = err_empty_name;
        port::name = "";
        return;
    } else if (!((iName.find("TTY") >= 0 && iName.find("TTY") < iName.length()) ||
                 (iName.find("CU")  >= 0 && iName.find("CU")  < iName.length()) ||
                 (iName.find("COM") >= 0 && iName.find("COM") < iName.length()))) {
        port::error[0] = err_wrong_name;
        port::name = "";
        return;
    } else {
        port::error[0] = ok;
        port::name = origName;
    }
}
std::string port::getName () { return port::name; }

void port::setBaud (unsigned int iBaud) {
    if (iBaud != 0) {
        bool baud_found = false;
        for (unsigned int i = 0; i < baud_vector.size(); i++) {
        	if (baud_vector.at(i) == iBaud) { baud_found = true; break;	}
        }
        if (baud_found) {
            port::error[1] = ok;
        } else {
            port::error[1] = err_baud_rate;
            port::baud = 0;
            port::str_baud = "B0";
        }
    } else {
        port::error[1] = err_baud_rate_not_set;
        port::baud = 0;
        port::str_baud = "B0";
    }
    if (port::error[1].what().compare(NO_ERROR) == 0) {
        port::baud = iBaud;
        port::str_baud = "B" + to_string(iBaud);
    } else {
        port::baud = 0;
        port::str_baud = "B0";
    }
}

unsigned int port::getBaud ()    { return port::baud; }
std::string port::getBaud_Str () { return port::str_baud; }

void port::setDataBits(unsigned char iDataBits) {
    if (iDataBits != 255) {
        bool dataBits_found = false;
        for (unsigned int i = 0; i < data_bits_vector.size(); i++) {
        	if (data_bits_vector.at(i) == iDataBits) { dataBits_found = true; break; }
        }
        if (dataBits_found) {
            port::error[2] = ok;
        } else {
            port::error[2] = err_data_bits;
            port::data_bits = 255;
        }
    } else {
        port::error[2] = err_data_bits_not_set;
        port::data_bits = 255;
    }
    if (port::error[2].what().compare(NO_ERROR) == 0) {
        port::data_bits = iDataBits;
    } else {
        port::data_bits = 255;
    }
}
unsigned char port::getDataBits() { return port::data_bits; }

void port::setParity(unsigned char iParity) {
    if (iParity != 255) {
        if (iParity == 0 || iParity == 1 || iParity == 2 || iParity == 3 || iParity == 4) {
            port::error[3] = ok;
        } else {
            port::error[3] = err_parity;
            port::parity = 255;
            port::parity_str = "";
        }
    } else {
        port::error[3] = err_parity_not_set;
        port::parity = 255;
        port::parity_str = "";
    }
    if (port::error[3].what().compare(NO_ERROR) == 0) {
        port::parity = iParity;
        port::parity_str = parity_str_vector[iParity];
    } else {
        port::parity = 255;
        port::parity_str = "";
    }
}
void port::setParity(std::string iParity) {
    if (iParity.compare("") == 0) {
        port::error[3] = err_parity_empty_string;
        port::parity = 255;
        port::parity_str = "";
    } else {
        transform(iParity.begin(), iParity.end(), iParity.begin(), ::toupper);
        iParity.erase(std::remove_if(iParity.begin(), iParity.end(), ::isspace), iParity.end());
        if (
            iParity.compare("NONE")  == 0 ||
            iParity.compare("ODD")   == 0 ||
            iParity.compare("EVEN")  == 0 ||
            iParity.compare("SPACE") == 0 ||
            iParity.compare("MARK")  == 0) {
            port::error[3] = ok;
        } else {
            port::error[3] = err_parity;
            port::parity = 255;
            port::parity_str = "";
        }
    }
    if (port::error[3].what().compare(NO_ERROR) == 0) {
        port::parity_str = iParity;
        if (iParity.compare("NONE")  == 0) { port::parity = 0; }
        if (iParity.compare("ODD")   == 0) { port::parity = 1; }
        if (iParity.compare("EVEN")  == 0) { port::parity = 2; }
        if (iParity.compare("SPACE") == 0) { port::parity = 3; }
        if (iParity.compare("MARK")  == 0) { port::parity = 4; }
    } else {
        port::parity = 255;
        port::parity_str = "";
    }
}
unsigned char port::getParity ()   { return port::parity;     }
std::string port::getParity_Str () { return port::parity_str; }

void port::setStopBits(unsigned char iStopBits) {
    if (iStopBits != 255) {
        if (iStopBits == 0 || iStopBits == 1 || iStopBits == 2) {
            port::error[4] = ok;
        } else {
            port::error[4] = err_stop_bits;
            port::stop_bits = 255;
            port::stop_bits_str = "";
        }
    } else {
        port::error[4] = err_stop_bits_not_set;
        port::stop_bits = 255;
        port::stop_bits_str = "";
    }
    if (port::error[4].what().compare(NO_ERROR) == 0) {
        port::stop_bits = iStopBits;
        port::stop_bits_str = stop_bits_str_vector[iStopBits];
    } else {
        port::stop_bits = 255;
        port::stop_bits_str = "";
    }
}
void port::setStopBits (std::string iStopBits) {
    if (iStopBits.compare("") == 0) {
        port::error[4] = err_stop_bits_empty_string;
        port::stop_bits = 255;
        port::stop_bits_str = "";
    } else {
        transform(iStopBits.begin(), iStopBits.end(), iStopBits.begin(), ::toupper);
        iStopBits.erase(std::remove_if(iStopBits.begin(), iStopBits.end(), ::isspace), iStopBits.end());
        if (
            iStopBits.compare("ONE")  == 0 ||
            iStopBits.compare("ONE5") == 0 ||
            iStopBits.compare("TWO")  == 0) {
            port::error[4] = ok;
        } else {
            port::error[4] = err_stop_bits;
            port::stop_bits = 255;
            port::stop_bits_str = "";
        }
    }
    if (port::error[4].what().compare(NO_ERROR) == 0) {
        port::stop_bits_str = iStopBits;
        if (iStopBits.compare("ONE")  == 0) { port::stop_bits = 0; }
        if (iStopBits.compare("ONE5") == 0) { port::stop_bits = 1; }
        if (iStopBits.compare("TWO")  == 0) { port::stop_bits = 2; }
    } else {
        port::stop_bits = 255;
        port::stop_bits_str = "";
    }
}
unsigned char port::getStopBits ()   { return port::stop_bits;     }
std::string port::getStopBits_Str () { return port::stop_bits_str; }

serial_error* port::getError()       { return port::error; }

#endif /* SERIAL_ROUTINES_H_ */
