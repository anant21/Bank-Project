//                              *^*^*^*^*
//                               PROJECT
//                              *^*^*^*^*

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<fstream.h>
#include<string.h>
#include<dos.h>
#include<time.h>
#define TAB 9
#define ENTER 13
#define BKSP 8
#define SPACE 32

ofstream fout;    //To open the file in write mode
ifstream fin;     //To open the file in read mode

void user(char []);
void main();
void balance(char []);
class bank                  //Details of the account holder
{
  char ac[15];
  char name[20];
  char fname[20];
  char dob[10];
   int age;
  char city[10];
  char state[20];
  char country[20];
  long pin;
  double mob;
  char email[30];
  char marital[10];
  char pan[10];
  char uid[12];
  char pass[22];
  char ctd[30];

public:
  bank()
  {
   strcpy(ac,NULL);
   strcpy(name,NULL);
   strcpy(fname,NULL);
   strcpy(dob,NULL);
   age=0;
   strcpy(city,NULL);
   strcpy(state,NULL);
   strcpy(country,NULL);
   pin=0;
   mob=0;
   strcpy(email,NULL);
   strcpy(marital,NULL);
   strcpy(pan,NULL);
   strcpy(uid,NULL);
   strcpy(pass,NULL);
   strcpy(ctd,NULL);
  }

  void changepass()           //To change the password
  {
    char pass2[20], ch; int i;
    cout<<"\nNew Password: ";
    //gets(pass);
   while(1){
   ch=getch();
    if(ch==ENTER){
       pass[i]='\0'; break;
      } else if(ch==BKSP){
	if(i>0){
		i--;
		cout<<"\b \b"; //to return cursor
	    }
	} else if(ch==TAB || ch==SPACE){
	continue;
	 } else{
	pass[i]=ch; 	i++;
	cout<<"*";
	}
}

    cout<<"\Re-Enter your Password: ";

while(1){
   ch=getch();
    if(ch==ENTER){
       pass2[i]='\0'; break;
      } else if(ch==BKSP){
	if(i>0){
		i--;
		cout<<"\b \b"; //to return cursor
	    }
	} else if(ch==TAB || ch==SPACE){
	continue;
	 } else{
	pass2[i]=ch; 	i++;
	cout<<"*";
	}
}

    if(strcmp(pass,pass2)==0){
       clrscr();
       cout<<"\t\t\tPassword Changed Successfully!\n";

       getch();
    } else{
	clrscr();
	pass2[20]=NULL;
	cout<<"\n\nPasswords doesn't match\n Please Enter again!\n";
	changepass();
    }


  }

  /*long int account_num(){

    long int max=99999999999,num=0, c=10000000000;

    randomize();
    num = c+ random(max);
    return num;

  } */

