#include <iostream>
#include <string> 
#include <fstream>
#include "CLink.cpp"
using namespace std;
class CWorkspace {
public:
	CWorkspace(CDataChain& data) :m_refChain(data) {}
	~CWorkspace(void) {}

	const char* GetChainString() { return m_refChain.GetFullString(); }
	void Init(int nDepth, int nLength) {
		m_refChain.Generate(nDepth, nLength);
	}
	bool Save(string& sFilepath) {
		string strforsave = GetChainString();
		cout << strforsave;
		ofstream outfile(sFilepath, fstream::app);
		outfile << size(strforsave) - 1 << endl;
		outfile << strforsave << endl;
		outfile << m_aLinks.size();
		for (int iter = 0; iter < m_aLinks.size(); iter++) {
			m_aLinks[iter]->Save(outfile);
		}
		outfile.close();
		return true;
	}
	bool Load(string& sFilepath) {
		ifstream infail; 
		infail.open(sFilepath);

		if (!infail.is_open()) { cout << "Error. Fail is not open."; return false; }
		else {
			string arr, rstr;
			while (!infail.eof()) {
				getline(infail, arr);				
				rstr += arr + "\n";

			}
			m_refChain.Assignment(rstr);
			infail.close();
			return true;
		}
	}
	int Find(const char* sSubStr, int nPos = 0) {
		return m_refChain.Find(sSubStr, nPos);
	}
	bool AddLink(int nStartPos, int nLength, CLink* pLink) {
		pLink->Assignment_nPos_nSize(nStartPos, nLength);
		return true;
	}
	bool RemoveLink(int nPosInList) {
		if (m_aLinks.size() < nPosInList) { return false; }
		m_aLinks.erase(m_aLinks.begin() + nPosInList - 1);
		return true;
	}
	bool GetAllLinks(LinksArray& aLinks) {
		for (int iter = 0; iter < m_aLinks.size(); iter++) {
			aLinks.push_back(m_aLinks[iter]);
		}
		return true;
	}
	void ShowAllLinks() {
		for (int iter = 0; iter < m_aLinks.size(); iter++) {
			m_aLinks[iter]->Get_nPosAND_nSize();
		}
	}

private:
	//������ �� ��������� (���������� �� CDataChain) �� ������������
	CDataChain& m_refChain;
	LinksArray m_aLinks;
};