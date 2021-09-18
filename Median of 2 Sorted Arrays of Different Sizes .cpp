//https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        int m=array1.size();
        //created a min heap and pushing array1 to min heap
        priority_queue<int,vector<int>,greater<int>> sorted(array1.begin(),array1.end());
        
        int n= array2.size();
        //pushing array2 to min heap
        for(int i=0;i<n;i++)
        sorted.push(array2[i]);
        
        double res;
        
        
        
        //if size of the array is odd then we just have to print
        //the ceil(m+n)/2 else intitalize two variables and one variable
        //contians middle element and another one contains middle_element-1
        
        if((m+n)%2==1){
            int index= (m+n)/2;
            // res = sorted[floor((m+n)/2)];
            for(int i=0;i<=index;i++){
                res= sorted.top();
                sorted.pop();
            }
            return res;
        }
        else{
            // res= double(((sorted[((m+n)/2)-1]+sorted[(m+n)/2)])/2)
            double res1=sorted.top(),res2;
            sorted.pop();
            for(int i=1;i<=(m+n)/2;i++){
                res2=res1;
                res1=sorted.top();
                sorted.pop();
            }
            
            return (res2+res1)/2;
            
        }
    }
};