  void getdata()      //It accepts the data from the new user
  {
    a:
    clrscr();
    cout<<"\n**Please provide your following details to proceed**\n";
    cout<<"    ------------------------------------------------\n";

    cout<<"\nDesired Account No.(alpha-numeric): ";
    fin.open("bank.txt", ios::binary | ios::in | ios::out);   //Opening the file in read mode to check
    char ac3[15];                                            //if user with entered account number is present
    gets(ac3);
 while(!fin.eof()) {

 fin.read((char *)&b, sizeof(b));

    int s;
    s = strlen(ac3);
    if(s==11 && strcmp(ac3,accn())!=0){

       cout<<"\n\t\tAccount number is valid!";
       cout<<"\n\nRe-Enter Account No.: ";
       gets(ac);
       cout<<"\n\t\t\tProceed!";
       fin.close();
       break;

      }

     else {

       cout<<"\n\t\t\tInvalid format or Number is already taken!";
       strcpy(ac,NULL);
       fin.close();
       getch();
       goto a;
    }
}  //while loop

    cout<<"\nYour Name: ";
    gets(name);

    cout<<"\nFather's Name: ";
    gets(fname);

    cout<<"\nDate of Birth(dd/mm/yyyy): ";
    gets(dob);

    cout<<"\nAge: ";
    cin>>age;

    cout<<"\nCity: ";
    gets(city);

    cout<<"\nState: ";
    gets(state);

    cout<<"\nCountry: ";
    gets(country);

    cout<<"\nPin: ";
    cin>>pin;

    cout<<"\nContact: ";
    cin>>mob;

    cout<<"\nEmail_ID: ";
    gets(email);

    cout<<"\nMarital Status: ";
    gets(marital);

    cout<<"\nPAN Number: ";
    gets(pan);

    cout<<"\nUID Number: ";
    gets(uid);

    p:
    char pass1[22]={NULL};
    char ch;  int i;

   cout<<"\nNew Password: ";

while(1){
  ch=getch();
    if(ch==ENTER){
       pass[i]='\0'; break;
      } else if(ch==BKSP){
	if(i>0){
		i--;
		cout<<"\b \b"; //to return cursor
	    }
	} else if(ch==TAB || ch==SPACE){
	continue;
	 } else{
	pass[i]=ch; 	i++;
	cout<<"*";
	}
}

    cout<<"\n\nRe-Enter your Password: ";

while(1){
   ch=getch();
    if(ch==ENTER){
       pass1[i]='\0'; break;
      } else if(ch==BKSP){
	if(i>0){
		i--;
		cout<<"\b \b"; //to return cursor
	    }
	} else if(ch==TAB || ch==SPACE){
	continue;
	 } else{
	pass1[i]=ch; 	i++;
	cout<<"*";
	}

}
    if(strcmp(pass,pass1)==0){
       clrscr();

       cout<<"\t\t     Registration Successful!\n\n";
       cout<<"\t\t Your Account No. is -> "<<accn();
       cout<<"\n\t\t\t     Thank You!\n";
       getch();
    } else{
	clrscr();
	pass1[22]=NULL;
	cout<<"\n\nPasswords doesn't match\n Please Enter again!\n";
	goto p;
    }

    //TIMESTAMP: It adds the date & time of account creation
    time_t tt;
    struct tm*ti;
    time(&tt);
    ti=localtime(&tt);
    strcpy(ctd,asctime(ti));


    getch();
  }



  void showdata()   //It prints the details of user currently logged in
  { cout<<"\nAccount Number: "<<ac;
    cout<<"\nAccount Holder's Name: "<<name;
    cout<<"\nFather's Name: "<<fname;
    cout<<"\nAge: "<<age;
    cout<<"\nDate of Birth: "<<dob;
    cout<<"\nAddress: "<<city<<", "<<state<<" - "<<pin;
    cout<<"\nCountry: "<<country;
    cout<<"\nPAN linked to A/C: "<<pan;
    cout<<"\nUID linked to A/C: "<<uid;
    cout<<"\nLinked Phone: "<<mob;
    cout<<"\nLinked Email_ID: "<<email;
    cout<<"\nAccount Created on: "<<ctd;
    cout<<"\n-------------------------------------------------------";
  }

  char *password(){
    return pass;
    }

 char *user_name(){
    return name;
  }

 char *accn(){
    return ac;
 }

}b;  // -------------------Class ends here--------------------------

class account        //Balance details of all account holders
{

public:
     char account[15];

     float money;

}a;

//Amount deposition
void amt_deposit(char account1[15]){

   clrscr();
   float amt = 0;
   a.money=0;
   cout<<"\t\t\tMONEY DEPOSIT\n";
   cout<<"\t\t\t-------------\n\n";

   fout.open("balance.txt", ios :: binary | ios::app);
   cout<<"\nEnter your account no.: ";
   gets(a.account);
   cout<<"Enter the amount: ";
   cin>>amt;

       a.money += amt;

    fout.write((char *)&a, sizeof(a));
    cout<<"\n\nMoney Added!";
    fout.close();
    user(account1);
    getch();
}

//Amount withdrawal
void amt_withdraw(char account1[15]){

    clrscr();
    float amt = 0;
    cout<<"\t\t\tMONEY WITHDRAW\n";
    cout<<"\t\t\t--------------\n\n";
    fout.open("balance.txt", ios :: binary | ios::app);
    cout<<"\nEnter your account no.: ";
    gets(a.account);
    cout<<"Enter the amount: ";
    cin>>amt;

       a.money -= amt;

    fout.write((char *)&a, sizeof(a));
    cout<<"\n\n\t\t\tTransaction Successful!";
    fout.close();
    user(account1);
    getch();
}


