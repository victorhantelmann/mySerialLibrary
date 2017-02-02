/*
 * serial_constants.h
 *
 *  Created on: Jan 27, 2017
 *      Author: victorhantelmann
 */

#ifndef SERIAL_CONSTANTS_H_
#define SERIAL_CONSTANTS_H_

#include <vector>

static const unsigned int baud_array[] = {0, 50, 75, 110, 134, 150, 200, 300, 600, 1200, 1800, 2400, 4800, 9600, 19200, 38400, 57600, 76800, 115200, 230400, 460800, 500000, 576000, 921600, 1000000, 1152000, 1500000, 2000000, 2500000, 3000000, 3500000, 4000000};
const std::vector<unsigned int> baud_vector (baud_array, baud_array + sizeof(baud_array) / sizeof(baud_array[0]) );

static const unsigned char data_bits_array[] = { 5, 6, 7, 8, 9 };
const std::vector<unsigned int> data_bits_vector (data_bits_array, data_bits_array + sizeof(data_bits_array) / sizeof(data_bits_array[0]));

static const std::string parity_str_array[] = {"NONE", "ODD", "EVEN", "SPACE", "MARK"};
const std::vector<std::string> parity_str_vector (parity_str_array, parity_str_array + sizeof(parity_str_array) / sizeof(parity_str_array[0]));

static const std::string stop_bits_str_array[] = {"ONE", "ONE5", "TWO"};
const std::vector<std::string> stop_bits_str_vector (stop_bits_str_array, stop_bits_str_array + sizeof(stop_bits_str_array) / sizeof(stop_bits_str_array[0]));

const std::string ERROR         = "[ERROR]: ";
const std::string NO_ERROR      = "ok";
const std::string EMPTY         = "[EMPTY] ";
const std::string WRONG         = "[WRONG] ";
const std::string BAUD          = "[BAUD RATE] ";
const std::string DATA_BITS     = "[DATA BITS] ";
const std::string PARITY        = "[PARITY] ";
const std::string STOP_BITS     = "[STOP BITS] ";
const std::string IS_SET        = "[is SET] ";
const std::string NOT_SET       = "[not SET] ";
const std::string NOT_SUCCEDED  = "[not SUCCEDED] ";
const std::string NOT_AVAILABLE = "[not AVAILABLE] ";
const std::string OSX           = "OSX ";
const std::string WIN           = "WIN ";
const std::string MAC           = "MAC ";
const std::string NLDLY_        = "[par. NLDLY] ";
const std::string CRDLY_        = "[par. CRDLY] ";
const std::string TABDLY_       = "[par. TABDLY] ";
const std::string VTDLY_        = "[par. VTDLY] ";
const std::string FFDLY_        = "[par. FFDLY] ";
const std::string CSIZE_        = "[par. CSIZE] ";

const std::string TERMIOS = "termios ";
const std::string ATTRIB  = "attribute ";
const std::string CAN_T   = "can't ";
const std::string READ    = "read ";
const std::string WRITE   = "write ";
const std::string SET     = "set ";
const std::string PASS    = "pass ";
const std::string PORT    = "port ";
const std::string STRUCT  = "structure ";
const std::string CONFIG  = "config. ";
const std::string STRING  = "string ";
const std::string NAME    = "name ";
const std::string NO_OF   = "number of ";
const std::string ON      = "on ";
const std::string IS      = "is ";
const std::string OF      = "of ";

const std::string ERR_EMPTY_NAME                   = ERROR + EMPTY + PORT + NAME;
const std::string ERR_WRONG_NAME                   = ERROR + WRONG + PORT + NAME;
const std::string ERR_BAUD                         = ERROR + WRONG + BAUD;
const std::string ERR_BAUD_NOT_SET                 = ERROR + BAUD + NOT_SET;
const std::string ERR_DATA_BITS                    = ERROR + WRONG + NO_OF + DATA_BITS;
const std::string ERR_DATA_BITS_NOT_SET            = ERROR + DATA_BITS + NOT_SET;
const std::string ERR_PARITY                       = ERROR + WRONG + CONFIG + ON + PARITY;
const std::string ERR_PARITY_NOT_SET               = ERROR + PARITY + NOT_SET;
const std::string ERR_PARITY_EMPTY_STRING          = ERROR + PARITY + STRING + IS + EMPTY;
const std::string ERR_STOP_BITS                    = ERROR + WRONG + CONFIG + ON + STOP_BITS;
const std::string ERR_STOP_BITS_NOT_SET            = ERROR + STOP_BITS + NOT_SET;
const std::string ERR_STOP_BITS_EMPTY_STRING       = ERROR + STOP_BITS + STRING + IS + EMPTY;
const std::string ERR_CAN_T_READ_TERMIOS_ATTRIBUTE = ERROR + CAN_T + READ + TERMIOS + ATTRIB;
const std::string ERR_CAN_T_SET_TERMIOS_BAUD       = ERROR + CAN_T + SET + TERMIOS + BAUD;
const std::string ERR_CAN_T_SET_TERMIOS_NLDLY      = ERROR + CAN_T + SET + TERMIOS + NLDLY_;
const std::string ERR_CAN_T_SET_TERMIOS_CRDLY      = ERROR + CAN_T + SET + TERMIOS + CRDLY_;
const std::string ERR_CAN_T_SET_TERMIOS_TABDLY     = ERROR + CAN_T + SET + TERMIOS + TABDLY_;
const std::string ERR_CAN_T_SET_TERMIOS_VTDLY      = ERROR + CAN_T + SET + TERMIOS + VTDLY_;
const std::string ERR_CAN_T_SET_TERMIOS_FFDLY      = ERROR + CAN_T + SET + TERMIOS + FFDLY_;
const std::string ERR_CAN_T_SET_TERMIOS_CSIZE      = ERROR + CAN_T + SET + TERMIOS + CSIZE_;
const std::string ERR_CAN_T_PASS_TERMIOS_STRUCT    = ERROR + CAN_T + PASS + TERMIOS + STRUCT;

#endif /* SERIAL_CONSTANTS_H_ */
