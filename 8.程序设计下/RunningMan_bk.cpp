#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

#define COLOR_STATUS 116   // ��װ���
#define COLOR_BODY   224   // ��׺���
#define COLOR_LEGS   160   // ��׺���

class Human {
protected:
    char* name;
    char sex;
    int age;

public:
    Human(const char* n = "����1", char s = 'M', int a = 0);
    Human(const Human& other);
    virtual ~Human();

    virtual void speak();
    void speak(const char* content);
    virtual void show();

    friend std::ostream& operator<<(std::ostream& os, const Human& h);
};

class RunningScore {
private:
    float* scores;
    int scoreCount;

public:
    RunningScore();
    ~RunningScore();

    void addScore(float score);
    float getAverage() const;
    void showScores() const;
    RunningScore& operator+=(float score);
};

class RunningHuman : public Human {
private:
    int energy;
    int runSpeed;
    int runDistance;
    RunningScore scoreSystem;

    void updateEnergy();
    void displayFigure(int t) const;
	void drawRunner(int pos, int frame) const;
    void printSpaces(int count) const;
    void setColor(int color)const;
	void resetColor()const;
public:
    RunningHuman(const char* n = "����1", char s = 'M', int a = 0);
    RunningHuman& operator+=(float score);

    void speak() override;
    void show() override;
    void run();
    void manageScores();
    void displayMenu();
};

// Human��ʵ��
Human::Human(const char* n, char s, int a) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    sex = s;
    age = a;
}

Human::Human(const Human& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    sex = other.sex;
    age = other.age;
}

Human::~Human() {
    delete[] name;
}

void Human::speak() {
    system("cls");
    std::cout << "===== �������� =====" << std::endl;
    std::cout << "����" << name << "������" << age << "�꣬�Ա�" 
            << (sex == 'M' ? "��" : "Ů") << "��" << std::endl;
}

void Human::speak(const char* content) {
    std::cout << name << "˵��" << content << std::endl;
}

void Human::show() {
    std::cout << "������" << name << std::endl
            << "�Ա�" << (sex == 'M' ? "��" : "Ů") << std::endl
            << "���䣺" << age << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Human& h) {
    os << "��������Ϣ��" << std::endl
        << "������" << h.name << std::endl
        << "�Ա�" << (h.sex == 'M' ? "��" : "Ů") << std::endl
        << "���䣺" << h.age;
    return os;
}

// RunningScore��ʵ��
RunningScore::RunningScore() : scores(nullptr), scoreCount(0) {}

RunningScore::~RunningScore() {
    if(scores) delete[] scores;
}

void RunningScore::addScore(float score) {
    float* newScores = new float[scoreCount + 1];
    for(int i=0; i<scoreCount; i++)
        newScores[i] = scores[i];
    newScores[scoreCount] = score;
    
    delete[] scores;
    scores = newScores;
    scoreCount++;
}

float RunningScore::getAverage() const {
    if(scoreCount == 0) return 0;
    float sum = 0;
    for(int i=0; i<scoreCount; i++)
        sum += scores[i];
    return sum / scoreCount;
}

void RunningScore::showScores() const {
    if(scoreCount == 0) {
        std::cout << "���޳ɼ���¼" << std::endl;
        return;
    }
    std::cout << "���гɼ���";
    for(int i=0; i<scoreCount; i++)
        std::cout << scores[i] << " ";
    std::cout << "\nƽ���֣�" << getAverage() << std::endl;
}

RunningScore& RunningScore::operator+=(float score) {
    addScore(score);
    return *this;
}

// RunningHuman��ʵ��
RunningHuman::RunningHuman(const char* n, char s, int a) 
    : Human(n, s, a) {
    energy = 100;
    runSpeed = 200;
    runDistance = 0;
}

void RunningHuman::updateEnergy() {
    energy = std::min(100, 50 + static_cast<int>(scoreSystem.getAverage()/2));
}

