#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

int main() {
    HINSTANCE hInstance = GetModuleHandle(NULL);
    PWSTR pCmdLine = GetCommandLine();
    return wWinMain(hInstance, 0, pCmdLine, SW_SHOWNORMAL);
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CenterWindow(HWND);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow) {

    MSG  msg;    
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Center";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);
  
    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Center",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 250, 150, 0, 0, hInstance, 0);  

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, 
                         WPARAM wParam, LPARAM lParam) {

    switch(msg) {
        case WM_CREATE: 
            CenterWindow(hwnd);
            break;      

        case WM_DESTROY: 
            PostQuitMessage(0);
            break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void CenterWindow(HWND hwnd) {

    RECT rc = {0};
    
    GetWindowRect(hwnd, &rc);
    int win_w = rc.right - rc.left;
    int win_h = rc.bottom - rc.top;

    int screen_w = GetSystemMetrics(SM_CXSCREEN);
    int screen_h = GetSystemMetrics(SM_CYSCREEN);
    
    SetWindowPos(hwnd, HWND_TOP, (screen_w - win_w)/2, 
        (screen_h - win_h)/2, 0, 0, SWP_NOSIZE);
}