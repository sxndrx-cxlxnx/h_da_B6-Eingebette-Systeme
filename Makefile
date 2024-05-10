CC = arm-none-eabi-gcc

CFLAGS = -mcpu=cortex-m3    \
		 -Wall			    \
		 -Wpedantic         \
		 -Werror            \
		 -L cmsis/linker    \
		 -T sam3x8e_sram.ld \
		 -D __SAM3X8E__     \
		 -I cmsis/src       \
		 -I include         \
		 -e Reset_Handler   \
		 -O0                \
		 -g

LDLIBS = -lm
 
SOURCES = cmsis/src/startup.c \
          cmsis/src/system.c  \
          cmsis/src/stubs.c   \
          src/clock.c         \
          src/debug.c         \
          src/led.c           \
          src/menu.c          \
          src/sample.c        \
          src/serial.c        \
          src/state.c         \
          src/twi.c           \
          src/matrix.c        \
          src/sonic.c         \
          src/drive.c         \
          src/motion.c        \
          src/main.c
 
DEPS = $(SOURCES:%.c=%.d)
OBJS = $(SOURCES:%.c=%.o)

%.d: %.c Makefile
	$(CC) $(CFLAGS) -MM -MT $(@:%.d=%.o) -MF $@ $<
 
%.o: %.c Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

main.elf: $(OBJS) 
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

ifeq (,$(filter clean,$(MAKECMDGOALS)))
include $(DEPS)
endif
 
.PHONY: clean openocd debug

clean:
	rm -f $(DEPS) $(OBJS) main.elf

openocd:
	openocd -f interface/cmsis-dap.cfg -f target/at91sam3ax_8x.cfg

debug: main.elf
	arm-none-eabi-gdb -ex "target extended-remote :3333" -ex "load" $<
