// https://github.com/13959582448/dataStructure-C-
// https://blog.csdn.net/milanla
// author:"hch"

#include<iostream>
#include"../队列/queue.h" //导入之前写过的队列
using namespace std;

template<typename T> //树的节点
class node
{
public:
    T data; //数据
    node<T>* lchild,*rchild; //左右孩子节点
    node(const T& v):data(v),lchild(nullptr),rchild(nullptr){}
    node():data(0),lchild(nullptr),rchild(nullptr){}
};

template<typename T> //树
class binaryTree
{
public:
    node<T>* root; //根节点
public:
    binaryTree():root(nullptr){}

    node<T>* create(); //层次创建
    inline void print(node<T>*); //方便打印
    void preTraverse(node<T>*); //先序遍历
    void inTraverse(node<T>*); //中序遍历
    void postTraverse(node<T>*); //后序遍历
    void traverse(node<T>*); //层次遍历
    void destroyTree(node<T>*); //销毁树
    size_t getDepth(node<T>*); //求深度

    ~binaryTree();
};

/* 数据(序号)
                312(1)
             /          \
          22(2)         33(3)
        /      \       /     \
    98(4)     43(5)   64(6)  77(7)
   /    \     /   \
12(8) 44(9) 0(10) 2(10) 

->写法: 312 22 33 98 43 64 77 12 44 0 2
*/

template<typename T>
node<T>* binaryTree<T>::create()
{
    node<T>* (nodes[100])={}; //nodes是数组 存的是每个节点指针 方便查询

    int i=1;
    T value;
    cout<<"按层次创建树,输入完成后按回车和Ctrl-d结束(0或'0'代表空):";
    while(cin>>value) //输入完成后按回车 再按ctrl+d 即可结束 有的需要按ctrl+z 
    {
        if(i==1)
        {
            this->root=new node<T>(value);
            nodes[i-1]=root;
            i++;
            continue;
        }

        if(value==0||value=='0') //value==0 0代表为空
        {
            if(nodes[i/2-1]&&i%2==0) //左孩子 因为按层次遍历所有的左孩子节点的逻辑序号都是偶数
            //判断是否存在该节点的双亲结点
            {
                nodes[i/2-1]->lchild=nullptr;
            }
            else if(nodes[i/2-1]) nodes[i/2-1]->rchild=nullptr; //双亲结点的左右孩子赋值
            nodes[i-1]=nullptr;
            i++;
            continue;
        }
        
        node<T>* newnode=new node<T>(value); //不为空的情况
        nodes[i-1]=newnode;
        if(nodes[i/2-1]&&i%2==0) nodes[i/2-1]->lchild=newnode;
        else if(nodes[i/2-1]) nodes[i/2-1]->rchild=newnode;
        i++;
    }
}

template<typename T>
inline void binaryTree<T>::print(node<T> *n) //方便打印的函数
{
    cout<<n->data<<" ";
}

template<typename T>
void binaryTree<T>::preTraverse(node<T>* n) //先序遍历
{
    if(n)
    {
        print(n); //先本节点
        preTraverse(n->lchild); //然后子树
        preTraverse(n->rchild); //最后右子树
    }
}

template<typename T>
void binaryTree<T>::inTraverse(node<T>* n) //中序遍历
{
    if(n)
    {
        inTraverse(n->lchild); //先左子树
        print(n); //然后本节点
        inTraverse(n->rchild); //最后右子树
    }
}

template<typename T>
void binaryTree<T>::postTraverse(node<T>* n) //后序遍历
{
    if(n)
    {
        postTraverse(n->rchild); //先右子树
        postTraverse(n->lchild); //然后左子树
        print(n); //最后本节点
    }
}

template<typename T>
void binaryTree<T>::traverse(node<T>* n) //层次遍历
{
    node<T>* tmp;
    queue<node<T>* > q(100); //这个可以看我写过的队列的定义
    q.enQueue(root);
    while(!q.isEmpty()) //队列不为空
    {
        q.deQueue(tmp);
        cout<<tmp->data<<" ";
        if(tmp->lchild) q.enQueue(tmp->lchild); //左孩子不为空
        if(tmp->rchild) q.enQueue(tmp->rchild); //又孩子不为空
    }
}

template<typename T>
size_t binaryTree<T>::getDepth(node<T> *n)
{
    if(!n) return 0; //空的节点的深度为0
    size_t lDepth=getDepth(n->lchild);
    size_t rDepth=getDepth(n->rchild); //获取左右子树的深度
    return lDepth>rDepth?(lDepth+1):(rDepth+1); 
    //一个节点左右子树中最深的那个加1等于该节点的深度
}

template<typename T>
void binaryTree<T>::destroyTree(node<T>* n) //销毁树
{
    if(n->lchild) destroyTree(n->lchild); //删除左子树
    if(n->rchild) destroyTree(n->rchild); //删除右子树
    delete n;

}

template<typename T>
binaryTree<T>::~binaryTree() //析构函数
{
    destroyTree(root);
}
