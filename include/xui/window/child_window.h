#include "../gragh/rect.h"
#include "../utility/string.h"
#include "window.h"
#include <memory>

namespace xui
{

class ChildWindow : public Window
{
  public:
    ChildWindow();
    ~ChildWindow();

    bool Create(Window *parent, const Rect &rect);
    void Destroy();

  private:
    Window *parent_ = nullptr;
};

} // namespace xui
