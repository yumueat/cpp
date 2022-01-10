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
    cout<<"��������ڵ��ֵ��";
    cin>>data;
    n--;
    binaryTree *p=this;
    while(n)
    {
        cout<<"��������һ��ֵ��λ��"<<endl;
        cout<<"1.�ӽڵ� 2.�ֵܽڵ� 3.�ص���һ���ڵ�"<<endl;
        cin>>flag;
        if (flag==1)
        {
            n--;
            binaryTree *temp=new binaryTree;
            temp->cnode=NULL;
            temp->bnode=NULL;
            cout<<"��������һ���ڵ��ֵ��";
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
            cout<<"��������һ���ڵ��ֵ��";
            cin>>temp->data;
            p->bnode=temp;
            temp->pnode=p;
            p=p->bnode;
        }
        else if (flag==3)
        {
            p=p->pnode;
            cout<<"��ǰ�ڵ��ֵΪ��"<<p->data<<endl;
        }
    }
}

int main()
{
    int n;
    binaryTree binarytree;
    cout<<"������ڵ�����";
    cin>>n;
    binarytree.createBinaryTree(n);
    cout<<"���������";
    binarytree.dlr(&binarytree);
    cout<<"\n���������";
    binarytree.ldr(&binarytree);
    cout<<"\n���������";
    binarytree.lrd(&binarytree);
}
