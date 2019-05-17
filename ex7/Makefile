CPP = c++

CPPSRCS = EmployeeManager1.cpp UnivStudentInheri.cpp DerivCreOrderp.cpp DerivDestOrder.cpp \
		  ProtectedHeri.cpp ISAinheritance.cpp HASInheritance.cpp

BUILDDIR = build

TARGET = 

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(CPPOBJS)

$(CPPOBJS):$(BUILDDIR)/%.o:%.cpp
	$(CPP) -o $@ $<

clean:
	rm -rf ${BUILDDIR}

.SUFFIXES: .cpp .o