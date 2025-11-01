#include <stdio.h>

int main(void) {
        int i =0;
        for(i; i<10; i++) {
                printf("Counting Up: %d\n",i);
        }

        while(i>=0) {
                printf("Counting Down: %d\n",i);
                i--;
        }

        do {
                i++;
        } while ( i < 20 );
        printf("After first do-while loop: %d\n",i);

        while(i>=0) {
                i--;
                if(i==18) {// continue option that will continue after the bracket
                        printf("Counting Down: %d\n",i);
                        i=16;
                        continue;
                }
                if(i==15) {// if i is equal to 15 break the loop
                        printf("stopped  at 15\n");
                        break;
                }
        }
        printf("After break condition in second do-while loop: %d\n",i);

}
