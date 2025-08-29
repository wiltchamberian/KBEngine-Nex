# ---------------- 源文件 ----------------
set(SRCS
	copy.cpp
	map.cpp
	math.cpp
	pickler.cpp
	py_compression.cpp
	py_gc.cpp
	pyurl.cpp
	py_platform.cpp
	pystruct.cpp
	pyprofile.cpp
	pyprofile_handler.cpp
	py_memorystream.cpp
	pywatcher.cpp
	script.cpp
	scriptobject.cpp
	scriptstdout.cpp
	scriptstderr.cpp
	scriptstdouterr.cpp
	scriptstdouterrhook.cpp
	sequence.cpp
	vector2.cpp
	vector3.cpp
	vector4.cpp
)
# ---------------- 创建静态库 ----------------
add_library(pyscript STATIC ${SRCS})

# ---------------- Python ----------------
include(${CMAKE_SOURCE_DIR}/cmakefile/Python.cmake)
target_link_libraries(pyscript PRIVATE KBE::Python)


target_link_libraries(pyscript PRIVATE fmt::fmt)


# 指定输出路径到 kbe/src/libs
set_target_properties(pyscript PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    LIBRARY_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
    RUNTIME_OUTPUT_DIRECTORY ${KBE_ROOT}/kbe/src/libs
)
