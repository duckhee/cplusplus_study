CPP = g++

CPPSRCS = RectangleFault.cpp

BUILDDIR = build

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

CPPFLAGS =

TARGET = 

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(CPPOBJS)

$(CPPOBJS):$(BUILDDIR)/%.o : %.cpp
	$(CPP) $< -o $@

clean:
	rm -rf $(BUILDDIR)



