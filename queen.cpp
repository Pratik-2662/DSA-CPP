#include <iostream>
#include <string.h>
using namespace std;

void permutation(string s, int len, int pos)
{
    if (pos == len)
    {
        cout << s << endl;
        return;
    }
    else
    {
        for (int i = pos; i < len; i++)
        {
            swap(s[pos], s[i]);
            permutation(s, len, pos + 1);
            swap(s[pos], s[i]);
        }
    }
}
int sum;
void rec(int n)
{
    sum = sum + n;
    if (n == 100)
    {
        cout << sum;
        return;
    }
    // cout<<n<<" ";
    rec(n + 1);
}
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return factorial(n - 1) * n;
}
int main()
{
    // string s = "ABC";
    // int len = s.length();
    // permutation(s,len,0);
    // rec(1);
    cout << factorial(30);

    return 0;
}