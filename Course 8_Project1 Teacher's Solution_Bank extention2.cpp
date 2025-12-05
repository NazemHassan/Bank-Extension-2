//#include <iostream>
//#include <vector>
//#include <string>
//#include <iomanip>
//#include <fstream>
//using namespace std;
//
//struct sClient
//{
//	string AccountNumber = "";
//	string PinCode = "";
//	string AccountName = "";
//	string Phone = "";
//	double AccountBalance = 0;
//	bool MarkClientForDelete = false;
//
//};
//struct sUser
//{
//	string Username;
//	string Password;
//	short Permissions = 0;
//	bool MarkForDelete = false;
//};
//const string ClientsFileName = "Client.txt";
//const string UsersFileName = "Users.txt";
//
//sUser CurrentUser;//this for anytime I need User Data I can Use this Varaible Instead of passing parameter in functions
//
//void ShowMainMenueScreen();
//void ShowTransactionsMenueScreen();
//void Login();
//void ShowManageUserScreen();
//
//
////Functions for show clients list
//vector<string> SplitString(string s1, string delimi)
//{
//	short pos = 0;
//	string sWord;
//	vector<string> vWords;
//	while ((pos = s1.find(delimi)) != std::string::npos)
//	{
//		sWord = s1.substr(0, pos);
//		if (sWord != "")
//		{
//			vWords.push_back(sWord);
//		}
//		s1.erase(0, pos + delimi.length());
//	}
//	if (s1 != "")
//	{
//		vWords.push_back(s1);
//	}
//	return vWords;
//}
//sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
//{
//	sClient Client;
//	vector<string> vClientData = SplitString(Line, Seperator);
//
//	Client.AccountNumber = vClientData[0];
//	Client.PinCode = vClientData[1];
//	Client.AccountName = vClientData[2];
//	Client.Phone = vClientData[3];
//	Client.AccountBalance = stod(vClientData[4]);
//
//	return Client;
//
//
//}
//vector<sClient> LoadDataFromFile(string FileName)
//{
//	vector<sClient> vClient;
//	fstream MyFile;
//	MyFile.open(FileName, ios::in);//read mode
//
//	if (MyFile.is_open())
//	{
//		string Line;
//		sClient Record;
//
//		while (getline(MyFile, Line))
//		{
//			Record = ConvertLineToRecord(Line);
//
//			vClient.push_back(Record);
//		}
//		MyFile.close();
//	}
//	return vClient;
//}
//void PrintClientData(sClient ClientData)
//{
//	cout << "| " << left << setw(15) << ClientData.AccountNumber;
//	cout << "| " << left << setw(10) << ClientData.PinCode;
//	cout << "| " << left << setw(40) << ClientData.AccountName;
//	cout << "| " << left << setw(12) << ClientData.Phone;
//	cout << "| " << left << setw(12) << ClientData.AccountBalance;
//}
//void PrintAllClientsData(vector<sClient>& vClientData)
//{
//	cout << "\n\t\t\t\t\tClient List (" << vClientData.size() << ") Client(s).";
//	cout << "\n-----------------------------------------------------------";
//	cout << "---------------------------------------------\n" << endl;
//	cout << "| " << left << setw(15) << "Account Number";
//	cout << "| " << left << setw(10) << "Pin Code";
//	cout << "| " << left << setw(40) << "Account Name";
//	cout << "| " << left << setw(12) << "Phone";
//	cout << "| " << left << setw(12) << "Balance\n";
//
//	cout << "\n-----------------------------------------------------------";
//	cout << "---------------------------------------------\n" << endl;
//
//	if (vClientData.size() == 0)
//	{
//		cout << "\t\t\tNo Client available in the system!";
//	}
//	else
//	{
//		for (sClient& Client : vClientData)
//		{
//			PrintClientData(Client);
//			cout << endl;
//		}
//	}
//	cout << "\n-----------------------------------------------------------";
//	cout << "---------------------------------------------\n" << endl;
//
//}
//
////Functions for Add new clients
//
//bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
//{
//	vector<sClient> Client = LoadDataFromFile(ClientsFileName);
//	fstream MyFile;
//	MyFile.open(FileName, ios::in);//Read mode
//
//	if (MyFile.is_open())
//	{
//		for (sClient& C : Client)
//		{
//			if (C.AccountNumber == AccountNumber)
//			{
//				MyFile.close();
//				return true;
//			}
//		}
//		MyFile.close();
//		return false;
//	}
//}
//sClient ReadNewClient()
//{
//	sClient Client1;
//
//
//	cout << "Enter account number? ";
//	getline(cin >> ws, Client1.AccountNumber);
//	while (ClientExistsByAccountNumber(Client1.AccountNumber, ClientsFileName))
//	{
//		cout << "\nClient with [" << Client1.AccountNumber << "] already exists, Enter another Account Number? ";
//		cin >> ws, Client1.AccountNumber;
//
//	}
//	cout << "Enter PinCode? ";
//	getline(cin, Client1.PinCode);
//	cout << "Enter Name? ";
//	getline(cin, Client1.AccountName);
//	cout << "Enter Phone? ";
//	getline(cin, Client1.Phone);
//	cout << "Enter AccountBalance? ";
//	cin >> Client1.AccountBalance;
//
//	return Client1;
//}
//string ConvertRecordToLine(sClient ClientData, string Seperator = "#//#")
//{
//	string Client1 = " ";
//
//	Client1 = ClientData.AccountNumber + Seperator;
//	Client1 += ClientData.PinCode + Seperator;
//	Client1 += ClientData.AccountName + Seperator;
//	Client1 += ClientData.Phone + Seperator;
//	Client1 += to_string(ClientData.AccountBalance);
//
//	return Client1;
//}
//void AddDataLineToFile(string FileName, string DataLine)
//{
//	fstream MyFile;
//	MyFile.open(FileName, ios::out | ios::app);
//	if (MyFile.is_open())
//	{
//		MyFile << DataLine << endl;
//
//		MyFile.close();
//	}
//
//}
//void AddClientDataToFile()
//{
//	sClient Client = ReadNewClient();
//	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
//}
//void AddClientsDataToFile()
//{
//	char AddMore = 'Y';
//
//	do
//	{
//		system("cls");
//		cout << "Adding new client\n\n";
//		AddClientDataToFile();
//
//		cout << "\nClient Added successfully, do you want to add more clients?";
//		cin >> AddMore;
//
//	} while (toupper(AddMore) == 'Y');
//}
//
////Fucntions for find Client
//string ReadAccountNumber()
//{
//	string Text = "";
//	cout << "Please enter account number\n";
//	//cin.ignore(1, '\n');
//	getline(cin >> ws, Text);
//	return Text;
//}
//void PrintClientCard(sClient ClientData)
//{
//	cout << "\nThe following are client details:\n\n";
//	cout << "-------------------------------------\n";
//	cout << "Account Number : " << ClientData.AccountNumber << endl;
//	cout << "Pin Code       : " << ClientData.PinCode << endl;
//	cout << "Name           : " << ClientData.AccountName << endl;
//	cout << "Phone          : " << ClientData.Phone << endl;
//	cout << "Account Balance: " << ClientData.AccountBalance << endl;
//	cout << "-------------------------------------\n";
//
//}
//bool FindClientDataByAccountNumber(string AccountNumber, sClient& Client, vector<sClient>& vClients)
//{
//	for (sClient& C : vClients)
//	{
//		if (C.AccountNumber == AccountNumber)
//		{
//			Client = C;
//			return true;
//		}
//	}
//	return false;
//}
//
////Functions for Delete Client
//bool MarkClientForDeletByAccountNumber(string AccountNumber, vector<sClient>& vClients)
//{
//	for (sClient& C : vClients)
//	{
//		if (C.AccountNumber == AccountNumber)
//		{
//			C.MarkClientForDelete = true;
//			return true;
//		}
//	}
//	return false;
//}
//vector<sClient> SaveClientsDataToFile(string FileName, vector<sClient>& vClients)
//{
//	fstream MyFile;
//	MyFile.open(FileName, ios::out);//Write Mode
//
//	if (MyFile.is_open())
//	{
//		string DataLine;
//		for (sClient& C : vClients)
//		{
//			if (C.MarkClientForDelete == false)
//			{
//				DataLine = ConvertRecordToLine(C);
//				MyFile << DataLine << endl;
//			}
//		}
//		MyFile.close();
//	}
//	return vClients;
//}
//bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
//{
//	char Answer = 'n';
//	sClient Client;
//	if (FindClientDataByAccountNumber(AccountNumber, Client, vClients))
//	{
//		PrintClientCard(Client);
//
//		cout << "\n\nAre you sure you want to delete this client? y/n ?";
//		cin >> Answer;
//		if (toupper(Answer) == 'Y')
//		{
//			MarkClientForDeletByAccountNumber(AccountNumber, vClients);
//			SaveClientsDataToFile(ClientsFileName, vClients);
//
//			vClients = LoadDataFromFile(ClientsFileName);
//
//			cout << "\n\nClient Deleted successfully.\n";
//			return true;
//		}
//	}
//	else
//	{
//		cout << "Client with Account Number (" << AccountNumber << ") is Not Found!\n";
//		return false;
//	}
//
//}
//
////Functions for Update Client info
//sClient ChangeClientRecord(string AccountNumber)
//{
//	sClient Client1;
//
//	Client1.AccountNumber = AccountNumber;
//	cout << "\nEnter PinCode? ";
//	getline(cin >> ws, Client1.PinCode);
//	cout << "Enter Name? ";
//	getline(cin, Client1.AccountName);
//	cout << "Enter Phone? ";
//	getline(cin, Client1.Phone);
//	cout << "Enter AccountBalance? ";
//	cin >> Client1.AccountBalance;
//
//	return Client1;
//}
//bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
//{
//	char Answer = 'n';
//	sClient Client;
//	if (FindClientDataByAccountNumber(AccountNumber, Client, vClients))
//	{
//		PrintClientCard(Client);
//
//		cout << "\n\nAre you sure you want to update this client? y/n ? ";
//		cin >> Answer;
//		if (toupper(Answer) == 'Y')
//		{
//			for (sClient& C : vClients)
//			{
//				if (C.AccountNumber == AccountNumber)
//				{
//					C = ChangeClientRecord(AccountNumber);
//					break;
//				}
//			}
//			SaveClientsDataToFile(ClientsFileName, vClients);
//			cout << "\nClients updated successfully\n";
//			return true;
//
//		}
//	}
//	else
//	{
//		cout << "\n\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
//		return false;
//	}
//
//}
////-------------------------------------------------------------------------------
//
//enum enMainMenueOptions
//{
//	ShowClientList = 1,
//	AddNewClient = 2, DeletClient = 3,
//	UpdateClientInfo = 4, FindClient = 5,
//	TransactionsMenue = 6, ManageUsers = 7, Logout = 8
//};
//enum enTransactionsMenueOptions
//{
//	eDeposit = 1, eWithdraw = 2,
//	eTotalBalances = 3, eMainMenue = 4
//};
//
//enum enManageUsersOptions
//{
//	eListUser = 1, eAddUser = 2, eDeleteUser = 3,
//	eUpdateUser = 4, eFindUser = 5, MainMenu = 6
//};
//
//enum enMainMenuPermissions
//{
//	eAll = -1, pListClient = 1, pAddClient = 2, pDeleteClient = 4, pUpdateClient = 8,
//	pFindClient = 16, pTransactions = 32, pManageUsers = 64
//};
//
//bool CheckPermission(enMainMenuPermissions Permission)
//{
//	if (CurrentUser.Permissions == enMainMenuPermissions::eAll)
//	{
//		return true;
//	}
//	else
//	{
//		if ((CurrentUser.Permissions & Permission) == Permission)
//			return true;
//		else;
//		return false;
//	}
//}
//void ShowDeniedAccessScreen()
//{
//	cout << "\n--------------------------------------\n";
//	cout << "Access Denied,\n";
//	cout << "You Don't Have Permission To Do This,\n";
//	cout << "Please Contact Your Admin.";
//	cout << "\n--------------------------------------\n";
//
//}
//
//void GoBackToMainScreen()
//{
//	cout << "\n\nPress any key to go back main menue...";
//	system("pause>0");
//
//	ShowMainMenueScreen();
//}
//
//void ShowClientListScreen()
//{
//	if (!CheckPermission(enMainMenuPermissions::pListClient))
//	{
//		system("cls");
//		ShowDeniedAccessScreen();
//		GoBackToMainScreen();
//	}
//
//
//	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
//	PrintAllClientsData(vClients);
//}
//void ShowAddNewClientsScreen()
//{
//	if (!CheckPermission(enMainMenuPermissions::pAddClient))
//	{
//		system("cls");
//		ShowDeniedAccessScreen();
//		GoBackToMainScreen();
//	}
//
//	AddClientsDataToFile();
//}
//void ShowDeleteClientScreen()
//{
//	if (!CheckPermission(enMainMenuPermissions::pDeleteClient))
//	{
//		system("cls");
//		ShowDeniedAccessScreen();
//		GoBackToMainScreen();
//	}
//
//	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
//	string AccountNumber = ReadAccountNumber();
//	DeleteClientByAccountNumber(AccountNumber, vClients);
//
//}
//void ShowUpdateClientScreen()
//{
//	if (!CheckPermission(enMainMenuPermissions::pUpdateClient))
//	{
//		system("cls");
//		ShowDeniedAccessScreen();
//		GoBackToMainScreen();
//	}
//
//	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
//	string AccountNumber = ReadAccountNumber();
//
//	UpdateClientByAccountNumber(AccountNumber, vClients);
//}
//void ShowFindClientScreen()
//{
//	if (!CheckPermission(enMainMenuPermissions::pFindClient))
//	{
//		system("cls");
//		ShowDeniedAccessScreen();
//		GoBackToMainScreen();
//	}
//
//	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
//	string AccountNumber = ReadAccountNumber();
//	sClient Client;
//	if (FindClientDataByAccountNumber(AccountNumber, Client, vClients))
//	{
//		PrintClientCard(Client);
//	}
//	else
//	{
//		cout << "Client with Account Number[" << AccountNumber << "] is Not Found!";
//	}
//
//}
//
//
//short ReadMainMenueOption()
//{
//	short Choice = 0;
//	cout << "Choose what do you want to do? [1 to 8]? ";
//	cin >> Choice;
//
//	return Choice;
//}
//
//
//void ShowEndScreen()
//{
//	cout << "===============================================\n";
//	cout << "\t\tProgramm ends\n";
//	cout << "===============================================\n";
//}
//
////Teacher's solution for the extension bank project
//short ReadTransactionsOptions()
//{
//	short Choice = 0;
//	cout << "Choose what do you want to do? [1 to 4]? ";
//	cin >> Choice;
//
//	return Choice;
//}
//bool DepositClientByAccountNumber(string AccountNumber, double Amount, vector<sClient> vClients)
//{
//	char Answer = 'Y';
//	cout << "\nAre you sure you want to perform this transaction? y/n ? ";
//	cin >> Answer;
//	if (toupper(Answer) == 'Y')
//	{
//		for (sClient& C : vClients)
//		{
//			if (C.AccountNumber == AccountNumber)
//			{
//				C.AccountBalance += Amount;
//				SaveClientsDataToFile(ClientsFileName, vClients);
//				cout << "\n\nDone successfully. New balance is " << C.AccountBalance << endl;
//				return true;
//			}
//		}
//
//	}
//	return false;
//}
//void GoBackToTransactionsMenue()
//{
//	cout << "\n\nPress any key to go back Transactions menue...";
//	system("pause>0");
//	ShowTransactionsMenueScreen();
//}
//void ShowDepositMenueScreen()
//{
//	system("cls");
//	cout << "\n-------------------------------------\n";
//	cout << "\t\tDeposit Screen\n";
//	cout << "-------------------------------------\n";
//
//	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
//	string AccountNumber = ReadAccountNumber();
//	sClient Client;
//
//	while (!FindClientDataByAccountNumber(AccountNumber, Client, vClients))
//	{
//		cout << "Client with [" << AccountNumber << "] does not exist.\n\n";
//		AccountNumber = ReadAccountNumber();
//	}
//
//	PrintClientCard(Client);
//	double Amount = 0;
//	cout << "Please enter deposit amount? ";
//	cin >> Amount;
//
//	DepositClientByAccountNumber(AccountNumber, Amount, vClients);
//
//}
//void ShowWithdrawMenueScreen()
//{
//	system("cls");
//	cout << "\n-------------------------------------\n";
//	cout << "\t\tWithdraw Screen\n";
//	cout << "-------------------------------------\n";
//
//	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
//	string AccountNumber = ReadAccountNumber();
//	sClient Client;
//
//	while (!FindClientDataByAccountNumber(AccountNumber, Client, vClients))
//	{
//		cout << "Client with [" << AccountNumber << "] does not exist.\n\n";
//		AccountNumber = ReadAccountNumber();
//	}
//
//	PrintClientCard(Client);
//	double Amount = 0;
//	cout << "Please enter withdraw amount? ";
//	cin >> Amount;
//	while (Amount > Client.AccountBalance)
//	{
//		cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
//		cout << "Please enter another amount? ";
//		cin >> Amount;
//	}
//
//	DepositClientByAccountNumber(AccountNumber, Amount * -1, vClients);
//
//}
//void PrintClientRecordLine(sClient Client)
//{
//	cout << "| " << left << setw(15) << Client.AccountNumber;
//	cout << "| " << left << setw(40) << Client.AccountName;
//	cout << "| " << left << setw(12) << Client.AccountBalance;
//}
//void ShowTotalBalancesMenue()
//{
//	vector<sClient> vClients = LoadDataFromFile(ClientsFileName);
//
//	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
//	cout << "\n-----------------------------------------------------------";
//	cout << "---------------------------------------------\n" << endl;
//	cout << "| " << left << setw(15) << "Account Number";
//	cout << "| " << left << setw(40) << "Account Name";
//	cout << "| " << left << setw(12) << "Balance\n";
//
//	cout << "\n-----------------------------------------------------------";
//	cout << "---------------------------------------------\n" << endl;
//
//	double TotalBalances = 0;
//	if (vClients.size() == 0)
//	{
//		cout << "\t\t\tNo Client available in the system!";
//	}
//	else
//	{
//		for (sClient& Client : vClients)
//		{
//			PrintClientRecordLine(Client);
//			TotalBalances += Client.AccountBalance;
//			cout << endl;
//		}
//	}
//	cout << "\n-----------------------------------------------------------";
//	cout << "---------------------------------------------\n" << endl;
//	cout << "\t\t\t\tTotal Balances = " << TotalBalances << endl;
//
//}
//void PerformTransactionsOption(enTransactionsMenueOptions TransactionOption)
//{
//	switch (TransactionOption)
//	{
//	case enTransactionsMenueOptions::eDeposit:
//		system("cls");
//		ShowDepositMenueScreen();
//		GoBackToTransactionsMenue();
//		break;
//
//	case enTransactionsMenueOptions::eWithdraw:
//		system("cls");
//		ShowWithdrawMenueScreen();
//		GoBackToTransactionsMenue();
//		break;
//
//	case enTransactionsMenueOptions::eTotalBalances:
//		system("cls");
//		ShowTotalBalancesMenue();
//		GoBackToTransactionsMenue();
//		break;
//
//	case enTransactionsMenueOptions::eMainMenue:
//		ShowMainMenueScreen();
//	}
//}
//void ShowTransactionsMenueScreen()
//{
//	if (!CheckPermission(enMainMenuPermissions::pTransactions))
//	{
//		system("cls");
//		ShowDeniedAccessScreen();
//		GoBackToMainScreen();
//	}
//
//	system("cls");
//	cout << "===============================================\n";
//	cout << "\t\tTransactions Menue screen\n";
//	cout << "===============================================\n";
//
//	cout << "\t[1] Deposit.\n";
//	cout << "\t[2] Withdraw.\n";
//	cout << "\t[3] Total Balances.\n";
//	cout << "\t[4] Main Menue.\n";
//	cout << "===============================================\n";
//
//
//	PerformTransactionsOption((enTransactionsMenueOptions)ReadTransactionsOptions());
//}
//
//void PerformMainMenueOption(enMainMenueOptions MainMenueOption)
//{
//	switch (MainMenueOption)
//	{
//	case enMainMenueOptions::ShowClientList:
//	{
//		system("cls");
//		ShowClientListScreen();
//		GoBackToMainScreen();
//		break;
//	}
//	case enMainMenueOptions::AddNewClient:
//	{
//		system("cls");
//		ShowAddNewClientsScreen();
//		GoBackToMainScreen();
//		break;
//	}
//	case enMainMenueOptions::DeletClient:
//	{
//		system("cls");
//		ShowDeleteClientScreen();
//		GoBackToMainScreen();
//		break;
//	}
//	case enMainMenueOptions::UpdateClientInfo:
//	{
//		system("cls");
//		ShowUpdateClientScreen();
//		GoBackToMainScreen();
//		break;
//	}
//	case enMainMenueOptions::FindClient:
//	{
//		system("cls");
//		ShowFindClientScreen();
//		GoBackToMainScreen();
//		break;
//	}
//	case enMainMenueOptions::TransactionsMenue:
//	{
//		ShowTransactionsMenueScreen();
//		break;
//	}
//	case enMainMenueOptions::ManageUsers:
//	{
//		ShowManageUserScreen();
//	}
//	case enMainMenueOptions::Logout:
//
//		system("cls");
//		//ShowEndScreen();
//		Login();
//	}
//}
//void ShowMainMenueScreen()
//{
//	system("cls");
//	cout << "===============================================\n";
//	cout << "\t\tMain Menue screen\n";
//	cout << "===============================================\n";
//
//	cout << "\t[1] Show Client List.\n";
//	cout << "\t[2] Add New Client.\n";
//	cout << "\t[3] Delete Clinet.\n";
//	cout << "\t[4] Update Client info.\n";
//	cout << "\t[5] Find Client.\n";
//	cout << "\t[6] Transactions.\n";
//	cout << "\t[7] Manage Users.\n";
//	cout << "\t[8] Logout.\n";
//	cout << "===============================================\n";
//
//	PerformMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
//}
//
//
////Extention 2 from course8
//
////Functions for show clients list
//sUser ConvertUserLineToRecord(string Line, string Seperator = "#//#")
//{
//	sUser User;
//	vector<string> vUsersData = SplitString(Line, Seperator);
//
//	User.Username = vUsersData[0];
//	User.Password = vUsersData[1];
//	User.Permissions = stoi(vUsersData[2]);
//	
//
//	return User;
//
//
//}
//vector<sUser> LoadUserDataFromFile(string FileName)
//{
//	vector<sUser> vUsers;
//	fstream MyFile;
//	MyFile.open(FileName, ios::in);//read mode
//
//	if (MyFile.is_open())
//	{
//		string Line;
//		sUser Record;
//
//		while (getline(MyFile, Line))
//		{
//			Record = ConvertUserLineToRecord(Line);
//
//			vUsers.push_back(Record);
//		}
//		MyFile.close();
//	}
//	return vUsers;
//}
//void PrintUserData(sUser User)
//{
//	cout << "| " << left << setw(15) << User.Username;
//	cout << "| " << left << setw(10) << User.Password;
//	cout << "| " << left << setw(40) << User.Permissions;
//	
//}
//void PrintAllUsers(vector<sUser>& vUsers)
//{
//	cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ") User(s).";
//	cout << "\n-----------------------------------------------------------";
//	cout << "---------------------------------------------\n" << endl;
//	cout << "| " << left << setw(15) << "Username";
//	cout << "| " << left << setw(10) << "Password";
//	cout << "| " << left << setw(40) << "Permission";
//	
//	cout << "\n-----------------------------------------------------------";
//	cout << "---------------------------------------------\n" << endl;
//
//	if (vUsers.size() == 0)
//	{
//		cout << "\t\t\tNo User available in the system!";
//	}
//	else
//	{
//		for (sUser& u : vUsers)
//		{
//			PrintUserData(u);
//			cout << endl;
//		}
//	}
//	cout << "\n-----------------------------------------------------------";
//	cout << "---------------------------------------------\n" << endl;
//
//}
//
//bool UserExistByUsername(string Username, vector<sUser>& vUsers)
//{
//	for (sUser& u : vUsers)
//	{
//		if (u.Username == Username)
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
////Functions for Add User
//string ConvertUserRecordToLine(sUser UserData, string Seperator = "#//#")
//{
//	string User = " ";
//
//	User = UserData.Username + Seperator;
//	User += UserData.Password + Seperator;
//	User += to_string(UserData.Permissions);
//
//	return User;
//}
//short ReadPermissionToSet()
//{
//	short Permission = 0;
//	char Answer = 'Y';
//
//	cout << "\nDo you want to give full access? Y/N? ";
//	cin >> Answer;
//	if (Answer == 'Y' || Answer == 'y')
//	{
//		return -1;
//	}
//
//	cout << "\nDo you want to give access to: \n";
//
//	cout << "\nShow Client List? Y/N? ";
//	cin >> Answer;
//	if (Answer == 'Y' || Answer == 'y')
//	{
//		Permission = enMainMenuPermissions::pListClient;
//	}
//
//	cout << "\nAdd New Client? Y/N? ";
//	cin >> Answer;
//	if (Answer == 'Y' || Answer == 'y')
//	{
//		Permission += enMainMenuPermissions::pAddClient;
//	}
//
//	cout << "\nDelete Client? Y/N? ";
//	cin >> Answer;
//	if (Answer == 'Y' || Answer == 'y')
//	{
//		Permission += enMainMenuPermissions::pDeleteClient;
//	}
//
//	cout << "\nUpdate Client? Y/N? ";
//	cin >> Answer;
//	if (Answer == 'Y' || Answer == 'y')
//	{
//		Permission += enMainMenuPermissions::pUpdateClient;
//	}
//
//	cout << "\nFind Client? Y/N? ";
//	cin >> Answer;
//	if (Answer == 'Y' || Answer == 'y')
//	{
//		Permission += enMainMenuPermissions::pFindClient;
//	}
//
//	cout << "\nTransactions? Y/N? ";
//	cin >> Answer;
//	if (Answer == 'Y' || Answer == 'y')
//	{
//		Permission += enMainMenuPermissions::pTransactions;
//	}
//
//	cout << "\nManage User? Y/N? ";
//	cin >> Answer;
//	if (Answer == 'Y' || Answer == 'y')
//	{
//		Permission += enMainMenuPermissions::pManageUsers;
//	}
//
//	return Permission;
//}
//sUser ReadNewUser()
//{
//	vector<sUser> vUsers = LoadUserDataFromFile(UsersFileName);
//	sUser User;
//
//	cout << "Enter Username? ";
//	getline(cin >> ws, User.Username);
//	while (UserExistByUsername(User.Username, vUsers))
//	{
//		cout << "User with (" << User.Username << ") is already exist, Enter another one? ";
//		getline(cin >> ws, User.Username);
//	}
//
//	cout << "\nEnter Password? ";
//	getline(cin >> ws, User.Password);
//
//	User.Permissions = ReadPermissionToSet();
//
//	return User;
//}
//void AddUserToFile()
//{
//	sUser User = ReadNewUser();
//	AddDataLineToFile(UsersFileName, ConvertUserRecordToLine(User));
//}
//void AddUsersToFile()
//{
//	char AddMore = 'Y';
//
//	do
//	{
//		system("cls");
//		cout << "Adding new User\n\n";
//		AddUserToFile();
//
//		cout << "\nUser Added successfully, do you want to add more users? ";
//		cin >> AddMore;
//
//	} while (toupper(AddMore) == 'Y');
//}
//
////Functions For Delete User
//bool FindUserByUsername(string Username, sUser& User, vector<sUser>& vUsers)
//{
//	for (sUser& u : vUsers)
//	{
//		if (u.Username  == Username)
//		{
//			User = u;
//			return true;
//		}
//	}
//	return false;
//}
//void PrintUserCard(sUser User)
//{
//	cout << "\nThe following are user details:\n\n";
//	cout << "-------------------------------------\n";
//	cout << "Username : " << User.Username << endl;
//	cout << "Password : " << User.Password << endl;
//	cout << "Permissions : " << User.Permissions << endl;
//	cout << "-------------------------------------\n";
//
//}
//bool MarkUserForDeletByUsername(string Username, vector<sUser>& vUsers)
//{
//	for (sUser& u : vUsers)
//	{
//		if (u.Username == Username)
//		{
//			u.MarkForDelete = true;
//			return true;
//		}
//	}
//	return false;
//}
//vector<sUser> SaveUsersDataToFile(string FileName, vector<sUser>& vUsers)
//{
//	fstream MyFile;
//	MyFile.open(FileName, ios::out);//Write Mode
//
//	if (MyFile.is_open())
//	{
//		string DataLine;
//		for (sUser& u : vUsers)
//		{
//			if (u.MarkForDelete == false)
//			{
//				DataLine = ConvertUserRecordToLine(u);
//				MyFile << DataLine << endl;
//			}
//		}
//		MyFile.close();
//	}
//	return vUsers;
//}
//bool DeleteUserByUsername(string Username, vector<sUser>& vUsers)
//{
//	if (Username == "Admin")
//	{
//		cout << "\n\nYou cannot delete this user.\n";
//		return false;
//	}
//
//	char Answer = 'n';
//	sUser User;
//	if (FindUserByUsername(Username, User, vUsers))
//	{
//		PrintUserCard(User);
//
//		cout << "\n\nAre you sure you want to delete this client? y/n ?";
//		cin >> Answer;
//		if (toupper(Answer) == 'Y')
//		{
//			MarkUserForDeletByUsername(Username, vUsers);
//			SaveUsersDataToFile(UsersFileName, vUsers);
//
//			vUsers = LoadUserDataFromFile(UsersFileName);
//
//			cout << "\n\nUser Deleted successfully.\n";
//			return true;
//		}
//	}
//	else
//	{
//		cout << "User with username(" << Username << ") is Not Found!\n";
//		return false;
//	}
//
//}
//string ReadUsername()
//{
//	string Username;
//	cout << "Enter username? ";
//	getline(cin >> ws, Username);
//
//	return Username;
//}
//
////Functions for Update User
//sUser ChangeUserRecord(string Username)
//{
//	sUser User;
//
//	User.Username = Username;
//
//	cout << "Enter Password? ";
//	getline(cin >> ws, User.Password);
//
//	User.Permissions = ReadPermissionToSet();
//
//	return User;
//}
//bool UpdateUserByUsername(string Username, vector<sUser>& vUsers)
//{
//	char Answer = 'n';
//	sUser User;
//	if (FindUserByUsername(Username, User, vUsers))
//	{
//		PrintUserCard(User);
//
//		cout << "\n\nAre you sure you want to update this user? y/n ? ";
//		cin >> Answer;
//		if (toupper(Answer) == 'Y')
//		{
//			for (sUser& u : vUsers)
//			{
//				if (u.Username == Username)
//				{
//					u = ChangeUserRecord(Username);
//					break;
//				}
//			}
//			SaveUsersDataToFile(UsersFileName, vUsers);
//			cout << "\nUser updated successfully\n";
//			return true;
//
//		}
//	}
//	else
//	{
//		cout << "\n\nUser with username (" << Username << ") is Not Found!\n";
//		return false;
//	}
//
//}
//
//
//void GoBackToManageUserScreen()
//{
//	cout << "\n\nPress any key to go back manage menu...";
//	system("pause>0");
//
//	ShowManageUserScreen();
//}
//bool FindUserByUsernameAndPassword(string Username, string Password, sUser& CurrentUser)
//{
//	vector<sUser> vUsers = LoadUserDataFromFile(UsersFileName);
//
//	for (sUser& u : vUsers)
//	{
//		if (Username == u.Username && Password == u.Password)
//		{
//			CurrentUser = u;
//			return true;
//		}
//	}
//	return false;
//}
//bool LoadUserInfo(string Username, string Password)
//{
//	if (FindUserByUsernameAndPassword(Username, Password, CurrentUser))
//		return true;
//	else
//		return false;
//}
//
//void ShowUpdateUserScreen()
//{
//	cout << "---------------------------\n";
//	cout << "\tUpdate User screen";
//	cout << "\n---------------------------\n";
//
//	vector<sUser> vUsers = LoadUserDataFromFile(UsersFileName);
//	string Username = ReadUsername();
//	UpdateUserByUsername(Username, vUsers);
//}
//void ShowFindUserScreen()
//{
//	vector<sUser> vUsers = LoadUserDataFromFile(UsersFileName);
//	string Username = ReadUsername();
//	sUser User;
//	if (FindUserByUsername(Username, User, vUsers))
//	{
//		PrintUserCard(User);
//	}
//	else
//	{
//		cout << "\nUser with (" << Username << ") Not found!\n";
//	}
//}
//void ShowDeletUserScreen()
//{
//	cout << "--------------------------------\n";
//	cout << "\tDelete Users Screen\n";
//	cout << "--------------------------------\n";
//
//	vector<sUser> vUsers = LoadUserDataFromFile(UsersFileName);
//	string Username = ReadUsername();
//	DeleteUserByUsername(Username, vUsers);
//}
//void ShowUserListScreen()
//{
//	vector<sUser> vUsers = LoadUserDataFromFile(UsersFileName);
//	PrintAllUsers(vUsers);
//}
//void ShowAddUserScreen()
//{
//	AddUsersToFile();
//}
//
//short ReadManageMenuOptions()
//{
//	short Choice = 0;
//	cout << "Choose what do you want to do? [1 to 6]? ";
//	cin >> Choice;
//
//	return Choice;
//}
//void PerformManageUsersOptions(enManageUsersOptions Option)
//{
//	switch (Option)
//	{
//	case enManageUsersOptions::eListUser:
//	{
//		system("cls");
//		ShowUserListScreen();
//		GoBackToManageUserScreen();
//		break;
//	}
//	case enManageUsersOptions::eAddUser:
//	{
//		ShowAddUserScreen();
//		GoBackToManageUserScreen();
//		break;
//	}
//	case enManageUsersOptions::eDeleteUser:
//	{
//		system("cls");
//		ShowDeletUserScreen();
//		GoBackToManageUserScreen();
//		break;
//	}
//	case enManageUsersOptions::eUpdateUser:
//	{
//		system("cls");
//		ShowUpdateUserScreen();
//		GoBackToManageUserScreen();
//		break;
//	}
//	case enManageUsersOptions::eFindUser:
//	{
//		system("cls");
//		ShowFindUserScreen();
//		GoBackToManageUserScreen();
//		break;
//	}
//	case enManageUsersOptions::MainMenu:
//	{
//		ShowMainMenueScreen();
//		break;
//	}
//
//	}
//}
//
//void ShowManageUserScreen()
//{
//
//	if (!CheckPermission(enMainMenuPermissions::pManageUsers))
//	{
//		system("cls");
//		ShowDeniedAccessScreen();
//		GoBackToMainScreen();
//	}
//
//	system("cls");
//	cout << "===============================================\n";
//	cout << "\t\tManage Users screen\n";
//	cout << "===============================================\n";
//
//	cout << "\t[1] List Users.\n";
//	cout << "\t[2] Add New User.\n";
//	cout << "\t[3] Delete User.\n";
//	cout << "\t[4] Update User info.\n";
//	cout << "\t[5] Find User.\n";
//	cout << "\t[6] Main Menu.\n";
//	cout << "===============================================\n";
//
//	PerformManageUsersOptions((enManageUsersOptions)ReadManageMenuOptions());
//}
//
//void Login()
//{
//	bool LoginFailed = false;
//	string Username, Password;
//
//	do
//	{
//		system("cls");
//		cout << "\n---------------------------\n";
//		cout << "\t Login Screen\n";
//		cout << "---------------------------\n";
//
//		if (LoginFailed)
//		{
//			cout << "Invalid Username/Password!\n";
//		}
//
//		cout << "Enter Username? ";
//		getline(cin >> ws,Username);
//		cout << "Enter Password? ";
//		getline(cin >> ws, Password);
//
//		LoginFailed = !LoadUserInfo(Username, Password);
//
//	} while (LoginFailed);
//
//	ShowMainMenueScreen();
//}
//
//int main()
//{
//	
//	Login();
//	system("pause>0");
//}


