//-------------------------------------------------------------------------------------------------
//Author:	   Jason McMullen and Anthony Martini
//Due Date:    3/6/14
//Program:	   Lab4
//Description: This program will read in a list of courses, store them in an array and then compare
//			   them and ouput some statistical details. The program will first start off prompt the
//			   user for the amount of courses they wish to enter. It then will compare that number
//			   to the size of the array and see if that is possible. If it is not, then the program
//			   will continually loop until the user enters an appropriate number (the function in
//			   charge of this will tell the user the max amount of courses that can be entered). It
//			   then will record the course information and store the details in a 2D array. The 
//			   program will then comput and ouput the overall course with the least amount of
//			   students in it. After that the proram will compute and output the maximum amount of
//			   students for each year. It will then sum all the students that attending each course
//			   for all the years it was offered and ouput the sum for each class. Finally, the
//			   program will print a graphical representation of the number of students that
//			   attended each course for every year it was offered (note: it will print a graph for
//			   each course entered).
//-------------------------------------------------------------------------------------------------
#include <iostream>;
#include <string>;
using namespace std;

//Constant to control the maximum number of courses in the array.
const int MAX_ENTRY = 10;

//Constants that will consist of the preapproved course name list. Each course will be later
//converted to an integer. The number following "course" will be its assigned integer value.
const string course1 = "CSC101";
const string course2 = "MTH223";
const string course3 = "ENG105";

//-------------------------------------------------------------------------------------------------
//Function getData: The function will first start out by calling another function to determine,
//					after being prompted, if the amount of courses the user wishes to enter is
//				    possible with the limit imposed on the array before compile. The function will
//				    then prompt the user to enter the course information. The input for the courses
//					has to follow a specific format:
//					YEAR  COURSE  # of STUDENTS   (course will be converted to an int by another
//					function)
//					If there is more room in the array the user will be prompted if they wish to
//					enter more data. If so, then the function will repeat itself. If not, then the
//					function will end.
//
//Precondition:		This function requires the actual array to be sent over so we can modify the
//					contents placed inside. It also will need the variable controlling the amount
//					of courses in the array and the variable that is holding the current index
//					of the array.
//Postcondition:	This function will not be returning anything.
//-------------------------------------------------------------------------------------------------
void getData(int list [][3], int& numCourses, int index);

//-------------------------------------------------------------------------------------------------
//Function graph: graph will print out the results of each class in a graphical format. The format
//				  will be a bar graph with the y axis as the year and the x axis as the number of
//				  students. The symbol "*" will be used to create the bars on the graph. Each set
//				  of 3 "*" will be a unit of 5 students.
//
//Precondition:   graph requires the ability to read the values store in the array and the length
//				  of the array sent to it to work properly.
//Postcondition:  This function will not return anything.
//-------------------------------------------------------------------------------------------------
void graph(const int list[][3]);

//-------------------------------------------------------------------------------------------------
//Function rangeOfYears: This function will compute and output the range of years that each class 
//						 was offered.
//
//Precondition:			 The function requires access to read the values in the array and the 
//						 length of the array as well as the amount of courses in the array sent to
//						 it. It also will need access to the variables for the low and high end of
//						 the ranges so it can change the values in their memory location without
//						 having to return anything.
//Postcondition:		 This function will not output anything.
//-------------------------------------------------------------------------------------------------
void rangeOfYears(const int list [][3], int numCourses, int& low, int& high);

//-------------------------------------------------------------------------------------------------
//Function totalPerCourse: The function will comput and output the total number of students per
//						   course.
//
//Precondition:			   totalPerCourse requires the array (so it may read the values stored
//						   within) and the length of the array.
//Postcondition:		   This function will not return anything.
//-------------------------------------------------------------------------------------------------
void totalPerCourse(const int list[][3]);

//-------------------------------------------------------------------------------------------------
//Function minNumberOfStudents: This function will compute and output the class, out of all that
//								were entered, that had the lowest amount of students in. It will
//								do this by going through each entry in the array and compare all
//								the classes to find the one with the least amount of students in
//								enrolled in it.
//
//Precondition:					This function requires array to be passed so it may read the
//								values stored within. It also will need the length of the array.
//Postcondition:			    This function will not ouput anything.
//-------------------------------------------------------------------------------------------------
void minNumberOfStudents(const int list[][3], int numCourses);

