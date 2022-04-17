#include <winternl.h>
#include <windows.h> //Double include due to /FORCE:MULTIPLE
#include "lazyimporter.hpp"
namespace Mem {

    

    template <typename t> t Read(uintptr_t addr) {
        if (addr < 0xffffff)
            return t();
        if (addr > 0x7fffffff0000)
            return t();

        return *reinterpret_cast<t*>(addr);
    }


	
}