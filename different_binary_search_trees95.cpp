/*
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
/*push_back() 向容器中加入一个右值元素(临时变量)的时候，首先会调用构造函数构造这一临时变量，然后需要调用拷贝
构造函数将这个临时对象放入容器中，原来的临时变量释放，这样造成的问题是临时变量申请的资源浪费。

emplace_back() 在容器尾部添加一个元素，这个元素原地构造，不需要触发拷贝构造和转移构造，而且调用形式更加简洁，
直接根据参数初始化临时对象的成员
*/
/*
解题思路：从start 到 end 节点之间依次序选择根节点，因为不同的根节点会导致不同的树形结构，然后再对左右两边的序列
按照这样的思路依次序选择根节点，然后遍历左子树的可能情况和右子树的可能情况，依次和根节点组成不同的树。注意在没有
左右子树的情况下向容器中添加nullptr,否则for循环不能进入
*/

#include <iostream>
#include <vector>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
    	std::vector<TreeNode*> trees;
    	if(n < 1){
    		return trees;
    	}
        return generateTrees(1,n);
    }
private:
	std::vector<TreeNode*> generateTrees(int start, int end){
		std::vector<TreeNode*> trees;
		if(start > end){
			trees.emplace_back(nullptr);
			return trees;
		}

		//这颗树使从下往上进行组合树的操作
		for(int i = start; i <= end; i++){
			std::vector<TreeNode*> leftTrees = generateTrees(start,i-1);
			std::vector<TreeNode*> rightTrees = generateTrees(i+1,end);

			for(auto leftTree:leftTrees){
				for(auto rightTree:rightTrees){
					TreeNode* root = new TreeNode(i);
					root->left = leftTree;
					root->right = rightTree;
					trees.emplace_back(root);
				}
			}
		}

		return trees;
	}
};

void printTree(TreeNode *node){
	if(nullptr != node){
		std::cout << node->val << " ";
		printTree(node->left);
		printTree(node->right);
	}
}

int main(){
	Solution r;
	std::vector<TreeNode*> result = r.generateTrees(3);

	std::cout <<"hello world!" << std::endl;
 	for(TreeNode* tmp:result){
		printTree(tmp);

		std::cout << std::endl;
	}
}