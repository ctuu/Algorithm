#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cun;
    int a[6] = {0};
    int ia[6] = {0};
    int t;
    cin >> t;
    while (t--)
    {
        cin >> cun;
        int i = cun % 5;
        switch (i)
        {
            case 0:
                if (!(cun & 1))
                {
                    a[0] += cun;
                    ia[0] = 1;
                }
                break;
            case 1:
                ++ia[1];
                if (ia[i] &1)
                    a[1] += cun;
                else
                    a[1] -= cun;
                break;
            case 2:
                ++a[2];
                ia[2] = 1;
                break;
            case 3:
                a[3] += cun;
               ++ia[3];
                break;
            case 4:
                a[4] = max (a[4], cun);
                ia[4] = 1;
                break;
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        if (i)
            cout << " ";
        if (!ia[i])
        {
            cout << "N";
            continue;
        }
        if (i == 0 || i == 1 || i == 4)
            cout << a[i];
        else if (i == 2)
            cout << a[i];
        else if (i == 3)
            cout << setprecision(1) << fixed << (double) a[3] / (double) ia[3];
    }
    return 0;
}
