#include<iostream>
#include<string.h>
using namespace std;

//trie node
struct TNode
{
	struct TNode *children[2];
    // nweh represents no. of words ending at that node
	int nweh;
};
//Return new node 
struct TNode *getNode(void)
{
	struct TNode *nnode=new TNode;
	nnode->nweh=0;  
	nnode->children[0]=NULL;
	nnode->children[1]=NULL;

	return nnode;
}
// If not present, inserts key into trie of root
void insert(struct TNode *root, string key,int l)
{
	struct TNode *temp=root;
	for(int i=0;i<l;i++)
	{
		int index=key[i]-'0';
	if(!temp->children[index]){temp->children[index]=getNode();}
		temp=temp->children[index];
	}
    // increment no. of inserted strings
	temp->nweh++;
}
// Returns no. of occurences of string in trie
int search(struct TNode *root, string key,int l)
{
	
	struct TNode *temp = root;
	if (temp==NULL){return 0;}
	for (int i=0;i<l;i++)
	{
		int index=key[i]-'0';
		if (temp==NULL){return 0;}
	
		if(!temp->children[index])
			return 0;
		temp=temp->children[index];
	}
	return temp->nweh;
}
TNode* remove(TNode* root,string key,int l,int depth=0) 
{
    // If trie is empty
	if (!root){return NULL;}
    // If last character of key is being processed 
	if (depth==l){
        // Decrement no. of strings ending here 
		if (root->nweh>0){root->nweh--;//cout<<"Subt"<<endl;
		}
		//If no children left and node itself isn't end of any string, delete it
		if(root->children[0]==NULL && root->children[1]==NULL && root->nweh==0){//delete (root);
		root=NULL;}
				
		return root;
    }
    // If not last character, recur for next character 
	int index=key[depth]-'0';
	root->children[index]=remove(root->children[index],key,l,depth+1);
	if(root->children[0]==NULL && root->children[1]==NULL && root->nweh==0){//delete (root);
	root=NULL;}
	return root;
}


//find no of strings in subtree of root
int addallend(struct TNode *root)
	{
	if(root->children[0]==NULL && root->children[1]==NULL){return root->nweh;}
	int cl=0,cr=0;
	if(root->children[0]!=NULL){cl=addallend(root->children[0]);}
	if(root->children[1]!=NULL){cr=addallend(root->children[1]);}
	return cl+cr;
	
	}

int searchpat2(string key,int l,struct TNode *root)
	{
	int i,j;
	int count=0;
	int k=key.length();
	int index=key[k-l]-'0';
	if (root==NULL){return 0;}
	if(l==0){return addallend(root)*k;}
	if(index==0){
	
	if(root->children[1]!=NULL){count=count+(addallend(root->children[1])*(k-l));}
	if(root->children[0]!=NULL){count+=searchpat2(key,l-1,root->children[0]);}
	return count;
	}

	if(index==1){
	
	if(root->children[0]!=NULL){count=count+(addallend(root->children[0])*(k-l));}
	if(root->children[1]!=NULL){count+=searchpat2(key,l-1,root->children[1]);}
	return count;
	}

	if(index!=0 && index!=1){
	if(root->children[0]!=NULL){count=count+searchpat2(key,l-1,root->children[0]);}
	if(root->children[1]!=NULL){count=count+searchpat2(key,l-1,root->children[1]);}
	
	//+searchpat2(key,l-1,root->children[1]);
	return count;
	}
	
	}



int searchpat(string key,int l,struct TNode **root)
	{
	int k,count,f=0;
	count=0;
	for(k=l-1;k<32;k++)
	{
	struct TNode *temp = root[k];
	if(temp==NULL){continue;}
//	cout<<k<<endl;
	
	for(int i=0;i<l;i++)
	{
		int index=key[i]-'0';
//		if (temp==NULL){return 0;}
//		cout<<"Index="<<index<<endl;
		if(!temp->children[index]){f=1;break;}
		temp=temp->children[index];
	}
	if(f==0){//cout<<"Adding"<<endl;
	count+=addallend(temp);
//	cout<<count<<endl;
	}
	f=0;
	}
	
	return count;
	}


//Add to all tries

void sliceandadd(string key,struct TNode **root)
	{
	int i,j;
    for(i=0;i<32;i++)
    {
    string stemp;
    for(j=(32-i-1);j<32;j++){stemp=stemp+key[j];}
//    cout<<"Inserting ";
//    for(int k=0;k<=i;k++){cout<<stemp[k];}
//    cout<<endl;

    insert(root[i],stemp,i+1);
    }
	}

//Remove from all tries

void sliceandremove(string key,struct TNode **root)
	{
	int i,j;
	for(i=0;i<32;i++)
    {
    string stemp;
    for(j=32-i-1;j<32;j++){stemp=stemp+key[j];}
//    cout<<"Removing =";
//    for(int k=0;k<=i;k++){cout<<stemp[k];}
 //   cout<<endl;
    remove(root[i],stemp,i+1);
//    cout<<"Inserted "<<i<<endl;
    }
	}

int main()
	{

	int Q,qc;
	cin>>Q;
	
	
    struct TNode *root[32];
    int i,j;
    for(i=0;i<32;i++)
    {
    root[i] = getNode(); 
    }
	for(qc=0;qc<Q;qc++)
	{
	int perf;
    cin>>perf;
    if(perf==1)
    {
    string s;
    cin>>s;
    int dec=search(root[31],s,s.length());
    if(dec==0){sliceandadd(s,root);}
    }
    

    if(perf==2)
    {
    string s;
    cin>>s;
    int dec=search(root[31],s,s.length());
    if(dec==1){sliceandremove(s,root);}
    }

    if(perf==3)
    {
    string s;
    cin>>s;
    cout<<searchpat(s,s.length(),root)<<endl;
    }
    
    if(perf==4)
    {
    string s;
    cin>>s;
    cout<<searchpat2(s,s.length(),root[31])<<endl;
    }
    }

    return 0; 
	}
