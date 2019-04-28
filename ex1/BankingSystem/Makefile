CC = g++

SRCS = BankingSystem.cpp

TARGET = 

BUILDDIR = build

CPPOBJS = $(addprefix $(BUILDDIR)/,$(SRCS:.cpp=.o))

all: clean createdirs $(CPPOBJS)

createdirs:
	$(shell mkdir ${BUILDDIR})

$(CPPOBJS): $(BUILDDIR)/%.o : %.cpp
	$(CC) $< -o $@

clean:
	rm -rf $(BUILDDIR)