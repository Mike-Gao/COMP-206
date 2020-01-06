#include <stdlib.h>
#include <stdio.h>
#include "ssv.h"


void parse(char record[], int *acct, float *amnt){
	sscanf(record,"%d %f", acct, amnt);
}