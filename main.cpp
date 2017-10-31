#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include"num.cpp"

namespace linear_algebra
{
	using std::abs;
	using std::swap;
	const int MAXN=10;
	class matrix
	{
		private:
			num a[MAXN][MAXN];
			int m,n;
			bool b;
		public:
			matrix(){}
			matrix(int mm,int nn,bool bb,num *aa):m(mm),n(nn),b(bb)
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
						//printf("%8.4f",a[j][k]);
						a[j][k].print(9);
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
					{
						int j=i;
						while(j<=m&&a[j][cur]==num(0))
						{
							j++;
						}
						if(j<=m)
						{
							if(i!=j)
							{
								for(int k=cur;k<=n+b;k++)
								{
									swap(a[i][k],a[j][k]);
								}
								if(need_print)
								{
									printf("(%d,%d), ",i,j);
								}
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
					num lam{0};
					for(int j=1;j<=m;j++)
					{
						if(i^j)
						{
							if(a[j][cur]!=0)
							{
								lam=-a[j][cur]/a[i][cur];
								for(int k=cur;k<=n+b;k++)
								{
									a[j][k]=a[j][k]+(a[i][k]*lam);
								}
								if(need_print)
								{
									//printf("%.4lf(%d)+(%d), ",lam,i,j);
									std::cout<<lam;
									printf("(%d)+(%d), ",i,j);
								}
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
						if(a[i][j]!=num(0))
						{
							be=j;
							break;
						}
					}
					if(be)
					{
						num lam=num(1)/a[i][be];
						for(int j=be;j<=n+b;j++)
						{
							a[i][j]=a[i][j]*lam;
						}
						if(need_print)
						{
							//printf("%.4lf(%d), ",lam,i);
							std::cout<<lam;
							printf("(%d), ",i);
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

using namespace linear_algebra;

int main()
{
	num temp[200]={0,1,1,1,1,1,0,1,1,2,1,1,0,1,3,1,1,1,0,4};
	matrix a(4,4,1,temp);
	a.guass(2);
	/*
	   double temp[200]={2,1,-5,1,8,1,-3,0,-6,9,0,2,-1,2,-5,1,4,-7,6,0};
	   matrix a(4,4,1,temp);
	   a.guass(0);
	   a.print();
	   */
	/*
	   num temp[200]={1,1,1,0,-1,2,1,-10,9,-3,1,20};
	   matrix a(3,3,1,temp);
	   a.guass(2);
	   */
}
