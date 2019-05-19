#include "TTabRecord.h"
#include "TArrayTable.h"

TTabRecord::TTabRecord()
{
}


TTabRecord::~TTabRecord()
{
}

TTabRecord & TTabRecord::operator=(const TTabRecord & st)
{
	if (TabSize != st.TabSize) {
		TabSize = st.maxsize;
		delete[] mas;
		mas = new T[TabSize];
	}
	for (int i = 0; i < TabSize; i++)
		mas[i] = st.mas[i];
	pos = st.pos;
}
