#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node * Left;
    Node * Right;

    Node(int val)
    {
        this->data=val;
        this->Left=NULL;
        this->Right=NULL;
    }
};

// struct Node{
//     int data;
//     struct Node* Left;
//     struct Node* Right;

//     Node(int val)
//     {
//         data=val;
//         Left=NULL;
//         Right=NULL;
//     }
// }
Node* CreateTree(Node* root)
{
    cout<<"Enter the data for Node(-1 to NOT insert the data):";
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1)
    {
        return NULL;
    }
    cout<<"Enter the data for left child of "<<data<<endl;
    root->Left=CreateTree(root->Left);
    cout<<"Enter the data  for right child of "<<data<<endl;
    root->Right=CreateTree(root->Right);
    return root;
}

void PreOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    cout<<root->data<<" ";
    PreOrder(root->Left);
    PreOrder(root->Right);
}

void PostOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    PostOrder(root->Left);
    PostOrder(root->Right);
    cout<<root->data<<" ";
    
}

void InOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    InOrder(root->Left);
    cout<<root->data<<" ";
    InOrder(root->Right);
    
}

void LevelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        
        if(temp->Left!=NULL){
            q.push(root->Left);
        }

        if(temp->Right!=NULL){
            q.push(root->Right);
        }
    }

}
int c=0;
int CountNode(Node* root)
{
     

    // if(root==NULL)
    // return c;
    // if(root->Left!=NULL)
    // {c+=1;
    // CountNode(root->Left);}
    // if(root->Right!=NULL)
    // {c+=1;
    // CountNode(root->Right);}
    // return c+1;
    


    if(root!=NULL)
    {
        CountNode(root->Left);
        c++;
        CountNode(root->Right);
    }
    return c;
}

int main()
{
    Node* root;
    root=CreateTree(root);
    cout<<"Preorder :"<<endl;
    PreOrder(root);
    cout<<endl;
    cout<<"Inorder :"<<endl;
    InOrder(root);
    cout<<endl;
    cout<<"Postorder :"<<endl;
    PostOrder(root);
    cout<<endl;
    // cout<<"Levelorder :"<<endl;
    // LevelOrder(root);
    // cout<<endl;

    cout<<"No. of nodes :"<<CountNode(root);

    return 0;  
}