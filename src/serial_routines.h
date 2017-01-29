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

#include <termios.h>  // Used for UART
#include <fcntl.h>    // Used for UART
#include <unistd.h>   // Used for UART

#include "serial_errors.h"

struct termios orig_attr;
struct termios new_attr;

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

    bool doOpen ();
    bool doClose ();
    int saveSetup ();
    int restoreSetup ();
    // c_iflag flag constants for [ INPUT ] -> SET
    int setIGNBRK (bool v);    bool getIGNBRK ();
    int setBRKINT (bool v);    bool getBRKINT ();
    int setIGNPAR (bool v);    bool getIGNPAR ();
    int setPARMRK (bool v);    bool getPARMRK ();
    int setINPCK  (bool v);    bool getINPCK  ();
    int setISTRIP (bool v);    bool getISTRIP ();
    int setINLCR  (bool v);    bool getINLCR  ();
    int setIGNCR  (bool v);    bool getIGNCR  ();
    int setICRNL  (bool v);    bool getICRNL  ();
    int setIXON   (bool v);    bool getIXON   ();
    int setIXOFF  (bool v);    bool getIXOFF  ();
    int setIXANY  (bool v);    bool getIXANY  ();
    int setIUTF8  (bool v);    bool getIUTF8  ();
    serial_error* getError ();

    // c_iflag flag constants for [ INPUT ]
    class inFlags {
    public:
    	bool ignbrk;        // IGNBRK   = Ignore BREAK
    	bool brkint;        // BRKINT   = BREAK causes the input and output queues to be flushed
    	bool ignpar;        // IGNPAR   = Ignore framing errors and parity errors
    	bool parmrk;        // PARMRK   = If bit is set, input bytes with parity or framing errors are marked when passed to the program
    	bool inpck;         // INPCK    = Enable input parity checking
    	bool istrip;        // ISTRIP   = Strip off eighth bit
    	bool inlcr;         // INLCR    = Translate NL to CR on input
    	bool igncr;         // IGNCR    = Ignore carriage return on input
    	bool icrnl;         // ICRNL    = Translate carriage return to newline on input (unless IGNCR is set)
    	bool ixon;          // IXON     = Enable XON/XOFF flow control on output
    	bool ixoff;         // IXOFF    = Enable XON/XOFF flow control on input
    	bool ixany;         // IXANY    = (XSI) Typing any character will restart stopped output.
    	bool iutf8;         // IUTF8    = (since Linux 2.6.4) (not in POSIX) Input is UTF8; this allows character-erase to be correctly performed in cooked mode
    }inFlags;
  private:

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

    // c_oflag flag constants for [ OUTPUT ]
    bool opost;         // OPOST    = Enable implementation-defined output processing
    bool onlcr;         // ONLCR    = (XSI) Map NL to CR-NL on output
    bool ocrnl;         // OCRNL    = Map CR to NL on output
    bool onocr;         // ONOCR    = Don't output CR at column 0
    bool onlret;        // ONLRET   = Don't output CR
    bool ofill; // OFILL    = Send fill characters for a delay, rather than using a timed delay
    std::string nldly;  // NLDLY   = Newline delay mask. Values are NL0 and NL1. [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
    std::string crdly;  // CRDLY   = Carriage return delay mask. Values are CR0, CR1, CR2, or CR3. [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
    std::string tabdly; // TABDLY  = Horizontal tab delay mask. Values are TAB0, TAB1, TAB2, TAB3 (or XTABS). A value of TAB3, that is, XTABS, expands tabs to spaces (with tab stops every eight columns). [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
    std::string vtdly;  // VTDLY   = Vertical tab delay mask. Values are VT0 or VT1
    std::string ffdly;  // FFDLY   = Form feed delay mask.  Values are FF0 or FF1. [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
    //bool olcuc;    // OLCUC    = (not in POSIX) Map lowercase characters to uppercase on output
    //bool ofdel;    // OFDEL    = (Not implemented on Linux.) Fill character is ASCII DEL (0177). If unset, fill character is ASCII NUL ('\0')
    //std::string bsdly;  // BSDLY   = (Has never been implemented.) Backspace delay mask. Values are BS0 or BS1. [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
    // c_cflag flag constants for [ CONTROL ]
    std::string csize;  // CSIZE    = Character size mask. Values are CS5, CS6, CS7, or CS8.
    bool cstopb;        // CSTOPB   = Set two stop bits, rather than one
    bool cread;         // CREAD    = Enable receiver
    bool parenb;        // PARENB   = Enable parity generation on output and parity checking for input
    bool parodd;        // PARODD   = If set, then parity for input and output is ODD; otherwise EVEN parity is used
    bool hupcl;         // HUPCL    = (hang up) Lower modem control lines after last process closes the device
    bool clocal;        // CLOCAL   = Ignore modem control lines
    //bool cbaud;    // CBAUD    = (not in POSIX) Baud speed mask (4+1 bits).  [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool cbaudex;  // CBAUDEX  = (not in POSIX) Extra baud speed mask (1 bit), included in CBAUD. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool loblk;    // LOBLK    = (not in POSIX) (Not implemented on Linux.) Block output from a noncurrent shell layer. For use by shl (shell layers).
    //bool cibaud;   // CIBAUD   = (not in POSIX) (Not implemented on Linux.) Mask for input speeds. The values for the CIBAUD bits are the same as the values for the CBAUD bits, shifted left IBSHIFT bits. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool cmspar;   // CMSPAR   = (not in POSIX) Use "stick" (mark/space) parity (supported on certain serial devices): if PARODD is set, the parity bit is always 1; if PARODD is not set, then the parity bit is always 0. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool crtscts;  // CRTSCTS  = (not in POSIX) Enable RTS/CTS (hardware) flow control. [requires _BSD_SOURCE or _SVID_SOURCE]
    // c_lflag flag constants for [ LOCAL MODES ]
    bool isig;          // ISIG     = When any of the characters INTR, QUIT, SUSP, or DSUSP are received, generate the corresponding signal
    bool icanon;        // ICANON   = Enable canonical mode
    bool echo;          // ECHO     = Echo input characters
    bool echoe;         // ECHOE    = If ICANON is also set, the ERASE character erases the preceding input character, and WERASE erases the preceding word
    bool echok;         // ECHOK    = If ICANON is also set, the KILL character erases the current line
    bool echonl;        // ECHONL   = If ICANON is also set, echo the NL character even if ECHO is not set
    bool noflsh;        // NOFLSH   = Disable flushing the input and output queues when generating signals for the INT, QUIT, and SUSP characters
    bool tostop;        // TOSTOP   = Send the SIGTTOU signal to the process group of a background process which tries to write to its controlling terminal
    //bool xcase;    // XCASE    = (not in POSIX; not supported under Linux) If ICANON is also set, terminal is uppercase only. Input is converted to lowercase, except for characters preceded by \. On output, uppercase characters are preceded by \ and lowercase characters are converted to uppercase. [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
    //bool echoctl;  // ECHOCTL  = (not in POSIX) If ECHO is also set, terminal special characters other than TAB, NL, START, and STOP are echoed as ^X, where X is the character with ASCII code 0x40 greater than the special character. For example, character 0x08 (BS) is echoed as ^H. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool echoprt;  // ECHOPRT  = (not in POSIX) If ICANON and ECHO are also set, characters are printed as they are being erased. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool echoke;   // ECHOKE   = (not in POSIX) If ICANON is also set, KILL is echoed by erasing each character on the line, as specified by ECHOE and ECHOPRT. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool defecho;  // DEFECHO  = (not in POSIX) (Not implemented on Linux.) Echo only when a process is reading
    //bool flusho;   // FLUSHO   = (not in POSIX; not supported under Linux) Output is being flushed. This flag is toggled by typing the DISCARD character. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool pendin;   // PENDIN   = (not in POSIX; not supported under Linux) All characters in the input queue are reprinted when the next character is read
    bool iexten;        // IEXTEN   = Enable implementation-defined input processing. This flag, as well as ICANON must be enabled for the special characters EOL2, LNEXT, REPRINT, WERASE to be interpreted, and for the IUCLC flag to be Actionive
    // c_cc array that defines [ SPECIAL CHARACTERS ]
    bool veof;          // VEOF     = (004, EOT, Ctrl-D) End-of-file character (EOF). This character causes the pending tty buffer to be sent to the waiting user program without waiting for end-of-line. If it is the first character of the line, the read(2) in the user program returns 0, which signifies end-of-file. Recognized when ICANON is set, and then not passed as input
    bool veol;          // VEOL     = (0, NUL) Additional end-of-line character (EOL). Recognized when ICANON is set
    bool verase;        // VERASE   = (0177, DEL, rubout, or 010, BS, Ctrl-H, or also #) Erase character (ERASE). This erases the previous not-yet-erased character, but does not erase past EOF or beginning-of-line. Recognized when ICANON is set, and then not passed as input
    bool vintr;         // VINTR    = (003, ETX, Ctrl-C, or also 0177, DEL, rubout) Interrupt character (INTR). Send a SIGINT signal. Recognized when ISIG is set, and then not passed as input
    bool vkill;         // VKILL    = (025, NAK, Ctrl-U, or Ctrl-X, or also @) Kill character (KILL). This erases the input since the last EOF or beginning-of-line. Recognized when ICANON is set, and then not passed as input
    bool vmin;          // VMIN     = Minimum number of characters for noncanonical read (MIN)
    bool vquit;         // VQUIT    = (034, FS, Ctrl-\) Quit character (QUIT). Send SIGQUIT signal. Recognized when ISIG is set, and then not passed as input
    bool vstart;        // VSTART   = (021, DC1, Ctrl-Q) Start character (START). Restarts output stopped by the Stop character. Recognized when IXON is set, and then not passed as input
    bool vstop;         // VSTOP    = (023, DC3, Ctrl-S) Stop character (STOP). Stop output until Start character typed. Recognized when IXON is set, and then not passed as input
    bool vsusp;         // VSUSP    = (032, SUB, Ctrl-Z) Suspend character (SUSP). Send SIGTSTP signal. Recognized when ISIG is set, and then not passed as input
    unsigned int vtime; // VTIME = Timeout in deciseconds for noncanonical read (TIME)
    //bool vdiscard; // VDISCARD = (not in POSIX; not supported under Linux; 017, SI, Ctrl-O) Toggle: start/stop discarding pending output. Recognized when IEXTEN is set, and then not passed as input
    //bool vdsusp;   // VDSUSP   = (not in POSIX; not supported under Linux; 031, EM, Ctrl-Y) Delayed suspend character (DSUSP): send SIGTSTP signal when the character is read by the user program. Recognized when IEXTEN and ISIG are set, and the system supports job control, and then not passed as input
    //bool veol2;    // VEOL2    = (not in POSIX; 0, NUL) Yet another end-of-line character (EOL2). Recognized when ICANON is set
    //bool vlnext;   // VLNEXT   = (not in POSIX; 026, SYN, Ctrl-V) Literal next (LNEXT). Quotes the next input character, depriving it of a possible special meaning. Recognized when IEXTEN is set, and then not passed as input
    //bool vreprint; // VREPRINT = (not in POSIX; 022, DC2, Ctrl-R) Reprint unread characters (REPRINT). Recognized when ICANON and IEXTEN are set, and then not passed as input
    //bool vstatus;  // VSTATUS  = (not in POSIX; not supported under Linux; status request: 024, DC4, Ctrl-T).  Status character (STATUS). Display status information at terminal, including state of foreground process and amount of CPU time it has consumed. Also sends a SIGINFO signal (not supported on Linux) to the foreground process group
    //bool vstch;    // VSWTCH   = (not in POSIX; not supported under Linux; 0, NUL) Switch character (SWTCH). Used in System V to switch shells in shell layers, a predecessor to shell job control
    //bool vwerase;  // VWERASE  = (not in POSIX; 027, ETB, Ctrl-W) Word erase (WERASE). Recognized when ICANON and IEXTEN are set, and then not passed as input
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

