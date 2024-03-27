#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int n0,m0,j=0,count=0,*hang=(int*)malloc(sizeof(int)),mohang,*lie=(int*)malloc(sizeof(int)),*lieshu=(int*)malloc(sizeof(int)),*hangshu=(int*)malloc(sizeof(int)),lieshustore,*hangshustore=(int*)malloc(sizeof(int)),lieshucount=0,lieshudizhi=0;
int min(int m,int n)
{
	int t;
	t=m;
	if(n<m)
		t=n;
	return t;
}
void fun(int m,int n)
{
	int i,k;
	if(n>1)
	{
		for(i=0;i<=n-1;i++)
		{
			j++;
			hang=(int*)realloc(hang,j*sizeof(int));
			hang[j-1]=n-i;/*valid*/
			mohang=m-hang[j-1];/*valid*/
			fun(mohang,min(mohang,hang[j-1]));
			j--;
		}
	}
	else
	{
		count=count+1;
		if(n==1)
		{
			hang=(int*)realloc(hang,(j+mohang)*sizeof(int));
			for(i=j;i<=j+mohang-1;i++)
				hang[i]=1;
			/**/
			printf("按行从上到下计数:");
			for(i=j+mohang-1;i>=0;i--)
				printf("%d ",hang[i]);
			printf("\n");
			/**/
			lie=(int*)realloc(lie,(hang[0])*sizeof(int));
			for(k=0;k<hang[0];k++)
			{
				lie[k]=0;
				for(i=0;i<=j+mohang-1;i++)
				{
					if(hang[i]-k-1>=0)
						lie[k]=lie[k]+1;
				}
			}
			/**/
			printf("按列从左到右计数:");
			for(k=0;k<hang[0];k++)
				printf("%d ",lie[k]);
			printf("\n\n");
			if(lieshustore!=hang[0])/*FUNCTION1 addstart*/
			{
				lieshustore=hang[0];
				lieshudizhi++;
				lieshu=(int*)realloc(lieshu,lieshudizhi*sizeof(int));
				lieshu[lieshudizhi-1]=lieshucount;
				lieshucount=1;
			}
			else
			{
				lieshucount++;
			}/*FUNCTION1 addfinish*/
			if(m0%min(m0,n0)!=0)/*FUNCTION2 addstart*/
			{
				for(i=0;i<=m0-((m0-m0%min(m0,n0))/min(m0,n0)+1);i++)
				{
					if(hangshustore[i]==lie[0])
						hangshu[i]++;
				}
			}
			else
			{
				for(i=0;i<=m0-m0/min(m0,n0);i++)
				{
					if(hangshustore[i]==lie[0])
						hangshu[i]++;
				}
			}/*FUNCTION2 addfinish*/
		}
		if(n==0)
		{
			printf("按行从上到下计数:");
			for(i=j-1;i>=0;i--)
				printf("%d ",hang[i]);
			printf("\n");
			/**/
			lie=(int*)realloc(lie,(hang[0])*sizeof(int));
			for(k=0;k<hang[0];k++)
			{
				lie[k]=0;
				for(i=0;i<=j-1;i++)
				{
					if(hang[i]-k-1>=0)
						lie[k]++;
				}
			}
			/**/
			printf("按列从左到右计数:");
			for(k=0;k<hang[0];k++)
				printf("%d ",lie[k]);
			printf("\n\n");
			if(lieshustore!=hang[0])/*FUNCTION1 addstart*/
			{
				lieshustore=hang[0];
				lieshudizhi++;
				lieshu=(int*)realloc(lieshu,lieshudizhi*sizeof(int));
				lieshu[lieshudizhi-1]=lieshucount;
				lieshucount=1;
			}
			else
			{
				lieshucount++;
			}/*FUNCTION1 addfinish*/
			if(m0%min(m0,n0)!=0)/*FUNCTION2 addstart*/
			{
				for(i=0;i<=m0-((m0-m0%min(m0,n0))/min(m0,n0)+1);i++)
				{
					if(hangshustore[i]==lie[0])
						hangshu[i]++;
				}
			}
			else
			{
				for(i=0;i<=m0-m0/min(m0,n0);i++)
				{
					if(hangshustore[i]==lie[0])
						hangshu[i]++;
				}
			}/*FUNCTION2 addfinish*/
		}
	}
}
void main()
{
	int i;
	printf("请像这样输入球的个数和筒宽,之间以逗号隔开'm,n':");
	scanf("%d,%d",&m0,&n0);
	lieshustore=min(m0,n0);/*FUNCTION1 add*/
	if(m0%min(m0,n0)!=0)/*FUNCTION2 addstart*/
	{
		hangshustore=(int*)realloc(hangshustore,(m0-((m0-m0%min(m0,n0))/min(m0,n0)+1)+1)*sizeof(int));
		hangshu=(int*)realloc(hangshu,(m0-((m0-m0%min(m0,n0))/min(m0,n0)+1)+1)*sizeof(int));
		for(i=0;i<=m0-((m0-m0%min(m0,n0))/min(m0,n0)+1);i++)
		{
			hangshustore[i]=(m0-m0%min(m0,n0))/min(m0,n0)+1+i;
			hangshu[i]=0;
		}
	}
	else
	{
		hangshustore=(int*)realloc(hangshustore,(m0-m0/min(m0,n0)+1)*sizeof(int));
		hangshu=(int*)realloc(hangshu,(m0-m0/min(m0,n0)+1)*sizeof(int));
		for(i=0;i<=m0-m0/min(m0,n0);i++)
		{
			hangshustore[i]=m0/min(m0,n0)+i;
			hangshu[i]=0;
		}
	}/*FUNCTION2 addfinish*/
	fun(m0,min(m0,n0));
	printf("\n如上所示,共有%d组解的组合。\n\n",count);
	lieshudizhi++;/*FUNCTION1 addstart*/
	lieshu=(int*)realloc(lieshu,lieshudizhi*sizeof(int));
	lieshu[lieshudizhi-1]=1;/*FUNCTION1 addfinish*/
	for(i=1;i<=lieshudizhi;i++)/*FUNCTION1 addstart*/
	{
		printf("纵向上有%d种数的组合种类，有%d个\n",lieshudizhi+1-i,lieshu[i-1]);
	}/*FUNCTION1 addfinish*/
	printf("\n\n");
	if(m0%min(m0,n0)!=0)/*FUNCTION2 addstart*/
	{
		for(i=m0-((m0-m0%min(m0,n0))/min(m0,n0)+1);i>=0;i--)
			printf("横向上有%d种数的组合种类，有%d个\n",hangshustore[i],hangshu[i]);
	}
	else
	{
		for(i=m0-m0/min(m0,n0);i>=0;i--)
			printf("横向上有%d种数的组合种类，有%d个\n",hangshustore[i],hangshu[i]);
	}/*FUNCTION2 addfinish*/
}