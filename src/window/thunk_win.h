#include <cassert>
#include <Windows.h>

namespace xui
{

template <typename T>
class Thunk
{
  private:
#ifdef _WIN64

#pragma pack(push, 1)
    typedef struct _StdCallThunk
    {
        USHORT m_mov_rcx; // mov rcx, this
        ULONG64 m_this;
        USHORT m_mov_rax; // mov rax, target
        ULONG64 m_relproc;
        USHORT m_jmp; // jmp target

    } StdCallThunk;
#pragma pack(pop)

#else

#pragma pack(push, 1)
    typedef struct _StdCallThunk
    {
        DWORD m_mov; // mov dword ptr [esp+4], this
        DWORD m_this;
        BYTE m_jmp; // jmp target
        DWORD m_relproc;

    } StdCallThunk;
#pragma pack(pop)

#endif

  private:
    static HANDLE thunk_heap_;
    StdCallThunk *thunk_;

  public:
    Thunk() : thunk_(nullptr)
    {
        if (thunk_heap_ == nullptr)
        {
            thunk_heap_ = ::HeapCreate(HEAP_CREATE_ENABLE_EXECUTE, 0, 0);
            assert(thunk_heap_ != nullptr);
        }

        thunk_ = (StdCallThunk *)::HeapAlloc(thunk_heap_, 0, sizeof(StdCallThunk));

#ifdef _WIN64
        thunk_->m_mov_rcx = 0xb948; // mov rcx, this
        thunk_->m_this = 0;
        thunk_->m_mov_rax = 0xb848; // mov rax, target
        thunk_->m_relproc = 0;
        thunk_->m_jmp = 0xe0ff; // jmp rax
#else
        thunk_->m_mov = 0x042444c7; // mov dword ptr [esp+4], this
        thunk_->m_this = 0;
        thunk_->m_jmp = 0xe9; // jmp target
        thunk_->m_relproc = 0;
#endif
    }

    ~Thunk()
    {
        if (thunk_ != nullptr)
        {
            ::HeapFree(thunk_heap_, 0, thunk_);
            thunk_ = nullptr;
        }
    }

    template <typename U>
    void SetObject(const U *object)
    {
        thunk_->m_this = (ULONG_PTR)object;
    }

    void SetRealProc(T proc)
    {
#ifdef _WIN64
        thunk_->m_relproc = (ULONG_PTR)proc;
#else
        thunk_->m_relproc = (ULONG_PTR)proc - ((ULONG_PTR)thunk_ + sizeof(StdCallThunk));
#endif
    }

    T GetThunkProc()
    {
        return (T)thunk_;
    }
};

template <typename T>
__declspec(selectany) HANDLE Thunk<T>::thunk_heap_ = nullptr;

} // namespace xui