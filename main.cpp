//*****************
//Program Name: Honors Project
//Author: Riyya Ahmed
//IDE Used: Repl-it
//Program description: Family bank account management
//*****************
#include<iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct Bank {
string name;
int age;
string accNum;
float checkBalance;
float saveBalance;
bool hasLoan;
float loanBalance;
int months;
float loanAmount;
float monthlyPayment;
float interestRate;
};

// Prototypes
void menu(vector <Bank> &, int &);
void view (vector <Bank> &, int );
void create (vector <Bank> &);
void remove (vector <Bank> & );
void deposit (vector <Bank> &, int );
void withdraw (vector <Bank> &, int );
void loan (vector <Bank> &, int);
void loanPay (vector <Bank> &, int);
void loanCheck (vector <Bank> &, int);

int main() {
  vector <Bank> account {{"Sam", 40, "1003453210", 10000,                               5000.0, false},
                        {"Mary", 38 , "1007895430", 5000, 500.0, false},
                        {"Rob", 19 , "1009894540", 1000, 200.0, false},
                        {"Carrie", 15, "1003245670",500, 100.0, false}};
  int choice = 0, userAccChoice;

  
  int num, acc;
    
    cout << "\tWhose account would you like to view today? Select: \n";
    for (int i = 0 ; i < account.size(); i++ )
      cout << "[" <<i+1 << "]" << account[i].name << endl;
    cin >> acc ; 

    //IVL for num
    while(acc <1 or acc > account.size())
    {
      cout <<"Error! Enter between the given ranges only! Enter again:  \n";
      cin >> acc; 
    }
   acc--;
  
  menu(account, choice);
 
 while(choice != 9)
 { 
    switch (choice)
    {
      case 1 :  {
                  view(account, acc);
                  break;
                }
      case 2 :  {
                  create(account);
                  break;
                }
      case 3 :  {
                  remove(account);
                  break;
                }
      case 4 :  {
                  deposit(account,acc);
                  break;
                }
      case 5 :  {
                  withdraw(account,acc);
                  break;
                }
      case 6 :  {
                 loan(account, acc);
                  break;
                }
      case 7 :  {
                 loanPay(account, acc);
                  break;
                }    
      case 8 :  {
                 loanCheck(account, acc);
                  break;
                }    
    }
     menu(account, choice);

  } 
cout << "\n\t **Program Ending! Have a good day!** \n";
  return 0;
}

//function defintion
void menu(vector <Bank> &t, int &num)
{  
  cout <<"\n***Welcome to your Family Banking Management system***\n";
  cout << "What would you like to do today? Select: \n";
  cout << setw(30) << "[1] View Account \n";
  cout << setw(32) << "[2] Create Account \n";
  cout << setw(32) << "[3] Delete Account \n";
  cout << setw(33) << "[4] Deposit Ammount \n";
  cout << setw(34) << "[5] Withdraw Ammount \n";
  cout << setw(26) << "[6] Get loan \n";
  cout << setw(35) << "[7] Make loan payment \n";
  cout << setw(36) << "[8] Check loan balance \n";
  cout << setw(22) << "[9] Quit \n";
  cin >> num;

  //IVL for num
  while(num <1 or num > 9)
  {
    cout << "Error! Enter between 1-9 only!Enter again: \n";
    cin >> num;
  }
  cin.ignore();
}

void view (vector <Bank> &t, int num)
{
  cout << endl << t[num].name << "'s account information: \n";
  cout << "Name: " << right << setw(30) << t[num].name << endl;
  cout << "Age: " << right << setw(30) << t[num].age << endl;
  cout << "Account Number: " << right << setw(24)<< t[num].accNum << endl;
  cout << "Checking Balance: " << right <<setw(18) << t[num].checkBalance << endl;
  cout << "Savings Balance: " << setw(19) << t[num].saveBalance << endl;
    cout << "\t\t\t***************\n";

}

