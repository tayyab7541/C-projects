#include<iostream>
#include<string>
#include "structure.h"
#include<queue>
#include<fstream>


void add_queue(std::queue<patient> *&obj1, int& size, std::string *&ar);
void remove_queue(std::queue<patient>*& obj1, int& size, std::string*& ar);

int main(int argc, char* argv[])
{

	if (argc == 2)
	{



		if (strcmp(argv[1], "--help") == 0)
		{
			std::cout << "If you have question in your mind \n *****  How To Use this program ?*****\n You are at right place \n";
			std::cout << "After you have compiled and linked program successfully \n";
			std::cout << "Run progarm as : file_name.exe 'number_of_queues_required_only_numbers' after that hit 'Enter' to go next \n\n";

		}
		else
		{
			if (atoi(argv[1]))  //this will check if user has given a digit for number of queues
			{
				int size = atoi(argv[1]);

				if (size >= 1) //this will make surre that user may not enter negative number as number of queues
				{
					std::fstream file;
					file.open("F:\\DSA\\DSA PROGRAMS\\Hospital system\\Hospital system\\Hospital_data.txt", std::ios::app);
					if (!file.is_open())
					{
						std::cout << "File cannot be opend check path of file \n";
						return 0;
					}

					else
					{


						int choice_number;
						std::queue<patient>* object;
						object = new std::queue<patient>[size];
						std::string* ar;
						ar = new std::string[size]; //this is used to store names of queues entered from user 
						int i;
						std::cout << "Enter Names of queues according to their purpose for which these are used \n";
						for (i = 0; i < size; ++i)   //this loop will get names of queues 
						{

							std::cout << "Enter name of " << i + 1 << " queue = ";
							std::getline(std::cin, ar[i]);  //getting names of queues
							file << 1 << "\t" << ar[i] << std::endl;

						}

						bool operation_check;  //used to terminate loop

						do   //i will name this loop as basic do while loop to show you where it ends 
						{

							operation_check = false;
							std::cout << "1:To Add patient \n2:To Display & Remove patient's record\n3:To add/remove another Queue\n4:To Diplay total number of queues with their names  \n5:To Exit program\nEnter Your choice = ";
							std::cin >> choice_number;
							if (choice_number == 1)
							{
								int index;
								std::string q_names;
								std::cin.ignore();
								std::cout << "Enter Names of Queues to perform operations = ";
								getline(std::cin, q_names);

								//checking index of queue
								bool found = false;
								for (i = 0; i < size; ++i)
								{
									if (ar[i] == q_names)      //to check if queue is present in list or not 
									{

										found = true; //setting that queue has been founded
										index = i;
										char option;
										do
										{
											bool f;
											patient pt;
											do         //getting name of patients
											{
												std::cout << "Enter Name of Patient = ";
												std::getline(std::cin, pt.p_name);
												f = true;
												for (char ch : pt.p_name)  //this will read string char by char 
												{
													if ((std::isalpha(ch)) || (std::isspace(ch))) //if it is char do nothing 
													{

													}
													else //it will make surre loop gets name again 
													{
														std::cout << "There should be ony alphabets in name \n";
														f = false;
														break;  //this will only stop inner loop
													}
												}
											} while (!f);

											do  //getting name patient's father
											{
												std::cout << "Enter Father Name of patient = ";
												std::getline(std::cin, pt.father_name);
												f = true;
												for (char ch : pt.father_name)  //this will read string char by char 
												{
													if ((std::isalpha(ch)) || (std::isspace(ch))) //if it is char do nothing 
													{

													}
													else //it will make surre loop gets name again 
													{
														std::cout << "There should be ony alphabets in name \n";
														f = false;
														break; //this will only break inner loop
													}
												}


											} while (!f);

											int count;

											do //getting cnic of patient
											{
												count = 0;
												std::string cnic;
												std::cout << "Enter CNIC OF Patient without dashes and space = ";
												std::getline(std::cin, cnic);
												f = true;
												for (char ch : cnic)  //if cnic input is not working right to do check this statement
												{
													if (std::isdigit(ch))
													{
														++count;  //counting number of digits in cnic
													}
													else
													{
														std::cout << "Enter numbers only in CNIC \n";
														f = false;
														break;
													}
												}
												if (f)
												{
													pt.cnic = cnic;   
												}

												if (count!=13&&f)
												{
													std::cout << "CINC  must have 13 digits \n";
												}

											} while (!f  || count!=13);  //loop will continue untill user enters correct value



											do //getting admission number of patien
											{
												std::string ad_number;
												std::cout << "Enter Admission number OF Patient = ";
												std::getline(std::cin, ad_number);
												f = true;

												for (char ch : ad_number)  //if ad_number input is not working right to do check this statement
												{
													if (std::isdigit(ch))
													{

													}
													else
													{
														std::cout << "Enter numbers only in Admission number \n";
														f = false;
														break;
													}
												}
												if (f)
												{
													pt.admission_number = stoi(ad_number);
												}

											} while (!f);

											do //getting Age of patient
											{
												std::string temp_age;
												std::cout << "Enter Age OF Patient = ";
												std::getline(std::cin, temp_age);
												f = true;

												for (char ch : temp_age)  //if Age input is not working right to do check this statement
												{
													if (std::isdigit(ch))
													{

													}
													else
													{
														std::cout << "Enter numbers only in Age \n";
														f = false;
														break;
													}

												}
												if (f)
												{
													pt.age = stoi(temp_age);
												}

											} while (!f);
											object[index].push(pt);  //pushing record in queue
											std::cout << "Patient record added successfully\n";
											//writting record to the file 
											file << "Queue Name \t" << q_names << std::endl;
											file << pt.p_name << "\t" << pt.father_name << "\t" << pt.cnic << "\t" << pt.admission_number << "\t" << pt.age << std::endl;
											std::cout << "To add another patient in same queue press  [y] =";
											std::cin >> option;
											std::cin.ignore();
										} while (option == 'y' || option == 'Y');
									} //end of if statement checking if queue with this name exists or not 
								}           //end of for loop looping through names of queues 

								if (!found) //if queue not found this will be executed 
								{
									std::cout << "Queue with this name could not be found in list of queues \n";
								}
							}

							else if (choice_number == 2)
							{

								bool q_check = false;
								std::string q_names;
								bool record_found = false;
								std::cin.ignore();
								std::cout << "Enter Name of Queue to perform operations = ";
								std::getline(std::cin, q_names);
								for (i = 0; i < size; ++i)
								{
									if (ar[i] == q_names)
									{
										if (!object[i].empty())
										{
											std::cout << object[i].front();
											q_check = true;
											object[i].pop();
											q_check = true;
											record_found = true;
										}
										else
										{
											q_check = true;
											q_check = true;
											record_found = true;
											std::cout << "Queue is empty nothing to dispaly more \n";
										}

									}
								}
								if (!q_check)
								{
									std::cout << "Queue with this name does not exist \n";
								}
								else //this is for if queue with that name is found but record is not found 
								{
									if (!record_found)
									{
										std::cout << "record cannot be found in queue \n";
									}

								}


							}

							else if (choice_number == 3)
							{
								char choice;
								std::cout << "A:To add new Queue \nR:To remove an existing queue \nEnter Your choice = ";
								std::cin >> choice;
								if (choice == 'a' || choice == 'A')
								{
									add_queue(object, size, ar);
								}
								else if(choice=='R'||choice=='r')
								{
									remove_queue(object, size, ar);
								}
							}

							else if (choice_number == 4)
							{
								std::cout << "Total number of Queues present = " << size << std::endl;
								std::cout << "****************************************************\n";
								std::cout << "*****************************************************\n";
								for (i = 0; i < size; ++i)
								{

									std::cout << i + 1 << "\t" << ar[i]<<"\t Number of patients = " << object[i].size() << std::endl;


								}
								std::cout << "****************************************************\n";
								std::cout << "*****************************************************\n";
							}

							else if (choice_number == 5)
							{
								operation_check = true;

							}
							else
							{
								std::cout << "Dear user Please Enter valid option \n";
							}



						} while (!operation_check);  //end basic do while loop
						file.close();
					}
				}
				else //program will exit if user will enter negative number
				{
					std::cout << "Run again and enter valid positive number for number of queues \n";
					return 0;
				}


			}
			else
			{
				std::cout << "Run again and enter valid number for number of queues \n";
				return 0;
			}
		}
	}

   else
   {
	   std::cout << "Invalid arguments Given to see how to use run in a way given below :\n";
	   std::cout << "file_name.exe  --help \n";
    }


}


