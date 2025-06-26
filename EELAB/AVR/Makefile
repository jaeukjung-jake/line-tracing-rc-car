# 사용할 모듈 폴더 이름
MODULES := UART BlinkedLED RingBuffer SWUART CPP

# .PHONY 자동 정의
.PHONY: all clean flash $(MODULES) $(addsuffix -flash, $(MODULES))

# 기본 타겟: 안내만 표시
all:
	@echo "💡 사용법:"
	@echo "  make [모듈명]             → 해당 모듈 빌드"
	@echo "  make [모듈명]-flash       → 해당 모듈 flash"
	@echo "  make clean                → 전체 clean"
	@echo ""
	@echo "가능한 모듈: $(MODULES)"

# 개별 모듈 빌드 (예: make UART)
$(MODULES):
	@echo "🔨 Building $@..."
	$(MAKE) -C $@

# 개별 모듈 flash (예: make UART-flash)
$(foreach mod,$(MODULES),$(eval $(mod)-flash: ; \
	@echo "⚡ Flashing $(mod)..."; \
	$(MAKE) -C $(mod) flash))

# 전체 clean
clean:
	@for dir in $(MODULES); do \
		if [ -f $$dir/Makefile ]; then \
			echo "🧹 Cleaning $$dir..."; \
			$(MAKE) -C $$dir clean; \
		fi \
	done
