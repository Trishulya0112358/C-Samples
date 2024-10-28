#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

using namespace std;

struct ListNode
{
	int dest;
	double cost;
	int col;
	struct ListNode* next;
};

struct MinheapNode
{
int v;
int parent;
double dist;
int count;

};
 

void insertmh(struct MinheapNode **A,int v,int u,double dist,int counter,int index)
{
MinheapNode *temp=(MinheapNode*)malloc(sizeof(MinheapNode));
temp->v=v;
temp->parent=u;
temp->dist=dist;
temp->count=counter;

//cout<<"Index="<<index;

A[index]=temp;

while(index!=0 && A[(index-1)/2]->dist>A[index]->dist)
{
MinheapNode *swap=A[index];
A[index]=A[(index-1)/2];
A[(index-1)/2]=swap;
index=(index-1)/2;
}
}


void MinHeapify(struct MinheapNode **A,int ind,int length)
{
int temp=ind;
if(2*ind+1<length && A[2*ind+1]->dist<A[ind]->dist){temp=2*ind+1;}
if(2*ind+2<length && A[2*ind+2]->dist<A[temp]->dist){temp=2*ind+2;}

if(temp!=ind){struct MinheapNode* tp=A[ind];A[ind]=A[temp];A[temp]=tp;MinHeapify(A,temp,length);}

}

struct MinheapNode* extractMin(struct MinheapNode **Arr,int length)
{
struct MinheapNode *minval=Arr[0];
int i=0;
if(length==0){return minval;}
//cout<<"In Extract Min"<<endl;
Arr[0]=Arr[length];
//struct MinheapNode *temp=NULL;

MinHeapify(Arr,0,length);

return minval;
}

