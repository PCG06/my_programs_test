.PHONY: all clean

all: c py
clean: clean-c clean-py

c:
	$(MAKE) --no-print-directory -C c_prgms

clean-c:
	$(MAKE) --no-print-directory -C c_prgms clean

py:
	$(MAKE) --no-print-directory -C python_prgms

clean-py:
	$(MAKE) --no-print-directory -C python_prgms clean
