# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/netlib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/netlib/build

# Include any dependencies generated for this target.
include src/CMakeFiles/netlib.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/netlib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/netlib.dir/flags.make

src/CMakeFiles/netlib.dir/acceptor.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/acceptor.cpp.o: ../src/acceptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/netlib.dir/acceptor.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/acceptor.cpp.o -c /root/netlib/src/acceptor.cpp

src/CMakeFiles/netlib.dir/acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/acceptor.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/acceptor.cpp > CMakeFiles/netlib.dir/acceptor.cpp.i

src/CMakeFiles/netlib.dir/acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/acceptor.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/acceptor.cpp -o CMakeFiles/netlib.dir/acceptor.cpp.s

src/CMakeFiles/netlib.dir/buffer.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/buffer.cpp.o: ../src/buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/netlib.dir/buffer.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/buffer.cpp.o -c /root/netlib/src/buffer.cpp

src/CMakeFiles/netlib.dir/buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/buffer.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/buffer.cpp > CMakeFiles/netlib.dir/buffer.cpp.i

src/CMakeFiles/netlib.dir/buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/buffer.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/buffer.cpp -o CMakeFiles/netlib.dir/buffer.cpp.s

src/CMakeFiles/netlib.dir/channel.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/channel.cpp.o: ../src/channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/netlib.dir/channel.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/channel.cpp.o -c /root/netlib/src/channel.cpp

src/CMakeFiles/netlib.dir/channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/channel.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/channel.cpp > CMakeFiles/netlib.dir/channel.cpp.i

src/CMakeFiles/netlib.dir/channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/channel.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/channel.cpp -o CMakeFiles/netlib.dir/channel.cpp.s

src/CMakeFiles/netlib.dir/currentthread.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/currentthread.cpp.o: ../src/currentthread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/netlib.dir/currentthread.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/currentthread.cpp.o -c /root/netlib/src/currentthread.cpp

src/CMakeFiles/netlib.dir/currentthread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/currentthread.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/currentthread.cpp > CMakeFiles/netlib.dir/currentthread.cpp.i

src/CMakeFiles/netlib.dir/currentthread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/currentthread.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/currentthread.cpp -o CMakeFiles/netlib.dir/currentthread.cpp.s

src/CMakeFiles/netlib.dir/defaultpoller.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/defaultpoller.cpp.o: ../src/defaultpoller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/netlib.dir/defaultpoller.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/defaultpoller.cpp.o -c /root/netlib/src/defaultpoller.cpp

src/CMakeFiles/netlib.dir/defaultpoller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/defaultpoller.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/defaultpoller.cpp > CMakeFiles/netlib.dir/defaultpoller.cpp.i

src/CMakeFiles/netlib.dir/defaultpoller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/defaultpoller.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/defaultpoller.cpp -o CMakeFiles/netlib.dir/defaultpoller.cpp.s

src/CMakeFiles/netlib.dir/epollpoller.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/epollpoller.cpp.o: ../src/epollpoller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/netlib.dir/epollpoller.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/epollpoller.cpp.o -c /root/netlib/src/epollpoller.cpp

src/CMakeFiles/netlib.dir/epollpoller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/epollpoller.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/epollpoller.cpp > CMakeFiles/netlib.dir/epollpoller.cpp.i

src/CMakeFiles/netlib.dir/epollpoller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/epollpoller.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/epollpoller.cpp -o CMakeFiles/netlib.dir/epollpoller.cpp.s

src/CMakeFiles/netlib.dir/eventloop.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/eventloop.cpp.o: ../src/eventloop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/netlib.dir/eventloop.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/eventloop.cpp.o -c /root/netlib/src/eventloop.cpp

src/CMakeFiles/netlib.dir/eventloop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/eventloop.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/eventloop.cpp > CMakeFiles/netlib.dir/eventloop.cpp.i

src/CMakeFiles/netlib.dir/eventloop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/eventloop.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/eventloop.cpp -o CMakeFiles/netlib.dir/eventloop.cpp.s

src/CMakeFiles/netlib.dir/eventloopthread.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/eventloopthread.cpp.o: ../src/eventloopthread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/netlib.dir/eventloopthread.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/eventloopthread.cpp.o -c /root/netlib/src/eventloopthread.cpp

