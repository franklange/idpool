#pragma once

#include <idpool/idpool.hpp>
#include <set>

namespace idp {

class idpool_st_t : public idpool
{
public:
    idpool_st_t(id_t start = 0);

    auto next() -> id_t override;
    auto peek() -> id_t override;
    void release(id_t) override;
    void reset() override;

private:
    id_t m_new;
    std::set<id_t> m_released{};
};

} // namespace idp
