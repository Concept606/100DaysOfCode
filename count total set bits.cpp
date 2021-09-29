// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    
    
    int countSetBits(int n)
    {
        /*If a number is given n and we have to count toal set bits from 1 to n we can count the 
    maximum power of 2 of that number and then total set bit from 1 to pow(2,maxPower) will be
    pow(2,maxPower-1) * no of bits to represent pow(2,maxpower)-1.
    
    And after that we recursively call the function
    
    Suppose if n= 9
    then from 1 to 5 is 
            total set bit
    
    001     1 
    010     2
    011     4   
    100     5
    101     7
    110     9   
    111     12
    
    1000    13  
    1001    15
    
    now max power of 2 is 3 
    now from 1 to 7 total set bit is:
    
    putting in formula pow(2,(3-1))*3=12
    
    After that we know that msb is 1 after that. So we delete that value and the rest is same.
    
    
    
    */
    
        
        if(n==0) return 0;
        int powOf2=maxPowOf2(n);
        int ans = powOf2*(1<<(powOf2-1)) + (n-(1<<powOf2))+1+countSetBits(n-(1<<powOf2));
        
        return ans;    
        
    }
    
    int maxPowOf2(int n){
        int count=0;
        while((1<<count)<=n)
            count++;
        return count-1;
    }
};