/*#include<iostream>
#include<sstream>
#include<string.h>
#include<ctype.h>
#include<fstream>
#include<stdlib.h>
//lib for login feature unistd.h available in Linux
//#include<time.h>
//#include<unistd.h>
*/
#include <windows.h>
#include <bits/stdc++.h>


//char const *pass= "password";

struct patient
{
    std :: string  fullname, hometown/*, user, pass*/;
	int age, count = 1, blood_presure, heart_beat, ID, d, m, y;
    float temp;
    bool death, rash;
	char gender, choice;
    patient*next;
};
class linkedqueue
{
	patient *head,*last;
	public:
	linkedqueue()
	{
		head=NULL;
		last=NULL;
	}
    patient input();
    void searchbyID();
    void searchbyID(int ID);
    void searchbyname();
    void searchmethod();
    void insertatend();
    void insertatfirst();
    void getpatientout();
    void waitingpatient();
    void listofpatients();
    int search(int);
};



//using linux to use login feature
/*void login();
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
}*/


int readnumber()
{
    int num;
    std::string input;
    while (true)
    {
        std::cout << "Please enter the ID: ";
        std::getline(std::cin, input);
        try
        {
            num = std::stoi(input);
            if (num > 0)
            {
                break;
            }
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Invalid input. Please enter a positive integer." << std::endl;
        }
    }
    return num;
}


void beauty(){
    int a = 176;
    char ch = a;
    std::cout << "\n";
    for(int i = 0; i < 38; i++){
        std::cout << ch;
    }std::cout << "\n";
}


void linkedqueue:: searchbyID(int num){
    num = readnumber();
    std::ifstream ip("DATAFULL.csv");
    std::string line;
    bool found = false;
    while (std::getline(ip, line))
    {
        std::istringstream iss(line);
        std::string id, name, birthday, country;

        if (std::getline(iss, id, ',') &&
            std::getline(iss, name, ',') &&
            std::getline(iss, birthday, ',')&&
            std::getline(iss, country))
        {
            char *endp = nullptr;
            int n = std::strtol(id.c_str(), &endp, 10);
            if (id.c_str() != endp && n == num)
            {
                std::cout << "The patient is: " << line;
                Sleep(3);
                found = true;
            }
        }
    }
    if (!found) {
        std::cout << "No patients in history found with ID: " << num << '\n';
    }
}



void searchbyname()
{
    patient*p=new patient();
    std::ifstream file("DATAFULL.csv");
    std::string name;
    std::string line;
    std::cout << "Enter the name of the patient: ";
    std::getline(std::cin, name);
    transform(name.begin(), name.end(), name.begin(), toupper);
    std::vector<std::string> matches;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string id, patient_name, birthday, country;
        if (std::getline(iss, id, ',') &&
            std::getline(iss, patient_name, ',') &&
            std::getline(iss, birthday, ',') &&
            std::getline(iss, country))
        {
            if (patient_name == name)
            {
                matches.push_back(line);
            }
        }
    }
    if (matches.empty())
    {
        std::cout << "No patients found with name: " << name << '\n';
    }
    else
    {
        std::cout << "The following patients were found with name: " << name << '\n';
        for (const auto& match : matches)
        {
            std::cout << match << '\n';
        }
        std :: cout << "\nDo you want to search more(Y/N): ";
        std :: cin >> p->choice;
        if(p->choice == 'y'|| p->choice == 'Y')
        {searchbyname();}
        else
        return;
    }
}

/*
void linkedqueue:: searchbyname() {
    patient*p=new patient();
    std :: cout << "\nThe name of patient: ";
    std::string name;
    getline(std :: cin, name);
    std::ifstream ip("DATAFULL.csv");
    std::string line;
    bool found = false;
    while (std::getline(ip, line))
    {
        std::istringstream iss(line);
        std::string id, patient_name, birthday, country;

        if (std::getline(iss, id, ',') &&
            std::getline(iss, patient_name, ',') &&
            std::getline(iss, birthday, ',')&&
            std::getline(iss, country))
        {
            char *endp = nullptr;
            if (name.c_str() != endp && name == patient_name)
            {
                std::cout << "The patient with the name: " << line;
                Sleep(3);
                std :: cout << "\nDo you want to search more(Y/N): ";
                std :: cin >> p->choice;
                if(p->choice == 'y'|| p->choice == 'Y')
                {searchbyname();}
                else
                found = true;
                break;
            }
        }
    }
    if (!found) {
        std::cout << "No patients found with name: " << name << '\n';
    }
}*/





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





