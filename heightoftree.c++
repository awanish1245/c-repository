#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
static int idx = -1;
Node *buildtree(vector<int> Nodes)
{
    idx++;
    if (Nodes[idx] == -1)
    {
        return NULL;
    }
    Node *currNode = new Node(Nodes[idx]);
    currNode->left = buildtree(Nodes);
    currNode->right = buildtree(Nodes);
    return currNode;
}
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    int currheight = max(leftheight, rightheight) + 1;
    return currheight;
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);

    cout << "root = " << root->data << endl;
    cout << "height:" << height(root) << endl;
    return 0;
}