CPP = g++

CPPSRCS = RealObjUnder1.cpp RealObjUnder2.cpp VirtualInternal.cpp MutiInheri1.cpp MultiInheri2.cpp \

BUILDDIR = build

TARGET = 

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