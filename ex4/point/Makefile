CPP = g++

CPPSRCS = Point.cpp Rectangle.cpp RectangleFaultFind.cpp

BUILDDIR = build

CPPEXTEND = -IPoint.h -IRectangle.h

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

TARGET = test

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build:$(CPPOBJS)
	$(CPP) -o $(TARGET) $^

$(CPPOBJS):$(BUILDDIR)/%.o:%.cpp
	$(CPP) $(CPPEXTEND) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(TARGET)