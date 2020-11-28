include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${PROJECT_SOURCE_DIR}/external)

ExternalProject_Add(googletest_ep
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG 78fdd6c00b8fa5dd67066fbb796affc87ba0e075
        GIT_PROGRESS true
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_INSTALL_LIBDIR=lib64 -DCMAKE_CXX_FLAGS="-w"
        )

link_directories(${EXTERNAL_INSTALL_LOCATION}/lib64)
