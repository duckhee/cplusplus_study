CC = g++

SRCS = UsingDcl2.cpp

BUILDDIR = buiild

TARGET = 

CPPOBJS = $(addprefix $(BUILDDIR)/,$(SRCS:.cpp=.o))

all: clean createdirs $(CPPOBJS)

createdirs:
	$(shell mkdir ${BUILDDIR})

$(CPPOBJS): $(BUILDDIR)/%.o : %.cpp
	$(CC) $< -o $@

clean:
	rm -rf $(BUILDDIR)