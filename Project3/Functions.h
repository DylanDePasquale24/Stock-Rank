#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>
#include <conio.h>
#include "Stock.h"

void loadData(string ticker, vector<Stock*>& Dow30, int index);
bool findStock(string ticker, vector<Stock*>& Dow30, int& index);
int dateConverter(string date);
string convertIntDateToString(int date);

class timer {
public:
    timer();
    void start();
    void stop();
    void reset();
    bool isRunning();
    unsigned long getTime();
    bool isOver(unsigned long seconds);
private:
    bool resetted;
    bool running;
    unsigned long beg;
    unsigned long end;
};

timer::timer() {
    resetted = true;
    running = false;
    beg = 0;
    end = 0;
}


void timer::start() {
    if (!running) {
        if (resetted)
            beg = (unsigned long)clock();
        else
            beg -= end - (unsigned long)clock();
        running = true;
        resetted = false;
    }
}


void timer::stop() {
    if (running) {
        end = (unsigned long)clock();
        running = false;
    }
}


void timer::reset() {
    bool wereRunning = running;
    if (wereRunning)
        stop();
    resetted = true;
    beg = 0;
    end = 0;
    if (wereRunning)
        start();
}


bool timer::isRunning() {
    return running;
}


unsigned long timer::getTime() {
    if (running)
        return ((unsigned long)clock() - beg) / CLOCKS_PER_SEC;
    else
        return end - beg;
}


bool timer::isOver(unsigned long seconds) {
    return seconds >= getTime();
}