//////// 


//CopyRight ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct stUser
{
    string UserName;
    string Password;
    int Permissions;
    bool MarkForDelete = false;
};

enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowMainMenue = 4 };

enum enManageUsersMenueOptions {
    eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
    eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
};

enum enMainMenueOptions {
    eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
    eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
    eManageUsers = 7, eExit = 8
};

enum enMainMenuePermissions {
    eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64
};

const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";

stUser CurrentUser;


void ShowMainMenue();
void ShowTransactionsMenue();
void ShowManageUsersMenue();
bool CheckAccessPermission(enMainMenuePermissions Permission);
void Login();


struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

vector<string> SplitString(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}

stUser ConvertUserLinetoRecord(string Line, string Seperator = "#//#")
{

    stUser User;
    vector<string> vUserData;

    vUserData = SplitString(Line, Seperator);

    User.UserName = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stoi(vUserData[2]);

    return User;

}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);//cast string to double


    return Client;

}

stUser ConvertUserLinetoRecord2(string Line, string Seperator = "#//#")
{
    stUser User;
    vector<string> vUserData;

    vUserData = SplitString(Line, Seperator);

    User.UserName = vUserData[0];
    User.Password = vUserData[1];
    User.Permissions = stoi(vUserData[2]);

    return User;

}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;

}

