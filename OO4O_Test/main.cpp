#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <tchar.h>

#include <oracl.h>
#include <obound.h>

#include "DBDialog.h"

void sendBonusEMPs(int amount, int *emps, int n)
{
	ODatabase db = OO4O_Test::DBDialog::LoginNewSession();
	
	db.GetParameters().Add("amount", amount, OPARAMETER_INVAR, OTYPE_NUMBER);
	OParamArray arr = db.GetParameters().AddTable("emps", OPARAMETER_INVAR, OTYPE_NUMBER, n);
	for (int i = 0; i < n; i++)
	{
		arr.SetValue(emps[i], i);
	}
	
	oresult res = db.ExecuteSQL("begin HR_PACKAGE_1.send_bonus_emps(:amount, :emps); end;");
	if (res != OSUCCESS)
	{
		std::cout << db.GetErrorText() << " " << db.GetServerErrorText() << std::endl;
	}

	db.GetParameters().Remove("amount");
	db.GetParameters().Remove("emps");
}

int main()
{
	OStartup();
	
	int emps[] = { 100, 101, 102, 103 };
	sendBonusEMPs(100, emps, 4);
	
	OShutdown();
	return 0;
}