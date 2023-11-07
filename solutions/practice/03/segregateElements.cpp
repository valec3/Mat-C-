class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                pos.push_back(arr[i]);
            }
            else{
                neg.push_back(arr[i]);
            }
        }
        for (int i = 0; i < neg.size(); i++)
        {
            ans.push_back(neg[i]);
        }
        for (int i = 0; i < pos.size(); i++)
        {
            ans.push_back(pos[i]);
        }
        for (int i = 0; i < n; i++)
        {
            arr[i]=ans[i];
        }
        
    }
};