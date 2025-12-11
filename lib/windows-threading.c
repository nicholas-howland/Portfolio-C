#include <windows.h>
#include <stdio.h>

DWORD WINAPI MyBackgroundFunction(LPVOID lpParam) {
    for (int i = 0; i < 5; i++) {
        printf("Running in background...\n");
        Sleep(1000); // insert code to run in the background here
    }
    return 0;
}

int main() {
    HANDLE hThread = CreateThread(NULL, 0, MyBackgroundFunction, NULL, 0, NULL);
    
    if (hThread != NULL) {
        WaitForSingleObject(hThread, INFINITE);
        CloseHandle(hThread);
    }
    
    printf("Background function completed.\n");
    return 0;
}
