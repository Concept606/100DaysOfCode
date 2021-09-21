//https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1


class Solution
{
public:
    vector<int> factorial(int N)
    {
        vector<int> result;

        //initializing the result as 1
        result.push_back(1);
        //outer loop contains the value of factorial in each iteration and
        //inner loop contains the answer and if answer size is greater than
        // the vector size then we carry forward to while loop
        //now reverse the vector to get the result
        for (int value = 2; value <= N; value++)
        {
            int carry = 0;
            for (int i = 0; i < result.size(); i++){
                int ans = result[i] * value+carry;
                result[i] = ans % 10;
                carry = ans / 10;
            }
            while (carry != 0)
            {
                result.push_back(carry % 10);
                carry /= 10;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
