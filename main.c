#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
	char name[60];
	int subject[5];
	int id;
	int sum;
	float avg;
	
}Student;

//Global variables to store student info and grades

Student *studentReport=NULL;
int Total=0;


void addInfo(const char *name, int id){
	studentReport=realloc(studentReport, (Total + 1) * sizeof(Student));
	if (studentReport == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(studentReport[Total].name, name); // Copy the name into the name array
    contactList[Total].id=id;
    Total++;
    printf("Student info has been updated\n");
}

void addGrade(int subject){
	
}

int main() {
	return 0;
}
