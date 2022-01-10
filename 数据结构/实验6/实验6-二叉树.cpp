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
//�������
void binaryTree::dlr(binaryTree * p)
{
    if(p!=NULL)
    {
        cout<<p->data<<' ';
        dlr(p->lchild);
        dlr(p->rchild);
    }
}
//�������
void binaryTree::ldr(binaryTree * p)
{
    if(p!=NULL)
    {
        ldr(p->lchild);
        cout<<p->data<<' ';
        ldr(p->rchild);
    }
}
//�������
void binaryTree::lrd(binaryTree * p)
{
    if(p!=NULL)
    {
        lrd(p->lchild);
        lrd(p->rchild);
        cout<<p->data<<' ';
    }
}
//����������
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
        cout<<"1.���ӽڵ� 2.���ӽڵ� 3.�ص����ڵ�"<<endl;
        cin>>flag;
        //��һ�������ӽڵ�����
        if (flag==1)
        {
            n--;
            binaryTree *temp=new binaryTree;
            temp->lchild=NULL;
            temp->rchild=NULL;
            cout<<"��������һ���ڵ��ֵ��";
            cin>>temp->data;
            p->lchild=temp;
            temp->pnode=p;
            p=p->lchild;
        }
        //��һ�������ӽڵ�����
        else if (flag==2)
        {
            n--;
            binaryTree *temp=new binaryTree;
            temp->lchild=NULL;
            temp->rchild=NULL;
            cout<<"��������һ���ڵ��ֵ��";
            cin>>temp->data;
            p->rchild=temp;
            temp->pnode=p;
            p=p->rchild;
        }
        //��Ҫ�ص���һ���ڵ�����
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
    cout<<"������ڵ�����";//����ڵ���
    cin>>n;
    binarytree.createBinaryTree(n);//����������
    cout<<"���������";
    binarytree.dlr(&binarytree);
    cout<<"\n���������";
    binarytree.ldr(&binarytree);
    cout<<"\n���������";
    binarytree.lrd(&binarytree);
}
