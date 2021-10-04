#include <stdio.h>
#include <string.h>
//basically need to replace calls to putchar, printf in stdio, perhaps memset from string?, will need testing. can replace memset with simple loops)

int k; //original has implicit int, adding int to remove errors
double sin(),cos();

int main(){ //another implicit int on main
    float A=0,B=0,i,j,z[1760];
    char b[1760];
    printf("\x1b[2J"); //this resets position and stops scroll (basically clear screen)
    for(;;){
        //void *memset(void *str, int c, size_t n) copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str. implicit call to string.h
        //ie moves char of 32 to all of b (space)
        // moves char of 0 to all of z (just 0'd out)
        memset(b,32,1760); //1760 is 80*22, b is a char, 1 byte
        memset(z,0,7040); //7040 is 4*1760, z is a float, 4 bytes 
        //clear screen
        for(j=0;6.28>j;j+=0.07) ///j is theta
            for(i=0; 6.28>i; i+=0.02){ //i is phi
                float c=sin(i),
                    d=cos(j),
                    e=sin(A),
                    f=sin(j),
                    g=cos(A),
                    h=d+2,
                    D=1/(c*h*e+f*g+5),
                    l=cos(i),
                    m=cos(B),
                    n=sin(B),
                    t=c*h*g-f*e;
                int x=40+30*D*(l*h*m-t*n),
                    y=12+15*D*(l*h*n+t*m),
                    o=x+80*y,
                    N=8*((f*e-c*d*g)*m-c*d*e-f*g-l*d*n);
                if(22>y&&y>0&&x>0&&80>x&&D>z[o]){
                    z[o]=D;;;b[o]=".,-~:;=!*#$@"[N>0?N:0];
                }
            } /*#****!!-*/     // end math don't worry about this
        printf("\x1b[H");      // sends formatted output to stdout. implicit call to stdio.h //this resets position and stops scroll
        for (k = 0; 1761 > k; k++)
            putchar(k % 80 ? b[k] : 10); //The C library function int putchar(int char) writes a character (an unsigned char) specified by the argument char to stdout. implicit call to stdio.h
            //replace this with putting the char and a color value
        A += 0.04;
        B += 0.02; 
        }
    }
            /*****####*******!!=;:~
       ~::==!!!**********!!!==::-
         .,~~;;;========;;;:~-.
             ..,--------,*/

//donut approx 40 char wide, 20 tall, centered
//80 total?
// 80 * 22 = 1760, how much higher does it go?
//goes approx 1 higher, max dist is 21, perhaps a cussion on top or bottom?
//realestate must be 80x22 = 1760, one row is blank
//artifacting occurs 1 row above (used for space), 
//and first point of bottom row (so row is unused)


//put char (will use col val), or perhaps absolute pos from this algo + 0xB8000

//add fucntion to putchar in abs position?
// if outside of range module of range

//if we use col val, make println set col val to 0 on new line.