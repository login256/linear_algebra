#include"matrix.cpp"

using namespace linear_algebra;

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
