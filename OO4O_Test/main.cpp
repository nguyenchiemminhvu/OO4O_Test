#include <oracl.h>

using namespace System;

#define DEBUG Console::Write
#define DEBUG_LINE Console::WriteLine

int main()
{
	OStartup();

	ODatabase noncondb;
	oresult res = noncondb.Open("localhost:1521/NONCONDB", "HR", "HR");
	if (res != OSUCCESS)
	{
		DEBUG_LINE("Can not open NONCONDB database");
		return -1;
	}

	ODynaset allEmp(noncondb, "select * from employees");
	double salary = 0.0f;
	while (!allEmp.IsEOF())
	{
		allEmp.GetFieldValue("salary", &salary);
		
		DEBUG_LINE(salary);

		allEmp.MoveNext();
	}

	noncondb.Close();
	OShutdown();
	return 0;
}