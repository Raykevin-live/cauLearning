#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

class Point
{
    int x,y;
    friend ostream& operator<<(ostream& os, const Point& pt);
public:
    //构造函数，输出 cout<<"\nPoint is called!";  并完成私有成员的初始化
    Point(int x = 0, int y=0){
    	cout<<"\nPoint is called!";
    	this->x = x, this->y = y;	
	}
    //析构函数，输出    cout<<"\n~Point is called!";
    ~Point(){
    	cout<<"\n~Point is called!";
	}
};
//友元输出函数，输出   "("<<p.x<<","<<p.y<<")";
ostream& operator<<(ostream& os, const Point& pt){
	os<<"("<<pt.x<<","<<pt.y<<")";
	return os;
}
template <typename T>
class DynamicArray {
private:
	T* array; //pointer  ，一个T类型的指针
	unsigned int mallocSize; //分配空间的大小。
public:
	//Constructors 
	// cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
	DynamicArray(){
		array = nullptr;
		mallocSize = 0;
	}; 
	DynamicArray(unsigned length, const T &content=T(0)){
		mallocSize = length;
		cout<<endl<< "new T["<<this->mallocSize<<"] malloc "<< this->mallocSize << "*"<<sizeof(T)<<"="<<this->mallocSize *sizeof(T)<<" bytes memory in heap";
		array = new T[mallocSize];
		for(int i = 0; i< mallocSize; i++){
			array[i] = content;
		}
		 
	}; // mallocSize=length; 设置每个元素的初始内容是 content；
	//Copy Constructor
	DynamicArray(const DynamicArray<T> & anotherDA ) {
		// 拷贝逻辑(深拷贝） 
		cout<<endl<< "Copy Constructor is called";
		mallocSize = anotherDA.mallocSize;
		array = new T[mallocSize];
//		memcpy(array, anotherDA.array, mallocSize*sizeof(T));
		for(int i=0; i<mallocSize; i++){
			array[i] = anotherDA.array[i];
		}
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
	// 函数内要输出  
	DynamicArray<T>& operator=(const DynamicArray<T> & anotherDA ) {
		cout<<endl<<"operator = is called";
		if(this != &anotherDA){
			// 赋值拷贝要将原来的对象析构掉 
			delete []array;
			mallocSize = anotherDA.mallocSize;
			array = new T[mallocSize];
//			memcpy(array, anotherDA.array, mallocSize*sizeof(T));
			for(int i=0; i<mallocSize; i++){
				array[i] = anotherDA.array[i];
			}
		}
		return *this;
	}
	int resize(unsigned int newSize, const T& ValOfNewItems) {
	cout<<"\nresize is called";
	if(newSize > mallocSize) {
		T* tmp = new T[newSize];
        for (int i = 0; i < mallocSize; i++) {
            tmp[i] = array[i];
        }
        for (unsigned int i = mallocSize; i < newSize; i++) {
            tmp[i] = ValOfNewItems;  
        }
        delete[] array;  
        array = tmp;  
        mallocSize = newSize;
        return 1;
	} else if(newSize < mallocSize) {
        T* tmp = new T[newSize];
        for (unsigned int i = 0; i < newSize; i++) {
            tmp[i] = array[i];
        }
        delete[] array;  
        array = tmp;  
        mallocSize = newSize;
		return -1;                      
	} else {
		return 0;
	}
}
};

//StudybarCommentBegin
int main()
{ 
	int i,j;
	DynamicArray<int>  a(20,0);	
	DynamicArray<DynamicArray<int>> b(10,a);
	b[0].resize(30,1);
	b[5].resize(10,5);
	for(i=0;i<10;i++)
	{	cout<<"\n";		
		for(j=0;j<b[i].capacity();j++)
		{	cout<<" "<<b[i][j] ;}
	}
	return 0;
}
//StudybarCommentEnd
