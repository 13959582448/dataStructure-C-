#include"BSTree.h"

int main(int argc,char** argv)
{
    BSTree<int> tree;
    tree.create();
    tree.inTraverse(tree.root);
    tree.deleteNode(1);
    tree.inTraverse(tree.root);
}