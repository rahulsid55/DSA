class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> output;
        int n=exp.size();
        for(int i=0;i<n;i++){
            if(exp[i]=='+' || exp[i]=='*' || exp[i]=='-'){
                vector<int> left=diffWaysToCompute(exp.substr(0,i));
                vector<int> right=diffWaysToCompute(exp.substr(i+1));
                for(auto a: left){
                    for(auto b: right){
                        if(exp[i]=='*'){
                            output.push_back(a*b);
                        }
                    }
                }
                for(auto a: left){
                    for(auto b: right){
                        if(exp[i]=='+'){
                            output.push_back(a+b);
                        }
                    }
                }
                for(auto a: left){
                    for(auto b: right){
                        if(exp[i]=='-'){
                            output.push_back(a-b);
                        }
                    }
                }
            }
        } 
        if(output.size()==0) output.push_back(stoi(exp));
        return output;
        
        
    }
};