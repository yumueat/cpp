#include <iostream>
#include <stack> //由于问题中的包是需要进行后进先出的操作，因此考虑到使用栈这种数据结构（后进先出）
using namespace std;

int backTrack(int w[], int v[], int length, int capacity, int tw)
{
    stack<int> Bag; //首先构造出一个空的背包
    int max = 0;    //不同装入情况中背包中物品最大的价值
    int weight = 0; //当前背包中物品的总重量
    int value = 0;  //当前背包中物品的总价值
    int i;
    int rw = tw;
    for (i = 0;; i++)
    {
        if (weight + w[i] < capacity) // 背包装入该物品后不会超重就往里面装，如果超重了就不装
        {
            Bag.push(i);
            weight += w[i];
            value += v[i];
            rw -= w[i];
        }
        else if (weight + w[i] == capacity) // 左剪枝
        {
            Bag.push(i);
            weight += w[i];
            value += v[i];
            rw -= w[i];
            i = length - 1;
        }
        if (weight + rw < capacity) //右剪枝
        {
            i = length - 1;
        }

        //当尝试到最后一个物品的时候一定是已经生成了一个装配方案的
        if (i == length - 1)
        {
            //与之前的最大装配方案进行比较，留下最大的
            if (max < value)
            {
                max = value;
            }
            //回溯
            {
                i = Bag.top(); //取出上一件装入的东西
                Bag.pop();
                weight -= w[i];
                value -= v[i];
                rw += w[i];
                if (i == length - 1) //保持前面不动只改最后一个尝试完后，就要对倒数第二个进行尝试了，所以看起来是连续从包里面取了两个物品
                {
                    if (Bag.empty())
                        break;     //背包空则证明全部情况都回溯过了
                    i = Bag.top(); //取出上一件装入的东西（连取两次）
                    Bag.pop();
                    weight -= w[i];
                    value -= v[i];
                    rw += w[i];
                }
            }
        }
    }
    return max;
}

int main(void)
{
    int num, capacity, tw = 0;
    cout << "请输入物品的个数：";
    cin >> num;
    int *weights = new int[num];
    int *values = new int[num];
    cout << "请输入每件物品的重量：";
    for (int i = 0; i < num; i++)
    {
        cin >> weights[i];
        tw += weights[i];
    }
    cout << "请输入每件物品的价值：";
    for (int i = 0; i < num; i++)
    {
        cin >> values[i];
    }
    cout << "请输入包的最大承重：";
    cin >> capacity;
    cout << "该问题的最优解为：" << backTrack(weights, values, num, capacity, tw) << endl;
    system("pause");
    return 0;
}

