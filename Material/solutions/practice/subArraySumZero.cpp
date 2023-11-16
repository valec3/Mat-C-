class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        set<int> s;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0) return true;
            s.insert(arr[i]);
        }
        for(int i = 0; i < n; i++){
            int sum = arr[i];
            if(sum == 0) return true;
            if(s.find(sum) != s.end()) return true;
            else s.insert(sum);
        }
        return false;
    }
};