void aboutus(char []);

//Money withdrawal & deposition page
void dep_withd(char account1[15]){

   clrscr();
   int ch;
   cout<<"\t\t  WITHDRAW or DEPOSIT  \n";
   cout<<"\t\t ----------------------\n\n";
   cout<<"\n1. Withdraw\n";
   cout<<"\n2. Deposit\n";
   cout<<"\n3. Check your Balance\n";
   cout<<"\n4. Go Back\n\n";
   cin>>ch;

   switch(ch){

   case 1: amt_withdraw(account1);

   case 2: amt_deposit(account1);

   case 3: balance(account1);

   case 4: user(account1);

   default: dep_withd(account1);
   }
}

void balance(char account1[15]){

   fin.open("balance.txt", ios::binary | ios::in);

   while(fin.read((char *)&a, sizeof(a))){

	if(strcmp(a.account, account1)==0){

		cout<<"\t\t\tACCOUNT BALANCE\n";
		cout<<"\t\t\t***************\n\n";
		cout<<"Balance: "<<a.money;
		user(account1);   //Redirects the user to after login page
		getch();
	}

   }
}

void add_record()    //It calls a function to accept new user details and adds to the database file
{ clrscr();
  fout.open("bank.txt",ios::binary | ios::app);

  b.getdata();
  fout.write((char *)&b, sizeof(b));
  fout.close();

}

void show_details(char account1[11])
{
  clrscr();
  int i=0;

  while(i<2){
   clrscr();
   cout<<"\n\n\n\t\t\tFetching Details"; delay(500);
   cout<<"."; delay(300); cout<<"."; delay(300); cout<<".";
   delay(300); cout<<".";
   i++;
 }
  clrscr();

  fin.open("bank.txt", ios::binary | ios::in);
  cout<<"\t\t\tAccount Details\n" ;
  cout<<"\t\t\t---------------\n" ;
  while(!fin.eof()){

   fin.read((char *)&b, sizeof(b));

  if(strcmp(account1,b.accn())==0){

      b.showdata();
      getch(); break;
    }

   else{
      cout<<"\n\nError while fetching your details!\n";
      cout<<"\nPlease contact your branch.";
      getch();
      user(account1);
   }
  }

  fin.close();
  user(account1);
}


void modify(char account1[11])    //To change the old password
{ clrscr();
  fstream f;
  char pass4[22];

  f.open("bank.txt", ios::binary | ios::in | ios::out);
  cout<<"\nEnter old password: ";
  gets(pass4);

 while(f.read((char *)&b, sizeof(b)))
  {
   if(strcmp(account1,b.accn())==0 && strcmp(pass4,b.password())==0)
     { clrscr();
       f.seekg(0,ios::cur);
       cout<<"\n\t\t\tPassword Change\n";
       cout<<"\t\t\t------------------\n\n";
       b.changepass();
       f.seekp(f.tellg() - sizeof(b));
       f.write((char *)&b, sizeof(b));
     }
    else{
	 cout<<"Incorrect old Password!";
	 getch();
	 user(account1);
    }
  }
  f.close();
  user(account1);  //Redirects the user to after login page (maintains the session)
  getch();
}

void logout(){    //Log out

	clrscr();
	cout<<"\t\t\t\t*********\n";
	cout<<"\t\t\t\tCITY BANK\n";
	cout<<"\t\t\t\t*********\n\n";
	cout<<"\n\t\t\tLogged out successfully!";
	getch();
	exit(-1);
}


void user(char account[15]){
	clrscr();
	int ch=0;   char account1[15];
	strcpy(account1, account);
	cout<<"\n********************************************************************************\n";
	cout<<"\tHello, "<<b.user_name()<<"!\t\t"<<"CITY BANK"<<"      \tAccount No.: "<<account1;
	cout<<"\n********************************************************************************\n";
	cout<<"\n1. Account Details\n\n";
	cout<<"2. Add or Withdraw Money \n\n";
	cout<<"3. Balance \n\n";
	cout<<"4. Change Password\n\n";
	cout<<"5. About us\n\n";
	cout<<"6. Log out\n\n";
	cout<<"Exit-->'0'\n\n";

	cin>>ch;

	switch(ch){

	   //Sending account number as parameter in listed functions will maintain the session of currently logged in user.
	   case 1: show_details(account1); break;
	   case 2: dep_withd(account1); break;
	   case 3: balance(account1); break;
	   case 4: modify(account1); break;
	   case 5: aboutus(account1); break;
	   case 6: logout(); break;
	   case 0: exit(1);

	   default: exit(2);
	}
	getch();
      }

  //LOGIN  PAGE
