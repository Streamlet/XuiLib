#include <Windows.h>

namespace xui
{

class Tls
{
  public:
    Tls();
    ~Tls();

  public:
    bool Set(void *value);
    void *Get();

  private:
    DWORD tls_index_;
};

} // namespace xui
