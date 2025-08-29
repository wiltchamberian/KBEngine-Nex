# 源文件列表
set(SRCS
	tinystr.cpp
	tinyxml.cpp
	tinyxmlerror.cpp
	tinyxmlparser.cpp
)

# 生成静态库
add_library(tinyxml STATIC ${SRCS})

# 如果没传入 KBE_ROOT，则默认取上级目录
if(NOT DEFINED KBE_ROOT)
    set(KBE_ROOT ${CMAKE_SOURCE_DIR}/../..) 
endif()


target_include_directories(tinyxml PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}   # tinyxml.h 的目录
)


# 指定输出路径到 kbe/src/libs
set_target_properties(tinyxml PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    LIBRARY_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    RUNTIME_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
)
