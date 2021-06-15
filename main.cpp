#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;

//class define
class contact
{
    long long phn;
    char name[50];
    char add[50];
    char email[50];
    char group[50];
public:
    //define create_contact function
    void create_contact()
    {
        system("color 0b");
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t----------------------------------------------------";
        cout<<"\n\t\t\t\t\t----------------------------------------------------";
        cout<<"\n\t\t\t\t\t **** \t    Contact Management System\t     ****";
        cout<<"\n\t\t\t\t\t----------------------------------------------------";
        cout<<"\n\t\t\t\t\t Enter Name :";

        cin.ignore();
        cin.getline(name,sizeof(name));
        cout<<"\n\t\t\t\t\t Enter Phone Number :";

        cin>>phn;
        cout<<"\n\t\t\t\t\t Enter  City:";

        cin.ignore();
        cin.getline(add,sizeof(add));
        cout<<"\n\t\t\t\t\t Enter Enter Email :";

        cin.ignore();
        cin.getline(email,sizeof(email));
        cout<<"\n\t\t\t\t\t Enter Enter Group :";

        cin.ignore();
        cin.getline(group,sizeof(group));
    };
    //define show_contact function
    void show_contact()
    {

        cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t----------------------------------------------------";
        cout<<"\n\t\t\t\t\t----------------------------------------------------";
        cout<<"\n\t\t\t\t\t **** \t    \t\tContact \t \t****";
        cout<<"\n\t\t\t\t\t----------------------------------------------------";
        cout<<"\n\t\t\t\t\tName : "<<name<<endl;
        cout<<"\n\t\t\t\t\tPhone Number : "<<phn<<endl;
        cout<<"\n\t\t\t\t\tAddress : "<<add<<endl;
        cout<<"\n\t\t\t\t\tEmail : "<<email<<endl;
        cout<<"\n\t\t\t\t\tGroup : "<<group<<endl;

    };

    long long get_num()
    {
        return phn;
    };

    char* get_name()
    {
        return name;
    };

    char* get_add()
    {
        return add;
    };

    char* get_email()
    {
        return email;
    };

    char* get_group()
    {
        return group;
    };
};


fstream fp;
contact con;

//define add_contact function
void add_contact()
{
    cout<<"Enter Your Contact Details"<<endl;
    con.create_contact();
    fp.open("contactBook.txt",ios::app);
    fp.write((char*)&con,sizeof(contact));
    fp.close();
    cout<<"Your Contact "<<con.get_name()<<" Details has been saved!"<<endl;
    getchar();
}

//define display_allcontact function
void display_allcontact()
{
    system("cls");
    fp.open("contactBook.txt", ios::in);
    cout<<"\t\t\t\t\tYour Contact Details:::"<<endl;
    while(fp.read((char*)&con, sizeof(contact)))
    {
        con.show_contact();
        cout<<"\n\t\t\t\t\t----------------------------------------------------"<<endl;

    }
    getchar();
    fp.close();
    getchar();
}

//define display_contactByNum function
void display_contactByNum()
{
    system("cls");
    long long num;
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\t **** \t    \t\tSEARCH \t \t****";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\tSearch Input(num): ";
    cin>>num;
    cout<<"\n\t\t\t\t\tYour Contact Details!"<<endl;
    fp.open("contactBook.txt",ios::in);
    bool found = false;
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&con, sizeof(contact)))
    {
        if(con.get_num() == num)
        {
            con.show_contact();
            cout<<"\n\t\t\t\t\t----------------------------------------------------"<<endl;
            found =true;
            getchar();
        }
    }

    if(found ==false)
    {
        cout<<"\n\t\t\t\t\tYour Contact Details Not Available!"<<endl;
        getchar();
    }
    fp.close();
    getchar();
}



//define del_contactByNum function
void del_contactByNum()
{
    system("cls");
    long long num;
    bool found = false;
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\t **** \t    \t\tDELETE \t \t****";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\tEnter Input(num)to Delete Number: ";
    cin>>num;
    fp.open("contactBook.txt",ios::in | ios::out);
    fp.seekg(0,ios::beg);
    fstream fp1;
    fp1.open("temp.txt",ios::out);
    while(fp.read((char*) &con,sizeof(contact)))
    {
        if(con.get_num() != num)
        {
            fp1.write((char*) &con,sizeof(contact));

        }

        else
        {
            found =true;
        }
    }

    if(found ==false)
    {
        cout<<"\n\t\t\t\t\tYour Contact Details Not Available!"<<endl;
        getchar();
    }
    else
    {
        cout<<"\n\t\t\t\t\tYour Contact Details DELETED!"<<endl;
        getchar();
    }

    fp1.close();
    fp.close();
    remove("contactBook.txt");
    rename("temp.txt","contactBook.txt");
    getchar();

}


