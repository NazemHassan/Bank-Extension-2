#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

enum enMainMenueOptions
{
	ShowClientList = 1,
	AddNewClient = 2, DeletClient = 3,
	UpdateClientInfo = 4, FindClient = 5,
	TransactionsMenue = 6, ManageUsers = 7, Logout = 8
};
enum enTransactionsMenueOptions
{
	eDeposit = 1, eWithdraw = 2,
	eTotalBalances = 3, eMainMenue = 4
};
enum enMainMenuePermissions {
	eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
	pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};


struct sClient
{
	string AccountNumber = "";
	string PinCode = "";
	string AccountName = "";
	string Phone = "";
	double AccountBalance = 0;
	bool MarkClientForDelete = false;

};
struct sUser
{
	string Username;
	string Password;
	short Permissions = 0;
	bool MarkForDelete = false;
};
const string UsersFileName = "Users.txt";
const string ClientsFileName = "Client.txt";

sUser CurrentUser;//this variable for any function need Current User Infromation

void Login();
void ShowMainMenueScreen();
void ShowTransactionsMenueScreen();
void ShowManageUsersMenuScreen();
void ShowAccessDeniedMessage();
bool CheckAccessPermission(enMainMenuePermissions Permission);


//Functions for show clients list
vector<string> SplitString(string s1, string delimi)
{
	short pos = 0;
	string sWord;
	vector<string> vWords;
	while ((pos = s1.find(delimi)) != std::string::npos)
	{
		sWord = s1.substr(0, pos);
		if (sWord != "")
		{
			vWords.push_back(sWord);
		}
		s1.erase(0, pos + delimi.length());
	}
	if (s1 != "")
	{
		vWords.push_back(s1);
	}
	return vWords;
}
sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.AccountName = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);

	return Client;


}
vector<sClient> LoadDataFromFile(string FileName)
{
	vector<sClient> vClient;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read mode

	if (MyFile.is_open())
	{
		string Line;
		sClient Record;

		while (getline(MyFile, Line))
		{
			Record = ConvertLineToRecord(Line);

			vClient.push_back(Record);
		}
		MyFile.close();
	}
	return vClient;
}
void PrintClientData(sClient ClientData)
{
	cout << "| " << left << setw(15) << ClientData.AccountNumber;
	cout << "| " << left << setw(10) << ClientData.PinCode;
	cout << "| " << left << setw(40) << ClientData.AccountName;
	cout << "| " << left << setw(12) << ClientData.Phone;
	cout << "| " << left << setw(12) << ClientData.AccountBalance;
}
void PrintAllClientsData(vector<sClient>& vClientData)
{
	cout << "\n\t\t\t\t\tClient List (" << vClientData.size() << ") Client(s).";
	cout << "\n-----------------------------------------------------------";
	cout << "---------------------------------------------\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Account Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance\n";

	cout << "\n-----------------------------------------------------------";
	cout << "---------------------------------------------\n" << endl;

	if (vClientData.size() == 0)
	{
		cout << "\t\t\tNo Client available in the system!";
	}
	else
	{
		for (sClient& Client : vClientData)
		{
			PrintClientData(Client);
			cout << endl;
		}
	}
	cout << "\n-----------------------------------------------------------";
	cout << "---------------------------------------------\n" << endl;

}

