#include<iostream> //Headers
#include<istream>
#include <cstdio>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <iomanip>
#include <cctype>
#include <unistd.h>
#include <windows.h>
#define max 10


using namespace std;

void login(); //global functions
void registr();
void AdminPortal();
void forgot();

HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //for colour code

class pharmacyManagementSystem // this is the base class
{
public:
    void mainMenu();
    void take_order();
    void delete_order();
    void modify();
	void order_list();
	void daily_summary();

};


struct node //constract node
{
	int reciept_number;
	string customerName;
	string date;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Probiotics","Vitamin C(500mg)","Napa Paracetamol(500mg)","Women'S Multivate","Benadryl Syrup","Monas 10",
	"Amino Zinc Tablet","Biocal D","Pantonix(40mg)","Royal Propollen"};
	double Medicine[10] = {16.00,18.00,2.00,650.00,120.00,16.00,5.00,285.00,9.55,450.00};
	double total;

	node *prev;
	node *next;
	node *link;

}*q, *temp;				//pointer declaration


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

void pharmacyManagementSystem::mainMenu()
{
    pharmacyManagementSystem pharmacyManagementSystemObj;
    int choice,key;
    do
    {
        cout<<"                                       +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
        cout<<"                                       |S|W|I|F|T| |M|E|D|A|C|C|E|S|S|+|                   \n";
        cout<<"                                       +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
        cout << "                              ==================================================\n\n";
        cout << "                              --------------------------------------------------\n";
        cout << "                              ||     1. Check Medicine Stock                  ||\n";
        cout << "                              ||     2. New Medicine Order                    ||\n";
        cout << "                              ||     3. Delete Medicine Order                 ||\n";
        cout << "                              ||     4. Modify Order List                     ||\n";
        cout << "                              ||     5. Print Receipt And Make Payment        ||\n";
        cout << "                              ||     6. Daily Summary Of Total Sales          ||\n";
        cout << "                              ||     7. Log out                               ||\n";
        cout << "                              --------------------------------------------------\n";
        cout << "                                           Enter Your Choice: ";
        cin >> choice;
        system("CLS");
        switch (choice)

        {
        case 1:
        {
            cout<<"\n";
            cout<<"                                     +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
            cout<<"                                     |S|W|I|F|T| |M|E|D|A|C|C|E|S|S|+|                   \n";
            cout<<"                                     +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
            cout<<"                              ================================================"<<endl;
            cout<<"                              ||           1. View Medicine List            ||"<<endl;
            cout<<"                              ||           2. Go back                       ||"<<endl;
            cout<<"                               \\_____----------------------------------_____/ "<<endl;
            cout<<"                                            Enter your Choice: ";
            cin>>key;
            system("CLS");
            if (key==1)
            {
            fstream MedicineList;

                MedicineList.open("MedicineList.txt",ios::in); //open a file to perform read operation using file object
   if (MedicineList.is_open()){   //checking whether the file is open
      string tp;
      while(getline(MedicineList, tp)){  //read data from file object and put it into string.
         cout << tp << "\n";   //print the data of the string
      }
      MedicineList.close();   //close the file object.
   }
   system("PAUSE");
   system("CLS");
}
            else if (key==2)
            {
                break;
                system("PAUSE");
                system("CLS");
            }
            }
            break;
        case 2:
        {
            pharmacyManagementSystemObj.take_order();
            break;
        }
        case 3:
        {
            pharmacyManagementSystemObj.delete_order();
            system("PAUSE");
            system("CLS");
            break;
        }
        case 4:
        {
            pharmacyManagementSystemObj.modify();
            system("PAUSE");
            system("CLS");
            break;
        }
        case 5:
        {
            pharmacyManagementSystemObj.order_list();
            system("PAUSE");
            system("CLS");
            break;
        }
        case 6:
        {
            pharmacyManagementSystemObj.daily_summary();
            system("PAUSE");
            system("CLS");
            break;
        }
        case 7:
        {
            AdminPortal();
            break;
        }

        default:
        {
            cout << "You Entered An Invalid Key Input\nKindly, Re-enter The Input! \n"
                 << endl;
            break;
        }
        }
    }
    while (choice != 7);
}



