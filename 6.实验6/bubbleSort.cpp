#include <iostream>
#include <iomanip>
using namespace std; 



template<class T>
void bubbleSort(T a[], int arraySize){
	for(int i=0; i<arraySize-1; i++){
		for(int j=i+1; j<arraySize; j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
}

//StudybarCommentBegin
int main()
{ 
   const int arraySize = 10;  // size of array
   int a[ arraySize ] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, i;

   // display int array in original order
   cout << "Integer data items in original order\n";

   for ( i = 0; i < arraySize; ++i )
      cout << setw( 6 ) << a[ i ];

   bubbleSort( a, arraySize );          // sort the array

   // display int array in sorted order
   cout << "\nInteger data items in ascending order\n";

   for ( i = 0; i < arraySize; ++i )
      cout << setw( 6 ) << a[ i ];

   cout << "\n\n";

   // initialize double array
   double b[ arraySize ] = { 10.1, 9.9, 8.8, 7.7, 6.6, 5.5,
                            4.4, 3.3, 2.2, 1.1 };
   
   // display double array in original order								 
   cout << "double point data items in original order\n";

   for ( i = 0; i < arraySize; ++i )
      cout << setw( 6 ) << b[ i ];

   bubbleSort( b, arraySize );          // sort the array
   
   // display sorted double array
   cout << "\ndouble point data items in ascending order\n";

   for ( i = 0; i < arraySize; ++i )
      cout << setw( 6 ) << b[ i ];

   cout << endl;

   return 0;

} // end main
//StudybarCommentEnd
