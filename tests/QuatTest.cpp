#include <gtest/gtest.h>
#include "otm/Quat.hpp"

using namespace otm;

TEST(QuatTest, Basic)
{
	constexpr Quat q1;
	EXPECT_TRUE(IsNearlyEqual(q1.v, Vec3{}));
	EXPECT_EQ(q1.s, 1);

	constexpr auto q2 = q1 * Quat{};
	EXPECT_TRUE(IsNearlyEqual(q1, q2));

	Quat q3{Vec3{0.369242f, -0.596525f, -0.712614f}.Unit(), 0.622533_rad};
	constexpr Quat q3e{0.1130857f, -0.1826944f, -0.2182483f, 0.9519464f};
	EXPECT_TRUE(IsNearlyEqual(q3, q3e));

	constexpr auto v1 = Vector<int, 3>::Forward();
	const auto v1r = v1.RotatedBy(Quat{UVec3::Right(), 90_deg});
	EXPECT_TRUE(IsNearlyEqual(v1r, Vec3::Down()));
}