//Functions for Add new clients
bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
	vector<sClient> Client = LoadDataFromFile(ClientsFileName);
	
	
	for (sClient& C : Client)
	{
		if (C.AccountNumber == AccountNumber)
		{
			return true;
		}
	}
	return false;
	
}
sClient ReadNewClient()
{
	sClient Client1;

	cout << "Enter account number? ";
	getline(cin >> ws, Client1.AccountNumber);
	while (ClientExistsByAccountNumber(Client1.AccountNumber, ClientsFileName))
	{
		cout << "\nClient with [" << Client1.AccountNumber << "] already exists, Enter another Account Number? ";
		getline(cin >> ws, Client1.AccountNumber);

	}
	cout << "Enter PinCode? ";
	getline(cin, Client1.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client1.AccountName);
	cout << "Enter Phone? ";
	getline(cin, Client1.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client1.AccountBalance;

	return Client1;
}
string ConvertRecordToLine(sClient ClientData, string Seperator = "#//#")
{
	string Client1 = " ";

	Client1 = ClientData.AccountNumber + Seperator;
	Client1 += ClientData.PinCode + Seperator;
	Client1 += ClientData.AccountName + Seperator;
	Client1 += ClientData.Phone + Seperator;
	Client1 += to_string(ClientData.AccountBalance);

	return Client1;
}
void AddDataLineToFile(string FileName, string DataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open())
	{
		MyFile << DataLine << endl;

		MyFile.close();
	}

}
void AddClientDataToFile()
{
	sClient Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}
void AddClientsDataToFile()
{
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "Adding new client\n\n";
		AddClientDataToFile();

		cout << "\nClient Added successfully, do you want to add more clients?";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');
}

//Fucntions for find Client
string ReadAccountNumber()
{
	string Text = "";
	cout << "Please enter account number\n";
	//cin.ignore(1, '\n');
	getline(cin >> ws, Text);
	return Text;
}
void PrintClientCard(sClient ClientData)
{
	cout << "\nThe following are client details:\n\n";
	cout << "-------------------------------------\n";
	cout << "Account Number : " << ClientData.AccountNumber << endl;
	cout << "Pin Code       : " << ClientData.PinCode << endl;
	cout << "Name           : " << ClientData.AccountName << endl;
	cout << "Phone          : " << ClientData.Phone << endl;
	cout << "Account Balance: " << ClientData.AccountBalance << endl;
	cout << "-------------------------------------\n";

}
bool FindClientDataByAccountNumber(string AccountNumber, sClient& Client, vector<sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

//Functions for Delete Client
bool MarkClientForDeletByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkClientForDelete = true;
			return true;
		}
	}
	return false;
}
vector<sClient> SaveClientsDataToFile(string FileName, vector<sClient>& vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//Write Mode

	if (MyFile.is_open())
	{
		string DataLine;
		for (sClient& C : vClients)
		{
			if (C.MarkClientForDelete == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}
bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	char Answer = 'n';
	sClient Client;
	if (FindClientDataByAccountNumber(AccountNumber, Client, vClients))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want to delete this client? y/n ?";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			MarkClientForDeletByAccountNumber(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);

			vClients = LoadDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted successfully.\n";
			return true;
		}
	}
	else
	{
		cout << "Client with Account Number (" << AccountNumber << ") is Not Found!\n";
		return false;
	}

}

//Functions for Update Client info
sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client1;

	Client1.AccountNumber = AccountNumber;
	cout << "\nEnter PinCode? ";
	getline(cin >> ws, Client1.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client1.AccountName);
	cout << "Enter Phone? ";
	getline(cin, Client1.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client1.AccountBalance;

	return Client1;
}
bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	char Answer = 'n';
	sClient Client;
	if (FindClientDataByAccountNumber(AccountNumber, Client, vClients))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want to update this client? y/n ? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}
			SaveClientsDataToFile(ClientsFileName, vClients);
			cout << "\nClients updated successfully\n";
			return true;

		}
	}
	else
	{
		cout << "\n\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
		return false;
	}

}

void ShowClientListScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pListClients))
	{
		ShowAccessDeniedMessage();
	}


	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
	PrintAllClientsData(vClients);
}

void ShowAddNewClientsScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pAddNewClient))
	{
		ShowAccessDeniedMessage();
	}

	AddClientsDataToFile();
}

void ShowDeleteClientScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pDeleteClient))
	{
		ShowAccessDeniedMessage();
	}


	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);

}

void ShowUpdateClientScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pUpdateClients))
	{
		ShowAccessDeniedMessage();
	}

	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pFindClient))
	{
		ShowAccessDeniedMessage();
	}

	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();
	sClient Client;
	if (FindClientDataByAccountNumber(AccountNumber, Client, vClients))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "Client with Account Number[" << AccountNumber << "] is Not Found!";
	}

}

void GoBackToMainScreen()
{
	cout << "\n\nPress any key to go back main menue...";
	system("pause>0");

	ShowMainMenueScreen();
}

short ReadMainMenueOption()
{
	short Choice = 0;
	cout << "Choose what do you want to do? [1 to 8]? ";
	cin >> Choice;

	return Choice;
}

bool CheckAccessPermission(enMainMenuePermissions Permission)
{
	if (CurrentUser.Permissions == enMainMenuePermissions::eAll)
		return true;

	if ((Permission & CurrentUser.Permissions) == Permission)
		return true;
	else
		return false;

}

void ShowEndScreen()
{
	cout << "===============================================\n";
	cout << "\t\tProgramm ends\n";
	cout << "===============================================\n";
}

short ReadTransactionsOptions()
{
	short Choice = 0;
	cout << "Choose what do you want to do? [1 to 4]? ";
	cin >> Choice;

	return Choice;
}
bool DepositClientByAccountNumber(string AccountNumber, double Amount, vector<sClient> vClients)
{
	char Answer = 'Y';
	cout << "\nAre you sure you want to perform this transaction? y/n ? ";
	cin >> Answer;
	if (toupper(Answer) == 'Y')
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance += Amount;
				SaveClientsDataToFile(ClientsFileName, vClients);
				cout << "\n\nDone successfully. New balance is " << C.AccountBalance << endl;
				return true;
			}
		}

	}
	return false;
}
void GoBackToTransactionsMenue()
{
	cout << "\n\nPress any key to go back Transactions menue...";
	system("pause>0");
	ShowTransactionsMenueScreen();
}
void ShowDepositMenueScreen()
{
	system("cls");
	cout << "\n-------------------------------------\n";
	cout << "\t\tDeposit Screen\n";
	cout << "-------------------------------------\n";

	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();
	sClient Client;

	while (!FindClientDataByAccountNumber(AccountNumber, Client, vClients))
	{
		cout << "Client with [" << AccountNumber << "] does not exist.\n\n";
		AccountNumber = ReadAccountNumber();
	}

	PrintClientCard(Client);
	double Amount = 0;
	cout << "Please enter deposit amount? ";
	cin >> Amount;

	DepositClientByAccountNumber(AccountNumber, Amount, vClients);

}
void ShowWithdrawMenueScreen()
{
	system("cls");
	cout << "\n-------------------------------------\n";
	cout << "\t\tWithdraw Screen\n";
	cout << "-------------------------------------\n";

	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();
	sClient Client;

	while (!FindClientDataByAccountNumber(AccountNumber, Client, vClients))
	{
		cout << "Client with [" << AccountNumber << "] does not exist.\n\n";
		AccountNumber = ReadAccountNumber();
	}

	PrintClientCard(Client);
	double Amount = 0;
	cout << "Please enter withdraw amount? ";
	cin >> Amount;
	while (Amount > Client.AccountBalance)
	{
		cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
		cout << "Please enter another amount? ";
		cin >> Amount;
	}

	DepositClientByAccountNumber(AccountNumber, Amount * -1, vClients);

}
void PrintClientRecordLine(sClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(40) << Client.AccountName;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}
void ShowTotalBalancesMenue()
{
	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n-----------------------------------------------------------";
	cout << "---------------------------------------------\n" << endl;
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Account Name";
	cout << "| " << left << setw(12) << "Balance\n";

	cout << "\n-----------------------------------------------------------";
	cout << "---------------------------------------------\n" << endl;

	double TotalBalances = 0;
	if (vClients.size() == 0)
	{
		cout << "\t\t\tNo Client available in the system!";
	}
	else
	{
		for (sClient& Client : vClients)
		{
			PrintClientRecordLine(Client);
			TotalBalances += Client.AccountBalance;
			cout << endl;
		}
	}
	cout << "\n-----------------------------------------------------------";
	cout << "---------------------------------------------\n" << endl;
	cout << "\t\t\t\tTotal Balances = " << TotalBalances << endl;

}
void PerformTransactionsOption(enTransactionsMenueOptions TransactionOption)
{
	switch (TransactionOption)
	{
	case enTransactionsMenueOptions::eDeposit:
		system("cls");
		ShowDepositMenueScreen();
		GoBackToTransactionsMenue();
		break;

	case enTransactionsMenueOptions::eWithdraw:
		system("cls");
		ShowWithdrawMenueScreen();
		GoBackToTransactionsMenue();
		break;

	case enTransactionsMenueOptions::eTotalBalances:
		system("cls");
		ShowTotalBalancesMenue();
		GoBackToTransactionsMenue();
		break;

	case enTransactionsMenueOptions::eMainMenue:
		ShowMainMenueScreen();
	}
}
void ShowTransactionsMenueScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pTranactions))
	{
		ShowAccessDeniedMessage();
	}

	system("cls");
	cout << "===============================================\n";
	cout << "\t\tTransactions Menue screen\n";
	cout << "===============================================\n";

	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances.\n";
	cout << "\t[4] Main Menue.\n";
	cout << "===============================================\n";


	PerformTransactionsOption((enTransactionsMenueOptions)ReadTransactionsOptions());
}