//-------------------------------------------------------------------------------------------------
//Function maxPerYear: This function will compute and output the class that had the max amount of
//					   students per year. The function will use a for loop to go through every
//					   course looking at only the third position in the second column. The years
//					   will then be examined to determine which course had the most amount of
//					   students enrolled in. The function will the ouput the year, course name,
//					   and the amount of students for that course.
//
//Precondition:		   This function will need the array passed to it so it may read the values 
//					   stored within. It will also need the length of the array passed as well.
//Postcondition:       This function will not return anything.
//-------------------------------------------------------------------------------------------------
void maxPerYear(const int list[][3], int numCourses, int low, int high);

//-------------------------------------------------------------------------------------------------
//Function totalPerCourse: This function will output the total number of students in each course
//						   for all years.
//
//Precondition:			   This function will need the array passed to it so it may read the values
//						   contained within as well as the length of the array.
//Postcondition:		   This function will not return anything.
//-------------------------------------------------------------------------------------------------
void totalPerCourse(int list[][3]);

//-------------------------------------------------------------------------------------------------
//Function checkRequest: This fucntion will determine if there is enough space left in the array to
//						 allow the user to enter more courses.
//
//Precondition:			 The function requires the entered number of courses to be passed to it. So
//						 it may change its value without having to return anything.
//Postcondition:		 The function will not return anything
//-------------------------------------------------------------------------------------------------
void checkRequest(int& numCourses);

//-------------------------------------------------------------------------------------------------
//Function addMore: This function will prompt the user and inquire if they wish to add more data
//					into the array. This prompt will only occur after it has been verified that
//					theres is sufficient room in the array for more entries. If the user wishes to
//					enter more data then the function will call getData.
//
//Precondition:		This function will require the array, the variable controlling the amount of 
//					courses in the array, and the index all to be passed to it.
//Postcondition:    This function will not return anything.
//-------------------------------------------------------------------------------------------------
void addMore(int list [][3], int numCourses, int index);

//-------------------------------------------------------------------------------------------------
//Function convertCourse: This function will compare an entered string and return an int value 
//						  assigned with it. The values have been predetermined wiht each course
//						  title. There will be no error checking in this function. If the user did
//						  not type the course name from the preapproved list then the function 
//						  will return a -1 and insert that into the array.
//
//Precondition:			  This function needs the entered string passed for it to compare that 
//						  string with a predetermined int value for each one.
//Postcondition:		  This function will return the int value of the course name entered in 
//						  order for it to be added to an int array. The values are: CSC101 = 1, 
//						  MTH223 = 2, ENG1-5 = 3.
//-------------------------------------------------------------------------------------------------
int convertCourse(string course);

//-------------------------------------------------------------------------------------------------
//Function courseName: This function will convert an integer back into the course title.
//
//Precondition:		   The function requires the indetifing integer sent to it so it can compare it
//					   to the predifined list of courses and turn it back into a string.
//Postcondition:	   This function will return the string containing the course title.
//-------------------------------------------------------------------------------------------------
string courseName(int num);

//-------------------------------------------------------------------------------------------------
//Function printMaxYear:
//
//Precondition:
//Postcondition:
//-------------------------------------------------------------------------------------------------
void printMaxYear(int list[][3], int answerIndex);

//-------------------------------------------------------------------------------------------------
//Function main: The main function. It will be responsible for running the program and making the
//				 necessary calls to following functions.
//-------------------------------------------------------------------------------------------------
int main()
{
	
	//create a new array. Will have to change code to adjust size of array
	int list[MAX_ENTRY][3];

	//inializing both variables to 0 since no courses have been added to the array yet
	int numCourses = 0;
	int index = 0;

	//low and high years. i.e. the range of years entered in the array
	int low, high;

	getData(list, numCourses, index);

	rangeOfYears(list, numCourses, low, high);

	minNumberOfStudents(list, numCourses);

	maxPerYear(list, numCourses, low, high);

	system("pause");

	return 0;

}//end main function

