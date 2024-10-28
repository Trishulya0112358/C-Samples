// Solution by Jigar
#include<iostream>
#include<typeinfo>
using namespace std;

float curr=0;

class nodereg{
	public:
	int reg,h;
	float x,v,t;
	nodereg *left;
	nodereg *right;
	nodereg *parent;
	};
class nodepos{
	public:
	int reg,h,ind;
	float p,v,t;
	nodepos *left;
	nodepos *right;
	nodepos *parent;
	};

int indins=0;

float A[10000];
int ar1[10000];
int ar2[10000];
float ax1[10000];
float ax2[10000];
float av1[10000];
float av2[10000];
float at1[10000];
float at2[10000];
float ap1[10000];
float ap2[10000];

nodereg *rootreg=NULL;
nodepos *rootpos=NULL;

int insertpos(int regi,float xi,float ti,float vi)
	{
	nodepos *t=rootpos;

	if(t==NULL)
	{
	t= new nodepos();
	t->reg=regi;
	t->t=ti;
	t->v=vi;
	t->p=xi;
	t->h=1;t->left=NULL;t->right=NULL;t->parent=NULL;
	rootpos=t;
	return 1;
	}
	
	nodepos *t2=NULL;
	while(t!=NULL)
	{
	if(t->p+(t->v)*(curr-t->t)<xi){t2=t;t=t->right;continue;}
	if(t->p+(t->v)*(curr-t->t)>xi){t2=t;t=t->left;continue;}
	if(t->p==xi)
		{
		if(t->v<vi){t2=t;t=t->right;continue;}
		if(t->v>vi){t2=t;t=t->left;continue;}
		}
	}
	
	t= new nodepos();
	t->reg=regi;
	t->t=ti;
	t->v=vi;
	t->p=xi;
	t->h=1;t->left=NULL;t->right=NULL;t->parent=t2;
	if(t->p+(t->v)*(curr-t->t)>xi){t2->left=t;}
	if(t->p+(t->v)*(curr-t->t)<xi){t2->right=t;}
	
	int hl=0,hr=0,h=0;
	if(t2->left!=NULL){hl=t2->left->h;}
	if(t2->right!=NULL){hr=t2->right->h;}

	hl>hr?h=hl:h=hr;
	t2->h=h+1;
	t2=t2->parent;
	while(t2!=NULL)
	{
		
	hl=0;hr=0;h=0;
	if(t2->left!=NULL){hl=t2->left->h;}
	if(t2->right!=NULL){hr=t2->right->h;}
	
	if(hr-hl>1)
	{
	nodepos *z=t2;
	nodepos *y=t2->right;
	
	if(t->p<y->p)
	{
	//rl
	nodepos *x=y->left;
	nodepos *temp1=x->right;
	nodepos *temp2=x->left;	
	nodepos *temp3=z->parent;
	
	y->left=temp1;
	if(temp1!=NULL){temp1->parent=y;}
	z->right=temp2;
	if(temp2!=NULL){temp2->parent=z;}
	x->left=z;
	z->parent=x;
	x->right=y;
	y->parent=x;
	x->parent=temp3;
	
	if(temp3!=NULL)
	{
	if(x->p+(x->v)*(curr-x->t)<temp3->p+(temp3->v)*(curr-temp3->t)){temp3->left=x;}
	else{temp3->right=x;}
	}
	
	hl=0;hr=0;h=0;
	if(x->left!=NULL){hl=x->left->h;}
	if(x->right!=NULL){hr=x->right->h;}
	
	hl>hr?h=hl:h=hr;
	x->h=h+1;
	
	hl=0;hr=0;h=0;
	if(y->left!=NULL){hl=y->left->h;}
	if(y->right!=NULL){hr=y->right->h;}
	
	hl>hr?h=hl:h=hr;
	y->h=h+1;
	
	hl=0;hr=0;h=0;
	if(z->left!=NULL){hl=z->left->h;}
	if(z->right!=NULL){hr=z->right->h;}
	
	hl>hr?h=hl:h=hr;
	z->h=h+1;
	
	if(rootpos==z){rootpos=x;}
	if(rootpos->left==NULL && rootpos->right==NULL){break;}
	nodepos *cp1,*cp2;
	
	float c1p,c1v,c1t,c2p,c2v,c2t;
	int c1r,c2r;
	
	if(t->right!=NULL)
	{
	cp1=t->right;
	while (cp1->left!=NULL){cp1=cp1->left;}
	c1p=cp1->p+(cp1->v)*(curr-cp1->t);
	c1v=cp1->v;
	c1t=cp1->t;
	c1r=cp1->reg;
	}
	
	else
	{
	cp1=t->parent;
	nodepos *cp11=t;
	while (cp1!=NULL && cp11==cp1->right)
	{
	cp11=cp1;
	cp1=cp1->parent;	
	}
	c1r=cp11->reg;
	c1p=cp11->p+(cp11->v)*(curr-cp11->t);
	c1t=cp11->t;
	c1v=cp11->v;
	}
	
	if(t->left!=NULL)
	{
	cp2=t->left;
	while (cp2->right!=NULL){cp2=cp2->right;}
	c2p=cp2->p+(cp2->v)*(curr-cp2->t);
	c2v=cp2->v;
	c2t=cp2->t;
	c2r=cp2->reg;
	}
	
	else
	{
	cp2=t->parent;
	nodepos *cp22=t;
	while (cp2!=NULL && cp22==cp2->left)
	{
	cp22=cp2;
	cp2=cp2->parent;	
	}
	c2r=cp22->reg;
	c2p=cp22->p+(cp22->v)*(curr-cp22->t);
	c2t=cp22->t;
	c2v=cp22->v;
	}

	if(c2v!=c1v)
	{
	float insheap=(c2p-c1p)/(c2v-c1v+0.00001);
	if(insheap<0){insheap=insheap*(-1);}
	
	A[indins]=insheap;//cout<<"inserted"<<"  "<<indins<<endl;
	ar1[indins]=c1r;
	av1[indins]=c1v;
	at1[indins]=c1t;
	ap1[indins]=c1p;
	ar2[indins]=c2r;
	av2[indins]=c2v;
	at2[indins]=c2t;
	ap2[indins]=c2p;

	int i=indins;
	indins++;
	while(i!=0 && A[(i-1)/2]>A[i])
	{
	float temp;
	int tempr;
	temp=A[i];
	A[i]=A[(i-1)/2];
	A[(i-1)/2]=temp;

	tempr=ar1[i];
	ar1[i]=ar1[(i-1)/2];
	ar1[(i-1)/2]=tempr;
	temp=av1[i];
	av1[i]=av1[(i-1)/2];
	av1[(i-1)/2]=temp;
	temp=at1[i];
	at1[i]=at1[(i-1)/2];
	at1[(i-1)/2]=temp;
	temp=ap1[i];
	ap1[i]=ap1[(i-1)/2];
	ap1[(i-1)/2]=temp;

	tempr=ar2[i];
	ar2[i]=ar2[(i-1)/2];
	ar2[(i-1)/2]=tempr;
	temp=av2[i];
	av2[i]=av2[(i-1)/2];
	av2[(i-1)/2]=temp;
	temp=at2[i];
	at2[i]=at2[(i-1)/2];
	at2[(i-1)/2]=temp;
	temp=ap2[i];
	ap2[i]=ap2[(i-1)/2];
	ap2[(i-1)/2]=temp;

	i=(i-1)/2;
	}
	}
	break;
	}
	
	if(t->p+(t->v)*(curr-t->t)>y->p+(y->v)*(curr-y->t))
	{
	
	nodepos *x=y->right;
	nodepos *temp1=y->left;
	nodepos *temp2=z->parent;
	
	y->left=z;
	z->parent=y;
	z->right=temp1;
	if(temp1!=NULL){temp1->parent=z;}
	y->parent=temp2;
	if(temp2!=NULL)
	{
	if(y->p+(y->v)*(curr-y->t)<temp2->p+(temp2->v)*(curr-temp2->t)){temp2->left=y;}
	else{temp2->right=y;}
	}
	
	hl=0;hr=0;h=0;
	if(x->left!=NULL){hl=x->left->h;}
	if(x->right!=NULL){hr=x->right->h;}
	
	hl>hr?h=hl:h=hr;
	x->h=h+1;
	
	hl=0;hr=0;h=0;
	if(y->left!=NULL){hl=y->left->h;}
	if(y->right!=NULL){hr=y->right->h;}
	
	hl>hr?h=hl:h=hr;
	y->h=h+1;
	
	hl=0;hr=0;h=0;
	if(z->left!=NULL){hl=z->left->h;}
	if(z->right!=NULL){hr=z->right->h;}	
	hl>hr?h=hl:h=hr;
	z->h=h+1;	
	if(rootpos==z){rootpos=y;}
	
	if(rootpos->left==NULL && rootpos->right==NULL){break;}	
	
	nodepos *cp1,*cp2;
	
	float c1p,c1v,c1t,c2p,c2v,c2t;
	int c1r,c2r;
	if(t->right!=NULL)
	{
	cp1=t->right;
	while (cp1->left!=NULL){cp1=cp1->left;}
	c1p=cp1->p+(cp1->v)*(curr-cp1->t);
	c1v=cp1->v;
	c1t=cp1->t;
	c1r=cp1->reg;
	}
	
	else
	{
	cp1=t->parent;
	nodepos *cp11=t;
	while (cp1!=NULL && cp11==cp1->right)
	{
	cp11=cp1;
	cp1=cp1->parent;	
	}
	c1r=cp11->reg;
	c1p=cp11->p+(cp11->v)*(curr-cp11->t);
	c1t=cp11->t;
	c1v=cp11->v;
	}
	
	if(t->left!=NULL)
	{
	cp2=t->left;
	while (cp2->right!=NULL){cp2=cp2->right;}
	c2p=cp2->p+(cp2->v)*(curr-cp2->t);
	c2v=cp2->v;
	c2t=cp2->t;
	c2r=cp2->reg;
	}
	
	else
	{
	cp2=t->parent;
	nodepos *cp22=t;
	while (cp2!=NULL && cp22==cp2->left)
	{
	cp22=cp2;
	cp2=cp2->parent;	
	}
	c2r=cp22->reg;
	c2p=cp22->p+(cp22->v)*(curr-cp22->t);
	c2t=cp22->t;
	c2v=cp22->v;
	}
	cout<<endl<<c2v<<"  "<<c1v<<endl;

	if(c2v!=c1v)
	{

	float insheap=(c2p-c1p)/(c2v-c1v+0.0001);
		if(insheap<0){insheap=insheap*(-1);}

	A[indins]=insheap;
	ar1[indins]=c1r;
	av1[indins]=c1v;
	at1[indins]=c1t;
	ap1[indins]=c1p;
	ar2[indins]=c2r;
	av2[indins]=c2v;
	at2[indins]=c2t;
	ap2[indins]=c2p;

	int i=indins;
	indins++;
	while(i!=0 && A[(i-1)/2]>A[i])
	{
	float temp;
	int tempr;
	temp=A[i];
	A[i]=A[(i-1)/2];
	A[(i-1)/2]=temp;

	tempr=ar1[i];
	ar1[i]=ar1[(i-1)/2];
	ar1[(i-1)/2]=tempr;
	temp=av1[i];
	av1[i]=av1[(i-1)/2];
	av1[(i-1)/2]=temp;
	temp=at1[i];
	at1[i]=at1[(i-1)/2];
	at1[(i-1)/2]=temp;
	temp=ap1[i];
	ap1[i]=ap1[(i-1)/2];
	ap1[(i-1)/2]=temp;

	tempr=ar2[i];
	ar2[i]=ar2[(i-1)/2];
	ar2[(i-1)/2]=tempr;
	temp=av2[i];
	av2[i]=av2[(i-1)/2];
	av2[(i-1)/2]=temp;
	temp=at2[i];
	at2[i]=at2[(i-1)/2];
	at2[(i-1)/2]=temp;
	temp=ap2[i];
	ap2[i]=ap2[(i-1)/2];
	ap2[(i-1)/2]=temp;

	i=(i-1)/2;
	}
	}
	break;	
	}	
	}
	
	if(hl-hr>1)
	{

	nodepos *z=t2;
	nodepos *y=t2->left;
	
	if(t->p+(t->v)*(curr-t->t)>y->p+(y->v)*(curr-y->t))
	{
	
	nodepos *x=y->right;
	nodepos *temp1=x->left;
	nodepos *temp2=x->right;
	nodepos *temp3=z->parent;
	y->right=temp1;
	if(temp1!=NULL){temp1->parent=y;}
	z->left=temp2;
	if(temp2!=NULL){temp2->parent=z;}
	x->left=y;
	y->parent=x;
	x->right=z;
	z->parent=x;
	x->parent=temp3;
	
	if(temp3!=NULL){
	if(x->p+(x->v)*(curr-x->t)<temp3->p+(temp3->v)*(curr-temp3->t)){temp3->left=x;
	}
	else{temp3->right=x;}
	}

	hl=0;hr=0;h=0;
	if(x->left!=NULL){hl=x->left->h;}
	if(x->right!=NULL){hr=x->right->h;}
	
	hl>hr?h=hl:h=hr;
	x->h=h+1;
	
	hl=0;hr=0;h=0;
	if(y->left!=NULL){hl=y->left->h;}
	if(y->right!=NULL){hr=y->right->h;}
	
	hl>hr?h=hl:h=hr;
	y->h=h+1;
	
	hl=0;hr=0;h=0;
	if(z->left!=NULL){hl=z->left->h;}
	if(z->right!=NULL){hr=z->right->h;}
	
	hl>hr?h=hl:h=hr;
	z->h=h+1;
	

	if(rootpos==z){rootpos=x;}
	if(rootpos->left==NULL && rootpos->right==NULL){break;}
	
	nodepos *cp1,*cp2;
	
	float c1p,c1v,c1t,c2p,c2v,c2t;
	int c1r,c2r;
	if(t->right!=NULL)
	{
	cp1=t->right;
	while (cp1->left!=NULL){cp1=cp1->left;}
	c1p=cp1->p+(cp1->v)*(curr-cp1->t);
	c1v=cp1->v;
	c1t=cp1->t;
	c1r=cp1->reg;
	}
	
	else
	{
	cp1=t->parent;
	nodepos *cp11=t;
	while (cp1!=NULL && cp11==cp1->right)
	{
	cp11=cp1;
	cp1=cp1->parent;	
	}
	c1r=cp11->reg;
	c1p=cp11->p+(cp11->v)*(curr-cp11->t);
	c1t=cp11->t;
	c1v=cp11->v;
	}
	
	if(t->left!=NULL)
	{
	cp2=t->left;
	while (cp2->right!=NULL){cp2=cp2->right;}
	c2p=cp2->p+(cp2->v)*(curr-cp2->t);
	c2v=cp2->v;
	c2t=cp2->t;
	c2r=cp2->reg;
	}
	
	else
	{
	cp2=t->parent;
	nodepos *cp22=t;
	while (cp2!=NULL && cp22==cp2->left)
	{
	cp22=cp2;
	cp2=cp2->parent;	
	}
	c2r=cp22->reg;
	c2p=cp22->p+(cp22->v)*(curr-cp22->t);
	c2t=cp22->t;
	c2v=cp22->v;
	}
	
	if(c2v!=c1v)
	{
	
	float insheap=(c2p-c1p)/(c2v-c1v+0.0001);
		if(insheap<0){insheap=insheap*(-1);}

	A[indins]=insheap;//cout<<"inserted"<<"  "<<indins<<endl;
	ar1[indins]=c1r;
	av1[indins]=c1v;
	at1[indins]=c1t;
	ap1[indins]=c1p;
	ar2[indins]=c2r;
	av2[indins]=c2v;
	at2[indins]=c2t;
	ap2[indins]=c2p;

	int i=indins;
	indins++;//cout<<"here";
	while(i!=0 && A[(i-1)/2]>A[i])
	{
	float temp;
	int tempr;
	temp=A[i];
	A[i]=A[(i-1)/2];
	A[(i-1)/2]=temp;

	tempr=ar1[i];
	ar1[i]=ar1[(i-1)/2];
	ar1[(i-1)/2]=tempr;
	temp=av1[i];
	av1[i]=av1[(i-1)/2];
	av1[(i-1)/2]=temp;
	temp=at1[i];
	at1[i]=at1[(i-1)/2];
	at1[(i-1)/2]=temp;
	temp=ap1[i];
	ap1[i]=ap1[(i-1)/2];
	ap1[(i-1)/2]=temp;

	tempr=ar2[i];
	ar2[i]=ar2[(i-1)/2];
	ar2[(i-1)/2]=tempr;
	temp=av2[i];
	av2[i]=av2[(i-1)/2];
	av2[(i-1)/2]=temp;
	temp=at2[i];
	at2[i]=at2[(i-1)/2];
	at2[(i-1)/2]=temp;
	temp=ap2[i];
	ap2[i]=ap2[(i-1)/2];
	ap2[(i-1)/2]=temp;


	i=(i-1)/2;
	}
	}
	break;
	}
	
	if(t->p+(t->v)*(curr-t->t)<y->p+(y->v)*(curr-y->t))
	{

	nodepos *x=y->left;
	nodepos *temp1=y->right;
	nodepos *temp2=z->parent;
	
	z->left=temp1;
	if(temp1!=NULL){temp1->parent=z;}
	y->right=z;
	z->parent=y;
	
	y->parent=temp2;
	
	if(temp2!=NULL){	
	if(y->p+(y->v)*(curr-y->t)<temp2->p+(temp2->v)*(curr-temp2->t)){temp2->left=y;}
	else{temp2->right=y;}
	}
	
	hl=0;hr=0;h=0;
	if(x->left!=NULL){hl=x->left->h;}
	if(x->right!=NULL){hr=x->right->h;}
	
	hl>hr?h=hl:h=hr;
	x->h=h+1;
	
	hl=0;hr=0;h=0;
	if(y->left!=NULL){hl=y->left->h;}
	if(y->right!=NULL){hr=y->right->h;}
	
	hl>hr?h=hl:h=hr;
	y->h=h+1;
	
	hl=0;hr=0;h=0;
	if(z->left!=NULL){hl=z->left->h;}
	if(z->right!=NULL){hr=z->right->h;}	
	hl>hr?h=hl:h=hr;
	z->h=h+1;	
	if(rootpos==z){rootpos=y;}
	if(rootpos->left==NULL && rootpos->right==NULL){break;}	
	
	nodepos *cp1,*cp2;
	
	float c1p,c1v,c1t,c2p,c2v,c2t;
	int c1r,c2r;
	if(t->right!=NULL)
	{
	cp1=t->right;
	while (cp1->left!=NULL){cp1=cp1->left;}
	c1p=cp1->p+(cp1->v)*(curr-cp1->t);
	c1v=cp1->v;
	c1t=cp1->t;
	c1r=cp1->reg;
	}
	
	else
	{
	cp1=t->parent;
	nodepos *cp11=t;
	while (cp1!=NULL && cp11==cp1->right)
	{
	cp11=cp1;
	cp1=cp1->parent;	
	}
	c1r=cp11->reg;
	c1p=cp11->p+(cp11->v)*(curr-cp11->t);
	c1t=cp11->t;
	c1v=cp11->v;
	}
	
	if(t->left!=NULL)
	{
	cp2=t->left;
	while (cp2->right!=NULL){cp2=cp2->right;}
	c2p=cp2->p+(cp2->v)*(curr-cp2->t);
	c2v=cp2->v;
	c2t=cp2->t;
	c2r=cp2->reg;
	}
	
	else
	{
	cp2=t->parent;
	nodepos *cp22=t;
	while (cp2!=NULL && cp22==cp2->left)
	{
	cp22=cp2;
	cp2=cp2->parent;	
	}
	c2r=cp22->reg;
	c2p=cp22->p+(cp22->v)*(curr-cp22->t);
	c2t=cp22->t;
	c2v=cp22->v;
	}
	if(c2v!=c1v)
	{
	float insheap=(c2p-c1p)/(c2v-c1v+0.0001);
		if(insheap<0){insheap=insheap*(-1);}

	A[indins]=insheap;//cout<<"inserted"<<"  "<<indins<<endl;
	ar1[indins]=c1r;
	av1[indins]=c1v;
	at1[indins]=c1t;
	ap1[indins]=c1p;
	ar2[indins]=c2r;
	av2[indins]=c2v;
	at2[indins]=c2t;
	ap2[indins]=c2p;

	int i=indins;
	indins++;//cout<<"here";
	while(i!=0 && A[(i-1)/2]>A[i])
	{
	float temp;
	int tempr;
	temp=A[i];
	A[i]=A[(i-1)/2];
	A[(i-1)/2]=temp;

	tempr=ar1[i];
	ar1[i]=ar1[(i-1)/2];
	ar1[(i-1)/2]=tempr;
	temp=av1[i];
	av1[i]=av1[(i-1)/2];
	av1[(i-1)/2]=temp;
	temp=at1[i];
	at1[i]=at1[(i-1)/2];
	at1[(i-1)/2]=temp;
	temp=ap1[i];
	ap1[i]=ap1[(i-1)/2];
	ap1[(i-1)/2]=temp;

	tempr=ar2[i];
	ar2[i]=ar2[(i-1)/2];
	ar2[(i-1)/2]=tempr;
	temp=av2[i];
	av2[i]=av2[(i-1)/2];
	av2[(i-1)/2]=temp;
	temp=at2[i];
	at2[i]=at2[(i-1)/2];
	at2[(i-1)/2]=temp;
	temp=ap2[i];
	ap2[i]=ap2[(i-1)/2];
	ap2[(i-1)/2]=temp;

	i=(i-1)/2;
	}
	}
	break;	
	}		
	}
	
	hl>hr?h=hl:h=hr;
	t2->h=h+1;
	t2=t2->parent;
	}	
	return 2;
	}

