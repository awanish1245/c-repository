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
    Node *currNodes = new Node(Nodes[idx]);
    currNodes->left = buildtree(Nodes);
    currNodes->right = buildtree(Nodes);
    return currNodes;
}
int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftcount = count(root->left);
    int rightcount = count(root->right);
    return leftcount + rightcount + 1;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *root = buildtree(nodes);

    cout << "root = " << root->data << endl;
    cout << "count: " << count(root) << endl;

    return 0;
}