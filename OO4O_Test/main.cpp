#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <tchar.h>
#include <process.h>

#include <oracl.h>
#include <obound.h>

#include "DBDialog.h"

class OBinderDEPT : public OBinder
{
public:
	virtual oresult PostMove(void)
	{
		std::cout << "In PostMove... " << std::endl;

		OValue deptID;
		this->GetDynaset().GetField("DEPARTMENT_ID").GetValue(&deptID);

		std::string sql= "select * from EMPLOYEES where department_id = ";
		String ^temp = ((int)deptID).ToString();
		IntPtr pTemp = Marshal::StringToHGlobalAnsi(temp);
		std::string sTemp = std::string((char *)pTemp.ToPointer());
		sql += sTemp;

		_empInDept->SetSQL(sql.c_str());
		_empInDept->RefreshQuery();

		ODynaset empDS = _empInDept->GetDynaset();
		
		while (!empDS.IsEOF())
		{
			OValue emp_name, dept_id;
			empDS.GetField("LAST_NAME").GetValue(&emp_name);
			empDS.GetField("DEPARTMENT_ID").GetValue(&dept_id);

			std::cout << (int)dept_id << " " << (const char *)emp_name << std::endl;

			empDS.MoveNext();
		}
		std::cout << std::endl;

		Marshal::FreeHGlobal(pTemp);
		return OSUCCESS;
	}

	void setDept(OBinder *deptBinder, ODatabase *db)
	{
		_empInDept = deptBinder;
		_db = db;
	}

private:
	OBinder *_empInDept;
	ODatabase *_db;
};

int main()
{
	OStartup();
	
	ODatabase db = OO4O_Test::DBDialog::Login();
	
	OBinderDEPT deptBinder;
	deptBinder.Open(db, "select * from DEPARTMENTS");
	
	ODynaset deptDS = deptBinder.GetDynaset();
	
	OBinder empInDeptBinder;
	empInDeptBinder.Open(db, 0);
	deptBinder.setDept(&empInDeptBinder, &db);
	
	deptDS.MoveFirst();
	while (!deptDS.IsEOF())
	{
		deptDS.MoveNext();
	}

	OShutdown();
	return 0;
}