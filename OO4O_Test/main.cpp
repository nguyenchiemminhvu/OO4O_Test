#include <string>
#include <iostream>
#include <afxwin.h>

#include <oracl.h>
#include <obound.h>
#include <omfc.h>

using namespace System;
using namespace System::Runtime::InteropServices;

int main()
{
	OStartup();
	
	ODatabase db("localhost:1521/NONCONDB", "HR", "HR");
	ODynaset ds(db, "select sum(SALARY) as sumsal from EMPLOYEES");
	ds.MoveFirst();
	if (!ds.IsEOF())
	{
		double s;
		ds.GetField("sumsal").GetValue(&s);
		std::cout << s << std::endl;
	}
	
	OShutdown();
	return 0;
}