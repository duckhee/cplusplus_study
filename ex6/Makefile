CPP = g++

CPPSRCS = ConstObject.cpp ConstOverloading.cpp MyFriendClass.cpp MyFriendFunction.cpp CComstatic.cpp \
          NeedGrobal.cpp StaticMember.cpp

BUILDDIR = build

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build:$(CPPOBJS)

$(CPPOBJS): $(BUILDDIR)/%.o : %.cpp
	$(CPP) $< -o $@

clean:
	rm -rf $(BUILDDIR)