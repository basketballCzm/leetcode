//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向
//线索化二叉搜索树

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//这一题使用递归版本和非递归版本再写一遍//中序遍历的递归和非递归解法，可以的，非常妙

//https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5
class Solution {
  public:
	//中序遍历
	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (NULL == pRootOfTree) {
			return NULL;
		}
		vector<TreeNode*> res;
		ConvertR(res, pRootOfTree);
		//改变每个节点的left和right域
		for (int i = 0; i < res.size() - 1; i++) {
			res[i]->right = res[i + 1];
			res[i + 1]->left = res[i];
		}

		//处理头尾 没说是否是环形
		//res[0]->left = res[res.size()-1];
		//res[res.size()-1]->right = res[0];
		return res[0];
	}

	void ConvertR(vector<TreeNode*>& res, TreeNode* pRoot) {
		if (NULL != pRoot) {
			ConvertR(res, pRoot->left);
			res.push_back(pRoot);
			ConvertR(res, pRoot->right);
		}
	}
};

class Solution {
  public:
	//递归写法 每次要保留当前节点的前一个节点。
	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (NULL == pRootOfTree) {
			return NULL;
		}

		TreeNode* pre = NULL;
		ConvertR(pRootOfTree, pre);

		TreeNode* p = pRootOfTree;
		while (NULL != p->left) {
			p = p->left;
		}
		return p;
	}

	//这里在递归的过程中pre节点的值发生了改变，因此要使用引用来进行传参
	void ConvertR(TreeNode* root, TreeNode*& pre) {
		if (NULL != root) {
			ConvertR(root->left, pre);

			root->left = pre;
			if (NULL != pre) {
				pre->right = root;
			}
			pre = root;
			ConvertR(root->right, pre);
		}
	}
};