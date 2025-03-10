// Copyright 2021 Yashina Darya
#include <gtest/gtest.h>

#include <gtest-mpi-listener.hpp>

#include "./min_vector_element.h"

TEST(Parallel_Operations_MPI, Test_Max_20) {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  std::vector<int> global_vec;
  const int count_size_vector = 20;

  if (rank == 0) {
    global_vec = getRandomVector(count_size_vector);
  }

  int global_max;
  global_max = getParallelOperations(global_vec, count_size_vector);

  if (rank == 0) {
    int reference_max = getSequentialOperations(global_vec);
    ASSERT_EQ(reference_max, global_max);
  }
}

TEST(Parallel_Operations_MPI, Test_Max_40) {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  std::vector<int> global_vec;
  const int count_size_vector = 40;

  if (rank == 0) {
    global_vec = getRandomVector(count_size_vector);
  }

  int global_max;
  global_max = getParallelOperations(global_vec, count_size_vector);

  if (rank == 0) {
    int reference_max = getSequentialOperations(global_vec);
    ASSERT_EQ(reference_max, global_max);
  }
}

TEST(Parallel_Operations_MPI, Test_Max_60) {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  std::vector<int> global_vec;
  const int count_size_vector = 60;

  if (rank == 0) {
    global_vec = getRandomVector(count_size_vector);
  }

  int global_max;
  global_max = getParallelOperations(global_vec, count_size_vector);

  if (rank == 0) {
    int reference_max = getSequentialOperations(global_vec);
    ASSERT_EQ(reference_max, global_max);
  }
}

TEST(Parallel_Operations_MPI, Test_Max_80) {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  std::vector<int> global_vec;
  const int count_size_vector = 80;

  if (rank == 0) {
    global_vec = getRandomVector(count_size_vector);
  }

  int global_max;
  global_max = getParallelOperations(global_vec, count_size_vector);

  if (rank == 0) {
    int reference_max = getSequentialOperations(global_vec);
    ASSERT_EQ(reference_max, global_max);
  }
}

TEST(Parallel_Operations_MPI, Test_Max_100) {
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  std::vector<int> global_vec;
  const int count_size_vector = 100;

  if (rank == 0) {
    global_vec = getRandomVector(count_size_vector);
  }

  int global_max;
  global_max = getParallelOperations(global_vec, count_size_vector);

  if (rank == 0) {
    int reference_max = getSequentialOperations(global_vec);
    ASSERT_EQ(reference_max, global_max);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  MPI_Init(&argc, &argv);

  ::testing::AddGlobalTestEnvironment(new GTestMPIListener::MPIEnvironment);
  ::testing::TestEventListeners& listeners =
      ::testing::UnitTest::GetInstance()->listeners();

  listeners.Release(listeners.default_result_printer());
  listeners.Release(listeners.default_xml_generator());

  listeners.Append(new GTestMPIListener::MPIMinimalistPrinter);
  return RUN_ALL_TESTS();
}
