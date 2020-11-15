#include "CDataChain.cpp"
#include <vector>
typedef vector<CLink*> LinksArray;
class CLink
{
public:
	CLink(CDataChain& refChain) :m_refChain(refChain) {}
	virtual ~CLink(void);

	////����� ����"����� ��"��� �� �������� � �����������
	//bool Attach(const char* sSubStr);

	////������������ ���� �� �������
	//virtual void Output(ostream& os);

	//������ ��"��� � ��������� ������
	virtual bool Save(ostream& so) {
		so << "Size:" << m_nSize << "\nPos:" << m_nPos;
	}

	////����� ��"��� �� �������� ������
	//virtual bool Load(istream& is);
protected:
	//��������� �� ��������� � ������ �����������
	CDataChain& m_refChain;
	//������� ������� � ����� �����������
	int m_nPos;
	//������� ��������, �� ��� ����"������� ��"���
	int m_nSize;
};