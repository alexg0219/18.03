#include <iostream>
#include <stack>
#include "Queue.h"

using namespace std;

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
}