void PerformMainMenueOption(enMainMenueOptions MainMenueOption)
{
	switch (MainMenueOption)
	{
	case enMainMenueOptions::ShowClientList:
	{
		system("cls");
		ShowClientListScreen();
		GoBackToMainScreen();
		break;
	}
	case enMainMenueOptions::AddNewClient:
	{
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainScreen();
		break;
	}
	case enMainMenueOptions::DeletClient:
	{
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainScreen();
		break;
	}
	case enMainMenueOptions::UpdateClientInfo:
	{
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainScreen();
		break;
	}
	case enMainMenueOptions::FindClient:
	{
		system("cls");
		ShowFindClientScreen();
		GoBackToMainScreen();
		break;
	}
	case enMainMenueOptions::TransactionsMenue:
	{
		system("cls");
		ShowTransactionsMenueScreen();
		break;
	}
	case enMainMenueOptions::ManageUsers:
	{
		system("cls");
		ShowManageUsersMenuScreen();
		break;
	}
	case enMainMenueOptions::Logout:

		system("cls");
		Login();
	}
}

void ShowMainMenueScreen() 
{
	system("cls");
	cout << "===============================================\n";
	cout << "\t\tMain Menue screen\n";
	cout << "===============================================\n";

	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Clinet.\n";
	cout << "\t[4] Update Client info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Manage Users.\n";
	cout << "\t[8] Logout.\n";
	cout << "===============================================\n";

	PerformMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}


//Project 1 in Course8. Extension 2 on the Bank Project from Course 7
enum enUserOptions{ListUesr = 1, AddUser = 2, DeleteUser = 3, 
UpdateUser = 4, FindUser = 5, MainMenu = 6};

sUser AskUserInformation()
{
	sUser User;
	cout << "Enter Username? ";
	cin >> User.Username;
	cout << "Enter Password? ";
	cin >> User.Password;

	return User;
}  

