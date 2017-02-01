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
    int applyNewSetup ();
    int restoreSetup ();

    serial_error* getError ();

    // c_iflag flag constants for [ INPUT ] -> SET -> GET
    int setIGNBRK (bool val);    bool getIGNBRK ();
    int setBRKINT (bool val);    bool getBRKINT ();
    int setIGNPAR (bool val);    bool getIGNPAR ();
    int setPARMRK (bool val);    bool getPARMRK ();
    int setINPCK  (bool val);    bool getINPCK  ();
    int setISTRIP (bool val);    bool getISTRIP ();
    int setINLCR  (bool val);    bool getINLCR  ();
    int setIGNCR  (bool val);    bool getIGNCR  ();
    int setICRNL  (bool val);    bool getICRNL  ();
    int setIXON   (bool val);    bool getIXON   ();
    int setIXOFF  (bool val);    bool getIXOFF  ();
    int setIXANY  (bool val);    bool getIXANY  ();
    int setIUTF8  (bool val);    bool getIUTF8  ();
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

    // c_oflag flag constants for [ OUTPUT ] -> SET -> GET
    int setOPOST  (bool val);    bool getOPOST  ();
    int setONLCR  (bool val);    bool getONLCR  ();
    int setOCRNL  (bool val);    bool getOCRNL  ();
    int setONOCR  (bool val);    bool getONOCR  ();
    int setONLRET (bool val);    bool getONLRET ();
    int setOFILL  (bool val);    bool getOFILL  ();
    int setNLDLY  (std::string inStr);    std::string getNLDLY  ();
    int setCRDLY  (std::string inStr);    std::string getCRDLY  ();
    int setTABDLY (std::string inStr);    std::string getTABDLY ();
    int setVTDLY  (std::string inStr);    std::string getVTDLY  ();
    int setFFDLY  (std::string inStr);    std::string getFFDLY  ();
    // c_oflag flag constants for [ OUTPUT ]
    class outFlags {
    public:
        bool opost;         // OPOST    = Enable implementation-defined output processing
        bool onlcr;         // ONLCR    = (XSI) Map NL to CR-NL on output
        bool ocrnl;         // OCRNL    = Map CR to NL on output
        bool onocr;         // ONOCR    = Don't output CR at column 0
        bool onlret;        // ONLRET   = Don't output CR
        bool ofill;         // OFILL    = Send fill characters for a delay, rather than using a timed delay
        std::string nldly;  // NLDLY   = Newline delay mask. Values are NL0 and NL1. [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
        std::string crdly;  // CRDLY   = Carriage return delay mask. Values are CR0, CR1, CR2, or CR3. [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
        std::string tabdly; // TABDLY  = Horizontal tab delay mask. Values are TAB0, TAB1, TAB2, TAB3 (or XTABS). A value of TAB3, that is, XTABS, expands tabs to spaces (with tab stops every eight columns). [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
        std::string vtdly;  // VTDLY   = Vertical tab delay mask. Values are VT0 or VT1
        std::string ffdly;  // FFDLY   = Form feed delay mask.  Values are FF0 or FF1. [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
    }outFlags;
    // c_cflag flag constants for [ CONTROL ] -> SET -> GET
    int setCSIZE  (std::string inStr);    std::string getCSIZE  ();
    int setCSTOPB (bool val);    bool getCSTOPB ();
    int setCREAD  (bool val);    bool getCREAD  ();
    int setPARENB (bool val);    bool getPARENB ();
    int setPARODD (bool val);    bool getPARODD ();
    int setHUPCL  (bool val);    bool getHUPCL  ();
    int setCLOCAL (bool val);    bool getCLOCAL ();
    // c_cflag flag constants for [ CONTROL ]
    class controlFlags {
    public:
    	std::string csize;  // CSIZE    = Character size mask. Values are CS5, CS6, CS7, or CS8.
    	bool cstopb;        // CSTOPB   = Set two stop bits, rather than one
    	bool cread;         // CREAD    = Enable receiver
    	bool parenb;        // PARENB   = Enable parity generation on output and parity checking for input
    	bool parodd;        // PARODD   = If set, then parity for input and output is ODD; otherwise EVEN parity is used
    	bool hupcl;         // HUPCL    = (hang up) Lower modem control lines after last process closes the device
    	bool clocal;        // CLOCAL   = Ignore modem control lines
    } controlFlags;
    // c_lflag flag constants for [ LOCAL MODES ] -> SET -> GET
    int setISIG   (bool val);    bool getISIG   ();
    int setICANON (bool val);    bool getICANON ();
    int setECHO   (bool val);    bool getECHO   ();
    int setECHOE  (bool val);    bool getECHOE  ();
    int setECHOK  (bool val);    bool getECHOK  ();
    int setECHONL (bool val);    bool getECHONL ();
    int setNOFLSH (bool val);    bool getNOFLSH ();
    int setTOSTOP (bool val);    bool getTOSTOP ();
    int setIEXTEN (bool val);    bool getIEXTEN ();
    // c_lflag flag constants for [ LOCAL MODES ]
    class localFlags {
    public:
    	bool isig;          // ISIG     = When any of the characters INTR, QUIT, SUSP, or DSUSP are received, generate the corresponding signal
    	bool icanon;        // ICANON   = Enable canonical mode
    	bool echo;          // ECHO     = Echo input characters
    	bool echoe;         // ECHOE    = If ICANON is also set, the ERASE character erases the preceding input character, and WERASE erases the preceding word
    	bool echok;         // ECHOK    = If ICANON is also set, the KILL character erases the current line
    	bool echonl;        // ECHONL   = If ICANON is also set, echo the NL character even if ECHO is not set
    	bool noflsh;        // NOFLSH   = Disable flushing the input and output queues when generating signals for the INT, QUIT, and SUSP characters
    	bool tostop;        // TOSTOP   = Send the SIGTTOU signal to the process group of a background process which tries to write to its controlling terminal
    	bool iexten;        // IEXTEN   = Enable implementation-defined input processing. This flag, as well as ICANON must be enabled for the special characters EOL2, LNEXT, REPRINT, WERASE to be interpreted, and for the IUCLC flag to be Actionive
    } localFlags;
    // c_cc array that defines [ SPECIAL CHARACTERS ] -> SET -> GET
    int setVEOF   (bool val);    bool getVEOF   ();
    int setVEOL   (bool val);    bool getVEOL   ();
    int setVERASE (bool val);    bool getVERASE ();
    int setVINTR  (bool val);    bool getVINTR  ();
    int setVKILL  (bool val);    bool getVKILL  ();
    int setVMIN   (bool val);    bool getVMIN   ();
    int setVQUIT  (bool val);    bool getVQUIT  ();
    int setVSTART (bool val);    bool getVSTART ();
    int setVSTOP  (bool val);    bool getVSTOP  ();
    int setVSUSP  (bool val);    bool getVSUSP  ();
    int setVTIME  (unsigned int val);    unsigned int getVTIME ();
    // c_cc array that defines [ SPECIAL CHARACTERS ]
    class specialCharFlags {
    public:
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
    } specialCharFlags;

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

    //bool olcuc;    // OLCUC    = (not in POSIX) Map lowercase characters to uppercase on output
    //bool ofdel;    // OFDEL    = (Not implemented on Linux.) Fill character is ASCII DEL (0177). If unset, fill character is ASCII NUL ('\0')
    //std::string bsdly;  // BSDLY   = (Has never been implemented.) Backspace delay mask. Values are BS0 or BS1. [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
    //bool cbaud;    // CBAUD    = (not in POSIX) Baud speed mask (4+1 bits).  [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool cbaudex;  // CBAUDEX  = (not in POSIX) Extra baud speed mask (1 bit), included in CBAUD. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool loblk;    // LOBLK    = (not in POSIX) (Not implemented on Linux.) Block output from a noncurrent shell layer. For use by shl (shell layers).
    //bool cibaud;   // CIBAUD   = (not in POSIX) (Not implemented on Linux.) Mask for input speeds. The values for the CIBAUD bits are the same as the values for the CBAUD bits, shifted left IBSHIFT bits. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool cmspar;   // CMSPAR   = (not in POSIX) Use "stick" (mark/space) parity (supported on certain serial devices): if PARODD is set, the parity bit is always 1; if PARODD is not set, then the parity bit is always 0. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool crtscts;  // CRTSCTS  = (not in POSIX) Enable RTS/CTS (hardware) flow control. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool xcase;    // XCASE    = (not in POSIX; not supported under Linux) If ICANON is also set, terminal is uppercase only. Input is converted to lowercase, except for characters preceded by \. On output, uppercase characters are preceded by \ and lowercase characters are converted to uppercase. [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
    //bool echoctl;  // ECHOCTL  = (not in POSIX) If ECHO is also set, terminal special characters other than TAB, NL, START, and STOP are echoed as ^X, where X is the character with ASCII code 0x40 greater than the special character. For example, character 0x08 (BS) is echoed as ^H. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool echoprt;  // ECHOPRT  = (not in POSIX) If ICANON and ECHO are also set, characters are printed as they are being erased. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool echoke;   // ECHOKE   = (not in POSIX) If ICANON is also set, KILL is echoed by erasing each character on the line, as specified by ECHOE and ECHOPRT. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool defecho;  // DEFECHO  = (not in POSIX) (Not implemented on Linux.) Echo only when a process is reading
    //bool flusho;   // FLUSHO   = (not in POSIX; not supported under Linux) Output is being flushed. This flag is toggled by typing the DISCARD character. [requires _BSD_SOURCE or _SVID_SOURCE]
    //bool pendin;   // PENDIN   = (not in POSIX; not supported under Linux) All characters in the input queue are reprinted when the next character is read
    //bool valdiscard; // VDISCARD = (not in POSIX; not supported under Linux; 017, SI, Ctrl-O) Toggle: start/stop discarding pending output. Recognized when IEXTEN is set, and then not passed as input
    //bool valdsusp;   // VDSUSP   = (not in POSIX; not supported under Linux; 031, EM, Ctrl-Y) Delayed suspend character (DSUSP): send SIGTSTP signal when the character is read by the user program. Recognized when IEXTEN and ISIG are set, and the system supports job control, and then not passed as input
    //bool valeol2;    // VEOL2    = (not in POSIX; 0, NUL) Yet another end-of-line character (EOL2). Recognized when ICANON is set
    //bool vallnext;   // VLNEXT   = (not in POSIX; 026, SYN, Ctrl-V) Literal next (LNEXT). Quotes the next input character, depriving it of a possible special meaning. Recognized when IEXTEN is set, and then not passed as input
    //bool valreprint; // VREPRINT = (not in POSIX; 022, DC2, Ctrl-R) Reprint unread characters (REPRINT). Recognized when ICANON and IEXTEN are set, and then not passed as input
    //bool valstatus;  // VSTATUS  = (not in POSIX; not supported under Linux; status request: 024, DC4, Ctrl-T).  Status character (STATUS). Display status information at terminal, including state of foreground process and amount of CPU time it has consumed. Also sends a SIGINFO signal (not supported on Linux) to the foreground process group
    //bool valstch;    // VSWTCH   = (not in POSIX; not supported under Linux; 0, NUL) Switch character (SWTCH). Used in System V to switch shells in shell layers, a predecessor to shell job control
    //bool valwerase;  // VWERASE  = (not in POSIX; 027, ETB, Ctrl-W) Word erase (WERASE). Recognized when ICANON and IEXTEN are set, and then not passed as input
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
            port::baud = 0;            port::str_baud = "B0";
            port::error[1] = err_baud_rate;
        }
    } else {
        port::error[1] = err_baud_rate_not_set;
        port::baud = 0;        port::str_baud = "B0";
    }
    if (port::error[1].what().compare(NO_ERROR) == 0) {
        port::baud = iBaud;
        port::str_baud = "B" + to_string(iBaud);
        if (tcgetattr(port::fstream, &new_attr) != 0) {
        	// termios [READ baud rate] error occured
        	// TODO !!! debatable if needed here in the end !!! cumulation in saveSetup ()
            port::baud = 0;            port::str_baud = "B0";
        	port::error[5] = err_can_t_read_termios_attribute;
        } else if (cfsetispeed(&new_attr, baud) != 0) { // termios [SET INPUT baud] error occured
            port::baud = 0;            port::str_baud = "B0";
        	port::error[5] = err_can_t_set_termios_baud;
        } else if (cfsetospeed(&new_attr, baud) != 0) { // termios [SET OUTPUT baud] error occured
            port::baud = 0;            port::str_baud = "B0";
        	port::error[5] = err_can_t_set_termios_baud;
        } else if (tcsetattr(1, TCSANOW, &new_attr) != 0){
        	// termios [PASS structure] error occured
        	// TODO !!! debatable if needed here in the end !!! cumulation in applyNewSetup ()
            port::baud = 0;            port::str_baud = "B0";
        	port::error[5] = err_can_t_pass_termios_struct;
        } else { // termios [no error]
        	port::error[5] = ok;
        }
    } else {
        port::baud = 0;        port::str_baud = "B0";
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
		port::error[5] = err_can_t_read_termios_attribute;
		result = -1;
	} else {
		new_attr = orig_attr;
		port::error[5] = ok;
		result = 0;
	}
	return result;
}
int port::applyNewSetup () {
	// TODO
	return 0;
}
int port::restoreSetup () {
	int result = tcsetattr (port::fstream, TCSANOW, &orig_attr);
	(result < 0) ? (result = -1) : (result = 0);
	return result;
}
/**
 * !
 * \brief function int port::setIGNBRK (bool val)
 * \param v as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IGNBRK.
 * Ignore BREAK.
 * A break condition is defined in the context of asynchronous serial
 * data transmission as a series of zero-value bits longer than a single byte.
 * */
