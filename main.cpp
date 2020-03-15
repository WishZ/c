#include <iostream>
#include <cmath>

using namespace std;

class Point {//Point类定义
public:
    Point(int xx = 0, int yy = 0):x(xx),y(yy) {
        count++;
    }

    ~Point() {
        cout << "析构函数";
        count--;
    }

    Point(Point &p) {
        x = p.x;
        y = p.y;
        count++;
    };

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
    static void showCount() {
        cout << " Object count = "<< count <<endl;
    }

private:
    int x, y;
    static int count;
};

//类的组合
class Line { //Line的类定义
public:
    Line(Point xp1, Point xp2);

    Line(Line &l);

    double getLen() {
        return len;
    }

private:
    Point p1, p2;//Point类的对象p1,p2
    double len;
};

//组合类的构造函数
Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {
    cout << "调用Line类的构造函数\n";
    double x = static_cast<double>(p1.getX() - p2.getX());
    double y = static_cast<double>(p1.getY() - p2.getY());
    len = sqrt(x * x + y * y);
}

Line::Line(Line &l) : p1(l.p1), p2(l.p2) {//组合类的复制构造函数
    cout << "调用了Line的复制构造函数\n";
    len = l.len;
}

//结合体
struct Student {
    int age;
    string name;
    char sex;
    int num;
};
//联合体  成员公用同一组内存单元  任何两个成员不会同时有效

class ExamInfo {
private:
    string name;
    enum {
        GRADE, PASS, PERCENTAGE
    } mode;
    union {
        char grade;
        bool pass;
        int percent;
    };
public:
    ExamInfo(string name, char grade) : name(name), mode(GRADE), grade(grade) {}

    ExamInfo(string name, bool pass) : name(name), mode(PASS), pass(pass) {}

    ExamInfo(string name, int percent) : name(name), mode(PERCENTAGE), percent(percent) {}

    void show();
};

void ExamInfo::show() {
    cout << name << ":";
    switch (mode) {
        case GRADE:
            cout << grade;
            break;
        case PASS:
            cout << (pass ? "PASS" : "FAIL");
            break;
        case PERCENTAGE:
            cout << percent;
            break;
    }
    cout << endl;
}

enum class Side {
    Right, left
};
enum class Thing {
    Wrong, Right
};

void other() {
    static int a=2;//静态变量 全局寿命 局部可见  声明后 不会再次初始化  只有第一次进入函数时初始化
    int c = 2; //局部变量 动态生存期  每次进入函数都初始化
}
int Point::count = 0;
int main() {
    Point::showCount();
    Point a(4,5);
    cout << "Point A:"<<a.getX()<<", "<< a.getY();
    Point::showCount();

    Point b(a);
    cout << "Point B:"<< b.getX()<<","<<b.getY();
    Point::showCount();

    Side s = Side::Right;
    Thing t = Thing::Right;
    ExamInfo course1("英语", 'B');
    ExamInfo course2("数学", true);
    ExamInfo course3("C++", 85);
    course1.show();
    course2.show();
    course3.show();
    Student stu = {19, "张三", 'F', 22};
    cout << stu.age << endl;
    Point myP1(1, 1), myP2(4, 5);
    Line line(myP1, myP2);
    Line line2(line);
    cout << "line的长度是：";
    cout << line.getLen() << endl;
    cout << "line2的长度是：";
    cout << line2.getLen() << endl;
    return 0;
}