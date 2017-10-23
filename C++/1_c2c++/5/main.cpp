#include <iostream>
#include <list>

using namespace std;

void show(list<int> &mylist)
{
    for(list<int>::iterator p = mylist.begin(); p!=mylist.end(); ++p)
    {
        if(p == mylist.begin())
            cout << *p;

        else
            cout << "-->" << *p;
    }
    cout << endl;
}

void rearrange(list<int> &mylist)
{
    for(list<int>::reverse_iterator rp = mylist.rbegin(); rp!=mylist.rend(); ++rp)
    {
        if(*rp % 2 == 0) // 偶数，移到链表的末尾
        {
            int tmp = *rp;

            mylist.remove(tmp);
            mylist.push_back(tmp);
        }
    }
}

int main()
{
    list<int> mylist;

    cout << "请输入链表中元素的总数：" << endl;
    int total;
    cin >> total;

    for(int i=1; i<=total; ++i)
    {
        mylist.push_back(i);
    }

    cout << "链表初始状态为：";
    show(mylist);

    cout << "奇偶数重新排列：";
    rearrange(mylist);
    show(mylist);

    return 0;
}

