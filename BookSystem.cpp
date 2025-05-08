#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

class Book {
public:
    int id;
    char title[50];
    float price;

    void input() {
        cout << "输入图书编号：";
        cin >> id;
        cout << "输入图书名称：";
        cin.ignore();
        cin.getline(title, 50);
        cout << "输入图书价格：";
        cin >> price;
    }

    string format() const {
        stringstream ss;
        ss << "图书编号：" << id << "\n图书名称：" << title 
           << "\n图书价格：" << fixed << setprecision(2) << price;
        return ss.str();
    }
};

class BookFileManager {
    string filename;
    
public:
    BookFileManager(const string& fname) : filename(fname) {}

    void addRecord() {
        ofstream outFile(filename, ios::binary | ios::app);
        Book b;
        b.input();
        
        if (outFile.write(reinterpret_cast<char*>(&b), sizeof(Book))) {
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

        inFile.seekg((pos-1)*sizeof(Book));
        Book b;
        if (inFile.read(reinterpret_cast<char*>(&b), sizeof(Book))) {
            cout << b.format() << endl;
        } else {
            cerr << "记录不存在！" << endl;
        }
    }

    void modifyPrice(int pos, float newPrice) {
        fstream file(filename, ios::binary | ios::in | ios::out);
        if (!file) {
            cerr << "文件不存在！" << endl;
            return;
        }

        file.seekg((pos-1)*sizeof(Book));
        Book b;
        if (file.read(reinterpret_cast<char*>(&b), sizeof(Book))) {
            b.price = newPrice;
            file.seekp((pos-1)*sizeof(Book));
            file.write(reinterpret_cast<char*>(&b), sizeof(Book));
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

        Book b;
        int counter = 0;
        while (inFile.read(reinterpret_cast<char*>(&b), sizeof(Book))) {
            cout << "记录#" << ++counter << "\n" 
                 << b.format() << "\n\n";
        }

        if (counter == 0) {
            cout << "没有记录！" << endl;
        }
    }

    void searchBooks(const string& keyword) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "文件不存在！" << endl;
            return;
        }

        Book b;
        int counter = 0;
        while (inFile.read(reinterpret_cast<char*>(&b), sizeof(Book))) {
            stringstream ss;
            ss << b.id << b.title;
            string bookInfo = ss.str();
            if (bookInfo.find(keyword) != string::npos) {
                cout << "记录#" << ++counter << "\n" 
                     << b.format() << "\n\n";
            }
        }

        if (counter == 0) {
            cout << "未找到匹配的图书记录！" << endl;
        }
    }
};

class MenuSystem {
    BookFileManager manager;
    
    void showMenu() {
        cout << "\n=== 图书管理系统 ==="
             << "\n1. 添加记录"
             << "\n2. 读取记录"
             << "\n3. 修改价格"
             << "\n4. 显示全部"
             << "\n5. 搜索图书"
             << "\n0. 退出系统"
             << "\n请输入选择：";
    }

public:
    MenuSystem() : manager("books.dat") {}

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
                    float price;
                    cout << "输入记录位置：";
                    cin >> pos;
                    cout << "输入新价格：";
                    cin >> price;
                    manager.modifyPrice(pos, price);
                    break;
                }
                case 4: 
                    manager.displayAll();
                    break;
                case 5: {
                    string keyword;
                    cout << "输入搜索关键词：";
                    getline(cin, keyword);
                    manager.searchBooks(keyword);
                    break;
                }
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
