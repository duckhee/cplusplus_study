CPP = c++

CPPSRCS = ObjectPointer.cpp EmployeeManager2.cpp EmployeeManager3.cpp EmployeeManager4.cpp

BUILDDIR = build

TARGET = 

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))


all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build:$(CPPOBJS)

$(CPPOBJS):$(BUILDDIR)/%.o:%.cpp
	$(CPP) -o $@ $<

clean:
	rm -rf $(BUILDDIR)

.SUFFIXES: .cpp .o

