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
		ofstream outfile(sFilepath, fstream::app);
		outfile << size(strforsave) - 1 << endl;
		outfile << GetChainString();
		outfile << m_aLinks.size() << endl;
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
			int rout = 1, many_Links = 0,i=0;
			string arr, resultstr, size_Links = "";
			while (!infail.eof()) {
				getline(infail, arr);	
				if (rout == 5) {
					if (arr[0] != 'S') {
						rout = 1;
						many_Links = 0;
						i = 0;
					}
				}
				if (rout == 2) { resultstr += arr + "\n"; }
				if (rout >= 3) {
					if (rout == 3) {
						for (i = 0; i < size(arr); i++) { size_Links += arr[i]; }
						many_Links = atoi(size_Links.c_str());
					}
					for (int iter = 0; iter < many_Links; iter++) {
						AddLink(0, 0, new CLink(m_refChain));
						m_aLinks[iter]->Load(infail);
					}
				}				
				rout++;
			}
			m_refChain.Assignment(m_refChain.GetFullString() + resultstr);
			infail.close();
			return true;
		}
	}
	int Find(const char* sSubStr, int nPos = 0) {
		return m_refChain.Find(sSubStr, nPos);
	}
	bool AddLink(int nStartPos, int nLength, CLink* pLink) {
		pLink->Assignment_nPos_nSize(nStartPos, nLength);
		m_aLinks.push_back(pLink);
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