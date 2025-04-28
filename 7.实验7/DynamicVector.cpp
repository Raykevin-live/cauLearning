#include <iostream>

using namespace std;

#define SIZE 4

template <class T>
class DynamicVector
{
	T* array; // pointer to the items ָ�����ռ��ָ��
	unsigned mallocSize; // number of allocated spaces ����ռ�Ĵ�С
	unsigned numofItems; // number of items �������Ѿ��洢��Ԫ������
	int virtualZero; // virtual zero ������ʼ�±꣬C������ͨ�������±��Ǵ�0��ʼ�� ����������Կ�����������±��-10��2�ȵ�������ʼ �������������

public:
	DynamicVector (int );  
	
	~DynamicVector();   //��Ҫ����
	
	inline void push_back (const T&); //��Ҫ����
	void push_back (const DynamicVector&);
	
	T& operator[] (int Vindex); 
	
	unsigned length() const;
	
	unsigned capacity() const;
	
	int firstIndex() const;
};

template <class T>
DynamicVector<T>::DynamicVector(int Vindex)
{
	array = NULL;
	numofItems = 0;
	mallocSize = 0;
	virtualZero = Vindex;
}
template <class T>
DynamicVector<T>::~DynamicVector(){
	delete []array;
	array = nullptr; 
} 
template <class T>
T& DynamicVector<T>::operator[] (int Vindex)
{
	int _entry = Vindex - virtualZero;
	if (_entry < 0 || _entry >= numofItems)
	{
	cout<<endl<<"Out Of Range";
	exit(1);
	}
	return array[_entry];
}
template <class T>
inline void DynamicVector<T>::push_back (const T& x){
	if (numofItems >= mallocSize) {
        unsigned newSize = (mallocSize == 0) ? SIZE : mallocSize * 2;
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
void DynamicVector<T>::push_back(const DynamicVector& other){
	 for (unsigned i = 0; i < other.numofItems; ++i) {
        this->push_back(other.array[i]);
    }
} 
template <class T>
unsigned DynamicVector<T>::length() const
{
	return numofItems;
}

template <class T>
unsigned DynamicVector<T>::capacity() const
{
	return this->mallocSize-1;
}

template <class T>
int DynamicVector<T>::firstIndex() const
{
	return this->virtualZero;
}


//StudybarCommentBegin
int main()
{
 
    DynamicVector<int> ra(-2);
    int i,n;
    cin>>n;
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
    ra[-2]=100;
    raCopy.push_back(ra);
    cout<<endl;
    int firstI=raCopy.firstIndex();
    for ( i = 0; i < raCopy.length() ; i++)
    {   cout<<raCopy[i+firstI ]<<" ";      
    }
    
 
  return 0;
}
//StudybarCommentEnd
