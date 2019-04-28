CC = g++

SRCS = FunctionOverloading.cpp

TARGET = 

BUILDDIR = build

CPPOBJS = $(addprefix $(BUILDDIR)/,$(SRCS:.cpp=.o))

all: clean createdirs $(CPPOBJS)

clean:
	rm -rf $(BUILDDIR)

createdirs: 
	$(shell mkdir ${BUILDDIR})

$(CPPOBJS): $(BUILDDIR)/%.o : %.cpp
	$(CC) $< -o $@




