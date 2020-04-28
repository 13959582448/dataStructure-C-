#include"RBTree.h"

int main(int argc,char **argv)
{
    RBTree tree;
    RBnode* node1=new RBnode(0,'b');
    RBnode* node2=new RBnode(1,'b');
    RBnode* node3=new RBnode(2,'r');
    RBnode* node4=new RBnode(3,'r');
    node1->left=node2;
    node1->right=node3;
    node3->left=node4;
    
    RBnode* node=tree.RLRotation(node1);
    cout<<node->val<<" "<<node->color<<endl;
    cout<<node->left->val<<" "<<node->left->color<<endl;
    cout<<node->right->val<<" "<<node->right->color<<endl;
    cout<<node->left->left->val<<" "<<node->left->left->color<<endl;

    tree.destroy(node);
}