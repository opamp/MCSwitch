#FIND_PACKAGE(Qt4 4.8.1 REQUIRED) # For Qt4
#INCLUDE_DIRECTORIES(${QT_QTXML_INCLUDE_DIR}) # For Qt4
FIND_PACKAGE(Qt5Widgets REQUIRED)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(BINARY_NAME "MCSwitch")

ADD_LIBRARY(mcswitch_xml STATIC ${SRC_DIR}/xml.cpp)
QT5_USE_MODULES(mcswitch_xml Xml)
#TARGET_LINK_LIBRARIES(mcswitch_xml ${QT_QTXML_LIBRARY}) # For Qt4

SET(MSRC
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/MainWindow.cpp
	${SRC_DIR}/CentralWidget.cpp
	${SRC_DIR}/AddNewEnvDialog.cpp
	${SRC_DIR}/Environments.cpp
	${SRC_DIR}/MCEnv.cpp
	${SRC_DIR}/xml.cpp
	)

SET(MHED
    ${SRC_DIR}/MainWindow.hpp
	${SRC_DIR}/CentralWidget.hpp
	${SRC_DIR}/AddNewEnvDialog.hpp
	${SRC_DIR}/Environments.hpp
	${SRC_DIR}/MCEnv.hpp
	${SRC_DIR}/xml.cpp
    )

QT5_ADD_RESOURCES(QRC ${SRC_DIR}/main.qrc) # Add resources.

# This is for Qt4 -----------------------------------
#QT4_WRAP_CPP(HMOD ${MHED})
#QT4_ADD_RESOURCES(QRC ${SRC_DIR}/main.qrc)
#ADD_DEFINITIONS(${QT_DEFINITIONS})
#INCLUDE(${QT_USE_FILE})
#----------------------------------------------------
MESSAGE(STATUS "Qt5 --> ${Qt5Widgets_VERSION_STRING}") #Show Qt's version to user.

SET(SRCS ${MSRC} ${HMOD} ${QRC})
IF(APPLE) 

	SET(SRCS ${SRCS} ${PROJECT_SOURCE_DIR}/src/resources/icons/mac_icon.icns)
	SET(MACOSX_BUNDLE_ICON_FILE ${PROJECT_SOURCE_DIR}/src/resources/icons/mac_icon.icns)
	SET_SOURCE_FILES_PROPERTIES(mac_icon.icns PROPERTIES 
	    MACOSX_PACKAGE_LOCATION Resources)
	ADD_EXECUTABLE(${BINARY_NAME} MACOSX_BUNDLE ${SRCS})

ELSEIF(WIN32)


	#SET(SRCS ${SRCS} ${PROJECT_SOURCE_DIR}/src/resource/win/WinPICON.rc)
	ADD_EXECUTABLE(${BINARY_NAME} WIN32 ${SRCS})

ELSEIF(UNIX AND NOT APPLE)

	ADD_EXECUTABLE(${BINARY_NAME} ${SRCS})
ENDIF()

QT5_USE_MODULES(${BINARY_NAME} Widgets Xml)
TARGET_LINK_LIBRARIES(${BINARY_NAME} mcswitch_xml)
#TARGET_LINK_LIBRARIES(${BINARY_NAME} ${QT_LIBRARIES} mcswitch_xml)#${QT_QTXML_LIBRARY}) #Qt4
