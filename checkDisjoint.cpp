#include <iostream>
#include <set>
using namespace std;
bool isDisjoint(int s1[], int s2[], int n1, int n2)
{
    set<int> s;
    for (int i = 0; i < n1; i++)
    {
        s.insert(s1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        s.insert(s2[i]);
    }
    if (s.size() != n1 + n2)
    {
        return 0;
    }
    return 1;
}
int main()
{
    int set1[] = {12, 34, 11, 9, 3};
    int set2[] = {2, 1, 3, 5};
    int n1 = sizeof(set1) / sizeof(set1[0]);
    int n2 = sizeof(set2) / sizeof(set1[0]);
    isDisjoint(set1, set2, n1, n2) ? cout << "Disjoint" : cout << "Not a Disjoint";
}