void login(){
	clrscr();
	int i=0, j;   char acc1[15], ch;
	strcpy(acc1,NULL);
	char pass4[22]={NULL};

	cout<<"\t\t\t\tLOGIN\n";
	cout<<"\n********************************************************************************\n";
	cout<<"\n\nAccount No.: "; gets(acc1);
	cout<<"\n\nPassword: ";

while(1){
   ch=getch();
    if(ch==ENTER){
       pass4[j]='\0'; break;
      } else if(ch==BKSP){
	if(j>0){
		j--;
		cout<<"\b \b"; //to return cursor
	    }
	} else if(ch==TAB || ch==SPACE){
	continue;
	 } else{
	pass4[j]=ch; 	j++;
	cout<<"*";
	}

}


       while(i<2){

	clrscr();
	cout<<"\n\n\n\t\t\tPlease wait"; delay(300);
	cout<<"."; delay(200); cout<<"."; delay(200); cout<<".";
	delay(200); cout<<".";
	i++;

       }

       clrscr();
       fin.open("bank.txt", ios::binary | ios::in);

       while(!fin.eof()){
	fin.read((char *)&b, sizeof(b));

	if(strcmp(pass4,b.password())==0 && strcmp(acc1,b.accn())==0){
	    clrscr();
	    cout<<"\t\t\t       Login successful!!"; delay(1000);
	    clrscr();
	    user(acc1);
	    getch();
	} else{
		clrscr();
		int ch=0;
		cout<<"\n********************************************************************************\n";
		cout<<"\t\t\t\tCITY BANK\n";
		cout<<"\n********************************************************************************\n";
		cout<<"\n\t\t\tIncorrect login credentials!\n";
		cout<<"\n\n1. Login\n\n";
		cout<<"2. Go To Home\n\n";
		cin>>ch;
		switch(ch){
			case 1: login();
			case 2: main();

			default: exit(8);
			}
		getch();
	}


    } //while loop

	fin.close();
	getch();

}     //login function

void aboutus(char account1[15])
{ clrscr();
  cout<<"About Us:\n";
  cout<<"--------\n\n";
  cout<<"Opening hours: \nMon - Fri -> 9 AM -5 PM\n"
      <<"Sat -> 9 AM - 1:30 PM \n\n";
  cout<<"Email: citybank@gmail.com\n\n";
  cout<<"Contact: 011-45738888\n\n";
  cout<<"Address: B-5/24, Safdarjung Enclave,\n\t Block B-7, Deer Park, Green Park(METRO),\n\t New Delhi-110029";
  getch();
  user(account1);    //Redirects the user to the previous logged in page.
}

void main()
{ clrscr();
  cout<<"\t\t\t*******************************\n";
  cout<<"\t\t\t   WELCOME  TO  CITY BANK\n";
  cout<<"\t\t\t*******************************\n\n";
  cout<<"\t\t\t* Every Person Deserves the Best *\n\n\n\n\n";
  cout<<"\t\t      +Branch : Safdajung Enclave, New Delhi\n";
  cout<<"\t\t       ------\n\n";
  cout<<"\t\t      +FreePhone : 08081154696 \n";
  cout<<"\t\t       ---------\n\n";
  cout<<"\a";
  cout<<"\b";
  getch();

  int c;

while(c!=0)
{
  clrscr();
  cout<<"\t\t\t\t*********\n";
  cout<<"\t\t\t\tCITY BANK\n";
  cout<<"\t\t\t\t*********\n\n";
  cout<<"\n1. Open New Account\n";
  cout<<"\n2. Login \n";
  cout<<"\n3. Exit-> '0'\n\n";
  cin>>c;
  switch(c)
  { case 0: exit(-23);

    case 1: add_record(); break;
    case 2: login(); break;


    default: cout<<"Wrong key!";
	     getch();
	     main();

  }
}

  getch();
}