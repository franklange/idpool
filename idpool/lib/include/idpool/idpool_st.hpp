#pragma once

#include <idpool/idpool.hpp>
#include <set>

namespace idp {

class idpool_st_t : public idpool
{
public:
    auto next() -> id_t override;
    void release(id_t) override;

    void reset() override;

private:
    id_t m_new{0};
    std::set<id_t> m_released{};
};

} // namespace idp