string ConvertUserRecordToLine(stUser User, string Seperator = "#//#")
{

    string stClientRecord = "";

    stClientRecord += User.UserName + Seperator;
    stClientRecord += User.Password + Seperator;
    stClientRecord += to_string(User.Permissions);

    return stClientRecord;

}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }


            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return false;


}

bool UserExistsByUsername(string Username, string FileName)
{


    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        stUser User;

        while (getline(MyFile, Line))
        {

            User = ConvertUserLinetoRecord(Line);
            if (User.UserName == Username)
            {
                MyFile.close();
                return true;
            }

        }

        MyFile.close();

    }

    return false;


}

sClient ReadNewClient()
{
    sClient Client;

    cout << "Enter Account Number? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }


    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;

}

int ReadPermissionsToSet()
{

    int Permissions = 0;
    char Answer = 'n';


    cout << "\nDo you want to give full access? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        return -1;
    }

    cout << "\nDo you want to give access to : \n ";

    cout << "\nShow Client List? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {


        Permissions += enMainMenuePermissions::pListClients;
    }


    cout << "\nAdd New Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pAddNewClient;
    }

    cout << "\nDelete Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pDeleteClient;
    }

    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pUpdateClients;
    }

    cout << "\nFind Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pFindClient;
    }

    cout << "\nTransactions? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pTranactions;
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pManageUsers;
    }


    return Permissions;

}

