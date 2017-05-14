//
//  fallingBall2.cpp
//  tree
/*
 * $2^D-1$个开关排列成深度为D的二叉树，最初都为关闭状态。有n个小球从顶端依次落下，并遵循如下规则：
1. 如果经过一个关闭的开关，则开关打开，小球落向左侧；
2. 如果经过一个打开的开关，则开关关闭，小球落向右侧；
输入D，n，输出最后一个小球最终落到的位置。
样例输入:
4 3
样例输出：
10
## 小球下落问题2
与原题一样，改为输出所有叶节点开关状态。
样例输入：
4 3
样例输出：
1 0 1 0 1 0 0 0
 */

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    Node *left=0,*right=0;  // 左右子树指针
    int id,status=0;   // 开关id,开关状态

    Node(int id0){    // 构造函数，可以理解为初始化函数
        id=id0;
    }

    int isLeaf() { // 成员方法，返回当前节点是否是叶子
        return left==0 && right==0;
    }

    void addChild(Node *child,int isleft) { // 添加一个新节点/子树
        (isleft ? left : right) = child;    // 直接设置左右子树字段
    }
};

// 构造以id为根节点，深度为d的满二叉树
Node* buildTree(int id, int depth){
    if (depth == 0) { // 递归边界
        return 0;
    }
    Node *node= new Node(id); // 本节点指针

    // 递归构造左右子树，深度减一
    node->addChild(buildTree(id*2, depth-1), 1);
    node->addChild(buildTree(id*2+1, depth-1), 0);
    return node;
}

// 模拟一次下落过程
int fall(Node* node){
    node->status ^= 1;   // 改变当前节点开关
    if (node->isLeaf()){ // 到底了，返回当前id
        return node->id;
    }
    return node->status==1 ? fall(node->left) : fall(node->right); // 选择下一层节点
}

void printChildNode(Node *node) {
    if(node == NULL)
        return;
    if(node->isLeaf())
        cout << node->status << " ";
    printChildNode(node->left);
    printChildNode(node->right);
}

int main(int argc, const char * argv[]) {
    int d, n;
    cin >> d >> n;
    vector<int> result;
    Node *root = buildTree(1, d);
    for (int i = 0; i <= n - 1; i++) { // 模拟前n次
        fall(root);
    }
    printChildNode(root);
    cout << endl;
    return 0;
}
