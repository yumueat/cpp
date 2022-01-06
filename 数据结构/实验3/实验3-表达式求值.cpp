#include <iostream>
using namespace std;
int getindex(char a)//获取相应符号对应的索引值，用于在表格中获取大小比较结果
{
    switch (a)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 3;
    case '(':
        return 4;
    case ')':
        return 5;
    case '#':
        return 6;
    default:
        break;
    }
}
char compare(char a,char b)//比较两个符号的优先级
{
    const char tableofoptr[][7]=
    {
        { '>','>','<','<','<','>','>' },
		{ '>','>','<','<','<','>','>' },
		{ '>','>','>','>','<','>','>' },
		{ '>','>','>','>','<','>','>' },
		{ '<','<','<','<','<','=','0' },
		{ '>','>','>','>','0','>','>' },
		{ '<','<','<','<','<','0','=' },
    };
    return tableofoptr[getindex(a)][getindex(b)];
}
int calcu(int a,int b,char opt)//按照符号计算
{
    switch (opt)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    
    default:
        break;
    }
}
void ans(char a[])//获取答案
{
    int i=0,flag=0,j=0,k=0,temp1,temp2;//i用于表达式定位，j用于操作数栈定位，k用于操作符栈定位 
    int opnd[255];//定义操作数栈储存操作数
    opnd[0]=0;
    char optr[255];//定义操作符栈储存操作符
    optr[0]='#';//把第一个赋值为#作为标记，使得后面的比较能遵循唯一规律
    char res,temp;
    while (a[i-1]!='#')//依位读入要运算的表达式
    {
        if (a[i]>='0'&&a[i]<='9')//判断是否是操作数
        {
            if (flag==0)//利用flag来判断前一位是否是数字，如果不是直接存入
            {
                flag=1;
                opnd[j]=a[i]-'0';
            }
            else if(flag==1)//如果前一位是数字，则要把相连的数字当作同一个数字来储存
            {
                opnd[j]=opnd[j]*10+(a[i]-'0');
            }
            i++;//准备读表达式下一位
        }
        else//处理是操作符的情况
        {
            if (flag==1)//如果上一个字符是操作数，则将flag记0，在下一个判断flag时则能表示上一位时操作符
            {
                flag=0;
                j++;//将操作数数组的定位往后移
            }
            res=compare(optr[k],a[i]);//比较操作符栈顶的操作符和表达式中的当前操作符的优先级
            switch (res)//按不同的优先级进行相应操作
            {
            case '<'://如果操作符栈顶的操作符优先级小于表达式当前操作符优先级，则将表达式当前操作符入栈，因为其优先级更高，所以要存入来和后续的进行比较，直至找出优先级最高的，也就是最先要被计算的
                optr[++k]=a[i];//入栈
                i++;//改变表达式的定位 
                break;
            case '='://如果为等于，则直接把栈顶操作符出栈，这一项时专门为处理括号和#准备的，因为只有（）和#才会出现=的情况
                k--;
                i++;
                break;
            case '>'://如果是大于，则直接把操作符栈顶元素出栈，调用函数进行计算
                temp=optr[k];//取出操作符栈顶元素
                k--;//出栈
                temp1=j-1;
                temp2=j-2;//准备调取操作数栈的元素
                j=temp2;//改变操作数栈的定位，便于储存计算后的结果
                opnd[j]=calcu(opnd[temp2],opnd[temp1],temp);//调用函数进行计算
                j++;//改变操作数栈的定位，便于存入下一个元素
                //注意这里不改变表达式的定位，因为还要用当前的表达式字符和上一个操作符栈的元素比较
                break;
            default:
                break;
            }
        }
    }
    cout<<opnd[0]<<endl;//因为操作数计算其实就是前后两个数不断运算，所以最后的结果会出现在栈顶，但计算到最后的操作数栈只有一个数了，此时栈顶元素和栈底元素相同
}
int main()
{
    char a[255];
    cin>>a;//存入表达式
    ans(a);//调用函数进行表达式运算
    return 0;
}
