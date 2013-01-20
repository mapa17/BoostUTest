#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 2.6)
#Name your project here
project(boostUnitTest)

enable_testing()
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
link_directories ( ${Boost_LIBRARY_DIRS} )


if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++0x")        ## Optimize
    #set(CMAKE_EXE_LINKER_FLAGS "-s")  ## Strip binary
endif()



set( SRC_FILES 
	Armageddon.cpp
 )

add_executable(Armageddon_Test Armageddon_test.cpp ${SRC_FILES} )                      
target_link_libraries(Armageddon_Test
					  ${Boost_LIBRARIES}
                      ${Boost_FILESYSTEM_LIBRARY}
                      ${Boost_SYSTEM_LIBRARY}
                      ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
                      )
                      

#This tells CMake to fib.c and name it fibonacci
add_executable(Armageddon main.cpp ${SRC_FILES} )

add_test(OkDoit Armageddon_Test)