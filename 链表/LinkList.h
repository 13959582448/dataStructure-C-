// https://github.com/13959582448
// https://blog.csdn.net/milanla
// author:"hch"

#include<iostream>
using namespace std;

template<typename T> //节点模板 
//不需要的话就直接去掉这一行 并把T改为需要的数据类型
class node
{
public:
    T value; 
    node<T>* next;
    node(const T v):value(v),next(nullptr){}  
    node():value(0),next(nullptr){}  
};

template<typename T>
class LinkList //单向链表模板
{
private:
    node<T>* head; //头节点(不含数据)
    size_t length; //链表

public:
    //三种构造函数
    LinkList(); //默认
    LinkList(LinkList<T>&); //复制
    LinkList(LinkList<T>&&); //转移
    
    LinkList<T>& insert_front(const T); //头插法
    LinkList<T>& insert_back(const T); //尾插法
    LinkList<T>& insertByPos(const size_t,const T); //在第n个节点前插入 1<=n<=length
    LinkList<T>& removeByPos(const size_t); //删除第n个节点 逻辑序号1<=n<=length
    LinkList<T>& removeByValue(const T); //按值匹配删除节点 

    T getValue(size_t); //获取第n个节点的值 逻辑序号 不包括头节点
    T getrValue(size_t); //获取倒数第n个节点 逻辑序号 不包括头节点
    bool show(); //遍历输出值
    size_t getLength(); //返回长度
    ~LinkList();

    T& operator[](size_t); //重载运算符
};

template<typename T>
LinkList<T>::LinkList() //初始化头节点
{
    head=new node<T>();
    head->next=nullptr;
    this->length=0;
}

template<typename T>
LinkList<T>::LinkList(LinkList<T>& tmp) //初始化头节点 复制
{
    head=tmp.head;
    length=tmp.length;
}

template<typename T>
LinkList<T>::LinkList(LinkList<T>&& tmp) //初始化头节点 转移
{
    head=tmp.head;
    tmp.head=nullptr; //防止tmp在被删除后this.head不会出错
    length=tmp.length;
}

template<typename T>
LinkList<T>& LinkList<T>::insert_back(const T v) //尾插法
{
    node<T>* newnode=new node<T>(v);
    node<T>* tmp=head;
    while(tmp->next)tmp=tmp->next; //找到最后一个节点
    tmp->next=newnode; //插入新值
    this->length++;
    return *this;
}

template<typename T>
LinkList<T>& LinkList<T>::insert_front(const T v) //头插法
{
    node<T>* newnode=new node<T>(v);
    newnode->next=head->next; 
    head->next=newnode;
    this->length++;
    return *this;
}

template<typename T>
LinkList<T>& LinkList<T>::insertByPos(const size_t pos,const T value)
{
    if(pos>this->length||pos<=0) //检查
    {
        cout<<"failed"<<endl;
        return *this;
    }
    node<T>* newnode=new node<T>(value); //创建新节点
    node<T>* pre=head;
    node<T>* tmp=head;
    for(int i=0;i<pos;i++)
    {
        pre=tmp;
        tmp=tmp->next;
    }
    newnode->next=tmp;
    pre->next=newnode; //插入新节点
    return *this;
}

template<typename T>
LinkList<T>& LinkList<T>::removeByPos(const size_t pos) 
{
    if(pos>this->length||pos<=0) //检查
    {
        cout<<"failed"<<endl;
        return *this;
    }
    int i=0;
    node<T>* tmp=head; 
    node<T>* pre;
    while(i<pos)
    {
        pre=tmp;
        tmp=pre->next; //每次循环后pre指针始终在tmp前面
        i++;
    }
    pre->next=tmp->next;
    delete tmp;
    this->length--;
    return *this;
}

template<typename T>
LinkList<T>& LinkList<T>::removeByValue(const T v)
{
    node<T>* tmp=head->next;
    node<T>* pre=head;
    while(tmp&&tmp->value!=v) //遍历寻找
    {
        pre=tmp;
        tmp=tmp->next; //pre指针始终在tmp的前面
    }
    if(!tmp) //如果不存着匹配的节点
    {
        cout<<"fail"<<endl;
        return *this;
    }
    pre->next=tmp->next; 
    delete tmp; //删除节点
    this->length--;
    return *this;
}

template<typename T>
size_t LinkList<T>::getLength() //返回长度
{
    return LinkList<T>::length;
}

template<typename T>
bool LinkList<T>::show() //遍历输出
{
    for(node<T>* tmp=head->next;tmp;tmp=tmp->next)
    {
        cout<<tmp->value<<" ";
    }
    cout<<"\n";
}

template<typename T>
T LinkList<T>::getValue(size_t pos) //获取第n个节点
{
    if(pos>this->getLength())
    {
        throw out_of_range("out of range");
    }
    node<T>* tmp=head;
    for(int i=0;i<pos;i++)
    {
        tmp=tmp->next;
    }
    return tmp->value;
}

template<typename T>
T LinkList<T>::getrValue(size_t pos) //获取倒数第n个节点
{
    if(pos>this->getLength())
    {
        throw out_of_range("out of range");
    }
    node<T>* fast=head; //快指针
    node<T>* slow=head; //慢指针
    for(int i=0;i<pos;i++) fast=fast->next; //快指针先走pos次
    while(fast) //快指针和慢指针同时走 慢指针始终离快指针pos个距离
    {
        fast=fast->next;
        slow=slow->next;
    }
    //当快指针到达最后的时候，慢指针离快指针pos个距离，即倒数第pos个节点的指针
    return slow->value; //返回慢指针的值
}

template<typename T>
LinkList<T>::~LinkList() //析构函数
{
    
    node<T>* tmp;
    while(head->next) 
    {
        tmp=head->next;
        delete head;
        head=tmp;
    }
    delete head;
}

template<typename T>
T& LinkList<T>::operator[](size_t pos)
{
    if(pos>=length||pos<0)
    {
        throw out_of_range("out of range");
    }
    node<T>* tmp=head->next;
    for(int i=0;i<pos;i++) tmp=tmp->next;
    return tmp->value;
}