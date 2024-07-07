#include <cstdio>
#include <cstdint>
#include <vector>
typedef int64_t lld;
using namespace std;

lld f(const vector<lld> &v, const lld key)
{
    lld left {}, right {static_cast<lld>(v.size()) - 1}, mid;
    lld first_occurence{-1};
    bool is_ascending {v.front() < v.back()};
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (key == v.at(mid))
        {
            first_occurence = mid;
            right = mid - 1;
        }
        else if (key < v.at(mid))
        {
            is_ascending ? right = mid - 1 : left = mid + 1;
        }
        else
        {
            is_ascending ? left = mid + 1 : right = mid - 1;
        }
    }
    return first_occurence;
}

lld g(const vector<lld> &v, const lld key)
{
    lld left {}, right {static_cast<lld>(v.size()) - 1}, mid;
    lld last_occurence{-1};
    bool is_ascending {v.front() < v.back()};
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (key == v.at(mid))
        {
            last_occurence = mid;
            left = mid + 1;
        }
        else if (key < v.at(mid))
        {
            is_ascending ? right = mid - 1 : left = mid + 1;
        }
        else
        {
            is_ascending ? left = mid + 1 : right = mid - 1;
        }
    }
    return last_occurence;
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
    
    lld result { g(v, key) == -1 ? 0 : g(v, key) - f(v, key) + 1};
    printf("Count of %lld in the array is = %lld\n", key, result);
    return 0;
}