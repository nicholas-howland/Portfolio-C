/*
CSCD240
Workin with files
*/

#include <stdio.h>
#include <stdlib.h>

void overwriteFile(char* filename) {
    FILE* fptr;
    fptr = fopen(filename,"w");
    fputs("",fptr);
    printf("File overwritten: %s\n",filename);
    fclose(fptr);
}

void writeLine(char* filename,char* line) {
    FILE* fptr;
    fptr = fopen(filename,"a");
    fputs(line,fptr);
    printf("%s$:%s\n",filename,line);
    fclose(fptr);

}

int main() {
    printf("Working with files:\n\n");
    printf("Ye old typewriter...\n\n");
    overwriteFile("test.txt");


    return 0;
}
