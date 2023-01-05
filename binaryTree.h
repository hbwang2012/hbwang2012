#pragma once
#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<string>

struct TreeNode
{
	string str;
	TreeNode* TLeft;
	TreeNode* TRight;
	TreeNode():TLeft(NULL), TRight(NULL) {}
	TreeNode(string val,TreeNode* left = NULL,TreeNode* right = NULL):str(val),TLeft(left),TRight(right){}
};
struct BT
{
	int val;
	BT* BTleft;
	BT* BTright;
	BT():BTleft(NULL),BTright(NULL){}
	BT(int v,BT* left = NULL, BT* right = NULL) :val(v), BTleft(left), BTright(right) {}
};
//序列化二叉树
//vector<BT*> btTOvec(BT* bt)
//{
//	vector<BT*> v;
//	if (bt)
//	{
//		queue<BT*> q;
//		q.push(bt);
//		v.push_back(q.front());
//		while (!q.empty())
//		{
//			int n = q.size();
//			for (int i = 0; i < n; i++)
//			{
//				v.push_back(q.front()->BTleft);
//				v.push_back(q.front()->BTright);
//				if (q.front()->BTleft)
//				{
//					q.push(q.front()->BTleft);
//				}
//				if (q.front()->BTright)
//				{
//					q.push(q.front()->BTright);
//				}
//				q.pop();
//			}
//		}
//	}
//	return v;
//}
//vector<BT*> btTOvec(BT* bt)
//{
//	vector<BT*> v;
//	if (bt)
//	{
//		queue<BT*> q;
//		q.push(bt);
//		v.push_back(q.front());
//		while (!q.empty())
//		{
//			if (q.front()->BTleft)
//			{
//				q.push(q.front()->BTleft);
//				v.push_back(q.front()->BTleft);
//			}
//			else
//			{
//				v.push_back(q.front()->BTleft);
//			}
//			if (q.front()->BTright)
//			{
//				q.push(q.front()->BTright);
//				v.push_back(q.front()->BTright);
//			}
//			else
//			{
//				v.push_back(q.front()->BTright);
//			}
//			q.pop();
//		}
//	}
//	return v;
//}
//void btserialize(BT* bt,string &str)
//{
//	if (bt)
//	{
//		str.append(to_string(bt->val)+',');
//		btserialize(bt->BTleft,str);
//		btserialize(bt->BTright,str);
//	}
//	else
//	{
//		str.append("#,");
//	}
//}
//void btreserialize(BT* &bt,string &str) //有错误，各个节点间不衔接。也可以改成衔接的，但是空结点暂时没办法置为NULL；
//{
//	int n = str.size();
//	int i = 0;
//	vector<string> v;
//	string temp;
//	while (i < n)
//	{
//		if (str[i] == ',')
//		{
//			v.push_back(temp);
//			temp.clear();
//		}
//		else
//		{
//			temp.push_back(str[i]);
//		}
//		i++;
//	}
//	bt = new BT;
//	int length = v.size();
//	if (length > 0)
//	{
//		BT* btt = bt;
//		stack<BT*> s;
//		if (v[0] != "#")
//		{
//			btt->val = stoi(v[0]);
//			s.push(btt);
//			btt = btt->BTleft;
//			int j = 1;
//			while (j < length)
//			{
//				if (v[j] != "#")
//				{
//					btt = new BT(stoi(v[j]));
//					s.push(btt);
//					btt = btt->BTleft;
//				}
//				else
//				{
//					if (!s.empty())
//					{
//						btt = s.top()->BTright;
//						s.pop();
//					}
//				}
//				j++;
//			}
//		}		
//	}
//}
//序列化二叉树，层次遍历法
string serialize(BT* bt)
{
	string str;
	if (bt)
	{
		queue<BT*> s;
		str.append(to_string(bt->val)+",");
		s.push(bt);
		while (!s.empty())
		{
			if (s.front()->BTleft)
			{
				s.push(s.front()->BTleft);
				str.append(to_string(s.front()->BTleft->val)+",");
			}
			else
			{
				str.append("#,");
			}
			if (s.front()->BTright)
			{
				s.push(s.front()->BTright);
				str.append(to_string(s.front()->BTright->val) + ",");
			}
			else
			{
				str.append("#,");
			}
			s.pop();
		}
	}
	return str;
}
//反序列化二叉树
BT* reserialize(string str)
{
	vector<string> v;
	int n = str.size();
	int i = 0;
	string temp;
	while (i < n)
	{
		if (str[i] == ',')
		{
			v.push_back(temp);
			temp.clear();
		}
		else
		{
			temp += str[i];
		}
		i++;
	}
	int length = v.size();
	BT* bt = NULL;
	if (length > 0)
	{
		queue<BT*> q;
		bt = new BT;
		bt->val = stoi(v[0]);
		q.push(bt);
		for (int j = 1; j < length; j++)
		{
			if (v[j] != "#")
			{
				q.front()->BTleft = new BT(stoi(v[j]));
				q.push(q.front()->BTleft);
			}
			if (v[++j] != "#")
			{
				q.front()->BTright = new BT(stoi(v[j]));
				q.push(q.front()->BTright);
			}
			q.pop();
		}
	}
	return bt;
}
//创建二叉树
void CreatTreeNode(TreeNode* &TR)
{
	string val;
	cin >> val;
	if (val == "#")
	{
		return;
	}
	TR = new TreeNode;
	TR->str = val;
	CreatTreeNode(TR->TLeft);
	CreatTreeNode(TR->TRight);
}
//前序遍历
void preTraverse(TreeNode* TR)
{
	if (TR)
	{
		cout << TR->str << " ";
		preTraverse(TR->TLeft);
		preTraverse(TR->TRight);
	}
}
void preTraverseInt(BT* bt)
{
	if (bt)
	{
		cout << bt->val << " ";
		preTraverseInt(bt->BTleft);
		preTraverseInt(bt->BTright);
	}
}
//前序遍历迭代方法
//void preIterator(TreeNode* TR)
//{
//	if (TR)
//	{
//		stack<TreeNode*> s;
//		s.push(TR);
//		while (!s.empty())
//		{
//			while (s.top())
//			{
//				cout << s.top()->str << " ";
//				s.push(s.top()->TLeft);
//			}
//			s.pop();
//			if (!s.empty())
//			{
//				TreeNode* temp = s.top();
//				s.pop();
//				s.push(temp->TRight);
//			}
//		}
//	}
//}
void preIterator(TreeNode* TR)
{
	stack<TreeNode*> s;
	while (TR || !s.empty())
	{
		if (TR)
		{
			cout << TR->str << " ";
			s.push(TR);
			TR = TR->TLeft;
		}
		else
		{
			TR = s.top()->TRight;
			s.pop();
		}
	}
}
//中序遍历
void midTraverse(TreeNode* TR)
{
	if (TR)
	{
		midTraverse(TR->TLeft);
		cout << TR->str << " ";
		midTraverse(TR->TRight);
	}
}
void midTraverse1(BT* bt)
{
	if (bt)
	{
		midTraverse1(bt->BTleft);
		cout << bt->val << " ";
		midTraverse1(bt->BTright);
	}
}
void midIteratior(TreeNode* TR)
{
	stack<TreeNode*> s;
	while (TR || !s.empty())
	{
		if (TR)
		{
			s.push(TR);
			TR = TR->TLeft;
		}
		else
		{
			cout << s.top()->str << " ";
			TR = s.top()->TRight;
			s.pop();
		}
	}
}
//后序遍历
void posTraverse(TreeNode* TR)
{
	if (TR)
	{
		posTraverse(TR->TLeft);
		posTraverse(TR->TRight);
		cout << TR->str << " ";
	}
}
void posIteratior(TreeNode* TR)
{
	stack<TreeNode*> s;
	TreeNode* last = NULL;
	while (TR || !s.empty())
	{
		if (TR)
		{
			s.push(TR);
			TR = TR->TLeft;
		}
		else if (!s.top()->TRight || s.top()->TRight == last)
		{
			cout << s.top()->str << " ";
			last = s.top();
			s.pop();
		}
		else
		{
			TR = s.top()->TRight;
		}
	}
}
//层次遍历法
void layerTraverse(TreeNode* TR)
{
	if (TR)
	{
		queue<TreeNode*> q;
		q.push(TR);
		while (!q.empty())
		{
			cout << q.front()->str << " ";
			if (q.front()->TLeft)
			{
				q.push(q.front()->TLeft);
			}
			if (q.front()->TRight)
			{
				q.push(q.front()->TRight);
			}
			q.pop();
		}
	}
}
void layerTraverse1(BT* bt)
{
	if (bt)
	{
		queue<BT*> q;
		q.push(bt);
		while (!q.empty())
		{
			cout << q.front()->val << " ";
			if (q.front()->BTleft)
			{
				q.push(q.front()->BTleft);
			}
			if (q.front()->BTright)
			{
				q.push(q.front()->BTright);
			}
			q.pop();
		}
	}
}
TreeNode* CreatTRpremid(string pre,string mid)
{
	if (!pre.empty())
	{
		TreeNode* TR = new TreeNode;
		TR->str = pre.substr(0,1);
		int pos = mid.find(pre.substr(0,1));
		TR->TLeft = CreatTRpremid(pre.substr(1,pos),mid.substr(0,pos));
		TR->TRight = CreatTRpremid(pre.substr(pos+1, pre.size()-pos-1), mid.substr(pos+1, mid.size()-pos-1));
		return TR;
	}
	return NULL;
}
//计算二叉树层数-1
int depth(TreeNode* TR)
{
	if (TR)
	{
		return max(depth(TR->TLeft),depth(TR->TRight)) + 1;
	}
	return 0;
}
//计算二叉树层数-2
int find_max_depth_V2(TreeNode* root)
{
	if (root)
	{
		queue<TreeNode*> q;
		q.push(root);
		int depth = 0;
		while (!q.empty())
		{
			depth++;
			int n = q.size();
			for (int i = 0; i < n; i++)
			{
				if (q.front()->TLeft)
				{
					q.push(q.front()->TLeft);
				}
				if (q.front()->TRight)
				{
					q.push(q.front()->TRight);
				}
				q.pop();
			}
		}
		return depth;
	}
	return 0;
}
//计算二叉树最小深度-1
int minDepth1(TreeNode* TR)
{
	if (TR == NULL)
	{
		return 0;
	}
	if (TR->TLeft == NULL && TR->TRight == NULL)
	{
		return 1;
	}
	if (TR->TLeft == NULL && TR->TRight != NULL)
	{
		return 1 + minDepth1(TR->TRight);
	}
	if (TR->TLeft != NULL && TR->TRight == NULL)
	{
		return 1 + minDepth1(TR->TLeft);
	}
	return 1 + min(minDepth1(TR->TLeft), minDepth1(TR->TRight));
}
//计算二叉树最小深度-2
int minDepth2(TreeNode* TR)
{
	if (TR)
	{
		queue<TreeNode*> q;
		q.push(TR);
		int depth = 0;
		while (!q.empty())
		{
			depth++;
			int n = q.size();
			for (int i = 0; i < n; i++)
			{
				if (!q.front()->TLeft && !q.front()->TRight)
				{
					return depth;
				}
				if (q.front()->TLeft)
				{
					q.push(q.front()->TLeft);
				}
				if (q.front()->TRight)
				{
					q.push(q.front()->TRight);
				}
				q.pop();
			}
		}
		return depth;
	}
	return 0;
}
//计算节点数
int countNode(TreeNode* TR)
{
	if (TR)
	{
		return countNode(TR->TLeft) + countNode(TR->TRight) + 1;
	}
	return 0;
}
//计算叶子节点数
int countLeft(TreeNode* TR)
{
	if (TR)
	{
		if (TR->TLeft == NULL && TR->TRight == NULL)
		{
			return 1;
		}
		else
		{
			return countLeft(TR->TLeft) + countLeft(TR->TRight);
		}

	}
	return 0;
}
//判断是否为子结构
bool isSameStructure(TreeNode* A, TreeNode* B)
{
	if (!B)
	{
		return true;
	}
	if (!A)
	{
		return false;
	}
	if (A->str != B->str)
	{
		return false;
	}
	else
	{
		return isSameStructure(A->TLeft, B->TLeft) && isSameStructure(A->TRight, B->TRight);
	}
}
bool isSubStructure(TreeNode* A, TreeNode* B) {
	if (!A || !B)
	{
		return false;
	}
	else if (A->str == B->str && isSameStructure(A->TLeft, B->TLeft) && isSameStructure(A->TRight, B->TRight))
	{
		return true;
	}
	else
	{
		return isSubStructure(A->TLeft, B) || isSubStructure(A->TRight, B);
	}
}

