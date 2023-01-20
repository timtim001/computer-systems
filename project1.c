/*
Author: Timothy Morren
Date:  9/13/21
Project: project1
Class: CSCI 3240
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main( int argc, char *argv[] )  {                       //command line argument inputs
    int i=0;
    char ch, temp[16];
    FILE *fp;
    fp =fopen(argv[1],"r");                                 //opens command line arg file as read file
    do {                                                    //while not at EOF get a new char from file 
      ch = fgetc(fp);                                       //grabs char and moves file stream pointer to next char
      if(isprint(ch)||ch=='\n'){                            //checks if ch is a printable character                      
         int m=i/16; 
         if(i%16==0){printf("%07x0: ",m);}                  //prints index format
         if(ch=='\n'){printf("0");}
         printf("%x", ch);                                  //prints the hex value of ch
         temp[i%16]=ch;                                     //stores the value in array for print later
         i++;
         if(i%2==0){printf(" ");}
         if(i%16==0){
            printf(" ");
            for(int j=0;j<16;j++){                          
               if(temp[j]=='\n'){printf("%c",'.');}         //format for new line
               else{printf("%c",temp[j]);}
            }                                               //loops through saved array of ch's and prints all 16
            printf("\n");
         }
      }
   } while(!feof(fp));                                      //end loop if EOF
   int r=16-i%16;                                           //calculates the amount of spaces needed to format last line
   int s=r*2+r/2+2;
   if(r!=0){
      printf("%*s",s,"");                                   //prints last line stored in ch array 
   }
   for(int j=0;j<i%16;j++){
      if(temp[j]=='\n'){printf("%c",'.');}                  //format for new line
      else{printf("%c",temp[j]);}
      }
   fclose(fp);                                              //close file
   return(0);
}