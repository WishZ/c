#ifndef CONSOLE_CLOCK_H
#define CONSOLE_CLOCK_H


class Clock {
public:
    Clock();
    Clock(int i, int i1, int i2);
    Clock(const Clock& c) = delete;
    void setTime(int newH, int newM, int news);

    void showTime();

private:
    int hour{}, minute{}, second{};
};


#endif //CONSOLE_CLOCK_H