void create (vector <Bank> &t)
{
  float n1,n2 ;
  Bank temp;
  cout << "\n\t **Welcome to View Account Module** \n";
  cout << "To create a new account within your family account, please provide the following information: \n";
  cout << "Enter name of the account holder: ";
  getline(cin , temp.name);
  cout << "Enter Age: ";
  cin >> temp.age;
  cout << "Enter the intial deposit in Checking Account- should be more than or equal to $100 to create a new account! ";
  cin >> n1;

  //IVL for n1
  while(n1 <=100 )
  {
    cout <<"Error! Enter amount more than or equal to $100 to continue! Enter again: \n";
    cin >> n1;
  }
  temp.checkBalance = n1;

  cout << "Enter the intial deposit in Savings Account- should be more than or equal to $50 to create a new account! ";
  cin >> n2;
  //IVL for n1
  while(n2 <=50 )
  {
    cout <<"Error! Enter amount more than or equal to $50 to continue! Enter again:  \n";
    cin >> n2;
  }
  temp.saveBalance = n2;

  //int n=n1=n2=n3=n4=n5 = 0;
  // create new account num
  string nums;
  for (int i = 0; i < 6; i++)
     nums += to_string(rand() % (9 - 0 + 1) + 0);
  temp.accNum =  "100" + nums;
  //cout << nums;

  t.push_back(temp);

  cout << "\n**Congratulations! New Account was successfully made!!**\n";
  cout <<  endl << temp.name << "'s new account information: \n";
  cout << "Name: " << right << setw(30) << temp.name << endl;
  cout << "Age: " << right << setw(30) << temp.age << endl;
  cout << "Account Number: " << right << setw(24)<< temp.accNum << endl;
  cout << "Checking Balance: " << right <<setw(18) << temp.checkBalance << endl;
  cout << "Savings Balance: " << setw(19) << temp.saveBalance << endl;
    cout << "\t\t\t***************\n";

  
}

void remove (vector <Bank> &t)
{
  int num;
    cout << "\n\t **Welcome to Remove Account Module** \n";
  cout << "Select the account you wish to delete: \n";
  for (int i = 0 ; i < t.size(); i++ )
    cout << "[" <<i+1 << "]" << t[i].name << endl;
  cin >> num ; 

  //IVL for num
  while(num <1 or num > t.size())
  {
    cout <<"Error! Enter between the given ranges only!  Enter again:  \n";
    cin >> num; 
  }
 
  t.erase(t.begin() + num -1);
  cout << "Account successfully deleted! \n";
    cout << "\t\t\t***************\n";

}

void deposit (vector <Bank> &t, int num)
{
  int n1;
  float check, save;

  cout << "Which account would you like to deposit in? Press 1 for Checking account or 2 for Savings account: ";
  cin >> n1;

  //IVL for N1
   while(n1 !=1 and n1 != 2)
  {
    cout <<"Error! Enter 1/2 only! \nEnter again:  ";
    cin >> n1; 
  }

  if (n1 == 1)
  {
    cout << "How much would you like to deposit? ";
    cin >> check;

      //IVL for check
      while(check < 0)
    {
      cout <<"Error! Enter atleast more than $0 \n  Enter again: ";
      cin >> check; 
    }
    
    t[num].checkBalance += check;
    cout << "New Checking account balance: $" << t[num].checkBalance << endl;
  }
  else
  {
    cout << "How much would you like to deposit? ";
    cin >> save;

      //IVL for check
      while(save < 0)
    {
      cout <<"Error! Enter atleast more than $0 \n  Enter again: ";
      cin >> save; 
    }
    
    t[num].saveBalance += save;
    cout << "New Saving account balance: $" << t[num].saveBalance << endl;
  }
    cout << "\t\t\t***************\n";

}

void withdraw(vector <Bank> &t, int num)
{
  int n1;
  float check, save;
  cout << "\n\t **Welcome to Withdraw Account Module** \n";

  cout << "Which account would you like to withdraw from? Press 1 for Checking account or 2 for Savings account: ";
  cin >> n1;

  //IVL for N1
   while(n1 !=1 and n1 != 2)
  {
    cout <<"Error! Enter 1/2 only! \n  Enter again: ";
    cin >> n1; 
  }

  if (n1 == 1)
  {
    cout << "How much would you like to withdraw? ";
    cin >> check;

    //IVL for check
      while(check < 0)
    {
      cout <<"Error! Enter atleast more than $0 \n Enter again: ";
      cin >> check; 
    }

    //limitation for kids
    while (t[num].age < 18 and check >100) 
    {
      cout << "Unfortunately, you cannot withdraw more than $100 from your account!  Enter again: ";
      cin >>check;
    }

    //balance check
    while (t[num].checkBalance < check) 
    {
      cout << "Sorry, you do not have enough balance!  Enter again: \n";
      cin >>check;
    }
    
      t[num].checkBalance -= check;
      cout << "New Checking account balance: $" << t[num].checkBalance << endl;
  
  
  }
  else
  {
    cout << "How much would you like to withdraw? ";
    cin >> save;

    //limitation for kids
    while (t[num].age < 18 and save >100) 
    {
      cout << "Unfortunately, you cannot withdraw more than $100 from your account!  Enter again: ";
      cin >> save;
    }

    //IVL for check
      while(save < 0)
    {
      cout <<"Error! Enter atleast more than $0 \n  Enter again: ";
      cin >> save; 
    }
//balance check
    while (t[num].saveBalance < save) 
    {
      cout << "Sorry, you do not have enough balance!  Enter again:  \n";
      cin >> save;
    }
    
      t[num].saveBalance -= save;
      cout << "New Saving account balance: $" << t[num].saveBalance << endl;
    
  }
    cout << "\t\t\t***************\n";

}

