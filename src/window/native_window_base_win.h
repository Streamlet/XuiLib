#pragma once

#include "thunk_win.h"
#include "tls_win.h"
#include <functional>
#include <map>
#include <tchar.h>
#include <Windows.h>
#include <xui/gragh/rect.h>

namespace xui
{

class NativeWindowBase
{
  public:
    NativeWindowBase();
    virtual ~NativeWindowBase();

    bool Create(HWND hParent,
                const Rect &rect,
                DWORD style,
                DWORD exStyle,
                LPCTSTR className,
                LPCTSTR windowName = nullptr,
                HMENU menu = nullptr,
                HINSTANCE instalce = nullptr);
    bool Destroy();
    operator HWND() const;

  private:
    bool Attach(HWND hWnd);
    HWND Detach();

  protected:
    typedef std::function<LRESULT(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled)> MsgHandler;
    void RegisterMessageHandler(UINT uMsg, MsgHandler handler);

  private:
    LRESULT ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);

    static LRESULT CALLBACK StartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

  private:
    HWND hwnd_;
    WNDPROC original_proc_;
    Thunk<WNDPROC> thunk_;
#ifdef _DEBUG
    DWORD thread_id_;
#endif
    std::multimap<UINT, MsgHandler> msg_handlers_;

    static Tls tls_;
    static HFONT font_;
};

} // namespace xui
