CPP = g++

CPPSRCS = FirstOperationOverloading.cpp AssignShallowCopyError.cpp InheritAssignOperation.cpp ImproveInit.cpp ArrayClass.cpp


CPP_INC = 

TARGET = 

BUILDDIR = build

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(CPPOBJS)

$(CPPOBJS):$(BUILDDIR)/%.o : %.cpp
	$(CPP) -o $@ $<

clean:
	rm -rf $(BUILDDIR)

.SUFFIXES:.cpp .o
