#include <iostream>
#include "calculations.h"
using namespace std;

int find_max(int x, int y)
{
	if(x>y) return x;
	else return y;
}

void foil(int x[])
{
	int A=x[0],B=x[1],C=x[2],D=x[3];
	cout<<A*C<<"x^2 + "<<(A*D)+(B*C)<<"x + "<<D*B;
}

int num_factor(int *x)
{
	int A = *x, B = *(x+1), C = *(x+2);
	int max = find_max(find_max(A,B),C);
	int factor;
	for(int i=max;i>1;i--)
	{
		if(A%i==0&&B%i==0&&C%i==0)
		{
			*x=(A/i), *(x+1)=(B/i), *(x+2)=(C/i);
			return i;
		}
	}
	return 1;
}

void factor(int x[],int common_factor)
{
	int A=x[0],B=x[1],C=x[2],A_array_size=1,C_array_size=1;
	int* A_Multiples;
	int* C_Multiples;
	bool A_neg = false, C_neg = false;
	
	if(A==1||A==-1)
	{
		A_array_size=2;
		A_Multiples = new int[A_array_size];
		if(A>0)
		{
			A_Multiples[0]=1;
			A_Multiples[1]=1;
		}
		else
		{
			A_Multiples[0]=-1;
			A_Multiples[1]=1;
		}
	}
	else
	{
		A_array_size = find_num_multiples(A);
		A_Multiples = new int[A_array_size];
		find_multiples(A_Multiples,A,A_array_size);
	}

	if(C==1||C==-1)
	{
		C_array_size=2;
		C_Multiples = new int[C_array_size];
		if(C>0)
		{
			C_Multiples[0]=1;
			C_Multiples[1]=1;
		}
		else
		{
			C_Multiples[0]=-1;
			C_Multiples[1]=1;
		}
	}
	else
	{
		C_array_size = find_num_multiples(C);
		C_Multiples = new int[C_array_size];
		find_multiples(C_Multiples,C,C_array_size);
	}

	//Finding Equation
	for(int i=0; i<A_array_size; i+=2)
        {
                for(int x=0;x<C_array_size;x+=2)
                {
                        if(A_Multiples[i]*C_Multiples[x] + A_Multiples[i+1]*C_Multiples[x+1]==B)
						{
							if(common_factor==1)
                                cout<<"\n("<<A_Multiples[i]<<"x + "<<C_Multiples[x+1]<<")("<<A_Multiples[i+1]<<"x + "<<C_Multiples[x]<<")\n";
							else
								cout<<"\n"<<common_factor<<"("<<A_Multiples[i]<<"x + "<<C_Multiples[x+1]<<")("<<A_Multiples[i+1]<<"x + "<<C_Multiples[x]<<")\n";
							x=C_array_size;
							i=A_array_size;
						}
                        else if(A_Multiples[i]*C_Multiples[x+1] + A_Multiples[i+1]*C_Multiples[x]==B)
						{
							if(common_factor==1)
                                cout<<"\n("<<A_Multiples[i]<<"x + "<<C_Multiples[x]<<")("<<A_Multiples[i+1]<<"x + "<<C_Multiples[x+1]<<")\n";
							else
								cout<<"\n"<<common_factor<<"("<<A_Multiples[i]<<"x + "<<C_Multiples[x]<<")("<<A_Multiples[i+1]<<"x + "<<C_Multiples[x+1]<<")\n";
							x=C_array_size;
							i=A_array_size;
						}
                }
		if(i==A_array_size-2)cout<<"\npolynomial cannot be factored any further.\n";
        }
}

int find_num_multiples(int num)
{
	if(num<0) 
	{
		num=num*-1;
	}
	int array_size=1;
		for(int i=1;i<num;i++)
		{
			if(num%i==0)
			{
				array_size++;
			}
		}
		array_size*=2;
		return array_size;
}

void find_multiples(int* arr, int num,int array_size)
{
	bool neg = false;
	if(num<0) 
	{
		num=num*-1;
		neg = true;
	}
		int *arr_copy=arr;
		int* new_arr=arr_copy+(array_size/2);
		for(int i=1,x=0;i<num;i++)
		{
			if(num%i==0)
			{
				if(x>0&&*(arr-1)==i) i=num;
				else
				{
					if(neg)
					{
						*arr = -i;
						*(arr+1) = num/i;
						arr+=2;
					}
					else
					{
						*arr = i;
						*(arr+1) = num/i;
						arr+=2;
						x++;
					}
				}
			}
		}
		for(int i=(array_size/2);i<array_size;i++,arr_copy++,new_arr++)
		{
			*new_arr = -(*arr_copy);
		}
}
