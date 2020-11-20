#pragma once
#include "CWorkspace.h"

typedef void (*ptDlgCommandFunc)(CWorkspace& ws);
class CDlgCommand {
public:
	CDlgCommand(const char* sName, ptDlgCommandFunc pFunc = NULL);
	~CDlgCommand(void);
	const char* GetName();
	void Run(CWorkspace& ws);
private:
	string m_sName;
	ptDlgCommandFunc m_pFunc;
};
class CDialogManager {
public:
	CDialogManager(CWorkspace& ws);
	~CDialogManager(void);
	void RegisterCommand(const char* sName, ptDlgCommandFunc pFunc);
	void Run();
private:
	vector<CDlgCommand*> m_aCommands;
	CWorkspace& m_refWorkspace;
};
