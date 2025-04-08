#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class DynamicArray {
private:
    T* array;        // 动态数组指针
    unsigned int capacity_; // 数组容量
    unsigned int size_;     // 实际元素个数

public:

    DynamicArray() : array(nullptr), capacity_(0), size_(0) {}

    
    DynamicArray(unsigned int cap, T initVal = T(0)) 
        : capacity_(cap), size_(cap) {
        array = new T[capacity_];
        for (unsigned int i = 0; i < capacity_; ++i) {
            array[i] = initVal;
        }
    }

   
    ~DynamicArray() {
        delete[] array;
    }

  
    unsigned int capacity() const {
        return capacity_;
    }

    
    unsigned int size() const {
        return size_;
    }


    T& operator[](unsigned int i) {
        if (i >= size_) {
            cout << "Out of Range!" << endl;
            exit(EXIT_FAILURE);
        }
        return array[i];
    }

    const T& operator[](unsigned int i) const {
        if (i >= size_) {
            cout << "Out of Range!" << endl;
            exit(EXIT_FAILURE);
        }
        return array[i];
    }
};

using VectorDouble = DynamicArray<double>;
//StudybarCommentBegin
int main()
{
    
    VectorDouble v1;
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;
    
    double value;
    cin >> value;
    
    VectorDouble v2(5,value);
    cout << v2[0] << endl;
    cout << v2[4] << endl;
    
    int capacity;
    cin >> capacity;
    
    VectorDouble v3(capacity);
    cout << v3.capacity() << endl;
    cout << v3.size() << endl;
    for (int i=0; i<capacity; i++) {
        v3[i] = i * 1.1;
    }
    cout << v3[5] << endl;
    cout << v3[31] << endl;

    return 0;
}
//StudybarCommentEnd
