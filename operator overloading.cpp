#include<iostream>
using namespace std;
class complex
{
	private:
		int real,img;
	public:
		 complex(){ }
		 complex(int a,int b): real(a),img(b){}
		 void dis() //function to display values 
         {
         	cout<<real<<" + "<<img<<"i"<<endl;
         	
		 }	
		 complex operator+(const complex &obj2) //overloaded function to sum objects
		 
		 { complex obj1;
		    obj1.real=real+obj2.real;
		 	obj1.img=img+obj2.img;
		 	return obj1;
		 }	 
		 complex operator-(const complex &obj)
		 {
		 	complex ret;
		 	ret.real=real-obj.real;
		 	ret.img=img-obj.img;
		 	return ret;
		 }
		 complex operator*(const complex &obj)
		 {
		 	complex ret;
		 	ret.real=real*obj.real;
		 	ret.img=img*obj.img;
		 	return ret;
		 }
		 complex operator/(const complex &obj)
		 {
		 	complex ret;
		 	ret.real=real/obj.real;
		 	ret.img=img/obj.img;
            return ret;
		 }
		 bool operator==(const complex obj)
		 {
		 	if(real==obj.real&&img==obj.img)
		 	{
		 		return 1;
			 }
			 else
			 {
			 	return 0;
			 }
		 }
		 friend ostream& operator<<(ostream &out,const complex &obj)
		 {
		 	out<<"real part = "<<obj.real<<endl;
		 	out<<"imaginary part = "<<obj.img<<endl;
            return out;
		 }
};
int main()
{
	complex o1(2,3),o2(3,5),sum,dif,multiply,div,equal;
	sum=o1+o2;
	cout<<"o1 values are \n";
	o1.dis();
	cout<<" \n o2 values are \n";
	o2.dis();
	cout<<"result of sum is \n";
	sum.dis();
	dif=o1-o2;
	cout<<"result of difference is \n";
	dif.dis();
	multiply=o1*o2;
	cout<<"result of multiply is  \n";
	multiply.dis();
	div=o1/o2;
	cout<<"result of division \n";
	div.dis();
	if(o1==o2)
	{
		cout<<"objects are equal \n";
	}
	else
	{
		cout<<"objects are not equal \n";
	}
	cout<<o1<<endl;
	cout<<o2;
	
	return 0;
}
