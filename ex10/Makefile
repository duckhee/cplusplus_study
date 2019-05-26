CPP = g++

CPPSRCS = FirstOperationOverloading.cpp OverloadingOperation.cpp GFunctionOverloading.cpp OneOpndOverloading.cpp \
          PostOpndOverloading.cpp PointMultipleOperation.cpp CommuMultipleOperation.cpp ConsoleOutput.cpp IterateConsoleOutput.cpp \
		  PointConsoleOutput.cpp 

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

.SUFFIXES: .cpp .o