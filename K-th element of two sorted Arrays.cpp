//https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/


class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        priority_queue<int,vector<int>,greater<int>> sorted(arr1,arr1+n);
        for(int i=0;i<m;i++)
            sorted.push(arr2[i]);
        int res;
        for(int i=0;i<k;i++){
            res= sorted.top();
            sorted.pop();}
        return res;
    }
};

// { Driver Code Starts.
 
// Driver code
