#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <sstream>
using namespace std;

#define FILENAME "students.dat"
struct Student {
    int id;          // 4�ֽ�
    char name[20];   // 20�ֽ�
    double score;    // 8�ֽ�

    Student(int i = 0, const char* n = "", double s = 0.0) 
        : id(i), score(s) {
        strncpy(name, n, 19);
        name[19] = '\0';
    }
};

void createTestFile() {
    ofstream fout(FILENAME, ios::binary);
    Student students[] = {
        {1, "Alice", 90.5},
        {2, "Bob", 85.0},
        {3, "Charlie", 92.3}
    };
    fout.write(reinterpret_cast<char*>(students), sizeof(students));
}

void displayRecord(int pos) {
    ifstream fin(FILENAME, ios::binary);
    fin.seekg(pos * sizeof(Student));
    
    Student s;
    fin.read(reinterpret_cast<char*>(&s), sizeof(Student));
    
    cout << "��¼λ�ã�" << pos 
         << "\nѧ�ţ�" << s.id
         << "\n������" << s.name
         << "\n�ɼ���" << fixed << setprecision(1) << s.score
         << "\n�ļ�ָ��λ�ã�0x" << hex << fin.tellg() 
         << endl;
}

void updateScore(int pos, double newScore) {
    fstream fs(FILENAME, ios::binary | ios::in | ios::out);
    fs.seekp(pos * sizeof(Student) + offsetof(Student, score));
    fs.write(reinterpret_cast<char*>(&newScore), sizeof(double));
}

void displayAll() {
    ifstream fin(FILENAME, ios::binary);
    Student s;
    
    cout << "\n��ǰ�ļ����ݣ�" << endl;
    while(fin.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        cout << "[0x" << hex << fin.tellg() - sizeof(Student) << "]" 
             << dec << s.id << " " << s.name << " " << s.score << endl;
    }
}

int main() {
    createTestFile();
    
    
    cout << "--- ���������ʾ ---" << endl;
    displayRecord(0);  
    displayRecord(2);  
    
    cout << "\n--- �޸ļ�¼��ʾ ---" << endl;
    updateScore(1, 88.5); 
    displayAll();
    
    cout << "\n--- �ַ��������� ---" << endl;
    string input = "4 David 95.5";
    istringstream iss(input);
    
    Student s;
    iss >> s.id >> s.name >> s.score;
    
    cout << "���������" << s.id << " " << s.name << " " << s.score << endl;
}