patient linkedqueue :: input()
{
    std :: fstream fout;
    std :: string name;

	// opens an existing csv file or creates a new file.
	fout.open("DATAFULL.csv",std :: ios::out | std :: ios::app);

    int flag=0;
   patient *p=new patient();
   std :: cout << "\n   Please enter data for patient\n";
   p->ID = readnumber();
   searchbyID(p->ID);
   std :: cout <<"\n   Date of hospitalization     : ";
   std :: time_t t = std::time(0);   
   std :: tm* now = std::localtime(&t);
   std :: string Date_of_hospitalization = std::to_string(now->tm_mday)+"/" + std::to_string(now->tm_mon)+"/" + std::to_string(now->tm_year + 1900);
   std :: cout << Date_of_hospitalization;
   std :: cout <<"\n   Full name     : ";
   std :: getline (std :: cin, p->fullname);
   std :: cout<<"   Gender(m/f)    : ";
   std :: cin>>p->gender;
   std :: cout << "   DoB(dd/mm/yyyy)    : ";std :: cin >> p->d; std :: cin >> p->m ; std :: cin>> p->y;
   std :: string dob  = std::to_string(p->d)+"/" + std::to_string(p->m)+"/" + std::to_string(p->y);
   std :: cout << dob;
   std :: cout<<"\n   Age            : ";
   p->age = (now->tm_year + 1900) - p->y;
   std :: cout << p->age;
   std :: cout<<"\n   Hometown  : ";
   std :: cin.ignore();
   std :: getline(std::cin, p->hometown);
   //fout << p->ID <<"," << p->name <<"," << p->blood << "," << p->gender << "," << p->age << "," << p->phone << "\n";


	if(search(p->ID))
	{
		p->ID=0;
		std :: cout << "\n   Data not valid. Operation cancelled.";
	}
	return *p;
}



void output(patient *p)
{
    beauty();
    std :: cout<<"\n   Patient data:\n";
    std :: cout<<"\n   ID         : "<<p->ID;
	std :: cout<<"\n   Full Name          : "<<p->fullname;
	std :: cout<<"\n   Gender             : "<<p->gender;
	std :: cout<<"\n   Age                : "<<p->age;
	std :: cout<<"\n   Hometown           : "<<p->hometown;
	//std :: cout<<"\n   Mobile Number      : "<<p->phone;
	beauty();
}


void linkedqueue :: insertatfirst()
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
     system("cls");
     std :: cout << "\n\tPatient added:";
     output(p);
}
void linkedqueue:: insertatend()
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
    p->next=NULL;
    last->next=p;
    last=p;
    }
    system("cls");
    beauty();
    std :: cout<<"\n  |-- HONGNGOC MANAGEMENT SYSTEM --|";
    beauty();
    std :: cout <<"\n  ----------PATIENT ADDED-----------";
    output(p);
}



void linkedqueue :: getpatientout()
{
	 system("cls");
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

void linkedqueue :: waitingpatient()
{
     if(head==NULL)
     {
     	std :: cout<<"\n  No Patient is waiting";
     }
     else
     {
     	patient*p=new patient();
     	p=head;
     	head=head->next;
 	    std :: cout << "\n  Waiting patient is:" << p->fullname;
 	 }
}


void linkedqueue :: listofpatients()
{
    std :: fstream fin;
    fin.open("DATAFULL.csv", std :: ios::in);
    if(head==NULL)
    {
    std :: cout<<"\n  No patient";
    }
    system("cls");
    beauty();
    std :: cout<<"\n  |-- HONGNGOC MANAGEMENT SYSTEM --|";
    beauty();
    patient*p=new patient;
    p=head;
    while(p!=NULL)
    {
    std :: cout<<"\n   Patient data:\n";
    std :: cout<<"\n   ID         : "<<p->ID;
	std :: cout<<"\n   Full Name          : "<<p->fullname;
	std :: cout<<"\n   Gender             : "<<p->gender;
	std :: cout<<"\n   Age                : "<<p->age;
	std :: cout<<"\n   Hometown           : "<<p->hometown;
	//std :: cout<<"\n   Mobile Number      : "<<p->phone;
    beauty();
    p=p->next;
    }
    std :: cout<<"\n";
}


void linkedqueue :: searchmethod(){
    linkedqueue * q;
    std :: cout << "\nDo you want to search by ID or name: ";
    std :: string choice;
    getline(std :: cin, choice);
    if(choice== "ID"||choice== "Id"||choice== "id")
    {
        q->searchbyID();
    }else q->searchbyname();
}




int readnum()
{
   char b[20];
   std :: cin.getline(b, sizeof(b));
   return atoi(b);
}


int main ()
{
    linkedqueue * q;
    int choice = 0, success;
    patient p;
    while (choice != 6)
	{
    beauty();
    std ::cout<<"\n  |-- HONGNGOC MANAGEMENT SYSTEM --|";
    beauty();
    
	std ::cout<<"\n   [1] Add normal patient\n";
	std ::cout<<"   [2] Add emergency patient\n";
	std ::cout<<"   [3] Patient to Doctor\n";
	std ::cout<<"   [4] Display patients are waiting\n";
	std ::cout<<"   [5] Search patient profile\n";
    std ::cout<<"   [6] Exit\n";
	std ::cout<<"\n   Please enter your choice : ";
	choice=readnum();
	beauty();
    switch (choice)
	{
	  case 1:	q->insertatend();
				std :: cout << "\n   Press any key";
	    		getchar();
	 			break;

      case 2:	q->insertatfirst();
	    		std :: cout << "\n   Press any key";
	    		getchar();
				break;

      case 3:	q->getpatientout();
	 	std :: cout<<"\n   Press any key";
     		getchar();
	      	break;

      case 4:	system("cls");
	 			q->listofpatients();
	 			std :: cout<<"\n   Press any key";
	 			getchar();
				break;
      case 5:   q->searchmethod();
                std :: cout<<"\n   Press any key";
                getchar();
                break;
	 }
    }
	if(choice==6)
	std ::cout<<"\n\t\tThank you! \n";
	exit(0);
}
