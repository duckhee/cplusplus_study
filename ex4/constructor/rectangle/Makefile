CPP = g++

CPPSRCS = Point.cpp Rectangle.cpp RectangleConstructor.cpp

CPPEXTEND = -IPoint.h -IRectangle.h

BUILDDIR = build

TARGET = test

CPPFLAGS = 

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(CPPOBJS)
	$(CPP) -o $(TARGET) $^

$(CPPOBJS): $(BUILDDIR)/%.o : %.cpp
	$(CPP) -o $@ -c $<  $(CPPEXTEND) 

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(TARGET)