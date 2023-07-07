#include <bits/stdc++.h>

using namespace std;
struct workshops
{
    int start_time;
    int duration;
    int end_time;
};
struct Available_Workshops
{
    int n;
    vector<workshops> *arr = new vector<workshops>(n);
};
Available_Workshops *initialize(int start_time[], int duration[], int n)
{
    Available_Workshops *aw = new Available_Workshops();
    aw->n = n;
    for (int i = 0; i < n; i++)
    {
        workshops *w = new workshops();
        (*w).start_time = start_time[i];
        w->duration = duration[i];
        w->end_time = start_time[i] + duration[i];
        aw->arr->push_back(*w);
    }
}
bool comp(const workshops &a, const workshops &b)
{
    return a.end_time < b.end_time;
}
int CalculateMaxWorkShops(Available_Workshops *ptr)
{
    sort(ptr->arr->begin(), ptr->arr->end(), comp);
    int res = 0;
    int e_time = 0;
    for (int i = 0; i < ptr->n; i++)
    {
        workshops current = ptr->arr->at(i);
        if (current.start_time >= e_time)
        {
            res++;
            e_time = ptr->arr->at(i).end_time;
        }
    }
    return res;
}
int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkShops(ptr) << endl;
    return 0;
}
