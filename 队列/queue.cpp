#include "queue.h"

int main(int argc,char **argv)
{
    int tmp;
    queue<int> q(5);
    q.enQueue(12);
    q.enQueue(20);
    q.enQueue(44);
    q.enQueue(33);
    cout<<q.getFront()<<endl;
    q.deQueue(tmp);
    cout<<q.getFront()<<endl;
    cout<<"length:"<<q.getLength()<<endl;
    q.enQueue(1221);
}