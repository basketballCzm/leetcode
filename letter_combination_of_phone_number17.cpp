/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/

/*
解题思路：这道题的构造字符串的方法让人想到递归构造字符串，在递归构造的过程中，要注意结束条件的选取
         对每个字符串中的字符当做一个节点进行递归构造字符串。
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	int size = digits.size();
    	vector<string> res;
    	if(0 == size){
    		return res;
    	}
    	string str;
    	construction_tree(res,str,digits,0);
    	return res;
    }

    void construction_tree(vector<string>& res, string str ,string digits, int index){
    	if(index == digits.size()){
    		res.push_back(str);
    		return;
    	}
    	string slet = get_map(digits[index]);
    	int size = slet.size();
    	for(int i = 0; i < size; i++){
    		construction_tree(res, str+slet[i], digits, index+1);
    	}

    }

    string get_map(char ch){
    	int i = 0;
    	for(i = 0; '#' != map_letter[i].ch; i++){
    		if(ch == map_letter[i].ch){
    			return map_letter[i].slet;
    		}
    	}

    	return map_letter[i].slet;
    }
private:
	struct map_letters{
		char ch;
		string slet;
	};
	const map_letters map_letter[9] = {{'2',"abc"},
	{'3',"def"},
	{'4',"ghi"},
	{'5',"jkl"},
	{'6',"mno"},
	{'7',"pqrs"},
	{'8',"tuv"},
	{'9',"wxyz"},
    {'#',""}};
};