#include<iostream>
#include<sstream>
#include<string.h>
#include<ctype.h>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

char const *pass= "hehe";

struct patient
{
    long long ID;
    const char *password;
	std :: string firstname, user;
	std :: string lastname;
	int age, count = 1, ch;
	char blood[5];
	char gender;
    patient*next;
};
class linkedqueue
{
	patient *head,*last;
	public:
	linkedqueue() //constructor
	{
		head=NULL;
		last=NULL;
	}
    patient input();
    void login();
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void listofpatients();
    int search(int);
    char departmentname[50];
};

void login(){
    patient *p=new patient();
    std :: cout << "Login to te depament!\n";
    std :: cout << "Enter user name: ";
    std :: cin >> p->user ;
    while (p->count < 5){
        std :: cout << "\n";
        p->password = getpass("Enter password: ");
        
        std :: cout << "\n";
        if (strcmp(p->password,pass)==0){
            std :: cout << "login successful";
            std :: cout << "Please wait ";
            for (int i = 0; i<3; i++){
                std :: cout << ".";
                sleep(4);
            }
            break;
        }
         else
        {
            std :: cout << "Invalid password. Please try again.\n" << '\n';
            p->count++;
        }
    }
    if (p->count++ == 5)
    {
        std :: cout << "Too many login attempts! The program will be exit.";
        exit(0);
    }

    std :: cout << "Thank you for login.\n";
}

int linkedqueue :: search(int item)
{
    if(head==NULL)
    return false;
    else
    {
    int flag=0;
    patient*p=new patient();
    p=head;

    while( p->next!=NULL && p->ID!=item )
    {
    p=p->next;
    }
    if(p->ID==item)
    {
    flag=1;
    return true;
    }
    if(flag==0)
    return false;
    }return 0;
}



int readnumber()
{
   char b[20];
   std :: cin.getline(b, sizeof(b));
   return atoi(b);
}

patient linkedqueue :: input()
{
    std :: fstream fout;
    std :: string name;

	// opens an existing csv file or creates a new file.
	fout.open("data.csv",std :: ios::out | std :: ios::app);

    int flag=0;
   patient *p=new patient();
   std :: cout << "\n   Please enter data for patient\n";
   std :: cout<<"\n   First name     : ";
   std :: cin >> p->firstname;
   std :: cout << "   Last name      : ";
   std :: cin >> p->lastname;
   name = p->firstname + " " + p->lastname;
   again :
   std :: cout << "   Blood Group    : ";
   std :: cin >> p->blood;
   if((strcmp(p->blood,"A+")==0)||(strcmp(p->blood,"a+")==0)||(strcmp(p->blood,"A-")==0)||(strcmp(p->blood,"a-")==0)||
      (strcmp(p->blood,"B+")==0)||(strcmp(p->blood,"b+")==0)||(strcmp(p->blood,"B-")==0)||(strcmp(p->blood,"b-")==0)||
      (strcmp(p->blood,"O+")==0)||(strcmp(p->blood,"o+")==0)||(strcmp(p->blood,"O-")==0)||(strcmp(p->blood,"o-")==0)||
      (strcmp(p->blood,"AB+")==0)||(strcmp(p->blood,"ab+")==0)||(strcmp(p->blood,"AB-")==0)||(strcmp(p->blood,"ab-")==0))
             flag=1;
    if(flag==0)
    {
        std :: cout<<"\n   Invalid Blood Group Try Again..\n\n";
        goto again;

    }
   std :: cout<<"   Gender(m/f)    : ";
   std :: cin>>p->gender;
   std :: cout<<"   Age            : ";
   std :: cin>>p->age;
   std :: cout<<"   Mobile number  : ";
   std :: cin>>p->ID;
   std :: cout << "Name" << "\t" << "Blood" << "\t" << "Gender" << "\t" << "Age" << "\t" << "Mobile Number";
   fout << p->firstname<<" " << p->lastname<<"\t" << p->blood << "\t" << p->gender << "\t" << p->age << "\t" << p->ID;


	if(search(p->ID))
	{
		p->ID=0;
		std :: cout << "\n   Data not valid. Operation cancelled.";
	}
	return *p;
}

