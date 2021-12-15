#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

int main() {
    HINSTANCE hInstance = GetModuleHandle(NULL);
    PWSTR pCmdLine = GetCommandLine();
    return wWinMain(hInstance, 0, pCmdLine, SW_SHOWNORMAL);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
    LPCWSTR myText = L"Text for the message box";
    LPCWSTR myCaption = L"Caption for the message box";
    MessageBoxW(NULL, myText, myCaption, MB_OKCANCEL);
    return 0;
}