#include "gtest/gtest.h"
#include "lib.h"

TEST(operatorSum, expectedSum) {
	Complex a, b, sum;
	
	a.real = 6.9;
	a.imaginary = 0;
	
	b.real = 0;
	b.imaginary = 9.6;
	sum = a + b;
	EXPECT_DOUBLE_EQ(sum.real, 6.9);
	EXPECT_DOUBLE_EQ(sum.imaginary, 9.6);
	
	a.real = -25.52;
	a.imaginary = -14.88;
	sum += a;
	EXPECT_DOUBLE_EQ(sum.real, -18.62);
	EXPECT_DOUBLE_EQ(sum.imaginary, -5.28);
}

TEST(operatorSub, expectedSub) {
	Complex a, b, sub;
	a.real = 13.87;
	a.imaginary = 7;
	
	b.real = -0.31;
	b.imaginary = 4.01;
	sub = a - b;
	EXPECT_DOUBLE_EQ(sub.real, 14.18);
	EXPECT_DOUBLE_EQ(sub.imaginary, 2.99);
	
	a.real = 228;
	a.imaginary = -0.337;
	sub -= a;
	EXPECT_DOUBLE_EQ(sub.real, -213.82);
	EXPECT_DOUBLE_EQ(sub.imaginary, 3.327);
	
	a.real = -213.82;
	a.imaginary = 0.327;
	sub -= a;
	EXPECT_DOUBLE_EQ(sub.real, 0);
	EXPECT_DOUBLE_EQ(sub.imaginary, 3);
}

TEST(operatorMul, expectedMul) {
	Complex a, b, Mul;
	a.real = 2;
	a.imaginary = 3;
	b.real = 5;
	b.imaginary = -7;
	Mul = a * b;
	EXPECT_DOUBLE_EQ(Mul.real, 31);
	EXPECT_DOUBLE_EQ(Mul.imaginary, 1);
	
	a.real = 0;
	a.imaginary = -2;
	Mul *= a;
	EXPECT_DOUBLE_EQ(Mul.real, 2);
	EXPECT_DOUBLE_EQ(Mul.imaginary, -62);
}

TEST(operatorDivision, expectedDivision) {
	Complex a, b, result;
	a.real = 1;
	a.imaginary = 3;
	
	b.real = 1;
	b.imaginary = 1;
	result = a / b;
	EXPECT_DOUBLE_EQ(result.real, 2);
	EXPECT_DOUBLE_EQ(result.imaginary, 1);
	
	a.real = 1;
	a.imaginary = 3;
	result /= a;
	EXPECT_DOUBLE_EQ(result.real, 0.5);
	EXPECT_DOUBLE_EQ(result.imaginary, -0.5);
}

TEST(operatorDivision, expectedDivisionByZeroException) {
	Complex a, b, c;
	
	a.real = -10;
	a.imaginary = 20;
	
	b.real = 0;
	b.imaginary = 0;
	
	std::string err;
	try {
		c = a / b;
	}     catch (std::logic_error& exception) {
		err = exception.what();
	}
	
	EXPECT_EQ(err, "ERROR: zero division");
	
}

TEST(operatorOut, expectedOutput) {
	Complex a;
	
	a.real = 0;
	a.imaginary = 0;
	testing::internal::CaptureStdout();
	std::cout << a;
	EXPECT_EQ(testing::internal::GetCapturedStdout(), "0");
	
	a.real = 121212;
	a.imaginary = 69;
	testing::internal::CaptureStdout();
	std::cout << a;
	EXPECT_EQ(testing::internal::GetCapturedStdout(), "121212+69i");
	
	a.real = -121212;
	a.imaginary = -69;
	testing::internal::CaptureStdout();
	std::cout << a;
	EXPECT_EQ(testing::internal::GetCapturedStdout(), "-121212-69i");
	
	a.real = 525.9;
	a.imaginary = 0;
	testing::internal::CaptureStdout();
	std::cout << a;
	EXPECT_EQ(testing::internal::GetCapturedStdout(), "525.9");
	
	a.real = -525.9;
	a.imaginary = 0;
	testing::internal::CaptureStdout();
	std::cout << a;
	EXPECT_EQ(testing::internal::GetCapturedStdout(), "-525.9");
	
	a.real = 0;
	a.imaginary = 1137.4;
	testing::internal::CaptureStdout();
	std::cout << a;
	EXPECT_EQ(testing::internal::GetCapturedStdout(), "1137.4i");
	
	a.real = 0;
	a.imaginary = -1137.4;
	testing::internal::CaptureStdout();
	std::cout << a;
	EXPECT_EQ(testing::internal::GetCapturedStdout(), "-1137.4i");
	
	a.real = 1;
	a.imaginary = 1;
	testing::internal::CaptureStdout();
	std::cout << a;
	EXPECT_EQ(testing::internal::GetCapturedStdout(), "1+i");
	
	a.real = -1;
	a.imaginary = -1;
	testing::internal::CaptureStdout();
	std::cout << a;
	EXPECT_EQ(testing::internal::GetCapturedStdout(), "-1-i");
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
