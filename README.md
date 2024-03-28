# Student-grade-tracker
This project is a simple student information and grade management system implemented in C. Here's a breakdown of the functionalities:

## Add Student Info (addInfo function):
Allows the user to add information for a new student, including their name, ID, subjects, and scores.
The information is stored in the studentReport array of Student structures.

## List all Student Info (listInfo function):
Lists all the information of all the students currently stored in the studentReport array.

## Search for Student (searchInfo function):
Allows the user to search for a student by name.
If the student is found, their information is displayed.

## Edit Student Report (editInfo function):
Allows the user to edit the information of an existing student.
The user can update the student's ID, name, subjects, and scores.

## Delete Student Info (deleteInfo function):
Allows the user to delete the information of an existing student from the system.
The student's information is removed from the studentReport array.

## Main Menu (main function):
Presents a menu to the user with options to perform various operations on student information.
Based on the user's choice, it invokes the corresponding functions to add, list, search, edit, or delete student information.
The loop continues until the user chooses to exit the program.

## Memory Management:
The studentReport array is dynamically resized using realloc whenever a new student is added.
Memory allocated for studentReport is freed upon program exit.

Overall, this program provides basic CRUD (Create, Read, Update, Delete) operations for managing student information.
