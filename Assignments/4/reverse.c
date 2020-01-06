// Name: Mike Gao
// ID: 260915701

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse_in_place(char *str) {
  size_t len = strlen(str);
  size_t i = 0;
  while (len > i) {
    char tmp = str[--len];
    str[len] = str[i];
    str[i++] = tmp;
  }
  return str;
}

int main(int argc, char *argv[]){
    if (argc != 3) {
        printf("Wrong number of arguments. Please input: ./reverse WORD1 WORD2\n");
	    exit (1);
    }

    char *str1 = reverse_in_place(argv[1]);
    char *str2 = argv[2];

    int result = strcmp(str1,str2);

    if (result == 0){
        printf("WORD1= %s WORD2= %s - REVERSE\n",&*str1,&*str2);
        exit (0);
    } else{
        printf("WORD1= %s WORD2= %s - NOT REVERSE\n",&*str1,&*str2);
        exit (0);
    }
}