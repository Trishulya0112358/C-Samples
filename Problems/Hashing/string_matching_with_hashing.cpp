#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<math.h>
using namespace std;

long long int random_number(long long int n)
    {
    long long int a=rand()%n;;
    while(a==0 || a%2==0 || a%3==0)
	{a=rand()%n;}
	return a;
    }
    
  	//power(p,k,mod)=(p^k)%mod
    
int power(long long int p,long long int k,long long int mod)
{
	int res=1;
	p=p%mod;
	while(k>0)
	{
	if(k%2==1){res=(res*p)%mod;}
	k=k>>1;
	p=(p*p)%mod;
	}
	return res;
}
    
int main()
	{
	srand(time(0));

  cout<<"Solution by Jigar"<<endl;
    
	long long int n,m,i;
	cin>>n;
	int A[n],H[n];
	char S[n];	
	for(i=0;i<n;i++)
	{
	cin>>S[i];
	A[i]=((int)S[i])-48;
	}
	
	cin>>m;

	long long int i_1[m],j_1[m],k_1[m],l_1[m];
	for(i=0;i<m;i++)
	{
	cin>>i_1[i]>>j_1[i]>>k_1[i]>>l_1[i];
	}
//	cout<<"i_1[0]="<<i_1[0]<<" j_1[0]="<<j_1[0]<<" k_1[0]="<<k_1[0]<<" l_1[0]="<<l_1[0]<<endl;
	int Output[m]={};
	int p=2;
	for(int no=0;no<(50*log(n)+100);no++)
	{
	long long int test,mod;
	mod=random_number(8*n*(log(n)));
//	cout<<mod<<endl;
	H[0]=A[0]%mod;
	
	for(i=1;i<n;i++)
	{
	H[i]=(H[i-1]+A[i]*power(p,i,mod))%mod;
	}
/*	cout<<endl<<"H array:"<<endl;
	for(i=0;i<n;i++)
	{
	cout<<H[i]<<" ";
	}	
*/	for(test=0;test<m;test++)
	{
	if(Output[test]==1){continue;}
	long long int h1,h2;
	h1=(H[j_1[test]-1]-H[i_1[test]-1]+mod)%mod;
	h2=(H[l_1[test]-1]-H[k_1[test]-1]+mod)%mod;
	if(h1<0){h1+=mod;}
	if(h2<0){h2+=mod;}
//	cout<<"h1="<<h1<<" h2="<<h2<<endl;
	if(i_1[test]<k_1[test])
	{
	h1=(h1*(power(p,k_1[test]-i_1[test],mod)))%mod;
	}
	else{h2=(h2*(power(p,i_1[test]-k_1[test],mod)))%mod;}
//	cout<<"h1 comp="<<h1<<" h2 comp="<<h2<<endl;

	if(h1!=h2){Output[test]=1;}
	}
	
/*	for(i=0;i<m;i++)
	{
	cout<<Output[i]<<" ";
	}
*/	//cout<<endl;
	}
//	cout<<endl;
//	cout<<endl<<endl<<endl<<endl;
	for(i=0;i<m;i++)
	{
	if(Output[i]==0){cout<<"1"<<endl;}
	else{cout<<"0"<<endl;}
//	cout<<Output[i]<<" ";
	}
//	cout<<endl;
	return 0;
	}
