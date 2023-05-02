#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *CreateBST(node* root , int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(data > root->data)
    {
        root->right = CreateBST(root->right , data);
    }
    else
    {
        root->left = CreateBST(root->left , data);
    }
    return root;
}

void takeInput(node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = CreateBST(root , data);
        cin>>data;
    }
}

void inorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void postorder(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void leveOrderTraversal(node* root)
{
    if(root == NULL)
    {
        return ;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* frontNode = q.front();
        q.pop();

        if(frontNode == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<frontNode->data<<" ";
            if(frontNode->left)
        {
            q.push(frontNode->left);
        }
            if(frontNode->right)
        {
            q.push(frontNode->right);
        }
        }
        
    }
}

int minValue(node* root)
{
    node *temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int maxValue(node* root)
{
    node *temp = root;
    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}
int main()
{
    node *root = NULL;
    cout<<"Enter the data\n";
    takeInput(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    leveOrderTraversal(root);
    return 0;
}