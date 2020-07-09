#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	short colonProbability = 30;
	char keys[] = {'A','S','D'};
	string randomLaugh = "";
	
	for(int i = 0; i < rand() % 20 + 15; i++) if(rand() % 100 > colonProbability) randomLaugh += keys[rand() % 3]; else randomLaugh += ':';
	
	const char* output = randomLaugh.c_str();
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
    
	return 0;
}
