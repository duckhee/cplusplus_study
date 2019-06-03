CPP = g++

CPPSRCS = Account.cpp AccountArray.cpp AccountHandler.cpp BankingSystemMain.cpp AccountArray.cpp

BUILDDIR = build

CPPINC = -IAccount.h -IAccountArray.h -IAccountHandler.h -IHighCreditAccount.h -INormalAccount.h -IBankingCommonDecl.h 

TARGET = bank

CPPOBJS = $(addprefix $(BUILDDIR)/, $(CPPSRCS:.cpp=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILDDIR})

build: $(CPPOBJS)
	$(CPP) -o $(BUILDDIR)/$(TARGET) $^

$(CPPOBJS):$(BUILDDIR)/%.o : %.cpp
	$(CPP) $(CPPINC) -o $@ -c $<

clean:
	rm -rf $(BUILDDIR)

.SUFFIXES: .cpp .o