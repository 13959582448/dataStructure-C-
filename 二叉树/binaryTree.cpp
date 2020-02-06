#include"binaryTree.h"

int main(int argc,char** argv)
{
    binaryTree<int> tree;
    // tree.create();
    // cout<<"先序遍历:";
    // tree.preOrder(tree.root);
    // cout<<"\n中序遍历:";
    // tree.inOrder(tree.root);
    // cout<<"\n后序遍历:";
    // tree.postOrder(tree.root);
    // cout<<"\n层次遍历:";
    // tree.Order(tree.root);
    // cout<<"\n树的深度:"<<tree.getDepth(tree.root);

    int size=6;
    int startRange=0,endRange=size-1;
    int pre[size],in[size];
    cout<<"输入先序和中序"<<endl;
    for(int i=0;i<size;i++) cin>>pre[i];
    for(int i=0;i<size;i++) cin>>in[i];

    node<int>* n=tree.createTreeBypreAndin(pre,in,startRange,endRange,startRange,endRange);
    cout<<"层次遍历:";
    tree.Order(n);
    tree.destroyTree(n);

}