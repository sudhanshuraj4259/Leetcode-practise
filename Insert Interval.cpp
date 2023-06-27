class Solution {
public:
    int bsearch(vector<vector<int>>& intervals, int target)
    {
        int n= intervals.size();
        int low=0, high=n-1, mid, ans=-1;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(intervals[mid][0]<target)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans+1;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // occurrence of last interval whoose start is strictly less than start of new interval;
        int idx= bsearch(intervals, newInterval[0]); 
        //cout<<idx<<"\n";   ✔correct index obtained
        int n=intervals.size();
        //initially non-overlapping, therefore no two start indices will be the same
        int pos;
        if(idx!=0)
        {
            // compare with the previous
            if(newInterval[0]<=intervals[idx-1][1])
            {
                intervals[idx-1][1]=max(intervals[idx-1][1], newInterval[1]);
                pos=idx-1;
            }
            else
            {
                pos=idx;
                intervals.insert(intervals.begin()+idx, newInterval);
                n++;
            }
        }
        else
        {
            intervals.insert(intervals.begin()+idx, newInterval);
            pos=idx;
            n++;
        }
        vector<bool>include(n, true);
        int prev=pos;
        // now only overlapping interval to be checked from position-pos onwards
        for(int i=pos+1;i<n;i++)
        {
            if(intervals[i][0]<=intervals[prev][1])//overlap
            {
                intervals[prev][1]=max(intervals[prev][1], intervals[i][1]);
                include[i]=false;
            }
            else
            {
                prev=i;
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(include[i])
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};
