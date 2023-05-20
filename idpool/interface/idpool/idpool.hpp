#pragma once

#include <cstdint>

namespace idp {

using id_t = std::uint32_t;

struct idpool
{
    virtual ~idpool() = default;

    virtual auto next() -> id_t = 0;
    virtual auto peek() -> id_t = 0;
    virtual void release(id_t) = 0;
    virtual void reset() = 0;
};

} // namespace idp