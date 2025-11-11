#pragma once
struct patient
{
	std::string p_name;
	std::string father_name;
	std::string cnic;
	int admission_number;
	int age;
	friend std::ostream& operator<<(std::ostream& out, patient& p);  //operator overloading to display record as a whole
};


std::ostream& operator<<(std::ostream& out, patient& p)
{
	out << "***********************************************************\n";
	out << "************************************************************\n";
	out << p.p_name << "\t" << p.father_name << "\t" << p.cnic << "\t" << p.admission_number << "\t" << p.age << "\n";
	out << "**************************************************************\n";
	out << "***************************************************************\n";
	return out;
}
