config:
	@echo ">>> config"
	cmake -S . -B build

build:
	@echo ">>> build"
	cmake --build build --target evre

run: build
	@echo ">>> run"
	@echo "   "
	@echo "---------------------------------"
	@echo "   "
	./build/evre.exe

clean:
	@echo ">>> clean"
	rm build/evre.exe

deep-clean:
	@echo ">>> deep-clean"
	rm -rf build

.PHONY: config build run clean