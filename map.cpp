#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<int, string> m;
    m.insert(make_pair(1, "Pratik"));
    m[26] = "vinay";
    m[30] = "vinay";
    m[44] = "vinay";
    m[50] = "vinay";
    m[62] = "vinay";
    m[26] = "pk";
    m.insert(make_pair(1, "string"));
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << m.count(33);
}
