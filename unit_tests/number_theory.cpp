/*
 * Quantum++
 *
 * Copyright (c) 2013 - 2016 Vlad Gheorghiu (vgheorgh@gmail.com)
 *
 * This file is part of Quantum++.
 *
 * Quantum++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Quantum++ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Quantum++.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>
#include <qpp.h>
using namespace qpp;

// Write your unit tests here. Some examples are provided below.

///// BEGIN bigint qpp::modpow(bigint a, bigint n, bigint p)
TEST(qpp_modpow_test, PositiveNumbers)
{
    EXPECT_EQ (0, qpp::modpow(2, 3, 4));
    EXPECT_EQ (34, qpp::modpow(17, 176, 37));
    EXPECT_EQ (4042, qpp::modpow(178373, 9281623, 6217));
}
///// END bigint qpp::modpow(bigint a, bigint n, bigint p)

///// BEGIN bigint qpp::modinv(bigint a, bigint p)
TEST(qpp_modinv_test, NonNegativeNumbers)
{
    EXPECT_EQ (1, qpp::modinv(1, 1));
    EXPECT_EQ (62, qpp::modinv(2, 123));
    EXPECT_EQ (21, qpp::modinv(1231, 22));
}
///// END bigint qpp::modinv(bigint a, bigint p)

///// BEGIN bigint qpp::gcd(bigint m, bigint n)
TEST(qpp_gcd_test, NonNegativeNumbers)
{
    EXPECT_EQ (10, qpp::gcd(10, 0));
    EXPECT_EQ (10, qpp::gcd(0, 10));
    EXPECT_EQ (1, qpp::gcd(1, 1));
    EXPECT_EQ (4, qpp::gcd(120, 1124));
    EXPECT_EQ (1, qpp::gcd(17, 131));
}

TEST(qpp_gcd_test, MixedNumbers)
{
    EXPECT_EQ (10, qpp::gcd(-10, 0));
    EXPECT_EQ (10, qpp::gcd(0, -10));
    EXPECT_EQ (1, qpp::gcd(1, -1));
    EXPECT_EQ (1, qpp::gcd(-1, 1));
    EXPECT_EQ (4, qpp::gcd(120, -1124));
    EXPECT_EQ (1, qpp::gcd(-17, 131));
}

TEST(qpp_gcd_test, NegativeNumbers)
{
    EXPECT_EQ (1, qpp::gcd(-1, -1));
    EXPECT_EQ (4, qpp::gcd(-120, -1124));
    EXPECT_EQ (1, qpp::gcd(-17, -131));
    EXPECT_EQ (20, qpp::gcd(-170180, -13100));
}
///// END bigint qpp::gcd(bigint m, bigint n)

///// BEGIN bigint qpp::gcd(const std::vector<bigint>& ns)
TEST(qpp_gcd_list_test, MixedNumbers)
{
    std::vector<bigint> v1{1, 0, -1, 0, 1};
    EXPECT_EQ(1, qpp::gcd(v1));

    std::vector<bigint> v2{1, 2, 3, 4, 5};
    EXPECT_EQ(1, qpp::gcd(v2));

    std::vector<bigint> v3{125000, -12680, 25040, -4};
    EXPECT_EQ(4, qpp::gcd(v3));
}
///// END bigint qpp::gcd(const std::vector<bigint>& ns)

///// BEGIN bigint qpp::lcm(bigint m, bigint n)
TEST(qpp_lcm_test, NonNegativeNumbers)
{
    EXPECT_EQ (0, qpp::lcm(10, 0));
    EXPECT_EQ (0, qpp::lcm(0, 10));
    EXPECT_EQ (1, qpp::lcm(1, 1));
    EXPECT_EQ (33720, qpp::lcm(120, 1124));
    EXPECT_EQ (2227, qpp::lcm(17, 131));
}

TEST(qpp_lcm_test, MixedNumbers)
{
    EXPECT_EQ (0, qpp::lcm(-10, 0));
    EXPECT_EQ (0, qpp::lcm(0, -10));
    EXPECT_EQ (1, qpp::lcm(1, -1));
    EXPECT_EQ (1, qpp::lcm(-1, 1));
    EXPECT_EQ (33720, qpp::lcm(120, -1124));
    EXPECT_EQ (2227, qpp::lcm(-17, 131));
}

TEST(qpp_lcm_test, NegativeNumbers)
{
    EXPECT_EQ (1, qpp::lcm(-1, -1));
    EXPECT_EQ (33720, qpp::lcm(-120, -1124));
    EXPECT_EQ (2227, qpp::lcm(-17, -131));
    EXPECT_EQ (111467900, qpp::lcm(-170180, -13100));
}
///// END bigint qpp::lcm(bigint m, bigint n)

///// BEGIN bigint qpp::lcm(const std::vector<bigint>& ns)
TEST(qpp_lcm_list_test, MixedNumbers)
{
    std::vector<bigint> v1{10, -10, 10, -10};
    EXPECT_EQ(10, qpp::lcm(v1));

    std::vector<bigint> v2{1, 2, 3, 4, 5};
    EXPECT_EQ(60, qpp::lcm(v2));

    std::vector<bigint> v3{12500, -1268, 2504, -4};
    EXPECT_EQ(2480525000, qpp::lcm(v3));
}
///// END bigint qpp::lcm(const std::vector<bigint>& ns)

///// BEGIN std::tuple<bigint, bigint, bigint> qpp::egcd(bigint m, bigint n)
TEST(qpp_egcd_test, NonNegativeNumbers)
{
    EXPECT_EQ (std::make_tuple(1, 0, 10), qpp::egcd(10, 0));
    EXPECT_EQ (std::make_tuple(0, 1, 10), qpp::egcd(0, 10));
    EXPECT_EQ (std::make_tuple(0, 1, 1), qpp::egcd(1, 1));
    EXPECT_EQ (std::make_tuple(-103, 11, 4), qpp::egcd(120, 1124));
    EXPECT_EQ (std::make_tuple(54, -7, 1), qpp::egcd(17, 131));
}

TEST(qpp_egcd_test, MixedNumbers)
{
    EXPECT_EQ (std::make_tuple(-1, 0, 10), qpp::egcd(-10, 0));
    EXPECT_EQ (std::make_tuple(0, -1, 10), qpp::egcd(0, -10));
    EXPECT_EQ (std::make_tuple(0, -1, 1), qpp::egcd(1, -1));
    EXPECT_EQ (std::make_tuple(0, 1, 1), qpp::egcd(-1, 1));
    EXPECT_EQ (std::make_tuple(-103, -11, 4), qpp::egcd(120, -1124));
    EXPECT_EQ (std::make_tuple(-54, -7, 1), qpp::egcd(-17, 131));
}

TEST(qpp_egcd_test, NegativeNumbers)
{
    EXPECT_EQ (std::make_tuple(0, -1, 1), qpp::egcd(-1, -1));
    EXPECT_EQ (std::make_tuple(103, -11, 4), qpp::egcd(-120, -1124));
    EXPECT_EQ (std::make_tuple(-54, 7, 1), qpp::egcd(-17, -131));
}
///// END std::tuple<bigint, bigint, bigint> qpp::egcd(bigint m, bigint n)
