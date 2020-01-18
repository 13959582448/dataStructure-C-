// https://github.com/13959582448/dataStructure-C-
// https://blog.csdn.net/milanla
// author:"hch"

#include<iostream>
using namespace std;

template<typename T>
class queue //循环队列
{
protected:
    T* data;
    size_t capacity;
    int front,rear;

public:
    queue(const size_t);
    queue(queue<T>&);
    queue(queue<T>&&); //构造函数

    queue<T>& enQueue(const T); //入队
    queue<T>& deQueue(T& e); //出队
    bool isEmpty(); //判空
    bool isFull(); //判满
    size_t getLength(); //长度
    T& getFront(); //队首元素
    
    ~queue(); //析构
};

template<typename T>
queue<T>::queue(const size_t capacity) //构造函数
{
    this->capacity=capacity;
    front=rear=0;
    data=new T[capacity];
}

template<typename T>
queue<T>::queue(queue<T>& tmp) //复制构造
{
    this->data=tmp.data;
    this->capacity=tmp.capacity;
    this->front=tmp.tmp;
    this->rear=tmp.rear;
}

template<typename T>
queue<T>::queue(queue<T>&& tmp) //转移构造
{
    this->data=tmp.data;
    tmp.data=nullptr;
    this->capacity=tmp.capacity;
    this->front=tmp.tmp;
    this->rear=tmp.rear;
}

template<typename T>
bool queue<T>::isEmpty() //判空
{
    if(rear==front) return true;
    return false;
}

template<typename T>
bool queue<T>::isFull() //判满
{
    if((rear+1)%capacity==front) return true;
    return false;
}

template<typename T>
queue<T>& queue<T>::enQueue(const T v) //入队
{
    if(isFull())
    {
        throw out_of_range("full");
    }
    data[rear]=v;
    rear=(rear+1)%capacity;
    return *this;
}

template<typename T>
queue<T>& queue<T>::deQueue(T& e) //出队
{
    if(isEmpty())
    {
        throw out_of_range("empty");
    }
    e=data[front];
    front=(front+1)%capacity;
}

template<typename T>
size_t queue<T>::getLength() //长度
{
    return (rear-front+capacity)%capacity;
}

template<typename T>
T& queue<T>::getFront() //取队首元素
{
    if(isEmpty()) throw out_of_range("empty");
    return data[front];
}

template<typename T>
queue<T>::~queue() //析构
{
    delete []data;
}