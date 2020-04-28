// https://github.com/13959582448/dataStructure-C-
// https://blog.csdn.net/milanla
// author:"hch"

#include<iostream>
using namespace std;

struct RBnode
{
    int val;
    char color;
    RBnode* left,*right,*parent;
    RBnode(const int v,char c):val(v),left(nullptr),right(nullptr),color(c){}
    RBnode(const int v,char c,RBnode* p):val(v),left(nullptr),right(nullptr),color(c),parent(p){}
};

class RBTree
{
public:
    RBnode* root;
    RBTree():root(nullptr){}
    
    void create();
    int getDepth(RBnode*); //获取高度
    inline int getBf(RBnode*); //获取平衡因子
    RBnode* insert(RBnode*,int); //插入一个新的节点
    RBnode* LRotation(RBnode*); //左旋
    RBnode* RRotation(RBnode*); //右旋
    RBnode* LRRotation(RBnode*); //左子树的右节点需要调整
    RBnode* RLRotation(RBnode*); //右子树的左节点需要调整

    void preOrder(RBnode *); //先序遍历
    void inOrder(RBnode*); //中序遍历
    void postOrder(RBnode*); //后序遍历

    void destroy(RBnode*); //销毁
    ~RBTree(); //析构函数
};

int RBTree::getDepth(RBnode* n)
{
    if(!n) return 0;
    int left=getDepth(n->left);
    int right=getDepth(n->right);
    return (left>right)?(left+1):(right+1);
}

inline int RBTree::getBf(RBnode* n)
{
    return (!n)?(0):(getDepth(n->left)-getDepth(n->right));
}

void RBTree::create()
{
    cout<<"输入数据(回车后按Ctrl+d结束):";
    int value;
    while(cin>>value)
    {
        root=insert(root,value);
    }
    cout<<"创建成功!"<<endl;
}

RBnode* RBTree::RRotation(RBnode* n) //右旋 顺时针(左左情况)
{
    RBnode* left=n->left;
    n->left=left->left;
    left->right=n;
    left->color='b';
    n->color='r';
    return left; //返回调整后的节点
}

RBnode* RBTree::LRotation(RBnode* n) //左旋 逆时针(右右情况)
{
    RBnode* right=n->right;
    n->right=right->left;
    right->left=n;
    right->color='b';
    n->color='r';
    return right; //返回节点
}

RBnode* RBTree::LRRotation(RBnode* n) //左子树的右节点需要调整
{
    n->left=LRotation(n->left);
    n->left->color='r';
    return RRotation(n); //先左旋 再右旋
}

RBnode* RBTree::RLRotation(RBnode* n) //右子树的左节点需要调整
{
    //先右旋
    n->right=RRotation(n->right);
    n->right->color='r';
    return LRotation(n); //再左旋
}

RBnode* RBTree::insert(RBnode* n,int value)
{
    if(!n)
    {
        n=new RBnode(value,'b',nullptr);
        return n;
    }

}



void RBTree::preOrder(RBnode* n)
{
    if(n)
    {
        cout<<n->val<<"("<<n->color<<") ";
        preOrder(n->left);
        preOrder(n->right);
    }
}

void RBTree::inOrder(RBnode* n)
{
    if(n)
    {
        inOrder(n->left);
        cout<<n->val<<"("<<n->color<<") ";
        inOrder(n->right);
    }
}

void RBTree::postOrder(RBnode* n)
{
    if(n)
    {
        postOrder(n->right);
        postOrder(n->left);
        cout<<n->val<<"("<<n->color<<") ";
    }
}

void RBTree::destroy(RBnode* n)
{
    if(n)
    {
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
}

RBTree::~RBTree()
{
    destroy(root);
}