sUser ConvertUserDataToRecord(string Line, string Seperator = "#//#")
{
	sUser User;
	vector<string> vUserDate = SplitString(Line, Seperator);

	User.Username = vUserDate[0];
	User.Password = vUserDate[1];
	User.Permissions = stoi(vUserDate[2]);
	

	return User;


}
vector<sUser> LoadUserDataFromFile(string FileName)
{
	vector<sUser> vUser;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read mode

	if (MyFile.is_open())
	{
		string Line;
		sUser Record;

		while (getline(MyFile, Line))
		{
			Record = ConvertUserDataToRecord(Line);

			vUser.push_back(Record);
		}
		MyFile.close();
	}
	return vUser;
}
bool IsUserExist(sUser User,sUser& CurrentUser, string FileName)
{
	vector<sUser> vUser = LoadUserDataFromFile(UsersFileName);
	fstream MyFile;
	MyFile.open(FileName, ios::in);//Read mode

	if (MyFile.is_open())
	{
		for (sUser& u : vUser)
		{
			if (u.Username == User.Username && u.Password == User.Password)
			{
				CurrentUser = u;
				MyFile.close();
				return true;
			}
		}
		MyFile.close();
		return false;
	}
}
bool IsUserExist(string Username, string FileName)//Overloaded
{
	vector<sUser> vUser = LoadUserDataFromFile(UsersFileName);
	fstream MyFile;
	MyFile.open(FileName, ios::in);//Read mode

	if (MyFile.is_open())
	{
		for (sUser& u : vUser)
		{
			if (u.Username == Username)
			{
				MyFile.close();
				return true;
			}
		}
		MyFile.close();
		return false;
	}
}

//Functions for Show User List
void PrintUserDate(sUser& User)
{
	cout << "| " << left << setw(15) << User.Username;
	cout << "| " << left << setw(10) << User.Password;
	cout << "| " << left << setw(40) << User.Permissions;
}
void PrintAllUsersData(vector<sUser>& vUsers)
{
	cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
	cout << "\n-----------------------------------------------------------";
	cout << "---------------------------------------------\n" << endl;
	cout << "| " << left << setw(15) << "User Name";
	cout << "| " << left << setw(10) << "Password";
	cout << "| " << left << setw(40) << "Permission";

	cout << "\n-----------------------------------------------------------";
	cout << "---------------------------------------------\n" << endl;

	if (vUsers.size() == 0)
	{
		cout << "No Users Available in the system\n";
	}
	else
	{
		for(sUser& User : vUsers)
		{
			PrintUserDate(User);
			cout << endl;
		}

	}

	cout << "\n-----------------------------------------------------------";
	cout << "---------------------------------------------\n" << endl;
}

//Functions for Find User
string ReadUsername()
{
	string Username;
	cout << "Please enter username? ";
	cin >> Username;

	return Username;
}
bool FindUserByUsername(string Username, sUser& User, vector<sUser> vUsers)
{
	
	for (sUser& U : vUsers)
	{
		if (Username == U.Username)
		{
			User = U;
			return true;
		}
	}
	return false;
}
void PrintUserCard(sUser UserInfo)
{
	cout << "\nThe following are User details:\n\n";
	cout << "-------------------------------------\n";
	cout << "Username : " <<UserInfo.Username << endl;
	cout << "Password : " << UserInfo.Password << endl;
	cout << "Permissions : " << UserInfo.Permissions << endl;
	cout << "-------------------------------------\n";

}

