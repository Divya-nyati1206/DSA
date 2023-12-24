#include<iostream>
using namespace std;

struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;

    node(int val)
    {
        key=val;
        left=NULL;
        right=NULL;
        height=1;
    }
};

struct node* root=NULL;

int max(int a,int b)
{
    return a>b?a:b;
}

int height(struct node* root)
{
    if(root==NULL)
    return 0;
    return root->height;
}

int balance_factor(struct node* root)
{
    return (height(root->left)-height(root->right))+1;
}

struct node* leftrotate(struct node* x)
{
    struct node* y=x->right;
    struct node* t2=y->left;
    y->left=x;
    x->right=t2;
    y->height=max(height(y->right),height(y->left))+1;
    x->height=max(height(x->right),height(x->left))+1;
    return y;
}

struct node* rightrotate(struct node* y)
{
    struct node* x=y->left;
    struct node* t2=x->right;
    x->right=y;
    y->left=t2;
    x->height=max(height(x->right),height(x->left))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return x;  
}

struct node* inserttoavl(struct node* root,int d)
{
    if(root==NULL)
    {
        root=new node(d);
        return root;
    }
    else if(d>root->key)
    {
        root->right=inserttoavl(root->right,d);
    }
    else if(d<root->key)
    {
        root->left=inserttoavl(root->left,d);
    }
    else{
        return root;
    }

    root->height=max(height(root->right),height(root->left))+1;;
    //left rotate
    int bf=balance_factor(root); 
    if(bf > 1 && d < root->left->key)
    {
        return rightrotate(root);
    }
     //right rotate
    if(bf <-1 && d > root->right->key)
    {
        return leftrotate(root);
    }
     //left right rotate
    if(bf > 1 && d > root->left->key)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
     // right left rotate
    if(bf < -1 && d < root->right->key)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;

}

struct node* takeinput(struct node* root)
{
    int d;
    cout<<"Enter the data which you want to insert in tree (-1 for NULL node)";
    cin>>d;
    while(d!=-1)
    {
        root=inserttoavl(root,d);
        cin>>d;
    }
    return root;
}

void insertion()
{
    root=takeinput(root);
}

void PreOrder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    cout<<root->key<<" ";
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
    cout<<root->key<<" ";
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
    cout<<root->key<<" ";
    
}

void traverse()
{
    cout<<"Enter 1 for preorder\nEnter 2 for Inorder\nEnter 3 for Postorder\nEnter your choice:";
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
        cout<<"Postorder :"<<endl;
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
    else if(root->key=d)
    {
        return root;
    }
    else if(root->key<d)
    {
        searchnode(root->right,d);
    }
    else if(root->key>d)
    {
        searchnode(root->left,d);
    }
    
}

void showheight()
{
    int data;
    cout<<"Enter the node of which you want height :";
    cin>>data;
    struct node* ser=searchnode(root,data);
    cout<<"Height of "<<data<<" is "<<ser->height;
}

int main()
{
    while(1)
    {
        int choice;
        cout<<"\nEnter 1 to insert\nEnter 2 to traverse\nEnter 0 to exit:";
        cin>>choice;
        if(choice!=0)
        {
            switch(choice)
            {
                case 1:insertion();break;
                case 2:traverse();break;
                //case 3:showheight();break;
                default:cout<<"Enter a valid choice!!!\n";break;
            }
        }
        else{
            break;
        }
    }

    return 0;
}

