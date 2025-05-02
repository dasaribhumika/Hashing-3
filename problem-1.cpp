// https://leetcode.com/problems/repeated-dna-sequences/description/

// Time Complexity: O(n) 
// Space Complexity: O(n)
// rolling hash
class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            int n = s.size();
            if(n<10) return {};
            unordered_map<char, long> mp;   unordered_set <long> allsubs; unordered_set <string> res;
            mp['A'] = 0l; mp['C'] = 1l; mp['G'] = 2l; mp['T'] = 3l;
            long currHash=0;
            long pw = 1;
            for(int i=0; i<9; i++) pw *= 4;
            for(int i=0; i<10; i++){
                //in
                currHash = currHash * 4 + mp[s[i]];
            }
            allsubs.insert(currHash);
            for(int i=1; i < n-9; i++){
                //out
                currHash = currHash - pw * mp[s[i-1]];
                // in
                currHash = currHash * 4 + mp[s[i+9]];
                if(allsubs.find(currHash) != allsubs.end()) res.insert(s.substr(i, 10));
                else allsubs.insert(currHash);
            }
            
            return vector<string> (res.begin(), res.end());
          
    
    
        }
    };

// Time Complexity: O(n) 
// Space Complexity: O(n)

    class Solution {
        public:
            vector<string> findRepeatedDnaSequences(string s) {
                int n = s.size();
                if(n<10) return {};
                unordered_map<string, int> mp; vector <string> res;
                for(int i=0; i < n-9; i++){
                    mp[s.substr(i, 10)]++;
                }
                for(auto it:mp){
                    if(it.second > 1){
                        res.push_back(it.first);
                    }
                }
                return res;
            }
        };