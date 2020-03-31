#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <tchar.h>

#include <oracl.h>
#include <obound.h>

#include "DBDialog.h"

int main()
{
	OStartup();
	
	OO4O_Test::DBDialog ^diag = gcnew OO4O_Test::DBDialog();
	diag->ShowDialog(nullptr);

	ODatabase db = diag->GetDatabase();
	
	if (!db.IsOpen())
	{
		std::cout << db.ErrorNumber() << std::endl;
		return -1;
	}
	else
	{
		std::cout << "Connected" << std::endl;
	}
	
	OShutdown();
	return 0;
}