bool port::getIGNBRK () { return port::inFlags.ignbrk; }
int port::setIGNBRK (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (IGNBRK)) : (new_attr.c_iflag & (IGNBRK));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.ignbrk = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setBRKINT (bool val)
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
int port::setBRKINT (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (BRKINT)) : (new_attr.c_iflag & (BRKINT));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.brkint = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIGNPAR (bool val)
 * \param v as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IGNPAR.
 * If this bit is set, any byte with a framing or parity error is ignored.
 * This is only useful if INPCK is also set.
 * */
bool port::getIGNPAR () { return port::inFlags.ignpar; }
int port::setIGNPAR (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (IGNPAR)) : (new_attr.c_iflag & (IGNPAR));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.ignpar = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setPARMRK (bool val)
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
int port::setPARMRK (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (PARMRK)) : (new_attr.c_iflag & (PARMRK));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.parmrk = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setINPCK (bool val)
 * \param v as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.INPCK.
 * If this bit is set, input parity checking is enabled.
 * If it is not set, no checking at all is done for parity errors on input and
 * the characters are simply passed through to the application.
 * */
bool port::getINPCK () { return port::inFlags.inpck; }
int port::setINPCK (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (INPCK)) : (new_attr.c_iflag & (INPCK));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.inpck = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setISTRIP (bool val)
 * \param v as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ISTRIP.
 * If this bit is set, valid input bytes are stripped to seven bits.
 * Otherwise, all eight bits are available for programs to read.
 * */
