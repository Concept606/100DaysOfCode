//https://practice.geeksforgeeks.org/problems/10471201e923a0b88a0c1482e6c7e8cc6fdfe93a/1

class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 
        // I followed here two pointer method, at first I intialize staring 
        // and ending indexes values in two variables.
        // now answer is maximum value of answer and the following
        // then if the value height of end is greater than height of start we 
        // increase the starting index as it cotains the small element otherwise
        // I decrease ending index as ending value contains the small element 
        int start=0, end= n-1;
        int answer=0;
        while(start<end){
            answer = max(answer,min(height[start],height[end])*(end-start-1));
            if(height[end]>height[start]) start++;
            else end--;
            
        }
        return answer;
    }   
};