#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;

    int  *a = new int[n + 1];
    int  *b = new int[n + 1];
    int  *c = new int[n + 1];

    string *str = new string[n + 1];

    int st1 = 1;
    for (int i = 0; i <=n; i++)
    {
        a[i] = 1;
        c[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        string str2;
        getline(cin, str2);
        if (p == 0)
        {
            a[i]++;
            getline(cin, str[i]);
            st1++;
            getline(cin, str2);
        }
        else
        {
                c[i] = p;
                getline(cin, str2);
        }
    }

    for (int i = n; i > 0; i--)
    {
        a[c[i]] = a[c[i]] + a[i];
    }

    int max = a[1];
    int maxi = 1;
    for (int i = 1; i <= n; i++)
    {
        if (max < a[i] )
        {
            max = a[i];
            maxi = i;
        }
    }
    cout << str[maxi] << endl;

    return 0;
}
