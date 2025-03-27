#include <iostream>

using namespace std;

class GradeBook{
private:
	string _course_name;
	string _instructor_name;
public:
	GradeBook(const string& courseName, const string& structorName){
		_course_name = courseName, _instructor_name = structorName;
	}
	string getInstructorName(){
		return _instructor_name;
	}
	
	void setInstructorName(const string&  structorName){
		_instructor_name = structorName;
	}
	
	void displayMessage(){
		cout<<"Welcome to the grade book for"<<endl<<_course_name<<"!"<<endl;
		cout<<"This course is presented by: "<<_instructor_name<<endl;
		
		
	}
};


//StudybarCommentBegin
int main()
{
   // create a GradeBook object; pass a course name and instructor name
   GradeBook gradeBook( 
      "CS101 Introduction to C++ Programming", "Professor Smith" );

   // display initial value of instructorName of GradeBook object
   cout << "gradeBook instructor name is: " 
      << gradeBook.getInstructorName() << "\n"; 

   // modify the instructorName using set function
   gradeBook.setInstructorName( "Assistant Professor Bates" );

   // display new value of instructorName
   cout << "new gradeBook instructor name is: " 
      << gradeBook.getInstructorName() << "\n";

   // display welcome message and instructor's name
   gradeBook.displayMessage(); 
   return 0; // indicate successful termination
} // end main

//StudybarCommentEnd
