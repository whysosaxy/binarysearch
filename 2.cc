#include <cstdio>
#include <cstdint>
#include <vector>
typedef int64_t lld;
using namespace std;

lld f(const vector<lld> &v, const lld key)
{
    lld left {}, right {static_cast<lld>(v.size()) - 1}, mid{-1};
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (key == v.at(mid))
        {
            return mid;
        }
        else if (key < v.at(mid))
        {
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return mid;
}

int main()
{
    lld n, key;
    scanf("%lld %lld", &n, &key);
    vector<lld> v(n);
    for (auto &&i : v)
    {
        scanf("%lld", &i);
    }
    
    lld result { f(v, key) };
    if (result == -1)
    {
        printf("Could not find!");
    }
    else
    {
        printf("Found at index = %lld", result);
    }
    return 0;
}