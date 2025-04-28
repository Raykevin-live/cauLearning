#include <iostream>
using namespace std;

#define SIZE 4

template <class T>
class DynamicVector {
    T* array;
    unsigned mallocSize;
    unsigned numofItems;
    int virtualZero;

public:
    DynamicVector(int Vindex);
    DynamicVector(const DynamicVector& other);
    DynamicVector( T* const first, T* const last,int Vindex=0);
    ~DynamicVector();
    DynamicVector& operator=(const DynamicVector& other); 

    inline void push_back(const T& x);
    void push_back(const DynamicVector& other); 
	bool operator == (const  DynamicVector& dv) const;
    T& operator[](int Vindex);
    unsigned length() const;
    unsigned capacity() const;  
    int firstIndex() const;
    void insert (int Vindex, const T&);
    DynamicVector operator()(int Vfirst, int Vlast) const;
  
    void remove ();   //删除最后一个元素。
 	void remove (int Vindex); //删除Vindex号元素。
 	void remove (int Vfirst, int Vlast);   //删除[Vindex,Vlast) 号元素。 注意是左闭右开集合，即不删除Vlast元素
 	
	void swap(DynamicVector<T> & dv);  //实现和 dv两个对象的内容交换
	
	T* begin() const{
		return &array[0];
	}
	T* end() const{
		return &array[numofItems];
	}
	
    template <class OS>
    friend ostream& operator<<(ostream&, const DynamicVector<OS>&);
};

template <class T>
DynamicVector<T>::DynamicVector(T* const first, T* const last, int Vindex){
	this->mallocSize = 0;
	this->numofItems = 0;
	array = nullptr;
	virtualZero = Vindex;
	int len = last - first;
	T* begin = first;
	for(int i=0; begin < last; i++){
		this->push_back(*begin++);
	}
}

