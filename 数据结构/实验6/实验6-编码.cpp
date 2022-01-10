#include<iostream>
using namespace std;
class binaryTree
{
    public:
    binaryTree(){}
    void createBinaryTree(int n);
    string ergodic(binaryTree * p,int n);
    void dlr(binaryTree * p);
    string data;
    binaryTree * pnode=NULL;
    binaryTree * lchild=NULL;
    binaryTree * rchild=NULL;
};
//创建编码用的二叉树
void binaryTree::createBinaryTree(int n)
{
    int flag;
    binaryTree *p=this;
    p->data="0";
    while(n--)
    {
        binaryTree *temp1=new binaryTree;
        binaryTree *temp2=new binaryTree;
        temp1->lchild=NULL;
        temp1->rchild=NULL;
        temp2->lchild=NULL;
        temp2->rchild=NULL;
        p->lchild=temp1;
        p->rchild=temp2;
        temp1->pnode=p;
        temp2->pnode=p;
        temp1->data="1";
        temp2->data="0";
        p=p->rchild;
        
    }
}
//编码
string binaryTree::ergodic(binaryTree * p,int n)
{
    string temp=p->data;
    for (int i=1;i<n;i++)
    {
        p=p->rchild;
        temp+=p->data;
    }
    return temp+p->lchild->data;
}
int main()
{
    int n,i;
    binaryTree binarytree;
    binaryTree * p=&binarytree;
    binarytree.createBinaryTree(8);
    char foo[8]={'b','f','e','h','d','c','a','g'};
    //输出编码结果
    for (i=0;i<8;i++)
    {
        cout<<foo[i]<<"的编码为：";
        cout<<binarytree.ergodic(&binarytree,i+1)<<endl;
    }
}
