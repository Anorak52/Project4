#include "TArrayTable.h"

class TScanTable : public TArrayTable {
public:
	TScanTable(int Size = TabMaxSize) : TArrayTable(Size) {};//�����������
	// �������� ������
	virtual PTDatValue FindRecord(string k);//����� ������
	virtual void InsRecord(string k, PTDatValue pVal);//��������
	virtual void DelRecord(string k);//������� ������
};