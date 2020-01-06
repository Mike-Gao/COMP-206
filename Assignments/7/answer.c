// Zenghao (Mike) Gao / ID: 260915701
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkwin(int goldNum){

    if (goldNum <= 0) {
	printf("<h2>YOU LOSE</h2>\n");
	printf("<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/dQw4w9WgXcQ?controls=0&autoplay=1\" frameborder=\"0\" allow=\"accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>");
        printf("\n<h2>YOU LOSE</h2> </body></html>");
        exit(0);
    } else if (goldNum >= 100) {
        printf("<h1>YOU WIN</h1>\n");
	printf("<iframe width=\"560\" height=\"315\" src=\"https://www.youtube.com/embed/tas0O586t80?controls=0&autoplay=1\" frameborder=\"0\" allow=\"accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture\" allowfullscreen></iframe>");
        printf("\n<h1>YOU WIN</h1> </body></html>");
        exit(0);
    }
}
void redirect(char *direction, char *user, int gold) {
	printf("<a href=\"https://cs.mcgill.ca/~%s/cgi-bin/addgold.cgi?gold=%d\">Press HERE to go %s</a>", user, gold, direction);
}

int main(){
    printf("Content-Type: text/html\n\n");
    printf("<!DOCTYPE html><html><body>");
	
    char * query = getenv("QUERY_STRING");
    char * len = getenv("QUERY_LENGTH");
    char resp[50];
    
    int goldNum = 10;
    if(!len)
	sscanf(query,"command=%[^&]&gold=%d",resp,&goldNum);
    else	
	scanf("command=%[^&]&gold=%d", resp, &goldNum);

    char * direction = "BACK";
    char * user = "zgao20";	
	if (!strcmp(resp,"NORTH")){
		checkwin(goldNum);
		direction = "NORTH";
		user = "znie4";
	}
	else if (!strcmp(resp,"SOUTH")){
		checkwin(goldNum);
		direction = "SOUTH";
		user = "tzhang74";
	}
	else if (!strcmp(resp,"EAST")){
		checkwin(goldNum);
		direction = "EAST";
		user = "czhou22";
	}
	else if (!strcmp(resp,"WEST")){
		checkwin(goldNum);
		direction = "WEST";
		user = "sberen1";
	}
	else if (!strcmp(resp,"GOLD")){
		checkwin(goldNum);
		printf("You have %d gold <br>", goldNum);
		
	}
	else if (strcmp(resp, "a.out")==0){
        	goldNum += 10;
		checkwin(goldNum);
        	printf("CORRECT! You now have %d gold <br>", goldNum);
        } else {
        	goldNum -= 5;
		checkwin(goldNum);
        	printf("WRONG ANSWER! You now have %d gold <br>", goldNum);
        }

   	redirect(direction, user, goldNum); 
	printf("</body></html>");
	return 0;

}
