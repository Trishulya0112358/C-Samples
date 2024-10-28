// Solution by Jigar
#include<bits/stdc++.h> 
using namespace std; 

float curr=0.0;
class Node  
{  
    public: 
    int reg,n,d;
	float t,x; 
    Node *left;  
    Node *right;  
    int height;  
};  
class Noded0
{  
    public: 
    int reg,n,d;
	float t,x; 
    Noded0 *left;  
    Noded0 *right;  
    int height;  
};  
class Noded1
{  
    public: 
    int reg,n,d;
	float t,x; 
    Noded1 *left;  
    Noded1 *right;  
    int height;  
};  
  
Node *root = NULL;  
Noded0 *rootd0=NULL;
Noded1 *rootd1=NULL;


int height(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  

int height(Noded0 *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  
int height(Noded1 *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  

int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  

Node* newNode(int regi,float xi,float ti,int di)  
{  
    Node* node = new Node(); 
    node->reg = regi;
    node->t=ti;
    node->x=xi;
    node->d=di;
    node->n=0;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  
    return(node);  
}  

Noded0* newNoded0(int regi,float xi,float ti,int di)  
{  
    Noded0* node = new Noded0(); 
    node->reg = regi;
    node->t=ti;
    node->x=xi;
    node->d=di;
    node->n=0;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; 
    return(node);  
} 

Noded1* newNoded1(int regi,float xi,float ti,int di)  
{  
    Noded1* node = new Noded1(); 
    node->reg = regi;
    node->t=ti;
    node->x=xi;
    node->d=di;
    node->n=0;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;   
    return(node);  
} 

Node *rightRotate(Node *y)  
{  
    Node *x = y->left;  
    Node *T2 = x->right;  
  	int n1=0,n2=0,n3=0;
  	if(x->left!=NULL){n1=(x->left->n)+1;}
	if(x->right!=NULL){n2=(x->right->n)+1;}
  	if(y->right!=NULL){n3=(y->right->n)+1;}
  	
	x->n=x->n+n3+1;
    y->n=y->n-n1-1;

// Perform rotation  

    x->right = y;  
    y->left = T2;  
  
// Update heights  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    return x;  
}  

Noded0 *rightRotated0(Noded0 *y)  
{  
    Noded0 *x = y->left;  
    Noded0 *T2 = x->right;  
  	int n1=0,n2=0,n3=0;
  	if(x->left!=NULL){n1=(x->left->n)+1;}
	if(x->right!=NULL){n2=(x->right->n)+1;}
  	if(y->right!=NULL){n3=(y->right->n)+1;}
  	
  
	x->n=x->n+n3+1;
    y->n=y->n-n1-1;

// Perform rotation
    x->right = y;  
    y->left = T2;  
  
// Update heights  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    return x;  
}  

Noded1 *rightRotated1(Noded1 *y)  
{  
    Noded1 *x = y->left;  
    Noded1 *T2 = x->right;  
  	int n1=0,n2=0,n3=0;
  	if(x->left!=NULL){n1=(x->left->n)+1;}
	if(x->right!=NULL){n2=(x->right->n)+1;}
  	if(y->right!=NULL){n3=(y->right->n)+1;}
  	

	x->n=x->n+n3+1;
    y->n=y->n-n1-1;

// Perform rotation  

    x->right = y;  
    y->left = T2;  
  
    // Update heights  
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    return x;  
}

  
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  	int n1=0,n2=0,n3=0;
  	
  	if(y->right!=NULL){n1=(y->right->n)+1;}
	if(y->left!=NULL){n2=(y->left->n)+1;}
  	if(x->left!=NULL){n3=(x->left->n)+1;}
        

    x->n=x->n-n1-1;
    y->n=y->n+n3+1;    


    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  	
    // Update heights  
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    return y;  
}  
  
Noded0 *leftRotated0(Noded0 *x)  
{  
    Noded0 *y = x->right;  
    Noded0 *T2 = y->left;  
  	int n1=0,n2=0,n3=0;
  	
  	if(y->right!=NULL){n1=(y->right->n)+1;}
	if(y->left!=NULL){n2=(y->left->n)+1;}
  	if(x->left!=NULL){n3=(x->left->n)+1;}


    x->n=x->n-n1-1;
    y->n=y->n+n3+1;    


    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  	
    // Update heights  
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    return y;  
}

Noded1 *leftRotated1(Noded1 *x)  
{  
    Noded1 *y = x->right;  
    Noded1 *T2 = y->left;  
  	int n1=0,n2=0,n3=0;
  	
  	if(y->right!=NULL){n1=(y->right->n)+1;}
	if(y->left!=NULL){n2=(y->left->n)+1;}
  	if(x->left!=NULL){n3=(x->left->n)+1;}
        

    x->n=x->n-n1-1;
    y->n=y->n+n3+1;    


    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  	
    // Update heights  
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    return y;  
}

int getBalance(Node *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  

int getBalanced0(Noded0 *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
int getBalanced1(Noded1 *N)  
{  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  

Node* insert(Node* node, int regi,float xi,float ti,int di)  
{  
    if (node == NULL)  
        return(newNode(regi,xi,ti,di));  
  
    if (regi < node->reg)
    	{  
        node->n++;
        node->left = insert(node->left, regi,xi,ti,di);
        }  
    else if (regi > node->reg)
    {  
    node->n++;
    node->right = insert(node->right,regi,xi,ti,di);  
    }
    else  
        return node;  
  
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    int balance = getBalance(node);  
  
  
    // Left Left Case  
    if (balance > 1 && regi < node->left->reg)
    	 
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && regi > node->right->reg)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && regi > node->left->reg)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && regi < node->right->reg)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  
}  

Noded0* insertd0(Noded0* node, int regi,float xi,float ti,int di)  
{  
    if (node == NULL)  
        return(newNoded0(regi,xi,ti,di));  
  
    if (xi < (node->x)+(node->t)-curr)
    	{  
        node->n++;
        node->left = insertd0(node->left, regi,xi,ti,di);
        }  
    else if (xi > (node->x)+(node->t)-curr)
    {  
    node->n++;
    node->right = insertd0(node->right,regi,xi,ti,di);  
    }
    else   
        return node;  
  
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    int balance = getBalanced0(node);  
  
  
    // Left Left Case  
    if (balance > 1 && xi < (node->x)+(node->t)-curr)
    	 
        return rightRotated0(node);  
  
    // Right Right Case  
    if (balance < -1 && xi > (node->x)+(node->t)-curr)  
        return leftRotated0(node);  
  
    // Left Right Case  
    if (balance > 1 && xi > (node->x)+(node->t)-curr)  
    {  
        node->left = leftRotated0(node->left);  
        return rightRotated0(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && xi < (node->x)+(node->t)-curr)  
    {  
        node->right = rightRotated0(node->right);  
        return leftRotated0(node);  
    }  
  
    return node;  
}  

Noded1* insertd1(Noded1* node, int regi,float xi,float ti,int di)  
{  
    if (node == NULL)  
        return(newNoded1(regi,xi,ti,di));  
  
    if (xi < (node->x)-(node->t)+curr)
    	{  
        node->n++;
        node->left = insertd1(node->left, regi,xi,ti,di);
        }  
    else if (xi > (node->x)-(node->t)+curr)
    {  
    node->n++;
    node->right = insertd1(node->right,regi,xi,ti,di);  
    }
    else  
        return node;  
  
    node->height = 1 + max(height(node->left),  
                        height(node->right));  
  
    int balance = getBalanced1(node);  
  
  
    // Left Left Case  
    if (balance > 1 && xi < (node->x)-(node->t)+curr)
    	 
        return rightRotated1(node);  
  
    // Right Right Case  
    if (balance < -1 && xi > (node->x)-(node->t)+curr)  
        return leftRotated1(node);  
  
    // Left Right Case  
    if (balance > 1 && xi > (node->x)-(node->t)+curr)  
    {  
        node->left = leftRotated1(node->left);  
        return rightRotated1(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && xi < (node->x)-(node->t)+curr)  
    {  
        node->right = rightRotated1(node->right);  
        return leftRotated1(node);  
    }  
  
    return node;  
} 

Node * minValueNode(Node* node)  
{  
    Node* current = node;  
  
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}

Noded0 * minValueNoded0(Noded0* node)  
{  
    Noded0* current = node;  
  
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}

Noded1 * minValueNoded1(Noded1* node)  
{  
    Noded1* current = node;  
  
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}
 
Node* deleteNode(Node* root, int regi,float ti)  
{  
      
    if (root == NULL)  
        return root;  
  
    //Check in left subtree  
    if ( regi < root->reg )
    {  
     (root->n)--;
     root->left = deleteNode(root->left, regi,ti);  
  	}
    //Check in right subtree  
    else if( regi > root->reg )  
    {
    (root->n)--;
    root->right = deleteNode(root->right, regi,ti);  
  	}
    else
    {  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else  
            *root = *temp;  
            free(temp);  
        }  
        else
        {  
            Node* temp = minValueNode(root->right);  
  
            root->reg = temp->reg;
            (root->n)--;  
  
            root->right = deleteNode(root->right,  
                                     temp->reg,ti);  
        }  
    }  
  
    if (root == NULL)  
    return root;  
  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    int balance = getBalance(root);  
  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}  
 
Noded0* deleteNoded0(Noded0* root, float xi,float ti)  
{  
      
    if (root == NULL)  
        return root;  
  
    //Check in left subtree  
    if ( xi < (root->x)+(root->t)-curr )
    {  
     (root->n)--;
     root->left = deleteNoded0(root->left, xi,ti);  
  	}
    //Check in right subtree  
    else if( xi > (root->x)+(root->t)-curr )  
    {
    (root->n)--;
    root->right = deleteNoded0(root->right, xi,ti);  
  	}
    else
    {  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Noded0 *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else   
            *root = *temp;  
            free(temp);  
        }  
        else
        {  
            Noded0* temp = minValueNoded0(root->right);  
  
            root->reg = temp->reg;
            (root->n)--;  
  
            root->right = deleteNoded0(root->right,  
                                     temp->reg,ti);  
        }  
    }  
  
    if (root == NULL)  
    return root;  
  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    int balance = getBalanced0(root);  
  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalanced0(root->left) >= 0)  
        return rightRotated0(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalanced0(root->left) < 0)  
    {  
        root->left = leftRotated0(root->left);  
        return rightRotated0(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalanced0(root->right) <= 0)  
        return leftRotated0(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalanced0(root->right) > 0)  
    {  
        root->right = rightRotated0(root->right);  
        return leftRotated0(root);  
    }  
  
    return root;  
}  
  
Noded1* deleteNoded1(Noded1* root, float xi,float ti)  
{  
    if (root == NULL)  
        return root;  
  
    //Check in left subtree  
    if ( xi < (root->x)-(root->t)+curr )
    {  
     (root->n)--;
     root->left = deleteNoded1(root->left, xi,ti);  
  	}
    //Check in right subtree  
    else if( xi > (root->x)-(root->t)+curr )  
    {
    (root->n)--;
    root->right = deleteNoded1(root->right, xi,ti);  
  	}
    else
    {  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Noded1 *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else   
            *root = *temp;   
            free(temp);  
        }  
        else
        {  
            Noded1* temp = minValueNoded1(root->right);  
  
            root->reg = temp->reg;
            (root->n)--;  
  
            root->right = deleteNoded1(root->right,  
                                     temp->reg,ti);  
        }  
    }  
  
    if (root == NULL)  
    return root;  
  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    int balance = getBalanced1(root);  
  
  
    // Left Left Case  
    if (balance > 1 &&  
        getBalanced1(root->left) >= 0)  
        return rightRotated1(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getBalanced1(root->left) < 0)  
    {  
        root->left = leftRotated1(root->left);  
        return rightRotated1(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getBalanced1(root->right) <= 0)  
        return leftRotated1(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getBalanced1(root->right) > 0)  
    {  
        root->right = rightRotated1(root->right);  
        return leftRotated1(root);  
    }  
  
    return root;  
}

float Search(Node *root, int regi)
{
	Node *temp = new Node;
	temp = root;
	while(temp != NULL)
	{
		if(temp->reg == regi)
		{
			if(temp->d==0)
			{return (temp->x)-curr+(temp->t);}
			if(temp->d==1)
			{return (temp->x)+curr-(temp->t);}
			
			
		}
		else if(temp->reg > regi)
			temp = temp->left;
		else
			temp = temp->right;
	}
 
	return -1.0;
}
 
Noded0* Searchd0(Noded0 *rooti, float xi)
{
	Noded0 *temp = new Noded0;
	Noded0 *t2 = new Noded0;
	temp = rooti;
	while(temp != NULL)
	{
		t2=temp;
		if((temp->x)+(temp->t)-curr == xi)
		{
			return temp;
		}
		else if((temp->x)+(temp->t)-curr > xi)
			temp = temp->left;
		else
			temp = temp->right;
	}
 
	return t2;
}

Noded1* Searchd1(Noded1 *rooti, float xi)
{
	Noded1 *temp = new Noded1;
	Noded1 *t2 = new Noded1;
	temp = rooti;
	while(temp != NULL)
	{
		t2=temp;
		if((temp->x)-(temp->t)+curr == xi)
		{
			return temp;
		}
		else if((temp->x)-(temp->t)+curr > xi)
			temp = temp->left;
		else
			temp = temp->right;
	}
 
	return t2;
} 
 
int find_immediate_left(Noded0* xr0,Noded1* xr1,float xr,int reg)
	{
	float p1=xr,p2;
	int d,r,f=0;
  if (xr0->reg==reg){d=0;if(xr0->left!=NULL){p1=(xr0->left->x)+(xr0->left->t)-curr;}else{p1=xr;}}	
	if (xr1->reg==reg){d=1;if(xr1->left!=NULL){p1=(xr1->left->x)-(xr1->left->t)+curr;}else{p1=xr;}}

  if(d==0)
	{
	Noded1* temp=new Noded1();
	Noded1* temp2=new Noded1();
	temp=rootd1;
	temp2=rootd1;
	
	if((temp->x)-(temp->t)+curr>xr){temp=temp->left;}
	else{temp=temp->right;}
	
	while(temp!=NULL)
	{
	
	if((temp2->x)-(temp2->t)+curr<xr && (temp->x)-(temp->t)+curr>xr)
	{p2=(temp2->x)-(temp2->t)+curr;break;}
	if((temp2->x)-(temp2->t)+curr>xr && (temp->x)-(temp->t)+curr<xr)
	{p2=(temp->x)-(temp->t)+curr;f=1;break;}
	temp2=temp;
	if((temp->x)-(temp->t)+curr>xr){temp=temp->left;}
	else{temp=temp->right;}
	
	}
	if(f==0)
	{p2=(temp2->x)-(temp2->t)+curr;
	r=temp2->reg;}
	else{p2=(temp->x)-(temp->t)+curr;
	r=temp->reg;
	}	
	}
			
	if(d==1)
	{
	Noded0* temp=rootd0;
	Noded0* temp2=rootd0;
	
	if((temp->x)-(temp->t)+curr>xr){temp=temp->left;}
	else{temp=temp->right;}
	while(temp!=NULL)
	{

	if((temp2->x)-(temp2->t)+curr<xr && (temp->x)-(temp->t)+curr>xr)
	{p2=(temp2->x)-(temp2->t)+curr;break;}

	if((temp2->x)-(temp2->t)+curr>xr && (temp->x)-(temp->t)+curr<xr)
	{p2=(temp->x)-(temp->t)+curr;f=1;break;}
	temp2=temp;
	if((temp->x)-(temp->t)+curr>xr){temp=temp->left;}
	else{temp=temp->right;}
	
	}
	if(f==0)
	{p2=(temp2->x)-(temp2->t)+curr;
	r=temp2->reg;}
	else{p2=(temp->x)-(temp->t)+curr;
	r=temp->reg;}	
	}
	if(p2>xr && p1==xr){return -1;}
	if(p2>xr && p1<xr){if(d==0){return xr0->left->reg;}else{return xr1->left->reg;}}
	if(p2<xr && p1==xr){return r;}
	if(p2<xr && p1<xr){if(p1>p2){if(d==0){return xr0->left->reg;}else{return xr1->left->reg;}}else{return r;}}	

	return 0;}


int find_immediate_right(Noded0* xr0,Noded1* xr1,float xr,int reg)
	{
	float p1=xr,p2;
	int d,r,f=0;
	if (xr0->reg==reg){d=0;if(xr0->right!=NULL){p1=(xr0->right->x)+(xr0->right->t)-curr;}else{p1=xr;}}
	
	if (xr1->reg==reg){d=1;if(xr1->right!=NULL){p1=(xr1->right->x)-(xr1->right->t)+curr;}else{p1=xr;}}
	if(d==0)
	{
	Noded1* temp=new Noded1();
	Noded1* temp2=new Noded1();
	temp=rootd1;
	temp2=rootd1;
	
	if((temp->x)-(temp->t)+curr>xr){temp=temp->left;}
	else{temp=temp->right;}
	
	while(temp!=NULL)
	{
	
	if((temp2->x)-(temp2->t)+curr<xr && (temp->x)-(temp->t)+curr>xr)
	{p2=(temp->x)-(temp->t)+curr;break;}
	if((temp2->x)-(temp2->t)+curr>xr && (temp->x)-(temp->t)+curr<xr)
	{p2=(temp2->x)-(temp2->t)+curr;f=1;break;}
	temp2=temp;
	if((temp->x)-(temp->t)+curr>xr){temp=temp->left;}
	else{temp=temp->right;}
	
	}
	if(f==1)
	{p2=(temp2->x)-(temp2->t)+curr;
	r=temp2->reg;}
	else{p2=(temp->x)-(temp->t)+curr;
	r=temp->reg;
	}	
	}
			
	if(d==1)
	{
	Noded0* temp=rootd0;
	Noded0* temp2=rootd0;
	
	if((temp->x)-(temp->t)+curr>xr){temp=temp->left;}
	else{temp=temp->right;}
	while(temp!=NULL)
	{

	if((temp2->x)-(temp2->t)+curr<xr && (temp->x)-(temp->t)+curr>xr)
	{p2=(temp->x)-(temp->t)+curr;break;}

	if((temp2->x)-(temp2->t)+curr>xr && (temp->x)-(temp->t)+curr<xr)
	{p2=(temp2->x)-(temp2->t)+curr;f=1;break;}
	temp2=temp;
	if((temp->x)-(temp->t)+curr>xr){temp=temp->left;}
	else{temp=temp->right;}
	
	}
	if(f==1)
	{p2=(temp2->x)-(temp2->t)+curr;
	r=temp2->reg;}
	else{p2=(temp->x)-(temp->t)+curr;
	r=temp->reg;}	
	}
	if(p2<xr && p1==xr){return -1;}
	if(p2<xr && p1>xr){if(d==0){return xr0->right->reg;}else{return xr1->right->reg;}}
	if(p2>xr && p1==xr){return r;}
	if(p2>xr && p1>xr){if(p1>p2){if(d==0){return xr0->right->reg;}else{return xr1->right->reg;}}else{return r;}}	
	return 0;
	}

int main()  
{  

    Noded0 *xreg0;
    Noded1 *xreg1;
    int xregil,xregir;
    int rils=10;  
    float xreg;
    int regid,did;
    float xind,tind;
      
 	int n,i,o;
	cin>>n;
	
	for(i=0;i<n;i++)
	{
	cin>>o;
	
	if(o==1)
	{
	cin>>regid>>xind>>tind>>did;
	float s=Search(root,regid);
	if(s!=-1.0){continue;}
	root = insert(root, regid,xind,tind,did);
    if(did==0){rootd0=insertd0(rootd0,regid,xind,tind,did);}
    if(did==1){rootd1=insertd1(rootd1,regid,xind,tind,did);}
    curr=tind;	
	}
	if(o==2)
	{
	cin>>regid>>tind;
	float s=Search(root,regid);
	if(s==-1.0){continue;}
	root = deleteNode(root,regid,tind);	
	Noded0* temp=Searchd0(rootd0,s);
	if(temp->reg==regid){deleteNoded0(rootd0,regid,tind);curr=tind;continue;}
	Noded1* temp2=Searchd1(rootd1,s);
	if(temp2->reg==regid){deleteNoded1(rootd1,regid,tind);curr=tind;continue;}		
	}
	if(o==3)
	{
	cin>>regid>>tind;
	
	xreg=Search(root,regid);
    xreg0=Searchd0(rootd0,xreg);
    xreg1=Searchd1(rootd1,xreg);    
    xregil=find_immediate_left(xreg0,xreg1,xreg,regid);
    cout<<xregil<<endl;
    }
	if(o==4)
	{
	cin>>regid>>tind;

	xreg=Search(root,regid);
    xreg0=Searchd0(rootd0,xreg);
    xreg1=Searchd1(rootd1,xreg);    
    xregil=find_immediate_right(xreg0,xreg1,xreg,regid);
    cout<<xregil<<endl;
    
    }
    if(o==5)
    {
    cin>>regid>>tind;
	xreg=Search(root,regid);
    xreg0=Searchd0(rootd0,xreg);
    xreg1=Searchd1(rootd1,xreg);
    int c1;
	if(xreg0->x==rootd0->x){if(rootd0->left!=0){c1=(rootd0->left->n)+1;}else{c1=0;}}
    if(xreg0->x>rootd0->x){c1=rootd0->n-xreg0->n;}
    
    if(xreg0->x<rootd0->x)
    {c1=xreg0->n;
    if(xreg0->right!=NULL){c1=c1-xreg0->right->n-1;}}
    int c2;
	if(xreg1->x==rootd1->x){if(rootd1->left!=0){c2=(rootd1->left->n)+1;}else{c2=0;}}

    if(xreg1->x>rootd1->x){c2=rootd1->n-xreg1->n;}
	if(xreg1->x<rootd1->x)
	{c2=xreg1->n;
    if(xreg1->right!=NULL){c2=c2-xreg1->right->n-1;}}
	
	    
    int count=c1+c2;
    cout<<count<<endl;
    }
	if(o==6)
    {
    cin>>regid>>tind;
	xreg=Search(root,regid);
    xreg0=Searchd0(rootd0,xreg);
    xreg1=Searchd1(rootd1,xreg);    

    int c1;
    if(xreg0->x==rootd0->x){if(rootd0->right!=0){c1=(rootd0->right->n)+1;}else{c1=0;}}
    if(xreg0->x<rootd0->x){c1=rootd0->n-xreg0->n;}
    
    if(xreg0->x>rootd0->x)
    {c1=xreg0->n;
    if(xreg0->left!=NULL){c1=c1-xreg0->left->n-1;}}
    int c2;
    
    if(xreg1->x==rootd1->x){if(rootd1->right!=0){c2=(rootd1->right->n)+1;}else{c2=0;}}    
    if(xreg1->x<rootd1->x){c2=rootd1->n-xreg1->n;}
	if(xreg1->x>rootd1->x)
	{c2=xreg1->n;
    if(xreg1->left!=NULL){c2=c2-xreg1->left->n-1;}}

    int count=c1+c2;    
    cout<<count<<endl;
    }	
	}      
    return 0;  
}  
