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
    binaryTree * cnode=NULL;
    binaryTree * bnode=NULL;
};
void binaryTree::dlr(binaryTree * p)
{
    if(p!=NULL)
    {
        cout<<p->data<<' ';
        dlr(p->cnode);
        dlr(p->bnode);
    }
}
void binaryTree::ldr(binaryTree * p)
{
    if(p!=NULL)
    {
        ldr(p->cnode);
        cout<<p->data<<' ';
        ldr(p->bnode);
    }
}
void binaryTree::lrd(binaryTree * p)
{
    if(p!=NULL)
    {
        lrd(p->cnode);
        lrd(p->bnode);
        cout<<p->data<<' ';
    }
}

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
        cout<<"1.子节点 2.兄弟节点 3.回到上一个节点"<<endl;
        cin>>flag;
        if (flag==1)
        {
            n--;
            binaryTree *temp=new binaryTree;
            temp->cnode=NULL;
            temp->bnode=NULL;
            cout<<"请输入下一个节点的值：";
            cin>>temp->data;
            p->cnode=temp;
            temp->pnode=p;
            p=p->cnode;
        }
        else if (flag==2)
        {
            n--;
            binaryTree *temp=new binaryTree;
            temp->cnode=NULL;
            temp->bnode=NULL;
            cout<<"请输入下一个节点的值：";
            cin>>temp->data;
            p->bnode=temp;
            temp->pnode=p;
            p=p->bnode;
        }
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
    cout<<"请输入节点数：";
    cin>>n;
    binarytree.createBinaryTree(n);
    cout<<"先序遍历：";
    binarytree.dlr(&binarytree);
    cout<<"\n中序遍历：";
    binarytree.ldr(&binarytree);
    cout<<"\n后序遍历：";
    binarytree.lrd(&binarytree);
}
