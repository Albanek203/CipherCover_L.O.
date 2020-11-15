#include "CDataChain.cpp"
#include <vector>
class CLink {
public:
	CLink(CDataChain& refChain) :m_refChain(refChain) {}
	/*virtual ~CLink(void);*/

	////����� ����"����� ��"��� �� �������� � �����������
	//bool Attach(const char* sSubStr);

	////������������ ���� �� �������
	//virtual void Output(ostream& os);

	virtual bool Save(ostream& so) {
		so << "Size:" << m_nSize << "\nPos:" << m_nPos;
		return 0;
	}

	//����� ��"��� �� �������� ������
	virtual bool Load(istream& is) {}

	void Assignment_nPos_nSize(int nPos,int nSize) {
		m_nPos = nPos;
		m_nSize = nSize;
	}
protected:
	//��������� �� ��������� � ������ �����������
	CDataChain& m_refChain;
	//������� ������� � ����� �����������
	int m_nPos;
	//������� ��������, �� ��� ����"������� ��"���
	int m_nSize;
};typedef vector<CLink*> LinksArray;