if(BUILD_TESTING)
  add_executable(tests test.cpp)
  target_link_libraries(tests PRIVATE GTest::gtest_main ${PROJECT_NAME})
  add_executable(${PROJECT_NAME}::tests ALIAS tests)

  include(GoogleTest)
  gtest_discover_tests(tests)
endif()