bool port::doOpen () {
	if (port::name.compare("") == 0) {
		std::cout << ERROR + NAME + IS + EMPTY << std::endl;
	} else {
		port::fstream = open (port::name.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
/** @test */std::cout << "fstream: " << to_string(port::fstream) << " | port::name.c_str(): " << port::name.c_str() << std::endl;
	}
	if (port::fstream == -1) {
		port::is_open = false;
	} else {
		port::is_open = true;
	}
	return port::is_open;
}
bool port::doClose () {
	close(port::fstream);
	port::fstream = -1;
	port::is_open = false;
	return port::is_open;
}

int port::saveSetup () {
	int result = tcgetattr (port::fstream, &orig_attr);
	if (result < 0) {
		result = -1;
	} else {
		new_attr = orig_attr;
		result = 0;
	}
	return result;
}
int port::restoreSetup () {
	int result = tcsetattr (port::fstream, TCSANOW, &orig_attr);
	(result < 0) ? (result = -1) : (result = 0);
	return result;
}
/**
 * !
 * \brief function int port::setIGNBRK (bool v)
 * \param v as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IGNBRK.
 * Ignore BREAK.
 * A break condition is defined in the context of asynchronous serial
 * data transmission as a series of zero-value bits longer than a single byte.
 * */
bool port::getIGNBRK () { return port::inFlags.ignbrk; }
int port::setIGNBRK (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (IGNBRK)) : (new_attr.c_iflag & (IGNBRK));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.ignbrk = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setBRKINT (bool v)
 * \param v as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.BRKINT.
 * BREAK causes the input and output queues to be flushed.
 * If this bit is set and IGNBRK is not set, a break condition clears the terminal
 * input and output queues and raises a SIGINT signal for the foreground process
 * group associated with the terminal.
 * If neither BRKINT nor IGNBRK are set, a break condition is passed to the
 * application as a single '\0' character if PARMRK is not set,
 * or otherwise as a three-character sequence '\377', '\0', '\0'.
 * */
bool port::getBRKINT () { return port::inFlags.brkint; }
int port::setBRKINT (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (BRKINT)) : (new_attr.c_iflag & (BRKINT));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.brkint = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIGNPAR (bool v)
 * \param v as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IGNPAR.
 * If this bit is set, any byte with a framing or parity error is ignored.
 * This is only useful if INPCK is also set.
 * */
bool port::getIGNPAR () { return port::inFlags.ignpar; }
int port::setIGNPAR (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (IGNPAR)) : (new_attr.c_iflag & (IGNPAR));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.ignpar = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setPARMRK (bool v)
 * \param v as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.PARMRK.
 * If this bit is set, input bytes with parity or framing errors are marked when passed to the program.
 * This bit is meaningful only when INPCK is set and IGNPAR is not set.
 * The way erroneous bytes are marked is with two preceding bytes, 377 and 0.
 * Thus, the program actually reads three bytes for one erroneous byte received from the terminal.
 * If a valid byte has the value 0377, and ISTRIP is not set, the program might confuse it
 * with the prefix that marks a parity error.
 * So a valid byte 0377 is passed to the program as two bytes, 0377 0377, in this case.
 * */
bool port::getPARMRK () { return port::inFlags.parmrk; }
int port::setPARMRK (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (PARMRK)) : (new_attr.c_iflag & (PARMRK));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.parmrk = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setINPCK (bool v)
 * \param v as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.INPCK.
 * If this bit is set, input parity checking is enabled.
 * If it is not set, no checking at all is done for parity errors on input and
 * the characters are simply passed through to the application.
 * */
bool port::getINPCK () { return port::inFlags.inpck; }
int port::setINPCK (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (INPCK)) : (new_attr.c_iflag & (INPCK));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.inpck = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setISTRIP (bool v)
 * \param v as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ISTRIP.
 * If this bit is set, valid input bytes are stripped to seven bits.
 * Otherwise, all eight bits are available for programs to read.
 * */
bool port::getISTRIP () { return port::inFlags.istrip; }
int port::setISTRIP (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (ISTRIP)) : (new_attr.c_iflag & (ISTRIP));
	                       //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.istrip = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setINLCR (bool v)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.INLCR.
 * If this bit is set, newline characters ('\n') received as input are passed
 * to the application as carriage return characters ('\r').
 * */
bool port::getINLCR () { return port::inFlags.inlcr; }
int port::setINLCR (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (INLCR)) : (new_attr.c_iflag & (INLCR));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.inlcr = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIGNCR (bool v)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IGNCR.
 * If this bit is set, carriage return characters ('\r') are discarded on input.
 * Discarding carriage return may be useful on terminals that send both carriage
 * return and linefeed when you type the RET key.
 * */
bool port::getIGNCR () { return port::inFlags.igncr; }
int port::setIGNCR (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (IGNCR)) : (new_attr.c_iflag & (IGNCR));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.igncr = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setICRNL (bool v)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ICRNL.
 * If this bit is set and IGNCR is not set, carriage return characters ('\r')
 * received as input are passed to the application as newline characters ('\n').
 * */
bool port::getICRNL () { return port::inFlags.icrnl; }
int port::setICRNL (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (ICRNL)) : (new_attr.c_iflag & (ICRNL));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.icrnl = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIXON (bool v)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IXON.
 * If this bit is set, start/stop control on output is enabled.
 * In other words, if the computer receives a STOP character, it suspends output
 * until a START character is received.
 * In this case, the STOP and START characters are never passed to the application program.
 * If this bit is not set, then START and STOP can be read as ordinary characters.
 * */
bool port::getIXON () { return port::inFlags.ixon; }
int port::setIXON (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (IXON)) : (new_attr.c_iflag & (IXON));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.ixon = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIXOFF (bool v)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IXOFF.
 * If this bit is set, start/stop control on input is enabled.
 * In other words, the computer sends STOP and START characters as necessary
 * to prevent input from coming in faster than programs are reading it.
 * The idea is that the actual terminal hardware that is generating the input
 * data responds to a STOP character by suspending transmission,
 * and to a START character by resuming transmission.
 * */
bool port::getIXOFF () { return port::inFlags.ixoff; }
int port::setIXOFF (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (IXOFF)) : (new_attr.c_iflag & (IXOFF));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.ixoff = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIXANY (bool v)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IXANY.
 * If this bit is set, any input character restarts output
 * when output has been suspended with the STOP character.
 * Otherwise, only the START character restarts output.
 * */
bool port::getIXANY () { return port::inFlags.ixany; }
int port::setIXANY (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (IXANY)) : (new_attr.c_iflag & (IXANY));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.ixany = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}
bool iutf8;         // IUTF8    =
/**
 * !
 * \brief function int port::setIUTF8 (bool v)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IUTF8.
 * (since Linux 2.6.4) (not in POSIX) Input is UTF8.
 * This allows character-erase to be correctly performed in cooked mode.
 * */
bool port::getIUTF8 () { return port::inFlags.iutf8; }
int port::setIUTF8 (bool v) {
	new_attr.c_iflag = (v) ? (new_attr.c_iflag | (IUTF8)) : (new_attr.c_iflag & (IUTF8));
	                       //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.iutf8 = (v) ? true : false; }
	return (r < 0) ? -1 : 0;
}

serial_error* port::getError()       { return port::error; }

#endif /* SERIAL_ROUTINES_H_ */
