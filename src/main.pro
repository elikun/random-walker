TEMPLATE = app
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += object_parallel_to_source
HEADERS = Common/*.hpp \
          Common/MDL_CommandQueue/*.hpp \
          Common/MDL_CommandReceiver/*.hpp \
          Common/MDL_CommandSender/*.hpp
SOURCES = Common/MDL_CommandQueue/*.cpp \
          Common/MDL_CommandReceiver/*.cpp \
          Common/MDL_CommandSender/*.cpp

config_commander {
    TARGET = SS_Commander/commander
    HEADERS += SS_Commander/*.hpp \
               SS_Commander/MDL_CommandGenerator/*.hpp
    SOURCES += SS_Commander/*.cpp \
               SS_Commander/MDL_CommandGenerator/*.cpp
}

config_environment {
    TARGET = SS_Environment/environment
    HEADERS += SS_Environment/*.hpp \
               SS_Environment/MDL_Dot/*.hpp \
               SS_Environment/MDL_Edge/*.hpp \
               SS_Environment/MDL_Graph/*.hpp
    SOURCES += SS_Environment/*.cpp \
               SS_Environment/MDL_Dot/*.cpp \
               SS_Environment/MDL_Edge/*.cpp \
               SS_Environment/MDL_Graph/*.cpp
}
