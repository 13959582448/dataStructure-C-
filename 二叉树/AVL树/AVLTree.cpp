#include"AVLTree.h"

int main(int argc,char** argv)
{
    AVLTree<int> tree;
    tree.create();
    tree.Order(tree.root);
    cout<<endl;
    tree.deleteNode(7);
    tree.Order(tree.root);
}