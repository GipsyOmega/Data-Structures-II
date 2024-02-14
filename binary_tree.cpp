#include <iostream>
#include <queue>
#include <chrono>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorderPrint(node *root)
{
    if (root != NULL)
    {
        inorderPrint(root->left);
        cout << root->data << " ";
        inorderPrint(root->right);
    }
    return;
}

void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << "\t";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << "\t";
        postorder(root->right);
        postorder(root->left);
    }
}

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i < end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    node *root = new node(curr);
    if (start == end)
    {
        return root;
    }
    int pos = search(inorder, start, end, curr);
    root->left = buildTree(preorder, inorder, start, pos - 1);
    root->right = buildTree(preorder, inorder, pos + 1, end);

    return root;
}

node *buildTreePO(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
    if (start > end)
    {
        return NULL;
    }
    int curr = postorder[idx];
    idx--;
    node *root = new node(curr);
    if (start == end)
    {
        return root;
    }
    int pos = search(inorder, start, end, curr);
    root->right = buildTree(postorder, inorder, pos + 1, end);
    root->left = buildTree(postorder, inorder, start, pos - 1);
    return root;
}

void printLevelOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    // ITERATIVE APPROACH
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *Node = q.front();
        q.pop();
        if (Node != NULL)
        {
            cout << Node->data << '\t';
            if (Node->left)
                q.push(Node->left);
            if (Node->right)
                q.push(Node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            cout << '\n';
        }
    }
}

int SumatK(node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int i = 0, sum = 0;
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *Node = q.front();
        q.pop();
        if (Node != NULL)
        {
            if (i == k)
                sum += Node->data;
            cout << Node->data << '\t';
            if (Node->left)
                q.push(Node->left);
            if (Node->right)
                q.push(Node->right);
        }

        else if (!q.empty())
        {
            q.push(NULL);
            i++;
            cout << '\n';
        }
        // cout << "I VALUE: " << i << endl;
    }
    return sum;
}

int countNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(node *root)
{
    return root ? sumNodes(root->left) + sumNodes(root->right) + root->data : 0;
}

int calcHeight(node *root) // O(N)
{
    return root ? max(calcHeight(root->left), calcHeight(root->right)) + 1 : 0;
}

int calcDiameter(node *root) // O(N^2)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = calcHeight(root->left);
    int rh = calcHeight(root->right);
    int currDia = lh + rh + 1;

    int ld = calcDiameter(root->left);
    int rd = calcDiameter(root->right);

    return max(currDia, max(ld, rd));
}

int calcDiameterOpt(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = calcDiameterOpt(root->left, &lh);
    int rDiameter = calcDiameterOpt(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

void sumReplace(node *root)
{
    if (root == NULL)
    {
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);

    if (root->left)
    {
        root->data += root->left->data;
    }

    if (root->right)
    {
        root->data += root->right->data;
    }
}

bool isBalanced(node *root, int *height)
{
    if (root)
        *height = 0;
    return true;

    int lh = 0, rh = 0;
    if (!isBalanced(root->left, &lh) || !isBalanced(root->right, &rh))
    {
        return false;
    }
    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
        return false;
}

void rightView(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        // cout << "N: " << n << endl;

        for (int i = 0; i < n; i++)
        {
            node *front = q.front();
            q.pop();
            if (i == n - 1)
            {
                cout << front->data << " ";
            }
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}
void leftView(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        // cout << "N: " << n << endl;

        for (int i = 0; i < n; i++)
        {
            node *front = q.front();
            q.pop();
            if (i == 0)
            {
                cout << front->data << " ";
            }
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

void flatten(node *root)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        flatten(root->left);
        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
}
// LEVEL ORDER?
/*    1
    2   3
   4 6 * 5
*/

void printSubtrees(node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << "\t";
        return;
    }
    printSubtrees(root->left, k - 1);
    printSubtrees(root->right, k - 1);
}

int printNodesatK(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        printSubtrees(root, k);
        return 0;
    }
    int dl = printNodesatK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << "\t";
        }
        else
        {
            printSubtrees(root->right, k - dl - 2);
        }
        return dl + 1;
    }
    int dr = printNodesatK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << "\t";
        }
        else
        {
            printSubtrees(root->left, k - dr - 2);
        }
        return dr + 1;
    }
    return -1;
}
int main()
{
    // int preorder[] = {1, 2, 4, 3, 5};
    // int inorder[] = {4, 2, 1, 5, 3};

    // node *Node = buildTree(preorder, inorder, 0, 4);
    // inorderPrint(Node);
    // inorder(Node);

    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(7);
    root->left->right = new node(5);
    root->right->left = new node(6);
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    // inorder(root);
    cout << endl;
    cout << "LEVEL ORDER TRAVERSAL\n";
    printLevelOrder(root);
    cout << "\nSUM AT KTH LEVEL\n";
    int sum = SumatK(root, 2);
    cout << "\nSUM: " << sum << endl;
    sum = sumNodes(root);
    cout << "\nSUM OF NODES: " << sum;
    sum = countNodes(root);
    cout << "\nNUMBER OF NODES: " << sum;
    sum = calcHeight(root);
    cout << "\nHEIGHT OF TREE: " << sum;
    sum = calcDiameter(root);
    cout << "\nDIAMETER OF TREE: " << sum;
    int height = 0;
    sum = calcDiameterOpt(root, &height);
    cout << "\nDIAMETER OF TREE Optimised: " << sum << endl;
    cout << "LEVEL ORDER TRAVERSAL\n";
    printLevelOrder(root);
    cout << endl;
    sumReplace(root);
    cout << "SUM REPLACE: LEVEL ORDER TRAVERSAL\n";
    printLevelOrder(root);
    cout << "\nTREE BALANCED?\n";
    cout << isBalanced(root, &height) << endl;
    cout << "RIGHT VIEW TREE\n";
    rightView(root);
    cout << "\nLEFT VIEW TREE\n";
    leftView(root);
    // cout << "\nFLATTEN BINARY TREE\n";
    // flatten(root);
    // inorderPrint(root);
    cout << "\nSUBTREES PRINT\n";
    printSubtrees(root, 1);
    cout << endl;
    cout << "NODES AT DISTANCE K PRINT\n";
    printNodesatK(root, root->left, 1);
}