#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void main()
	{
	float x1,x2,y1,y2;
	int lc,pc,i,j,gd=DETECT,gm,m=400;
	char ch;

    printf("dragon by jigar");

	FILE *fp;
	clrscr();

	fp=fopen("dragon.grs","r");
	fscanf(fp,"%c",&ch);
	getch();
	while(ch!='*')
	     {
	     printf("%c",ch);
	     fscanf(fp,"%c",&ch);
	     }
	getch();
//search till *
	while(ch!='\n')
	     {
	     printf("%c",ch);
	     fscanf(fp,"%c",&ch);
	     }
	getch();
//search till \n
	fscanf(fp,"%f %f %f %f",&x1,&x2,&y1,&y2);
	printf("\n%f %f %f %f",x1,x2,y1,y2);
	fscanf(fp,"%d",&lc);
	printf("%d",lc);
	getch();
// display boundary & no of lines
	initgraph(&gd,&gm,"d:\\tc\\tc\\bgi");
//	setcolor(GREEN);
	rectangle(x1*m,479-(x2*m),y1*m,479-(y2*m));
	getch();

// setcolor(GREEN);
	for(i=0;i<=lc-1;i++)
	   {
	   fscanf(fp,"%d",&pc);		//get point count
	   fscanf(fp,"%f %f",&x1,&y1);  //get first point

	   moveto(x1*m,479-(y1*m));	//rev

	   for(j=0;j<pc-1;j++)
	      {
	      fscanf(fp,"%f %f",&x2,&y2);
	      lineto(x2*m,479-(y2*m));	//draw line to next point rev
	      }
//	      getch();
	   }
	getch();
	closegraph();
	fclose(fp);
	}
