#include "../gragh/rect.h"
#include "../utility/string.h"
#include "window.h"
#include <memory>

namespace xui
{

class NativeWindow;

class RootWindow : public Window
{
  public:
    RootWindow();
    ~RootWindow();

    bool Create(const RootWindow *owner, const Rect &rect, const string &caption);
    bool Destroy();

  private:
    std::unique_ptr<NativeWindow> native_window_;
};

} // namespace xui
