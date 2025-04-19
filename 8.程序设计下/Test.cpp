/*******************************************************************
*				名    称：学生成绩管理系统1.0                      *             
*				创建日期：2025-4-18                                *
*				最后修改：2025-4-18                                *
*				版    权：中国农业大学信息与电气工程学院           *
*				版 本 号：1.0 									   * 
*               Developed By Kevin                      		   *
*******************************************************************/


#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

#define N 20   //数组的长度
#define COURSEMAX 3 // 课程数量 

enum class Course : int{Chinese, Math, English};
void clearScreen();
/*******************************************************       
功能:显示菜单
参数：无				  
返回值：无
*******************************************************/
void displayMenu()
{
	
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout<<"+                 学生成绩管理系统                 +\n";
	cout<<"+                                                  +\n";
	cout<<"+                    1. 录入                       +\n";
	cout<<"+                    2. 输出                       +\n";
	cout<<"+                    3. 查询                       +\n";
	cout<<"+                    4. 排序                       +\n";
	cout<<"+                    5. 切换课程                   +\n";
	cout<<"+                    6. 结束                       +\n";
	cout<<"+                                                  +\n";
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	
}

/*******************************************************       
功能:登陆函数，验证口令
参数：
类型：char []
说明：用户输入口令					  
返回值：1或0
类型：int
说明：1表示通过验证；0表示没有通过
*******************************************************/
int login()
{
    char password[8];/*用户输入的口令*/
	static char key[8]="1234";
    int count = 0;
	int s=0;
	
    /*====验证用户的口令，如果三次输入均错误，则不允许进入系统====*/
	do
	{
		count++;
		cout<<"请输入口令：";
		gets(password);        
        if(strcmp(password,key)==0)
			s = 1;
        else
			s = 0;
	}while(s==0 && count<3); 
	clearScreen();
	cout<<" Reloading...\n";
	cout<<" 系统登录成功! \n";
	return s;
}


/*******************************************************       
功能:输入学生成绩到数组中
参数：
参数1：score[]
类型：int []
说明：学生成绩数组
参数2：length
类型：int 
说明：要输入的学生成绩数组的长度 
返回值：i
类型：int
说明：实际成绩数组的有效值个数
*******************************************************/
int inputScore(int score[],int length)
{
	int i=0;
	int tmp;
	
	cout<<"请输入学生的成绩（以-1结束输入):\n";
	do
	{
		cout<<"第"<<i+1<<"个学生：";
		cin>>tmp;
		if(tmp>=0&&tmp<=100)
		{
			score[i]=tmp;
			i++;
		}
    }while(tmp!=-1 && i<length);
	clearScreen();
	cout<<" 信息录入成功，本次录入"<<i<<"条数据! "<<endl;
	return i;
}
/*******************************************************       
功能:输出数组中的学生成绩
参数：
参数1：score[]
类型：int []
说明：学生成绩数组
参数2：length
类型：int 
说明：要输出的成绩数组的长度 
返回值：无
类型：void
说明：
*******************************************************/
void outputScore(int score[],int length)
{
	if(length <=0){
		cout<<" 信息为空! \n";
		return ;
	}
	int i=0;
	cout<<"学生成绩如下：\n";
	for(i=0;i<length;i++)
		cout<<i+1<<"\t"<<score[i]<<endl;
	cout<<"\n";
	return ;
}
/*******************************************************       
功能:查找某个学生成绩是否在数组中，如果找到，则输出下标，
否则，显示没有找到。
参数：
参数1：score[]
类型：int []
说明：学生成绩数组
参数2：length
类型：int 
说明：要输入的学生成绩数组的长度 
参数2：xScore
类型：int 
说明：要查找的学生成绩 
返回值：k
类型：int
说明：
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
功能:排序学生的成绩，按照从小到大顺序排序。
参数：
参数1：score[]
类型：int []
说明：学生成绩数组
参数2：length
类型：int 
说明：要输入的学生成绩数组的长度 
返回值：无
类型：void
说明：
*******************************************************/
void sortScore(int score[ ], int length)
{
	int i, j, t;
	clearScreen();	
	cout<<"成绩排序如下：\n";
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
	cout << "请输入课程编号（0=Chinese, 1=Math, 2=English）: ";
	int input;
	while(1){
		cin>>input;
		if (input >= 0 && input <= 2) {
	        Course course = static_cast<Course>(input);
	        switch (course) {
	        	clearScreen();
	            case Course::Chinese:
	                std::cout << " 已切换到课程：语文" << std::endl;
	                break;
	            case Course::Math:
	                std::cout << " 已切换到课程：数学" << std::endl;
	                break;
	            case Course::English:
	                std::cout << " 已切换到课程：英语" << std::endl;
	                break;
	        }
	        break;
	    } else {
	        std::cerr << " 输入无效！请重新输入：";
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
功能:主函数
参数：无				  
返回值：无
*******************************************************/
int main()
{
    int choice = 0; /*代表用户选择的操作数字 */
    int s=0,datalen=0,x,find;
    // 课程成绩数组 
    int *course[COURSEMAX];
    for (int i = 0; i < COURSEMAX; i++) {
        course[i] = (int *)malloc(sizeof(int)*N);  // 动态分配内存
    }
    	
     /*====验证用户的口令====*/
	if (login( ) == 0) 
	{
		cout<<" 口令错误，不允许进入本系统!\n";
		exit( 0 );
	}
	
    /*====根据用户的选择，执行相应的操作.====*/
    Course input = Course::Chinese;
    while(1)
    {	
		displayMenu();
		cout << "\n 当前课程: ";
		switch (input) {
            case Course::Chinese:
                std::cout << "语文" << std::endl;
                break;
            case Course::Math:
                std::cout << "数学" << std::endl;
                break;
            case Course::English:
                std::cout << "英语" << std::endl;
                break;
        }
        
		cout<<"\n 请选择您的操作(1,2,3,4,5,6)：\n";
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
			cout<<"\n 请输入要查找的成绩：";
			cin>>x;
			find=queryScore(course[i],datalen,x);
			if(find>=0)
				cout<<"要查成绩在数组中的下标为:"<<find<<endl;
			else 
				cout<<"没有要查找的成绩:\n";
			break;
		case 4:
			sortScore(course[i],datalen);
			outputScore(course[i],datalen);
			break;
		case 5:
			input = switchCourse();
			break;
		case 6:
			cout<<" 正在退出成绩管理系统,请稍后..."<<endl;
			Sleep(500); 
			
			// 释放内存
			for (int i = 0; i < COURSEMAX; i++) {
        		free(course[i]);  // 动态分配内存
    		} 
			exit(0);
		default:
			printf(" 选择错误，请重新选择!\n"); 
        }
    }
    return 0;
}
