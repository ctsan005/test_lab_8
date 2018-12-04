set (CMAKE_CXX_STANDARD 11)
ADD_SUBDIRECTORY(googletest)


ADD_EXECUTABLE(test
    test.cpp
    composite.cpp
    iterator.cpp
    visitor.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