void add_queue(std::queue<patient> *&obj1, int& size, std::string *&ar)   //function to add queue
{
	int number_of_new_queues;
	int pre_size;
	do
	{
		std::cout << "Enter how many queues you want to enter more = ";
		std::cin >> number_of_new_queues;

	} while (number_of_new_queues < 0);
	
	
	pre_size = size;
	size += number_of_new_queues;
	
	std::queue<patient> *temp;
	std::string *temp_names;
	temp_names = new std::string[size];
	temp = new std::queue<patient>[size];
	int i = 0;
	for (int i = 0; i < pre_size;++i)
	{
		while(!obj1[i].empty())
		{
			temp[i].push(obj1[i].front());
			obj1[i].pop();
		}
	}
	
	
	
	for (int i =0; i < size; ++i)
	{
		if(i>=pre_size)
		{
			std::cout << "Enter name of " << i + 1 << " queue to add =";
			std::cin.ignore();
			std::getline(std::cin, temp_names[i]);
		}	
		else
		{
			temp_names[i] = ar[i];
		}

	}

	std::cout << "Queue has been added \n";
	delete[] ar;
	delete[] obj1;
	obj1 = temp;
	ar = temp_names;
	temp = nullptr;
	temp_names = nullptr;
}



void remove_queue(std::queue<patient>*& obj1, int& size, std::string*& ar)  //function to remove a queue
{
	std::queue<patient> *temp;

	std::string *temp_names, ar_name;

	int temp_size = size-1;

	std::cout << "Enter Name of Queue to be deleted = ";
	std::cin.ignore();
	getline(std::cin, ar_name);

	temp = new std::queue<patient>[temp_size];

	temp_names = new std::string[temp_size];

	bool found = false;

	for (int i = 0; i <size; ++i)
	{
		if (ar_name == ar[i])
		{
			for (int j = i; j < size - 1; ++j)
			{
				    temp[j] = obj1[j+1];
					temp_names[j] = ar[j+1];

			}
			--size;
			found = true;
			break;
		}
		else
		{
			temp[i] = obj1[i];
			temp_names[i] = ar[i];
			
		}

	}
	if (found)
	{
		delete[] ar;
		delete[] obj1;

		ar = temp_names;
		obj1 = temp;
		temp_names = nullptr;
		temp = nullptr;
		std::cout << "Queue has been deleted \n";
	}
	else
	{
		delete[] temp;
		delete[] temp_names;
	}

}