//define edit_contact function
void edit_contact()
{
    system("cls");
    long long num;
    bool found = false;
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\t **** \t    \t\tEDIT\t \t****";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\tEnter Input(num)to EDIT Number: ";
    cin>>num;
    fp.open("contactBook.txt",ios::in | ios::out);
    fp.seekg(0,ios::beg);
    fstream fp1;
    fp1.open("temp.txt",ios::out);
    while(fp.read((char*) &con,sizeof(contact)))
    {
        if(con.get_num() == num)
        {
            contact c1;
            c1.create_contact();
            fp1.write((char*) &c1,sizeof(contact));
            found =true;
        }
        else

        {
          fp1.write((char*) &con,sizeof(contact));

        }
    }

    if(found ==false)
    {
        cout<<"\n\t\t\t\t\tYour Contact Details Not Available!"<<endl;
        getchar();
    }

    fp1.close();
    fp.close();
    remove("contactBook.txt");
    rename("temp.txt","contactBook.txt");
    cout<<"\n\t\t\t\t\tYour Contact Details EDITED!"<<endl;
    getchar();
}


//define start function
void start()
{
    system("color 0B");
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t\t Contact management system...";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\tLOADING...";
    char x=219;

    for(int i=0;i<35;i++)
    {
        cout<<x;
        if(i<10)
        {
            Sleep(300);
        }
        else if(i>=10 && i<=20)
        {
            Sleep(150);
        }
        else
        {
            Sleep(25);
        }
    }
    system("cls");
}


//define End function
void End()
{
    system("cls");
    system("color 0B");
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\t Thank you for using Contact management system...";
    cout<<"\n\t\t\t\t\t----------------------------------------------------";
    cout<<"\n\t\t\t\t\tCLOSEING...";
    char x=219;

    for(int i=0;i<35;i++)
    {
        cout<<x;
        if(i<10)
        {
            Sleep(300);
        }
        else if(i>=10 && i<=20)
        {
            Sleep(150);
        }
        else
        {
            Sleep(25);
        }
    }
    system("cls");
}

//define main function
int main()
{
    start();
    int ch;
    do{



		system("cls");
		system("color 0b");
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\n\t\t\t\t\t----------------------------------------------------";
        cout<<"\n\t\t\t\t\t----------------------------------------------------";
        cout<<"\n\t\t\t\t\t **** Welcome to Contact Management System ****";
        cout<<"\n\t\t\t\t\t----------------------------------------------------";
        cout<<"\n\t\t\t\t\t|\t\t [1] Add a new Contact\t\t   |";
        cout<<"\n\t\t\t\t\t|\t\t [2] List all Contacts\t\t   |";
        cout<<"\n\t\t\t\t\t|\t\t [3] Search contact \t\t   |";
        cout<<"\n\t\t\t\t\t|\t\t [4] Edit Contact \t\t   |";
        cout<<"\n\t\t\t\t\t|\t\t [5] Delete Contact\t\t   |";
        cout<<"\n\t\t\t\t\t|\t\t [0] Exit\t\t\t   |";
        cout<<"\n\t\t\t\t\t----------------------------------------------------\n";
		cout<<"\n\t\t\t\t\t\t\t Enter the choice:";
        cin>>ch;

        //define switch case
		switch(ch)
		{
			case 0:
			    {
			        cout<<"\n\t\t\t\t\tThank you for using Contact management system...";
			        End();
			        exit(1);
                    break;
			    }


			case 1:
			    {
			        add_contact();
                    break;
                }

			case 2:

			    {
			        display_allcontact();
                    break;
			    }
			case 3:
				{
				    display_contactByNum();
                    break;
				}

			case 4:
			    {
			        edit_contact();
                    break;
			    }

			case 5:
			    {
			        del_contactByNum();
                    break;
                }




			default:
			    {
                    break;
			    }


    }

    }while(ch != 0);

    return 0;
}
