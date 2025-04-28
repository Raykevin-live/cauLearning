//StudybarCommentBegin
//����ǰ׺��������û��ϵ�����ǰ׺�Ĺ����Ǹ���׼�����Զ����ļ��ģ����רע����Ҫ��ɵĺ������ܼ��ɡ�
#include <cstdio>      // ��� #include <stdio.h>
#include <windows.h>    // Windows API������ԭ��
#include <Urlmon.h>     // URL ���� API������ԭ��
#include <ctime>        // ��� #include <time.h>
#include <iostream>     // C++ ��׼���������
#include <fstream>      // C++ �ļ���
using namespace std;
#pragma comment(lib, "urlmon.lib") 

class  CurlDownloadFile
{
private:
	char filename[1000];
	char url[1000];
	int res;
public:
	CurlDownloadFile(char *inurl,char *infilename){
		srand(time(0));
    	sprintf(filename,"%s",infilename);
		//printf(filename);
	    sprintf(url,"%s?id=%u",inurl,rand());	
		//printf(url);
		res = URLDownloadToFile(NULL, url  , filename, 0, NULL);
		if(res != S_OK) {
			printf("%s open and saveto %s error!",url,filename);
			exit(0);
		}

	}
	~CurlDownloadFile()
	{
		DeleteFile(filename);
	}
};

void file_read_dosomething(char *filename);  //��д�ú���
//StudybarCommentEnd
#include <sstream>
void file_read_dosomething(char *filename){
	fstream file(filename);
	int lineCount = 0, wordsCount = 0;
	char str[1000];
	
	while(file.getline(str, 1000, '\n')){
		lineCount++;
		stringstream ss(str);
		string word;
		while(ss>>word) wordsCount++;
	}
	cout<<wordsCount<<","<<lineCount<<endl;
}
//StudybarCommentBegin
int main()
{
	CurlDownloadFile  mydownloadfile("http://vm.cau.edu.cn/~zlh/test1.txt","data.txt");

	file_read_dosomething("data.txt");
    return 0;

}
//StudybarCommentEnd
