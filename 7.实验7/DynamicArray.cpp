#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

class Point
{
    int x,y;
    
    friend ostream& operator<<(ostream& os, const Point& pt);
public:
    //���캯������� cout<<"\nPoint is called!";  �����˽�г�Ա�ĳ�ʼ��
    Point(int x = 0, int y=0){
    	this->x = x, this->y = y;
    	cout<<"\nPoint is called!";
	}

    //�������������    cout<<"\n~Point is called!";
    ~Point(){
    	cout<<"\n~Point is called!";
	}
};

//��Ԫ������������   "("<<p.x<<","<<p.y<<")";
ostream& operator<<(ostream& os, const Point& pt){
	os<<"("<<pt.x<<","<<pt.y<<")";
	return os;
}
	
template <typename T>
class DynamicArray {
private:
	T* array; //pointer  ��һ��T���͵�ָ��
	unsigned int mallocSize; //����ռ�Ĵ�С��

public:
	//Constructors 
	// cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
	DynamicArray(unsigned length, const T &content):array(NULL), mallocSize(length){
		if(array==NULL){
			array = new T[mallocSize];
		}
		else{
			array = NULL;
		}
		for(int i = 0; i< mallocSize; i++){
			array[i] = content;
		}
		 cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
	}; // mallocSize=length; ����ÿ��Ԫ�صĳ�ʼ������ content��
	//Copy Constructor

	DynamicArray(const DynamicArray<T> & anotherDA ) {
		// �����߼�(����� 
		mallocSize = anotherDA.mallocSize;
		array = new T[mallocSize];
		memcpy(array, anotherDA.array, mallocSize*sizeof(T));
		
		cout<<endl<< "Copy Constructor is called";
	};
	// Destructors
	// cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
	~DynamicArray(){
	 	cout<<endl<< "delete[] array free "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
		 delete []array;
	};
	
	//return the this->mallocSize
	unsigned int capacity() const{
		return this->mallocSize;
	};
	
	// for the array[i]=someT.
	T& operator[](unsigned int i) {
		return *(array+i);
	};
	const T& operator[](unsigned int i) const{
		return *(array+i);
	};
	
	// ������Ҫ���  

	DynamicArray<T>& operator=(const DynamicArray<T> & anotherDA ) {
		mallocSize = anotherDA.mallocSize;
		array = new T[mallocSize];
		memcpy(array, anotherDA.array, mallocSize*sizeof(T));
		
		cout<<endl<<"operator = is called";
		return *this;
	}
};

//StudybarCommentBegin
int main()
{
int length,i;
cin>> length;

DynamicArray<Point> iarray(length,Point(3));

DynamicArray<Point> iarray2(iarray),iarray3(iarray2);

cout<<endl;
for(i=0;i<length;i++) {
	cout << iarray3[i] <<" ";
	iarray[i] = Point(i,i+1);	
}
iarray3=iarray2=iarray;
cout<<endl;
for(i=0;i<length;i++) {
	cout << iarray3[i] <<" ";	
}

return 0;
}
//StudybarCommentEnd
