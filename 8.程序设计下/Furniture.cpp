//StudybarCommentBegin
#include<iostream>
using namespace std;
class Furniture
{protected:	int weight;
 public:
		void setWeight(int w)
		{weight=w;}	
};
//StudybarCommentEnd
class Sofa:virtual public Furniture{
public:
	void sitting();	
};
class Bed:virtual public Furniture{
public:
	void sleeping();	
};
class Sofabed:public Sofa, public Bed{
public:
	void watchTv();
};
//StudybarCommentBegin
 void Sofa::sitting()
{ cout <<weight<<"sitting on chair...\n"; }	
void Bed::sleeping()
{ cout <<weight<<"sleeping ...\n"; }
void Sofabed::watchTv()
{ cout <<weight<<"watching TV...\n"; }
int  main()
{	Sofabed s;  
	s.setWeight(12);
	s.sitting();
	s.watchTv();
	s.sleeping();	
	return 0;
}
//StudybarCommentEnd
