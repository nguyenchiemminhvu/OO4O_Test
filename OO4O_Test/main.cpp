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
	
	ODatabase db = OO4O_Test::DBDialog::Login();

	
	
	OShutdown();
	return 0;
}