#pragma once

#include "../gragh/rect.h"
#include "message.h"
#include <functional>
#include <map>
#include <vector>

namespace xui
{

class NativeWindow;
class ChildWindow;

class Window
{
  public:
    Window();
    virtual ~Window();

  protected:
    typedef std::function<void *(WindowMessage msg, void *param, bool &handled)> MsgHandler;
    void RegisterMessaheHandler(WindowMessage msg, MsgHandler handler);

    Rect ClientRect() const;

  private:
    friend class NativeWindow;
    void *ProcessMessage(WindowMessage msg, void *param, bool &handled);

  private:
    std::multimap<WindowMessage, MsgHandler> msg_handlers_;

  protected:
    friend class RootWindow;
    friend class ChildWindow;
    Rect rect_;
    uint8_t alpha_ = 255;
    std::vector<ChildWindow *> children_;
};

} // namespace xui
