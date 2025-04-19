/*******************************************************************
*				��    �ƣ�ѧ���ɼ�����ϵͳ1.0                      *             
*				�������ڣ�2025-4-18                                *
*				����޸ģ�2025-4-18                                *
*				��    Ȩ���й�ũҵ��ѧ��Ϣ���������ѧԺ           *
*				�� �� �ţ�1.0 									   * 
*               Developed By Kevin                      		   *
*******************************************************************/


#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

class Score; 
#define N 20   //����ĳ���
#define COURSEMAX 3 // �γ����� 

enum class Course : int{Chinese, Math, English};

class Score{
private:
	int score[N];
	int dataSize;
//	Course course;
public:
	Score():dataSize(0){}

	int inputScore();// �ɼ�����
	void outputScore();// �ɼ����
	int queryScore(int xScore); // �ɼ���ѯ
	void sortScore(); // �ɼ����� 
	
	//��̬��Ա����
	static Course switchCourse(); // �γ��л�
	static int login(); // ��¼
	static void displayMenu(); // ���˵�
	static void clearScreen(); // �������� 
};

/*******************************************************       
����:��ʾ�˵�
��������				  
����ֵ����
*******************************************************/
void Score::displayMenu()
{
	
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout<<"+                 ѧ���ɼ�����ϵͳ                 +\n";
	cout<<"+                                                  +\n";
	cout<<"+                    1. ¼��                       +\n";
	cout<<"+                    2. ���                       +\n";
	cout<<"+                    3. ��ѯ                       +\n";
	cout<<"+                    4. ����                       +\n";
	cout<<"+                    5. �л��γ�                   +\n";
	cout<<"+                    6. ����                       +\n";
	cout<<"+                                                  +\n";
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	
}

/*******************************************************       
����:��½��������֤����
������
���ͣ�char []
˵�����û��������					  
����ֵ��1��0
���ͣ�int
˵����1��ʾͨ����֤��0��ʾû��ͨ��
*******************************************************/
int Score::login()
{
    char password[8];/*�û�����Ŀ���*/
	static char key[8]="1234";
    int count = 0;
	int s=0;
	
    /*====��֤�û��Ŀ���������������������������ϵͳ====*/
	do
	{
		count++;
		cout<<"��������";
		gets(password);        
        if(strcmp(password,key)==0)
			s = 1;
        else
			s = 0;
	}while(s==0 && count<3); 
	clearScreen();
	cout<<" Reloading...\n";
	Sleep(500); 
	cout<<" ϵͳ��¼�ɹ�! \n";
	return s;
}

/*******************************************************       
����:����ѧ���ɼ���������
������
����1��score[]
���ͣ�int []
˵����ѧ���ɼ�����
����2��length
���ͣ�int 
˵����Ҫ�����ѧ���ɼ�����ĳ��� 
����ֵ��i
���ͣ�int
˵����ʵ�ʳɼ��������Чֵ����
*******************************************************/
int Score::inputScore()
{
	int i=0;
	int tmp;
	
	cout<<"������ѧ���ĳɼ�����-1��������):\n";
	do
	{
		cout<<"��"<<i+1<<"��ѧ����";
		cin>>tmp;
		if(tmp>=0&&tmp<=100)
		{
			score[i]=tmp;
			i++;
		}
    }while(tmp!=-1 && i<N);
	clearScreen();
	cout<<" ��Ϣ¼��ɹ�������¼��"<<i<<"������! "<<endl;
	dataSize = i; 
	return dataSize;
}
/*******************************************************       
����:��������е�ѧ���ɼ�
������
����1��score[]
���ͣ�int []
˵����ѧ���ɼ�����
����2��length
���ͣ�int 
˵����Ҫ����ĳɼ�����ĳ��� 
����ֵ����
���ͣ�void
˵����
*******************************************************/
void Score::outputScore()
{
	if(dataSize <=0){
		cout<<" ��ϢΪ��! \n";
		return ;
	}
	int i=0;
	cout<<"ѧ���ɼ����£�\n";
	for(i=0;i<dataSize;i++)
		cout<<i+1<<"\t"<<score[i]<<endl;
	cout<<"\n";
	return ;
}
/*******************************************************       
����:����ĳ��ѧ���ɼ��Ƿ��������У�����ҵ���������±꣬
������ʾû���ҵ���
������
����1��score[]
���ͣ�int []
˵����ѧ���ɼ�����
����2��length
���ͣ�int 
˵����Ҫ�����ѧ���ɼ�����ĳ��� 
����2��xScore
���ͣ�int 
˵����Ҫ���ҵ�ѧ���ɼ� 
����ֵ��k
���ͣ�int
˵����
*******************************************************/
int Score::queryScore(int xScore)
{
	int i;
	
	for(i=0;i<dataSize;i++)
	{
		if(xScore==score[i])
        {
		   return i;
        }
    }
    return -1;
}

