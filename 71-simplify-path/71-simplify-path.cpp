class Solution {
public:
    string simplifyPath(string path) {
        istringstream iss(path);
        vector<string> tokens;
        string token;
        while(getline(iss,token,'/'))
        {
            if(token=="." or token=="")
            {
                continue;
            }
            else
            {
                tokens.push_back(token);
            }
        }
        vector<string> stack;
        if(path[0]=='/')
        {
            stack.push_back("");
        }
        for(auto i: tokens)
        {
            cout<<stack.size()<<i<<endl;
            if(i=="..")
            {
                if(stack.size()==0 or stack[stack.size()-1]=="..")
                {
                    stack.push_back("..");
                }
                else if(stack[stack.size()-1]!="")
                {
                    stack.pop_back();
                }
            }
            else
            {
                cout<<i<<endl;
                stack.push_back(i);
            }
            
        }
        if(stack.size()==1 and stack[0]=="")
        {
            return "/";
        }
          ostringstream oss;
        
        int i=0;
        for(auto token: stack)
        {
            if(i!=0)
            {
                oss<<"/"
;            }
            i++;
            oss<<token;
        }
        return oss.str();
        
    }
};