void pharmacyManagementSystem::take_order()
{
    system("cls");
	int i;
    int choice, quantity, price,None;

    cout<<"\n";
            cout<<"                                     +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
            cout<<"                                     |S|W|I|F|T| |M|E|D|A|C|C|E|S|S|+|                   \n";
            cout<<"                                     +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
            cout<<"                              ================================================"<<endl;

	cout <<"                                            Add Order Details\n";
	cout <<"                                   _____________________________________ \n\n";

	node *temp;
	temp=new node;

				cout <<"                  **************************************************************************\n";
				cout<<"                   DRUGS ID"<<"\tDRUGS TYPE"<<"   \t    DRUGS NAME"<<"              DRUGS PRICE(BDT)"<<endl;
				cout <<"                  **************************************************************************\n";
                cout<<"                   0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Probiotics"<<"			Taka 16.00"<<endl;
                cout<<"                   0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Vitamin C(500mg)"<<"		Taka 18.00"<<endl;
                cout<<"                   0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Napa Paracetamol(500mg)"<<"     Taka 2.00"<<endl;
                cout<<"                   0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Women'S Multivate"<<"		Taka 650.00"<<endl;
                cout<<"                   0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Benadryl Syrup"<<"	 	Taka 120.00"<<endl;
                cout<<"                   0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Monas 10"<<"        		Taka 16.00"<<endl;
                cout<<"                   0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Amino Zinc Tablet"<<"		Taka 5.00"<<endl;
                cout<<"                   0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    Biocal D"<<"			Taka 285.00"<<endl;
                cout<<"                   0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    Pantonix(40mg)"<<"	        Taka 9.55"<<endl;
                cout<<"                   0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    Royal Propollen"<<"		Taka 450.00"<<endl;
                cout<<"               "<<endl;

	temp = new node;
	cout <<"Type Order no: ";
    cin >> temp->reciept_number;
	cout<<"Enter Customer Name: ";
	cin>> temp->customerName;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout <<"How many Medicine would you like to order:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout <<" " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout <<"The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{

		cout <<"Please enter your selection : "<<endl;
		cin>> temp->menu2[i];
        cout<<"Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout <<"How many medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout <<"The amount You need to pay is: " << temp->amount[i]<<" Taka"<<endl;
        system("PAUSE");

	}
	cout<<"==========================================================================="<<endl;
    cout << "Order Taken Successfully"<<endl;
    cout<<"==========================================================================="<<endl;
    cout << "Go to Receipt Menu to Pay The Bill"<<endl;
    cout<<"==========================================================================="<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("cls");
    }
}


void pharmacyManagementSystem::order_list()
{
    int i, num, num2;
	bool found;
	system("cls");
	node *temp;

	temp=start_ptr;
	found = false;

	cout<<" Enter the Receipt Number To Print The Receipt\n";
	cin>>num2;
	cout<<"\n";
	cout<<"==========================================================================="<<endl;
	cout <<"\t\tHere is the Order list\n";
	cout<<"==========================================================================="<<endl;


	if(temp == NULL)
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)
        {
		cout <<"Receipt Number : "<<temp->reciept_number;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->customerName<<endl;

		cout<<"Order Date : "<<temp->date<<endl;

		cout<<"_____________________________________________________________________________"<<endl;

		cout << "===============================================================================" << endl;
		cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price  |" << endl;
		cout << "=========++==================++===================++=================++========" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout << temp->type <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" Taka"<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}

		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"Total Bill is : "<<temp->total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> num;
        if (num<temp->total)
        {
            do
        {

            cout<<"This is not enough! Please type the exact amount!"<<endl;
            cin>>num;
        }
        while(num!=temp->total);
        cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done\nThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
        }
        else
        {
		cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done\nThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
		}


    }
}
}

void pharmacyManagementSystem::delete_order()
{
    system("cls");
	int i, num, count;
            cout<<"                                     +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
            cout<<"                                     |S|W|I|F|T| |M|E|D|A|C|C|E|S|S|+|                   \n";
            cout<<"                                     +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
            cout<<"                              ================================================"<<endl;
    cout<<"                                 Enter the Order Number you want to delete: ";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"                                    Can not delete from an empty list.\n";
	else
	{
		if(start_ptr->reciept_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"                                 The Order is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;

		while((!found) && (q != NULL))
		{
  			if(q->reciept_number != num)
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q)
				last = temp;
				delete q;
				cout<<"                           The Receipt is Deleted Successfully"<<endl;
			}
			else
				cout<<"                             Item to be deleted is not in the list."<<endl;
			}
		}
}

void pharmacyManagementSystem::modify()
{
    system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = start_ptr;
            cout<<"                                     +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
            cout<<"                                     |S|W|I|F|T| |M|E|D|A|C|C|E|S|S|+|                   \n";
            cout<<"                                     +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
            cout<<"                              ================================================"<<endl;
 cout<<"                                      Enter Order Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"                                   NO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "Change  Order Number: ";
    cin >> temp->reciept_number;
	cout<< "Change Customer Name: ";
	cin>> temp->customerName;
	cout<<"Change Date : ";
	cin>>temp->date;
	cout << "How many New Medicine would you like to Change:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << " " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{

		cout << "Please enter your selection to Change: "<<endl;
		cin>> temp->menu2[i];
        cout<< "Change Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many New medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<" Rupe"<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");

	}

 cout<<"RECORD MODIFIED....!"<<endl;
 }
 else
 {
 	if(temp != NULL && temp->reciept_number != sid)
 	{
 	cout<<"Invalid Reciept Number...!"<<endl;
    }
 }
}
}
}


