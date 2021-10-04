# Boot-to-Donut

Permission is granted to use this code for anything with the exception of graded assignments, unless of course specific permission is granted by a course instructor.

Porting the famous "Donut.c" code to run straight from boot without an operating system in VGA text mode.

Note: ------------
Information and original source of Donut.C can be found here: https://www.a1k0n.net/2011/07/20/donut-math.html

This project was inspired by an Operating Systems class assignment and reading through Donut.c code to better understand how it works.

Files will be uploaded upon completion removing certian portions of code (not required to run this instance) in order to maintain academic integrity. 
-----------------

Steps: 

1. Analyze Donut.C
   In Donut2.c, you can see that I've broken down Donut.C into a more readible format, analyzed how the code displays to the screenm, and have removed implicit declarations in order to make my compiler happy.

2. Build "OS" from bootloader
  In order to run the code on a computer, a bootloader must be loaded into memory, the system will be set to 32-bit protected mode, and handed off to boot2.c where I complete most of this project. Tools used for this process can be seen in the makefile. Because there is no underlying operating system, symbols must be stripped from object code to run on bare hardware. This has been tested on debian.

3. Recreate print functions
   As no operating exists, function library calls are unavailable and new funtions must be created to print in VGA text mode. VGA text mode supports 80 columns and 25 rows. Printing to the screen is accomplished by moving text and color codes to memory starting at the address 0xB8000 in a space of 80x25*2 bytes. Code for these portions can be seen in boot2.S and boot2.c.

ToDo:

4. Porting the Donut
  After understanding the code in Donut better, we can replace print calls with our custom calls and modifying the equations to confine it to the size of VGA text output (80x25). Since the Donuts default display length is divisible 80, this process is fairly straight forward and can be seen in the final product.

Since compilation and launch of this project is complicated, a demo video with be created.