src/CMakeFiles/netlib.dir/eventloopthread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/eventloopthread.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/eventloopthread.cpp > CMakeFiles/netlib.dir/eventloopthread.cpp.i

src/CMakeFiles/netlib.dir/eventloopthread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/eventloopthread.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/eventloopthread.cpp -o CMakeFiles/netlib.dir/eventloopthread.cpp.s

src/CMakeFiles/netlib.dir/eventloopthreadpool.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/eventloopthreadpool.cpp.o: ../src/eventloopthreadpool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/netlib.dir/eventloopthreadpool.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/eventloopthreadpool.cpp.o -c /root/netlib/src/eventloopthreadpool.cpp

src/CMakeFiles/netlib.dir/eventloopthreadpool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/eventloopthreadpool.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/eventloopthreadpool.cpp > CMakeFiles/netlib.dir/eventloopthreadpool.cpp.i

src/CMakeFiles/netlib.dir/eventloopthreadpool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/eventloopthreadpool.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/eventloopthreadpool.cpp -o CMakeFiles/netlib.dir/eventloopthreadpool.cpp.s

src/CMakeFiles/netlib.dir/inetaddress.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/inetaddress.cpp.o: ../src/inetaddress.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/netlib.dir/inetaddress.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/inetaddress.cpp.o -c /root/netlib/src/inetaddress.cpp

src/CMakeFiles/netlib.dir/inetaddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/inetaddress.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/inetaddress.cpp > CMakeFiles/netlib.dir/inetaddress.cpp.i

src/CMakeFiles/netlib.dir/inetaddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/inetaddress.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/inetaddress.cpp -o CMakeFiles/netlib.dir/inetaddress.cpp.s

src/CMakeFiles/netlib.dir/logger.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/logger.cpp.o: ../src/logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/netlib.dir/logger.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/logger.cpp.o -c /root/netlib/src/logger.cpp

src/CMakeFiles/netlib.dir/logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/logger.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/logger.cpp > CMakeFiles/netlib.dir/logger.cpp.i

src/CMakeFiles/netlib.dir/logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/logger.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/logger.cpp -o CMakeFiles/netlib.dir/logger.cpp.s

src/CMakeFiles/netlib.dir/poller.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/poller.cpp.o: ../src/poller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/netlib.dir/poller.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/poller.cpp.o -c /root/netlib/src/poller.cpp

src/CMakeFiles/netlib.dir/poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/poller.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/poller.cpp > CMakeFiles/netlib.dir/poller.cpp.i

src/CMakeFiles/netlib.dir/poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/poller.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/poller.cpp -o CMakeFiles/netlib.dir/poller.cpp.s

src/CMakeFiles/netlib.dir/socket.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/socket.cpp.o: ../src/socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/CMakeFiles/netlib.dir/socket.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/socket.cpp.o -c /root/netlib/src/socket.cpp

src/CMakeFiles/netlib.dir/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/socket.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/socket.cpp > CMakeFiles/netlib.dir/socket.cpp.i

src/CMakeFiles/netlib.dir/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/socket.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/socket.cpp -o CMakeFiles/netlib.dir/socket.cpp.s

src/CMakeFiles/netlib.dir/tcpconnection.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/tcpconnection.cpp.o: ../src/tcpconnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/CMakeFiles/netlib.dir/tcpconnection.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/tcpconnection.cpp.o -c /root/netlib/src/tcpconnection.cpp

src/CMakeFiles/netlib.dir/tcpconnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/tcpconnection.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/tcpconnection.cpp > CMakeFiles/netlib.dir/tcpconnection.cpp.i

src/CMakeFiles/netlib.dir/tcpconnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/tcpconnection.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/tcpconnection.cpp -o CMakeFiles/netlib.dir/tcpconnection.cpp.s

src/CMakeFiles/netlib.dir/tcpserver.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/tcpserver.cpp.o: ../src/tcpserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object src/CMakeFiles/netlib.dir/tcpserver.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/tcpserver.cpp.o -c /root/netlib/src/tcpserver.cpp