void RunningHuman::setColor(int color) const{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void RunningHuman::resetColor() const{
    setColor(7); // �ָ�Ĭ�ϻҵ׺���
}

void RunningHuman::displayFigure(int t) const {
    system("cls");
    const int animFrame = t % 4;  

    setColor(COLOR_STATUS);
    std::cout << " " << name << " ?" << energy 
              << " ����:" << runDistance + t << "��";
    if(scoreSystem.getAverage() > 0) {
        std::cout << " �ٶ�+" << (200 - runSpeed)/2 << "%";
    }
    std::cout << " [Q�˳�]";
    resetColor();

    int pos = t % 70;
    drawRunner(pos, animFrame);
}

void RunningHuman::drawRunner(int pos, int frame) const {
	if(energy < 30) {
	    setColor(79); // ��װ�����˸
	    std::cout << " ! ";
	    resetColor();
	}
    // ͷ�� 
    setColor(10); // ����ɫ
    printSpaces(pos);
    std::cout << "  O\n";

    // ������ֱ�
    setColor(12); // ����ɫ
    printSpaces(pos);
    switch(frame % 2) {
        case 0: std::cout << " /|\\\n"; break;
        case 1: std::cout << " -|-\n"; break;
    }

    // �Ȳ�
    setColor(14); // ��ɫ
    printSpaces(pos);
    switch(frame % 2) {
        case 0: std::cout << " / \\\n"; break;
        case 1: std::cout << " | |\n"; break;
    }
    resetColor();
}

void RunningHuman::printSpaces(int count) const {
    for(int i=0; i<count%70; ++i) 
        std::cout << ' ';
}

RunningHuman& RunningHuman::operator+=(float score) {
    if(score >=0 && score <=100) {
        scoreSystem += score;
        updateEnergy();
    } else {
        std::cout << "��Ч�ɼ���";
    }
    return *this;
}

void RunningHuman::speak() {
    Human::speak();
    std::cout << "��ǰ������" << energy << std::endl
            << "�ۼƱ��ܾ��룺" << runDistance << "��" << std::endl
            << "ƽ���ɼ���" << scoreSystem.getAverage() << std::endl;
}

void RunningHuman::show() {
    Human::show();
    std::cout << "������" << energy << std::endl
            << "���ܾ��룺" << runDistance << "��" << std::endl;
    scoreSystem.showScores();
}

void RunningHuman::run() {
    int t = 0;
    bool running = true;
    int baseSpeed = std::max(50, static_cast<int>(200 - scoreSystem.getAverage()/2));
    
    while(running && t<1000 && energy>0) {
        displayFigure(t);
        runSpeed = baseSpeed + (100 - energy)/2;
        Sleep(runSpeed);
        
        if(_kbhit()) {
            char key = _getch();
            if(key == 'q' || key == 'Q') running = false;
        }
        
        t++;
        energy = std::max(0, energy-1);
    }
    
    runDistance += t;
    system("cls");
    std::cout << "���α��ܾ��룺" << t << "��\nʣ��������" << energy << std::endl;
}

void RunningHuman::manageScores() {
    int choice;
    do {
        system("cls");
        std::cout << "===== �ɼ����� =====" << std::endl;
        std::cout << "1. ��ӳɼ�\n2. �鿴�ɼ�\n3. ����\n��ѡ��";
        std::cin >> choice;
        
        switch(choice) {
            case 1: {
                float score;
                std::cout << "����ɼ�(0-100): ";
                std::cin >> score;
                if(score >=0 && score <=100) {
                    scoreSystem += score;
                    updateEnergy();
                    std::cout << "��ӳɹ�����ǰƽ����" << scoreSystem.getAverage() << std::endl;
                } else {
                    std::cout << "��Ч�ɼ���";
                }
                system("pause");
                break;
            }
            case 2:
                scoreSystem.showScores();
                system("pause");
                break;
        }
    } while(choice != 3);
}

void RunningHuman::displayMenu() {
    int choice;
    do {
        system("cls");
        std::cout << "===== ���˵� =====" << std::endl;
        std::cout << "1. ���ҽ���\n2. �ɼ�����\n3. ��ʼ����\n4. �˳�\n��ѡ��";
        std::cin >> choice;
        
        switch(choice) {
            case 1: 
                speak();
                system("pause");
                break;
            case 2:
                manageScores();
                break;
            case 3:
                run();
                system("pause");
                break;
        }
    } while(choice != 4);
}

int main() {
    srand(time(NULL));
    
    RunningHuman runner("�˶�����", 'M', 20);
    runner += 85.5f;  
    runner += 92.0f;
    
    runner.displayMenu();
    
    std::cout << " ϵͳ�����˳�..." << std::endl;
    Sleep(500); 
    return 0;
}  
