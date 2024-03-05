# CMake generated Testfile for 
# Source directory: /home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests
# Build directory: /home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AVLBST.ConstructionDestruction "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLBST.ConstructionDestruction")
set_tests_properties(AVLBST.ConstructionDestruction PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLInsert.OneNode "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.OneNode")
set_tests_properties(AVLInsert.OneNode PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLInsert.DoubleInsertLeft "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.DoubleInsertLeft")
set_tests_properties(AVLInsert.DoubleInsertLeft PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLInsert.DoubleInsertRight "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.DoubleInsertRight")
set_tests_properties(AVLInsert.DoubleInsertRight PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLInsert.InsertZigZigLeft "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.InsertZigZigLeft")
set_tests_properties(AVLInsert.InsertZigZigLeft PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLInsert.InsertZigZigRight "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.InsertZigZigRight")
set_tests_properties(AVLInsert.InsertZigZigRight PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLInsert.InsertZigZagLeft "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.InsertZigZagLeft")
set_tests_properties(AVLInsert.InsertZigZagLeft PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLInsert.InsertZigZagRight "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.InsertZigZagRight")
set_tests_properties(AVLInsert.InsertZigZagRight PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLInsert.7Elements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.7Elements")
set_tests_properties(AVLInsert.7Elements PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLClear.Clear "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLClear.Clear")
set_tests_properties(AVLClear.Clear PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLInsert.Duplicates "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.Duplicates")
set_tests_properties(AVLInsert.Duplicates PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLInsert.Random50x30ele "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.Random50x30ele")
set_tests_properties(AVLInsert.Random50x30ele PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLInsert.Random3x5000ele "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLInsert.Random3x5000ele")
set_tests_properties(AVLInsert.Random3x5000ele PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLRemove.EmptyTree "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.EmptyTree")
set_tests_properties(AVLRemove.EmptyTree PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLRemove.NodeMismatch "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.NodeMismatch")
set_tests_properties(AVLRemove.NodeMismatch PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLRemove.SingleRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.SingleRemove")
set_tests_properties(AVLRemove.SingleRemove PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLRemove.RightChildRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.RightChildRemove")
set_tests_properties(AVLRemove.RightChildRemove PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLRemove.LeftChildRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.LeftChildRemove")
set_tests_properties(AVLRemove.LeftChildRemove PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLRemove.TwoChildrenRemove_3Node "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.TwoChildrenRemove_3Node")
set_tests_properties(AVLRemove.TwoChildrenRemove_3Node PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLRemove.TwoChildrenRemove_4Node "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.TwoChildrenRemove_4Node")
set_tests_properties(AVLRemove.TwoChildrenRemove_4Node PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLRemove.Random50x30ele "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLRemove.Random50x30ele")
set_tests_properties(AVLRemove.Random50x30ele PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLStress.InsertRemove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLStress.InsertRemove")
set_tests_properties(AVLStress.InsertRemove PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
add_test(AVLStress.Remove "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "--error-exitcode=113" "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/avl_tests" "--gtest_filter=AVLStress.Remove")
set_tests_properties(AVLStress.Remove PROPERTIES  _BACKTRACE_TRIPLES "/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/CustomTests.cmake;43;add_test;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/test_cmake_lib/TestTargets.cmake;233;add_executable_gtests;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;3;add_header_problem;/home/vayunmathur/Documents/code/c++/class/hw4/hw4_tests/avl_tests/CMakeLists.txt;0;")
