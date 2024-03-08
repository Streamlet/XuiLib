#include <cassert>
#include <xui/window/child_window.h>

namespace xui
{

ChildWindow::ChildWindow()
{
}

ChildWindow ::~ChildWindow()
{
}

bool ChildWindow::Create(Window *parent, const Rect &rect)
{
    assert(parent != nullptr && parent_ == nullptr);
    parent_ = parent;
    rect_ = rect;
    parent_->children_.push_back(this);
    return true;
}

void ChildWindow::Destroy()
{
    assert(parent_ != nullptr);
    parent_->children_.erase(std::remove(parent_->children_.begin(), parent_->children_.end(), this),
                             parent_->children_.end());
}

} // namespace xui
