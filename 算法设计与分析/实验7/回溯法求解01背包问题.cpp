#include <iostream>
#include <stack> //���������еİ�����Ҫ���к���ȳ��Ĳ�������˿��ǵ�ʹ��ջ�������ݽṹ������ȳ���
using namespace std;

int backTrack(int w[], int v[], int length, int capacity, int tw)
{
    stack<int> Bag; //���ȹ����һ���յı���
    int max = 0;    //��ͬװ������б�������Ʒ���ļ�ֵ
    int weight = 0; //��ǰ��������Ʒ��������
    int value = 0;  //��ǰ��������Ʒ���ܼ�ֵ
    int i;
    int rw = tw;
    for (i = 0;; i++)
    {
        if (weight + w[i] < capacity) // ����װ�����Ʒ�󲻻ᳬ�ؾ�������װ����������˾Ͳ�װ
        {
            Bag.push(i);
            weight += w[i];
            value += v[i];
            rw -= w[i];
        }
        else if (weight + w[i] == capacity) // ���֦
        {
            Bag.push(i);
            weight += w[i];
            value += v[i];
            rw -= w[i];
            i = length - 1;
        }
        if (weight + rw < capacity) //�Ҽ�֦
        {
            i = length - 1;
        }

        //�����Ե����һ����Ʒ��ʱ��һ�����Ѿ�������һ��װ�䷽����
        if (i == length - 1)
        {
            //��֮ǰ�����װ�䷽�����бȽϣ���������
            if (max < value)
            {
                max = value;
            }
            //����
            {
                i = Bag.top(); //ȡ����һ��װ��Ķ���
                Bag.pop();
                weight -= w[i];
                value -= v[i];
                rw += w[i];
                if (i == length - 1) //����ǰ�治��ֻ�����һ��������󣬾�Ҫ�Ե����ڶ������г����ˣ����Կ������������Ӱ�����ȡ��������Ʒ
                {
                    if (Bag.empty())
                        break;     //��������֤��ȫ����������ݹ���
                    i = Bag.top(); //ȡ����һ��װ��Ķ�������ȡ���Σ�
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
    cout << "��������Ʒ�ĸ�����";
    cin >> num;
    int *weights = new int[num];
    int *values = new int[num];
    cout << "������ÿ����Ʒ��������";
    for (int i = 0; i < num; i++)
    {
        cin >> weights[i];
        tw += weights[i];
    }
    cout << "������ÿ����Ʒ�ļ�ֵ��";
    for (int i = 0; i < num; i++)
    {
        cin >> values[i];
    }
    cout << "��������������أ�";
    cin >> capacity;
    cout << "����������Ž�Ϊ��" << backTrack(weights, values, num, capacity, tw) << endl;
    system("pause");
    return 0;
}

