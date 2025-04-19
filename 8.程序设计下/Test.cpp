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

#define N 20   //����ĳ���
#define COURSEMAX 3 // �γ����� 

enum class Course : int{Chinese, Math, English};
void clearScreen();
/*******************************************************       
����:��ʾ�˵�
��������				  
����ֵ����
*******************************************************/
void displayMenu()
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
int login()
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
int inputScore(int score[],int length)
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
    }while(tmp!=-1 && i<length);
	clearScreen();
	cout<<" ��Ϣ¼��ɹ�������¼��"<<i<<"������! "<<endl;
	return i;
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
void outputScore(int score[],int length)
{
	if(length <=0){
		cout<<" ��ϢΪ��! \n";
		return ;
	}
	int i=0;
	cout<<"ѧ���ɼ����£�\n";
	for(i=0;i<length;i++)
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
int queryScore(int score[],int length,int xScore)
{
	int i;
	
	for(i=0;i<length;i++)
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
void sortScore(int score[ ], int length)
{
	int i, j, t;
	clearScreen();	
	cout<<"�ɼ��������£�\n";
	for(i = 0; i < length - 1; i++)
	{
		for(j = 0; j < length - i - 1; j++)
			if(score[ j ]>score[ j + 1 ])
			{
				t = score[ j ];
				score[ j ] = score[ j + 1 ];
				score[ j + 1 ] = t;
			}
	}
}
Course switchCourse(){
	cout << "������γ̱�ţ�0=Chinese, 1=Math, 2=English��: ";
	int input;
	while(1){
		cin>>input;
		if (input >= 0 && input <= 2) {
	        Course course = static_cast<Course>(input);
	        switch (course) {
	        	clearScreen();
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

void clearScreen() {
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
    int *course[COURSEMAX];
    for (int i = 0; i < COURSEMAX; i++) {
        course[i] = (int *)malloc(sizeof(int)*N);  // ��̬�����ڴ�
    }
    	
     /*====��֤�û��Ŀ���====*/
	if (login( ) == 0) 
	{
		cout<<" ������󣬲�������뱾ϵͳ!\n";
		exit( 0 );
	}
	
    /*====�����û���ѡ��ִ����Ӧ�Ĳ���.====*/
    Course input = Course::Chinese;
    while(1)
    {	
		displayMenu();
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
			datalen=inputScore(course[i],N);
			break;
		case 2:
			outputScore(course[i],datalen);
			break;
		case 3: 
			cout<<"\n ������Ҫ���ҵĳɼ���";
			cin>>x;
			find=queryScore(course[i],datalen,x);
			if(find>=0)
				cout<<"Ҫ��ɼ��������е��±�Ϊ:"<<find<<endl;
			else 
				cout<<"û��Ҫ���ҵĳɼ�:\n";
			break;
		case 4:
			sortScore(course[i],datalen);
			outputScore(course[i],datalen);
			break;
		case 5:
			input = switchCourse();
			break;
		case 6:
			cout<<" �����˳��ɼ�����ϵͳ,���Ժ�..."<<endl;
			Sleep(500); 
			
			// �ͷ��ڴ�
			for (int i = 0; i < COURSEMAX; i++) {
        		free(course[i]);  // ��̬�����ڴ�
    		} 
			exit(0);
		default:
			printf(" ѡ�����������ѡ��!\n"); 
        }
    }
    return 0;
}
