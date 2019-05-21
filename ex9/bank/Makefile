CPP = g++

CPPSRCS = Account.cpp AccountHandler.cpp BankingSystemMain.cpp 

CPPINC = -IAccount.h -IAccountHandler.h -IBankingCommonDecl.h -IHightCreditAccount.h -INormalAccount.h
BUILDDIR = build

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

.SUFFIXES:.cpp .o