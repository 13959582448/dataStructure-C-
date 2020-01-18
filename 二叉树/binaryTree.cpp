#include"binaryTree.h"

int main(int argc,char** argv)
{
    binaryTree<int> tree;
    tree.create();
    // cout<<tree.root->data<<endl;
    tree.preTraverse(tree.root);
    
}