stUser ReadNewUser()
{
    stUser User;

    cout << "Enter Username? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, User.UserName);

    while (UserExistsByUsername(User.UserName, UsersFileName))
    {
        cout << "\nUser with [" << User.UserName << "] already exists, Enter another Username? ";
        getline(cin >> ws, User.UserName);
    }

    cout << "Enter Password? ";
    getline(cin, User.Password);

    User.Permissions = ReadPermissionsToSet();

    return User;

}

vector <stUser> LoadUsersDataFromFile(string FileName)  
{

    vector <stUser> vUsers;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        stUser User;

        while (getline(MyFile, Line))
        {

            User = ConvertUserLinetoRecord(Line);

            vUsers.push_back(User);
        }

        MyFile.close();

    }

    return vUsers;

}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{

    vector <sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);//read Mode

    if (MyFile.is_open())
    {

        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {

            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();

    }

    return vClients;

}

void PrintClientRecordLine(sClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void PrintUserRecordLine(stUser User)
{

    cout << "| " << setw(15) << left << User.UserName;
    cout << "| " << setw(10) << left << User.Password;
    cout << "| " << setw(40) << left << User.Permissions;
}

void PrintClientRecordBalanceLine(sClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowAccessDeniedMessage()
{
    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";
    cout << "\n------------------------------------\n";
}

void ShowAllClientsScreen()
{


    if (!CheckAccessPermission(enMainMenuePermissions::pListClients))
    {
        ShowAccessDeniedMessage();
        return;
    }

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

void ShowAllUsersScreen()
{


    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vUsers.size() == 0)
        cout << "\t\t\t\tNo Users Available In the System!";
    else

        for (stUser User : vUsers)
        {

            PrintUserRecordLine(User);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

void ShowTotalBalances()
{

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {

            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.AccountBalance;

            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;

}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";

}

void PrintUserCard(stUser User)
{
    cout << "\nThe following are the user details:\n";
    cout << "-----------------------------------";
    cout << "\nUsername    : " << User.UserName;
    cout << "\nPassword    : " << User.Password;
    cout << "\nPermissions : " << User.Permissions;
    cout << "\n-----------------------------------\n";

}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{

    for (sClient C : vClients)
    {

        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }

    }
    return false;

}

bool FindUserByUsername(string Username, vector <stUser> vUsers, stUser& User)
{

    for (stUser U : vUsers)
    {

        if (U.UserName == Username)
        {
            User = U;
            return true;
        }

    }
    return false;

}

bool FindUserByUsernameAndPassword(string Username, string Password, stUser& User)
{

    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    for (stUser U : vUsers)
    {

        if (U.UserName == Username && U.Password == Password)
        {
            User = U;
            return true;
        }

    }
    return false;

}

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;

}

stUser ChangeUserRecord(string Username)
{
    stUser User;

    User.UserName = Username;

    cout << "\n\nEnter Password? ";
    getline(cin >> ws, User.Password);

    User.Permissions = ReadPermissionsToSet();

    return User;

}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

bool MarkUserForDeleteByUsername(string Username, vector <stUser>& vUsers)
{
    for (stUser& U : vUsers)
    {
        if (U.UserName == Username)
        {
            U.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (sClient C : vClients)
        {

            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

    return vClients;

}

vector <stUser> SaveUsersDataToFile(string FileName, vector <stUser> vUsers)
{

    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite

    string DataLine;

    if (MyFile.is_open())
    {

        for (stUser U : vUsers)
        {

            if (U.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.  
                DataLine = ConvertUserRecordToLine(U);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

    return vUsers;

}

void AddDataLineToFile(string FileName, string  stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {

        MyFile << stDataLine << endl;

        MyFile.close();
    }

}

void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));

}

void AddNewUser()
{
    stUser User;
    User = ReadNewUser();
    AddDataLineToFile(UsersFileName, ConvertUserRecordToLine(User));

}

void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
        //system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";


        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}

void AddNewUsers()
{
    char AddMore = 'Y';
    do
    {
        //system("cls");
        cout << "Adding New User:\n\n";

        AddNewUser();
        cout << "\nUser Added Successfully, do you want to add more Users? Y/N? ";


        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');

}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{



    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);

            //Refresh Clients 
            vClients = LoadCleintsDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }

}

bool DeleteUserByUsername(string Username, vector <stUser>& vUsers)
{

    if (Username == "Admin")
    {
        cout << "\n\nYou cannot Delete This User.";
        return false;

    }

    stUser User;
    char Answer = 'n';

    if (FindUserByUsername(Username, vUsers, User))
    {

        PrintUserCard(User);

        cout << "\n\nAre you sure you want delete this User? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            MarkUserForDeleteByUsername(Username, vUsers);
            SaveUsersDataToFile(UsersFileName, vUsers);

            //Refresh Clients 
            vUsers = LoadUsersDataFromFile(UsersFileName);

            cout << "\n\nUser Deleted Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nUser with Username (" << Username << ") is Not Found!";
        return false;
    }

}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{

    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {

        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            for (sClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }

            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }

}

bool UpdateUserByUsername(string Username, vector <stUser>& vUsers)
{

    stUser User;
    char Answer = 'n';

    if (FindUserByUsername(Username, vUsers, User))
    {

        PrintUserCard(User);
        cout << "\n\nAre you sure you want update this User? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            for (stUser& U : vUsers)
            {
                if (U.UserName == Username)
                {
                    U = ChangeUserRecord(Username);
                    break;
                }

            }

            SaveUsersDataToFile(UsersFileName, vUsers);

            cout << "\n\nUser Updated Successfully.";
            return true;
        }

    }
    else
    {
        cout << "\nUser with Account Number (" << Username << ") is Not Found!";
        return false;
    }

}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients)
{
    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {

        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }

        }


        return false;
    }

}

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;

}

