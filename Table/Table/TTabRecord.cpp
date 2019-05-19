#include "TTabRecord.h"
#include "TArrayTable.h"

TTabRecord::TTabRecord()
{
}


TTabRecord::~TTabRecord()
{
}
	
TTabRecord & operator = (TTabRecord &tr)// присваивание 
{
		Key = tr.Key; pValue = tr.pValue;
		return *this;
}