//-------------------------------------------------------------------------------------------------
//Function getData: The function will first start out by calling another function to determine,
//					after being prompted, if the amount of courses the user wishes to enter is
//				    possible with the limit imposed on the array before compile. The function will
//				    then prompt the user to enter the course information. The input for the courses
//					has to follow a specific format:
//					YEAR  COURSE  # of STUDENTS   (course will be converted to an int by another
//					function)
//					If there is more room in the array the user will be prompted if they wish to
//					enter more data. If so, then the function will repeat itself. If not, then the
//					function will end.
//
//Precondition:		This function requires the actual array to be sent over so we can modify the
//					contents placed inside. It also will need the variable controlling the amount
//					of courses in the array and the variable that is holding the current index
//					of the array.
//Postcondition:	This function will not be returning anything.
//-------------------------------------------------------------------------------------------------
void getData(int list [][3], int& numCourses, int index)
{

	//check to see if the amount of courses user wants to enter is possible
	checkRequest(numCourses);

	//prompt
	cout << "Please enter the course information as follows:\n"
		 << "Year  Course  # of Students"
		 << endl;

	//loop controlling the enter of data in the 2D array. Index will be updated so if more courses
	//wish to be entered the function will not over-write previously entered data
	for (int i = index; i < numCourses; i++)
	{

		for (int j = 0; j < 3; j++)
		{

			if (j != 1)
			{

				cin >> list[i][j];

			}//end if statement
			else
			{

				string course;

				cin >> course;

				int courseID = convertCourse(course);

				list[i][j] = courseID;

			}//end else statement

		}//end nested for loop

		//move the index to the next empty spot in the array
		index++;

	}//end for loop

	//ask if user would like to add more entries if there is more room
	addMore(list, numCourses, index);
	
}//end getData function

//-------------------------------------------------------------------------------------------------
//Function checkRequest: This fucntion will determine if there is enough space left in the array to
//						 allow the user to enter more courses.
//
//Precondition:			 The function requires the entered number of courses to be passed to it. So
//						 it may change its value without having to return anything.
//Postcondition:		 The function will not return anything
//-------------------------------------------------------------------------------------------------
void checkRequest(int& numCourses)
{
	
	//will hold the amount of courses the user wishes to enter
	int numRequest;

	//prompt and show total remaining space in the array
	cout << "How many courses would you like to add?\n"
		 << "Note: only "
		 << MAX_ENTRY - numCourses
		 << " spaces remain."
		 << endl;

	cin  >> numRequest;

	//check to see if there is room to accomodate the request. If so, then add it. If not, then
	//ask for a more reasonable number and repeat the function.
	if (numRequest <= (MAX_ENTRY - numCourses)) 
	{

		numCourses += numRequest;

	}//end if statement
	else
	{

		cout << "Please enter a number equal to or less than "
			 << MAX_ENTRY - numCourses
			 << endl;

		checkRequest(numCourses);

	}//end else statement

}//end checkRequest function

//-------------------------------------------------------------------------------------------------
//Function addMore: This function will prompt the user and inquire if they wish to add more data
//					into the array. This prompt will only occur after it has been verified that
//					theres is sufficient room in the array for more entries. If the user wishes to
//					enter more data then the function will call getData.
//
//Precondition:		This function will require the array, the variable controlling the amount of 
//					courses in the array, and the index all to be passed to it.
//Postcondition:    This function will not return anything.
//-------------------------------------------------------------------------------------------------
void addMore(int list[][3], int numCourses, int index)
{

	//variable to determine if the user wants to add more course information
	int answer;

	//check to see if there is room in the array for more courses. If so, then will prompt user
	//asking if they would like to enter more
	if (numCourses < MAX_ENTRY)
	{

		cout << "Would you like to add more courses?\n"
			 << "Note: only "
			 << MAX_ENTRY - numCourses
			 << " can be entered. 1 to enter more, 0 to continue to next menu."
			 << endl;

		cin >> answer;

		//check to see what they entered
		if (answer == 1)
		{

			getData(list, numCourses, index);

		}//end nested if statement

	}//end if statement

}//end addMore function

//-------------------------------------------------------------------------------------------------
//Function convertCourse: This function will compare an entered string and return an int value 
//						  assigned with it. The values have been predetermined wiht each course
//						  title. There will be no error checking in this function. If the user did
//						  not type the course name from the preapproved list then the function 
//						  will return a -1 and insert that into the array.
//
//Precondition:			  This function needs the entered string passed for it to compare that 
//						  string with a predetermined int value for each one.
//Postcondition:		  This function will return the int value of the course name entered in 
//						  order for it to be added to an int array. The values are: CSC101 = 1, 
//						  MTH223 = 2, ENG1-5 = 3. The function will return a -1 if the course 
//						  entered does not match what it on the predetermined list of courses.
//-------------------------------------------------------------------------------------------------
int convertCourse(string course)
{
	
	int answer = -1;

	//CSC101
	if (course == course1)
	{

		answer = 1;

	}//end if statment
	//MTH223
	else if (course == course2)
	{

		answer = 2;

	}//end first else
	//ENG105
	else if (course == course3)
	{

		answer = 3;

	}//end last else
	
	return answer;

}//end convertCourse function

