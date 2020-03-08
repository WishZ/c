#include <iostream>
#include "Clock.h"

void Clock::setTime(int newH, int newM, int news) {

}

void Clock::showTime() {

}

Clock::Clock(int i, int i1, int i2) :
        hour(i), minute(i1), second(i2) {

}

Clock::Clock() {

}

//Clock::Clock(const Clock &c) {
//
//}

using namespace std;
class Name{

    char name[20];

public:

    void strcpy(char name[20], const char string[1]) {

    }

    Name(){

        strcpy (name,""); cout<<'?';

    }

    Name(char *fname){

        strcpy (name, fname); cout<<'?';

    }

};
class MyClass{

private:

    int num;

public:

    MyClass(int d):num(d){}

    MyClass(const MyClass& original):num (original.num){
        cout << "s\n";
    }

    friend void print(MyClass C){cout<<C.num; }

};


int main() {
    MyClass c(5);

    MyClass *p1;

    p1=&c;

    print(*p1);

    print(c);

    Name names[3] ={Name("111"),Name("222")};
    Clock myClock(1, 2, 3);
    myClock.setTime(1, 12, 3);
    myClock.showTime();
    cout << "Hello ";
    return 0;
}