#pragma once

#include "../renderer/gdi_renderer_win.h"
#include "native_window_base_win.h"
#include <memory>
#include <xui/window/child_window.h>
#include <xui/window/root_window.h>

namespace xui
{

class NativeWindow : public NativeWindowBase
{
  public:
    NativeWindow(RootWindow *window);
    ~NativeWindow();

  private:
    LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);

    LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    void Redraw();
    void RenderWindow(Window *window, HDC hDC, Rect rect);

    LRESULT OnSysKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnSysKeyUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnKeyUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnUniChar(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnLButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnLButtonDblClk(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnRButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnRButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnRButtonDblClk(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnMButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnMButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnMButtonDblClk(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnXButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnXButtonUp(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnXButtonDblClk(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnMouseWheel(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnMouseHWheel(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);
    LRESULT OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, bool &bHandled);

  private:
    RootWindow *window_;
    std::unique_ptr<GdiRenderer> gdi_renderer_;
};

} // namespace xui
