class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(); //also size of window
        int n2 = s2.size();

        if(n1>n2){
            return false;
        }

        int l = 0;
        int r = 0;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        for(int i = 0; i<n1;i++){
            count1[s1[i] - 'a']++;
        }

        while(r<n2){
            count2[s2[r] - 'a']++;

            if(r-l+1<n1){
                r++;
                continue;
            }

            if(count1 == count2){
                return true;
            }

            count2[s2[l] - 'a']--;

            l++;
            r++;
        }

        return false;
    }
};