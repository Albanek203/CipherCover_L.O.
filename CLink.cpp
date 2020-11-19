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
		so << "Size:" << m_nSize << " Pos:" << m_nPos;
		return true;
	}

	//����� ��"��� �� �������� ������
	virtual bool Load(istream& is) { 
		string arr,value = "";
		int i = 5;
		getline(is, arr);		
		while (arr[i] != ' ') { value += arr[i]; i++; }
		m_nSize = stoi(value.c_str());
		value = "";
		arr.erase(0, i + 5);
		i = 0;
		while (isdigit(arr[i])) { value += arr[i]; i++; }
		m_nPos = stoi(value.c_str());
		return true;
	}

	void Assignment_nPos_nSize(int nPos,int nSize) {
		m_nPos = nPos;
		m_nSize = nSize;
	}
	void Get_nPosAND_nSize() {
		cout << "Size:" << m_nSize << " Pos:" << m_nPos<< endl;
	}
protected:
	//��������� �� ��������� � ������ �����������
	CDataChain& m_refChain;
	//������� ������� � ����� �����������
	int m_nPos;
	//������� ��������, �� ��� ����"������� ��"���
	int m_nSize;
};
typedef vector<CLink*> LinksArray;