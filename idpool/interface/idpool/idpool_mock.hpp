#pragma once

#include <idpool/idpool_base.hpp>
#include <gmock/gmock.h>

namespace idp {

struct idpool_mock : idpool_base
{
    MOCK_METHOD(id_t, next, (), (override));
    MOCK_METHOD(void, release, (id_t), (override));
    MOCK_METHOD(void, reset, (), (override));
};

} // namespace idp