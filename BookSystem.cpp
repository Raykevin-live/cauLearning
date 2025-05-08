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
        cout << "����ͼ���ţ�";
        cin >> id;
        cout << "����ͼ�����ƣ�";
        cin.ignore();
        cin.getline(title, 50);
        cout << "����ͼ��۸�";
        cin >> price;
    }

    string format() const {
        stringstream ss;
        ss << "ͼ���ţ�" << id << "\nͼ�����ƣ�" << title 
           << "\nͼ��۸�" << fixed << setprecision(2) << price;
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
            cout << "��¼��ӳɹ���" << endl;
        } else {
            cerr << "д��ʧ�ܣ�" << endl;
        }
    }

    void readRecord(int pos) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "�ļ������ڣ�" << endl;
            return;
        }

        inFile.seekg((pos-1)*sizeof(Book));
        Book b;
        if (inFile.read(reinterpret_cast<char*>(&b), sizeof(Book))) {
            cout << b.format() << endl;
        } else {
            cerr << "��¼�����ڣ�" << endl;
        }
    }

    void modifyPrice(int pos, float newPrice) {
        fstream file(filename, ios::binary | ios::in | ios::out);
        if (!file) {
            cerr << "�ļ������ڣ�" << endl;
            return;
        }

        file.seekg((pos-1)*sizeof(Book));
        Book b;
        if (file.read(reinterpret_cast<char*>(&b), sizeof(Book))) {
            b.price = newPrice;
            file.seekp((pos-1)*sizeof(Book));
            file.write(reinterpret_cast<char*>(&b), sizeof(Book));
            cout << "�޸ĳɹ���" << endl;
        } else {
            cerr << "��¼�����ڣ�" << endl;
        }
    }

    void displayAll() {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "�ļ������ڣ�" << endl;
            return;
        }

        Book b;
        int counter = 0;
        while (inFile.read(reinterpret_cast<char*>(&b), sizeof(Book))) {
            cout << "��¼#" << ++counter << "\n" 
                 << b.format() << "\n\n";
        }

        if (counter == 0) {
            cout << "û�м�¼��" << endl;
        }
    }

    void searchBooks(const string& keyword) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "�ļ������ڣ�" << endl;
            return;
        }

        Book b;
        int counter = 0;
        while (inFile.read(reinterpret_cast<char*>(&b), sizeof(Book))) {
            stringstream ss;
            ss << b.id << b.title;
            string bookInfo = ss.str();
            if (bookInfo.find(keyword) != string::npos) {
                cout << "��¼#" << ++counter << "\n" 
                     << b.format() << "\n\n";
            }
        }

        if (counter == 0) {
            cout << "δ�ҵ�ƥ���ͼ���¼��" << endl;
        }
    }
};

class MenuSystem {
    BookFileManager manager;
    
    void showMenu() {
        cout << "\n=== ͼ�����ϵͳ ==="
             << "\n1. ��Ӽ�¼"
             << "\n2. ��ȡ��¼"
             << "\n3. �޸ļ۸�"
             << "\n4. ��ʾȫ��"
             << "\n5. ����ͼ��"
             << "\n0. �˳�ϵͳ"
             << "\n������ѡ��";
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
                    cout << "�����¼λ�ã�";
                    cin >> pos;
                    manager.readRecord(pos);
                    break;
                }
                case 3: {
                    int pos;
                    float price;
                    cout << "�����¼λ�ã�";
                    cin >> pos;
                    cout << "�����¼۸�";
                    cin >> price;
                    manager.modifyPrice(pos, price);
                    break;
                }
                case 4: 
                    manager.displayAll();
                    break;
                case 5: {
                    string keyword;
                    cout << "���������ؼ��ʣ�";
                    getline(cin, keyword);
                    manager.searchBooks(keyword);
                    break;
                }
                case 0: 
                    cout << "ϵͳ���˳���" << endl;
                    break;
                default: 
                    cerr << "��Чѡ�" << endl;
            }
        } while (choice != 0);
    }
};

int main() {
    MenuSystem system;
    system.run();
    return 0;
}    
