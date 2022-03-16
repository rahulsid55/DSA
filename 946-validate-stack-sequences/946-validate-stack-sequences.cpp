class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i=0,j=0,n=pushed.size();
        while(i<n and j<n){
            if(pushed[i]==popped[j]){
                i++;
                j++;
            }
            else if(!s.empty() and popped[j]==s.top()){
                s.pop();
                j++;
            }
            else{
                s.push(pushed[i]);
                i++;
            }
        }
        if(j!=n){
            while(!s.empty() and popped[j]==s.top()){
                //cout<<s.top()<<" ";
                s.pop();
                j++;
            }
        }
        return s.empty()?1:0;
        
        
        
    }
};