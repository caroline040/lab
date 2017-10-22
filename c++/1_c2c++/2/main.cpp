#include <iostream>

using namespace std;

int main(void)
{
    cout << "请输入天数（整数）:" << endl;

    int days;
    cin >> days;

    if(days < 0)
    {
        cout << "非法输入，再见！" << endl;
        return 0;
    }

    cout << days << "天 = " << days/7 << "个星期零" << days%7 << "天" << endl;

    return 0;
}
