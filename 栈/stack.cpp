#include"stack.h"

int main(int argc,char **argv)
{
    stack<int> s(3);
    cout<<"capacity:"<<s.getCapacity()<<endl;
    s.push(22);
    s.push(11);
    s.push(99);
    cout<<"Top:"<<s.getTop()<<endl;
    s.push(10);
    cout<<s.pop()<<endl;
    cout<<"size:"<<s.size()<<endl;
}