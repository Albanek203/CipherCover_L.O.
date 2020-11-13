#include <iostream>
#include <string> 
#include <fstream>
#include "CDataChain.cpp"
using namespace std;
class CWorkspace {
public:
	CWorkspace(CDataChain& data) :m_refChain(data) {}
	~CWorkspace(void) {}

	const char* GetChainString() { return m_refChain.GetFullString(); }
	bool Save(string& sFilepath) {
		ofstream outfile(sFilepath, fstream::app);
		outfile << GetChainString() << endl;
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
private:
	//Зсилка на контейнер (породжений від CDataChain) із послідовністю
	CDataChain& m_refChain;
};