/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
*/
/*
递归解法: 检查根节点下面的左右两颗子树是否对称，检查根节点左孩子和右孩子是否相等，左孩子的左孩子和右孩子的右孩子，左孩子的右孩子和右孩子的左孩子是否相等如果以上三种情况成立，那么这两颗子树是对称的。

队列的基本操作size,pop,push,back获取队尾元素,front获取队头元素,队列尾进头出
非递归解法: 使用队列来分别对根节点的左右子树进行层次遍历，但是层次遍历很特殊，对于根节点的左子树中的节点，先使得左孩子入队列，再使得右孩子如队列，依次类推。对于右子树中的节点，先使得右孩子入队列，再使得左孩子入队列。新建两个队列分别维护左右子树，从左右队列中取元素时首先要判断取出的两个元素是否相等，如果相等则进行上面操作。
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
    bool isSymmetric(TreeNode* root) {
    	if(NULL == root){
    		return true;
    	}
    	return isSymmetric1(root->left, root->right);
    }

    /*
    bool isSymmetric1(TreeNode *lleft, TreeNode *rright){
    	if(NULL == lleft && NULL == rright){
    		return true;
    	}else if(NULL == lleft || NULL == rright){
    		return false;
    	}
    	else if(lleft->val == rright->val){
    		return isSymmetric1(lleft->left, rright->right) & isSymmetric1(lleft->right, rright->left);
    	}
    	//lleft->val != rright-val
    	return false;
    }*/

    bool isSymmetric1(TreeNode *lleft, TreeNode *rright){
    	if(NULL == lleft && NULL == rright){
    		return true;
    	}else if(NULL != lleft && NULL != rright){
    		if(lleft->val == rright->val){
    			return isSymmetric1(lleft->left, rright->right) & isSymmetric1(lleft->right, rright->left);
    		}else{
    			return false;
    		}
    	}else{
    		return false;
    	}
    }
};

//非递归解法
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
    bool isSymmetric(TreeNode* root) {
        if(NULL == root){
        	return true;
        }

        //back 进  front  出
        queue<TreeNode*> queue_left;
        queue<TreeNode*> queue_right;
        queue_left.push(root->left);
        queue_right.push(root->right);

        while(!queue_left.empty() && !queue_right.empty()){
        	TreeNode *node_left = queue_left.front();
        	TreeNode *node_right = queue_right.front();
        	if(NULL == node_left && NULL == node_right){
        		queue_left.pop();
        		queue_right.pop();
        		continue;
        	}else if(NULL != node_left && NULL != node_right){
        		if(node_left->val == node_right->val){
        			queue_left.pop();
        			queue_right.pop();
        			queue_left.push(node_left->left);
        			queue_left.push(node_left->right);
        			queue_right.push(node_right->right);
        			queue_right.push(node_right->left);
        			continue;
        		}else{
        			return false;
        		}
        	}else{
        		return false;
        	}
        }

        if(!queue_right.empty() || !queue_left.empty()){
        	return false;
        }

        return true;
    }
};