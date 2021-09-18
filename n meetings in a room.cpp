// https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/


class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    // bool sortbysec(static pair<int,int> &a,
    //               static pair<int,int> &b)
    // {
    //     return (a.second < b.second);
    // }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meet;
        
        for(int i=0;i<n;i++)
            meet.push_back(make_pair(end[i],start[i]));
        
       sort(meet.begin(), meet.end());
       // [&](pair<int,int> a,pair<int,int>b){
    //       return a.second<b.second;
    //   }
        
        int time_limit = meet[0].first;
        
        vector<pair<int,int>> result;
        
        result.push_back(meet[0]);
        int cnt=1;
        for(int i=1;i<n;i++){
            if(meet[i].second > time_limit){
                cnt++;
                time_limit=meet[i].first;
                result.push_back(meet[i]);
            }
        }
        return cnt;
    }
};