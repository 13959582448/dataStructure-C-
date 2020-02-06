#include"BSTree.h"

int main(int argc,char** argv)
{
    BSTree<int> tree;
    tree.create();
    tree.inOrder(tree.root);
    tree.deleteNode(1);
    cout<<"\n";
    tree.inOrder(tree.root);
    cout<<"\nheight:"<<tree.getHeight(tree.root)<<endl;
}