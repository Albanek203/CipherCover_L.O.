#include "CLink.h"

CLink::CLink(CDataChain& refChain) :m_refChain(refChain) {}
CLink::~CLink(void) {}
bool CLink::Save(ostream& so) {
	so << "Size:" << m_nSize << " Pos:" << m_nPos;
	return true;
}
bool CLink::Load(istream& is) {
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

void CLink::Assignment_nPos_nSize(int nPos,int nSize) {
	m_nPos = nPos;
	m_nSize = nSize;
}
void CLink::Get_nPosAND_nSize() { cout << "Size:" << m_nSize << " Pos:" << m_nPos<< endl; }
int CLink::Take_nPos() { return m_nPos; }

typedef vector<CLink*> LinksArray;


CLinkURL::CLinkURL(CDataChain& refChain) :CLink(refChain) {}
CLinkURL:: ~CLinkURL(void) {}
void CLinkURL::Add_URL(const char* str) { m_sURL = str; }


CLinkPerson::CLinkPerson(CDataChain& refChain) :CLink(refChain) {}
CLinkPerson::~CLinkPerson(void) {}
void CLinkPerson::AssigmentGroup(int member) { m_nGroupCode = member; }
void CLinkPerson::AssigmentName(string name) { m_sName = name; }
