#include <iostream>
#include<iomanip>
#include<cmath>

using namespace std;


class Cassemblage{
private:
	int _array[1000];
	int _count;
public:
	Cassemblage(const int* array, int count){
		for(int i=0; i<count; i++){
			_array[i] = array[i];
		}
		_count = count;
	}
};


//StudybarCommentBegin
int main(int argc, char* argv[])
{
	Cassemblage z1, z2, x1, x2, x3;
	int i, n1, n2, a1[1000], a2[1000];
	
	cin >> n1;
	for(i=0; i<n1; i++)
	{
		cin >> a1[i];
	}
    z1.Set(a1, n1);
	cin >> n2;
	for(i=0; i<n2; i++)
	{
		cin >> a2[i];
	}	
	z2.Set(a2, n2);

	x1=z1+z2;
	x1.Show();
	cout << endl;

	x2=z1&z2;
	x2.Show();
	cout << endl;

	x3=z1-z2;
	x3.Show();


	return 0;
}

//StudybarCommentEnd
