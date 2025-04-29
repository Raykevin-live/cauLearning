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
        cout << "����ѧ�ţ�";
        cin >> id;
        cout << "����������";
        cin.ignore();
        cin.getline(name, 20);
        cout << "����ɼ���";
        cin >> score;
    }

    string format() const {
        stringstream ss;
        ss << "ѧ�ţ�" << id << "\n������" << name 
           << "\n�ɼ���" << fixed << setprecision(1) << score;
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

        inFile.seekg((pos-1)*sizeof(Student));
        Student s;
        if (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            cout << s.format() << endl;
        } else {
            cerr << "��¼�����ڣ�" << endl;
        }
    }

    void modifyScore(int pos, float newScore) {
        fstream file(filename, ios::binary | ios::in | ios::out);
        if (!file) {
            cerr << "�ļ������ڣ�" << endl;
            return;
        }

        file.seekg((pos-1)*sizeof(Student));
        Student s;
        if (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            s.score = newScore;
            file.seekp((pos-1)*sizeof(Student));
            file.write(reinterpret_cast<char*>(&s), sizeof(Student));
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

        Student s;
        int counter = 0;
        while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            cout << "��¼#" << ++counter << "\n" 
                 << s.format() << "\n\n";
        }

        if (counter == 0) {
            cout << "û�м�¼��" << endl;
        }
    }
};

class MenuSystem {
    StudentFileManager manager;
    
    void showMenu() {
        cout << "\n=== ѧ������ϵͳ ==="
             << "\n1. ��Ӽ�¼"
             << "\n2. ��ȡ��¼"
             << "\n3. �޸ĳɼ�"
             << "\n4. ��ʾȫ��"
             << "\n0. �˳�ϵͳ"
             << "\n������ѡ��";
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
                    cout << "�����¼λ�ã�";
                    cin >> pos;
                    manager.readRecord(pos);
                    break;
                }
                case 3: {
                    int pos;
                    float score;
                    cout << "�����¼λ�ã�";
                    cin >> pos;
                    cout << "�����³ɼ���";
                    cin >> score;
                    manager.modifyScore(pos, score);
                    break;
                }
                case 4: 
                    manager.displayAll();
                    break;
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
