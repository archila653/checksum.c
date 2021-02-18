/********************************/
/* Program Name:                */
/* Author:                      */
/* Date:                        */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

#define max_int (255)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  byte checksum; 
  byte complement;
  byte header[10];
  int retval;
  int quotient; 
  int remainder;

  retval = read(STDIN_FILENO, &header, 10);  

  int c = 0;


       while(c < count)
       { 
               
               if(c == 5) 
               {
                   checksum = header[c];
                   header[c] = 0;                
               }
              
               sum += header[c]; 
               c++;  
          
       }
         
       quotient = sum/(max_int + 1);
       remainder = sum%(max_int + 1);
       sum = quotient + remainder;
       complement = max_int-sum;
   
  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}
