#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SUBJECTS (5)

typedef struct Student{
	char name[60];
	char subject[MAX_SUBJECTS][50];
	int score[MAX_SUBJECTS];
	int id;
	int sum;
	float avg;
	
}Student;

//Global variables to store student info and grades

Student *studentReport=NULL;
int Total=0;


void addInfo(const char *name, int id, const char subject[][50], const int score[]){
	int i;
	studentReport=realloc(studentReport, (Total + 1) * sizeof(Student));
	if (studentReport == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    // Copy name and ID for the new student
    strcpy(studentReport[Total].name, name); // Copy the name into the name array
    studentReport[Total].id=id;
    
    // Copy subjects and scores for the new student
    for(i=0; i<MAX_SUBJECTS; i++){
    	strcpy(studentReport[Total].subject[i], subject[i]); // Copy the name into the name array
    	studentReport[Total].score[i]=score[i];
	}
	
	// Increment the total count of students
    Total++;
    printf("Student info has been updated\n");
}

void listInfo(){
	int i, j;
	for(i=0; i<Total; i++){
		printf("%d. %s :\n",studentReport[i].id, studentReport[i].name);
		
		
		// Print subjects and scores for the current student
		for(j=0; j<MAX_SUBJECTS; j++){
			printf("%s\t%d",studentReport[i].subject[j], studentReport[i].score[j]);
		}
	}	
}

void searchInfo(const char *name){
	int i;
	int flag=0;
	
	for(i=0; i< Total; i++){
		if(strcmp(studentReport[i].name, name)==0){
			flag=1;
			break;
		}
	}
	
	if(flag==1){
		int j;
		printf("%d. %s :\n",studentReport[i].id, studentReport[i].name);
		
		
		// Print subjects and scores for the current student
		for(j=0; j<MAX_SUBJECTS; j++){
			printf("%s\t%d",studentReport[i].subject, studentReport[i].score);
		}
	}
}

void deleteInfo(const char *name){
	int i;
	int flag=0;
	
	for(i=0;i<Total; i++){
		if(strcmp(studentReport[i].name, name)==0){
			flag=1;
			break;
		}
	}
	
	
	if(flag==1){
		int j;
		for(j=i; j<Total-1; j++){
			studentReport[j]=studentReport[j+1];
		}
		Total--;
		printf("%s has been deleted\n",name);
	}else{
		printf("%s was not found\n", name);
	}
}

void editInfo(const char *name, int id, const char subject[][50], const int score[]){
	int i;
	int flag=0;
	
	for(i=0; i< Total; i++){
		if(strcmp(studentReport[i].name, name)==0){
			flag=1;
			break;
		}
	}
	
	if(flag==1){
		char newName[60];
		char newSub[MAX_SUBJECTS][50];
		int newId;
		int newScore[MAX_SUBJECTS];
		
		
		printf("Enter student Id: \n");
		scanf("%d", &newId);
		getchar();
		
		printf("Enter new Student Name: \n");
		fgets(newName, sizeof(newName), stdin);
		
		strcpy(studentReport[i].name, newName); // Copy the name into the name array
    	studentReport[i].id=newId;
    	
    	for(i=0; i<MAX_SUBJECTS; i++){
    	strcpy(studentReport[i].subject[i], subject[i]); // Copy the name into the name array
    	studentReport[i].score[i]=score[i];
    	
    	printf("Student Report has been updated\n");
		}
	}
	else{
		printf("Student not found\n");
	}
}

int main() {
	int option, id;
	int score[MAX_SUBJECTS];
	char name[60], subject[MAX_SUBJECTS][5];
	
	printf("1. Add Student Info\n");
	printf("2.List all Student Info\n");
	printf("3. search for Student\n");
	printf("4. Edit Student Report\n");
	printf("5. Delete Student Info\n");
	printf("6. Exit\n");
	
	
	while(1){
		printf("Enter your option(1-6)\n");
		scanf("%d", &option);
		
		
		switch(option){
			case 1:
				
				printf("Enter Student ID: \n");
				scanf("%d",&id);
				
				printf("Enter the Student Name: \n");
				scanf("%s", name);
				
				printf("Enter Subjects: \n");
				scanf("%s", subject);
				
				printf("Enter the score for each subject: \n");
				scanf("%d", &score);
				getchar();
				addInfo(name, id, subject, score);
				break;
				
			case 2:
				listInfo();
				break;
				
			case 3:
				printf("Enter a name: \n");
				fgets(name, sizeof(name), stdin);
				getchar();
				searchInfo(name);
				break;
				
			case 4:
				printf("Enter a name: \n");
				fgets(name, sizeof(name), stdin);
				
				deleteInfo(name);
				break;
				
			case 5:
				printf("Enter Student ID: \n");
				scanf("%d",&id);
				
				printf("Enter the Student Name: \n");
				scanf("%s", name);
				
				printf("Enter Subjects: \n");
				scanf("%s", subject);
				
				printf("Enter the score for each subject: \n");
				scanf("%d", &score);
				getchar();
				editInfo(name, id, subject, score);
				break;
				
			case 6:
				free(studentReport);
				printf("Exiting the program...\n");
				break;
				
			default:
				printf("Invalid Choice\n");
				break;		
		}
	}
	return 0;
}




















