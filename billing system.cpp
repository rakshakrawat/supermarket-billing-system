#include<iostream>
#include<fstream>

using namespace std;

class shopping{
	private:
	int pcode;
	float price;
	float dis;
	string pname;

	public:
	void menu();
	void administractor();
	void buyer();
	void add();
	void edit();
	void list();
	void receipt();
	void rem();
};

void shopping :: menu(){
	m:
	int choice;
	string email;
	string password;

	cout<<"\t-----------------------------\n";
	cout<<"\t|                           |\n";
	cout<<"\t|   Supermarket Main Menu   |\n";
	cout<<"\t|                           |\n";
	cout<<"\t-----------------------------\n";
	cout<<"\t|                           |\n";
	cout<<"\t| 1) Administrator          |\n";
	cout<<"\t|                           |\n";
	cout<<"\t| 2) Buyer                  |\n";
	cout<<"\t|                           |\n";
	cout<<"\t| 3) Exit                   |\n";
	cout<<"\t|                           |\n";
	cout<<"\t Please select!              \n";
	cin>>choice;
	switch(choice){
		case 1:
		{
			cout<<"\t Please Login \n\n";
			cout<<"\t Enter Email  \n";
			cin>>email;
			cout<<"\t Password     \n";
			cin>>password;

			if(email=="admin@email.com" && password=="admin@123"){
				administractor();
			}
			else{
				cout<<"Invalid email/password";
			}
			break;
		}
		case 2:
		{
			buyer();
		}
		case 3:
		{
			exit(0);
		}
		default:
		{
			cout<<"Please select from the given options";
		}
	}
goto m;
}

void shopping :: administractor(){
	m:
	int choice;
	cout<<"\n\t-----------------------------\n";
	cout<<"\t|                           |\n";
	cout<<"\t|     Adminstrator menu     |\n";
	cout<<"\t|                           |\n";
	cout<<"\t-----------------------------\n";
	cout<<"\t| 1) Add the product        |\n";
	cout<<"\t|                           |\n";
	cout<<"\t| 2) Modify the product     |\n";
	cout<<"\t|                           |\n";
	cout<<"\t| 3) Delete the product     |\n";
	cout<<"\t|                           |\n";
	cout<<"\t| 4) Back to main menu      |\n";
	cout<<"\t|                           |\n";

	cout<<"\n\t please enter your choice ";
	cin>>choice;

	switch(choice){
		case 1:
			add();
			break;

		case 2:
			edit();
			break;

		case 3:
			rem();
			break;

		case 4:
			menu();
			break;
		
		default:
			cout<<"Invalid choice";
	}
	goto m;
}

void shopping :: buyer(){
	m:
	int choice;
	cout<<"\n\t-----------------------------\n";
	cout<<"\t|                           |\n";
	cout<<"\t|           Buyer           |\n";
	cout<<"\t|                           |\n";
	cout<<"\t-----------------------------\n";
	cout<<"\t| 1) Buy product            |\n";
	cout<<"\t|                           |\n";
	cout<<"\t| 2) go back                |\n";
	cout<<"\t|                           |\n\n";
	cout<<"\t Enter your choice ";
	cin>>choice;
	switch(choice){
		case 1:
			receipt();
			break;
		
		case 2:
			menu();
			break;

		default:
			cout<<"Invalid choice";
	}
	goto m;
}

void shopping :: add(){
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;

	cout<<"\n\t Add new product ";
	cout<<"\n\n\t Product code of the product : ";
	cin>>pcode;
	cout<<"\n\t Name of the product : ";
	cin>>pname;
	cout<<"\n\t Price of the product : ";
	cin>>price;
	cout<<"\n\t Discount on the product : ";
	cin>>dis;

	data.open("database.txt",ios::in);

	if(!data){
		data.open("database.txt" ,ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else{
		data>>c>>n>>p>>d;

		while(!data.eof()){
			if(c==pcode){
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	
	if(token==1){
		goto m;
	}
	else{
		data.open("database.txt" ,ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	}
	cout<<"\n\t Record inserted !";

}
void shopping :: edit(){
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;

	cout<<"\n\t Modify the record";
	cout<<"\n\t Product code :";
	cin>>pkey;

	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n File doesn't exist";
	
	}
	else{
		data1.open("database1.txt", ios::app| ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pkey==pcode){
				cout<<"\n\t Product new code :";
				cin>>c;
				cout<<"\n\t Name of the product :";
				cin>>n;
				cout<<"\n\t Price :";
				cin>>p;
				cout<<"\n\t Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\t Record edited";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;

		}
		data.close();
		data1.close();

		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0){
			cout<<"\n\n Record not found !";
		}
	}
}

void shopping :: rem(){
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\t Delete product ";
	cout<<"\n\n\t Product code";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data){
		cout<<"File doesn't exist";
	}

	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pcode==pkey){
				cout<<"\n\t Product delete succesfully";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");

		if(token==0){
			cout<<"\n\n Record not found";
		}
	}

}

void shopping:: list(){
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\t_________________________________\n";
	cout<<"\tProNo\t Name \t Price \n";
	cout<<"\t_________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof()){
		cout<<"\t"<<pcode<<"\t"<<pname<<"\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	cout<<"\n\n";
	data.close();
}

void shopping :: receipt(){
	
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;

	cout<<"\n\n\t\t RECEIPT";
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\n Empty Database";
	}
	else{
		data.close();

		list();
		cout<<"\n\t_____________________________________";
		cout<<"\n\t|                                    |";
		cout<<"\n\t|                                    |";
		cout<<"\n\t|        Please place the order      |";
		cout<<"\n\t|                                    |";
		cout<<"\n\t|____________________________________|\n\n";

		do{
			m:
			
			cout<<"\n Enter Product code : ";
			cin>>arrc[c];
			cout<<"\n Enter the product quantity : ";
			cin>>arrq[c];
			for(int i = 0;i<c;i++){
				if(arrc[c]==arrc[i]){
					cout<<"\n Duplicate product code. Please try again !";
					goto m;
				}
				
			}
			c++;
			cout<<"\n Do you want to buy another product? Press y for yes and n for no : ";
			cin>>choice;
		}
		while(choice=='y');

		cout<<"\n\t_____________________RECEIPT_______________________\n";
		cout<<"\n Product No. \t Product quantity \t Price \t Amount with discount \n";
		
		for(int i = 0;i<c;i++){
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof()){
				
				if(pcode==arrc[i]){
					amount=price*arrq[i];
					dis = amount-(amount*dis/100);
					total = total + dis;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t"<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
			data.close();
		}
		
	}
	
	cout<<"\n\t___________________________________________";
	cout<<"\n\t Total Amount :"<<total<<"\n\n";
}

int main(){
	shopping s;
	s.menu();
}

