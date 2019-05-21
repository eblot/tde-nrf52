#-----------------------------------------------------------------------------
# ADC driver for nRF52
#
# @file CMakeLists.txt
#-----------------------------------------------------------------------------

build_component_from (
  src/nrfx_clock.c
  src/nrfx_comp.c
  src/nrfx_gpiote.c
  src/nrfx_i2s.c
  src/nrfx_lpcomp.c
  src/nrfx_pdm.c
  src/nrfx_power.c
  src/nrfx_power_clock.c
  src/nrfx_ppi.c
  src/nrfx_pwm.c
  src/nrfx_qdec.c
  src/nrfx_qspi.c
  src/nrfx_rng.c
  src/nrfx_rtc.c
  src/nrfx_saadc.c
  src/nrfx_spi.c
  src/nrfx_spim.c
  src/nrfx_spis.c
  src/nrfx_swi.c
  src/nrfx_systick.c
  src/nrfx_timer.c
  src/nrfx_twi.c
  src/nrfx_twim.c
  src/nrfx_twis.c
  src/nrfx_uart.c
  src/nrfx_uarte.c
  src/nrfx_wdt.c
)
