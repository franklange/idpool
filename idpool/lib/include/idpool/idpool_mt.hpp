#pragma once

#include <idpool/idpool.hpp>
#include <idpool/idpool_st.hpp>

#include <mutex>
#include <set>

namespace idp {

class idpool_mt_t : public idpool
{
public:
    idpool_mt_t(id_t start = 0);

    auto next() -> id_t override;
    auto peek() -> id_t override;
    void release(id_t) override;
    void reset() override;

private:
    idpool_st_t m_pool;

    using Lock = std::lock_guard<std::mutex>;
    std::mutex m_mutex;
};

} // namespace idp
