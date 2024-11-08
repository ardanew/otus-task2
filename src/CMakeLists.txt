add_executable(ip_filter main.cpp ip.cpp filter.cpp ip.h filter.h)

include(GNUInstallDirs)
install(
    TARGETS ip_filter COMPONENT app
    PERMISSIONS OWNER_WRITE OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
