CC = g++

TARGET = 

SRCS = StringIO.cpp

BUILDDIR = build

CPPOBJS = $(addprefix $(BUILDDIR)/,$(SRCS:.cpp=.o))


all: clean createdirs $(CPPOBJS)

createdirs:
	$(shell mkdir ${BUILDDIR})


clean:
	rm -rf $(BUILDDIR)

$(CPPOBJS): $(BUILDDIR)/%.o : %.cpp
	$(CC) $< -o $@

	
