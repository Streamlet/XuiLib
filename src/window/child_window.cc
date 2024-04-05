#include <cassert>
#include <xui/window/child_window.h>

namespace xui
{

ChildWindow::ChildWindow()
{
}

ChildWindow ::~ChildWindow()
{
    assert(parent_ == nullptr);
}

bool ChildWindow::Create(Window *parent, const Rect &rect)
{
    assert(parent != nullptr && parent_ == nullptr);
    parent_ = parent;
    rect_ = rect;
    parent_->children_.push_back(this);

    bool bHandled = true;
    ProcessMessage(XUI_WM_CREATE, nullptr, bHandled);
    return true;
}

void ChildWindow::Destroy()
{
    bool bHandled = true;
    ProcessMessage(XUI_WM_DESTROY, nullptr, bHandled);

    assert(parent_ != nullptr);
    parent_->children_.erase(std::remove(parent_->children_.begin(), parent_->children_.end(), this),
                             parent_->children_.end());
    parent_ = nullptr;
}

} // namespace xui
