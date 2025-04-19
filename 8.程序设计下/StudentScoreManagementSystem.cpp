/*******************************************************************
*				名    称：学生成绩管理系统1.0                         *             
*				创建日期：2025-4-18                                 *
*				最后修改：2025-4-18                                *
*				版    权：中国农业大学信息与电气工程学院           *
*				版 本 号：1.0                                      *
*******************************************************************/

#include <iostream>
#include <cstring>
#include <limits>
#include <cstdlib>
#include <windows.h>
using namespace std;

#define N 20   //数组的长度


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
	cout<<"+                    5. 结束                       +\n";
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
	
	return s;
}

// 学生成绩类  
class Score {
private:
    int scores[N];  // 成绩数组，最大长度N
    int scoresCount;      // 已经存储的成绩数量 

public:
    // 构造函数，初始化datalen为0
    Score(int maxSize = N) : scoresCount(0) {}  // 保持与N的兼容性

    // 录入成绩，返回实际输入的个数
    int inputScore() {
        scoresCount = 0;
        int tmp;
        cout << "请输入学生的成绩（以-1结束输入）：\n";
        while (scoresCount < 20) {
            cout << "第" << scoresCount + 1 << "个学生：";
            cin >> tmp;
            if (tmp == -1) break;
            if (tmp >= 0 && tmp <= 100) {
                scores[scoresCount] = tmp;
                scoresCount++;
            } else {
                cout << "无效成绩，请重新输入（0-100或-1结束）。\n";
            }
        }
        return scoresCount;
    }

    // 输出成绩
    void outputScore() const {
        cout << "学生成绩如下：\n";
        for (int i = 0; i < scoresCount; i++) {
            cout << i + 1 << "\t" << scores[i] << endl;
        }
    }

    // 查询成绩，返回下标或-1
    int queryScore(int xScore) const {
        for (int i = 0; i < scoresCount; i++) {
            if (scores[i] == xScore) return i;
        }
        return -1;
    }

    // 升序排序成绩
    void sortScore() {
        for (int i = 0; i < scoresCount - 1; i++) {
            for (int j = 0; j < scoresCount - i - 1; j++) {
                if (scores[j] > scores[j + 1]) {
                    swap(scores[j], scores[j + 1]);
                }
            }
        }
    }
};

/*******************************************************       
功能:主函数
参数：无				  
返回值：无
*******************************************************/
int main() 
{
    const int COURSE_COUNT = 3;  // 课程数量
    int currentCourse = 0;       // 当前课程索引
    int choice = 0, x, find;
    Score courses[COURSE_COUNT]; // 对象数组
    
    /*====验证用户的口令====*/
    if(login() == 0) 
    {
        cout<<"口令错误，不允许进入本系统!\n";
        exit(0);
    }

    /*====主操作循环====*/
    while(1)
    {
        cout << "\n当前课程: " << currentCourse+1 << "/" << COURSE_COUNT << endl;
        displayMenu();
        cout<<"\n 请选择您的操作(1-6)：\n";
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除输入缓冲

        switch(choice)
        {
        case 1:
            courses[currentCourse].inputScore();
            break;
        case 2:
            courses[currentCourse].outputScore();
            break;
        case 3: 
            cout<<"\n 请输入要查找的成绩：";
            cin>>x;
            find = courses[currentCourse].queryScore(x);
            if(find >= 0)
                cout<<"成绩所在位置:"<<find<<endl;
            else 
                cout<<"未找到该成绩\n";
            break;
        case 4:
            courses[currentCourse].sortScore();
            courses[currentCourse].outputScore();
            break;
        case 5:  
            cout << "输入目标课程编号(1-" << COURSE_COUNT << "): ";
            int newCourse;
            cin >> newCourse;
            if(newCourse >=1 && newCourse <= COURSE_COUNT) {
                currentCourse = newCourse - 1;
                cout << "已切换到课程" << newCourse << endl;
            } else {
                cout << "无效的课程编号！" << endl;
            }
            break;
        case 6:  // 退出系统
        	cout<<"即将退出系统，请稍后..."<<endl;
        	Sleep(500);
            exit(0);
        default:
            cout << "无效操作！" << endl;
        }
    }
    return 0;
}