void pharmacyManagementSystem::daily_summary()
{
    int i,num;
	system("cls");
	node *temp ;

	temp=start_ptr;


	if(temp == NULL)
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"==========================================================================="<<endl;

		while(temp!=NULL)

		{


		    	ofstream fout;
	char fname[20];
	char rec[80];

	cout<<"Enter a unique file name: ";
	cin>>fname;

	fout.open(fname, ios::app);






				cout <<"Receipt Number : "<<temp->reciept_number;
				cout <<"\n";
				cout<<"Customer Name: "<<temp->customerName<<endl;

				cout<<"Order Date : "<<temp->date<<endl;

				cout<<"____________________________________________________________________________"<<endl;

				cout << "==========================================================================" << endl;
				cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "=======++==================++================++===============++==========" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout << temp->type <<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" Taka"<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}

			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			cout<<"Total Bill is : "<<temp->total;

			cout <<"\n";
			cout <<"\n";
			cout <<"\n_______________________________________________________________________________\n";


			fout <<"Receipt Number : "<<temp->reciept_number;
				fout <<"\n";
				fout<<"Customer Name: "<<temp->customerName<<endl;

				fout<<"Order Date : "<<temp->date<<endl;
				fout <<"\n";
				fout<<"Total Bill is : "<<temp->total;
				temp=temp->next;
                cout<<"Data inserted successfully..!!";
                fout.close();
		}

	}
}



void Type(const char *p)
{
    if (NULL == p)
        return;

    while (*p)
    {
        printf("%c\xDB", *p++);
        ::Sleep(1);
        printf("\b \b");
        ::Sleep(1);
    }
    ::Sleep(1);
}









