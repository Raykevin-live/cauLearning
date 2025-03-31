#include <iostream>

using namespace std;

// function template printArray definition

void printArray( const int *arrayset, int count )

{

   for ( int i = 0; i < count && arrayset[i]!='\0' ; i++ )

      cout << arrayset[ i ] << " ";

   cout << endl;

} // end function template printArray

void printArray( const char *arrayset, int count )

{

   for ( int i = 0; i < count && arrayset[i]!='\0' ; i++ )

      cout << arrayset[ i ] << " ";

   cout << endl;

} 

void printArray( const char **arrayset, int count )

{
	int set = 0;
   for ( int i = 0; i < count && arrayset[i]!='\0' ; i++ ){
   		set = (set+1)%4; 
		printf("%10s", arrayset[i]);
		if(set==0){
			cout<<endl;
		}
   }
   		
		
      

   cout << endl;

} 

void printArray( const double *arrayset, int count )

{

   for ( int i = 0; i < count && arrayset[i]!='\0' ; i++ )

      cout << arrayset[ i ] << " ";

   cout << endl;

} 

//StudybarCommentBegin
int main()
{
    // set size of arrays
    const int aCount = 5;
    const int bCount = 7;
    const int cCount = 6;
    const int sCount = 8;
    
    // initialize arrays
    int a[ aCount ] = { 1, 2, 3, 4, 5 };
    double b[ bCount ] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
    char c[ cCount ] = "HELLO";  // 6th position for null
    const char *strings[ sCount ] = { "one", "two", "three", "four",
        "five", "six", "seven", "eight" };
    
    cout << "Array a contains:\n";
    printArray( a, aCount );  // integer template function
    
    cout << "\nArray b contains:\n";
    printArray( b, bCount );  // float template function
    
    cout << "\nArray c contains:\n";
    printArray( c, cCount );  // character template function
    
    cout << "\nArray strings contains:\n";
    printArray( strings, sCount );  // function specific to string arrays
    
    return 0;
    
} // end main

//StudybarCommentEnd
