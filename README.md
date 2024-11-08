# Boot-to-Donut

Porting the famous "Donut.c" code to run straight from boot without an operating system in VGA text mode.

Note: ------------
Information and original source of Donut.C can be found here: https://www.a1k0n.net/2011/07/20/donut-math.html
-----------------

Steps: 

1. Analyze Donut.C
   In Donut2.c, you can see that I've broken down Donut.C into a more readable format, analyzed how the code displays to the screen, and removed implicit declarations in order to make my compiler happy.

2. Build "OS" from bootloader
  In order to run the code on a computer, a bootloader must be loaded into memory, the system will be set to 32-bit protected mode and handed off to boot2.c where I complete most of this project. Tools used for this process can be seen in the makefile. Because there is no underlying operating system, symbols must be stripped from object code to run on bare hardware. This has been tested on Debian.

3. Recreate print functions
   As no operating exists, function library calls are unavailable, and new functions must be created to print in VGA text mode. VGA text mode supports 80 columns and 25 rows. Printing to the screen is accomplished by moving text and color codes to memory starting at the address 0xB8000 in a space of 80x25*2 bytes. The code for these portions can be seen in boot2.S and boot2.c.

ToDo:

4. Porting the Donut
  After understanding the code in Donut better, we can replace print calls with our custom calls and modify the equations to confine it to the size of VGA text output (80x25). Since the Donuts default display length is divisible 80, this process is fairly straightforward and can be seen in the final product.

Since the compilation and launch of this project are complicated, a demo video with be created.
