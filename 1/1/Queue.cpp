#include "Queue.h"

void Queue::enQueue(int x)
{
    s1.push(x);
}

int Queue::deQueue()
{
    if (s1.empty() && s2.empty()) 
    {
        cout << "Q is empty";
        exit(0);
    }

    if (s2.empty()) 
    {
        while (!s1.empty()) 
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int x = s2.top();
    s2.pop();
    return x;
}