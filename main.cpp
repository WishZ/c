#include <iostream>
#include <cmath>

using namespace std;

class Point {//Point�ඨ��
public:
    Point(int xx = 0, int yy = 0):x(xx),y(yy) {
        count++;
    }

    ~Point() {
        cout << "��������";
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

//������
class Line { //Line���ඨ��
public:
    Line(Point xp1, Point xp2);

    Line(Line &l);

    double getLen() {
        return len;
    }

private:
    Point p1, p2;//Point��Ķ���p1,p2
    double len;
};

//�����Ĺ��캯��
Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {
    cout << "����Line��Ĺ��캯��\n";
    double x = static_cast<double>(p1.getX() - p2.getX());
    double y = static_cast<double>(p1.getY() - p2.getY());
    len = sqrt(x * x + y * y);
}

Line::Line(Line &l) : p1(l.p1), p2(l.p2) {//�����ĸ��ƹ��캯��
    cout << "������Line�ĸ��ƹ��캯��\n";
    len = l.len;
}

//�����
struct Student {
    int age;
    string name;
    char sex;
    int num;
};
//������  ��Ա����ͬһ���ڴ浥Ԫ  �κ�������Ա����ͬʱ��Ч

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
    static int a=2;//��̬���� ȫ������ �ֲ��ɼ�  ������ �����ٴγ�ʼ��  ֻ�е�һ�ν��뺯��ʱ��ʼ��
    int c = 2; //�ֲ����� ��̬������  ÿ�ν��뺯������ʼ��
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
    ExamInfo course1("Ӣ��", 'B');
    ExamInfo course2("��ѧ", true);
    ExamInfo course3("C++", 85);
    course1.show();
    course2.show();
    course3.show();
    Student stu = {19, "����", 'F', 22};
    cout << stu.age << endl;
    Point myP1(1, 1), myP2(4, 5);
    Line line(myP1, myP2);
    Line line2(line);
    cout << "line�ĳ����ǣ�";
    cout << line.getLen() << endl;
    cout << "line2�ĳ����ǣ�";
    cout << line2.getLen() << endl;
    return 0;
}