#include <iostream>
#include <iomanip>
#include<windows.h>
using namespace std;
int main()
{
    int min;
    for (int min = 5; min > 0; min--)
    {
        for (int sec = 59; sec < 60; sec--)
        {
            cout << left << setw(2) << min << sec;
            cout.flush();

            Sleep(1000);
            cout << '\r';

            if (sec < 1)
                break;
        }
        if (min == 0)
        {
            cout << "Time's up!" << endl;
        }
    }
    system("pause");
    return 0;
}