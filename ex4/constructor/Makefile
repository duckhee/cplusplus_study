CPP = g++

CPPSRCS = Constructor1.cpp Constructor2.cpp FruitSaleSim2.cpp FruitSaleSim3.cpp ReferenceMember.cpp privateConstructor.cpp Destructor.cpp \
		  objArr.cpp ObjPtrArr.cpp

BUILDDIR = build

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

TARGET = 

CPPFLAGS = 

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(CPPOBJS)

$(CPPOBJS):$(BUILDDIR)/%.o : %.cpp
	$(CPP) $< -o $@

clean:
	rm -rf $(BUILDDIR)