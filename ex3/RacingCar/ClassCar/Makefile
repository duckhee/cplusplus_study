CPP = g++

CPPSRCS = Car.cpp RacingMain.cpp

CPPINC = -I.Car.h

BUILDDIR = build

CPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

TARGET = testcar

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(CPOBJS)
	$(CPP) -o $(TARGET) $^


$(CPOBJS): $(BUILDDIR)/%.o : %.cpp
	$(CPP) $(CPPINC) -o $@ -c $<

clean:
	rm -rf $(TARGET)
	rm -rf $(BUILDDIR)
