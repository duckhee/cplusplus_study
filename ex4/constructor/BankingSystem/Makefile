CPP = g++

CPPSRCS = BankingSystemVer02.cpp

BUILDDIR = build

TARGET = 

CPPFLAGS = 

CPPEXTEND = 

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(CPPOBJS)

$(CPPOBJS):$(BUILDDIR)/%.o : %.cpp
	$(CPP) $< -o $@

clean:
	rm -rf $(BUILDDIR)
	