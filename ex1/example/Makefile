CPP = g++

SRCS = example1.cpp example2.cpp example3.cpp example4.cpp

BUILDDIR = build

CPPOBJS = $(addprefix $(BUILDDIR)/,$(SRCS:.cpp=.o))

all: clean createdirs $(CPPOBJS)

createdirs:
	$(shell mkdir ${BUILDDIR})

$(CPPOBJS): $(BUILDDIR)/%.o : %.cpp
	$(CPP) $< -o $@

clean:
	rm -rf $(BUILDDIR)

