#include"LinkList.h"


int main(int argc ,char **argv)
{
    LinkList<int> list;
    list.insert_back(1);
    list.insert_back(2);
    list.insert_back(3);
    list.insert_back(4);
    list.show();
    list.removeByPos(2);
    list.show();
    list.removeByValue(4);
    list.show();
    cout<<"length:"<<list.getLength()<<endl;
    list.insert_back(100);
    list.insert_back(123);
    list.insertByPos(4,223);
    list.show();
    cout<<"第二个节点是"<<list.getValue(2)<<endl;
    cout<<"最后一个节点是"<<list.getrValue(1)<<" 倒数第二个节点是"<<list.getrValue(2)<<endl;
    list[0]=-20;
    list.show();

}
