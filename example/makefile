CXX=g++
CFLAGS=-std=c++11 -g
CXXFLAGS=-std=c++11 -g

TARGET:=echo
OBJS = echo.cpp
$(TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS)  $(OBJS) -o $(TARGET) -lnetlib -lpthread