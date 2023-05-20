#include <idpool/idpool_mt.hpp>

#include <limits>
#include <stdexcept>

namespace idp {

idpool_mt_t::idpool_mt_t(const id_t s)
    : m_pool{s}
{}

auto idpool_mt_t::next() -> id_t
{
    const Lock l{m_mutex};
    return m_pool.next();
}

void idpool_mt_t::release(const id_t id)
{
    const Lock l{m_mutex};
    m_pool.release(id);
}

void idpool_mt_t::reset()
{
    const Lock l{m_mutex};
    m_pool.reset();
}

} // namespace idp