void dijkstra(int src,int V,struct ListNode **AList,int k,double g)
{
double dist[V][k+1];
int VK[V][k+1];

for(int i=0;i<V;i++)
{
for(int j=0;j<=k;j++)
{
VK[i][j]=0;
dist[i][j]=INT_MAX;
}
}

for(int i=0;i<=k;i++)
{
VK[src][i]=1;
dist[src][i]=0;
}
int curr=0;
int max=V*k;
struct MinheapNode *Arr[V*k];
	
	for(int i=0;i<V*k;i++)
	{
	Arr[i]=NULL;
	}
	
	struct ListNode *temp=AList[src];
//	int counter=0;
	while(temp!=NULL)
	{
	int v=temp->dest;
//	if((temp->cost<dist[v]) || VK[v][counter]==0)
//	{
	insertmh(Arr,v,src,temp->cost,temp->col,curr);
//	cout<<endl<<"Inserting:"<<v<<endl;

	VK[v][temp->col]=1;
	dist[v][temp->col]=temp->cost;
	
	curr++;
	temp=temp->next;
//	}
	}
//	cout<<"Source inserted"<<endl<<endl;
//		cout<<endl<<"Heap"<<endl;

/*	for(int i=0;i<curr;i++)
	{
	cout<<Arr[i]->v+1<<" ";
	}
	cout<<endl;
	cout<<endl<<VK[0][0]<<" "<<VK[0][1]<<endl<<endl;
*/
	while(curr>0)
	{
    struct MinheapNode* minHNode=NULL;
	if(curr==1){curr--;minHNode=Arr[curr];//cout<<"Last:"<<minHNode->v<<endl;
}
	
	else
	{
	//cout<<"Extracting"<<endl;
	minHNode = extractMin(Arr,curr-1);
	curr--;
//	cout<<"Extracted:";
/*		cout<<endl<<"Heap"<<endl;

	for(int i=0;i<curr;i++)
	{
	cout<<Arr[i]->v+1<<" ";
	}
	cout<<endl;

*/	}
//    struct MinheapNode *minHNode=Arr[0];
    int u = minHNode->v;
    //cout<<u<<endl;
    int kup = minHNode->count;
	VK[u][kup]=1;
	if(dist[u][kup]>minHNode->dist)
	{dist[u][kup]=minHNode->dist;}
	struct ListNode *temp=AList[u];
	while(temp!=NULL)
	{
	//cout<<"Here2";
	int v=temp->dest;
//	cout<<"Temp of "<<u;
//	cout<<"In ADJ "<<v<<endl;
	if(kup+temp->col<=k && VK[v][kup+temp->col]==0 && temp->cost+dist[u][kup]<dist[v][kup+temp->col])
	{
//	dist[v][kup+temp->col]=dist[u][kup]+temp->cost;
//	VK[v][kup+temp->col]=1;
	insertmh(Arr,v,u,dist[u][kup]+temp->cost,kup+temp->col,curr);
/*		cout<<endl<<"Heapins"<<endl;

	for(int i=0;i<curr;i++)
	{
	cout<<Arr[i]->v+1<<" ";
	}
	cout<<endl;

	cout<<endl<<"Insertingv:"<<v<<"  Pathcount:"<<kup+temp->col<<endl;
*/	curr++;
/*	cout<<endl<<"Heap"<<endl;
	for(int i=0;i<curr;i++)
	{
	cout<<Arr[i]->v+1<<" ";
	}
	cout<<endl;

	cout<<"Current:"<<curr<<endl;
*/	}
	temp=temp->next;
	//cout<<"Here1";
//	}
	}
	}
  /*  cout<<endl;
    cout<<"Printing1"<<endl;
    for(int i=0;i<V;i++)
    {
    for(int j=0;j<=k;j++)
    {
    cout<<dist[i][j]<<" ";
    }
    cout<<endl;
    }
    cout<<endl;
    cout<<"Printing2"<<endl;
    
    for(int i=0;i<V;i++)
    {
    for(int j=0;j<=k;j++)
    {
    cout<<VK[i][j]<<" ";
    }
    cout<<endl;
    }
    int f=0;
    cout<<endl<<"Final Check"<<endl;

   */
	int f=0;
	for(int i=0;i<=k;i++)
    {
    if(VK[V-1][i]!=0 && dist[V-1][i]<g){f=1;//cout<<"i="<<i<<" "<<VK[V-1][i]<<"  "<<dist[V-1][i]<<endl;
}
    }
  //  cout<<"g="<<g;
//	cout<<dist[marker][0]<<"  "<<dist[marker][1]<<endl;
    if(f==0){cout<<"No"<<endl;}
	else{cout<<"Yes"<<endl;}
}




int main()
	{
	int k;
	double g;
	int N,i,M;
	cin>>g;
	cin>>k;
	cin>>N>>M;

  cout<<"Solution by Jigar"<<endl;
    
	//struct AdjList *A*list=(struct AdjList *)malloc(N*sizeof(struct AdjList));
	struct ListNode **Alist=(struct ListNode **)malloc(N*sizeof(struct ListNode*));
	
	for(i=0;i<N;i++)
	{
	
	Alist[i]=NULL;	
	}

	for(i=0;i<M;i++)
	{
	int n1,n2,c;
	double p;
	cin>>n1>>n2>>p>>c;
	n1=n1-1;
	n2=n2-1;
	struct ListNode *newNode=(struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *newNode2=(struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->dest=n2;
	newNode->cost=-(log10(1-p));
	newNode->col=c;

	newNode2->dest=n1;
	newNode2->cost=-(log10(1-p));
	newNode2->col=c;

	if(Alist[n1]==NULL){Alist[n1]=newNode;newNode->next=NULL;}
	else{newNode->next=Alist[n1]->next;Alist[n1]->next=newNode;}
	
	if(Alist[n2]==NULL){Alist[n2]=newNode2;newNode2->next=NULL;}
	else{newNode2->next=Alist[n2]->next;Alist[n2]->next=newNode2;}
	
	}
	
	dijkstra(0,N,Alist,k,g);
	}
