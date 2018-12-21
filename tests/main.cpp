#include "gtest/gtest.h"
#include <iostream>


TEST(sample, check_env_vars) {
	ASSERT_STREQ(std::getenv("LD_LIBRARY_PATH"), "my-custom-library-path");
}


int  main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}