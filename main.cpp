#include <iostream>
#include<iomanip>

using namespace std;
enum Weekday {
    SUN, MON, TUE, WED, THU, FRI, SAT
};
enum GameResult {
    WIN, LOST, TIE, CANCEL
};

double power(double x, int n) {
    double result = 1;
    while (n--) {
        result *= x;
    }
    return result;
}

double const PI = 3.14156;

double area() {
    short iType;
    double radius, a, b, area = 0;
    cout << "请输入要计算面积的类型？(1：圆形,2：长方形,3：正方形)";
    cin >> iType;
    switch (iType) {
        case 1:
            cout << "请输入半径：\n";
            cin >> radius;
            area = PI * radius * radius;
            break;
        case 2:
            cout << "请输入长：\n";
            cin >> a;
            cout << "请输入宽：\n";
            cin >> b;
            area = a * b;
            break;
        case 3:
            cout << "请输入边长：\n";
            cin >> a;
            area = a * a;
            break;
        default:
            cout << "输入的类型不合法\n";
    }
    cout << "面积的值为：" << area << endl;
    return area;
}

enum MonthEnum {
    January = 1, February, March, April, May, June, July, August, September, October, November, December
};
struct theTimeStruct {
    unsigned int year;
    unsigned int mon;
    unsigned int day;
    unsigned int hour;
    unsigned int min;
    unsigned int sec;
};

string timeStr() {
    string str;
    theTimeStruct timeStruct{2020, 3, 4, 21, 45, 11};
    cout << "请输入年份：\n";
    cin >> timeStruct.year;

    cout << "请输入月份：\n";
    cin >> timeStruct.mon;
    if (MonthEnum(timeStruct.mon) > December || MonthEnum(timeStruct.mon) < January) {
        cout << "您输入的月份不合法，请重新输入：";
        cin >> timeStruct.mon;
    }
    cout << "请输入日期：\n";
    cin >> timeStruct.day;

    cout << "请输入小时：\n";
    cin >> timeStruct.hour;

    cout << "请输入分钟：\n";
    cin >> timeStruct.min;

    cout << "请输入秒数：\n";
    cin >> timeStruct.sec;

    cout << "您输入的时间是："
         << timeStruct.year << "-"
         << timeStruct.mon << "-"
         << timeStruct.day << " "
         << timeStruct.hour << ":"
         << timeStruct.min << ":"
         << timeStruct.sec << endl;
    return str;
}

void testEEr() {
    cout << "ss";
    timeStr();
}
//输入一个8位二进制 转化为十进制输出

double binaryToDecimal();//

double binaryToDecimal() {
    int value = 0;
    cout << "请输入8位二进制编码：\n";

    for (int i = 7; i >= 0; i--) {
        char ch;
        cin >> ch;
        if (ch == '1') {
            value += static_cast<int>(power(2, i));
        }
    }
    cout << "转化的结果是：" << value;
    return value;
}

int main() {
    binaryToDecimal();

    testEEr();
    area();
    cout << power(5, 3);
    int bbb = 1, ccc = 0;
    auto aaa = bbb + ccc;
    decltype(bbb) jjj = 11.22;

    GameResult result;
    enum GameResult omit = CANCEL;
    for (int count = WIN; count <= CANCEL; count++) {
        result = GameResult(count);

        if (result == omit) {
            cout << "CANCEL";
        } else {
            cout << "The Game played is";
            if (result == WIN) cout << "WIN";
            if (result == LOST) cout << "LOST";
            cout << endl;
        }
    }


    typedef double xx, cc;
    using vv = double;

    int k, g = 0, h = 0;
    cout << "请输入一些正整数，输入0退出：\n";
    cin >> k;

    while (k != 0) {
        if (k > 0) g++;
        if (k < 0) h++;
        cin >> k;
    }

    cout << "大于0的次数：" << g << endl;
    cout << "小于0的次数：" << h << endl;


    int n;
    cout << "请输入一个正整数：";
    cin >> n;
    cout << "Number   " << n << "   Factors   ";

    for (int b = 1; b <= n; b++) {
        if (n % b == 0) {
            cout << b << "    ";
        }
    }


    int sum1 = 0, i1 = 0;
    cin >> i1;
    do {
        sum1 += i1;
        i1++;
    } while (i1 < 10);
    cout << sum1;


    int j;
    cout << "请输入一个整数：";
    cin >> j;
    do {
        int right_num = 0;
        right_num = j % 10;
        cout << right_num;
        j /= 10;
    } while (j != 0);


    int i = 0, sum = 0;
    while (i <= 10) {
        sum += i;
        i++;
    }
    cout << "sum = " << sum << endl;


    int year;
    cout << "请输入年号：\n";
    cin >> year;
    bool isLeapYeay;
    isLeapYeay = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeapYeay) {
        cout << "是闰年\n";
    } else {
        cout << "不是闰年\n";
    }


    int day;
    cout << "请输入day\n";
    cin >> day;
    switch (day) {
        case 0 :
            cout << "周日\n";
            break;
        case 1:
            cout << "周一" << endl;
            break;
        default:
            cout << "这是默认值啦\n";
            break;
    }

    int q, w, e;
    cout << "请输入q,w,e" << endl;
    cin >> q >> w >> e;
    cout << q << w << e;
    cout << setw(5) << setprecision(3) << 3.1415;

    if (q > w) cout << "q > w";
    else {
        if (q == w) {
            cout << "q = w";
        } else {
            cout << "q < w";
        }
    }
    int x, y, z;
    cout << "请输入x:\n";
    cin >> x;
    cout << "请输入y:\n";
    cin >> y;
    z = x > y ? x - y : y - x;
    cout << "结果是\t\t" << z << "\n";


    int a;
    unsigned int b = 100;
    unsigned int c = 50;

    a = b - c;
    cout << "a is" << a << endl;
    a = c - b;
    cout << "a is" << a << endl;


//
    cout << "int is " << sizeof(int) << "bytes\n";
    cout << "char32_t is " << sizeof(char32_t) << "bytes\n";
    cout << "long is " << sizeof(long) << "bytes\n";
    cout << "double is " << sizeof(double) << "bytes\n";
    cout << sizeof(short) << "bytes\n";
    const double pi(3.15149);
    int radius(0);
    static_cast<int>(radius);
    cout << sizeof('C++');
    cout << "The initial radius is :" << radius << "\n";
    cin >> radius;
    cout << "The radius is:" << radius << '\n';
    cout << "PI is:" << pi << '\n';
    cout << "Please enter a different radius!\n";
    cin >> radius;
    cout << "Now the radius is changed to:" << radius << '\n';

    return 0;
}