/*******************************************************       
����:����ѧ���ĳɼ������մ�С����˳������
������
����1��score[]
���ͣ�int []
˵����ѧ���ɼ�����
����2��length
���ͣ�int 
˵����Ҫ�����ѧ���ɼ�����ĳ��� 
����ֵ����
���ͣ�void
˵����
*******************************************************/
void Score::sortScore()
{
	int i, j, t;
	clearScreen();	
	cout<<"�ɼ��������£�\n";
	for(i = 0; i < dataSize - 1; i++)
	{
		for(j = 0; j < dataSize - i - 1; j++)
			if(score[ j ]>score[ j + 1 ])
			{
				t = score[ j ];
				score[ j ] = score[ j + 1 ];
				score[ j + 1 ] = t;
			}
	}
}
Course Score::switchCourse(){
	cout << "������γ̱�ţ�0=Chinese, 1=Math, 2=English��: ";
	int input;
	while(1){
		cin>>input;
		if (input >= 0 && input <= 2) {
	        Course course = static_cast<Course>(input);
	        clearScreen();
	        switch (course) {
	            case Course::Chinese:
	                std::cout << " ���л����γ̣�����" << std::endl;
	                break;
	            case Course::Math:
	                std::cout << " ���л����γ̣���ѧ" << std::endl;
	                break;
	            case Course::English:
	                std::cout << " ���л����γ̣�Ӣ��" << std::endl;
	                break;
	        }
	        break;
	    } else {
	        std::cerr << " ������Ч�����������룺";
	    }
	}
	
	return static_cast<Course>(input);
}

void Score::clearScreen() {
    #ifdef _WIN32
        system("cls");   // Windows
    #else
        system("clear"); // Linux/macOS
    #endif
}

/*******************************************************       
����:������
��������				  
����ֵ����
*******************************************************/
int main()
{
    int choice = 0; /*�����û�ѡ��Ĳ������� */
    int s=0,datalen=0,x,find;
    // �γ̳ɼ����� 
	Score course[COURSEMAX];
    	
     /*====��֤�û��Ŀ���====*/
	if (Score::login( ) == 0) 
	{
		cout<<" ������󣬲�������뱾ϵͳ!\n";
		exit( 0 );
	}
	
    /*====�����û���ѡ��ִ����Ӧ�Ĳ���.====*/
    Course input = Course::Chinese;
    while(1)
    {	
		Score::displayMenu();
		cout << "\n ��ǰ�γ�: ";
		switch (input) {
            case Course::Chinese:
                std::cout << "����" << std::endl;
                break;
            case Course::Math:
                std::cout << "��ѧ" << std::endl;
                break;
            case Course::English:
                std::cout << "Ӣ��" << std::endl;
                break;
        }
        
		cout<<"\n ��ѡ�����Ĳ���(1,2,3,4,5,6)��\n";
        cin>>choice;
		int i = static_cast<int>(input);
        switch(choice)
        {
		case 1:
			datalen=course[i].inputScore();
			break;
		case 2:
			Score::clearScreen();
			course[i].outputScore();
			break;
		case 3: 
			cout<<"\n ������Ҫ���ҵĳɼ���";
			cin>>x;
			find=course[i].queryScore(x);
			if(find>=0)
				cout<<"Ҫ��ɼ��������е��±�Ϊ:"<<find<<endl;
			else 
				cout<<"û��Ҫ���ҵĳɼ�:\n";
			break;
		case 4:
			course[i].sortScore();
			course[i].outputScore();
			break;
		case 5:
			input = Score::switchCourse();
			break;
		case 6:
			cout<<" �����˳��ɼ�����ϵͳ,���Ժ�..."<<endl;
			Sleep(500); 
			
			exit(0);
		default:
			printf(" ѡ�����������ѡ��!\n"); 
        }
    }
    return 0;
}
