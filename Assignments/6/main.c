#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "ssv.h"
#include "string.h"
// ID: 260915701
// Name: Zenghao (Mike) Gao

int main(){
	FILE *file = fopen("mini6tester.ssv","r");
	char buffer [1000];
	int account;
	float amount;
	while (fgets(buffer, 1000, file)){
		if(!strcmp(buffer,"\n")) continue;
		parse(buffer, &account, &amount);
		findUpdate(account, amount);
	}
	prettyPrint();
	exit(0);
}
