#include "CWorkspace.cpp"
using namespace  std;
typedef void (*ptDlgCommandFunc)(CWorkspace& ws);

class CDlgCommand
{
public:
	CDlgCommand(const char* sName, ptDlgCommandFunc pFunc = NULL) {
		m_sName = sName;
		m_pFunc = pFunc;
	}
	~CDlgCommand(void) {}
	const char* GetName() { return m_sName.c_str(); }
	void Run(CWorkspace& ws) {
		m_pFunc(ws);
	}
private:
	string m_sName;
	ptDlgCommandFunc m_pFunc;
};
class CDialogManager {
public:
	CDialogManager(CWorkspace& ws):m_refWorkspace(ws){
		m_aCommands.push_back(new CDlgCommand ("Quit"));
	}

	~CDialogManager(void) {}

	void RegisterCommand(const char* sName, ptDlgCommandFunc pFunc) {
		m_aCommands.push_back(new CDlgCommand(sName, pFunc));
	}

	void Run() {
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
private:
	vector<CDlgCommand*> m_aCommands;
	CWorkspace& m_refWorkspace;
};
