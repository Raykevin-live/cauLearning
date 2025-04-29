#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Student {
public:
    int id;
    char name[20];
    float score;

    void input() {
        cout << "输入学号：";
        cin >> id;
        cout << "输入姓名：";
        cin.ignore();
        cin.getline(name, 20);
        cout << "输入成绩：";
        cin >> score;
    }

    string format() const {
        stringstream ss;
        ss << "学号：" << id << "\n姓名：" << name 
           << "\n成绩：" << fixed << setprecision(1) << score;
        return ss.str();
    }
};

class StudentFileManager {
    string filename;
    
public:
    StudentFileManager(const string& fname) : filename(fname) {}

    void addRecord() {
        ofstream outFile(filename, ios::binary | ios::app);
        Student s;
        s.input();
        
        if (outFile.write(reinterpret_cast<char*>(&s), sizeof(Student))) {
            cout << "记录添加成功！" << endl;
        } else {
            cerr << "写入失败！" << endl;
        }
    }

    void readRecord(int pos) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "文件不存在！" << endl;
            return;
        }

        inFile.seekg((pos-1)*sizeof(Student));
        Student s;
        if (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            cout << s.format() << endl;
        } else {
            cerr << "记录不存在！" << endl;
        }
    }

    void modifyScore(int pos, float newScore) {
        fstream file(filename, ios::binary | ios::in | ios::out);
        if (!file) {
            cerr << "文件不存在！" << endl;
            return;
        }

        file.seekg((pos-1)*sizeof(Student));
        Student s;
        if (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            s.score = newScore;
            file.seekp((pos-1)*sizeof(Student));
            file.write(reinterpret_cast<char*>(&s), sizeof(Student));
            cout << "修改成功！" << endl;
        } else {
            cerr << "记录不存在！" << endl;
        }
    }

    void displayAll() {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "文件不存在！" << endl;
            return;
        }

        Student s;
        int counter = 0;
        while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            cout << "记录#" << ++counter << "\n" 
                 << s.format() << "\n\n";
        }

        if (counter == 0) {
            cout << "没有记录！" << endl;
        }
    }
};

class MenuSystem {
    StudentFileManager manager;
    
    void showMenu() {
        cout << "\n=== 学生管理系统 ==="
             << "\n1. 添加记录"
             << "\n2. 读取记录"
             << "\n3. 修改成绩"
             << "\n4. 显示全部"
             << "\n0. 退出系统"
             << "\n请输入选择：";
    }

public:
    MenuSystem() : manager("students.dat") {}

    void run() {
        int choice;
        do {
            showMenu();
            cin >> choice;
            cin.ignore();

            switch(choice) {
                case 1: 
                    manager.addRecord();
                    break;
                case 2: {
                    int pos;
                    cout << "输入记录位置：";
                    cin >> pos;
                    manager.readRecord(pos);
                    break;
                }
                case 3: {
                    int pos;
                    float score;
                    cout << "输入记录位置：";
                    cin >> pos;
                    cout << "输入新成绩：";
                    cin >> score;
                    manager.modifyScore(pos, score);
                    break;
                }
                case 4: 
                    manager.displayAll();
                    break;
                case 0: 
                    cout << "系统已退出！" << endl;
                    break;
                default: 
                    cerr << "无效选项！" << endl;
            }
        } while (choice != 0);
    }
};

int main() {
    MenuSystem system;
    system.run();
    return 0;
}
