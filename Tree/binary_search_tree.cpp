#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

struct node* Node=NULL;
struct node* pre=NULL;
struct node* root=NULL;

void insertion()
{
    int data;
    cout<<"Enter the value you want to insert :";
    cin>>data;
    if(root==NULL)
    {
        root=new node(data);
    }
    else
    {
        Node=root;
        pre=NULL;
        while(Node!=NULL)
        {
            if(Node->data>data)
            {
                pre=Node;
                Node=Node->left;
            }
            else if(Node->data<data)
            {
                pre=Node;
                Node=Node->right;
            }
        }
        if(pre->data>data)
        {
            pre->left=new node(data);
        }
        else if(pre->data<data)
        {
            pre->right=new node(data);
        }
    }
}

// struct node* inserttobst(struct node* root,int d)
// {
//     if(root==NULL)
//     {
//         root = new node(d);
//         return root;
//     }
//     else if(root->data>d)
//     {
//         root->left=inserttobst(root->left,d);
//     }
//     else if(root->data<d)
//     {
//         root->right=inserttobst(root->right,d);
//     }
//     return root;
// }

// struct node* takeinput(struct node* root)
// {
//     int data;
//     cout<<"\nEnter the data you want to insert in binary search tree :";
//     while(data!=-1)
//     {
//         root=inserttobst(root,data);
//         cin>>data;
//     }
//     return root;
// }

// void insertion()
// {
//     root=takeinput(root);
// }

struct node* minvalue(struct node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct node* deletenode(struct node* root,int val)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==val)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        if(root->left!=NULL && root->right==NULL)
        {
            struct node* temp=root->left;
            delete root;
            return temp;
        }

        if(root->right!=NULL && root->left==NULL)
        {
            struct node* temp=root->right;
            delete root;
            return temp;
        }

        if(root->left!=NULL && root->right!=NULL)
        {
            int mini=minvalue(root->right)->data;
            root->data=mini;
            root->right=deletenode(root->right,mini);
            return root;
        }
    }
    else if(root->data>val)
    {
        root->left=deletenode(root->left,val);
        return root;
    }
    else{
        root->right=deletenode(root->right,val);
        return root;
    }
}

void deletion()
{
    int val;
    cout<<"Enter the node which you want to delete :";
    cin>>val;
    root=deletenode(root,val);
}

void PreOrder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
    
}

void PostOrder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
    
}

void traverse()
{
    cout<<"Enter 1 for preorder traversal\nEnter 2 for inorder traversal\nEnter 3 for postorder traversal:";
    int ch;
    cin>>ch;
    if(ch==1)
    {
        cout<<"Preorder :"<<endl;
        PreOrder(root);
        cout<<endl;
    }
    else if(ch==2)
    {
        cout<<"Inorder :"<<endl;
        InOrder(root);
        cout<<endl;
    }
    else if(ch==3)
    {
        cout<<"Postordeer :"<<endl;
        PostOrder(root);
        cout<<endl;
    }
}

struct node* searchnode(struct node* root,int d)
{
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->data=d)
    {
        return root;
    }
    else if(root->data<d)
    {
        searchnode(root->right,d);
    }
    else if(root->data>d)
    {
        searchnode(root->left,d);
    }
    
}

void search()
{
    cout<<"Enter the data you want to search in binary search tree :";
    int d;
    cin>>d;
    struct node* ser=searchnode(root,d);
    cout<<d<<" found at address :"<<ser<<endl;
}

int main()
{
    int choice;

    while(1)
    {
        cout<<"Enter 1 for insertion\nEnter 2 for deletion\nEnter 3 for traversing\nEnter 4 to search a node\nEnter 0 to exit\nEnter your choice";
        cin>>choice;
        if(choice!=0)
        {
            switch(choice)
            {
                case 1:insertion();break;
                case 2:deletion();break;
                case 3:traverse();break;
                case 4:search();break;
                default:cout<<"Enter a valid choice!!!";break;
            }
        }

        if(choice==0)
        {
            break;
        }
    }

    return 0;
}