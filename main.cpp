#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>


namespace liner_algebra
{
	using std::abs;
	using std::swap;
	const double eps=1e-6;
	const int MAXN=10;
	class matrix
	{
		private:
			double a[MAXN][MAXN];
			int m,n;
			bool b;
		public:
			matrix(){}
			matrix(int mm,int nn,bool bb,double *aa):m(mm),n(nn),b(bb)
			{
				int cur=0;
				for(int i=1;i<=m;i++)
				{
					for(int j=1;j<=n+b;j++)
					{
						a[i][j]=aa[cur];
						cur++;
					}
				}
			}
			void print()
			{
				for(int j=1;j<=m;j++)
				{
					for(int k=1;k<=n+b;k++)
					{
						printf("%8.4f",a[j][k]);
					}
					putchar(10);
				}
			}
			void guass(int need_print)	//need_print=0:不输出 1:输出操作 2:每次输出矩阵
			{
				int cur=0;
				for(int i=1;i<=m;i++)
				{
					if(need_print)
					{
						printf("line %d:\n",i);
					}
					cur++;
					while(cur<=n)
	double temp[200]={2,1,-5,1,8,1,-3,0,-6,9,0,2,-1,2,-5,1,4,-7,6,0};
	matrix a(4,4,1,temp);
	a.guass(0);
	a.print();
					{
						int j=i;
						while(j<=m&&abs(a[j][cur])<=eps)
						{
							j++;
						}
						if(j<=m)
						{
							for(int k=cur;k<=n+b;k++)
							{
								swap(a[i][k],a[j][k]);
							}
							if(i!=j&&need_print)
							{
								printf("(%d,%d), ",i,j);
							}
							break;
						}
						else
						{
							cur++;
						}
					}
					if(cur>n)
					{
						break;
					}
					double lam=0;
					for(int j=1;j<=m;j++)
					{
						if(i^j)
						{
							lam=-a[j][cur]/a[i][cur];
							for(int k=cur;k<=n+b;k++)
							{
								a[j][k]+=a[i][k]*lam;
							}
							if(need_print)
							{
								printf("%.4lf(%d)+(%d), ",lam,i,j);
							}
						}
					}
					if(need_print)
					{
						putchar(10);
					}
					if(need_print>=2)
					{
						print();
					}
				}
				if(need_print)
				{
					std::cout<<"final:\n";
				}
				for(int i=1;i<=m;i++)
				{
					int be=0;
					for(int j=1;j<=n;j++)
					{
						if(abs(a[i][j])>eps)
						{
							be=j;
							break;
						}
					}
					if(be)
					{
						double lam=1/a[i][be];
						for(int j=be;j<=n+b;j++)
						{
							a[i][j]*=lam;
						}
						if(need_print)
						{
							printf("%.4lf(%d), ",lam,i);
						}
					}
				}
				if(need_print)
					putchar(10);
				if(need_print>=2)
				{
					print();
				}
				return;
			}
	};
}

using namespace liner_algebra;

int main()
{
	/*
	   double temp[200]={0,1,1,1,1,1,0,1,1,2,1,1,0,1,3,1,1,1,0,4};
	   matrix a(4,4,1,temp);
	   a.guass(2);
	*/
	/*
	double temp[200]={2,1,-5,1,8,1,-3,0,-6,9,0,2,-1,2,-5,1,4,-7,6,0};
	matrix a(4,4,1,temp);
	a.guass(0);
	a.print();
	*/
	double temp[200]={1,1,1,0,-1,2,1,-10,9,-3,1,20};
	matrix a(3,3,1,temp);
	a.guass(0);
	a.print();
}
