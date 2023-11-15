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

    bool Create(const Window *parent, const Rect &rect, const string &caption);
    bool Destroy();

  private:
    ChildWindow *parent_;
};

} // namespace xui
