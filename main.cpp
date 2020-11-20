#include "CDlgCommand.h"
#define EXTENSION (".txt")

void Init(CWorkspace& ws) {
	int Depth, Lengh;
	cout << "Enter Depth:";
	cin >> Depth;
	cout << "Enter Lengh:";
	cin >> Lengh;
	ws.Init(Depth, Lengh);
}
void Init_by_PI(CWorkspace& ws) {
	int Lengh;
	cout << "Enter Lengh:";
	cin >> Lengh;
	ws.Init_by_PI(Lengh);
}
void Save(CWorkspace& ws) {
	string name_file;
	cout << "Enter a name for the file where the data will be stored:";
	cin >> name_file;
	name_file += EXTENSION;
	if (ws.Save(name_file)) { cout << "Ok!\n"; }
	else { cout << "Error\n"; }
}
void Load(CWorkspace& ws) {
	string name_file;
	cout << "Enter the name of the file from which the data will be downloaded:";
	cin >> name_file;
	name_file += EXTENSION;
	if (ws.Load(name_file)) { cout << "Ok!\n"; }
}
void ShowFullSequence(CWorkspace& ws) {
	cout << ws.GetChainString() << endl;
}
void ShowAllLinks(CWorkspace& ws){
	ws.ShowAllLinks();
}

void Find(CWorkspace& ws) {
	int nPos;
	string str;
	cout << "Enter the ribbon we are looking for:";
	cin >> str;
	cout << "Indicate from which position we will start searching:";
	cin >> nPos;
	int temp = ws.Find(str.c_str(), nPos);
	if (temp == -1) { cout << "Unfortunately, there is no such tape\n"; }
	else { cout << "The tape at position " << temp << " is required\n"; }
}

void RemoveLink(CWorkspace& ws) {
	int position;
	cout << "Enter a position to delete:";
	cin >> position;
	if (ws.RemoveLink(position)) { cout << "Ok!\n"; }
	else { cout << "The index has gone beyond\n"; }
}

void AddPerson(CWorkspace& ws) {
	string Substr, sName;
	int nGroup;
	cout << "Enter string:";
	cin >> Substr;
	cout << "Enter the name:";
	cin >> sName;
	cout << "Enter number of group:";
	cin >> nGroup;
	if (ws.AddPerson(Substr.c_str(), nGroup, sName.c_str())) { cout << "Ok!\n"; }
	else { cout << "The index has gone beyond\n"; }
}

void AddURL(CWorkspace& ws) {
	string sSubStr, sURL;
	cout << "Enter string:";
	cin >> sSubStr;
	cout << "Enter url:";
	cin >> sURL;
	if (ws.AddURL(sSubStr.c_str(), sURL.c_str())) { cout << "Ok!\n"; }
	else { cout << "The index has gone beyond\n"; }
}

void TestPosition(CWorkspace& ws) {
	int nPos;
	LinksArray aNearestLinks;
	cout << "Enter position:";
	cin >> nPos;
	if (ws.TestPosition(nPos, aNearestLinks)) {
		cout << "The position is included " << aNearestLinks.size() << " links.\n";
	}
	else { cout << "We did not find any links.\n"; }
}

void TestInterval(CWorkspace& ws) {
	int nStartPos, nEndPos;
	LinksArray aNearestLinks;
	cout << "Enter start position:";
	cin >> nStartPos;
	cout << "Enter end position";
	cin >> nEndPos;
	if (ws.TestInterval(nStartPos, nEndPos, aNearestLinks)) {
		cout << "The position is included " << aNearestLinks.size() << " links.";
		cout << "\nin the range from " << nStartPos << " to " << nEndPos << endl;
	}
	else { cout << "We did not find any links.\nin the range from " << nStartPos << " to " << nEndPos << endl; }
}
int main(){
	CDataSimple data;
	CWorkspace ws(data);
	CDialogManager mgr(ws);
	mgr.RegisterCommand("Init sequence", Init);
	mgr.RegisterCommand("Init PI sequence", Init_by_PI);
	mgr.RegisterCommand("Show sequence", ShowFullSequence);
	mgr.RegisterCommand("Show links", ShowAllLinks);
	mgr.RegisterCommand("Add person", AddPerson);
	mgr.RegisterCommand("Add link",AddURL);
	mgr.RegisterCommand("Remove link", RemoveLink);
	mgr.RegisterCommand("Test position", TestPosition);
	mgr.RegisterCommand("Test interval", TestInterval);
	mgr.RegisterCommand("Find", Find);
	mgr.RegisterCommand("Save", Save);
	mgr.RegisterCommand("Load", Load);
	mgr.Run();
	return 0;
}