template <class OS>
ostream& operator<<(ostream& os, const DynamicVector<OS>& dv){
	if(dv.numofItems==0) os<<"The arrray is empty.";
	else{
		for(int i=0; i<dv.numofItems; i++){
			os<<dv.array[i]<<" ";
		}
	}
	return os;
}
template <class T>
void DynamicVector<T>::insert(int Vindex, const T& x){
	int _entry = Vindex - virtualZero;
    if (_entry < 0 || _entry > static_cast<int>(numofItems)) {
        cerr << "Index out of range!";
        exit(1);
    }
	this->push_back(x);
	for(int i=numofItems-2; i>=_entry; i--){
		array[i+1] = array[i];
	}
	array[_entry] = x;
}
template <class T>
void DynamicVector<T>::remove (){
	if(numofItems!=0){
		numofItems--;
	}
}
template <class T>
void DynamicVector<T>::remove (int Vindex){
	int pop = Vindex - virtualZero;
    if (pop < 0 || pop > static_cast<int>(numofItems)) {
        cerr << "Index out of range!";
        exit(1);
    }
    --numofItems;
    for(int i=pop; i<numofItems; i++){
    	array[i] = array[i+1];
	}
}
template <class T>
void DynamicVector<T>::remove (int Vfirst, int Vlast){
	int popbegin = Vfirst - virtualZero;
    if (popbegin < 0 || popbegin > static_cast<int>(numofItems)) {
        cerr << "Index out of range!";
        exit(1);
    }
    int popend = Vlast - virtualZero;
    if (popend <= popbegin || popend > static_cast<int>(numofItems)) {
        cerr << "Index out of range!";
        exit(1);
    }
    
    int diff = popend-popbegin;
    for(int i=popbegin; i+diff < numofItems; i++){
    	array[i] = array[i+diff];
	}
	numofItems -= diff;
}
template <class T>
DynamicVector<T> DynamicVector<T>::operator()(int Vfirst, int Vlast) const{
	int begin = Vfirst - virtualZero;
    if (begin < 0 || begin > static_cast<int>(numofItems)) {
        cerr << "Index out of range!";
        exit(1);
    }
    int end = Vlast - virtualZero;
    if (end <= begin || end > static_cast<int>(numofItems)) {
        cerr << "Index out of range!";
        exit(1);
    }
    
    DynamicVector tmp(this->virtualZero);
    for(int i=begin; i<end; i++){
    	tmp.push_back(array[i]);
	}
	return tmp;
}
template <class T>
DynamicVector<T>::DynamicVector(const DynamicVector& other) {
    mallocSize = other.mallocSize;
    numofItems = other.numofItems;
    virtualZero = other.virtualZero;
    array = new T[mallocSize];
    for (unsigned i = 0; i < numofItems; ++i) {
        array[i] = other.array[i];
    }
}
template <class T>
void DynamicVector<T>::swap(DynamicVector<T>& dv){
	DynamicVector<T> tmp1 = dv;
	DynamicVector<T> tmp2 = *this;
	dv = tmp2;
	*this = tmp1;
}
template <class T>
bool DynamicVector<T>::operator==(const  DynamicVector<T>& dv) const{
	if(numofItems!=dv.numofItems) return false;
	for(int i=0; i<numofItems; i++){
		if(array[i]!=dv.array[i]) return false;
	}
	return true;
}
template <class T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& other) {
    if (this != &other) {
        delete[] array;
        mallocSize = other.mallocSize;
        numofItems = other.numofItems;
        virtualZero = other.virtualZero;
        array = new T[mallocSize];
        for (unsigned i = 0; i < numofItems; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

template <class T>
DynamicVector<T>::DynamicVector(int Vindex) : array(nullptr), mallocSize(0), numofItems(0), virtualZero(Vindex) {}

template <class T>
DynamicVector<T>::~DynamicVector() {
    delete[] array;
}

template <class T>
void DynamicVector<T>::push_back(const T& x) {
    if (numofItems >= mallocSize) {
        unsigned newSize = (mallocSize == 0) ? SIZE : mallocSize * 4;
        T* newArray = new T[newSize];
        for (unsigned i = 0; i < numofItems; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        mallocSize = newSize;
    }
    array[numofItems++] = x;
}


template <class T>
void DynamicVector<T>::push_back(const DynamicVector& other) {
    for (unsigned i = 0; i < other.numofItems; ++i) {
        this->push_back(other.array[i]);
    }
}

template <class T>
T& DynamicVector<T>::operator[](int Vindex) {
    int _entry = Vindex - virtualZero;
    if (_entry < 0 || _entry >= static_cast<int>(numofItems)) {
        cerr << "Index out of range!";
        exit(1);
    }
    return array[_entry];
}

template <class T>
unsigned DynamicVector<T>::length() const {
    return numofItems;
}

template <class T>
unsigned DynamicVector<T>::capacity() const {
    return mallocSize-1; 
}

template <class T>
int DynamicVector<T>::firstIndex() const {
    return virtualZero;
}

//StudybarCommentBegin
int main()
{
 
    DynamicVector<int> ra(-2);
    
   
    int i,n;
    cin>>n;
    
    cout<<ra;
     
    ra.push_back(-3);
    ra.push_back(-2);
    ra.push_back(-1);
    for ( i = 0; i < n; i++)
    {
      ra.push_back(i);
    }
    cout<<"\n malloSize is "<<ra.capacity();
    cout<<"\n numofItems is "<<ra.length();
    cout<<"\n StartIndex is " << ra.firstIndex()<<endl;
    for ( i = -2; i < n+1; i++)
    {
      cout<<ra[i]<<" ";      
    }
    cout<<endl;
    DynamicVector<int> raCopy(ra);
    cout<<"\n malloSize is "<<raCopy.capacity();
    cout<<"\n numofItems is "<<raCopy.length();
    cout<<"\n StartIndex is " << raCopy.firstIndex()<<endl;
    cout<<endl;
    for ( i = -2; i < n+1; i++)
    {   cout<<++ra[i]<<" ";      
    }
    cout<<endl;
    for ( i = -2; i < n+1; i++)
    {   cout<<raCopy[i]<<" ";      
    }
    
    raCopy=ra;
    if (ra==raCopy)  cout<<"\n ra == raCopy";
    else cout<<"\n ra != raCopy";
    
	 
    ra[-2]=100;
    
    if (ra==raCopy)  cout<<"\n ra == raCopy";
    else cout<<"\n ra != raCopy";
    
    raCopy.push_back(ra);
    cout<<endl;
    int firstI=raCopy.firstIndex();
    for ( i = 0; i < raCopy.length() ; i++)
    {   cout<<raCopy[i+firstI ]<<" ";      
    }
    cout<<endl;
    raCopy.insert(-2,6);
    raCopy.insert(-1,7);
    cout<<raCopy;
    
    raCopy.remove();    
    cout<<endl;
    cout<<raCopy<<" remove()";
 
   
    raCopy.remove(-1);    
    cout<<endl;
    cout<<raCopy<<" remove(-1)";
    
    raCopy.remove(-1,1);    
    cout<<endl;
    cout<<raCopy<<" remove(-1,1)";

    ra=raCopy(-1,3);    
    cout<<endl;
    cout<<ra<<" raCopy(-1,3)";

    ra.swap(raCopy);    
    cout<<endl<<"ra.swap(raCopy)"<<endl;
    cout<<ra;
    cout<<endl;
    cout<<raCopy;

    double tmpx[100]={0};
    for(i=0;i<=2*n;i++) tmpx[i]=(i+0.1);

   cout<<endl<<"DynamicVector( T* const first, T* const last,int Vindex=0)";    
    DynamicVector<double> doubleVector1(&tmpx[1],&tmpx[n]);    
    cout<<"\n numofItems is "<<doubleVector1.length();
    cout<<"\n StartIndex is " <<doubleVector1.firstIndex();
    cout<<endl<<doubleVector1;
    
    
     DynamicVector<double> doubleVector2(doubleVector1.begin(),doubleVector1.end(),-3);     
     cout<<"\n numofItems is "<<doubleVector2.length();
    cout<<"\n StartIndex is " <<doubleVector2.firstIndex();
    cout<<endl<<doubleVector2;
  return 0;
}
//StudybarCommentEnd
