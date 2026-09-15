class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        set<string> st;
        for(auto it: wordList){
            st.insert(it);
        }
        unordered_map<string,int> mp2;
        st.erase(beginWord);
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            string str=f.first;
            cout<<str<<endl;
            if(str==endWord) return f.second;
            for(int i=0; i<str.length(); i++){
                string s=str;
                for(int j=0; j<26; j++){
                    s[i] = 'a' + j;
                    if(st.find(s)!=st.end()){
                        q.push({s, f.second+1});
                        st.erase(s);
                    }
                }
            }
        }

        return 0;
    }
};