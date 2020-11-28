#include "CDlgCommand.h"

typedef void (*ptDlgCommandFunc)(CWorkspace& ws);

CDlgCommand::CDlgCommand(const char* sName, ptDlgCommandFunc pFunc) {
	m_sName = sName;
	m_pFunc = pFunc;
}
CDlgCommand::~CDlgCommand(void) {
	m_sName = nullptr;
	m_pFunc = nullptr;
}
const char* CDlgCommand::GetName() { return m_sName.c_str(); }
void CDlgCommand::Run(CWorkspace& ws) {	m_pFunc(ws); }

CDialogManager::CDialogManager(CWorkspace& ws):m_refWorkspace(ws){
	m_aCommands.push_back(new CDlgCommand ("Quit"));
}
CDialogManager::~CDialogManager(void) {}
void CDialogManager::RegisterCommand(const char* sName, ptDlgCommandFunc pFunc) {
	m_aCommands.push_back(new CDlgCommand(sName, pFunc));
}
void CDialogManager::Run() {
	int nCommand = 666;
	while (nCommand) {
		for (size_t i = 0; i < m_aCommands.size(); i++)
			cout << i << " - " << m_aCommands[i]->GetName() << endl;
		cout << "Enter command:";
		cin >> nCommand;
		if ((nCommand > 0) && (nCommand < (int)m_aCommands.size()))
			m_aCommands[nCommand]->Run(m_refWorkspace);
		else { break; }
		system("pause");
		system("cls");
	}
}
