# 8-Puzzle for the ICS-OS
	An application made by CMSC 125 students as partial requirements for the completion of CMSC 125 - Operating Systems.


## Installing ICS-OS
	1.) Download the <a href="https://github.com/srg-ics-uplb/ics-os">ICS-OS repository here</a>

	2.) Download libc6 to get rid of the sys/cdefs.h error

		$sudo apt-get install libc6-dev-i386

	WHEN RUNNING ON A 64-BIT SYSTEM

	3.) Open a terminal and go to the ics-os folder then run the following commands:

		$cd kernel
		$cp Makefile Makefile.32bit
		$cp Makefile.Ubuntu_14.04_x86_64 Makefile
		$cd ../
		$cd make clean
		$cd make

	WHEN RUNNING ON A 32-BIT SYSTEM

	3.) Open a terminal then go to the ics-os folder then run the following commands:

		$make clean
		$make

## Installing the 8-Puzzle Game:
	1.) Download and extract this repository

	2.) Copy and paste the 8puzzle folder to /ics-os/contrib/

	3.) Go the the 8puzzle folder:

		$cd ics-os/contrib/8puzzle
		$make
		$make install

	4.) Return to the ics-os folder then run:

		$sudo make install

	5.) You can now run the .exe file on the ICS-OS!

## Editing the source code:
	1.) Edit the .c file in the 8puzzle folder located in /ics-os/contrib/

	2.) Run:

		$./compile.sh

		in order to compile your code to the OS.

	If the command doesn't work, run:

		$chmod 755 compile.sh

	then run it again.

### Authors
	Miles Lawrence R. Basnillo
	Jeriel Jaro