//判断是否为子树
bool isSameTree(TreeNode* A, TreeNode* B)
{
	if (!A && !B)
	{
		return true;
	}
	if (!A || !B)
	{
		return false;
	}
	if (A->str != B->str)
	{
		return false;
	}
	else
	{
		return isSameTree(A->TLeft, B->TLeft) && isSameTree(A->TRight, B->TRight);
	}
}
bool isSubTree(TreeNode* A, TreeNode* B) {
	if (!A || !B)
	{
		return false;
	}
	if (A->str == B->str && isSameTree(A->TLeft, B->TLeft) && isSameTree(A->TRight, B->TRight))
	{
		return true;
	}
	else
	{
		return isSubTree(A->TLeft, B) || isSubTree(A->TRight, B);
	}
}

//计算第k层节点数
int countKNodes(TreeNode* TR,int k)
{
	if (TR && k >= 1)
	{
		queue<TreeNode*> q;
		q.push(TR);
		int t = 0;
		while (!q.empty())
		{
			t++;
			int n = q.size();
			if (t == k)
			{
				return n;
			}
			for (int i = 0; i < n; i++)
			{
				if (q.front()->TLeft)
					q.push(q.front()->TLeft);
				if (q.front()->TRight)
					q.push(q.front()->TRight);
				q.pop();
			}
		}
	}
	return 0;
}
//判断是否为平衡二叉树
bool isBalanced(TreeNode* TR)
{
	if (TR)
	{
		if (abs(depth(TR->TLeft) - depth(TR->TRight)) > 1)
		{
			return false;
		}
		else
		{
			return isBalanced(TR->TLeft) && isBalanced(TR->TRight);
		}
	}
	return true;
}
//判断是否为完全二叉树
bool isFullTree1(TreeNode* TR)
{
	if (TR)
	{
		queue<TreeNode*> q;
		q.push(TR);
		bool flag = false;
		while (!q.empty())
		{
			if (!flag)
			{
				if (q.front()->TLeft && q.front()->TRight)
				{
					q.push(q.front()->TLeft);
					q.push(q.front()->TRight);
				}
				else if (q.front()->TLeft)
				{
					q.push(q.front()->TLeft);
					flag = true;
				}
				else if (q.front()->TRight)
				{
					q.push(q.front()->TRight);
					return false;
				}
				else
				{
					flag = true;
				}
			}
			else
			{
				if (q.front()->TLeft || q.front()->TRight)
				{
					return false;
				}
			}
			q.pop();
		}
	}
	return true;
}
bool isFullTree2(TreeNode* TR)
{
	if (TR)
	{
		queue<TreeNode*> q;
		q.push(TR);
		while (q.front())
		{
			q.push(q.front()->TLeft);
			q.push(q.front()->TRight);
			q.pop();
		}
		while (!q.empty())
		{
			if (q.front())
			{
				return false;
			}
			q.pop();
		}
	}
	return true;
}
//是否为镜像
bool isMirror(TreeNode* TR1, TreeNode* TR2)
{
	if (!TR1 && !TR2)
	{
		return true;
	}
	if (!TR1 || !TR2)
	{
		return false;
	}
	if (TR1->str != TR2->str)
	{
		return false;
	}
	else
	{
		return isMirror(TR1->TLeft,TR2->TRight) && isMirror(TR1->TRight,TR2->TLeft);
	}
}
//镜像二叉树
TreeNode* mirrorTree(TreeNode* TR)
{
	if (TR)
	{
		TreeNode* temp = TR->TLeft;
		TR->TLeft = TR->TRight;
		TR->TRight = temp;
		mirrorTree(TR->TLeft);
		mirrorTree(TR->TRight);
	}
	return NULL;
}
//寻找最近公共祖先点
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root)
	{
		if (root->str == p->str || root->str == q->str)
		{
			return root;
		}
		TreeNode* left = lowestCommonAncestor(root->TLeft, p, q);
		TreeNode* right = lowestCommonAncestor(root->TRight, p, q);
		if (left && right)
		{
			return root;
		}
		if (left)
		{
			return left;
		}
		if (right)
		{
			return right;
		}
	}
	return NULL;
}
//二叉树中和为某一值的路径
void findpath(BT* bt, int target, int cursum, vector<vector<int>>& result, vector<int>& path);
vector<vector<int>> FindPath(BT* bt,int target)
{
	vector<vector<int>> result;
	if (bt)
	{
		int cursum = 0;
		vector<int> path;
		findpath(bt,target,cursum,result,path);
	}
	return result;
}
void findpath(BT* bt, int target, int cursum, vector<vector<int>>& result, vector<int>& path)
{
	cursum += bt->val;
	path.push_back(bt->val);
	if (cursum == target && !bt->BTleft && !bt->BTright)
	{
		result.push_back(path);
	}
	if (bt->BTleft)
	{
		findpath(bt->BTleft, target, cursum, result, path);
	}
	if (bt->BTright)
	{
		findpath(bt->BTright, target, cursum, result, path);
	}
	path.pop_back();
}
//二叉搜索树查找
BT* bstSearch(BT* bt, int t)
{
	if (!bt || bt->val == t)
	{
		return bt;
	}
	else if (t < bt->val)
	{
		return bstSearch(bt->BTleft,t);
	}
	else
	{
		return bstSearch(bt->BTright, t);
	}
}
//二叉排序树插入
void bstIsert(BT* &bt, int t)
{
	if (!bt)
	{
		bt = new BT(t);
	}
	else if (t == bt->val)
	{
		return;
	}
	else if (t < bt->val)
	{
		bstIsert(bt->BTleft,t);
	}
	else
	{
		bstIsert(bt->BTright,t);
	}
}
//二叉排序树的生成
void bstCreat(BT* &bt,vector<int> v)
{
	//BT* bt = NULL;
	for (int i = 0; i < v.size(); i++)
	{
		bstIsert(bt,v[i]);
	}
	//return bt;
}
//二叉搜索树节点删除
void deleteNode(BT*& bt);
void deleteboth(BT* &bt, BT* & root);
void bstDelete(BT* &bt, int t)
{
	if (!bt)
	{
		return;
	}
	else if (bt->val == t)
	{
		deleteNode(bt);
	}
	else if (bt->val < t)
	{
		bstDelete(bt->BTright,t);
	}
	else
	{
		bstDelete(bt->BTleft, t);
	}
}
void deleteNode(BT*& bt)
{
	BT* temp;
	if (!bt->BTleft && !bt->BTright)
	{
		delete bt;
		bt = NULL;
	}
	else if (bt->BTleft)
	{
		temp = bt;
		bt = bt->BTleft;
		delete temp;
	}
	else if (bt->BTright)
	{
		temp = bt;
		bt = bt->BTright;
		delete temp;
	}
	else
	{
		deleteboth(bt,bt->BTleft);
	}
}
void deleteboth(BT* &bt, BT* &root)
{
	BT* temp;
	if (!root->BTright)
	{
		temp = root;
		bt->val = root->val;
		root = root->BTleft;
		delete temp;
	}
	else
	{
		deleteboth(bt, root->BTright);
	}
}
//判断是否为合法的二叉搜索树
bool bstJudge1(BT* bt)
{
	if (!bt)
	{
		return true;
	}
	else if(!bt->BTleft && !bt->BTright)
	{
		return true;
	}
	else if(bt->BTleft && !bt->BTright && bt->BTleft->val < bt->val)
	{
		return bstJudge1(bt->BTleft);
	}
	else if (!bt->BTleft && bt->BTright && bt->BTright->val > bt->val)
	{
		return bstJudge1(bt->BTright);
	}
	else if(bt->BTleft && bt->BTright && bt->BTleft->val < bt->val && bt->BTright->val > bt->val)
	{
		return bstJudge1(bt->BTleft) && bstJudge1(bt->BTright);
	}
	else
	{
		return false;
	}
}
void inOrder(BT* &bt, vector<int> &v);
bool bstJudge2(BT* bt)
{
	vector<int> v;
	inOrder(bt, v);
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] >= v[i + 1])
		{
			return false;
		}
	}
	return true;
}
void inOrder(BT*& bt, vector<int>& v)
{
	if (bt)
	{
		inOrder(bt->BTleft,v);
		v.push_back(bt->val);
		inOrder(bt->BTright, v);
	}
}
//n个节点能组成多少种二叉树(或二叉搜索树)
int bstnums(int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return 1;
	}
	vector<int> v(n + 1, 0);
	v[0] = 1;
	v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			v[i] += v[j] * v[i - j - 1];
		}
	}
	return v[n];
}
void test()
{
	cout << bstnums(3) << endl;
	//TreeNode* TR = NULL;
	//CreatTreeNode(TR);
	//preTraverse(TR);
	//cout << endl;
	//midTraverse(TR);
	//cout << endl;
	//posTraverse(TR);
	//cout << endl;
	//string pre = "ABDHEICFGJ";
	//string mid = "DHBIEAFCJG";
	//TreeNode* TR = CreatTRpremid(pre,mid);
	//preTraverse(TR);
	//midTraverse(TR);
	//posTraverse(TR);
	//cout << endl;
	//preIterator(TR);
	//midIteratior(TR);
	//posIteratior(TR);
	//cout << endl;
	//posTraverse(TR);
	//layerTraverse(TR);
	//cout << endl;
	//cout << depth(TR) << endl;
	//cout << countNode(TR) << endl;
	//cout << countLeft(TR) << endl;
	//cout << find_max_depth_V2(TR) << endl;
	//cout << minDepth1(TR) << endl;
	//cout << minDepth2(TR) << endl;
	//cout << countKNodes(TR, 4) << endl;
	//cout << isBalanced(TR) << endl;
	//cout << isFullTree1(TR) << endl;
	//cout << isFullTree2(TR) << endl;
	//BT bt1(4);
	//BT bt2(3);
	//BT bt3(5);
	//BT bt4(1);
	//BT bt5(2);
	//BT bt6(6);
	//bt1.BTleft = &bt2;
	//bt1.BTright = &bt3;
	//bt2.BTleft = &bt4;
	//bt3.BTright = &bt6;
	//bt4.BTright = &bt5;
	//midTraverse1(&bt1);
	//cout << endl;
	//BT* bt = NULL;
	//bstIsert(bt,1);
	//midTraverse1(bt);
	//cout << endl;
	//vector<int> v = {2,5,3,4,8,1,2,3,7,6,8};
	////BT* bbt = bstCreat(v);
	//BT* bbt = NULL;
	//bstCreat(bbt, v);
	//midTraverse1(bbt);
	//cout << endl;
	//bstDelete(bbt,6);
	//midTraverse1(bbt);
	//cout << endl;
	//cout << bstJudge1(&bt1) << endl;
	//cout << bstJudge2(&bt1) << endl;
	//vector<vector<int>> v = FindPath(&bt1, 12);
	//for (int i = 0; i < v.size(); i++)
	//{
	//	for (int j = 0; j < v[i].size(); j++)
	//	{
	//		cout << v[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//string str = serialize(&bt1);
	//cout << str << endl;
	//BT* bt = reserialize(str);
	//layerTraverse1(bt);
	//cout << endl;
	//string str;
	//btserialize(&bt1,str);
	//cout << str << endl;
	//BT* bt = new BT;
	//btreserialize(bt,str);
	//preTraverseInt(bt);
	//cout << endl;
	//vector<BT*> v;
	//v = btTOvec(&bt1);
	//for (vector<BT*>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	if (*it)
	//	{
	//		cout << (*it)->val << " ";
	//	}
	//	else
	//	{
	//		cout << "#" << " ";
	//	}
	//	
	//}
	//cout << endl;
	//vector<int*> v;
	//int a = 10;
	//v.push_back(&a);
	//cout << **v.begin() << endl;
}