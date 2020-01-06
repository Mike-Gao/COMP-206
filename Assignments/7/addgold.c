// Zenghao (Mike) Gao / ID: 260915701
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    FILE * f = fopen("../index.html", "rt");
    char buffer[1000];
   	printf("Content-type:text/html\n\n");	 
	char * query = getenv("QUERY_STRING");
	int goldNum;	
    	if (strstr(query,"gold") != NULL) {
		sscanf(query, "gold=%d", &goldNum);
	} else {
		goldNum = 10;
	}
	while(fgets(buffer,1000,f)){
		if(strstr(buffer, "</form>")!= NULL){
			printf("<input type=\"hidden\" name=\"gold\" value=\"%d\">\n",goldNum);
		}
		printf("%s",buffer);
	}
}
