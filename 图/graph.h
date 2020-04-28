#include<iostream>
#include<vector>
using namespace std;
using infoType=int;
#define MAXV 100
#define MAXE 100


struct vertexType //顶点类型
{
    int no; //顶点编号
    infoType info; //其他信息
    vertexType():no(0),info(0){}
    vertexType(int n):no(n){}
    vertexType(int n,infoType i):no(n),info(i){}
};

class MatGraph //邻接矩阵
{
public:
    int nVertexs,nEdges; //顶点和边
    int edges[MAXV][MAXE];
    vector<vertexType> vertexs;

    MatGraph():nVertexs(0),nEdges(0){}
    MatGraph(int v,int e):nVertexs(v),nEdges(e){}
    void create(); //创建
};

struct node
{
    int no; //顶点编号
    int weight;
    node* next;
    node(int n):no(n),weight(0),next(nullptr){}//头节点
    node(int n,int w):no(n),weight(w),next(nullptr){} //边节点

    void insertFront(node* n)
    {
        n->next=this->next;
        this->next=n;
    }
};

class AdjGraph
{
public:
    int nVertexs,nEdges;
    node* adjList[MAXV]; //节点组成的链表数组
    AdjGraph(int v,int e):nVertexs(v),nEdges(e)
    {
        for(int i=0;i<v;i++)
            adjList[i]=nullptr;
    }
    ~AdjGraph();
    void create(MatGraph);
    void show(); //输出链表
};

AdjGraph::~AdjGraph()
{
    node* pre,*tmp;
    for(int i=0;i<nVertexs;i++)
    {
        pre=adjList[i];
        tmp=pre->next;
        while(tmp) {delete pre;pre=tmp;tmp=tmp->next;}
        delete pre;
    }
}

void AdjGraph::show()
{
    node* tmp;
    for(int i=0;i<nVertexs;i++)
    {
        cout<<"节点编号(权重): ";
        tmp=adjList[i];
        while(tmp)
        {
            cout<<tmp->no<<"("<<tmp->weight<<")";
            if(tmp->next) cout<<" -> ";
            tmp=tmp->next;
        }
        cout<<endl;
    }
}

void MatGraph::create()
{
    int flag;
    cout<<"是否为有向图(0/1):";
    cin>>flag;
    cout<<"输入各边(格式:0(点) 1(点) 20(权重)):";
    int i,j,value;
    while(cin>>i>>j>>value)
    {
        edges[i][j]=value;
        if(!flag) edges[j][i]=value;
        vertexType v(value);
        
    }
}