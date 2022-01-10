#include<iostream>
using namespace std;
class binaryTree
{
    public:
    binaryTree(){}
    void createBinaryTree(int n);
    void dlr(binaryTree * p);
    void ldr(binaryTree * p);
    void lrd(binaryTree * p);
    char data;
    binaryTree * pnode=NULL;
    binaryTree * lchild=NULL;
    binaryTree * rchild=NULL;
};
//先序遍历
void binaryTree::dlr(binaryTree * p)
{
    if(p!=NULL)
    {
        cout<<p->data<<' ';
        dlr(p->lchild);
        dlr(p->rchild);
    }
}
//中序遍历
void binaryTree::ldr(binaryTree * p)
{
    if(p!=NULL)
    {
        ldr(p->lchild);
        cout<<p->data<<' ';
        ldr(p->rchild);
    }
}
//后序遍历
void binaryTree::lrd(binaryTree * p)
{
    if(p!=NULL)
    {
        lrd(p->lchild);
        lrd(p->rchild);
        cout<<p->data<<' ';
    }
}
//创建二叉树
void binaryTree::createBinaryTree(int n)
{
    int flag;
    cout<<"请输入根节点的值：";
    cin>>data;
    n--;
    binaryTree *p=this;
    while(n)
    {
        cout<<"请输入下一个值的位置"<<endl;
        cout<<"1.左子节点 2.右子节点 3.回到父节点"<<endl;
        cin>>flag;
        //下一个是左子节点的情况
        if (flag==1)
        {
            n--;
            binaryTree *temp=new binaryTree;
            temp->lchild=NULL;
            temp->rchild=NULL;
            cout<<"请输入下一个节点的值：";
            cin>>temp->data;
            p->lchild=temp;
            temp->pnode=p;
            p=p->lchild;
        }
        //下一个是右子节点的情况
        else if (flag==2)
        {
            n--;
            binaryTree *temp=new binaryTree;
            temp->lchild=NULL;
            temp->rchild=NULL;
            cout<<"请输入下一个节点的值：";
            cin>>temp->data;
            p->rchild=temp;
            temp->pnode=p;
            p=p->rchild;
        }
        //需要回到上一个节点的情况
        else if (flag==3)
        {
            p=p->pnode;
            cout<<"当前节点的值为："<<p->data<<endl;
        }
    }
}

int main()
{
    int n;
    binaryTree binarytree;
    cout<<"请输入节点数：";//输入节点数
    cin>>n;
    binarytree.createBinaryTree(n);//创建二叉树
    cout<<"先序遍历：";
    binarytree.dlr(&binarytree);
    cout<<"\n中序遍历：";
    binarytree.ldr(&binarytree);
    cout<<"\n后序遍历：";
    binarytree.lrd(&binarytree);
}
