#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <fstream>

#include <string.h>
#include <cstring>
#include <string>

#include <Windows.h>
#include "TDateValue.h"

using namespace std;

//typedef string TKey // ��� ����� ������
// ����� ��������-�������� ��� ������� �������
typedef TTabRecord* PTTabRecord;
class TTabRecord : public TDatValue {
protected: // ����
	string Key; // ���� ������
	PTDatValue pValue; // ��������� �� ��������
public: // ������
	TTabRecord(string k = "", PTDatValue pVal = NULL);// �����������
	void SetKey(string k);// ���������� �������� �����
	string GetKey(void); // �������� �������� �����
	void SetValuePtr(PTDatValue p);// ���������� ��������� �� ������
	PTDatValue GetValuePTR(void); // �������� ��������� �� ������
	virtual TDatValue * GetCopy(); // ���������� �����
	TTabRecord & operator = (TTabRecord &tr);// ������������
	virtual int operator == (const TTabRecord &tr); // ��������� =
	virtual int operator < (const TTabRecord &tr); // ��������� �<�
	virtual int operator > (const TTabRecord &tr); // ��������� �>�
   //������������� ������ ��� ��������� ����� ������, ��. �����
	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
};