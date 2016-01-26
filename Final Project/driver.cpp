#include <iostream>
#include <math.h>
#include "calculations.h"
using namespace std;



int main()
{
	int responce,common_factor;
	int equation_Nums[4];
	int* pntr = equation_Nums;

	cout<<"Welcome to the Polynomial Calculator!\n";
do{
	do{
		cout<<"\nWould you like to hear the directions?\n1)Yes\n2)No\nPlease enter a 1 or a 2: ";
		cin>>responce;
		if(responce==1)
		{
			cout<<"\n***DIRECTIONS***\nThis a polynomial calculator that foils and factors polynomials whoes degree does not exceed 2. (See below for example.)\n\nFoiling Examples:\n(3x + 2)(2x + 1) --- Correct\n(3x^2 + 2)(2x + 1) --- Incorrect (Degree Exceeds 2)\n\nFactoring Example:\n3x^2 + 14x + 8 --- Correct\n3x^3 + 14x^2 + 8x + 2 --- Incorrect (Degree Exceeds 2)\n***DIRECTIONS***\n ";//display directions
		}
		else if(responce!=1&&responce!=2)
		{
			cout<<"\n***** ERROR: Must enter a '1' or a '2' *****\n";//Error Message
		}
	}while(responce!=1 && responce!=2);
	do{
		cout<<"\nAre you attempting to factor or foil?\n1)Foil\n2)Factor\nPlease enter a 1 or 2: ";
		cin>>responce;
		if(responce==1)
		{
			cout<<"\nFoiling ----> (Ax + B)(Cx + D)\n"; //Foiling
			for(int i = 0, x=65;i<4;i++,x++)
			{
				cout<<"Enter the value for " <<(char) x<< " : ";
				cin>>equation_Nums[i];
			}
			cout<<"\nYour Foiled Equation:\n";
			foil(equation_Nums);
		}
		else if (responce==2)
		{
			cout<<"\nFactoring ----> Ax^2 + Bx + C\n"; //Factoring
			for(int i = 0, x=65;i<3;i++,x++)
			{
				cout<<"Enter the value for " <<(char) x<< " : ";
				cin>>equation_Nums[i];
			}
			cout<<"\nYour Equation:\n";
			cout<<"("<<equation_Nums[0]<<"x^2 + "<<equation_Nums[1]<<"x + "<<equation_Nums[2]<<")";
			common_factor = num_factor(pntr);
			if(common_factor>1)
			{
				cout<<"\n\nYour Equation With GFC Factored Out:\n";
				cout<<common_factor<<"("<<equation_Nums[0]<<"x^2 + "<<equation_Nums[1]<<"x + "<<equation_Nums[2]<<")";
			}
			cout<<"\n\nYour Completely Factored Equation:";
			if(sqrt(equation_Nums[2])+sqrt(equation_Nums[2])==equation_Nums[1])
			{
				if(common_factor==1)
                                	cout<<"\n(x + "<<sqrt(equation_Nums[2])<<")(x + "<<sqrt(equation_Nums[2])<<")\n";
				else
					cout<<"\n"<<common_factor<<"(x + "<<sqrt(equation_Nums[2])<<")(x + "<<sqrt(equation_Nums[2])<<")\n";

			}
                        else if( -(sqrt(equation_Nums[2])) + -(sqrt(equation_Nums[2]))==equation_Nums[1])
                        {
                                if(common_factor==1)
                                        cout<<"\n(x - "<<sqrt(equation_Nums[2])<<")(x - "<<sqrt(equation_Nums[2])<<")\n";
                                else
                                        cout<<"\n"<<common_factor<<"(x - "<<sqrt(equation_Nums[2])<<")(x - "<<sqrt(equation_Nums[2])<<")\n";

                        }
                        else
                                factor(equation_Nums,common_factor);

		}
		else
		{
			cout<<"ERROR: Must enter a '1' or a '2'";
		}
	}while(responce!=1 && responce!=2);
	do{
	cout<<"\nWould you like to make another calculation?\n1)Yes\n2)No\nPlease enter a 1 or 2: ";
	cin>>responce;
	if (responce == 2) cout<<"\nGoodbye!\n";
	else if(responce == 1){}
	else cout<<"\nERROR: Must enter a '1' or a '2'\n";
	}while(responce!=1 && responce!=2);
}while(responce==1);
	return 0;
}