//-------------------------------------------------------------------------------------------------
//Function courseName: This function will convert an integer back into the course title.
//
//Precondition:		   The function requires the indetifing integer sent to it so it can compare it
//					   to the predifined list of courses and turn it back into a string.
//Postcondition:	   This function will return the string containing the course title.
//-------------------------------------------------------------------------------------------------
string courseName(int num)
{

	string answer = " ";

	if (num == 1)
	{

		answer = course1;

	}//end if statement
	else if (num == 2)
	{

		answer = course2;

	}//end else if statment
	else if (num == 3)
	{

		answer = course3;

	}//end else if statement

	return answer;

}//end courseName function

//-------------------------------------------------------------------------------------------------
//Function maxPerYear: This function will compute and output the class that had the max amount of
//					   students per year. The function will use a for loop to go through every
//					   course looking at only the third position in the second column. The years
//					   will then be examined to determine which course had the most amount of
//					   students enrolled in. The function will the ouput the year, course name,
//					   and the amount of students for that course.
//
//Precondition:		   This function will need the array passed to it so it may read the values 
//					   stored within. It will also need the length of the array passed as well.
//Postcondition:       This function will not return anything.
//-------------------------------------------------------------------------------------------------
void maxPerYear(const int list [][3], int numCourses, int low, int high)
{

	int answer = 0;
	int answerIndex = 0;
	int j = 0;
	int maxYearArray[MAX_ENTRY];

	cout << "The courses that had the MAXIMUM number of students per year :"
		 << endl;

	for (int i = 0; i < numCourses; i++)
	{

		if (list[i][0] >= low)
		{

			if (list[i][2])
			{



			}//end nested if statement

		}//end if statement

	}//end for loop

}//end maxPerYear function

//-------------------------------------------------------------------------------------------------
//Function printMaxYear:
//
//Precondition:
//Postcondition:
//-------------------------------------------------------------------------------------------------
void printMaxYear(int list[][3], int answerIndex)
{

	cout << "In "
		 << list[answerIndex][0]
		 << " the max number of students is in "
		 << courseName(list[answerIndex][1])
		 << " with "
		 << list[answerIndex][2]
		 << " students"
		 << endl;

}//end printMaxYear function

//-------------------------------------------------------------------------------------------------
//Function minNumberOfStudents: This function will compute and output the class, out of all that
//								were entered, that had the lowest amount of students in. It will
//								do this by going through each entry in the array and compare all
//								the classes to find the one with the least amount of students in
//								enrolled in it.
//
//Precondition:					This function requires array to be passed so it may read the
//								values stored within. It also will need the length of the array.
//Postcondition:			    This function will not ouput anything.
//-------------------------------------------------------------------------------------------------
void minNumberOfStudents(const int list [][3], int numCourses)
{
	
	int answer = list[0][2];
	int answerIndex = 0;
	
	for (int i = 0; i < numCourses; i++)
	{

		int numStudents = list[i][2];

		if (numStudents <= answer)
		{

			answer = numStudents;
			answerIndex = i;

		}//end if statements

	}//end for loop

	cout << "The course with the MINIMUM number of students was in "
		 << list[answerIndex][0]
		 << " "
		 << courseName(list[answerIndex][1])
		 << " with "
		 << list[answerIndex][2]
		 << " students"
		 << endl;

}//end minNumberOfStudents function

//-------------------------------------------------------------------------------------------------
//Function rangeOfYears: This function will compute and output the range of years that each class 
//						 was offered.
//
//Precondition:			 The function requires access to read the values in the array and the 
//						 length of the array as well as the amount of courses in the array sent to
//						 it. It also will need access to the variables for the low and high end of
//						 the ranges so it can change the values in their memory location without
//						 having to return anything.
//Postcondition:		 This function will not output anything.
//-------------------------------------------------------------------------------------------------
void rangeOfYears(const int list [][3], int numCourses, int& low, int& high)
{

	low = list[0][0];
	high = list[0][0];

	for (int i = 0; i < numCourses; i++)
	{

		int year = list[i][0];

		if (low >= year)
		{

			low = list[i][0];

		}//end if statement

		if (high <= year)
		{

			high = list[i][0];

		}//end if statment

	}//end for loop

}//end rangeOfYears function