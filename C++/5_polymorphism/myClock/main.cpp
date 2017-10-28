#include <iostream>
#include <unistd.h>
#include "myclock.h"

using namespace std;

int main()
{
    myClock clock(57, 58);

    while(1)
    {
        cout << clock << endl;
        clock++;

        usleep(100*1000);
    }

    return 0;
}

