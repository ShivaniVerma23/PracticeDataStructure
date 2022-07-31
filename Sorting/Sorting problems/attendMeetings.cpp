#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



bool sortcol(const vector<int>&v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}
int can_attend_all_meetings(vector<vector<int>> &intervals) {
    // Write your code here.
    int numOfMeetings = intervals.size();
    
    sort(intervals.begin(), intervals.end(), sortcol);
    int start_time = 0;
    int end_time = 0 ;
    int prev_end_time = 0 ;
    
    for (auto it = intervals.begin(); it!= intervals.end(); it++)
    {
        vector <int> row = *it;

        auto itr = row.begin();
        start_time = *itr;
        end_time = *(++itr);
        if (prev_end_time > start_time)
        {
             return 0;
        }
    prev_end_time = end_time;
        
    }
    
    return 1;
}

int main()
{
    vector<vector<int>> timings ={{1, 5}, {5, 8}, {10, 15}};
    int numOfMeetings{0};

    numOfMeetings = can_attend_all_meetings(timings);

    cout << numOfMeetings<<endl;

    return 0;
}