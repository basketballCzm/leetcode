/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/
/*
同前序加中序推导树结构一样，都是首先找到根节点，然后通过根节点在序列中推出左右子树的节点个数，然后再分别构造左右子树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() && postorder.empty()){
            return NULL;
        }

        return buildTreeR(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* buildTreeR(vector<int>& inorder, int ins, int ine, vector<int>& postorder, int posts, int poste){
        if(ins > ine || posts > poste){
            return NULL;
        }

        int nroot = postorder[poste];
        int index = -1;
        for(int i = ins; i <= ine; i++){
            if(nroot == inorder[i]){
                index = i;
                break;
            }
        }

        TreeNode* proot = new TreeNode(nroot);
        TreeNode* pleft = buildTreeR(inorder, ins, index-1, postorder, posts ,posts+(index-ins)-1);
        TreeNode* pright = buildTreeR(inorder, index+1, ine, postorder, posts+(index-ins), poste-1);
        proot->left = pleft;
        proot->right = pright;

        return proot;
    }
};