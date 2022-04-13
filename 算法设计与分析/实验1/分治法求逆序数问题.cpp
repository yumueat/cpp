#include<iostream>
using namespace std; 
int ans;		 		
void Merge(int a[],int low,int mid,int high) //二路归并 
{  
//	cout<<low<<' '<<high<<endl;
   int i=low;
   int j=mid+1;
   int k=0;
   int *tmp=(int *)malloc((high-low+1)*sizeof(int));
   while(i<=mid && j<=high) 		
   {  if(a[i]>a[j])
      {  tmp[k++]=a[j++];
         ans+=mid-i+1;
      }
      else tmp[k++]=a[i++];
   }
   while(i<=mid) tmp[k++]=a[i++];
   while(j<=high) tmp[k++]=a[j++];
   for(int k1=0;k1<k;k1++)		
       a[low+k1]=tmp[k1];
   free(tmp);
}
void get_reverse_order_pair_num(int a[],int start,int end)//递归的划分数组以调用二路归并算法进行排序和计数 
{
	if (start == end - 1)//划分到最小单位的情况 
	{
		Merge(a,start,start,end); 
	}
	else if(start == end - 2)//3个时的特殊情况 
	{
		Merge(a,start,start,start+1);
		Merge(a,start,start+1,end);
	} 
	else//递归 
	{
		int start1=start;
		int end1=(start+end)/2;
		int start2=end1+1;
		int end2=end;
		get_reverse_order_pair_num(a,start1,end1);
		get_reverse_order_pair_num(a,start2,end2);
		Merge(a,start,(start+end)/2,end);
	}
}
int main()
{
	int a[]={3,1,4,5,2};//要求的整数数组 
	get_reverse_order_pair_num(a,0,4);
	cout<<ans;
//	for (int i=0;i<=4;i++)
//	{
//		cout<<a[i]<<' ';
//	} 
	return 0;
}
