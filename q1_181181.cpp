#include <iostream>
#include <fstream>
#include "gitHubUser2.h"
#include <string>
using namespace std;

void readDataFromFile( gitHubUser2* &users, string filepath,int &size)
{
	ifstream read;
	read.open(filepath);
	read >> size;
	users = new gitHubUser2 [size];
	for (int i = 0 ; i < size ;i++)
	{

		read >> users[i].firstName;
		read >> users[i].userName;
		read >> users[i].email;
		read >> users[i].folderCount;
		int x = users[i].folderCount;
		users[i].gitHubFolders = new string[x];
		
		for (int j = 0 ; j < x ; j++)
		{
			read.ignore();
			getline(read, users[i].gitHubFolders[j]);
		}
		users[i].institution_name = nullptr;
		users[i].qualification_level = nullptr;
	}

}
void Print(gitHubUser2 *users, int s)
{
	cout << "There are "<< s << " users\n";
for (int i = 0 ; i < s ;i++)
	{
		cout << "First Name: " << users[i].firstName<<endl;
		cout << "User name: " << users[i].userName<<endl;
		cout << "Email: " << users[i].email<<endl;
		cout << "There are " << users[i].folderCount << " folders \n";
		cout << "Name as\n";
		for (int j = 0 ; j <  users[i].folderCount; j++)
		{
			cout << users[i].gitHubFolders[j]<<endl;
		}
		if (users[i].institution_name != nullptr)
		{
			cout << "The isnstitution name of " << users[i].firstName << " is " << *users[i].institution_name << endl;
			cout << "The education level of " << users[i].firstName << " is " << *users[i].qualification_level << endl;
		}
		cout << endl;
	}
}
void setEduBckGrnd(gitHubUser2* &user ,int s)
{
	for (int i = 0; i < s; i++)
	{
		user[i].institution_name = new string;
		cout <<user[i].firstName << " enter your institution name: ";
		cin >> *user[i].institution_name;
		user[i].qualification_level = new string;
		cout <<user[i].firstName << " enter your Qualification level: ";
		cin >> *user[i].qualification_level;
	}

}

void remove (gitHubUser2 *user,int s)
{
	for (int i = 0; i < s; i++)
	{
		user[i].qualification_level = nullptr;
		user[i].institution_name = nullptr;
	}
}
void backuparray ( gitHubUser2 *users , gitHubUser2 * backup , int s)
{
	backup = new gitHubUser2 [s];
	for (int i = 0 ; i < s ; i++)
	{
		backup[i].firstName = users[i].firstName;
		backup[i].userName = users[i].userName;
		backup[i].email = users[i].email;
		backup[i].folderCount = users[i].folderCount;
		backup[i].gitHubFolders = new string[backup[i].folderCount];
		for (int j = 0 ; j < backup[i].folderCount ; j++)
		{
			backup[i].gitHubFolders[j] = users[i].gitHubFolders[j];
		}

	}
}


int main ()
{
	gitHubUser2 *users = nullptr;
	gitHubUser2 *backup = nullptr;
	int s,x = 5;
	readDataFromFile(users, "Input.txt", s);
	while (x != 0)
	{
		cout << "\nWELCOME TO GITHUB USER PROFILE\n\n";
		cout << "Enter --> 1 If you wanna print data of users\n"
			"Enter --> 2 To set Education Background\n"
			"Enter --> 3 For removing Educational info\n"
			"Enter --> 4 For Making Backup\n"
			"Enter --> 0 If you wanna exit\n";
		cin >> x;
		if (x == 1)
		{
			Print(users, s);
		}
		if (x == 2)
		{
			setEduBckGrnd(users, s);
		}
		if (x == 3)
		{
			remove(users, s);
			cout << "<-----Educational info is successfully deleted----->\n";
		}
		if (x == 4)
		{
			backuparray(users, backup, s);
			cout << "Backup has been made Successfully";
		}
		if (x == 0)
		{
			cout << "Thanks for coming (-,-)\n\n";
		}
		if (x < 0 || x > 4)
			cout << "Invalid input again";
	}
	for (int i = 0; i < s; i++)                 //DEALLOCATION
	{
		users[i].gitHubFolders = nullptr;
		if (backup != nullptr)
		{
			delete backup[i].gitHubFolders;
			backup[i].gitHubFolders = nullptr;
			delete backup[i].institution_name;
			backup[i].institution_name = nullptr;
			delete backup[i].qualification_level;
			backup[i].qualification_level = nullptr;
		}
	}
	delete[]users;
	delete[]backup;


	return 0;
}