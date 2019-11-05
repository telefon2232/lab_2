#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);
	m[0][3] = 5;
	TMatrix<int> mp(m);

	EXPECT_EQ(m, mp);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> matrix_1(5);
	matrix_1[0][3] = 5;
	TMatrix<int> matrix_2(matrix_1);
	matrix_2[0][3] = 2;
	EXPECT_NE(matrix_1, matrix_2);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> matrix_1(5);
	EXPECT_EQ(matrix_1.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> matrix_1(6);
	matrix_1[0][3] = 5;
	EXPECT_EQ(matrix_1[0][3], 5);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> matrix_1(6);
	ASSERT_ANY_THROW(matrix_1[-1][2]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> matrix_1(6);
	ASSERT_ANY_THROW(matrix_1[MAX_MATRIX_SIZE][2]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> matrix_1(2);
	matrix_1[0][0] = 1;
	matrix_1[0][1] = 1;
	matrix_1[1][1] = 3;
	EXPECT_EQ(matrix_1, matrix_1 = matrix_1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> matrix_1(2), matrix_2(2);
	matrix_1[0][0] = 1;
	matrix_1[0][1] = 1;
	matrix_1[1][1] = 3;
	matrix_2 = matrix_1;
	EXPECT_EQ(matrix_1, matrix_2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> matrix_1(2), matrix_2(7);
	matrix_1 = matrix_2;
	EXPECT_EQ(matrix_1.GetSize(), 7);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> matrix_1(2), matrix_2(7);
	matrix_1 = matrix_2;
	EXPECT_EQ(matrix_1, matrix_2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> matrix_1(2), matrix_2(2);
	matrix_1[0][0] = 1;
	matrix_1[0][1] = 1;
	matrix_1[1][1] = 3;
	matrix_2[0][0] = 1;
	matrix_2[0][1] = 1;
	matrix_2[1][1] = 3;
	EXPECT_EQ(matrix_1, matrix_2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> matrix_1(2);
	EXPECT_EQ(matrix_1, matrix_1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> matrix_1(2), matrix_2(4);
	EXPECT_NE(matrix_1, matrix_2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> matrix_1(6), matrix_2(6), sum(6);
	for (int i = 0; i < 6; i++)
		for (int j = i; j < 6; j++)
		{
			matrix_1[i][j] = i + j;
			matrix_2[i][j] = -j;
			sum[i][j] = i;
		}
	EXPECT_EQ(matrix_1 + matrix_2, sum);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> matrix_1(7), matrix_2(12);
	ASSERT_ANY_THROW(matrix_1 + matrix_2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> matrix_1(6), matrix_2(6), sub(6);
	for (int i = 0; i < 6; i++)
		for (int j = i; j < 6; j++)
		{
			matrix_1[i][j] = i + j;
			matrix_2[i][j] = -j;
			sub[i][j] = i + 2 * j;
		}
	EXPECT_EQ(matrix_1 - matrix_2, sub);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> matrix_1(6), matrix_2(7);
	ASSERT_ANY_THROW(matrix_1 - matrix_2);
}