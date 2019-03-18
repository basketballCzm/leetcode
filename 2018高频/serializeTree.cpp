/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例:

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
思路：
1. 使用先序遍历的递归算法进行构造。
2. 使用BFS的方法进行类似层次遍历的方法构造。
以上两种方式都要注意边界值的校验。
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
class Codec {
  public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream out;
		serializeTree(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream in(data);
		return deserializeTree(in);
	}

	void serializeTree(TreeNode* root, ostringstream& out) {
		if (root) {
			out << root->val << " ";
			serializeTree(root->left, out);
			serializeTree(root->right, out);
		} else {
			out << "# ";
		}
	}

	TreeNode* deserializeTree(istringstream& in) {
		string val;
		in >> val;
		if ("#" == val) {
			return NULL;
		}
		TreeNode* root = new TreeNode(stoi(val));
		root->left = deserializeTree(in);
		root->right = deserializeTree(in);


		return root;
	}
};

//使用层次遍历的结果构造二叉树
class Codec {
  public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream out;
		deque<TreeNode*> que;
		if (root) {
			que.push_back(root);
		}
		while (!que.empty()) {
			TreeNode* tmp = que.front();
			que.pop_front();
			if (NULL != tmp) {
				out << tmp->val << " ";
				que.push_back(tmp->left);
				que.push_back(tmp->right);
			} else {
				out << "# ";
			}
		}

		return out.str();

	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty()) {
			return NULL;
		}
		istringstream in(data);
		string val;
		in >> val;
		deque<TreeNode*> que;
		TreeNode* root = new TreeNode(stoi(val));
		que.push_back(root);
		while (!que.empty()) {
			TreeNode* tmp = que.front();
			que.pop_front();
			if (!(in >> val)) {
				break;
			}
			if ("#" != val) {
				TreeNode* pleft = new TreeNode(stoi(val));
				tmp->left = pleft;
				que.push_back(pleft);
			}

			if (!(in >> val)) {
				break;
			}
			if ("#" != val) {
				TreeNode* pright = new TreeNode(stoi(val));
				tmp->right = pright;
				que.push_back(pright);
			}
		}

		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));