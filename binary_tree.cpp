#include <iostream>
using namespace std;
class node{
    char data;
    node *left;
    node *right;
    friend class binary_tree;
};

class stack{
    node* st[20];
    int top;
    public: 
    stack()
    {
        top=-1;
    }
    node* push(node *t);
    node* pop();
    int empty();
};

node* stack::push(node *t){
    top++;
    st[top]=t;
    return st[top];
}

node* stack::pop(){
    node *t = st[top];
    top--;
    return t;
}

int stack::empty(){
    if(top==-1)
        return true;
    else
        return false;
}

class binary_tree{
    node *root;
    public:
        void build();
        void build_recursive();
        void create(node*root);
        void create_recursive(node*root);
        void preorder(node*root);
        void preorder();
        void nonrec_preorder();
        void inorder(node*root);
        void inorder();
        void nonrec_inorder();
        void postorder(node*root);
        void postorder();
        void nonrec_postorder();
};

void binary_tree::build(){
    root = new node();
    cout<<"data for root node: \n";
    cin>>root->data;
    cout<<endl;
    root->left = root->right = NULL;
    create(root);
}

/*void binary_tree :: build_recursive()
{
    root = new node();
    cout<<"Enter data for Root node \n";
    cin>>root->data;
    cout<<endl;
    root->left = root->right = NULL;
    create_recursive(root);
}
*/
void binary_tree::create(node *root){
    char choice;
    cout << "enter q to stop giving input" << endl;
    do {
        node *temp = root;
        node *ptr = new node();
        string path;

        cout << "path: ";
        cin>>path;
        cout<<"\ndata: ";
        cin>>ptr->data;
        cout<<endl;

        bool invalidPath = false;

        for(int i = 0; i < path.length(); i++) {
            char c = path[i];

            if (c == '0') {
                if (i == path.length()-1){
                    temp->left = ptr;
                } else {
                    temp = temp->left;
                }
            } else if (c == '1') {
                if (i == path.length()-1){
                    temp->right = ptr;
                } else {
                    temp = temp->right;
                }
            } else {
                cerr << "invalid path" << endl;
                invalidPath = true;
                break;
            }
            if(invalidPath) break;
        }

        cout << "add data?" << endl;
        cin >> choice;


        /*int flag=0;
        char ch;
        node *temp = root;
        node *ptr = new node();
        cout<<"Enter the  data\n";
        cin>> ptr->data;
        cout<<endl;
        ptr->left = ptr->right = NULL;
        while(flag == 0){
            cout<<"Where do you want to enter the data: Right(R) or Left(L)"<<" "<<temp->data<<"\n";
            cin>>ch;
            cout<<endl;
            if(ch == 'L')
            {
                if(temp->left == NULL)
                {
                    temp->left=ptr;
                    flag = 1;
                }
                else
                {
                    temp=temp->left;
                    flag=0;
                }
            }
            if(ch == 'R')
            {
                if(temp->right == NULL)
                {
                    temp->right=ptr;
                    flag = 1;
                }
                else
                {
                    temp=temp->right;
                    flag=0;
                }
            }
        }*/
    }while(choice != 'q');
}
/*
void binary_tree ::create_recursive(node *root)
{
         node *ptr;
    char ch;
    cout<<"Do you want to attach node on Left? Yes(Y) or No(N)\n";
    cin>>ch;
    cout<<endl;
    if(ch == 'Y')
    {
        ptr = new node();
        cout<<"Enter data of node\n";
        cin>>ptr->data;
        ptr->left = ptr->right = NULL;
        root->left = ptr;
        create_recursive(ptr);
    }
    cout<<"Do you want to attach node on Right? Yes(Y) or No(N)\n";
    cin>>ch;
    cout<<endl;
    if(ch == 'Y')
    {
        ptr = new node();
        cout<<"Enter data of node\n";
        cin>>ptr->data;
        ptr->left = ptr->right = NULL;
        root->right = ptr;
        create_recursive(ptr);
    }
}
*/
void binary_tree::preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void binary_tree::preorder()
{
    cout<<"\n preorder traversal :";
    preorder(root);
}

void binary_tree::nonrec_preorder()
{
    stack s;
    node *temp = root;
     cout<<"\n nonrec_preorder traversal :";
    while(1)
    {
        while(temp!=NULL)
        {
            cout<<temp->data;
            s.push(temp);
            temp=temp->left;
        }
        if(s.empty()==true)
            break;
        temp=s.pop();
        temp = temp->right;
    }
      
   
}

void binary_tree::inorder(node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }
}

void binary_tree::inorder()
{
    cout<<"\n inorder traversal :";
    inorder(root);
}

void binary_tree::nonrec_inorder()
{
    stack s;
    node *temp = root;
    cout<<"\n nonrec_inorder traversal :";
    while(1)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        if(s.empty()==true)
            break;
        temp=s.pop();
        cout<<temp->data;
        temp = temp->right;
    }
     
    
}

void binary_tree::postorder(node*root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data;
    }
}

void binary_tree::postorder()
{
    cout<<"\n postorder traversal :";
    postorder(root);
}

void binary_tree::nonrec_postorder()
{
    stack s1, s2;
    node *temp = root;
    s1.push(temp);
    cout<<"\n nonrec_postorder traversal :";
    while(!s1.empty())
    {
        temp = s1.pop();
        s2.push(temp);
        if(temp->left!=NULL)
            s1.push(temp->left);
        if(temp->right!=NULL)
            s1.push(temp->right);
    }
    while(!s2.empty())
    {
        temp = s2.pop();
        cout<<temp->data;
    }
    
    
}

int main()
{
	binary_tree b;
	b.build();
	//b.build_recursive();
	b.preorder();
	b.nonrec_preorder();
	b.inorder();
	b.nonrec_inorder();
	b.postorder();
	b.nonrec_postorder();
	return 0;
}