//Functions for Delete User
bool MarkUserForDelete(string Username, vector<sUser>& vUsers)
{
	for (sUser& U : vUsers)
	{
		if (Username == U.Username)
		{
			U.MarkForDelete = true;
			return true;
		}
	}
	return false;
}
string ConvertUserRecordToLine(sUser User, string Seperator = "#//#")
{
	string strUser = " ";

	strUser = User.Username + Seperator;
	strUser += User.Password + Seperator;
	strUser += to_string(User.Permissions);

	return strUser;
}
vector<sUser> SaveUsersDataToFile(string FileName, vector<sUser>& vUsers)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//Write Mode

	if (MyFile.is_open())
	{
		string DataLine;
		for (sUser& U : vUsers)
		{
			if (U.MarkForDelete == false)
			{
				DataLine = ConvertUserRecordToLine(U);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vUsers;
}
bool DeleteUserByUsername(string Username, vector<sUser> vUsers)
{
	char Answer = 'Y';
	sUser User;
	if (FindUserByUsername(Username, User, vUsers))
	{
		PrintUserCard(User);

		cout << "\nAre you sure you want to delete this User? Y/N? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			MarkUserForDelete(Username, vUsers);
			
			SaveUsersDataToFile(UsersFileName, vUsers);
			vUsers = LoadUserDataFromFile(UsersFileName);
			cout << "User deleted successfully\n";
			return true;
		}

	}
	else
	{
		cout << "User with Username (" << Username << ") is Not Found!\n";
		return false;
	}
}

//Functions for Add new Users
short ChosePermissionsToUser()
{
	short total = 0;
	char Answer = 'Y';
	string Permissions[7] = {"Show Client List", "Add New Client", "Delete Client", "Update ClientInfo",
	"Find Client", "Transactions Menu", "Manage Users"};

	cout << "\nDo you want to give access to: \n";
	for (short j = 0; j < 7; j++)
	{
		cout << "\n" <<Permissions[j] << " y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			total += pow(2,j);
		}
	}
	return total;
}
sUser ReadNewUser()
{
	char Answer = 'y';
	sUser User;	
	cout << "\nEnter Username? ";
	cin >> User.Username;
	while (IsUserExist(User.Username, UsersFileName))
	{
		cout << "\nUser with (" << User.Username << ") already exist, Enter another one? \n ";
		cin >> User.Username;
	}
	cout << "\nEnter Password? ";
	cin >> User.Password;

	cout << "\nDo you want to give full access? y/n? ";
	cin >> Answer;
	if (tolower(Answer) == 'y')
	{
		User.Permissions = -1;
	}
	else
	{
		User.Permissions = ChosePermissionsToUser();
	}

	return User;
}
void AddUserToFile(string FileName)
{
	sUser User = ReadNewUser();
	AddDataLineToFile(FileName, ConvertUserRecordToLine(User));
}
void AddUsersToFile(string FileName)
{
	cout << "\tAdd New User Screen\n";
	cout << "-----------------------------------\n";

	cout << "\nAdding New User: \n";

	char Answer = 'y';
	do
	{
		AddUserToFile(FileName);

		cout << "\nUser Added successfully. Do You Want To Add More Users? ";
		cin >> Answer;

	} while (tolower(Answer) == 'y');

}

//Functions for Update user
sUser ChangeUserInfo(string Username)
{
	char Answer = 'y';
	sUser User;

	User.Username = Username;
	cout << "Enter Password\n";
	cin >> User.Password;

	cout << "\nDo you want to give full access? y/n? ";
	cin >> Answer;
	if (tolower(Answer) == 'y')
	{
		User.Permissions = -1;
	}
	else
	{
		User.Permissions = ChosePermissionsToUser();
	}
	return User;
}
bool UpdateUserByUsername(string Username, vector<sUser> vUsers)
{
	char WantUpdate = 'y';
	sUser User;
	if (FindUserByUsername(Username, User, vUsers))
	{
		PrintUserCard(User);
		cout << "Do you want to update this user? y/n? ";
		cin >> WantUpdate;
		if (tolower(WantUpdate) == 'y')
		{
			for (sUser& U : vUsers)
			{
				if (User.Username == U.Username)
				{
					U = ChangeUserInfo(Username);
					break;
				}
			}
			SaveUsersDataToFile(UsersFileName, vUsers);
			return true;
		}
		
	}
	else
	{
		cout << "User with (" << Username << ") Not found\n";
		return false;
	}
}
void ShowUpdateUserScreen()
{
	cout << "---------------------------\n";
	cout << "\tUpdate User screen";
	cout << "\n---------------------------\n";

	vector<sUser> vUsers = LoadUserDataFromFile(UsersFileName);
	string Username = ReadUsername();
	UpdateUserByUsername(Username, vUsers);
}

//////////////////////////////////////////////
void GoBackToManageUserScreen()
{
	cout << "\n\nPress any key to go back Transaction menu...";
	system("pause>0");

	ShowManageUsersMenuScreen();
}

