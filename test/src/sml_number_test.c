// Copyright 2011 Juri Glass, Mathias Runge, Nadim El Sayed 
// DAI-Labor, TU-Berlin
// 
// This file is part of libSML.
// 
// libSML is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// libSML is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with libSML.  If not, see <http://www.gnu.org/licenses/>.

#include "../unity/unity_fixture.h"
#include "test_helper.h"
#include <sml/sml_number.h>

TEST_GROUP(sml_number);

sml_buffer *buf;

TEST_SETUP(sml_number) {
	buf = sml_buffer_init(512);
}

TEST_TEAR_DOWN(sml_number) {
	
}

TEST(sml_number, parse_unsigned8) {
	hex2binary("6201", sml_buf_get_current_buf(buf));
	u8 n = sml_u8_parse(buf);
	TEST_ASSERT_EQUAL(1, n);
}

TEST(sml_number, parse_unsigned16) {
	hex2binary("630101", sml_buf_get_current_buf(buf));
	u16 n = sml_u16_parse(buf);
	TEST_ASSERT_EQUAL(257, n);
}

TEST(sml_number, parse_unsigned32) {
	hex2binary("6500000001", sml_buf_get_current_buf(buf));
	u32 n = sml_u32_parse(buf);
	TEST_ASSERT_EQUAL(1, n);
}

TEST(sml_number, parse_unsigned32_fewer_bytes) {
	hex2binary("64010001", sml_buf_get_current_buf(buf));
	u32 n = sml_u32_parse(buf);
	TEST_ASSERT_EQUAL(65537, n);
}

TEST(sml_number, parse_unsigned64) {
	hex2binary("690000000000000001", sml_buf_get_current_buf(buf));
	u64 n = sml_u64_parse(buf);
	TEST_ASSERT_EQUAL(1, n);
}

TEST(sml_number, parse_unsigned64_fewer_bytes) {
	hex2binary("67000000000001", sml_buf_get_current_buf(buf));
	u64 n = sml_u64_parse(buf);
	TEST_ASSERT_EQUAL(1, n);
}


TEST(sml_number, parse_int8) {
	hex2binary("52FF", sml_buf_get_current_buf(buf));
	i8 n = sml_i8_parse(buf);
	TEST_ASSERT_EQUAL(-1, n);
}

TEST(sml_number, parse_int16) {
	hex2binary("53EC78", sml_buf_get_current_buf(buf));
	i16 n = sml_i16_parse(buf);
	TEST_ASSERT_EQUAL(-5000, n);
}

TEST(sml_number, parse_int32) {
	hex2binary("55FFFFFFFF", sml_buf_get_current_buf(buf));
	i32 n = sml_i32_parse(buf);
	TEST_ASSERT_EQUAL(-1, n);
}

TEST(sml_number, parse_int64) {
	hex2binary("59FFFFFFFFFFFFFFFF", sml_buf_get_current_buf(buf));
	i64 n = sml_i64_parse(buf);
	TEST_ASSERT_EQUAL(-1, n);
}

TEST(sml_number, parse_int64_fewer_bytes) {
	hex2binary("58FFFFFFFFFFEC78", sml_buf_get_current_buf(buf));
	i64 n = sml_i64_parse(buf);
	TEST_ASSERT_EQUAL(-5000, n);
}

TEST_GROUP_RUNNER(sml_number) {
	RUN_TEST_CASE(sml_number, parse_unsigned8);
	RUN_TEST_CASE(sml_number, parse_unsigned16);
	RUN_TEST_CASE(sml_number, parse_unsigned32);
	RUN_TEST_CASE(sml_number, parse_unsigned64);
	RUN_TEST_CASE(sml_number, parse_unsigned32_fewer_bytes);
	RUN_TEST_CASE(sml_number, parse_unsigned64_fewer_bytes);
	RUN_TEST_CASE(sml_number, parse_int8);
	RUN_TEST_CASE(sml_number, parse_int16);
	RUN_TEST_CASE(sml_number, parse_int32);
	RUN_TEST_CASE(sml_number, parse_int64);
	RUN_TEST_CASE(sml_number, parse_int64_fewer_bytes);
}



