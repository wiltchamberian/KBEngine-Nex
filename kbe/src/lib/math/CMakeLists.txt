# ---------------- 源文件 ----------------
set(SRCS
	math.cpp
)
# ---------------- 创建静态库 ----------------
add_library(math STATIC ${SRCS})

target_link_libraries(math PRIVATE fmt::fmt)

# 指定输出路径到 kbe/src/libs
set_target_properties(math PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    LIBRARY_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    RUNTIME_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
)
