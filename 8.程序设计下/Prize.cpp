#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <conio.h> 
#include <windows.h>
#include <stdio.h>
int main(){
	FILE* fp = fopen("data.txt", "r");
	if(fp == NULL) return -1;
	char buffer[10][20] = {'\0'};
	for(int i=0; i<10; i++){
		fgets(buffer[i], sizeof(buffer[i]), fp);
		size_t len = strcspn(buffer[i], "\n");
    	buffer[i][len] = '\0';
    	std::cout<<buffer[i]<<std::endl;
	}
	
	fclose(fp);
	return 0;
}
//using namespace std;
//
//class Prize {
//protected:
//    string name;
//    int total;
//    vector<string> winners;
//public:
//    Prize(const string& n, int t) : name(n), total(t) {}
//    virtual ~Prize() {}
//    
//    bool canDraw() const { return winners.size() < total; }
//    void addWinner(const string& num) { winners.push_back(num); }
//    void showWinners() const {
//        cout << name << "获奖者：" << endl;
//        for (const auto& w : winners) cout << w << endl;
//    }
//    int remain() const { return total - winners.size(); }
//    const string& getName() const { return name; }
//};
//
//class FirstPrize : public Prize {
//public:
//    FirstPrize() : Prize("一等奖", 1) {}
//};
//
//class SecondPrize : public Prize {
//public:
//    SecondPrize() : Prize("二等奖", 2) {}
//};
//
//class ThirdPrize : public Prize {
//public:
//    ThirdPrize() : Prize("三等奖", 5) {}
//};
//
//class MenuSystem {
//private:
//    vector<string> participants;
//    set<string> drawnNumbers;
//    FirstPrize fp;
//    SecondPrize sp;
//    ThirdPrize tp;
//    
//    vector<string> loadParticipants(const string& filename) {
//        vector<string> nums;
//        ifstream infile(filename);
//        string line;
//        while (getline(infile, line)) {
//            nums.push_back(line);
//        }
//        return nums;
//    }
//    
//	void moveCursorToLine(int line) {// 移动光标到指定行
//	    std::cout << "\033[" << line << ";0H";
//	}
//	void refreshLines(const std::vector<std::string>& contents) {
//	    std::cout << "\033[s"; // 保存光标位置
//	    for (size_t i = 0; i < contents.size(); ++i) {
//	        moveCursorToLine(i + 1);   // 第i行
//	        std::cout << "\033[K" << contents[i]; // 清行+输出
//	    }
//	    std::cout << "\033[u"; // 恢复光标位置
//	    std::cout.flush();
//	}
//	void printRandom(Prize& pr, int n){
//		string name = pr.getName()+": ";
//		for(int i=0; i<n; i++){
//			vector<string> content{name};
//			int index = rand()%10;
//			content.push_back(participants[index]);
//			Sleep(30);
//			refreshLines(content);
//		}
//	}
//    string drawRandom() {
//        vector<string> available;
//        for (const auto& p : participants) {
//            if (drawnNumbers.find(p) == drawnNumbers.end())
//                available.push_back(p);
//        }
//        if (available.empty()) return "";
//        
//        int idx = rand() % available.size();
//        drawnNumbers.insert(available[idx]);
//        return available[idx];
//    }
//
//public:
//    MenuSystem(const char* file) {
//        participants = loadParticipants(file);
//        srand(time(NULL));
//    }
//
//    void startDrawing() {
//        cout << "\n按任意键开始抽奖..." << endl;
//        _getch();
//        printRandom(fp, 10);
//        while (fp.canDraw()) {
//            string winner = drawRandom();
//            fp.addWinner(winner);
//            system("cls");
//            cout << fp.getName() << ": " << winner << endl;
//        }
//        cout << "\n按任意键开始抽奖..." << endl;
//        _getch();
//        system("cls");
//        printRandom(sp, 15);
//        while(sp.canDraw()) {
//            string winner = drawRandom();
//            sp.addWinner(winner);
//            cout << sp.getName() << ": " << winner << endl;
//        }
//        
//        cout << "\n按任意键开始抽奖..." << endl;
//        _getch();
//        system("cls");
//        printRandom(tp, 20);
//        while (tp.canDraw()) {
//            string winner = drawRandom();
//            tp.addWinner(winner);
//            cout << tp.getName() << ": " << winner << endl;
//        }
//        
//		cout << "\n按任意键查看结果..." << endl;
//		_getch();
//        system("cls");
//        cout<<"  结果汇总中...\n";
//        Sleep(500);
//        cout << "\n=== 抽奖结果 ===" << endl;
//        fp.showWinners();
//        cout<<"\n";
//        sp.showWinners();
//        cout<<"\n";
//        tp.showWinners();
//    }
//};
//
//int main() {
//    MenuSystem ms("data.txt");
//    ms.startDrawing();
//    return 0;
//}
