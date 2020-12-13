#include<iostream>
#include<string>
#include"ABnomalReturn.h"
#include"KVDBHandler.h"
using namespace std;
int main()
{
	KVDBHandler* handler;
	handler = new KVDBHandler("test.txt");
	string command;
	while (1)
	{
		cout << "******************************" << endl;
		cout << "This K-V Database named 'test' does not support Chinese,does not support empty value,does not support space input" << endl;
		cout << "Command list:" << endl;
		cout << "1. SET" << endl;
		cout << "2. GET" << endl;
		cout << "3. DEL" << endl;
		cout << "4. PURGE" << endl;
		cout << "5. EXIT" << endl;
		cout << "******************************" << endl;
		cout << "Please enter your command serial number according to the command list:" << endl;
		cout << "command serial number:";
		cin >> command;
		if (command == "1")
		{
			string key, value;
			cout << "key=";
			cin >> key;
			cout << "value=";
			cin >> value;
			int flag = set(handler, key, value);
			if (flag == FILE_OPENIBG_FAILED)
				cout << "FILE_OPENIBG_FAILED!" << endl << "Set failed";
			else cout << "Set success" << endl;
		}
		else if (command == "2")
		{
			string value, key;
			cout << "key=";
			cin >> key;
			int flag = get(handler, key, value);
			if (flag == SUCCESS)
				cout << "Get success" << endl << key << "'s value=" << value << endl;
			else if (flag == KEY_NOT_EXIST)
				cout << "Get failed! Key does not exist" << endl;
			else if (flag == KEY_DELETED)
				cout << "Get failed! Key has been deleted" << endl;
			else if (flag == MEOMORY_ALLOCATION_FAILUER)
				cout << "MEOMORY_ALLOCATION_FAILUER" << endl;
			else if (flag == FILE_OPENIBG_FAILED)
				cout << "FILE_OPENIBG_FAILED" << endl;
		}
		else if (command == "3")
		{
			string key;
			cout << "key=";
			cin >> key;
			int flag = del(handler, key);
			if (flag == SUCCESS)
				cout << "Dellete success!" << endl;
			else if (flag == KEY_NOT_EXIST)
				cout << "Delete failed! Key does not exist" << endl;
			else if (flag == KEY_DELETED)
				cout << "Delete failed! Key has been deleted" << endl;
			else if (flag == MEOMORY_ALLOCATION_FAILUER)
				cout << "MEOMORY_ALLOCATION_FAILUER" << endl;
			else if (flag == FILE_OPENIBG_FAILED)
				cout << "FILE_OPENIBG_FAILED" << endl;
		}
		else if (command == "4")
		{
			int flag = purge(handler);
			if (flag == SUCCESS)
				cout << "Purge success" << endl;
			else cout << "Purge failed!" << endl;
		}
		else if (command == "5")
		{
			cout << "Thank you for your use" << endl;
			break;
		}
		else cout << "error command" << endl;
		system("pause");
		system("cls");
	}
	return 1;
}