int insertreg(int regi,float xi,float ti,float vi)
	{
	nodereg *t=rootreg;

	if(t==NULL)
	{
	t= new nodereg();
	t->reg=regi;
	t->t=ti;
	t->v=vi;
	t->x=xi;
	t->h=1;t->left=NULL;t->right=NULL;t->parent=NULL;
	rootreg=t;
	return 1;
	}
	
	nodereg *t2=NULL;
	while(t!=NULL)
	{
	if(t->reg<regi){t2=t;t=t->right;continue;}
	if(t->reg>regi){t2=t;t=t->left;continue;}
	if(t->reg==regi){return -1;}
	}
	
	t= new nodereg();
	t->reg=regi;
	t->t=ti;
	t->v=vi;
	t->x=xi;
	t->h=1;t->left=NULL;t->right=NULL;t->parent=t2;
	if(t2->reg>regi){t2->left=t;}
	if(t2->reg<regi){t2->right=t;}
	
	int hl=0,hr=0,h=0;
	if(t2->left!=NULL){hl=t2->left->h;}
	if(t2->right!=NULL){hr=t2->right->h;}

	hl>hr?h=hl:h=hr;
	t2->h=h+1;
	t2=t2->parent;
	while(t2!=NULL)
	{
		
	hl=0;hr=0;h=0;
	if(t2->left!=NULL){hl=t2->left->h;}
	if(t2->right!=NULL){hr=t2->right->h;}
	
	if(hr-hl>1)
	{
	nodereg *z=t2;
	nodereg *y=t2->right;
	
	if(t->reg<y->reg)
	{
	
	nodereg *x=y->left;
	nodereg *temp1=x->right;
	
	nodereg *temp2=x->left;	
	nodereg *temp3=z->parent;
	
	y->left=temp1;
	if(temp1!=NULL){temp1->parent=y;}
	z->right=temp2;
	if(temp2!=NULL){temp2->parent=z;}
	x->left=z;
	z->parent=x;
	x->right=y;
	y->parent=x;
	x->parent=temp3;
	
	if(temp3!=NULL)
	{
	if(x->reg<temp3->reg){temp3->left=x;}
	else{temp3->right=x;}
	}
	
	hl=0;hr=0;h=0;
	if(x->left!=NULL){hl=x->left->h;}
	if(x->right!=NULL){hr=x->right->h;}
	
	hl>hr?h=hl:h=hr;
	x->h=h+1;
	
	hl=0;hr=0;h=0;
	if(y->left!=NULL){hl=y->left->h;}
	if(y->right!=NULL){hr=y->right->h;}
	
	hl>hr?h=hl:h=hr;
	y->h=h+1;
	
	hl=0;hr=0;h=0;
	if(z->left!=NULL){hl=z->left->h;}
	if(z->right!=NULL){hr=z->right->h;}
	
	hl>hr?h=hl:h=hr;
	z->h=h+1;
	
	if(rootreg==z){rootreg=x;}
	break;
	}
	
	if(t->reg>y->reg)
	{
	nodereg *x=y->right;
	
	nodereg *temp1=y->left;
	nodereg *temp2=z->parent;
	
	y->left=z;
	z->parent=y;
	z->right=temp1;
	if(temp1!=NULL){temp1->parent=z;}
	y->parent=temp2;
	if(temp2!=NULL)
	{
	if(y->reg<temp2->reg){temp2->left=y;}
	else{temp2->right=y;}
	}
	
	hl=0;hr=0;h=0;
	if(x->left!=NULL){hl=x->left->h;}
	if(x->right!=NULL){hr=x->right->h;}
	
	hl>hr?h=hl:h=hr;
	x->h=h+1;
	
	hl=0;hr=0;h=0;
	if(y->left!=NULL){hl=y->left->h;}
	if(y->right!=NULL){hr=y->right->h;}
	
	hl>hr?h=hl:h=hr;
	y->h=h+1;
	
	hl=0;hr=0;h=0;
	if(z->left!=NULL){hl=z->left->h;}
	if(z->right!=NULL){hr=z->right->h;}	
	hl>hr?h=hl:h=hr;
	z->h=h+1;	
	if(rootreg==z){rootreg=y;}
	break;	
	}	
	}

	if(hl-hr>1)
	{
	nodereg *z=t2;
	nodereg *y=t2->left;
	
	if(t->reg>y->reg)
	{
	
	nodereg *x=y->right;
	nodereg *temp1=x->left;
	nodereg *temp2=x->right;
	nodereg *temp3=z->parent;
	y->right=temp1;
	if(temp1!=NULL){temp1->parent=y;}
	z->left=temp2;
	if(temp2!=NULL){temp2->parent=z;}
	x->left=y;
	y->parent=x;
	x->right=z;
	z->parent=x;
	x->parent=temp3;
	
	if(temp3!=NULL){
	if(x->reg<temp3->reg){temp3->left=x;
	}
	else{temp3->right=x;}
	}

	hl=0;hr=0;h=0;
	if(x->left!=NULL){hl=x->left->h;}
	if(x->right!=NULL){hr=x->right->h;}
	
	hl>hr?h=hl:h=hr;
	x->h=h+1;
	
	hl=0;hr=0;h=0;
	if(y->left!=NULL){hl=y->left->h;}
	if(y->right!=NULL){hr=y->right->h;}
	
	hl>hr?h=hl:h=hr;
	y->h=h+1;
	
	hl=0;hr=0;h=0;
	if(z->left!=NULL){hl=z->left->h;}
	if(z->right!=NULL){hr=z->right->h;}
	
	hl>hr?h=hl:h=hr;
	z->h=h+1;
	

	if(rootreg==z){rootreg=x;}
	break;
	}
	
	if(t->reg<y->reg)
	{
	nodereg *x=y->left;
	nodereg *temp1=y->right;
	nodereg *temp2=z->parent;
	
	z->left=temp1;
	if(temp1!=NULL){temp1->parent=z;}
	y->right=z;
	z->parent=y;
	
	y->parent=temp2;
	
	if(temp2!=NULL){	
	if(y->reg<temp2->reg){temp2->left=y;}
	else{temp2->right=y;}
	}
	
	hl=0;hr=0;h=0;
	if(x->left!=NULL){hl=x->left->h;}
	if(x->right!=NULL){hr=x->right->h;}
	
	hl>hr?h=hl:h=hr;
	x->h=h+1;
	
	hl=0;hr=0;h=0;
	if(y->left!=NULL){hl=y->left->h;}
	if(y->right!=NULL){hr=y->right->h;}
	
	hl>hr?h=hl:h=hr;
	y->h=h+1;
	
	hl=0;hr=0;h=0;
	if(z->left!=NULL){hl=z->left->h;}
	if(z->right!=NULL){hr=z->right->h;}	
	hl>hr?h=hl:h=hr;
	z->h=h+1;	
	if(rootreg==z){rootreg=y;}
	break;	
	}		
	}
	
	hl>hr?h=hl:h=hr;
	t2->h=h+1;
	t2=t2->parent;
	}
	return 2;
	}
	
