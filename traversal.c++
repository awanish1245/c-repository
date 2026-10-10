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
void levelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *curr = Q.front();
        Q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
        {
            Q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            Q.push(curr->right);
        }
        cout << endl;
    }
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);

    cout << "root = " << root->data << endl;
    levelorder(root);
    return 0;
}