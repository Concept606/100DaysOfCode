//https://practice.geeksforgeeks.org/problems/sum-of-query-ii5310/1

class Solution{
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        vector<int>result;
        vector<int>preSum(n);
        preSum[0]=arr[0];
        
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+arr[i];
        }
        
        for(int i=0;i<2*q;i+=2){
            int left= queries[i]-1;
            int right=queries[i+1]-1;
            int sum=0;
            if(left==0)
                result.push_back(preSum[right]);
            else
                result.push_back(preSum[right]-preSum[left-1]);
        }
        return result;
    }
};