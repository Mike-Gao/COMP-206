#include <stdlib.h>
#include <stdio.h>
#include "linked.h"

static struct ACCOUNT *head = NULL;

struct ACCOUNT {
         int accountNumber;
         float balance;
         struct ACCOUNT *next;
};

void findUpdate(int account, float amount){
	struct ACCOUNT *prev = NULL;
	struct ACCOUNT *cur = NULL;
	
	if (head == NULL){
		head = malloc(sizeof(struct ACCOUNT));
		head->accountNumber = account;
		head->balance = amount;
		head->next = NULL;
	} else {
		for (cur = head; cur != NULL; prev = cur, cur = cur->next){
			if(cur->accountNumber == account){
				cur->balance += amount;
				return;
			}
		}
		cur = malloc(sizeof(struct ACCOUNT));
		cur->accountNumber = account;
		cur->balance = amount;
		cur->next = NULL;
		prev->next = cur;
	}
}

void prettyPrint(){
//ACCOUNT ID: nnnnn BALANCE: $ nnnnnn.nn
	for(struct ACCOUNT *cur = head; cur != NULL; cur = cur->next){
		printf("ACCOUNT ID: %5d BALANCE: $ %9.2f\n", cur->accountNumber, cur->balance);
	}
}