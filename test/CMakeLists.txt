include_directories ( ${MATH_LIB_SOURCE_DIR}/library )



find_package( GTest REQUIRED )


add_executable( TestMathLib main.cpp )

target_link_libraries(  TestMathLib  ${GTEST_BOTH_LIBRARIES} )


add_test(  TestMathLib   TestMathLib  )
