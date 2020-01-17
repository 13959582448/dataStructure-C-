// https://github.com/13959582448
// https://blog.csdn.net/milanla
// author:"hch"

#include<iostream>
using namespace std;

template<typename T>
class stack
{
protected:
    T* bottom; //底部指针
    T* top; //顶部指针
    size_t capacity; //容量

public:
    stack(size_t);
    T pop(); //出栈
    T getTop(); //返回栈顶元素
    int push(const T); //进栈
    size_t getCapacity(); //返回容量
    size_t size(); //返回大小
    bool isEmpty(); //判断是否为空
    bool isFull(); //判断是否栈满
    ~stack(); //析构
};

template<typename T>
stack<T>::stack(size_t s) //创建一个大小为s的栈
{
    this->bottom=new T[s];
    this->top=this->bottom;
    this->capacity=s;
}

template<typename T>
size_t stack<T>::getCapacity() //返回容量
{
    return this->capacity;
}

template<typename T>
size_t stack<T>::size() //返回已经装入的元素个数
{
    return top-bottom;
}

template<typename T>
bool stack<T>::isEmpty() //判断是否为空
{
    if(bottom==top)return true;
    return false;
}

template<typename T>
bool stack<T>::isFull() //判断是否栈满
{
    if(top-bottom==capacity)return true;
    return false;
}

template<typename T>
T stack<T>::pop() //出栈
{
    if(isEmpty())
    {
        fprintf(stdout,"failed.\n");
        exit(0);
    }
    this->top--; //指针向下移动
    T result=*top; 
    return result; 
}

template<typename T>
T stack<T>::getTop()
{
    T* tmp=top;
    tmp--;
    return *tmp; //取栈顶元素
}

template<typename T>
int stack<T>::push(const T v) //进栈
{
    if(isFull())
    {
        fprintf(stderr,"failed.\n");
        return 0;
    }
    *top=v;
    top++;
    return 1;
}

template<typename T>
stack<T>::~stack() //析构函数
{
    delete []bottom;
}