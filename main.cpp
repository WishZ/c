#include <iostream>
#include <cmath>

using namespace std;

class Point {//Point类定义
public:
    Point(int xx = 0, int yy = 0) {
        x = xx;
        y = yy;
    }

    Point(Point &p);

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

private:
    int x, y;
};

Point::Point(Point &p) {//复制构造函数的事项
    x = p.x;
    y = p.y;
    cout << "调用了Point的复制构造函数\n";
}

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

int main() {
    Point myP1(1, 1), myP2(4, 5);
    Line line(myP1, myP2);
    Line line2(line);
    cout << "line的长度是：";
    cout << line.getLen() << endl;
    cout << "line2的长度是：";
    cout << line2.getLen() << endl;
    return 0;
}