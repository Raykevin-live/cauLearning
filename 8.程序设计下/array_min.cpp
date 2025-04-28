//StudybarCommentBegin
#include<iostream>
using namespace std;
//StudybarCommentEnd

#include <vector>
#include <algorithm>
template<class T, int N>
class array_min{
private:
	vector<T> array;
public:
	void add(T x){
		cin>>x;
		array.push_back(x);
	}
	void print_min(){
		sort(array.begin(), array.end());
		cout<<array[0];
	}
};

//StudybarCommentBegin
int main(void)
{
    int i;
	array_min <int, 4>  array1;
	array_min <double, 5>  array2;
	for (i = 0; i<4; i++)
	{
		array1.add(i);
	}
	for (i = 0; i<5; i++)
	{
		array2.add(i);
	}
	array1.print_min();
	cout << endl;
	array2.print_min();
	cout << endl;
        return 1;
}
//StudybarCommentEnd
