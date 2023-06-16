class Solution {
    private:
    void solve(string digits, vector<string>& ans,string output, int index,vector<string> mapp){
        //basee case
        if(index>=digits.size()){
            ans.push_back(output);
            return;
        }

        int num = digits[index] - '0';
        string val = mapp[num];

        for(int i =0;i<val.length();i++){
            output.push_back(val[i]);
            solve(digits,ans,output,index+1, mapp);
            output.pop_back();
        }
        
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> mapp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string output = "";
        int index = 0;
        if(digits.length()==0)
            return ans;
        solve(digits, ans, output, index, mapp);
        return ans;
    }
};

