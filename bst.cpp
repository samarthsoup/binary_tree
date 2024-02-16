#include <iostream>

using namespace std;

class node {
	string word,meaning;
	node *left, *right;
	
	friend class bst;
};

class bst {
	node *root;
	
	public:	
		void create();
		void inorder(node*root);
        void inorder();
        void mirror(node*root);
        void mirror();
        void mirror_non_recursive(node*root);
        void mirror_non_recursive();
        node* copy(node*root);
        void copy();
        void level_wise(node*root);
        void level_wise();
		void remove();
};

class queue {
	node* kyu[20];
	int front, rear;
	
	public: 
		queue() {
			front = -1;
			rear = -1;
		}
		void insert(node *t) {
			rear++;
			kyu[rear] = t;
		}
		node* remove() {
			front++;
			return kyu[front];
		}
		bool empty(){
			if(front == rear) {
				return true;
			} else {
				return false;
			}
		}
};

void bst::create() {
	root = new node();
	cout << "enter root->word: ";
	cin >> root->word;
	cout << "enter root->meaning: ";
	cin >> root->meaning;
	root->left = root->right = NULL;
	
	char choice;
    cout << "enter q to stop giving input" << endl;
	do {
		node *temp = root;
		int flag = 1;
		node *curr = new node();
		
		cout << "add data?" << endl;
        cin >> choice;
		
		if (choice != 'q'){
			cout << "enter curr->word: ";
			cin >> curr->word;
			cout << "enter curr->meaning: ";
			cin >> curr->meaning;
			
			curr->left = curr->right = NULL;
			
			while (flag == 1) {
				if (curr->word <= temp->word) {
					if (temp->left == NULL) {
						temp->left = curr;
						flag = 0;
						break;
					} else {
						temp = temp->left;
						flag = 1;
					}
				} else {
					if (temp->right == NULL) {
						temp->right = curr;
						flag = 0;
						break;
					} else {
						temp = temp->right;
						flag = 1;
					}
				}
			}
		}
	} while (choice != 'q');
}

void bst::inorder(node*root) {
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->word<<": "<<root->meaning<<endl;
        inorder(root->right);
    }
}

void bst::inorder() {
    cout<<"\ndictionary traversal:\n";
    inorder(root);
}

void bst::mirror(node*root) {
	node *temp = root->left;
	root->left = root->right;
	root->right = temp;
	if (root->left != NULL) {
		mirror(root->left);
	}
	if (root->right != NULL) {
		mirror(root->right);
	}
}

void bst::mirror() {
	cout<<"\nmirrored!\n";
	mirror(root);
}

void bst::mirror_non_recursive(node* root) {
	queue q;
	node* temp = root;
	q.insert(temp);
	while(!q.empty()){
		temp = q.remove();
		node *t = root->left;
		root->left = root->right;
		root->right = t;
		
		if(temp->left!=NULL) q.insert(temp->left);
		if(temp->right!=NULL) q.insert(temp->right);
	}
}

void bst::mirror_non_recursive() {
	cout<<"\nmirrored!\n";
	mirror_non_recursive(root);
}
		

node* bst::copy(node*root) {
	node *temp = NULL;
	if(root != NULL) {
		temp = new node();
		temp->word = root->word;
		temp->meaning = root->meaning;
		temp->left = copy(root->left);
		temp->right = copy(root->right);
	}
	return temp;
}

void bst::copy() {
	cout<<"\ncopied!\n";
	node* a = copy(root);
	inorder(a);
}

void bst::level_wise(node*root) {
	queue q;
	node* temp = root;
	q.insert(temp);
	while(!q.empty()) {
		temp = q.remove();
		cout << temp->word << ": " << temp->meaning << endl;
		if (temp->left != NULL) {
			q.insert(temp->left);
		}
		if (temp->right != NULL) {
			q.insert(temp->right);
		}
	}
}

void bst::level_wise() {
	cout<<"\nlevel wise traversal:\n";
    level_wise(root);
}

void bst::remove() {
	string key;
	cout << "enter data of node that you want to delete: ";
	cin >> key;
	node* temp = root;
	node* parent = NULL;

	while(temp!=NULL){
		if(temp->word == key){
			break;
		} else if(temp->word < key){
			parent = temp;
			temp = temp->right;
		} else {
			parent = temp;
			temp = temp->left;
		}
	}

	if(temp != root){
		if (temp->left == NULL && temp->right == NULL){
			if(parent->right == temp) parent->right = temp->left;
			else {
				parent->left = NULL;
				delete(temp);
			}
		} else if (temp->left != NULL && temp->right == NULL){
			if(parent->right == temp) parent->right = temp->left;
			temp->left = NULL;
			delete(temp);
		} else if (temp->left == NULL && temp->right != NULL){
			if(parent->left == temp) parent->left = temp->right;
			temp->right = NULL;
			delete(temp);
		} else {
			node* s = temp->left;
			node* r = temp->right;

			if(parent->right == temp) parent->right = r;
			else parent->left = r;

			while(r->left != NULL){
				r = r->left;
			}
			r->left = s;
		}
	}
	

	if(temp == root){
		if(temp->left == NULL && temp->right == NULL){
			root = NULL;
		} else if (temp->left != NULL && temp->right == NULL){
			root = temp->left;
			delete(temp);
		} else if (temp->left == NULL && temp->right != NULL){
			root = temp->right;
			delete(temp);
		} else {
			node* r= temp->right;
			node* s = temp->left;
			root=r;
			while(r->left != NULL){
				r = r->left;
			}
			r->left = s;
			temp->left=NULL;
		}
	}
}

int main() {
	bst b;
	b.create();
	b.inorder();
	//b.level_wise();
	b.remove();
	b.inorder();
	//b.copy();
	//b.mirror_non_recursive();
	//b.inorder();
	return 0;
}
		