void output(patient *p)
{
    int a =178;
    char ch = a;
	std :: cout << "\n";
    for(int i=0; i < 38; i++){
        std :: cout << ch;
    }
    std :: cout<<"\n   Patient data:\n";
	std :: cout<<"\n   First Name         : "<<p->firstname;
	std :: cout<<"\n   Last Name          : "<<p->lastname;
	std :: cout<<"\n   Gender             : "<<p->gender;
	std :: cout<<"\n   Age                : "<<p->age;
	std :: cout<<"\n   Blood Group        : "<<p->blood;
	std :: cout<<"\n   Mobile Number      : "<<p->ID;
	std :: cout << "\n";
    for(int i=0; i < 38; i++){
        std :: cout << ch;
    }
}
void linkedqueue :: insertatbeg()
{
     patient*p=new patient();
     *p=input();
     if(p->ID==0)
     return;

     if(head==NULL)

     {
         head=p;
         last=p;
         p->next=NULL;
     }
     else
     {
        p->next=head;
        head=p;
     }
     system("clear");
     std :: cout << "\n\tPatient added:";
     output(p);
}
void linkedqueue:: insertatend()
{
    int ascii = 178;
    char ch = ascii;
    patient*p=new patient();
    *p=input();
    if(p->ID==0)
    return;

    if(head==NULL)
    {
    head=p;
    last=p;
    p->next=NULL;
    }
    else
    {
    p->next=NULL;
    last->next=p;
    last=p;
    }
    system("clear");
    std :: cout << "\n";
    for(int i=0; i < 38; i++){
        std :: cout << ch;
    }
    std :: cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    std :: cout << "\n";
    for(int i=0; i < 38; i++){
        std :: cout << ch;
    }
    std :: cout <<"\n  ----------PATIENT ADDED-----------";
    output(p);
}
void linkedqueue :: getpatientout()
{
	 system("clear");
     if(head==NULL)
     {
     	std :: cout<<"\n  No Patient to operate";
     }
     else
     {
     	patient*p=new patient();
     	p=head;
     	head=head->next;
 	    std :: cout << "\n  Patient to operate:";
        output(p);
 	 }
}

void linkedqueue :: listofpatients()
{
    std :: fstream fin;
    fin.open("data.csv", std :: ios::in);
    int ascii = 178;
    char ch = ascii;
    if(head==NULL)
    {
    std :: cout<<"\n  No patient";
    }
    system("clear");
    std :: cout << "\n";
    for(int i=0; i < 38; i++){
        std :: cout << ch;
    }
    std :: cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    std :: cout << "\n";
    for(int i=0; i < 38; i++){
        std :: cout << ch;
    }
    patient*p=new patient;
    p=head;
    while(p!=NULL)
    {
    std :: cout<<"\n   Patient data:\n";
    std :: cout<<"\n   First Name       : "<<p->firstname;
    std :: cout<<"\n   Last Name        : "<<p->lastname;
    std :: cout<<"\n   Gender           : "<<p->gender;
    std :: cout<<"\n   Age              : "<<p->age;
    std :: cout<<"\n   Blood Group      : "<<p->blood;
    std :: cout<<"\n   Mobile Number    : "<<p->ID;
    std :: cout << "\n";
    for(int i=0; i < 38; i++){
        std :: cout << ch;
    }
    p=p->next;
    }
    std :: cout<<"\n";
}


void departmentmenu (linkedqueue * q)
{
    int a = 178;
    char ch = a;
    int choice = 0;
    patient p;
    while (choice != 5)
	{
    std :: cout << "\n";
    for(int i=0; i < 38; i++){
        std :: cout << ch;
    }
    std :: cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
    std :: cout << "\n";
    for(int i=0; i < 38; i++){
        std :: cout << ch;
    }
    std :: cout<<"\n\n   "<<q->departmentname;
	std :: cout<<"\n   [1] Add normal patient\n";
	std :: cout<<"   [2] Add critically ill patient\n";
	std :: cout<<"   [3] Take patient to Doctor\n";
	std :: cout<<"   [4] Display list\n";
	std :: cout<<"   [5] Change department or exit\n";
	std :: cout<<"\n   Please enter your choice : ";
	choice=readnumber();
	std :: cout << "\n";
    for(int i=0; i < 38; i++){
        std :: cout << a;
    }
    switch (choice)
	{
	  case 1:	q->insertatend();
				std :: cout << "\n   Press any key";
	    		getchar();
	 			break;

      case 2:	q->insertatbeg();
	    		std :: cout << "\n   Press any key";
	    		getchar();
				break;

      case 3:	q->getpatientout();
	 			std :: cout<<"\n   Press any key";
     			getchar();
	      		break;

      case 4:	system("clear");
	 			q->listofpatients();
	 			std :: cout<<"\n   Press any key";
	 			getchar();
				break;
	 }
    }
}

int main ()
{
    login();
    int ascii = 178;
    char ch = ascii;
    int i, choice = 0;
	linkedqueue departments[4];
	while(choice!=5)
	{
		strcpy(departments[0].departmentname,"GENERAL CLINIC\n");
		strcpy(departments[1].departmentname,"HEART CLINIC\n");
		strcpy(departments[2].departmentname,"LUNG CLINIC\n");
		strcpy(departments[3].departmentname,"PLASTIC SURGERY\n");
		std :: cout<<"\n";
        for(int i=0; i < 38; i++){
            std :: cout << ch;
        }
		std :: cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
		std :: cout<<"\n";
        for(int i=0; i < 38; i++){
            std :: cout << ch;
        }
        std :: cout<<"\n\n   Main Menu\n\n";
		for (i = 0; i < 4; i++)
		{
			std :: cout<<"   "<<(i+1)<<": "<<departments[i].departmentname;
		}
		std :: cout<<"   5: Exit";
		std :: cout<<"\n\n   Please enter your choice : ";
		choice=readnumber();
		if(choice>=1 && choice<=4)
		{
			departmentmenu(&departments[choice-1]);
		}

	}
	if(choice==5)
	std :: cout<<"\n\t\tThank you! \n";
	exit(0);
}

