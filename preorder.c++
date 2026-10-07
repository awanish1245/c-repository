#include <iostream>
#include <vector>
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
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);

    cout << "root = " << root->data << endl;
    preorder(root);
    cout << endl;

    return 0;
}