#pragma once
#include <stack>
#include <iostream>

using namespace std;

struct Queue
{
    stack<int> s1, s2;

    void enQueue(int x);

    int deQueue();
};