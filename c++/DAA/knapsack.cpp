#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class item
{
public:
    float weight, profit;
    float ratio;
    item(float w, float p) : weight(w), profit(p)
    {
        ratio = (p / w);
    }
};
class knapsack
{
public:
    float capacity;
    vector<item> items;
    knapsack(float c) : capacity(c) {}
    void addItems(item i)
    {
        items.push_back(i);
    }
    float solve()
    {
        int n = items.size();
        sort(items.begin(), items.end(), [](item &a, item &b)
             { return a.ratio > b.ratio; });
        float total_wt = 0, total_cost = 0;
        for (auto &i : items)
        {
            if (i.weight <= capacity)
            {
                total_wt += i.weight;
                total_cost += i.profit;
                capacity -= i.weight;
                cout << "wt: " << total_wt << endl;
                cout << "pr: " << total_cost << endl;
                cout << "cap: " << capacity << endl;
            }
            else
            {
                total_wt += capacity;
                total_cost += capacity * i.ratio;
                capacity = 0;
                cout << "wt: " << total_wt << endl;
                cout << "pr: " << total_cost << endl;
                cout << "cap: " << capacity << endl;
                // cout<<"tc: "<<total_cost<<endl;
                break;
            }
        }

        return total_cost;
    }
};
int main()
{
    vector<item> items = {item(5, 30), item(15, 45), item(22, 77), item(10, 40), item(25, 90)};
    knapsack k(60);
    for (auto &i : items)
    {
        k.addItems(i);
    }
    cout << "max profit: " << k.solve() << endl;
    return 0;
}