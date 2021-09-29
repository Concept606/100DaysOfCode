//https://practice.geeksforgeeks.org/problems/cb02d40f50b0113c47cd9036e5f340bb51b32289/1#
//time cx:O(n^2)


class Solution{
    public:
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
        if(N==0) return 1;
        
        if(N == 1)
            return ((preorder[0]==inorder[0]) && (inorder[0]==postorder[0]));
        
        int inIndex=-1, f=0;
        int i;
        //checking preorder[0] in inorder
        for(i =0;i<N;i++){
            if(inorder[i]==preorder[0]){
                inIndex=i;
                break;
            }
        }
        //checkin if preordr[0] exists in postorder or not
        if(inIndex!=-1){
            for(i=0;i<N;i++){
                if(postorder[i]==preorder[0]){
                    f=1;
                    break;
                }
            }
        }
        
        //if preoder doesnot exist in inorder or postorder returnin false
        if(inIndex == -1 || f==0) return 0;
        
        //for left subtree preorder is next index which is currently searched,
        //and length is index of the element in inorder

        int leftTree=checktree(preorder+1,inorder,postorder, inIndex);
        
        //for right subtree
        int rightTree= checktree(preorder+inIndex+1, 
                        inorder+inIndex+1, postorder+inIndex,N-inIndex-1);
        
        return (leftTree && rightTree);
    } 

};

