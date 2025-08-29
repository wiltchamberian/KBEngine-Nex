# ---------------- 源文件 ----------------
set(SRCS
	common.cpp
	db_exception.cpp
	db_transaction.cpp
	db_interface_mysql.cpp
	entity_table_mysql.cpp
	entity_sqlstatement_mapping.cpp
	kbe_table_mysql.cpp
)
# ---------------- 创建静态库 ----------------
add_library(db_mysql STATIC ${SRCS})


# ---------------- Python ----------------
include(${CMAKE_SOURCE_DIR}/cmakefile/Python.cmake)
target_link_libraries(db_mysql PRIVATE KBE::Python)


target_link_libraries(db_mysql PRIVATE fmt::fmt)



# 指定输出路径到 kbe/src/libs
set_target_properties(db_mysql PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    LIBRARY_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    RUNTIME_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
)
