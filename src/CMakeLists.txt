qt_add_library(qamqp
    qamqpauthenticator.cpp qamqpauthenticator.h
    qamqpchannel.cpp qamqpchannel.h qamqpchannel_p.h
    qamqpchannelhash.cpp qamqpchannelhash_p.h
    qamqpclient.cpp qamqpclient.h qamqpclient_p.h
    qamqpexchange.cpp qamqpexchange.h qamqpexchange_p.h
    qamqpframe.cpp qamqpframe_p.h
    qamqpglobal.h
    qamqpmessage.cpp qamqpmessage.h qamqpmessage_p.h
    qamqpqueue.cpp qamqpqueue.h qamqpqueue_p.h
    qamqptable.cpp qamqptable.h
)

# Get the latest abbreviated commit hash of the working branch
execute_process(
    COMMAND git describe --long --dirty --tags
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

target_compile_definitions(qamqp PUBLIC
    GIT_VERSION=\"${GIT_HASH}\"
    QAMQP_BUILD
)

target_link_libraries(qamqp PUBLIC
    Qt::Core
    Qt::Network
)

if(((NEED_GCOV_SUPPORT GREATER 0)) AND (gcov))
    target_compile_options(qamqp
        -fprofile-arcs
        -ftest-coverage
    )
endif()

install(TARGETS qamqp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    FRAMEWORK DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
