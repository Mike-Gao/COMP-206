#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ID: 260915701
// Name: Mike Gao

int main(int argc, char *argv[]){
	
	if (argc < 2) {
		printf("Your did not provide any arguments. Please enter: ./database CMD OPT1 OPT2 OPT3 OPT4\n");
		exit(1);
	}
	char *cmd = argv[1];
	
	if (strcmp(cmd,"SHOW") == 0){
		FILE* file = fopen("database.csv","r");
		int record_num = 0;
		char buffer[1000];
		char id[200]="",name[400]="",age[200]="",gpa[200]="";
		int i,j;
		while (fgets(buffer,999,file)){
			i = 0;
			for(j=0; j<200 && buffer[i]!=','; j++, i++){
				id[j]=buffer[i];
			}
			i++;
			for(j=0; j<400 && buffer[i]!=','; j++, i++){
				name[j]=buffer[i];
			}
			i++;
			for(j=0; j<200 && buffer[i]!=','; j++, i++){
				age[j]=buffer[i];
			}
			i++;
			for(j=0; j<200 && buffer[i]!='\0' && buffer[i]!='\r' && buffer[i]!='\n'; j++, i++){
				gpa[j]=buffer[i];
			}
			

// 				id = atoi(strsep(&line[record_num],","));
// 				name = strsep(&line[record_num],",");
// 				age = atoi(strsep(&line[record_num],","));
// 				gpa = atof(strsep(&line[record_num],","));
			
			record_num++;
			
			printf("Record %-3d: ID=%-10d NAME=%-10s AGE=%-10d GPA=%-10.1f \n",record_num, atoi(id), name, atoi(age), atof(gpa));
			memset(buffer,0,999);
			memset(id,0,199);
			memset(name,0,399);
			memset(age,0,199);
			memset(gpa,0,199);
		}
		
		exit(0);

	} else if (strcmp(cmd,"DELETE") == 0){
		if(argv[2] == NULL){
			printf("Name of record to delete is missing\n");
			exit(1);
		} else {
			FILE* file = fopen("database.csv","r");
			FILE* tmp = fopen("database.tmp","w");
			int i,j;
			int searched = 0;
			char buffer[1000] = "";
			while (fgets(buffer,999,file)){
				char id[200]="",name[400]="",age[200]="",gpa[200]="";
				i = 0;
				for(j=0; j<200 && buffer[i]!=','; j++, i++){
					id[j]=buffer[i];
				}
				i++;
				for(j=0; j<400 && buffer[i]!=','; j++, i++){
					name[j]=buffer[i];
				}
				i++;
				for(j=0; j<200 && buffer[i]!=','; j++, i++){
					age[j]=buffer[i];
				}
				i++;
				for(j=0; j<200 && buffer[i]!='\0' && buffer[i]!='\r' && buffer[i]!='\n'; j++, i++){
					gpa[j]=buffer[i];
				}
				if (atoi(argv[2]) == atoi(id) && searched < 1){
					searched++;
				} else {
					fputs(id,tmp);
					fputs(",",tmp);
					fputs(name,tmp);
					fputs(",",tmp);
					fputs(age,tmp);
					fputs(",",tmp);
					fputs(gpa,tmp);
					fputs("\n",tmp);
					
				}
				memset(buffer,0,999);
				memset(id,0,199);
				memset(name,0,399);
				memset(age,0,199);
				memset(gpa,0,199);
			}
			system("rm database.csv");
			system("mv database.tmp database.csv");
		}
		
	}
	else if (strcmp(cmd,"ADD") == 0){
		if(argv[2] == NULL || argv[3] == NULL || argv[4] == NULL || argv[5] == NULL){
			printf("Missing ID, Name, AGE, and GPA arguments\n");
			exit(1);
		} else {
			FILE* file = fopen("database.csv","at");
			fputs(argv[2],file);
			fputs(",",file);
			fputs(argv[3],file);
			fputs(",",file);
			fputs(argv[4],file);
			fputs(",",file);
			fputs(argv[5],file);
			fputs("\n",file);
		}
	}
	else {
		printf("The command you requested in invalid. Please select from one of these: SHOW, DELETE, ADD\n");
		exit(1);
	}

}
