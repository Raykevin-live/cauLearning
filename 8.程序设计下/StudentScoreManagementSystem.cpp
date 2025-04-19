/*******************************************************************
*				��    �ƣ�ѧ���ɼ�����ϵͳ1.0                         *             
*				�������ڣ�2025-4-18                                 *
*				����޸ģ�2025-4-18                                *
*				��    Ȩ���й�ũҵ��ѧ��Ϣ���������ѧԺ           *
*				�� �� �ţ�1.0                                      *
*******************************************************************/

#include <iostream>
#include <cstring>
#include <limits>
#include <cstdlib>
#include <windows.h>
using namespace std;

#define N 20   //����ĳ���


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
	cout<<"+                    5. ����                       +\n";
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
	
	return s;
}

// ѧ���ɼ���  
class Score {
private:
    int scores[N];  // �ɼ����飬��󳤶�N
    int scoresCount;      // �Ѿ��洢�ĳɼ����� 

public:
    // ���캯������ʼ��datalenΪ0
    Score(int maxSize = N) : scoresCount(0) {}  // ������N�ļ�����

    // ¼��ɼ�������ʵ������ĸ���
    int inputScore() {
        scoresCount = 0;
        int tmp;
        cout << "������ѧ���ĳɼ�����-1�������룩��\n";
        while (scoresCount < 20) {
            cout << "��" << scoresCount + 1 << "��ѧ����";
            cin >> tmp;
            if (tmp == -1) break;
            if (tmp >= 0 && tmp <= 100) {
                scores[scoresCount] = tmp;
                scoresCount++;
            } else {
                cout << "��Ч�ɼ������������루0-100��-1��������\n";
            }
        }
        return scoresCount;
    }

    // ����ɼ�
    void outputScore() const {
        cout << "ѧ���ɼ����£�\n";
        for (int i = 0; i < scoresCount; i++) {
            cout << i + 1 << "\t" << scores[i] << endl;
        }
    }

    // ��ѯ�ɼ��������±��-1
    int queryScore(int xScore) const {
        for (int i = 0; i < scoresCount; i++) {
            if (scores[i] == xScore) return i;
        }
        return -1;
    }

    // ��������ɼ�
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
����:������
��������				  
����ֵ����
*******************************************************/
int main() 
{
    const int COURSE_COUNT = 3;  // �γ�����
    int currentCourse = 0;       // ��ǰ�γ�����
    int choice = 0, x, find;
    Score courses[COURSE_COUNT]; // ��������
    
    /*====��֤�û��Ŀ���====*/
    if(login() == 0) 
    {
        cout<<"������󣬲�������뱾ϵͳ!\n";
        exit(0);
    }

    /*====������ѭ��====*/
    while(1)
    {
        cout << "\n��ǰ�γ�: " << currentCourse+1 << "/" << COURSE_COUNT << endl;
        displayMenu();
        cout<<"\n ��ѡ�����Ĳ���(1-6)��\n";
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������뻺��

        switch(choice)
        {
        case 1:
            courses[currentCourse].inputScore();
            break;
        case 2:
            courses[currentCourse].outputScore();
            break;
        case 3: 
            cout<<"\n ������Ҫ���ҵĳɼ���";
            cin>>x;
            find = courses[currentCourse].queryScore(x);
            if(find >= 0)
                cout<<"�ɼ�����λ��:"<<find<<endl;
            else 
                cout<<"δ�ҵ��óɼ�\n";
            break;
        case 4:
            courses[currentCourse].sortScore();
            courses[currentCourse].outputScore();
            break;
        case 5:  
            cout << "����Ŀ��γ̱��(1-" << COURSE_COUNT << "): ";
            int newCourse;
            cin >> newCourse;
            if(newCourse >=1 && newCourse <= COURSE_COUNT) {
                currentCourse = newCourse - 1;
                cout << "���л����γ�" << newCourse << endl;
            } else {
                cout << "��Ч�Ŀγ̱�ţ�" << endl;
            }
            break;
        case 6:  // �˳�ϵͳ
        	cout<<"�����˳�ϵͳ�����Ժ�..."<<endl;
        	Sleep(500);
            exit(0);
        default:
            cout << "��Ч������" << endl;
        }
    }
    return 0;
}
