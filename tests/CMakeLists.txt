qt_add_executable(tests
    common/qamqptestcase.h
    main.cpp
    tst_qamqpchannel.cpp tst_qamqpchannel.h
    tst_qamqpclient.cpp tst_qamqpclient.h
    tst_qamqpexchange.cpp tst_qamqpexchange.h
    tst_qamqpqueue.cpp tst_qamqpqueue.h
)
target_include_directories(tests PRIVATE
    ../src
    common
)

target_link_libraries(tests PRIVATE
    qamqp
    Qt::Core
    Qt::Network
    Qt::Test
)


# Resources:
set_source_files_properties("files/certs/client/cert.pem"
    PROPERTIES QT_RESOURCE_ALIAS "client-cert.pem"
)
set_source_files_properties("files/certs/client/key.pem"
    PROPERTIES QT_RESOURCE_ALIAS "client-key.pem"
)
set_source_files_properties("files/certs/testca/cacert.pem"
    PROPERTIES QT_RESOURCE_ALIAS "ca-cert.pem"
)
set(certs_resource_files
    "files/certs/client/cert.pem"
    "files/certs/client/key.pem"
    "files/certs/testca/cacert.pem"
)

qt_add_resources(tests "certs"
    PREFIX
        "/certs"
    FILES
        ${certs_resource_files}
)

install(TARGETS tests
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

