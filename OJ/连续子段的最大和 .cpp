#include<stdio.h>
int MaxSubSum(int A[],int left,int right);
int main()
{
	int A[5]={1,-3,4,1,-9};
	int max=MaxSubSum(A,0,4);
	printf("����ֶκ�Ϊ��");
	printf("%dn",max);
	return 0; 
 
}
int MaxSubSum(int A[],int left,int right)
{
		int leftsum=0;
		int rightsum=0;
		int s1=0;
		int s2=0;
		int i;
int	center=(left+right)/2;
		if(left==right)
		{
			if(A[left]<0)//��ĿҪ�����ֵ����0
				return 0;
			else
 
			return A[left];
		}
	 leftsum=MaxSubSum(A,left,center);//�ݹ���������
	 rightsum=MaxSubSum(A,center+1,right);//�ݹ���������
	 s1=A[center];//��Ŵ��м俪ʼ����ߵ���������Ӷ�
	 s2=A[center+1];//��Ŵ��м俪ʼ���ұߵ���������Ӷ�
	 int temp1=A[center];//��ʱ����
	 int temp2=A[center+1];
	 for( i=center-1;i>=0;i--)//���S1���������ֵ
	 {	
		 
		 temp1=A[i]+temp1;//���м䵽���һֱ��ֵ
		 if(s1<temp1)
			 s1=temp1;//���м䵽���һֱ��ֵ,s1Ϊ���ֵ
	 }
 
	 for( i=center+2;i<=right;i++)//���S2���������ֵ
	 {
		  temp2=A[i]+temp2;
		 if(s2<temp2)
			 s2=temp2;
		 
	 }
	 int sum=s1+s2;
	 if(leftsum>sum)
		 sum=leftsum;
	 if(rightsum>sum)
		 sum=rightsum;
	 return sum;//���ظõݹ���������һ��ֵ
 
}
