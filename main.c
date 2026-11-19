#include <stdio.h>
#include <stdio.h>
#include <windows.h>
DWORD WINAPI print_message(LPVOID ptr){
	char *message;
	message = (char *) ptr;
	Sleep(1000);
	printf("%s", message);
	return 0;
}

int main(int argc, char* argv[]){
	DWORD threadID1, threadID2;
	HANDLE threadH1, threadH2;
	char *message1 = "hello \n";
	char *message2 = "world";
	threadH1 = CreateThread(NULL, 0, print_message, message1, 0, &threadID1);
	threadH2 = CreateThread(NULL, 0, print_message, message2, 0, &threadID2);
	/* (a) */
	WaitForSingleObject(threadH1, INFINITE);
	/* (b) */
	WaitForSingleObject(threadH2, INFINITE);
	
	CloseHandle(threadH1);
	CloseHandle(threadH2);
	Sleep(1000);
	return 0;
}

