# qmake .pro file for qdirstat/src
#
# Go to the project toplevel dir and build all Makefiles:
#
#     qmake
#
# Then build with
#
#     make
#

TEMPLATE	     = app

QT		    += widgets
CONFIG		    += debug
DEPENDPATH	    += .
MOC_DIR		     = .moc
OBJECTS_DIR	     = .obj
LIBS		    += -lz

TARGET		     = qdirstat
TARGET.files	     = qdirstat
TARGET.path	     = /usr/bin
INSTALLS	    += TARGET

SOURCES	  = main.cpp			\
	    DebugHelpers.cpp		\
	    DataColumns.cpp		\
	    DirInfo.cpp			\
	    DirReadJob.cpp		\
	    DirSaver.cpp		\
	    DirTree.cpp			\
	    DirTreeCache.cpp		\
	    DirTreeModel.cpp		\
	    DirTreeView.cpp		\
	    Exception.cpp		\
	    ExcludeRules.cpp		\
	    FileInfo.cpp		\
	    FileInfoIterator.cpp	\
	    FileInfoSorter.cpp		\
	    Logger.cpp			\
	    MainWindow.cpp		\
	    PercentBar.cpp		\


HEADERS	  =				\
	    DebugHelpers.h		\
	    DataColumns.h		\
	    DirInfo.h			\
	    DirReadJob.h		\
	    DirSaver.h			\
	    DirTree.h			\
	    DirTreeCache.h		\
	    DirTreeModel.h		\
	    DirTreeView.h		\
	    Exception.h			\
	    ExcludeRules.h		\
	    FileInfo.h			\
	    FileInfoIterator.h		\
	    FileInfoSorter.h		\
	    Logger.h			\
	    MainWindow.h		\
	    PercentBar.h		\
	    SignalBlocker.h		\



FORMS	  = main-window.ui

RESOURCES = icons.qrc



