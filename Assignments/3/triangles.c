// Mike Gao
// ID: 260915701

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i, j, size;

/* Input rows from user */
if (argc != 2) {
	printf("Enter number of rows: ");
	scanf("%d", &size);
}else{
	size=atoi(argv[1]);
}

if (size <= 0){
	printf("An incorrect triangle size was inputted. The size must be greater than 0 and an integer number. syntax: ./triangles SIZE");
	exit (-1);
}

/* Row Iteration */
for(i=1; i<=size; i++){
    /* Print Spaces */
    for(j=i; j<size; j++){
        printf(" ");
    }

    /* Print Star */
    for(j=1; j<=i; j++){
        printf("*");
    }

    /* Print Next Line */
    printf("\n");
    }
    
exit(-1);
}
