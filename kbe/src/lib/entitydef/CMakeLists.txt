# ---------------- 源文件 ----------------
set(SRCS
	fixedarray.cpp
	common.cpp
	datatype.cpp
	datatypes.cpp
	detaillevel.cpp
	entity_component.cpp
	entity_component_call.cpp
	entity_call.cpp
	entitydef.cpp
	py_entitydef.cpp
	entitycallabstract.cpp
	fixeddict.cpp
	method.cpp
	property.cpp
	remote_entity_method.cpp
	scriptdef_module.cpp
	volatileinfo.cpp
)
# ---------------- 创建静态库 ----------------
add_library(entitydef STATIC ${SRCS})


# ---------------- Python ----------------
include(${CMAKE_SOURCE_DIR}/cmakefile/Python.cmake)
target_link_libraries(entitydef PRIVATE KBE::Python)


target_link_libraries(entitydef PRIVATE fmt::fmt)



# 指定输出路径到 kbe/src/libs
set_target_properties(entitydef PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    LIBRARY_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    RUNTIME_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
)
