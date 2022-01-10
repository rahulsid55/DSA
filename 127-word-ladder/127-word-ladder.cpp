class Solution {
public:
    bool differ(string a ,string b){
        int ct=0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i]) ct++;
        }
        if(ct==1) return true;
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        map<string,vector<string>> graph;
        for(int i=0;i<n;i++)
        {

            if(differ(wordList[i],beginWord))
            {
                graph[beginWord].push_back(wordList[i]);
                graph[wordList[i]].push_back(beginWord);
            }
        }
       
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
              if(differ(wordList[i],wordList[j]))
             {
                graph[wordList[j]].push_back(wordList[i]);
                graph[wordList[i]].push_back(wordList[j]);
             }
            }
        }
      
        queue<string> q;
		map<string,int> visited;
		map<string,int> dist;
		map<string,string> parent;

		for(int i=0;i<n;i++){
			parent[wordList[i]] = -1;
		}

		q.push(beginWord);
		visited[beginWord] =1;
		parent[beginWord] = beginWord;
		dist[beginWord] = 1;

		while(!q.empty()){
			string f = q.front();
            //cout<<f<<" ";
			q.pop();
			for(auto nbr : graph[f]){
				if(!visited.count(nbr)){
					q.push(nbr);
					parent[nbr] = f;
					dist[nbr] = dist[f] + 1;
					visited[nbr] = 1;
				}
			}
		}
        cout<<endl;
       
        if(!visited.count(endWord)) return 0;
        return dist[endWord];
        
        
    }
};