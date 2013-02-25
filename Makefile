all: make_sdcc_nrf24le1

make_sdcc_nrf24le1:
	$(MAKE) -C ./_target_sdcc_nrf24le1 all

clean: clean_sdcc_nrf24le1

clean_sdcc_nrf24le1:
	$(MAKE) -C ./_target_sdcc_nrf24le1 clean