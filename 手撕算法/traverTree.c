/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> res;
    	inorderTraversalTree(res, root);
    	return res;
    }

    void inorderTraversalTree(vector<int>& res, TreeNode* root){
    	if(NULL != root){
    		inorderTraversalTree(res, root->left);
    		res.push_back(root->val);
    		inorderTraversalTree(res, root->right);
    	}
    }
};

//层次遍历非递归算法
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		queue<TreeNode*> q;
		TreeNode* tmp = root;
		q.push(tmp);
		while(!stk.empty()){
			tmp = q.front();
			q.pop();
			res.push_back(tmp->val);
			if(NULL != tmp->left){
				q.push(tmp->left);
			}

			if(NULL != tmp->right){
				q.push(tmp->right);
			}
		}

		return res;
	}
};

// 层次遍历的非递归算法
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		if (NULL == root){
			return res;
		}

		deque<TreeNode*> q;
		q.push_back(root);
		while(!q.empty()){
			TreeNode* ptmp = q.front()
			q.pop_front();
			res.push_back(ptmp->value);
			if(NULL ！= ptmp->left){
				res.push_back(ptmp->left);
			}
			if(NULL != ptmp->right){
				res.push_back(ptmp->right);
			}
		}
 	}
};

//先序遍历的非递归算法
//与中序遍历类似，都是先访问根节点，依次向左子树进行遍历，直到左子树访问完全，但是注意，这一过程和中序遍历的
//这一过程是相反的，然后对右子树进行相同的遍历操作
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		stack<TreeNode*> stk;
		TreeNode *tmp = root;
		while(NULL != tmp || !stk.empty()){
			while(NULL != tmp){
				res.push_back(tmp->val);
				stk.push(tmp);
				tmp = tmp->left;
			}

			if(!stk.empty()){
				tmp = stk.pop();
				tmp = tmp->right;
			}
		}

		return res;
	}
};

//先序遍历的非递归写法
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		if(NULL == root){
			return res;
		}

		stack<TreeNode*> s;
		TreeNode* pcur = root;
		while(NULL != pcur || !s.empty()){
			while(pcur){
				res.push_back(pcur->val);
				s.push(pcur);
				pcur = pcur->left;
			}

			if(!s.empty()){
				TreeNode* ptmp = s.top();
				s.pop();
				pcur = ptmp->right;
			}
		}

	}
};



//中序遍历的非递归算法
// 通过栈来回溯相当于是先左孩子，然后中节点，然后对右孩子进行相同的回溯
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		stack<TreeNode*> stk;
		TreeNode* tmp = root;
		while(NULL != tmp || ！stk.empty()){
			while(NULL != tmp){
				stk.push(tmp);
				tmp = tmp->left;
			}

			if(!stk.empty()){
				tmp = stk.top();
				res.push_back(tmp->val);
				stk.pop();
				tmp = tmp->right;
			}
		}

		return res;
	}
};

//中序遍历的非递归算法
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		if(NULL == root){
			return res;
		}

		TreeNode* pcur = root;
		stack<TreeNode*> s;
		while(NULL != pcur || !s.empty()){
			while(NULL != pcur){
				stack.push_back(pcur);
				pcur = pcur->left;
			}

			if(!s.empty()){
				TreeNode* ptmp = s.top();
				s.pop();
				res.push_back(ptmp->value);
				pcur = ptmp->right;
			}
		}
	}
};
//后续遍历的非递归算法1
//模仿中序遍历的非递归算法，只不过对于一个节点第一次访问的时候不进行处理，等到第二次访问的时候再进行处理
//新建一个节点，然后对初始化该值，进行入栈操作。
class Solution{
public:
	struct FlagNode{
		bool flag;
		TreeNode* node;
	};
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		stack<FlagNode*> stk;
		TreeNode *tmp = root;
		while(NULL != tmp || !stk.empty()){
			while(NULL != tmp){
				FlagNode *pNew = new FlagNode();
				pNew->flag = true;
				pNew->node = tmp;
				stk.push(pNew);
				tmp = tmp->left;
			}

			if(!stk.empty()){
				FlagNode *Ftmp = stk.pop();
				if(Ftmp->flag){
					Ftmp->flag = false;
					stk.push(Ftmp);
				}else{
					res.push_back(Ftmp->node->val);
					delete Ftmp;
				}

				if(NULL == Ftmp){
					tmp = NULL;
				}else{
					tmp = Ftmp->node->right;
				}
			}
		}

		return res;
	}
};

//模仿中序遍历的非递归算法，只不过对于一个节点第一次访问的时候不进行处理，等到第二次访问的时候再进行处理
class Solution{
public:
	struct FlagNode{
		bool flag;
		TreeNode* node;
	};
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		if (NULL == root){
			return res;
		}
		TreeNode* pcur = root;
		stack<FlagNode*> s;
		while(NULL != pcur || !s.empty()){
			while(NULL != pcur){
				FlagNode* ptmp = new FlagNode();
				ptmp->flag = true;
				ptmp->node = pcur;
				s.push(ptmp);
				pcur = pcur->left;
			}

			if(!s.empty()){
				FlagNode* ptmp = s.top();
				s.pop();
				if(ptmp->flag){
					ptmp->flag = false;
					s.push(ptmp);
				}else{
					res.push_back(ptmp->value);
					delete ptmp;
					ptmp = NULL;
				}

				if (NULL == ptmp){
					pcur = NULL;
				}else{
					pcur = ptmp->right;
				}
			}
		}

		return res;
	}
};

//后序遍历的非递归算法2 首先查看该节点是否有左右孩子，如果没有则直接访问，如果有，查看前驱是否为空，
//如果为空那么就将该节点的左右孩子入栈如果不为空那么查看该前驱是否为当前节点的左孩子或者是右孩子，如果是则将该节点进行访问。
class Solution{
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		stack<TreeNode*> stk;
		TreeNode* pre = NULL;
		TreeNode* cur = root;
		stk.push(root);
		while(NULL != cur || !s.empty()){
			cur = stk.top();
			if((NULL == cur->left && NULL == cur->right) ||
				(NULL != pre && (pre == cur->left || pre == cur->right))){
				res.push_back(cur->val);
				stk.pop();
			}

			if(NULL != cur->left){
				stk.push(cur->left);
			}

			if(NULL != cur->right){
				stk.push(cur->right);
			}
		}

		return res;
	}
};