int main()
{
    int choice;
    SetConsoleTextAttribute(h,11);
    Type("\n\t\t\t\t\t      Welcome to our Project \n");
    Type("\t\t\t\t\t+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+\n");
    Type("\t\t\t\t\t|S|W|I|F|T| |M|E|D|A|C|C|E|S|S|+|\n");
    Type("\t\t\t\t\t+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+\n");
    Type("\t\t\t\t================================================\n");
    Type("\t\t\t\t================================================\n\n");
    Type("\t\t\t\t------------------------------------------------\n");
    Type("\t\t\t\t||     Project By: \t\t\t      ||\n");
    Type("\t\t\t\t||    +CHINMOY | ANSAR | SHUVRO | ABDULLAH+   ||\n");
    Type("\t\t\t\t------------------------------------------------\n");
    Type("\t\t\t\t================================================\n");
    system("PAUSE");
    system("CLS");
    cout<<"                    ***********************************************************************\n";
    cout<<"                                       +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
    cout<<"                                       |S|W|I|F|T| |M|E|D|A|C|C|E|S|S|+|                   \n";
    cout<<"                                       +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
    cout<<"                    ***********************       Admin Portal       **********************\n";
    cout<<"                                          ---------------------------\n\n";
    cout<<"                                         ||       1.LOGIN\n"<<endl;
    cout<<"                                         ||    2.ADD NEW ADMIN\n"<<endl;
    cout<<"                                         ||  3.FORGOT PASSWORD (or) USERNAME\n"<<endl;
    cout<<"                                         ||        4.Exit\n"<<endl;
    cout<<"                                           ---------------------------\n";
    cout<<"                                             Enter your choice :";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        AdminPortal();
        break;
    case 3:

        forgot();
        break;
        case 4:

        cout<<"Thanks for using this program";
        break;
    default:
        system("cls");
        cout<<"You've made a mistake , Try again..\n"<<endl;
        main();
    }
    getch();
}
void login()
{
    int count;
    string user,pass,u,p;
    system("cls");
    cout<<"                    ***********************************************************************\n";
    cout<<"                                        +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
    cout<<"                                        |S|W|I|F|T| |M|E|D|A|C|C|E|S|S|+|                   \n";
    cout<<"                                        +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
    cout<<"                    ***********************       Admin Portal       **********************\n";
    cout<<"                                          ---------------------------\n\n";
    cout<<"                                       Please enter the following details-\n"<<endl;
    cout<<"                                                 USERNAME/EMAIL :";
    cin>>user;
    cout<<"                                                 PASSWORD :";
    cin>>pass;

    ifstream input("database.txt");
    while(input>>u>>p)
    {
        if(u==user && p==pass)

        {
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {
        SetConsoleTextAttribute(h,11);
        Type("\t\t\t  ===========================LOADING===============================\n");
        Type("\t\t\t  =========================PLEASE WAIT=============================\n");
        Type("\t\t\t  =====================SETTING UP SOFTWARE=========================\n");
        SetConsoleTextAttribute(h,11);
        cout<<"\n\t\t\t\t\t\t  Hello "<<user<<"\n\t\t\t\t\t\t  <LOGIN SUCCESSFUL>\n\t\t\t\t\t\t  Thanks for logging in..\n";
        system("PAUSE");
        system("cls");
        pharmacyManagementSystem pharmacyManagementSystemObj;
        pharmacyManagementSystemObj.mainMenu();


    }
    else
    {
        cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
        system("PAUSE");
        login();
    }
}

void registr()
{

    string reguser,regpass,ru,rp;
    system("cls");
    SetConsoleTextAttribute(h,11);
    cout<<"                    ***********************************************************************\n";
    cout<<"                                        +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
    cout<<"                                        |S|W|I|F|T| |M|E|D|A|C|C|E|S|S|+|                   \n";
    cout<<"                                        +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
    cout<<"                    ***********************       Admin Portal       **********************\n";
    cout<<"                                          ---------------------------\n\n";
    cout<<"                                       Please enter the following details-\n"<<endl;
    cout<<"                                            ENTER NEW USERNAME/EMAIL :";
    cin>>reguser;
    cout<<"                                            ENTER NEW PASSWORD :";
    cin>>regpass;

    ofstream reg("database.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"\nRegistration Successful\n";



}

void AdminPortal()
 {
    int choice;
    SetConsoleTextAttribute(h,11);
    cout<<"                    ***********************************************************************\n";
    cout<<"                                       +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
    cout<<"                                       |S|W|I|F|T| |M|E|D|A|C|C|E|S|S|+|                   \n";
    cout<<"                                       +-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+-+                   \n";
    cout<<"                    ***********************       Admin Portal       **********************\n";
    cout<<"                                          ---------------------------\n\n";
    cout<<"                                         ||       1.LOGIN\n"<<endl;
    cout<<"                                         ||    2.ADD NEW ADMIN\n"<<endl;
    cout<<"                                         ||  3.FORGOT PASSWORD (or) USERNAME\n"<<endl;
    cout<<"                                         ||        4.Exit\n"<<endl;
    cout<<"                                           ---------------------------\n";
    cout<<"                                             Enter your choice :";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        AdminPortal();
        break;
    case 3:
        forgot();
        break;
        case 4:
        cout<<"Thanks for using this program";
        break;
    default:
        system("cls");
        cout<<"You've made a mistake , Try again..\n"<<endl;
        AdminPortal();
    }
 }

void forgot()
{
    int ch;
    system("cls");
    cout<<"Forgotten ? We're here for help\n";
    cout<<"1.Search your id by username"<<endl;
    cout<<"2.Search your id by password"<<endl;
    cout<<"3.Main menu"<<endl;
    cout<<"Enter your choice :";
    cin>>ch;
    switch(ch)
    {
    case 1:
    {
        int count=0;
        string searchuser,su,sp;
        cout<<"\nEnter your remembered username :";
        cin>>searchuser;

        ifstream searchu("database.txt");
        while(searchu>>su>>sp)
        {
            if(su==searchuser)
            {
                count=1;
            }
        }
        searchu.close();
        if(count==1)
        {
            cout<<"\n\nHurray, account found\n";
            cout<<"\nYour password is "<<sp;
            cin.get();
            cin.get();
            system("cls");
            AdminPortal();
        }
        else
        {
            cout<<"\nSorry, Your userID is not found in our database\n";
            cout<<"\nPlease kindly contact your system administrator for more details \n";
            cin.get();
            cin.get();
            AdminPortal();
        }
        break;
    }
    case 2:
    {
        int count=0;
        string searchpass,su2,sp2;
        cout<<"\nEnter the remembered password :";
        cin>>searchpass;

        ifstream searchp("database.txt");
        while(searchp>>su2>>sp2)
        {
            if(sp2==searchpass)
            {
                count=1;
            }
        }
        searchp.close();
        if(count==1)
        {
            cout<<"\nYour password is found in the database \n";
            cout<<"\nYour Id is : "<<su2;
            cin.get();
            cin.get();
            system("cls");
            AdminPortal();
        }
        else
        {
            cout<<"Sorry, We cannot found your password in our database \n";
            cout<<"\nkindly contact your administrator for more information\n";
            cin.get();
            cin.get();
            AdminPortal();
        }

        break;
    }

    case 3:
    {
        cin.get();
        AdminPortal();
    }
    default:
        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
        forgot();
    }
}
