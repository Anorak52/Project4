#include "TScanTable.h"
#include "TTabRecord.h"
#include "TDateValue.h"

enum TSortMethod { INSERT_SORT, MERGE_SORT, QUIQ_SORT };
class TSortTable : public TScanTable {
protected:
	TSortMethod SortMethod; // ����� ����������
	void SortData(void); // ���������� ������
	void InsertSort(PTTabRecord *pMem, int DataCount); // ����� �������
	void MergeSort(PTTabRecord *pMem, int DataCount); // ����� �������
	void MergeSorter(PTTabRecord * &pData, PTTabRecord * &pBuff, int Size);
	void MergeData(PTTabRecord *&pData, PTTabRecord *&pBuff, int n1, int n2);
	void QuiqSort(PTTabRecord *pMem, int DataCount); // ������� ����������
	void QuiqSplit(PTTabRecord *pData, int Size, int &Pivot);
public:
	TSortTable(int Size = TabMaxSize) : TScanTable(Size) {};// �����������
	TSortTable(const TScanTable &tab); // �� ��������������� �������
	TSortTable & operator=(const TScanTable &tab); // ������������
	TSortMethod GetSortMethod(void); // �������� ����� ����������
	void SetSortMethod(TSortMethod sm);// ���������� ����� ����������
	// �������� ������
	virtual PTDatValue FindRecord(string k); // ����� ������
		virtual void InsRecord(string k, PTDatValue pVal); // ��������
	virtual void DelRecord(string k); // ������� ������
};
