#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

#define COLOR_STATUS 116   // 青底白字
#define COLOR_BODY   224   // 红底黑字
#define COLOR_LEGS   160   // 红底黑字

class Human {
protected:
    char* name;
    char sex;
    int age;

public:
    Human(const char* n = "达人1", char s = 'M', int a = 0);
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
    RunningHuman(const char* n = "达人1", char s = 'M', int a = 0);
    RunningHuman& operator+=(float score);

    void speak() override;
    void show() override;
    void run();
    void manageScores();
    void displayMenu();
};

// Human类实现
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
    std::cout << "===== 基本介绍 =====" << std::endl;
    std::cout << "我是" << name << "，今年" << age << "岁，性别" 
            << (sex == 'M' ? "男" : "女") << "。" << std::endl;
}

void Human::speak(const char* content) {
    std::cout << name << "说：" << content << std::endl;
}

void Human::show() {
    std::cout << "姓名：" << name << std::endl
            << "性别：" << (sex == 'M' ? "男" : "女") << std::endl
            << "年龄：" << age << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Human& h) {
    os << "【基本信息】" << std::endl
        << "姓名：" << h.name << std::endl
        << "性别：" << (h.sex == 'M' ? "男" : "女") << std::endl
        << "年龄：" << h.age;
    return os;
}

// RunningScore类实现
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
        std::cout << "暂无成绩记录" << std::endl;
        return;
    }
    std::cout << "所有成绩：";
    for(int i=0; i<scoreCount; i++)
        std::cout << scores[i] << " ";
    std::cout << "\n平均分：" << getAverage() << std::endl;
}

RunningScore& RunningScore::operator+=(float score) {
    addScore(score);
    return *this;
}

// RunningHuman类实现
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
    setColor(7); // 恢复默认灰底黑字
}

void RunningHuman::displayFigure(int t) const {
    system("cls");
    const int animFrame = t % 4;  

    setColor(COLOR_STATUS);
    std::cout << " " << name << " ?" << energy 
              << " 距离:" << runDistance + t << "米";
    if(scoreSystem.getAverage() > 0) {
        std::cout << " 速度+" << (200 - runSpeed)/2 << "%";
    }
    std::cout << " [Q退出]";
    resetColor();

    int pos = t % 70;
    drawRunner(pos, animFrame);
}

void RunningHuman::drawRunner(int pos, int frame) const {
	if(energy < 30) {
	    setColor(79); // 红底白字闪烁
	    std::cout << " ! ";
	    resetColor();
	}
    // 头部 
    setColor(10); // 亮绿色
    printSpaces(pos);
    std::cout << "  O\n";

    // 身体和手臂
    setColor(12); // 亮红色
    printSpaces(pos);
    switch(frame % 2) {
        case 0: std::cout << " /|\\\n"; break;
        case 1: std::cout << " -|-\n"; break;
    }

    // 腿部
    setColor(14); // 黄色
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
        std::cout << "无效成绩！";
    }
    return *this;
}

void RunningHuman::speak() {
    Human::speak();
    std::cout << "当前体力：" << energy << std::endl
            << "累计奔跑距离：" << runDistance << "米" << std::endl
            << "平均成绩：" << scoreSystem.getAverage() << std::endl;
}

void RunningHuman::show() {
    Human::show();
    std::cout << "体力：" << energy << std::endl
            << "奔跑距离：" << runDistance << "米" << std::endl;
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
    std::cout << "本次奔跑距离：" << t << "米\n剩余体力：" << energy << std::endl;
}

void RunningHuman::manageScores() {
    int choice;
    do {
        system("cls");
        std::cout << "===== 成绩管理 =====" << std::endl;
        std::cout << "1. 添加成绩\n2. 查看成绩\n3. 返回\n请选择：";
        std::cin >> choice;
        
        switch(choice) {
            case 1: {
                float score;
                std::cout << "输入成绩(0-100): ";
                std::cin >> score;
                if(score >=0 && score <=100) {
                    scoreSystem += score;
                    updateEnergy();
                    std::cout << "添加成功！当前平均：" << scoreSystem.getAverage() << std::endl;
                } else {
                    std::cout << "无效成绩！";
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
        std::cout << "===== 主菜单 =====" << std::endl;
        std::cout << "1. 自我介绍\n2. 成绩管理\n3. 开始奔跑\n4. 退出\n请选择：";
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
    
    RunningHuman runner("运动达人", 'M', 20);
    runner += 85.5f;  
    runner += 92.0f;
    
    runner.displayMenu();
    
    std::cout << " 系统即将退出..." << std::endl;
    Sleep(500); 
    return 0;
}  
