ROOTDIR = ../../..
include $(ROOTDIR)/Makefile.rules

CFLAGS += -D_KERNEL
#CFLAGS += -D_DEBUG
LDFLAGS = -Bstatic -Ttext 100000 
LDFLAGS += -m elf_i386

#
# init.o must be first
#
OBJS = init.o asm.o blk.o boot.o buf.o bufq.o cpuid.o dev.o event.o file.o fs.o fsops.o intr.o mem.o mutex.o nextlex.o os.o path.o print.o proc.o queue.o region.o segment.o string.o sys.o syscall.o tsc.o uname.o vm.o
LIBS = -lload -lrrfs -ldevfs -ldev -lsysfs -ltime

TGT = os

all: kern
	cd $(ROOTDIR)/sys/src/dev; make
	cd $(ROOTDIR)/sys/src/devfs; make
	cd $(ROOTDIR)/sys/src/load; make
	cd $(ROOTDIR)/sys/src/rrfs; make
	cd $(ROOTDIR)/sys/src/sysfs; make
	cd $(ROOTDIR)/sys/src/time; make
	make build

kern: $(OBJS)

build:
	$(LD) $(LDFLAGS) -nostdlib -L$(LIBDIR) -o $(TGT) $(OBJS) $(LIBS)
	$(SIZE) $(TGT)

clean: kernclean
	cd $(ROOTDIR)/sys/src/dev; make clean
	cd $(ROOTDIR)/sys/src/devfs; make clean
	cd $(ROOTDIR)/sys/src/load; make clean
	cd $(ROOTDIR)/sys/src/rrfs; make clean
	cd $(ROOTDIR)/sys/src/sysfs; make clean
	cd $(ROOTDIR)/sys/src/time; make clean

kernclean:
	$(RM) *~ $(OBJS) $(TGT).sym $(TGT)

indent: clean
	Indent
	cd $(ROOTDIR)/sys/src/dev; Indent
	cd $(ROOTDIR)/sys/src/devfs; Indent
	cd $(ROOTDIR)/sys/src/load; Indent
	cd $(ROOTDIR)/sys/src/rrfs; Indent
	cd $(ROOTDIR)/sys/src/sysfs; Indent
	cd $(ROOTDIR)/sys/src/time; Indent
