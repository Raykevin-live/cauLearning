#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//using c Language 
//int main(){
//	srand(time(NULL));
//	const char* pre = "1871";
//	FILE*  fp = fopen("data.txt", "w+");
//	// ������Ϣ 
//	for(int i=0; i<10; i++){
//		fwrite(pre, sizeof(char), strlen(pre), fp);
//		for(int j=0; j<7; j++){
//			char tmp = rand()%10 + '0';
//			fwrite(&tmp, sizeof(char), 1, fp);
//		}
//		char tmp = '\n';
//		fwrite(&tmp, sizeof(char), 1, fp);
//	}
//	//��ȡ
//	 
//	fclose(fp);
//	return 0;
//}
//
//using namespace std;
//int main(){
//	srand(time(NULL));
//	ofstream outfile;
//	outfile.open("data.txt", ios::out|ios::trunc);
//	if(!outfile){
//		return -1;
//	}
//	for(int i=0; i<10; i++){
//		string num = "1871";
//		for(int i=0; i<7; i++){
//			num += (rand()%10+'0');
//		}
//		outfile<<num;
//		outfile<<"\n";
//	}
//	outfile.close();
//	return 0;
//}
//
//using namespace std;
//int main(){
//	srand(time(NULL));
//	ofstream outfile;
//	outfile.open("data.txt", ios::out|ios::trunc);
//	if(!outfile){
//		return -1;
//	}
//	for(int i=0; i<10; i++){
//		string num = "1871";
//		for(int i=0; i<7; i++){
//			num += (rand()%10+'0');
//		}
//		outfile.write(num.c_str(), num.size());
//		outfile<<"\n";
//	}
//	outfile.close();
//	return 0;
//}

//int main(){
//	
//	int i = 0;
//	char bar[102];
//	memset(bar, 0 ,sizeof(bar));
//	const char *lable="|/-\\";
//	while(i <= 100 ){
//		printf("��ʼ��");
//		printf("[%-100s][%d%%][%c]\r", bar, i, lable[i%4]);
//		fflush(stdout);
//		bar[i++] = '#';
//		Sleep(10);
//	}
//	printf("\n");
//
//	return 0;
//}

#include <iostream>
#include <unistd.h> 

#include <iostream>
#include <vector>
using namespace std;
// �ƶ���굽ָ����
void moveCursorToLine(int line) {
    std::cout << "\033[" << line << ";0H";
}

void refreshLines(const std::vector<std::string>& contents) {
    std::cout << "\033[s"; // ������λ��
    
    for (size_t i = 0; i < contents.size(); ++i) {
        moveCursorToLine(i + 1);   // ��i��
        std::cout << "\033[K" << contents[i]; // ����+���
    }
    
    std::cout << "\033[u"; // �ָ����λ��
    std::cout.flush();
}

int main() {
    // ��ʼ����ʾ
    std::cout << "CPU ʹ����: \n�ڴ�ռ��: \n�����ٶ�: \n";

    // ģ�⶯̬����
    vector<vector<string>> lines = {
    	{
        "CPU ʹ����: 35%",
        "�ڴ�ռ��: 2.8/8GB",
        "�����ٶ�: ��1.2MB/s ��0.8MB/s"},
        {
        "CPU ʹ����: 45%",
        "�ڴ�ռ��: 2.8/8GB",
        "�����ٶ�: ��1.2MB/s ��0.8MB/s"},
        {
        "CPU ʹ����: 55%",
        "�ڴ�ռ��: 2.8/8GB",
        "�����ٶ�: ��1.2MB/s ��0.8MB/s"}
    };
    for(int i=0; i<3; i++){
    	Sleep(500);
    	refreshLines(lines[i]);
	}
    
    
    return 0;
}