void loan (vector <Bank> &t, int num)
{
  int months;
  float amount , rate;
  cout << "\n\t**Welcome to Loan module! **\n";
  
  cout << ">Select one of the interest rates that our bank offers: \n";
  cout << setw(15) << "[1] 4.5% \n";
  cout << setw(15) << "[2] 4.2% \n";
  cin >> rate;
  //IVL  for rate
  while(rate!= 1 and rate != 2)
  {
    cout << "Error! Enter 1/2 only!\n Enter again: ";
    cin >> rate;
  }
  if (rate == 1 ) rate = 4.5;
  else if (rate == 2) rate = 4.2;
  t[num].interestRate = rate; //stored in the vector

  cout << "Enter loan ammount: ";
  cin >> amount;

  while(amount <0)
  {
    cout << "Enter atleast more than 0 to proceed! \n Enter again: ";
    cin >> amount;
  }

   //limitation for kids
    while (t[num].age < 18 and amount > 200) 
    {
      cout << "Unfortunately, you cannot request loan more than $200!  Enter again: ";
      cin >> amount;
    }
    t[num].loanAmount = amount;

  //loan period/time for payment
    cout << "Select your loan payment period: \n";
    cout << setw(15) << "[1] 2 years (24 months) \t [2] 5 years (60 months) \n";
    cin >> months;

    //IVL for months
    while(months != 1 and months != 2)
    {
      cout << "Select from 1/2 option only! \n Enter again: ";
      cin >> months;
    }
    if (months == 1 ) months = 24;
    else if (months ==2) months = 60;
    t[num].months = months;

    t[num].hasLoan = true;

    cout << "\n \t ** Congratulations! Your loan has been approved!** \n";
    cout << "Your loan details: \n";
    cout << ">Loan Under: " << setw(20) << t[num].name <<endl;
    cout << ">Loan Amount: " << setw(15) << "$" << t[num].loanAmount << endl;
    cout << ">Interest Rate: " << setw(16) << t[num].interestRate << "%" <<endl;
    cout << ">Interest period: " << setw(15) << t[num].months << endl;
    cout << "\t\t\t***************\n";
}

void loanPay (vector <Bank> &t, int num)
{
  float calc, payment;
  cout << "\n\t**Welcome to Loan Payment Module!**\n";

  //check if person took loan
  while (t[num].hasLoan == false)
  {
    cout << "Sorry,it looks like " << t[num-1].name << " has not requested for loan! Enter number again to make your payment: ";
    cin >> num;
  } 

  cout << "\t **Current loan detail**\n";
  cout <<">Loan you requested for: " << setw(15) << t[num].loanAmount <<endl;

 // compound interest calculation
  float p = t[num].loanAmount;
  float r = t[num].interestRate / 100;
  int time = t[num].months /12;
  int n = t[num].months;
  float total = 0;
  calc = p * (pow((1+ (r/n)), n*time)) ;
   total = calc;
    //total = t[num].loanAmount + calc;

  //calc = p*(1+(r/n));
  t[num].loanBalance = calc;
  cout << ">Your Loan payment has to be: " << setw(20) << "$" << total << endl;
  cout << ">Your expected monthly payment is: " << setw(15) <<"$" << total/n;
  
  //loan payment
  cout << "\n How much would you like to pay today? $";
  cin >> payment;

  //IvL for payment
  while(payment <0 )
  {
    cout << "Error!Enter atleast more than $0.\n Enter again: ";
    cin >>payment;
  }

  t[num].loanBalance -= payment; 
}

void loanCheck (vector <Bank> &t, int num)
{
  cout << "\n\t**Welcome to Loan Balance Check Module!**\n";
  
 while (t[num].hasLoan == false)
  {
    cout << "Sorry,it looks like " << t[num-1].name << " has not requested for loan! Enter number again to make your payment: ";
    cin >> num;
  } 


  cout << "\t **Loan balance detail**\n";
  cout <<">Loan you requested for: " << setw(15) << t[num].loanAmount <<endl;
  cout << ">Loan Balance: " << setw(15) << "$" << t[num].loanBalance << endl;
  cout << "\t\t\t***************\n";
}

