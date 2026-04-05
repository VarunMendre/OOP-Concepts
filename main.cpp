#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        // n = no of bags, k = minutes
        int n, k;

        cin >> n >> k;
        multiset<long long> bags;

        // O(n * log n) time complexity, as we are inserting n elements into the multiset, each insertion taking O(log n) time
        for (int i = 0; i < n; i++)
        {
            long long candies;
            cin >> candies;
            bags.insert(candies);
        }

        long long total_candies = 0;


        // O(k * log n) time complexity, as we are performing k iterations and each iteration involves O(log n) operations for erasing and inserting elements in the multiset
        for (int i = 0; i < k; i++)
        {
            // auto it = prev(bags.end());
            auto it = (--bags.end());
            long long candies = *it;

            total_candies += candies;
            bags.erase(it); // O(1) operation, remove only that particular element not all occurrences of that element

            long long new_candies = candies / 2;
            bags.insert(new_candies); // O(log n) operation, insert the new candies back into the multiset
        }

        cout<< total_candies << endl;
    }

    return 0;
}
