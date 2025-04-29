#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <stdexcept>  // ����쳣ͷ�ļ�
using namespace std;

class Student {
private:
    int id;
    string name;
    double score;
    
public:
    Student(int i = 0, string n = "", double s = 0.0) 
        : id(i), name(n), score(s) {}

    string serialize() const {
        stringstream ss;
        ss << id << "|" << name << "|" << fixed << setprecision(1) << score;
        return ss.str();
    }

    void deserialize(const string& data) {
        if (data.empty()) {
            throw invalid_argument("�������޷�����");
        }
        
        vector<string> parts;
        stringstream ss(data);
        string part;
        
        while (getline(ss, part, '|')) {
            parts.push_back(part);
        }
        
        if (parts.size() != 3) {
            throw invalid_argument("���ݸ�ʽ����: " + data);
        }
        
        try {
            id = stoi(parts[0]);
        } catch (...) {
            throw invalid_argument("��Ч��ID: " + parts[0]);
        }
        
        name = parts[1];
        
        try {
            score = stod(parts[2]);
        } catch (...) {
            throw invalid_argument("��Ч�ķ���: " + parts[2]);
        }
    }

    void display() const {
        cout << "ID: " << id << "\tName: " << setw(15) << left << name 
             << "\tScore: " << score << endl;
    }
    
    double getScore() const { return score; }
    void updateScore(double newScore) { score = newScore; }
};

class FileManager {
private:
    fstream file;
    const string filename = "students.dat";
    
public:
    FileManager() {
        file.open(filename, ios::in | ios::out | ios::binary | ios::ate);
        if (!file) {
            file.open(filename, ios::out);
            file.close();
            file.open(filename, ios::in | ios::out | ios::binary | ios::ate);
        }
    }

    ~FileManager() { file.close(); }

    void append(const Student& s) {
        string data = s.serialize() + "\n";
        file.seekp(0, ios::end);
        file.write(data.c_str(), data.size());
        file.flush();
    }

    Student readAt(int pos) {
        vector<string> records;
        string line;
        
        file.seekg(0);
        while (getline(file, line)) {
            if (!line.empty()) {
                records.push_back(line);
            }
        }
        
        if (pos < 0 || pos >= records.size()) {
            cerr << "��Ч��λ��! ��Ч��Χ: 0-" << records.size()-1 << endl;
            return Student();
        }
        
        try {
            Student s;
            s.deserialize(records[pos]);
            return s;
        } catch (const invalid_argument& e) {
            cerr << "����: " << e.what() << endl;
            return Student();
        }
    }

    // �޸����һ����¼���޸���λ���⣩
    void updateLastRecord() {
        streampos endPos;
        file.seekg(0, ios::end);
        endPos = file.tellg();
        
        if(endPos == 0) {  // ���ļ�
            cerr << "�ļ�Ϊ��!" << endl;
            return;
        }

        // �������һ����¼����ʼλ��
        streampos startPos = endPos;
        char ch;
        do {
            file.seekg(-1, ios::cur);
            startPos = file.tellg();
            file.get(ch);
        } while(ch != '\n' && startPos > 0);

        // ��ȡ��¼
        file.seekg(startPos + (ch == '\n' ? 1 : 0));
        string line;
        getline(file, line);
        
        // �޸Ĳ�д��
        Student s;
        s.deserialize(line);
        s.updateScore(s.getScore() + 5.0);
        
        string newData = s.serialize() + "\n";
        file.seekp(startPos + (ch == '\n' ? 1 : 0));
        file.write(newData.c_str(), newData.size());
    }

    // ��ʾ���м�¼
    void displayAll() {
        file.seekg(0, ios::beg);
        string line;
        cout << "\n===== ���м�¼ =====" << endl;
        while(getline(file, line)) {
            Student s;
            s.deserialize(line);
            s.display();
        }
        file.clear();  // ������ܵ�eof״̬
    }
};

int main() {
	FileManager fm;
    try {
        fm.append(Student(1001, "Alice Cooper", 85.5));
    	fm.append(Student(1002, "Bob Marley", 92.0));
    	fm.append(Student(1003, "Charlie Parker", 78.5));
        
        cout << "===== ���Զ�ȡ =====" << endl;
    	Student s = fm.readAt(0);
    	s.display();
    } catch (const exception& e) {
        cerr << "�����쳣: " << e.what() << endl;
    }
    // �޸����һ����¼
    fm.updateLastRecord();
    
    // ��ʾȫ����¼
    fm.displayAll();
    return 0;
}
