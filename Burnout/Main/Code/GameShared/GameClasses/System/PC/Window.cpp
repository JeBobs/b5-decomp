#include "Window.hpp"


bool g_01397E63;
bool g_0139813C;
bool g_0139813E;
bool g_0139813F;
HWND g_0139815C;
bool g_01398242;


void fn_008FB500()
{
    MSG msg;
    msg.message = 0;
    while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
        {
            g_0139813F = true;
        }

        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    fn_008FB8F0();
    if (g_01397E63)
    {
        PostQuitMessage(0);
        g_01397E63 = false;
    }
}

HWND fn_008FB590(int p1, int p2, bool p3)
{
    HMODULE moduleHandle = GetModuleHandleA(nullptr);
    
    char moduleFileName[MAX_PATH];
    GetModuleFileNameA(nullptr, moduleFileName, MAX_PATH);

    WNDCLASSA wndClass;
    wndClass.style = 0;
    wndClass.lpfnWndProc = fn_008FB9D0;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = moduleHandle;
    wndClass.hIcon = ExtractIconA(moduleHandle, moduleFileName, 0);
    wndClass.hCursor = LoadCursorA(nullptr, IDC_ARROW);
    wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
    wndClass.lpszMenuName = nullptr;
    wndClass.lpszClassName = "BurnoutParadiseWindowClass";
    if (RegisterClassA(&wndClass) == 0 && GetLastError() != ERROR_CLASS_ALREADY_EXISTS)
    {
        return nullptr;
    }

    RECT rect;
    SetRect(&rect, 0, 0, p1, p2);
    AdjustWindowRect(&rect, p3 ? (WS_POPUP | WS_CLIPCHILDREN) : (WS_CLIPCHILDREN | WS_BORDER | WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX), FALSE);

    // TODO: finish this function
}

void fn_008FB8F0()
{
    if (g_0139813E)
    {
        if (!g_0139813C || g_01398242)
        {
            ShowCursor(FALSE);
            ClipCursor(nullptr);

            while (ShowCursor(TRUE) < 0)
            {
            }
        }
        else
        {
            RECT windowRect;
            if (GetClientRect(g_0139815C, &windowRect))
            {
                POINT pt1, pt2;
                pt1.x = windowRect.left;
                pt1.y = windowRect.top;
                pt2.x = windowRect.right;
                pt2.y = windowRect.bottom;
                ClientToScreen(g_0139815C, &pt1);
                ClientToScreen(g_0139815C, &pt2);

                RECT screenRect;
                screenRect.left = pt1.x;
                screenRect.top = pt1.y;
                screenRect.right = pt2.x;
                screenRect.bottom = pt2.y;
                ClipCursor(&screenRect);

                while (ShowCursor(FALSE) >= 0)
                {
                }
            }
        }

        g_0139813E = false;
    }
}

LRESULT CALLBACK fn_008FB9D0(HWND p1, UINT p2, WPARAM p3, LPARAM p4)
{

}
