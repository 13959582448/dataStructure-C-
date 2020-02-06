// https://github.com/13959582448/dataStructure-C-
// https://blog.csdn.net/milanla
// author:"hch"

#include<iostream>
#include"../二叉排序(搜索)树/queue.h"
using namespace std;

template<typename T>
struct AVLnode
{
    int height; //balance factor
    AVLnode<T>* lchild,*rchild; //左右子节点
    T val;
    AVLnode(const T v):lchild(nullptr),rchild(nullptr),val(v),height(0){}
};

template<typename T>
class AVLTree
{
public:
    AVLnode<T>* root;
    AVLTree():root(nullptr){}
    
    void create(); //创建AVL树
    AVLnode<T>* add(AVLnode<T>*,const T); //添加节点

    AVLnode<T>* balance(AVLnode<T>*,int,int,int); //平衡一个节点
    AVLnode<T>* LRotation(AVLnode<T>*); //左旋
    AVLnode<T>* RRotation(AVLnode<T>*); //右旋
    AVLnode<T>* LRBalance(AVLnode<T>*&); //LR左子树的右子树导致失衡
    AVLnode<T>* RLBalance(AVLnode<T>*&); //RL右子树的左子树导致失衡
    inline int getBf(AVLnode<T>*); //获取高度(深度)
    
    int getHeight(AVLnode<T>*);
    void deleteNode(const T); //删除节点
    AVLnode<T>* deleteNode(AVLnode<T>*,const T); //删除节点

    void preOrder(AVLnode<T>*); //先序遍历
    void inOrder(AVLnode<T>*); //中序遍历
    void postOrder(AVLnode<T>*); //后序遍历 
    void Order(AVLnode<T>*); //层次遍历

    void destroy(AVLnode<T>*); //
    ~AVLTree(); //析构函数
};

template<typename T>
inline int AVLTree<T>::getBf(AVLnode<T>* node)
{   
    return (!node)?(0):(getHeight(node->lchild)-getHeight(node->rchild));
}

template<typename T>
int AVLTree<T>::getHeight(AVLnode<T>* node)
{
    if(!node) return 0;
    int left=0,right=0;
    if(node->lchild) left=getHeight(node->lchild);
    if(node->rchild) right=getHeight(node->rchild);
    return (left>right)?(left+1):(right+1);
}

template<typename T>
void AVLTree<T>::create()
{
    T value;
    cout<<"输入数据(回车后按Ctrl+d结束):";
    while(cin>>value)
    {
        root=add(root,value);
    }
}

template<typename T>
AVLnode<T>* AVLTree<T>::add(AVLnode<T>* node,const T value)
{
    if(!node)
    {
        node=new AVLnode<T>(value);
        return node;
    }
    if(value<node->val)
        node->lchild=add(node->lchild,value);
    else if(value>node->val)
        node->rchild=add(node->rchild,value);

    int bf=getBf(node);
    int left_bf=getBf(node->lchild);
    int right_bf=getBf(node->rchild);

    return balance(node,bf,left_bf,right_bf); //返回平衡好的根节点

}

template<typename T>
AVLnode<T>* AVLTree<T>::balance(AVLnode<T>* node,int bf,int left_bf,int right_bf)
{
    if(bf>1&&left_bf>=0) //右旋
    {
        return RRotation(node);
    }
    if(bf<-1&&right_bf<=0) //左旋
    {
        return LRotation(node);
    }
    if(bf>1&&left_bf<0) //LR
    {
        return LRBalance(node);
    }
    if(bf<-1&&right_bf>0) //RL
    {
        return RLBalance(node);
    }
    return node;
}

template<typename T>
AVLnode<T>* AVLTree<T>::LRotation(AVLnode<T>* oldNode) //左旋 右子树导致失衡
{
    AVLnode<T>* right=oldNode->rchild;
    oldNode->rchild=right->lchild;
    right->lchild=oldNode;

    return right;
}

template<typename T>
AVLnode<T>* AVLTree<T>::RRotation(AVLnode<T>* oldNode) //右旋 左子树导致失衡
{
    AVLnode<T>* left=oldNode->lchild;
    oldNode->lchild=left->rchild;
    left->rchild=oldNode;

    return left;
}

template<typename T>
AVLnode<T>* AVLTree<T>::LRBalance(AVLnode<T>*& oldnode) //左子树的右节点导致失衡
{
    oldnode->lchild=LRotation(oldnode->lchild);
    return RRotation(oldnode);
}

template<typename T>
AVLnode<T>* AVLTree<T>::RLBalance(AVLnode<T>*& oldnode) //右子树的左节点导致失衡
{
    oldnode->rchild=RRotation(oldnode->rchild);
    return LRotation(oldnode);
}

template<typename T>
void AVLTree<T>::Order(AVLnode<T>* node)
{
    AVLnode<T>* tmp;
    queue<AVLnode<T>* > q(100); //这个可以看我写过的队列的定义
    q.enQueue(root);
    while(!q.isEmpty()) //队列不为空
    {
        q.deQueue(tmp);
        cout<<tmp->val<<" ";
        if(tmp->lchild) q.enQueue(tmp->lchild); //左孩子不为空
        if(tmp->rchild) q.enQueue(tmp->rchild); //右孩子不为空
    }
}

template<typename T>
void AVLTree<T>::deleteNode(const T value)
{
    root=deleteNode(root,value);
}

template<typename T>
AVLnode<T>* AVLTree<T>::deleteNode(AVLnode<T>* node,const T value)
{
    if(!node) return nullptr;
    AVLnode<T>* ans; //返回值用于代替node
    if(value>node->val) //右子树
    {
        node->rchild=deleteNode(node->rchild,value);
        ans=node;
    }
    else if(value<node->val) //左子树
    {
        node->lchild=deleteNode(node->lchild,value);
        ans=node;
    }
    else //匹配
    {
        if(!node->lchild) //左子树为空
        {
            ans=node->rchild;
        }
        else if(!node->rchild) //右子树为空
        {
            ans=node->lchild;
        }
        else //均不为空
        {
            AVLnode<T>* tmp=node->rchild; 
            while(tmp->lchild) tmp=tmp->lchild; //右子树中最小的值
            tmp->lchild=node->lchild;
            tmp->rchild=deleteNode(node->rchild,tmp->val); 
            ans=tmp; //代替node
        } 
        delete node;
    }
    
    if(!ans) return nullptr;
    int bf=getBf(ans);
    int left_bf=getBf(ans->lchild),right_bf=getBf(ans->rchild);
    ans=balance(ans,bf,left_bf,right_bf); //平衡

    return ans;    
}

template<typename T>
void AVLTree<T>::destroy(AVLnode<T>* node) //删除节点及其子树
{
    if(node->lchild) destroy(node->lchild);
    if(node->rchild) destroy(node->rchild);
    delete node;
}

template<typename T>
void AVLTree<T>::preOrder(AVLnode<T>* node) //先序
{
    if(node)
    {
        cout<<node->val<<" ";
        if(node->lchild) preOrder(node->lchild);
        if(node->rchild) preOrder(node->rchild);
    }
}

template<typename T>
AVLTree<T>::~AVLTree()
{
    if(root) destroy(root);
}