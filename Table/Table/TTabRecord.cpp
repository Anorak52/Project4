#include "TTabRecord.h"
#include "TArrayTable.h"

TTabRecord::TTabRecord()
{
}


TTabRecord::~TTabRecord()
{
}
	
TTabRecord & operator = (TTabRecord &tr)// ������������ 
{
		Key = tr.Key; pValue = tr.pValue;
		return *this;
}
