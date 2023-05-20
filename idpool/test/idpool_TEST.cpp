#include <idpool/idpool_st.hpp>

#include <gtest/gtest.h>

namespace idp::test {

struct IdPoolTest : public ::testing::Test
{
    idpool_st_t m_pool;
};

TEST_F(IdPoolTest, single_fetch)
{
    EXPECT_EQ(0, m_pool.next());
}

TEST_F(IdPoolTest, id_monotone)
{
    const auto i = m_pool.next();
    EXPECT_EQ(1, (m_pool.next() - i));
}

TEST_F(IdPoolTest, release_on_empty_throws)
{
    EXPECT_THROW(m_pool.release(0), std::exception);
}

TEST_F(IdPoolTest, release_idempotent)
{
    const auto id = m_pool.next();
    EXPECT_NO_THROW(m_pool.release(id));
    EXPECT_NO_THROW(m_pool.release(id));
}

TEST_F(IdPoolTest, release_unknown)
{
    const auto id = m_pool.next();
    EXPECT_THROW(m_pool.release(id + 1), std::exception);
}

TEST_F(IdPoolTest, reassign_released)
{
    const auto id = m_pool.next();
    m_pool.release(id);

    EXPECT_EQ(id, m_pool.next());
}

TEST_F(IdPoolTest, average_case)
{
    m_pool.next();
    m_pool.release(m_pool.next());
    m_pool.release(m_pool.next());
    m_pool.next();

    EXPECT_EQ(2, m_pool.next());
}

TEST_F(IdPoolTest, reset)
{
    m_pool.next();
    m_pool.next();

    m_pool.reset();
    EXPECT_EQ(0, m_pool.next());
}

TEST_F(IdPoolTest, custom_init_value)
{
    idpool_st_t idp{17};
    EXPECT_EQ(17, idp.next());
}

} // namespace idp::test
