#include "CDataChain.h"

CDataChain::CDataChain(void) {}
CDataChain::~CDataChain(void) {}
void CDataSimple::Generate(int nDepth, int nMaxLength){
	string gen = "";
	for (int iter = 0; iter <= nDepth; iter++) {
		if (size(gen) > nMaxLength) { break; }
		gen += to_string(iter);
	}
	m_sChain = gen + "\n";
}
const char* CDataSimple::GetFullString() { return m_sChain.c_str(); }
void CDataSimple::Assignment(string str) { m_sChain = str; }
int CDataSimple::Find(const char* sSubStr, int nPos) {
	string Sub = m_sChain;
	Sub.erase(0, nPos);
	if (Sub.find(sSubStr)) { return Sub.rfind(sSubStr) + nPos; }
	else { return -1; }
}
size_t CDataSimple::GetLength() { return size(m_sChain); }


void CDataPi::Generate(int nDepth, int nMaxLenght) {
	ifstream temp_r;
	ofstream temp_w;
	string str;
	temp_w.open("temp.txt");
	temp_w << setprecision(nMaxLenght) << 4. * atan(1.);
	temp_w.close();
	temp_r.open("temp.txt");
	getline(temp_r, str);
	temp_r.close();
	remove("temp.txt");
	str.erase(str.find('.'), 1);
	m_sChain = str + "\n";
}
const char* CDataPi::GetFullString() { return m_sChain.c_str(); }
void CDataPi::Assignment(string str) { m_sChain = str; }
int CDataPi::Find(const char* sSubStr, int nPos) {
	string Sub = m_sChain;
	Sub.erase(0, nPos);
	if (Sub.find(sSubStr)) { return Sub.rfind(sSubStr) + nPos; }
	else { return -1; }
}
size_t CDataPi::GetLength() { return size(m_sChain); }
string CDataPi::ChangeString() { return m_sChain; }