string ReadUserName()
{
    string Username = "";

    cout << "\nPlease enter Username? ";
    cin >> Username;
    return Username;

}

void ShowListUsersScreen()
{

    ShowAllUsersScreen();

}

void ShowAddNewUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New User Screen";
    cout << "\n-----------------------------------\n";

    AddNewUsers();


}

void ShowDeleteUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Users Screen";
    cout << "\n-----------------------------------\n";

    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    string Username = ReadUserName();
    DeleteUserByUsername(Username, vUsers);

}

void ShowUpdateUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Users Screen";
    cout << "\n-----------------------------------\n";

    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    string Username = ReadUserName();

    UpdateUserByUsername(Username, vUsers);
}

void ShowDeleteClientScreen()
{


    if (!CheckAccessPermission(enMainMenuePermissions::pDeleteClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);

}

void ShowUpdateClientScreen()
{
    if (!CheckAccessPermission(enMainMenuePermissions::pUpdateClients))
    {
        ShowAccessDeniedMessage();
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);

}

void ShowAddNewClientsScreen()
{

    if (!CheckAccessPermission(enMainMenuePermissions::pUpdateClients))
    {
        ShowAccessDeniedMessage();
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    AddNewClients();

}

void ShowFindClientScreen()
{


    if (!CheckAccessPermission(enMainMenuePermissions::pFindClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";

}

void ShowFindUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind User Screen";
    cout << "\n-----------------------------------\n";

    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    stUser User;
    string Username = ReadUserName();
    if (FindUserByUsername(Username, vUsers, User))
        PrintUserCard(User);
    else
        cout << "\nUser with Username [" << Username << "] is not found!";

}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";

}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";


    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();


    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }


    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);

}

void ShowWithDrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();


    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter withdraw amount? ";
    cin >> Amount;

    //Validate that the amount does not exceeds the balance
    while (Amount > Client.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);

}

void ShowTotalBalancesScreen()
{

    ShowTotalBalances();

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

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();
}

void GoBackToTransactionsMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowTransactionsMenue();

}

void GoBackToManageUsersMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowManageUsersMenue();

}

short ReadTransactionsMenueOption()
{
    cout << "Choose what do you want to do? [1 to 4]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
{
    switch (TransactionMenueOption)
    {
    case enTransactionsMenueOptions::eDeposit:
    {
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eWithdraw:
    {
        system("cls");
        ShowWithDrawScreen();
        GoBackToTransactionsMenue();
        break;
    }


    case enTransactionsMenueOptions::eShowTotalBalance:
    {
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenue();
        break;
    }


    case enTransactionsMenueOptions::eShowMainMenue:
    {

        ShowMainMenue();

    }
    }

}

void ShowTransactionsMenue()
{

    if (!CheckAccessPermission(enMainMenuePermissions::pTranactions))
    {
        ShowAccessDeniedMessage();
        GoBackToMainMenue();
        return;
    }

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tTransactions Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "===========================================\n";
    PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 8]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
{
    switch (ManageUsersMenueOption)
    {
    case enManageUsersMenueOptions::eListUsers:
    {
        system("cls");
        ShowListUsersScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eAddNewUser:
    {
        system("cls");
        ShowAddNewUserScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eDeleteUser:
    {
        system("cls");
        ShowDeleteUserScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eUpdateUser:
    {
        system("cls");
        ShowUpdateUserScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eFindUser:
    {
        system("cls");

        ShowFindUserScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eMainMenue:
    {
        ShowMainMenue();
    }
    }

}

short ReadManageUsersMenueOption()
{
    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void ShowManageUsersMenue()
{

    if (!CheckAccessPermission(enMainMenuePermissions::pManageUsers))
    {
        ShowAccessDeniedMessage();
        GoBackToMainMenue();
        return;
    }

    system("cls");
    cout << "===========================================\n";
    cout << "\t\tManage Users Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "===========================================\n";


    PerfromManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
    {
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eShowTransactionsMenue:
        system("cls");
        ShowTransactionsMenue();
        break;

    case enMainMenueOptions::eManageUsers:
        system("cls");
        ShowManageUsersMenue();
        break;

    case enMainMenueOptions::eExit:
        system("cls");
        // ShowEndScreen();
        Login();

        break;
    }

}

void ShowMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout.\n";
    cout << "===========================================\n";


    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

bool  LoadUserInfo(string Username, string Password)
{

    if (FindUserByUsernameAndPassword(Username, Password, CurrentUser))
        return true;
    else
        return false;

}

void Login()
{
    bool LoginFaild = false;

    string Username, Password;
    do
    {
        system("cls");

        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (LoginFaild)
        {
            cout << "Invlaid Username/Password!\n";
        }

        cout << "Enter Username? ";
        cin >> Username;

        cout << "Enter Password? ";
        cin >> Password;

        LoginFaild = !LoadUserInfo(Username, Password);

    } while (LoginFaild);

    ShowMainMenue();

}

int main()

{
    Login();

    system("pause>0");
    return 0;
}