bool port::getISTRIP () { return port::inFlags.istrip; }
int port::setISTRIP (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (ISTRIP)) : (new_attr.c_iflag & (ISTRIP));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.istrip = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setINLCR (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.INLCR.
 * If this bit is set, newline characters ('\n') received as input are passed
 * to the application as carriage return characters ('\r').
 * */
bool port::getINLCR () { return port::inFlags.inlcr; }
int port::setINLCR (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (INLCR)) : (new_attr.c_iflag & (INLCR));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.inlcr = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIGNCR (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IGNCR.
 * If this bit is set, carriage return characters ('\r') are discarded on input.
 * Discarding carriage return may be useful on terminals that send both carriage
 * return and linefeed when you type the RET key.
 * */
bool port::getIGNCR () { return port::inFlags.igncr; }
int port::setIGNCR (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (IGNCR)) : (new_attr.c_iflag & (IGNCR));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.igncr = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setICRNL (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ICRNL.
 * If this bit is set and IGNCR is not set, carriage return characters ('\r')
 * received as input are passed to the application as newline characters ('\n').
 * */
bool port::getICRNL () { return port::inFlags.icrnl; }
int port::setICRNL (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (ICRNL)) : (new_attr.c_iflag & (ICRNL));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.icrnl = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIXON (bool val)
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
int port::setIXON (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (IXON)) : (new_attr.c_iflag & (IXON));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.ixon = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIXOFF (bool val)
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
int port::setIXOFF (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (IXOFF)) : (new_attr.c_iflag & (IXOFF));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.ixoff = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIXANY (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IXANY.
 * If this bit is set, any input character restarts output
 * when output has been suspended with the STOP character.
 * Otherwise, only the START character restarts output.
 * */
bool port::getIXANY () { return port::inFlags.ixany; }
int port::setIXANY (bool val) {
  	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (IXANY)) : (new_attr.c_iflag & (IXANY));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.ixany = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIUTF8 (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IUTF8.
 * (since Linux 2.6.4) (not in POSIX) Input is UTF8.
 * This allows character-erase to be correctly performed in cooked mode.
 * */
bool port::getIUTF8 () { return port::inFlags.iutf8; }
int port::setIUTF8 (bool val) {
	new_attr.c_iflag = (val) ? (new_attr.c_iflag | (IUTF8)) : (new_attr.c_iflag & (IUTF8));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::inFlags.iutf8 = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setOPOST (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.OPOST.
 * If this bit is set, output data is processed in some unspecified way
 * so that it is displayed appropriately on the terminal device.
 * This typically includes mapping newline characters ('\n') onto
 * carriage return and linefeed pairs.
 * If this bit isn't set, the characters are transmitted as-is.
 * */
bool port::getOPOST () { return port::outFlags.opost; }
int port::setOPOST (bool val) {
	new_attr.c_oflag = (val) ? (new_attr.c_oflag | (OPOST)) : (new_attr.c_oflag & (OPOST));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::outFlags.opost = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setONLCR (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ONLCR.
 * If this bit is set, convert the newline character on output into
 * a pair of characters, carriage return followed by linefeed.
 * */
bool port::getONLCR () { return port::outFlags.onlcr; }
int port::setONLCR (bool val) {
	new_attr.c_oflag = (val) ? (new_attr.c_oflag | (ONLCR)) : (new_attr.c_oflag & (ONLCR));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::outFlags.onlcr = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setOCRNL (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.OCRNL.
 * If this bit is set, convert the carriage return to linefeed.
 * */
bool port::getOCRNL () { return port::outFlags.ocrnl; }
int port::setOCRNL (bool val) {
	new_attr.c_oflag = (val) ? (new_attr.c_oflag | (OCRNL)) : (new_attr.c_oflag & (OCRNL));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::outFlags.ocrnl = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setONOCR (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ONOCR.
 * If this bit is set, don't output carriage return at column 0.
 * */
bool port::getONOCR () { return port::outFlags.onocr; }
int port::setONOCR (bool val) {
	new_attr.c_oflag = (val) ? (new_attr.c_oflag | (ONOCR)) : (new_attr.c_oflag & (ONOCR));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::outFlags.onocr = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setONLRET (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ONLRET.
 * If this bit is set, don't output carriage return at all.
 * */
bool port::getONLRET () { return port::outFlags.onlret; }
int port::setONLRET (bool val) {
	new_attr.c_oflag = (val) ? (new_attr.c_oflag | (ONLRET)) : (new_attr.c_oflag & (ONLRET));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::outFlags.onlret = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setOFILL (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.OFILL.
 * If this bit is set, send fill characters for a delay, rather than using a timed delay.
 * */
bool port::getOFILL () { return port::outFlags.ofill; }
int port::setOFILL (bool val) {
	new_attr.c_oflag = (val) ? (new_attr.c_oflag | (OFILL)) : (new_attr.c_oflag & (OFILL));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::outFlags.ofill = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setNLDLY (std::string inStr)
 * \param std::string values are NL0 and NL1
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.NLDLY.
 * Newline delay mask. [requires _BSD_SOURCE or _SVID_SOURCE or _XOPEN_SOURCE]
 * NL0 = No delay.
 * NL1 = 0.10 seconds delay.
 * If ONLRET is set, then carriage-return delays are used instead of newline delays.
 * If OFILL  is set, then two fill characters are transmitted.
 * */
std::string port::getNLDLY () { return port::outFlags.nldly; }
int port::setNLDLY (std::string inStr) {
	int result;
	std::string lStr = ""; port::outFlags.nldly = lStr;
	if (inStr.compare("NL0") == 0 || inStr.compare("nl0") == 0 ||
		inStr.compare("Nl0") == 0 || inStr.compare("nL0") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | NL0;
		result = 0; lStr = "NL0";
	} else if (inStr.compare("NL1") == 0 || inStr.compare("nl1") == 0 ||
			   inStr.compare("Nl1") == 0 || inStr.compare("nL1") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | NL1;
		result = 0; lStr = "NL1";
	} else {
		result = -1;
	}
	result = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (result == -1) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::outFlags.nldly = lStr; }
	return result;
}
/**
 * !
 * \brief function int port::setCRDLY (std::string inStr)
 * \param std::string inStr values are CR0, CR1, CR2 and CR3
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.CRDLY.
 * Delay associated with carriage-return character.
 * CR0 = No delay.
 * CR1 = Delay dependent on column position, or if OFILL is set then two fill characters are transmitted.
 * CR2 = 0.10 seconds delay, or if OFILL is set then four fill characters are transmitted.
 * CR3 = 0.15 seconds delay.
 * */
std::string port::getCRDLY () { return port::outFlags.crdly; }
int port::setCRDLY (std::string inStr) {
	int result;
	std::string lStr = ""; port::outFlags.crdly = lStr;
	if (inStr.compare("CR0") == 0 || inStr.compare("cr0") == 0 ||
		inStr.compare("Cr0") == 0 || inStr.compare("cR0") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | CR0;
		result = 0; lStr = "CR0";
	} else if (inStr.compare("CR1") == 0 || inStr.compare("cr1") == 0 ||
			   inStr.compare("Cr1") == 0 || inStr.compare("cR1") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | CR1;
		result = 0; lStr = "CR1";
	} else if (inStr.compare("CR2") == 0 || inStr.compare("cr2") == 0 ||
			   inStr.compare("Cr2") == 0 || inStr.compare("cR2") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | CR2;
		result = 0; lStr = "CR2";
	} else if (inStr.compare("CR3") == 0 || inStr.compare("cr3") == 0 ||
			   inStr.compare("Cr3") == 0 || inStr.compare("cR3") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | CR3;
		result = 0; lStr = "CR3";
	} else {
		result = -1;
	}
	result = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (result == -1) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::outFlags.crdly = lStr; }
	return result;
}
/**
 * !
 * \brief function int port::setTABDLY (std::string inStr)
 * \param std::string inStr values are TAB0, TAB1, TAB2 and TAB3
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.TABDLY.
 * Delay associated with tab character.
 * TAB0 = No horizontal tab processing.
 * TAB1 = Delay dependent on column position, or if OFILL is set then two fill characters are transmitted.
 * TAB2 = 0.10 seconds delay, or if OFILL is set then two fill characters are transmitted.
 * TAB3 = Tabs are expanded into spaces.
 * */
std::string port::getTABDLY () { return port::outFlags.tabdly; }
int port::setTABDLY (std::string inStr) {
	int result;
	std::string lStr = ""; port::outFlags.tabdly = lStr;
	if (inStr.compare("TAB0") == 0 || inStr.compare("Tab0") == 0 || inStr.compare("tab0") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | TAB0;
		result = 0; lStr = "TAB0";
	} else if (inStr.compare("TAB1") == 0 || inStr.compare("Tab1") == 0 || inStr.compare("tab1") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | TAB1;
		result = 0; lStr = "TAB1";
	} else if (inStr.compare("TAB2") == 0 || inStr.compare("Tab2") == 0 || inStr.compare("tab2") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | TAB2;
		result = 0; lStr = "TAB2";
	} else if (inStr.compare("TAB3") == 0 || inStr.compare("Tab3") == 0 || inStr.compare("tab3") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | TAB3;
		result = 0; lStr = "TAB3";
	} else {
		result = -1;
	}
	result = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (result == -1) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::outFlags.tabdly = lStr; }
	return result;
}
/**
 * !
 * \brief function int port::setVTDLY (std::string inStr)
 * \param std::string inStr values are VT0, VT1
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VTDLY.
 * Delay associated with vertical-tab processing.
 * VT0 = No delay.
 * VT1 = 2 seconds delay.
 * */
std::string port::getVTDLY () { return port::outFlags.vtdly; }
int port::setVTDLY (std::string inStr) {
	int result;
	std::string lStr = ""; port::outFlags.vtdly = lStr;
	if (inStr.compare("VT0") == 0 || inStr.compare("vt0") == 0 ||
		inStr.compare("Vt0") == 0 || inStr.compare("vT0") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | VT0;
		result = 0; lStr = "VT0";
	} else if (inStr.compare("VT1") == 0 || inStr.compare("vt1") == 0 ||
			   inStr.compare("Vt1") == 0 || inStr.compare("vT1") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | VT1;
		result = 0; lStr = "VT1";
	} else {
		result = -1;
	}
	result = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (result == -1) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::outFlags.vtdly = lStr; }
	return result;
}
/**
 * !
 * \brief function int port::setFFDLY (std::string inStr)
 * \param std::string inStr values are FF0, FF1
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.FFDLY.
 * Delay associated with form-feed processing.
 * FF0 = No delay.
 * FF1 = 2 seconds delay.
 * */
std::string port::getFFDLY () { return port::outFlags.ffdly; }
int port::setFFDLY (std::string inStr) {
	int result;
	std::string lStr = ""; port::outFlags.ffdly = lStr;
	if (inStr.compare("FF0") == 0 || inStr.compare("ff0") == 0 ||
		inStr.compare("Ff0") == 0 || inStr.compare("fF0") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | FF0;
		result = 0; lStr = "FF0";
	} else if (inStr.compare("FF1") == 0 || inStr.compare("ff1") == 0 ||
			   inStr.compare("Ff1") == 0 || inStr.compare("fF1") == 0) {
		new_attr.c_oflag = new_attr.c_oflag | FF1;
		result = 0; lStr = "FF1";
	} else {
		result = -1;
	}
	result = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (result == -1) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::outFlags.ffdly = lStr; }
	return result;
}
/**
 * !
 * \brief function int port::setCSIZE (std::string inStr)
 * \param std::string inStr values are CS5, CS6, CS7, or CS8.
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.CSIZE.
 * Is a collection of bits indicating the number of bits per byte
 * (not counting the parity bit, if any).
 * These bits specify byte size for both transmission and reception.
 * Possible settings of CSIZE are given with the following symbols:
 * CS5 - 5 bits per byte
 * CS6 - 6 bits per byte
 * CS7 - 7 bits per byte
 * CS8 - 8 bits per byte
 * Using z/OS UNIX pseudoterminal support, all values are accepted,
 * but CSIZE is changed to CS8.
 * Using z/OS UNIX Outboard Communications Server (OCS) support,
 * the specified value is used.
 * */
std::string port::getCSIZE () { return port::controlFlags.csize; }
int port::setCSIZE (std::string inStr) {
	int result;
	std::string lStr = ""; port::controlFlags.csize = lStr;
	if (inStr.compare("CS5") == 0 || inStr.compare("cs5") == 0 ||
		inStr.compare("Cs5") == 0 || inStr.compare("sS5") == 0) {
		new_attr.c_cflag = new_attr.c_cflag | CS5;
		result = 0; lStr = "CS5";
	} else if (inStr.compare("CS6") == 0 || inStr.compare("cs6") == 0 ||
			   inStr.compare("Cs6") == 0 || inStr.compare("sS6") == 0) {
		new_attr.c_cflag = new_attr.c_cflag | CS6;
		result = 0; lStr = "CS6";
	} else if (inStr.compare("CS7") == 0 || inStr.compare("cs7") == 0 ||
	           inStr.compare("Cs7") == 0 || inStr.compare("sS7") == 0) {
		new_attr.c_cflag = new_attr.c_cflag | CS7;
		result = 0; lStr = "CS7";
	} else if (inStr.compare("CS8") == 0 || inStr.compare("cs8") == 0 ||
	           inStr.compare("Cs8") == 0 || inStr.compare("sS8") == 0) {
		new_attr.c_cflag = new_attr.c_cflag | CS8;
		result = 0; lStr = "CS8";
	} else {
		result = -1;
	}
	result = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (result == -1) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::controlFlags.csize = lStr; }
	return result;
}
/**
 * !
 * \brief function int port::setCSTOPB (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.CSTOPB.
 * Sends two stop bits when necessary.
 * If CSTOPB is 0, only one stop bit is used.
 * Using z/OS UNIX pseudoterminal support, this bit is always 0.
 * Using z/OS UNIX OCS support, the specified value is used.
 * */
bool port::getCSTOPB () { return port::controlFlags.cstopb; }
int port::setCSTOPB (bool val) {
	new_attr.c_cflag = (val) ? (new_attr.c_cflag | (CSTOPB)) : (new_attr.c_cflag & (CSTOPB));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::controlFlags.cstopb = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setCREAD (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.CREAD.
 * Enables reception.
 * If this bit is set to 0, no input characters are received from the terminal.
 * Using z/OS UNIX pseudoterminal support, this bit is always enabled and set to 1.
 * */
bool port::getCREAD () { return port::controlFlags.cread; }
int port::setCREAD (bool val) {
	new_attr.c_cflag = (val) ? (new_attr.c_cflag | (CREAD)) : (new_attr.c_cflag & (CREAD));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::controlFlags.cread = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setPARENB (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.PARENB.
 * Enables parity generation and detection.
 * A parity bit is added to each character on output, and expected from each character on input.
 * If this bit is not set, no parity bit is added to output characters,
 * and input characters are not checked for correct parity.
 * <IBM> Under z/OS UNIX, if this bit is set to 1 in a request, it is ignored.
 * It is always set to 0.
 * <IBM> Using z/OS UNIX OCS support, the specified value is used.
 * */
bool port::getPARENB () { return port::controlFlags.parenb; }
int port::setPARENB (bool val) {
	new_attr.c_cflag = (val) ? (new_attr.c_cflag | (PARENB)) : (new_attr.c_cflag & (PARENB));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::controlFlags.parenb = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setPARODD (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.PARODD.
 * Indicates odd parity (when parity is enabled).
 * If PARODD is 0, even parity is used (when parity is enabled).
 * <IBM> Under z/OS UNIX, if this bit is set to 1 in a request, it is ignored.
 * It is always set to 0.
 * <IBM> Using z/OS UNIX OCS support, the specified value is used.
 * */
bool port::getPARODD () { return port::controlFlags.parodd; }
int port::setPARODD (bool val) {
	new_attr.c_cflag = (val) ? (new_attr.c_cflag | (PARODD)) : (new_attr.c_cflag & (PARODD));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::controlFlags.parodd = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setHUPCL (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.HUPCL.
 * Lowers the modem control lines for a port when
 * the last process that has the port open closes
 * the port (or the process ends).
 * In other words, this tells the system to hang up
 * when all relevant processes have finished using the port.
 * For pseudoterminals HUPCL controls what happens when
 * the slave pseudoterminals is closed. If HUPCL is set when
 * the last file descriptor for the slave pseudoterminal is
 * closed, then the slave pseudoterminal cannot be re-opened.
 * The master terminal has to be closed and re-opened before
 * the pair can be used again.
 * */
bool port::getHUPCL () { return port::controlFlags.hupcl; }
int port::setHUPCL (bool val) {
	new_attr.c_cflag = (val) ? (new_attr.c_cflag | (HUPCL)) : (new_attr.c_cflag & (HUPCL));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::controlFlags.hupcl = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setCLOCAL (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.CLOCAL.
 * Ignores modem status lines.
 * A call to open() returns immediately without waiting
 * for a modem connection to complete.
 * If this bit is set to 0, modem status lines are monitored
 * and open() waits for the modem connection.
 * */
bool port::getCLOCAL () { return port::controlFlags.clocal; }
int port::setCLOCAL (bool val) {
	new_attr.c_cflag = (val) ? (new_attr.c_cflag | (CLOCAL)) : (new_attr.c_cflag & (CLOCAL));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::controlFlags.clocal = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setISIG (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ISIG.
 * If ISIG is set to 1, signals are generated if special control characters
 * are entered so:
 *   SIGINT is generated if INTR is entered;
 *   SIGQUIT is generated if QUIT is entered;
 *   SIGTSTP is generated if SUSP is entered and job control is supported.
 * The special control characters are controlled by the c_cc member.
 * If ISIG is 0, the system does not generate signals when these special
 * control characters are entered.
 * */
bool port::getISIG () { return port::localFlags.isig; }
int port::setISIG (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (ISIG)) : (new_attr.c_lflag & (ISIG));
	                         //                0 |  1 = 1                    1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::localFlags.isig = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setICANON (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ICANON.
 * Enables canonical input processing, also called line mode.
 * Input is not delivered to the application until an entire line has been input.
 * The end of a line is indicated by:
 *   - a newline,
 *   - End Of File (EOF),
 *   - EOL character (where the character used as the EOL character
 *     is directed by the c_cc member of the termios structure).
 * Canonical input processing uses the ERASE character to erase a single input
 * character, and the KILL character to erase an entire line.
 * The MAX_CANON value specifies the maximum number of bytes in an input line in
 * canonical mode.
 * If ICANON is 0, read requests take input directly from the input queue so:
 *    the system does not wait for the user to enter a complete line. This is
 *    called noncanonical mode. ERASE and KILL characters are not handled by
 *    the system but passed directly to the application.
 * See also the descriptions of MIN and TIME in the c_cc member.
 * */
bool port::getICANON () { return port::localFlags.icanon; }
int port::setICANON (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (ICANON)) : (new_attr.c_lflag & (ICANON));
	                         //                0 |  1 = 1                    1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::localFlags.icanon = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setECHO (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ECHO.
 * Echoes input characters back to the terminal.
 * If this is bit is 0, input characters are not echoed.
 * */
bool port::getECHO () { return port::localFlags.echo; }
int port::setECHO (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (ECHO)) : (new_attr.c_lflag & (ECHO));
	                         //                0 |  1 = 1                    1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::localFlags.echo = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setECHOE (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ECHOE.
 * Echoes the ERASE character as an error-correcting backspace.
 * When the user inputs an ERASE character, the terminal erases
 * the last character in the current line from the display (if possible).
 * The character used as the ERASE character is dictated by the c_cc member
 * of the termios structure.
 * ECHOE has an effect only if the ICANON bit is 1.
 * */
bool port::getECHOE () { return port::localFlags.echoe; }
int port::setECHOE (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (ECHOE)) : (new_attr.c_lflag & (ECHOE));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::localFlags.echoe = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setECHOK (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ECHOK.
 * Either causes the terminal to erase the line from the display,
 * or echoes the KILL character followed by an \n character.
 * ECHOK has an effect only if the ICANON bit is set to 1.
 * */
bool port::getECHOK () { return port::localFlags.echok; }
int port::setECHOK (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (ECHOK)) : (new_attr.c_lflag & (ECHOK));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::localFlags.echok = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setECHOK (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.ECHOK.
 * Echoes the newline (line-feed) character ‘\n’ even if the ECHO bit is off.
 * ECHONL has an effect only if the ICANON bit is set to 1.
 * */
bool port::getECHONL () { return port::localFlags.echonl; }
int port::setECHONL (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (ECHONL)) : (new_attr.c_lflag & (ECHONL));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::localFlags.echonl = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setNOFLSH (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.NOFLSH.
 * If this bit is set to 1, the system does not flush the input and output queues
 * if a signal is generated by one of the special characters described in ISIG above.
 * If NOFLSH is set to 0, the queues are flushed if one of the special characters is found.
 * */
bool port::getNOFLSH () { return port::localFlags.noflsh; }
int port::setNOFLSH (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (NOFLSH)) : (new_attr.c_lflag & (NOFLSH));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::localFlags.noflsh = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setTOSTOP (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.TOSTOP.
 * If this bit is set to 1, a SIGTTOU signal is sent to the process group of a process
 * that tries to write to a terminal when it is not in the terminal's foreground process
 * group. However, if the process that tries to write to the terminal is blocking or
 * ignoring SIGTTOU signals, the system does not raise the SIGTTOU signal.
 * If TOSTOP is 0, output from background processes is output to the current output
 * stream, and no signal is raised.
 * */
bool port::getTOSTOP () { return port::localFlags.tostop; }
int port::setTOSTOP (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (TOSTOP)) : (new_attr.c_lflag & (TOSTOP));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::localFlags.tostop = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setIEXTEN (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.IEXTEN.
 * Enables extended implementation-defined functions.
 * These are not defined, and IEXTEN is always set to 0.
 * If the ERASE, KILL or EOF character is preceded by a backslash character,
 * the special character is placed in the input queue without doing the
 * "special character" processing and the backslash is discarded.
 * */
bool port::getIEXTEN () { return port::localFlags.iexten; }
int port::setIEXTEN (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (IEXTEN)) : (new_attr.c_lflag & (IEXTEN));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::localFlags.iexten = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setVEOF (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VEOF.
 * Gives the End Of File character EOF. 'CTRL-D'
 * It is recognized only in canonical (line) mode.
 * When this is found in input, all bytes waiting to be read are immediately passed
 * to the application without waiting for the end of the line.
 * The EOF character itself is discarded.
 * If EOF occurs at the beginning of a line, the read function that tries to read
 * that line receives an End Of File (EOF) indication.
 * Note that EOF results in End Of File only if it is at the beginning of a line !!!
 * If it is preceded by one or more characters, it indicates only End Of Line (EOL).
 * */
bool port::getVEOF () { return port::specialCharFlags.veof; }
int port::setVEOF (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (VEOF)) : (new_attr.c_lflag & (VEOF));
	                         //                0 |  1 = 1                    1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::specialCharFlags.veof = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setVEOL (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VEOL.
 * Indexes the EOL special character (Ctrl-@ or ASCII NULL), which is recognized on input
 * if the ICANON flag is set.
 * EOL is an additional line delimiter, like NL, and is not normally used.
 * */
bool port::getVEOL () { return port::specialCharFlags.veol; }
int port::setVEOL (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (VEOL)) : (new_attr.c_lflag & (VEOL));
	                         //                0 |  1 = 1                    1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::specialCharFlags.veol = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setVERASE (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VERASE.
 * Indexes the ERASE special character (Backspace), which is recognized on input
 * if the ICANON flag is set.
 * The ERASE character does not erase beyond the beginning of the line as delimited
 * by a NL, EOL, EOF, or EOL2 character.
 * If the ICANON flag is set, the ERASE character is discarded when processed.
 * */
bool port::getVERASE () { return port::specialCharFlags.verase; }
int port::setVERASE (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (VERASE)) : (new_attr.c_lflag & (VERASE));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::specialCharFlags.verase = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setVINTR (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VINTR.
 * Indexes the INTR special character (Ctrl-c), which is recognized on input
 * if the ISIG flag is set.
 * The INTR character generates a SIGINT signal, which is sent to all processes
 * in the foreground process group for which the terminal is the controlling
 * terminal.
 * If the ISIG flag is set, the INTR character is discarded when processed.
 * */
bool port::getVINTR () { return port::specialCharFlags.vintr; }
int port::setVINTR (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (VINTR)) : (new_attr.c_lflag & (VINTR));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::specialCharFlags.vintr = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setVKILL (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VKILL.
 * Indexes the KILL special character (Ctrl-u), which is recognized on input
 * if the ICANON flag is set.
 * The KILL character deletes the entire line, as delimited by a NL, EOL, EOF,
 * or EOL2 character.
 * If the ICANON flag is set, the KILL character is discarded when processed.
 * */
bool port::getVKILL () { return port::specialCharFlags.vkill; }
int port::setVKILL (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (VKILL)) : (new_attr.c_lflag & (VKILL));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::specialCharFlags.vintr = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setVMIN (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VMIN.
 * Indexes the MIN value, which is not a special character.
 * The use of the MIN value is described in the discussion of noncanonical mode
 * input processing in:
 * "ldterm Line Discipline"
 * in:
 * General Programming Concepts: Writing and Debugging Programs.
 * */
bool port::getVMIN () { return port::specialCharFlags.vmin; }
int port::setVMIN (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (VMIN)) : (new_attr.c_lflag & (VMIN));
	                         //                0 |  1 = 1                    1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::specialCharFlags.vmin = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setVQUIT (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VQUIT.
 * Indexes the QUIT special character (Ctrl-\), which is recognized on input
 * if the ISIG flag is set.
 * The QUIT character generates a SIGQUIT signal, which is sent to all processes
 * in the foreground process group for which the terminal is the controlling
 * terminal, and writes a core image file into the current working directory.
 * If the ISIG flag is set, the QUIT character is discarded when processed.
 * */
bool port::getVQUIT () { return port::specialCharFlags.vquit; }
int port::setVQUIT (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (VQUIT)) : (new_attr.c_lflag & (VQUIT));
	                         //                0 |  1 = 1                     1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::specialCharFlags.vquit = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setVSTART (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VSTART.
 * Indexes the START special character (Ctrl-q), which is recognized:
 * on input if the IXON flag is set
 * and generated on output if the IXOFF flag is set.
 * The START character can be used to resume output that has been suspended
 * by a STOP character.
 * If the IXON flag is set, the START character is discarded when processed.
 * While output is not suspended, START characters are ignored and not read.
 * <IBM> VSTRT is an alias for VSTART.
 * */
bool port::getVSTART () { return port::specialCharFlags.vstart; }
int port::setVSTART (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (VSTART)) : (new_attr.c_lflag & (VSTART));
	                         //                0 |  1 = 1                      1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::specialCharFlags.vstart = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setVSTOP (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VSTOP.
 * Indexes the STOP special character (Ctrl-s), which is recognized:
 * on input if the IXON flag is set
 * and generated on output if the IXOFF flag is set.
 * The STOP character can be used to with terminals to prevent output
 * from disappearing before it can be read.
 * If the IXON flag is set, the STOP character is discarded when processed.
 * While output is suspended, STOP characters are ignored and not read.
 * */
bool port::getVSTOP () { return port::specialCharFlags.vstop; }
int port::setVSTOP (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (VSTOP)) : (new_attr.c_lflag & (VSTOP));
	                         //                0 |  1 = 1                    1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::specialCharFlags.vstop = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setVSUSP (bool val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VSUSP.
 * Indexes the SUSP special character (Ctrl-z), which is recognized on input
 * if the ISIG flag is set.
 * The SUSP character generates a SIGTSTP signal, which is sent to all processes
 * in the foreground process group for which the terminal is the controlling terminal.
 * If the ISIG flag is set, the SUSP character is discarded when processed.
 * */
bool port::getVSUSP () { return port::specialCharFlags.vsusp; }
int port::setVSUSP (bool val) {
	new_attr.c_lflag = (val) ? (new_attr.c_lflag | (VSUSP)) : (new_attr.c_lflag & (VSUSP));
	                         //                0 |  1 = 1                    1 &  0 = 0
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::specialCharFlags.vsusp = (val) ? true : false; }
	return (r < 0) ? -1 : 0;
}
/**
 * !
 * \brief function int port::setVTIME (unsigned int val)
 * \param value as bool
 * \returns int, 0 if OK, -1 if ERROR
 * \details
 * Action: changes termios.VTIME.
 * Indexes the TIME value, which is not a special character.
 * The use of the TIME value is described in the discussion of noncanonical mode
 * input processing in "ldterm Line Discipline" in General Programming Concepts:
 * Writing and Debugging Programs.
 * */
unsigned int port::getVTIME () { return port::specialCharFlags.vtime; }
int port::setVTIME (unsigned int val) {
	new_attr.c_lflag = (val > 0) ? (new_attr.c_lflag | (VTIME)) : 0;
	int r = tcsetattr (port::fstream, TCSANOW, &new_attr);
	if (r < 0) {
		std::cerr << __FUNCTION__<< " tcsetattr " + ERROR + NOT_SUCCEDED << std::endl;
	} else { port::specialCharFlags.vtime = (val > 0) ? val : 0; }
	return (r < 0) ? -1 : 0;
}

serial_error* port::getError()       { return port::error; }

#endif /* SERIAL_ROUTINES_H_ */
