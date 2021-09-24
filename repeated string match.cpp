//https://practice.geeksforgeeks.org/problems/0cba668df04d657fde4d1bd28b626a01e61097f1/1#

//https://www.geeksforgeeks.org/minimum-number-of-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it/

class Solution{

    public:
    int repeatedStringMatch(string A, string B) 
    {
        //if A conatins B then A.length()>=B.length()
        //so we get a new string s and increment it until it is larger/equal
        //than B
        //now if s contains B we return ans otherwise we return ans+1 as we have
        //add A to s again
        string s=A;
        
        int ans =1;
        
        while(s.size()<B.size()){
            s+=A;
            ans++;
        }
        
        if(isSubString(B,s)) return ans;
        
        if(isSubString(B,s+A)) return ans+1;
        
        else return -1;
    }
    //function to check the substring
    bool isSubString(string B,string S){
        
        int len1 = B.length(), len2= S.length();
        //len2-len1 is the max diff between two stirngs
        for(int i=0;i<=len2-len1;i++){
            int j;
            //checking for if any element of S is match with B or not
            for(j=0;j<len1;j++)
                if(S[i+j] != B[j])
                    break;
            
            if(j==len1)
            return true;
        }
        return false;
    }
  
};