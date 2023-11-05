#include "tls_win.h"
#include <cassert>

namespace xui
{

Tls::Tls() : tls_index_(TLS_OUT_OF_INDEXES)
{
    tls_index_ = ::TlsAlloc();
    assert(tls_index_ != TLS_OUT_OF_INDEXES);
}

Tls::~Tls()
{
    assert(tls_index_ != TLS_OUT_OF_INDEXES);
    ::TlsFree(tls_index_);
    tls_index_ = TLS_OUT_OF_INDEXES;
}

bool Tls::Set(void *value)
{
    return ::TlsSetValue(tls_index_, value);
}

void *Tls::Get()
{
    return ::TlsGetValue(tls_index_);
}

} // namespace xui
