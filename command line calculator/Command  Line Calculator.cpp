#include <iostream>
#include<string>
#include<cmath>
#include "Stack.h"
int main(int argc,char **argv)
{

	if (argc>=4 )
	{
		int size;
		stack<int> numbers;
		stack<std::string> brackets_check;
		stack<std::string> stk2;
		std::string *ar;
		size = argc-1;
		ar = new std::string[size];
		int k = 0;
		for (int i = 1; i < argc; ++i)
		{
			if (atoi(argv[i]))
			{
				ar[k] = argv[i];
				++k;
			}
			else if((strcmp(argv[i],"+")==0)|| (strcmp(argv[i], "-") == 0 )||( strcmp(argv[i], "*") == 0 )|| (strcmp(argv[i], "/") == 0) ||( strcmp(argv[i], "^") == 0) || (strcmp(argv[i], "(") == 0) || (strcmp(argv[i], ")") == 0))
			{
				ar[k] = argv[i];
				++k;
				
			}
			else 
			{
				std::cout << "Invalid operands \n";
				return 0;
			
			}
		}

		//this is for checking brackets 
		for (int i = 0; i < size; i++)
		{
			if (ar[i] == "(")
			{
				brackets_check.push("(");
			}
			else if (ar[i] == ")")
			{
				brackets_check.pop();
			}
		}


		// this is checking stack if there is left any bracket or not if yes than it will stop program 
		try	{
			if (brackets_check.empty())
			{
				//this will do nothing as brackets are equal
			}
			else
			{
				throw("Brackets in expression are not equal \n");
			}
		}
		catch (const char* e)
		{
			std::cout << e << std::endl;
			return 0;
		}


		for (int j= 0; j < size; ++j)   //this loop will input operand in nummbers stakc and operators in stk2 stack
		{
			try
			{

				int num=stoi(ar[j]); //thsi will convert string into integer if digits are present in string at specific indes otherwise throw and exception
				numbers.push(num);
				

			 }
			catch (std::invalid_argument a)
			{        
				
				if (stk2.empty()) //this will push operator if stack is empty 
				{
					stk2.push(ar[j]);
				}

				else //this will check precedence of operator if stack is not empty 
				{
					
					if (ar[j] == "(")  //pushing opening bracket into stack
					{
						stk2.push("(");
					}

					else if (ar[j] == ")")  //if closing bracket comes it will solve brackets first 
					{
						std::string ope;
						try
						{
							ope = stk2.top();
						}
						catch (const char* e)
						{
							std::cout << e << std::endl;

							break;
						}
						try
						{
							stk2.pop();
						}
						catch (const char* e)
						{
							std::cout << e << std::endl;
							break;
						}

						while (ope != "(")
						{			
								int dig1, dig2, dig3;
								try
								{
									dig1 = numbers.top();  //getting value of top
								}
								catch (const char* e)
								{
									std::cout << e << std::endl;
									break;
								}
								try
								{
									numbers.pop();     //removing value from top
								}
								catch (const char* e)
								{
									std::cout << e << std::endl;
									break;
								}
								try
								{
									dig2 = numbers.top();         //getting value of top
			
								}
								catch (const char* e)
								{
									std::cout << e << std::endl;
									break;
								}
								try
								{
									numbers.pop();        //removing value from top
								}
								catch (const char* e)
								{
									std::cout << e << std::endl;
									break;
								}								
								dig3 = math(dig2, dig1, ope);  //calling function to calculate values 
								numbers.push(dig3); //pushing result on top of numbers stack 

								try
								{
									ope = stk2.top();   //updating value of operator 
								}
								catch (const char* e)
								{
									std::cout << e << std::endl;

									break;
								}
								try
								{
									stk2.pop();  //removing operator from top
								}
								catch (const char* e)
								{
									std::cout << e << std::endl;
									break;
								}


						}
						
					}

					else
					{

						//this is being done to check precedence 
						int n1, n2;
						std::string check1, check2;
						check2 = ar[j];     //this store input operator 
						try
						{
							check1 = stk2.top();  // this store operator that is at top of stack
						}
						catch (const char* e)
						{
							std::cout << e << std::endl;
							break;
						}
						

						if (check1 == "(") //because if there is ( it will put operators after this until curly bracket
						{
							n1 = 0;
						}
						else
						{
							n1 = precedence(check1);   //getting precedence of operator that is on top
						}

						n2 = precedence(check2);      //checking precedence of operator that in input
						if (n1 >= n2)    //if operator on top and input are have same precedence or top has greater precedence it remove operator from top first and then push input operator
						{
							std::string ope;
							try
							{
								ope = stk2.top();    //getting operator that is on top of stack
							}
							catch (const char* e)
							{
								std::cout << e << std::endl;
								break;
							}
							try
							{
								stk2.pop();    //removig operator from top 
							}
							catch (const char* e)
							{
								std::cout << e << std::endl;
								break;
							}

							stk2.push(ar[j]);  //this will put new operator on top 
							
							int dig1, dig2, dig3;
							try
							{
								dig1 = numbers.top();   //getting number from top 
							}
							catch (const char* e)
							{
								std::cout << e << std::endl;
								break;
							}
							
							try
							{
								numbers.pop();  //removing number from top
							}
							catch (const char* e)
							{
								std::cout << e << std::endl;
								break;
							}

							try
							{
								dig2 = numbers.top();  //getting second number from top
							}
							catch (const char* e)
							{
								std::cout << e << std::endl;
								break;
							}

							try
							{
								numbers.pop();   //removing element from top
							}

							catch (const char* e)
							{
								std::cout << e << std::endl;
								break;
							}
							
							
							
							dig3 = math(dig2, dig1, ope); //because check1 contains top of stk2 stack
							numbers.push(dig3);           //pushing result to stack

						}





						else if (n2 > n1)
						{
							stk2.push(ar[j]);
						}
					}
				}

			}
		}


		while (!stk2.empty())  //this will continue untill stk2 is not empty 
		{
			int dig1, dig2, dig3;
			std::string ope;
			try
			{
				ope = stk2.top();   //getting operator that is on top of stack 
			}
			catch (const char* e)
			{
				std::cout << e << std::endl;
				return 0;
			}


			try
			{
				stk2.pop();  //removing operator from top
			}
			catch (const char* e)
			{
				std::cout << e << std::endl;
				return 0;
			}


			try
			{
				dig1 = numbers.top();   //getting first number from top of stack

			}
			catch (const char* e)
			{
				std::cout << e << std::endl;
				return 0;
			}


			try
			{
				numbers.pop();  //removing number from stack
			}
			catch (const char* e)
			{
				std::cout << e << std::endl;
				return 0;
			}


			try
			{
				dig2 = numbers.top();   //getting second number from stack 
				
			}
			catch (const char* e)
			{
				std::cout << e << std::endl;
				return 0;
			}


			try
			{
				numbers.pop();  //removing number from top of stack 
			}
			catch (const char* e)
			{
				std::cout << e << std::endl;
				return 0;
			}
			
			
			dig3 = math(dig2, dig1, ope);  //calling function to calculate result
			numbers.push(dig3);            //pushing new result on top of stack 
		}

		std::cout << numbers.top() << std::endl;  //displaying final results 
		numbers.pop();
	}
	else if (argc == 2 && (strcmp(argv[1], "--help") == 0))
			{ 
        std::cout << "========================================\n";
		std::cout << "Welcome To Help Section \n";
		std::cout << "=========================================\n";
		
		std::cout << "How to use this calculator ? \n";
		std::cout << "1: Usage = 1st_Operand Operator 2nd_operand \n";
		std::cout << "2: Space between operator and operand is must also give space between brackets, operators, and operands \n";
		std::cout << "3: while calculating power of number wirte symbol of power as '^' in double quotation \n";
		std::cout << "=============================================\n";
		std::cout<<"==============================================\n";
	}
	else
	{
		std::cout << "========================================\n";
		std::cout << "Welcome To Help Section \n";
		std::cout << "=========================================\n";
		std::cout << "How to use this calculator ? \n";
		std::cout << "1:Usage = 1st_Operand Operator 2nd_operand \n";
		std::cout << "2:Space between operator and operand is must also give space between brackets, operators, and operands \n";
		std::cout << "3:while calculating power of number wirte symbol of power as '^' in double quotation \n";
	}

}
