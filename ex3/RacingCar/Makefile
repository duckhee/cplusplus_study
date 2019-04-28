CPP = g++

SRCS = RacingCar.cpp RacingCarAdd.cpp RacingCarEnum.cpp RacingCarOuterFunc.cpp RacingCarClassBase.cpp

BUILDDIR = build

COBJS = $(addprefix $(BUILDDIR)/, $(SRCS:.cpp=.o))

CPPFLAGS = 

TARGET =

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(COBJS)

$(COBJS):$(BUILDDIR)/%.o : %.cpp
	$(CPP) $< -o $@

clean:
	rm -rf $(BUILDDIR)

