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
		outfile << size(strforsave) << endl;
		outfile << strforsave << endl;
		outfile << m_aLinks.size();
		for (int iter = 0; iter <= m_aLinks.size(); iter++) {
			*m_aLinks[iter]->Save(outfile);
		}
		outfile.close();
		return true;
	}
	bool Load(string& sFilepath) {
		ifstream infail; // Вхідні данні
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
private:
	//Зсилка на контейнер (породжений від CDataChain) із послідовністю
	CDataChain& m_refChain;
	LinksArray m_aLinks;
};