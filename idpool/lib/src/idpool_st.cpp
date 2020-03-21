#include <idpool/idpool_st.hpp>

#include <limits>
#include <stdexcept>

namespace idp {

auto idpool_st_t::next() -> id_t
{
    if (!m_released.empty())
    {
        const auto n = *(m_released.begin());
        m_released.erase(m_released.begin());
        return n;
    }

    if (m_new == std::numeric_limits<id_t>::max())
        throw std::runtime_error{"[idpool] maximum number of objects reached"};

    return m_new++;
}

void idpool_st_t::release(const id_t id)
{
    if (id >= m_new)
        throw std::logic_error{"[idpool] id never issued"};

    m_released.insert(id);
}

void idpool_st_t::reset()
{
    m_new = 0;
    m_released.clear();
}

} // namespace idp