void mhpfy(int i)
	{
	int l=2*i+1; 
    	int r=2*i+2; 
    	int smallest=i; 
    	if (l<indins && A[l]<A[i]){smallest=l;} 
	if (r<indins && A[r]<A[smallest]){smallest=r;} 
	if (smallest!=i) 
    	{ 
        float temp;
	int tempr;
	temp=A[i];
	A[i]=A[(i-1)/2];
	A[(i-1)/2]=temp;

	tempr=ar1[i];
	ar1[i]=ar1[(i-1)/2];
	ar1[(i-1)/2]=tempr;
	temp=av1[i];
	av1[i]=av1[(i-1)/2];
	av1[(i-1)/2]=temp;
	temp=at1[i];
	at1[i]=at1[(i-1)/2];
	at1[(i-1)/2]=temp;
	temp=ap1[i];
	ap1[i]=ap1[(i-1)/2];
	ap1[(i-1)/2]=temp;

	tempr=ar2[i];
	ar2[i]=ar2[(i-1)/2];
	ar2[(i-1)/2]=tempr;
	temp=av2[i];
	av2[i]=av2[(i-1)/2];
	av2[(i-1)/2]=temp;
	temp=at2[i];
	at2[i]=at2[(i-1)/2];
	at2[(i-1)/2]=temp;
	temp=ap2[i];
	ap2[i]=ap2[(i-1)/2];
	ap2[(i-1)/2]=temp;
        mhpfy(smallest); 
    	} 	
	}
	
int main()
	{
	int a,m;	
	int tc;
	cin>>m;
	for(tc=0;tc<m;tc++)
	{
	int cla;
	cin>>cla;
	if (cla==1)
	{
	int r,x,v;
	cin>>r>>x>>v;
	insertreg(r,x,curr,v);
	insertpos(r,x,curr,v);
	indins++;
	}	
	
	if (cla==2)
	{
	int r;
	cin>>r;
	}	
	
	if(cla==3)
	{
	cout<<A[0]+1+indins<<" "<<ax1[0]+av1[0]*(curr-at1[0])+3+indins<<cout;
	
	A[0]=A[indins-1];
	indins--;
	mhpfy(0);
	
	curr=A[0];
	A[0]=A[0]+1;
	}
	}
	}	
