#include <stdio.h>
#include <stdlib.h>

int main (void) {
    
    char c;
    int count = 0;
    
    FILE *fp = fopen("one_hot_encoding_file.txt", "r"); //Opens input to read
    
    FILE *output = fopen("output.csv", "w"); //Opens output to write
    
    c = fgetc(fp);
    
    while (c != EOF) {
       
        if (c == '\"') {
            
            //make edits
            for (count=0;count<8;count++) { //runs 7 times, starts on the first 1/0
                
                c = fgetc(fp); //get the 1/0
                fprintf(output, "%c,", c); //Prints the 1/0 then a comma 
                
            } //end for
            
            c = fgetc(fp); //get the 1/0
            fprintf(output, "%c", c); //Prints the last 1/0
            
            c = fgetc(fp); //gets the second quote and does nothing with it
            
        } //end if c is a "
        else {
            fprintf(output, "%c", c);
        } //end else
        
        c = fgetc(fp);
    } //end while

} //end main
