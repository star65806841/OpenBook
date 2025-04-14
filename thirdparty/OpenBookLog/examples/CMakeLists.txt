project(PairIdeaLogExamples)

find_package(Qt6 REQUIRED COMPONENTS Core)

file(GLOB _src *.h *.cpp *.qrc)
add_executable(${PROJECT_NAME} ${_src})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt6::Core
    OpenBookLog)
target_include_directories(${PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:${TOOLUNIT_GENERATED_INCLUDE_DIR}>"
)

