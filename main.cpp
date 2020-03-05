#include <iostream>
#include<iomanip>
#include <cmath>

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
    cout << "������Ҫ������������ͣ�(1��Բ��,2��������,3��������)";
    cin >> iType;
    switch (iType) {
        case 1:
            cout << "������뾶��\n";
            cin >> radius;
            area = PI * radius * radius;
            break;
        case 2:
            cout << "�����볤��\n";
            cin >> a;
            cout << "�������\n";
            cin >> b;
            area = a * b;
            break;
        case 3:
            cout << "������߳���\n";
            cin >> a;
            area = a * a;
            break;
        default:
            cout << "��������Ͳ��Ϸ�\n";
    }
    cout << "�����ֵΪ��" << area << endl;
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
    cout << "��������ݣ�\n";
    cin >> timeStruct.year;

    cout << "�������·ݣ�\n";
    cin >> timeStruct.mon;
    if (MonthEnum(timeStruct.mon) > December || MonthEnum(timeStruct.mon) < January) {
        cout << "��������·ݲ��Ϸ������������룺";
        cin >> timeStruct.mon;
    }
    cout << "���������ڣ�\n";
    cin >> timeStruct.day;

    cout << "������Сʱ��\n";
    cin >> timeStruct.hour;

    cout << "��������ӣ�\n";
    cin >> timeStruct.min;

    cout << "������������\n";
    cin >> timeStruct.sec;

    cout << "�������ʱ���ǣ�"
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
//����һ��8λ������ ת��Ϊʮ�������

double binaryToDecimal();//

double binaryToDecimal() {
    int value = 0;
    cout << "������8λ�����Ʊ��룺\n";

    for (int i = 7; i >= 0; i--) {
        char ch;
        cin >> ch;
        if (ch == '1') {
            value += static_cast<int>(power(2, i));
        }
    }
    cout << "ת���Ľ���ǣ�" << value;
    return value;
}

double arctan(double x) {
    double sqr = x * x;
    double e = x;
    double r = 0;
    int i = 1;
    while (e / i > 1e-15) {
        double f = e / i;
        r = (i % 4 == 1) ? r + f : r - f;
        e = e * sqr;
        i += 2;
    }
    return r;
}

void getPi() {
    double a = 16.0 * arctan(1.0 / 5.0);
    double b = 4.0 * arctan(1.0 / 239.0);
    cout << "PI = " << a - b << endl;
}

bool symm(unsigned int n) {
    unsigned i = n;
    unsigned m = 0;
    while (i > 0) {
        m = m * 10 + i % 10;
        i /= 10;
    }
    return m == n;
}

const double TINY_VALUE = 1e-10;

double tsin(double x) {
    double g = 0;
    double t = x;
    int n = 1;
    do {
        g += t;
        n++;
        t = -t * x * x / (2 * n - 1) / (2 * n - 2);
    } while (fabs(t) >= TINY_VALUE);
    return g;
}

void testTsin() {
    double k, r, s;
    cout << "r = ";
    cin >> r;
    cout << "s = ";
    cin >> s;
    if (r * r <= s * s) {
        k = sqrt(tsin(r) * tsin(r) + tsin(s) * tsin(s));
    } else {
        k = tsin(r * s) / 2;
    }
    cout << k << endl;
}


void testSymm() {
    for (unsigned m = 11; m < 1000; m++) {
        if (symm(m) && symm(m * m) && symm(m * m * m)) {
            cout << "m = " << m << endl;
            cout << "m * m = " << m * m << endl;
            cout << "m * m * m = " << m * m * m << endl;
        }
    }
}

unsigned fac(unsigned n) {
    unsigned f;
    if (n == 0) {
        f = 1;
    } else {
        f = fac(n - 1) * n;
    }
    return f;
}

void testFac() {
    unsigned int a;
    cout << "������һ����������\n";
    cin >> a;
    cout << "�׳�ֵΪ��" << fac(a) << "\n";
}
void function2 (int n);
void function1 (int n) {
    cout<<"function1";
    if(n<=0)
        return;
    function2 (n-2);
}
void function2 (int n){
    cout<<"function2";
    if(n<=0)
        return;
    function1 (n-1);
}

int fib (int n){
    cout << "fib\n";
    if (n==0)
        return 1;
    else if (n==1)
        return 2;
    else
        return fib(n-1)+fib(n-2);
}
int f(int a,int b)
{
    if(a<b)

        return f((b-a),a);

    else if(a ==b)

        return 2*a;

    else

        return f(f(a/2,b),f(b,b%2));
}

int comm(int n, int k) {
    cout << "comm \n";
    if (k > n)
        return 0;
    else if (n == k || k== 0)
        return 1;
    else
        return comm(n-1,k)+comm(n-1,k-1);
}

void testComm() {
    int n,k;
    cout << "��������������n��k:";
    cin >>n >> k;
    cout << "C(n,k) = " << comm(n,k) << endl;
}

int main() {
    testComm();
    cout << f(3,5);
    fib(2);
    function1(5);
    testFac();
    testTsin();
    testSymm();
    getPi();

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
    cout << "������һЩ������������0�˳���\n";
    cin >> k;

    while (k != 0) {
        if (k > 0) g++;
        if (k < 0) h++;
        cin >> k;
    }

    cout << "����0�Ĵ�����" << g << endl;
    cout << "С��0�Ĵ�����" << h << endl;


    int n;
    cout << "������һ����������";
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
    cout << "������һ��������";
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
    cout << "��������ţ�\n";
    cin >> year;
    bool isLeapYeay;
    isLeapYeay = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeapYeay) {
        cout << "������\n";
    } else {
        cout << "��������\n";
    }


    int day;
    cout << "������day\n";
    cin >> day;
    switch (day) {
        case 0 :
            cout << "����\n";
            break;
        case 1:
            cout << "��һ" << endl;
            break;
        default:
            cout << "����Ĭ��ֵ��\n";
            break;
    }

    int q, w, e;
    cout << "������q,w,e" << endl;
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
    cout << "������x:\n";
    cin >> x;
    cout << "������y:\n";
    cin >> y;
    z = x > y ? x - y : y - x;
    cout << "�����\t\t" << z << "\n";


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