src/CMakeFiles/netlib.dir/tcpserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/tcpserver.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/tcpserver.cpp > CMakeFiles/netlib.dir/tcpserver.cpp.i

src/CMakeFiles/netlib.dir/tcpserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/tcpserver.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/tcpserver.cpp -o CMakeFiles/netlib.dir/tcpserver.cpp.s

src/CMakeFiles/netlib.dir/thread.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/thread.cpp.o: ../src/thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object src/CMakeFiles/netlib.dir/thread.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/thread.cpp.o -c /root/netlib/src/thread.cpp

src/CMakeFiles/netlib.dir/thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/thread.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/thread.cpp > CMakeFiles/netlib.dir/thread.cpp.i

src/CMakeFiles/netlib.dir/thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/thread.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/thread.cpp -o CMakeFiles/netlib.dir/thread.cpp.s

src/CMakeFiles/netlib.dir/timestamp.cpp.o: src/CMakeFiles/netlib.dir/flags.make
src/CMakeFiles/netlib.dir/timestamp.cpp.o: ../src/timestamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object src/CMakeFiles/netlib.dir/timestamp.cpp.o"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netlib.dir/timestamp.cpp.o -c /root/netlib/src/timestamp.cpp

src/CMakeFiles/netlib.dir/timestamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netlib.dir/timestamp.cpp.i"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/netlib/src/timestamp.cpp > CMakeFiles/netlib.dir/timestamp.cpp.i

src/CMakeFiles/netlib.dir/timestamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netlib.dir/timestamp.cpp.s"
	cd /root/netlib/build/src && /opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/netlib/src/timestamp.cpp -o CMakeFiles/netlib.dir/timestamp.cpp.s

# Object files for target netlib
netlib_OBJECTS = \
"CMakeFiles/netlib.dir/acceptor.cpp.o" \
"CMakeFiles/netlib.dir/buffer.cpp.o" \
"CMakeFiles/netlib.dir/channel.cpp.o" \
"CMakeFiles/netlib.dir/currentthread.cpp.o" \
"CMakeFiles/netlib.dir/defaultpoller.cpp.o" \
"CMakeFiles/netlib.dir/epollpoller.cpp.o" \
"CMakeFiles/netlib.dir/eventloop.cpp.o" \
"CMakeFiles/netlib.dir/eventloopthread.cpp.o" \
"CMakeFiles/netlib.dir/eventloopthreadpool.cpp.o" \
"CMakeFiles/netlib.dir/inetaddress.cpp.o" \
"CMakeFiles/netlib.dir/logger.cpp.o" \
"CMakeFiles/netlib.dir/poller.cpp.o" \
"CMakeFiles/netlib.dir/socket.cpp.o" \
"CMakeFiles/netlib.dir/tcpconnection.cpp.o" \
"CMakeFiles/netlib.dir/tcpserver.cpp.o" \
"CMakeFiles/netlib.dir/thread.cpp.o" \
"CMakeFiles/netlib.dir/timestamp.cpp.o"

# External object files for target netlib
netlib_EXTERNAL_OBJECTS =

../lib/libnetlib.so: src/CMakeFiles/netlib.dir/acceptor.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/buffer.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/channel.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/currentthread.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/defaultpoller.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/epollpoller.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/eventloop.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/eventloopthread.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/eventloopthreadpool.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/inetaddress.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/logger.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/poller.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/socket.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/tcpconnection.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/tcpserver.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/thread.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/timestamp.cpp.o
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/build.make
../lib/libnetlib.so: src/CMakeFiles/netlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/netlib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX shared library ../../lib/libnetlib.so"
	cd /root/netlib/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/netlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/netlib.dir/build: ../lib/libnetlib.so

.PHONY : src/CMakeFiles/netlib.dir/build

src/CMakeFiles/netlib.dir/clean:
	cd /root/netlib/build/src && $(CMAKE_COMMAND) -P CMakeFiles/netlib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/netlib.dir/clean

src/CMakeFiles/netlib.dir/depend:
	cd /root/netlib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/netlib /root/netlib/src /root/netlib/build /root/netlib/build/src /root/netlib/build/src/CMakeFiles/netlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/netlib.dir/depend
