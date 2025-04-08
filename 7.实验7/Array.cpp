#include <iostream>
using namespace std;

template <class elementType, int numberOfElements>
class Array {
public:
    Array() : size(numberOfElements) {
        arrayCount++;
    }

    int getSize() const {
        return size;
    }

    static int getArrayCount() {
        return arrayCount;
    }

    friend istream& operator>>(istream& input, Array& a) {
        for (int i = 0; i < numberOfElements; ++i) {
            input >> a.ptr[i];
        }
        return input;
    }

    friend ostream& operator<<(ostream& output, const Array& a) {
        for (int i = 0; i < numberOfElements; ++i) {
            output << a.ptr[i];
            if (i != numberOfElements - 1) output << " ";
        }
        return output;
    }

private:
    elementType ptr[numberOfElements];
    int size;
    static int arrayCount;
};

template <class elementType, int numberOfElements>
int Array<elementType, numberOfElements>::arrayCount = 0;


//StudybarCommentBegin
int main()
{
    // create intArray object
    Array< int, 5 > intArray1;
    
    // initialize intArray with user input values
    cin >> intArray1;
    
    // create intArray object
    Array< int, 5 > intArray2;
    
    // initialize intArray with user input values
    cin >> intArray2;
    
    // create floatArray
    Array< float, 5 > floatArray;
    
    cin >> floatArray;
    
    // output intArray1
    cout << "\nIntArray1 contains " << intArray1.getSize() << " Elements.\n";
    cout << "The values in intArray are:\n";
    cout << intArray1;
 
    // output intArray2
    cout << "\nIntArray2 contains " << intArray2.getSize() << " Elements.\n";
    cout << "The values in intArray are:\n";
    cout << intArray2;
    
    // output floatArray
    cout << "\nDoubleArray contains " << floatArray.getSize() << " Elements.\n";
    cout << "The values in the doubleArray are:\n";
    cout << floatArray;
    
    cout << "\nThere are " << Array<int,5>::getArrayCount() << " Array<int,5> objects.\n";
    cout << "\nThere are " << Array<float,5>::getArrayCount() << " Array<float,5> objects.\n";

    return 0;
    
} // end main


//StudybarCommentEnd
