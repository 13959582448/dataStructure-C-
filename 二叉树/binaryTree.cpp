#include"binaryTree.h"

int main(int argc,char** argv)
{
    binaryTree<int> tree;
    tree.create();
    cout<<"先序遍历:";
    tree.preTraverse(tree.root);
    cout<<"\n中序遍历:";
    tree.inTraverse(tree.root);
    cout<<"\n后序遍历:";
    tree.postTraverse(tree.root);
    cout<<"\n层次遍历:";
    tree.traverse(tree.root);
    cout<<"\n树的深度:"<<tree.getDepth(tree.root);
}