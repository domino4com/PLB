<img src="assets/PLB.svg" width=200 align="right">

# PLB - Power LiPo 18650 Single Cell
This provider power and power information from a single cell **18650**
| Specifications | |
| --: | :--: |
| Communication | I²C |
| I²C Address | 0x36 |
| ChipSet | Maxim Integrated MAX17048|
| Datasheet | [.pdf](https://www.analog.com/media/en/technical-documentation/data-sheets/MAX17048-MAX17049.pdf) |
| Suggested Arduino Library | [GitHub](https://github.com/sparkfun/SparkFun_MAX1704x_Fuel_Gauge_Arduino_Library) |
| Suggested MicroPython Library | [GitHub](https://github.com/adafruit/Adafruit_CircuitPython_MAX1704x)|

## Supported I²C Modes
- [X] 100 kbit/s Standard Mode (SM) 
- [X] 400 kbit/s	Fast Mode	FM
- [ ] 1 Mbit/s	Fast Mode Plus	FM+
- [ ] 3.4Mbit/s	High Speed Mode	HS
- [ ] 5 Mbit/s	Ultra Fast Mode	UFM

## Features of MAX17048
- Precision ±7.5mV/Cell Voltage Measurement
- ModelGauge Algorithm
  - Provides Accurate State-of-Charge
  - Compensates for Temperature/Load Variation
  - Does Not Accumulate Errors, Unlike Coulomb
Counters
  - Eliminates Learning
  - Eliminates Current-Sense Resistor
- Ultra-Low Quiescent Current
  - 3μA Hibernate, 23μA Active
  - Fuel Gauges in Hibernate Mode
  - Automatically Enters and Exits Hibernate Mode
- Reports Charge and Discharge Rate
- Battery-Insertion Debounce
  - Best of 16 Samples to Estimate Initial SOC
- Programmable Reset for Battery Swap
  - 2.28V to 3.48V Range
- Configurable Alert Indicator
  - Low SOC
  - 1% Change in SOC
  - Battery Undervoltage/Overvoltage
  - VRESET Alert

# License: 
<img src="assets/CC-BY-NC-SA.svg" width=200 align="right">
Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License

[View License Deed](https://creativecommons.org/licenses/by-nc-sa/4.0/) | [View Legal Code](https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode)