void ShowLoginScreen()
{
	cout << "---------------------------\n";
	cout <<"\tLogin screen";
	cout << "\n---------------------------\n";
}

void ShowUserListScreen()
{
	vector<sUser>vUsers = LoadUserDataFromFile(UsersFileName);
	PrintAllUsersData(vUsers);
}

void ShowFindUserScreen()
{
	cout << "-----------------------------\n";
	cout << "\tFind  Users Screen\n";
	cout << "-----------------------------\n";


	vector<sUser> vUsers = LoadUserDataFromFile(UsersFileName);
	string Username = ReadUsername();
	sUser User;
	if (FindUserByUsername(Username, User, vUsers))
	{
		PrintUserCard(User);
	}
	else
	{
		cout << "\n\nNo User Found!\n";
	}
	GoBackToManageUserScreen();
}

void ShowDeleteUserScreen()
{	
	cout << "--------------------------------\n";
	cout << "\tDelete Users Screen\n";
	cout << "--------------------------------\n";


	string Username = ReadUsername();

	if (Username == "Admin")
	{
		cout << "\n\nYou cannot delete this user.\n";
		GoBackToManageUserScreen();
	}
	else
	{
		vector<sUser> vUsers = LoadUserDataFromFile(UsersFileName);
		DeleteUserByUsername(Username, vUsers);
	}
}

void ShowAddNewUserScreen()
{
	AddUsersToFile(UsersFileName);
}

void ShowAccessDeniedMessage()
{
	cout << "\n--------------------------------------\n";
	cout << "Access Denied,\n";
	cout << "You Don't Have Permission To Do This,\n";
	cout << "Please Contact Your Admin.";
	cout << "\n--------------------------------------\n";

	GoBackToMainScreen();
}

short ReadManageMenuOptions()
{
	short Option = 0;
	cout << "Chose what do you want to do? [1 to 6]? ";
	cin >> Option;

	return Option;
}
void PerformManageUsersOptions(enUserOptions Option)
{
	switch (Option)
	{
	case enUserOptions::ListUesr:
	{
		system("cls");
		ShowUserListScreen();
		GoBackToManageUserScreen();
		break;
	}
	case enUserOptions::AddUser:
	{
		system("cls");
		AddUsersToFile("Users.txt");
		GoBackToManageUserScreen();
	}
	case enUserOptions::DeleteUser:
	{
		system("cls");
		ShowDeleteUserScreen();
		GoBackToManageUserScreen();
	}
	case enUserOptions::UpdateUser:
	{
		system("cls");
		ShowUpdateUserScreen();
		GoBackToManageUserScreen();
	}
	case enUserOptions::FindUser:     
	{
		system("cls");
		ShowFindUserScreen();
	}
	
	case enUserOptions::MainMenu:
	{
		ShowMainMenueScreen();
		break;
	}
	}
}
void ShowManageUsersMenuScreen()
{
	if (!CheckAccessPermission(enMainMenuePermissions::pManageUsers))
	{
		ShowAccessDeniedMessage();
	}

	system("cls");
	cout << "===============================================\n";
	cout << "\t\tManage Users Menu screen\n";
	cout << "===============================================\n";

	cout << "\t[1] List Users.\n";
	cout << "\t[2] Add New User.\n";
	cout << "\t[3] Delete User.\n";
	cout << "\t[4] Update User.\n";
	cout << "\t[5] Find User.\n";
	cout << "\t[6] Main Menu.\n";
	cout << "===============================================\n";

	PerformManageUsersOptions((enUserOptions)ReadManageMenuOptions());
} 

void Login()
{
	ShowLoginScreen();

	sUser UserInfo = AskUserInformation();

	while (!IsUserExist(UserInfo,CurrentUser, UsersFileName))
	{
		system("cls");
		ShowLoginScreen();
		cout << "Invalid Username/Password!\n";
		UserInfo = AskUserInformation();
	}

	ShowMainMenueScreen();

}

int main()
{
	Login();

	system("pause>0");
}
