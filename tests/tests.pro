TEMPLATE = app
QT += core
CONFIG += console c++17
CONFIG -= app_bundle

INCLUDEPATH += \
    ../code/ProjectTemplate \
    ../third_party/googletest/googletest/include \
    ../third_party/googletest/googlemock/include \
    ../third_party/googletest/googletest \
    ../third_party/googletest/googlemock

SOURCES += \
    ../code/ProjectTemplate/report.cpp \
    ../code/ProjectTemplate/category.cpp \
    ../code/ProjectTemplate/expense.cpp \
    ../code/ProjectTemplate/income.cpp \
    ../code/ProjectTemplate/monthlyincome.cpp \
    ../code/ProjectTemplate/irregularincome.cpp \
    ../code/ProjectTemplate/profile.cpp \
    ../third_party/googletest/googletest/src/gtest-all.cc \
    ../third_party/googletest/googlemock/src/gmock-all.cc \
    test_category.cpp \
    test_profile.cpp \
    test_report.cpp \
    test_storage_mock.cpp \
    tests_main.cpp

HEADERS += \
    ../code/ProjectTemplate/report.h \
    ../code/ProjectTemplate/category.h \
    ../code/ProjectTemplate/expense.h \
    ../code/ProjectTemplate/income.h \
    ../code/ProjectTemplate/monthlyincome.h \
    ../code/ProjectTemplate/irregularincome.h \
    ../code/ProjectTemplate/profile.h \
    appservice.h \
    istorage.h \
    mock_storage.h

LIBS += -pthread

