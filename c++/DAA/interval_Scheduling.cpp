// greedy algorithm
// interval scheduling problem(activity selection)
#include <iostream>
#include <algorithm>
using namespace std;
class activity
{
public:
    int ac_id, st_time, fn_time;
    void getDetail(int id, int ST, int FT)
    {
        ac_id = id;
        st_time = ST;
        fn_time = FT;
    }
};
void swap(activity &a, activity &b) {
    activity temp = a;
    a = b;
    b = temp;
}
class actSelection
{
public:
    activity activities[6];
    int n = 6;
    actSelection() : n(6) {}

    void addActivities()
    {
        activities[0].getDetail(1, 0, 6);
        activities[1].getDetail(2, 1, 2);
        activities[2].getDetail(3, 3, 4);
        activities[3].getDetail(4, 5, 7);
        activities[4].getDetail(5, 5, 9);
        activities[5].getDetail(6, 8, 9);
    }
    void Sort(){
        sort(activities, activities + n, [](const activity &a, const activity &b) {
    return a.fn_time < b.fn_time;
        });
    }
    void selectActivity()
    {
        cout << "selected activities are: " << endl;
        int selected = 0;
        cout << activities[selected].ac_id << ": (" << activities[selected].st_time << " , " << activities[selected].fn_time << ")" << endl;
        for (int i = 1; i < n; i++)
        {
            if (activities[i].st_time >= activities[selected].fn_time)
            {

                selected = i;
                cout << activities[selected].ac_id << ": (" << activities[selected].st_time << " , " << activities[selected].fn_time << ")" << endl;
            }
        }
    }
};
int main()
{
    actSelection selector;
    selector.addActivities();
    selector.Sort();
    selector.selectActivity();
}