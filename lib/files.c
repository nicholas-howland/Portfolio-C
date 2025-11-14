#include <stdio.h>
#include <stdlib.h>

void overwriteFile(char* filename, char* text){
    FILE* fptr;
    fptr = fopen(filename,"w");
    fputs("",fptr);
    printf("File named %s was overwritten with \n%s\n",filename,text);
    fclose(fptr);
}
void appendToFile(char* filename, char* text) {
    FILE* fptr;
    fptr = fopen(filename,"a");
    printf("Wrote the following:\n%s$: %s",filename,text);
    fputs(text,fptr);
    fclose(fptr);
}
void writeToFile(char* filename, int maxLineSize) {
    FILE* fptr;
    fptr = fopen(filename,"a");
    printf("\n%s$:",filename);

    char safeString[maxLineSize];
    int trueSize=0;
    fgets(safeString,sizeof(safeString),stdin);
    int size=sizeof(safeString);
    while(trueSize<maxLineSize && safeString[trueSize]!=10){
        trueSize++;
        if(trueSize>=size){
            int c; while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }

    fputs(safeString,fptr);
    fclose(fptr);
}


int readFile(char* filename){
    FILE *fptr;
    char onebit;
    char line[100];
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    while (fgets(line, sizeof(line), fptr) != NULL) {
        printf("%s", line);
    }
    fclose(fptr);
    return 0;
}


void binaryWriteToFile(char* filename);



int main() {
// simple overwrite to file named file-test.txt
    char* finame="file-test.txt";
    overwriteFile(finame,"");
    appendToFile(finame,"      This is a test file\n   ");
    writeToFile(finame,300);
    printf("## contents of %s ##\n",finame);
    readFile(finame);
}
