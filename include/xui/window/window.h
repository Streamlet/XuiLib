#pragma once

#include "message.h"
#include <functional>
#include <map>

namespace xui
{

class NativeWindow;
class ChildWindow;

class Window
{
  public:
    Window();
    ~Window();

  protected:
    typedef std::function<void *(WindowMessage msg, void *param, bool &handled)> MsgHandler;
    void RegisterMessaheHandler(WindowMessage msg, MsgHandler handler);

  private:
    friend class NativeWindow;
    void *ProcessMessage(WindowMessage msg, void *param, bool &handled);

  private:
    std::multimap<WindowMessage, MsgHandler> msg_handlers_;

  protected:
    std::vector<ChildWindow *> children_;
};

} // namespace xui