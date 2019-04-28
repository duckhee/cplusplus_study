CC = g++

SRCS = NameAlias.cpp

TARGET = 

BUILDDIR = build

CPPOBJS = $(addprefix $(BUILDDIR)/,$(SRCS:.cpp=.o))

all: clean createdir $(CPPOBJS)

createdir:
	$(shell mkdir ${BUILDDIR})

$(CPPOBJS): $(BUILDDIR)/%.o : %.cpp
	$(CC) $< -o $@

clean:
	rm -rf $(BUILDDIR)

